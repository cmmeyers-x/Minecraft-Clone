#include <CSCI441/objects.hpp>
#include <ctime>
#include "MpEngine.hpp"
//*************************************************************************************
//
// Helper Functions

#ifndef M_PI
#define M_PI 3.14159265
#endif

/// \desc Simple helper function to return a random number between 0.0f and 1.0f.
GLfloat getRand() {
    return (GLfloat)rand() / (GLfloat)RAND_MAX;
}

//*************************************************************************************
//
// Public Interface

MpEngine::MpEngine(int OPENGL_MAJOR_VERSION, int OPENGL_MINOR_VERSION,
                         int WINDOW_WIDTH, int WINDOW_HEIGHT, const char* WINDOW_TITLE)
         : CSCI441::OpenGLEngine(OPENGL_MAJOR_VERSION, OPENGL_MINOR_VERSION, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) {

    for(auto& _key : _keys) _key = GL_FALSE;

    _mousePosition = glm::vec2(MOUSE_UNINITIALIZED, MOUSE_UNINITIALIZED );
    _leftMouseButtonState = GLFW_RELEASE;
}

MpEngine::~MpEngine() {
    delete _cameraManager;
    delete _textureManager;
    delete _block;
    delete _chunk;
}

void MpEngine::handleKeyEvent(GLint key, GLint action) {
    if(key != GLFW_KEY_UNKNOWN)
        _keys[key] = ((action == GLFW_PRESS) || (action == GLFW_REPEAT));

    if(action == GLFW_PRESS) {
        switch( key ) {
            // quit!
            case GLFW_KEY_Q:
            case GLFW_KEY_ESCAPE:
                setWindowShouldClose();
                break;

            default: break; // suppress CLion warning
        }
    }
}

void MpEngine::handleMouseButtonEvent(GLint button, GLint action) {
    // if the event is for the left mouse button
    if( button == GLFW_MOUSE_BUTTON_LEFT ) {
        // update the left mouse button's state
        _leftMouseButtonState = action;
    }
}

void MpEngine::handleCursorPositionEvent(glm::vec2 currMousePosition) {
    // if mouse hasn't moved in the window, prevent camera from flipping out
    if(_mousePosition.x == MOUSE_UNINITIALIZED) {
        _mousePosition = currMousePosition;
    }

    // if the left mouse button is being held down while the mouse is moving
    if(_leftMouseButtonState == GLFW_PRESS) {
        // rotate the camera by the distance the mouse moved
        _cameraManager->getCamera()->rotate((currMousePosition.x - _mousePosition.x) * 0.005f,
                         (_mousePosition.y - currMousePosition.y) * 0.005f );
    }

    // update the mouse position
    _mousePosition = currMousePosition;
}

void MpEngine::handleMouseScrollEvent(double xOffset, double yOffset) {
    // yOffset is -1 if scrolling towards user else 1
    yOffset == -1 ? _cameraManager->zoomOut() : _cameraManager->zoomIn();
}

//*************************************************************************************
//
// Engine Setup

void MpEngine::_setupGLFW() {
    CSCI441::OpenGLEngine::_setupGLFW();

    // set our callbacks
    glfwSetKeyCallback(_window, lab05_keyboard_callback);
    glfwSetMouseButtonCallback(_window, lab05_mouse_button_callback);
    glfwSetCursorPosCallback(_window, lab05_cursor_callback);
    glfwSetScrollCallback(_window, lab05_mouse_scroll_callback);
}

void MpEngine::_setupOpenGL() {
    glEnable( GL_DEPTH_TEST );					                    // enable depth testing
    glDepthFunc( GL_LESS );							                // use less than depth test

    glEnable(GL_BLEND);									            // enable blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	            // use one minus blending equation

    glEnable(GL_SCISSOR_TEST);


    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );	// clear the frame buffer to black
    
}

void MpEngine::_setupShaders() {

    _lightingShaderProgram = new CSCI441::ShaderProgram("shaders/lab05.v.glsl", "shaders/lab05.f.glsl" );
    _lightingShaderUniformLocations.mvpMatrix      = _lightingShaderProgram->getUniformLocation("mvpMatrix");
    _lightingShaderAttributeLocations.vPos         = _lightingShaderProgram->getAttributeLocation("vPos");

    // TODO #3A: assign uniforms
    _lightingShaderUniformLocations.lightDirection = _lightingShaderProgram->getUniformLocation("lightDirection");
    _lightingShaderUniformLocations.lightColor     = _lightingShaderProgram->getUniformLocation("lightColor");
    _lightingShaderUniformLocations.materialColor  = _lightingShaderProgram->getUniformLocation("materialColor");
    _lightingShaderUniformLocations.normalMatrix   = _lightingShaderProgram->getUniformLocation("normalMatrix");

    // Specular and Ambient Uniforms
    _lightingShaderUniformLocations.lightSpecular = _lightingShaderProgram->getUniformLocation("lightSpecular");
    _lightingShaderUniformLocations.lightAmbience = _lightingShaderProgram->getUniformLocation("lightAmbience");

    _lightingShaderUniformLocations.materialSpecular = _lightingShaderProgram->getUniformLocation("materialSpecular");
    _lightingShaderUniformLocations.materialAmbience = _lightingShaderProgram->getUniformLocation("materialAmbience");

    // direction vector of camera for reflectance
    _lightingShaderUniformLocations.viewVector = _lightingShaderProgram->getUniformLocation("viewVector");

    // position of the point light for point light calcs
    _lightingShaderUniformLocations.pointLightPosition = _lightingShaderProgram->getUniformLocation("pointLightPosition");
    // color of point light
    _lightingShaderUniformLocations.pointLightColor = _lightingShaderProgram->getUniformLocation("pointLightColor");

    _lightingShaderUniformLocations.flashlightPosition = _lightingShaderProgram->getUniformLocation("flashlightPosition");
    _lightingShaderUniformLocations.flashlightDirection = _lightingShaderProgram->getUniformLocation("flashlightDirection");
    _lightingShaderUniformLocations.flashlightColor = _lightingShaderProgram->getUniformLocation("flashlightColor");
    // TODO #3B: assign attributes
    _lightingShaderAttributeLocations.vertexNormal = _lightingShaderProgram->getAttributeLocation("vertexNormal");

    _setupBlockShader();
}


void MpEngine::_setupBlockShader(){
    _blockShaderProgram = new CSCI441::ShaderProgram("shaders/block.v.glsl", "shaders/block.f.glsl" );



    // attributes
    _blockShaderAttributeLocations.vPos = _blockShaderProgram->getAttributeLocation("vPos");
    _blockShaderAttributeLocations.texCoord = _blockShaderProgram->getAttributeLocation("textCordinateIn");
    _blockShaderAttributeLocations.vertexNormal = _blockShaderProgram->getAttributeLocation("vertexNormal");
    _blockShaderAttributeLocations.instanceMatrix = _blockShaderProgram->getAttributeLocation("instanceMatrix");

    // uniforms
    _blockShaderUniformLocations.projection = _blockShaderProgram->getUniformLocation("projection");
    _blockShaderUniformLocations.view = _blockShaderProgram->getUniformLocation("view");
    _blockShaderUniformLocations.textureMap = _blockShaderProgram->getUniformLocation("textureMap");

}




void MpEngine::_setupBuffers() {
    // TODO #4: need to connect our 3D Object Library to our shader


    CSCI441::setVertexAttributeLocations( _lightingShaderAttributeLocations.vPos, _lightingShaderAttributeLocations.vertexNormal ); //// (2nd argument)


    _cameraManager = new CameraManager();
    _cameraManager->initPlayers(_lightingShaderProgram->getShaderProgramHandle(),
                                _lightingShaderUniformLocations.mvpMatrix,
                                _lightingShaderUniformLocations.normalMatrix,
                                _lightingShaderUniformLocations.materialColor);



    /*
    _tree = new Tree(_lightingShaderProgram->getShaderProgramHandle(),
                     _lightingShaderUniformLocations.mvpMatrix,
                     _lightingShaderUniformLocations.normalMatrix, //// just this line added
                     _lightingShaderUniformLocations.materialColor);
    */
    _createGroundBuffers();
    _generateEnvironment();



    _textureManager = new TextureManager();
    _textureManager->LoadTextures("textures/");



    _block = new Block();
    _block->setupBlock(_blockShaderProgram->getShaderProgramHandle(),
                       _blockShaderUniformLocations.projection,
                       _blockShaderUniformLocations.view,
                       _blockShaderUniformLocations.textureMap,
                       _blockShaderAttributeLocations.vPos,
                       _blockShaderAttributeLocations.vertexNormal,
                       _blockShaderAttributeLocations.texCoord);
    _block->setTexture("dirt", _textureManager->getTextureHandle("dirt"));



    Block *stoneBlock = new Block();
    stoneBlock->setupBlock(_blockShaderProgram->getShaderProgramHandle(),
                           _blockShaderUniformLocations.projection,
                           _blockShaderUniformLocations.view,
                           _blockShaderUniformLocations.textureMap,
                           _blockShaderAttributeLocations.vPos,
                           _blockShaderAttributeLocations.vertexNormal,
                           _blockShaderAttributeLocations.texCoord);
    stoneBlock->setTexture("stone", _textureManager->getTextureHandle("stone"));



    _chunk = new Chunk(stoneBlock);
    _chunk->generateChunk(glm::vec3(0,0,0));

}

void MpEngine::_createGroundBuffers() {
    // TODO #8: expand our struct
    struct Vertex {
        GLfloat x, y, z, xn, yn, zn;
    };

    // TODO #9: add normal data
    Vertex groundQuad[4] = {
            {-1.0f, 0.0f, -1.0f, 0.0f, .5f, 0.5f},
            { 1.0f, 0.0f, -1.0f, 0.0f, .5f, 0.5f},
            {-1.0f, 0.0f,  1.0f, 0.0f, .5f, 0.5f},
            { 1.0f, 0.0f,  1.0f, 0.0f, .5f, 0.5f}
    };

    GLushort indices[4] = {0,1,2,3};

    _numGroundPoints = 4;

    glGenVertexArrays(1, &_groundVAO);
    glBindVertexArray(_groundVAO);

    GLuint vbods[2];       // 0 - VBO, 1 - IBO
    glGenBuffers(2, vbods);
    glBindBuffer(GL_ARRAY_BUFFER, vbods[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(groundQuad), groundQuad, GL_STATIC_DRAW);

    glEnableVertexAttribArray(_lightingShaderAttributeLocations.vPos);
    glVertexAttribPointer(_lightingShaderAttributeLocations.vPos, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    // TODO #10: hook up vertex normal attribute
    glEnableVertexAttribArray(_lightingShaderAttributeLocations.vertexNormal);
    glVertexAttribPointer(_lightingShaderAttributeLocations.vertexNormal, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float)*3));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbods[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void MpEngine::_generateEnvironment() {
    //******************************************************************
    // parameters to make up our grid size and spacing, feel free to
    // play around with this
    const GLfloat GRID_WIDTH = WORLD_SIZE * 1.8f;
    const GLfloat GRID_LENGTH = WORLD_SIZE * 1.8f;
    const GLfloat GRID_SPACING_WIDTH = 1.0f;
    const GLfloat GRID_SPACING_LENGTH = 1.0f;
    // precomputed parameters based on above
    const GLfloat LEFT_END_POINT = -GRID_WIDTH / 2.0f - 5.0f;
    const GLfloat RIGHT_END_POINT = GRID_WIDTH / 2.0f + 5.0f;
    const GLfloat BOTTOM_END_POINT = -GRID_LENGTH / 2.0f - 5.0f;
    const GLfloat TOP_END_POINT = GRID_LENGTH / 2.0f + 5.0f;
    //******************************************************************

///STUFF FOR DRAWING BUILDINGS, NOT TREES

///Stuff for drawing trees
///##################################################################################################

    srand( time(0) );                                                   // seed our RNG

//    for(int i = LEFT_END_POINT; i < RIGHT_END_POINT; i += GRID_SPACING_WIDTH) {
//        for(int j = BOTTOM_END_POINT; j < TOP_END_POINT; j += GRID_SPACING_LENGTH) {
//            if( i % 2 && j % 2 && getRand() < 0.4f ) {
//                if(!(i < 0) && !(j < 0)) {
//                // translate to spot, (modified from LAB05)
//                glm::mat4 transToSpotMtx = glm::translate( glm::mat4(1.0), glm::vec3(i, 0.0f, j) );
//                // compute random height
//                //GLdouble height = powf(getRand(), 2.5)*10 + 1;
//                GLdouble height = abs((sin((3.14*1.5)*i/RIGHT_END_POINT)) * abs(cos((3.14*1.5)*j/TOP_END_POINT) * 15) + 5.0f);
//                // scale to building size
//                glm::mat4 scaleToHeightMtx = glm::scale( glm::mat4(1.0), glm::vec3(1, height, 1) );
//
//                // translate up to grid
//                glm::mat4 transToHeight = glm::translate( glm::mat4(1.0), glm::vec3(0, height/2.0f, 0) );
//
//                // compute full model matrix
//                glm::mat4 modelMatrix = transToHeight * scaleToHeightMtx * transToSpotMtx;
//
//                // compute random color
//                glm::vec3 color( 0.235f, 0.180f, 0.164 );
//
//
////                // store building properties
////                BuildingData currentBuilding = {modelMatrix, color};
////                _buildings.emplace_back( currentBuilding );
////                } else {
////                    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0), glm::vec3(i, 0.0f, j));
////                    GLfloat scale = ((rand() % 60 + 40) / 20.0f);
////                    modelMatrix = glm::scale(modelMatrix, glm::vec3(scale, scale, scale));
////                    TreeData currentTree = {modelMatrix};
////                    _trees.emplace_back(currentTree);
////
////                }
//
//            }
//        }
//    }
}
///##################################################################################################

void MpEngine::_setupTextures() {
    //_textureHandles[TEXTURE_ID::DIRT] = _loadAndRegisterTexture("textures/dirt.jpg");
}



void MpEngine::_setupScene() {
    _cameraSpeed = glm::vec2(0.25f, 0.02f);

    //Directional lighting static uniforms
    glm::vec3 directionLight = glm::vec3(-1.0f,-1.0f,-1.0f);
    glm::vec3 colorLight = glm::vec3(1.0f,1.0f,1.0f);
    glm::vec3 lightSpecular = glm::vec3(1.0f,1.0f,1.0f);

    glm::vec3 flashPos = glm::vec3(10.199,8.66f,10.15);
    glm::vec3 flashDir = glm::vec3(0.0f,-1.0f, 0.0f);
    glm::vec3 flashlightColor = glm::vec3(0.305, 0.074, 0.325);

    //Point light static uniforms
    // Set the point light position to be at the center of the world, and up a bit
    glm::vec3 pointLightPosition = glm::vec3(0.0f, 0.5f, 0.0f);
    glm::vec3 pointLightColor = glm::vec3(1.0f, 0.0f, 0.0f);

    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(),
                        _lightingShaderUniformLocations.flashlightColor,
                        1,
                        &flashlightColor[0]);


    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(),
                        _lightingShaderUniformLocations.pointLightColor,
                        1,
                        &pointLightColor[0]);

    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(),
                        _lightingShaderUniformLocations.flashlightPosition,
                        1,
                        &flashPos[0]);

    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(),
                        _lightingShaderUniformLocations.flashlightDirection,
                        1,
                        &flashDir[0]);

    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(),
                        _lightingShaderUniformLocations.pointLightPosition,
                        1,
                        &directionLight[0]);


    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(),
                        _lightingShaderUniformLocations.lightDirection,
                        1,
                        &directionLight[0]);

    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(),
                        _lightingShaderUniformLocations.lightColor,
                        1,
                        &colorLight[0]);

    glProgramUniform3fv(_lightingShaderProgram->getShaderProgramHandle(), // mp
                        _lightingShaderUniformLocations.lightSpecular,
                        1,
                        &lightSpecular[0]);
}

//*************************************************************************************
//
// Engine Cleanup

void MpEngine::_cleanupShaders() {
    fprintf( stdout, "[INFO]: ...deleting Shaders.\n" );
    delete _lightingShaderProgram;
}

void MpEngine::_cleanupBuffers() {
    fprintf( stdout, "[INFO]: ...deleting VAOs....\n" );
    CSCI441::deleteObjectVAOs();
    glDeleteVertexArrays( 1, &_groundVAO );

    fprintf( stdout, "[INFO]: ...deleting VBOs....\n" );
    CSCI441::deleteObjectVBOs();

    fprintf( stdout, "[INFO]: ...deleting models..\n" );
}

void MpEngine::_cleanupTextures() {
    fprintf( stdout, "[INFO]: ...deleting textures\n" );
    //glDeleteTextures(1, &_textureHandles[TEXTURE_ID::DIRT]);
}

//*************************************************************************************
//
// Rendering / Drawing Functions - this is where the magic happens!

void MpEngine::_renderScene(glm::mat4 viewMtx, glm::mat4 projMtx) {

    // use our lighting shader program
    _lightingShaderProgram->useProgram();


    glm::vec3 materialSpecularCharacters = glm::vec3(0.6f, 0.6f, 0.6f);
  //  glm::vec3 materialSpecularTrees = glm::vec3(0.4f, 0.4f, 0.4f);
    glm::vec3 materialSpecularBuildings = glm::vec3(0.3f, 0.3f, 0.3f);

    glm::vec3 lightAmbient = glm::vec3(1.0f, 1.0f, 1.0f);
    glUniform3fv(_lightingShaderUniformLocations.lightAmbience, 1, &lightAmbient[0]);

    // send the view vector from the camera
    glUniform3fv(_lightingShaderUniformLocations.viewVector, 1, &_cameraManager->getCamera()->getPosition()[0]);

    // Draw Trees and Towers
   // glUniform3fv(_lightingShaderUniformLocations.materialSpecular, 1, &materialSpecularTrees[0]);
   // for( const TreeData& currentTree : _trees ) {
   //     _tree->drawTree(currentTree.modelMatrix, viewMtx, projMtx);
   // }

    glUniform3fv(_lightingShaderUniformLocations.materialSpecular, 1, &materialSpecularBuildings[0]);
   // for( const BuildingData& currentBuilding : _buildings ) {
    //    _computeAndSendMatrixUniforms(currentBuilding.modelMatrix, viewMtx, projMtx);
//
    //    glUniform3fv(_lightingShaderUniformLocations.materialColor, 1, &currentBuilding.color[0]);
//
   //     CSCI441::drawSolidCube(1.0);
  //  }

    // Draw all characters
    glUniform3fv(_lightingShaderUniformLocations.materialSpecular, 1, &materialSpecularCharacters[0]);
    glm::mat4 modelMtx(1.0f);
    _cameraManager->drawAllCharacters(modelMtx, viewMtx, projMtx);

    // draw the ground plane
    glm::mat4 groundModelMtx = glm::scale( glm::mat4(1.0f), glm::vec3(WORLD_SIZE, 1.0f, WORLD_SIZE));
    _computeAndSendMatrixUniforms(groundModelMtx, viewMtx, projMtx);

    glm::vec3 groundColor(0.341f, 0.619f, 0.698f);
    glm::vec3 groundMaterialSpec(0.1f, 0.1f, 0.1f);
    glUniform3fv(_lightingShaderUniformLocations.materialColor, 1, &groundColor[0]);
    glUniform3fv(_lightingShaderUniformLocations.materialSpecular, 1, &groundMaterialSpec[0]);

//    glBindVertexArray(_groundVAO);
//    glDrawElements(GL_TRIANGLE_STRIP, _numGroundPoints, GL_UNSIGNED_SHORT, (void*)0);


//    _blockShaderProgram->useProgram();
//    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//    _block->drawBlock(modelMatrix, viewMtx, projMtx);
//    modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 0.0f));
//    _block->drawBlock(modelMatrix, viewMtx, projMtx);


    _chunk->drawChunk(viewMtx, projMtx);
}

void MpEngine::_updateScene() {
    // turn right
    if( _keys[GLFW_KEY_D] ) {
        _cameraManager->rotateRight();
    }
    // turn left
    if( _keys[GLFW_KEY_A] ) {
        _cameraManager->rotateLeft();
    }
    // move foward
    if( _keys[GLFW_KEY_W] ) {
        _cameraManager->moveForward();
    }
    // move backward
    if( _keys[GLFW_KEY_S] ) {
        _cameraManager->moveBackward();
    }
    // Set freeCam
    if( _keys[GLFW_KEY_1]) {
        _cameraManager->setCamera(CameraManager::CameraType::freeCam);
    }
    // Set arcballCam
    if( _keys[GLFW_KEY_2]) {
        _cameraManager->setCamera(CameraManager::CameraType::arcballCam);
    }
    // Set first person camera
    if( _keys[GLFW_KEY_3]) {
       _cameraManager->toggleSecondCamera();
    }

    // set first character
    if( _keys[GLFW_KEY_4]) {
        _cameraManager->setPlayer(CameraManager::Players::player1);
    }
    // sets second character
    if( _keys[GLFW_KEY_5]) {
        _cameraManager->setPlayer(CameraManager::Players::player2);
    }
    // sets third character
    if( _keys[GLFW_KEY_6]) {
        _cameraManager->setPlayer(CameraManager::Players::player3);
    }
    // fourth character
    if( _keys[GLFW_KEY_7]) {
        _cameraManager->setPlayer(CameraManager::Players::player4);
    }

}

void MpEngine::run() {
    //  This is our draw loop - all rendering is done here.  We use a loop to keep the window open
    //	until the user decides to close the window and quit the program.  Without a loop, the
    //	window will display once and then the program exits.
    while( !glfwWindowShouldClose(_window) ) {	        // check if the window was instructed to be closed
        glDrawBuffer( GL_BACK );				        // work with our back frame buffer
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );	// clear the current color contents and depth buffer in the window

        GLint framebufferWidth, framebufferHeight;
        const int minXY = 3;

        if (_cameraManager->secondCameraEnabled()){
            glEnable(GL_SCISSOR_TEST);
            glScissor( 0, 0, framebufferWidth/minXY, framebufferHeight/minXY);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glDisable(GL_SCISSOR_TEST);

            glViewport( 0, 0, framebufferWidth/minXY, framebufferHeight/minXY);
            //  glScissor( 0, 0, framebufferWidth/minXY, framebufferHeight/minXY);

            glDrawBuffer( GL_BACK );
            glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );	// clear the current color contents and depth buffer in the window
            glClearDepth(1.0f);

            glm::mat4 projectionMatrix = glm::perspective( 45.0f, (GLfloat) framebufferWidth / (GLfloat) framebufferHeight, 1.0f, 1000.0f );
            // set up our look at matrix to position our camera
            glm::mat4 viewMatrix = _cameraManager->getSecondCamera()->getViewMatrix();

            _renderScene(viewMatrix, projectionMatrix);
        }

        // Get the size of our framebuffer.  Ideally this should be the same dimensions as our window, but
        // when using a Retina display the actual window can be larger than the requested window.  Therefore,
        // query what the actual size of the window we are rendering to is.

        glfwGetFramebufferSize( _window, &framebufferWidth, &framebufferHeight );

        glViewport( 0, 0, framebufferWidth, framebufferHeight);
        glScissor(0,0, framebufferWidth, framebufferHeight);


        // with a FOV of 45 degrees, for our current aspect ratio, and Z ranges from [0.001, 1000].
        glm::mat4 projectionMatrix = glm::perspective( 45.0f, (GLfloat) framebufferWidth / (GLfloat) framebufferHeight, 0.001f, 1000.0f );
        // set up our look at matrix to position our camera
        glm::mat4 viewMatrix = _cameraManager->getCamera()->getViewMatrix();

        // draw everything to the window
        _renderScene(viewMatrix, projectionMatrix);

        _updateScene();

        glfwSwapBuffers(_window);                       // flush the OpenGL commands and make sure they get rendered!
        glfwPollEvents();				                // check for any events and signal to redraw screen
    }
}

//*************************************************************************************
//
// Private Helper FUnctions


GLuint MpEngine::_loadAndRegisterTexture() {
    // our handle to the GPU
    GLuint textureHandle = 0;

    const char* FILENAME = "assets/textures/sky3_low_res.png";
    // enable setting to prevent image from being upside down
    stbi_set_flip_vertically_on_load(true);

    // will hold image parameters after load
    GLint imageWidth, imageHeight, imageChannels;
    // load image from file
    GLubyte* data = stbi_load( FILENAME, &imageWidth, &imageHeight, &imageChannels, 0);

    // if data was read from file
    if( data ) {
        const GLint STORAGE_TYPE = (imageChannels == 4 ? GL_RGBA : GL_RGB);

        // TODO #01
        glGenTextures(1, &textureHandle);
        // TODO #02
        glBindTexture(GL_TEXTURE_2D, textureHandle);
        // TODO #03
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // TODO #04
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        // TODO #05
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        // TODO #06
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        std::cout << "============================================made it here1=================================================" << std::endl;
        // TODO #07
        glTexImage2D(GL_TEXTURE_2D, 0, STORAGE_TYPE, imageWidth, imageHeight, 0, STORAGE_TYPE, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        std::cout << "============================================made it here2=================================================" << std::endl;
        fprintf( stdout, "[INFO]: %s texture map read in with handle %d\n", FILENAME, textureHandle);

        // release image memory from CPU - it now lives on the GPU
        stbi_image_free(data);
    } else {
        // load failed
        fprintf( stderr, "[ERROR]: Could not load texture map \"%s\"\n", FILENAME );
    }

    // return generated texture handle
    return textureHandle;

}


void MpEngine::_computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const {
    // precompute the Model-View-Projection matrix on the CPU
    glm::mat4 mvpMtx = projMtx * viewMtx * modelMtx;
    // then send it to the shader on the GPU to apply to every vertex
    _lightingShaderProgram->setProgramUniform(_lightingShaderUniformLocations.mvpMatrix, mvpMtx);

    // TODO #7: compute and send the normal matrix
    glm::mat3 normalMtx = glm::mat3(glm::transpose(glm::inverse(modelMtx))); ////
    glProgramUniformMatrix3fv(_lightingShaderProgram->getShaderProgramHandle(), ////
                        _lightingShaderUniformLocations.normalMatrix, 1, GL_FALSE,
                        &normalMtx[0][0]);
//    _lightingShaderProgram->setProgramUniform(_lightingShaderUniformLocations.normalMatrix, normalMtx); //this also works
}

//*************************************************************************************
//
// Callbacks

void lab05_keyboard_callback(GLFWwindow *window, int key, int scancode, int action, int mods ) {
    auto engine = (MpEngine*) glfwGetWindowUserPointer(window);

    // pass the key and action through to the engine
    engine->handleKeyEvent(key, action);
}

void lab05_cursor_callback(GLFWwindow *window, double x, double y ) {
    auto engine = (MpEngine*) glfwGetWindowUserPointer(window);

    // pass the cursor position through to the engine
    engine->handleCursorPositionEvent(glm::vec2(x, y));
}

void lab05_mouse_button_callback(GLFWwindow *window, int button, int action, int mods ) {
    auto engine = (MpEngine*) glfwGetWindowUserPointer(window);

    // pass the mouse button and action through to the engine
    engine->handleMouseButtonEvent(button, action);
}

void lab05_mouse_scroll_callback(GLFWwindow* window, double xOffset, double yOffset){
    auto engine = (MpEngine*) glfwGetWindowUserPointer(window);
    // pass the scroll direction to the engine
    // only Y is used due to exclusive mouse input
    engine->handleMouseScrollEvent(xOffset, yOffset);
}
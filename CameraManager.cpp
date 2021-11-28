//
// Created by cmmeyers on 10/11/21.
//

#include "CameraManager.hpp"

CameraManager::CameraManager(){
    // Initalize Cameras
    cameras[CameraType::freeCam] = new CSCI441::FreeCam();
    cameras[CameraType::arcballCam] = new ArcBallCam();
    cameras[CameraType::firstPersonCam] = new CSCI441::FreeCam();
    _currentCamera = CameraType::freeCam;

    movementSpeed = 0.2f;
    rotateSpeed = 0.1f;

    _secondCameraEnabled = false;

    cameras[CameraType::freeCam]->setPosition( glm::vec3(60.0f, 40.0f, 30.0f));
    cameras[CameraType::freeCam]->setTheta( -M_PI / 3.0f );
    cameras[CameraType::freeCam]->setPhi( M_PI / 2.8f );
    cameras[CameraType::freeCam]->recomputeOrientation();

    cameras[CameraType::arcballCam]->setPosition( glm::vec3(60.0f, 40.0f, 30.0f));
    cameras[CameraType::arcballCam]->setTheta( -M_PI / 3.0f );
    cameras[CameraType::arcballCam]->setPhi( M_PI / 2.8f );
    cameras[CameraType::arcballCam]->recomputeOrientation();

    cameras[CameraType::firstPersonCam]->setPosition( glm::vec3(60.0f, 40.0f, 30.0f));
    cameras[CameraType::firstPersonCam]->setTheta( -M_PI / 3.0f );
    cameras[CameraType::firstPersonCam]->setPhi( M_PI / 2.0f );
    cameras[CameraType::firstPersonCam]->recomputeOrientation();
}



CameraManager::~CameraManager() {
    for (int i = 0; i < NUM_CAMS; ++i){
        free(cameras[i]);
    }

    for (int i = 0; i < NUM_PLAYERS; ++i){
        free(characters[i]);
    }
}

void CameraManager::initPlayers(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation,
                                GLint materialColorUniformLocation) {

    characters[Players::player1] = new Popsickle(shaderProgramHandle, mvpMtxUniformLocation, normalMtxUniformLocation, materialColorUniformLocation);
    characters[Players::player2] = new Skier(shaderProgramHandle, mvpMtxUniformLocation, normalMtxUniformLocation, materialColorUniformLocation);
    characters[Players::player3] = new Deimos(shaderProgramHandle, mvpMtxUniformLocation, normalMtxUniformLocation, materialColorUniformLocation);
    characters[Players::player4] = new Flashlight(shaderProgramHandle, mvpMtxUniformLocation, normalMtxUniformLocation, materialColorUniformLocation);

    _currentPlayer = Players::player1;
}

void CameraManager::setCamera(CameraType cameraEnum) {
    _currentCamera = cameraEnum;
}

void CameraManager::setPlayer(Players playerEnum) {
    _currentPlayer = playerEnum;
    this->setCameraPoint();
}

CSCI441::Camera* CameraManager::getCamera() {
    return( cameras[_currentCamera]);
}

CSCI441::Camera* CameraManager::getSecondCamera() {
    return(cameras[CameraType::firstPersonCam]);
}

// We already hold a pointer so we can get it through existing enum
void CameraManager::setSecondCamera(CameraType cameraEnum) {
    _secondCameraEnabled = true;
}

GenericCharacter* CameraManager::getPlayer(){
    return( characters[_currentPlayer]);
}




void CameraManager::moveForward() {
    if (_currentCamera != CameraType::freeCam){
        std::cout << "x: " <<  this->getCamera()->getPosition().x <<  "y: " <<  this->getCamera()->getPosition().y << "z: " <<  this->getCamera()->getPosition().z << std::endl;
        this->getPlayer()->moveForward(movementSpeed);
        this->setCameraPoint();
    }
    else{ // free cam not attached to player
        this->getCamera()->moveForward(movementSpeed);
    }
}

void CameraManager::moveBackward() {
    if (_currentCamera != CameraType::freeCam){
        this->getPlayer()->moveBackward(movementSpeed);
        this->setCameraPoint();
    }
    else {
        this->getCamera()->moveBackward(movementSpeed);
    }
}

void CameraManager::rotateLeft() {
    if (_currentCamera != CameraType::freeCam) {
        this->getPlayer()->rotate(rotateSpeed);
        this->setCameraPoint();
    }
}

void CameraManager::rotateRight() {
    if (_currentCamera != CameraType::freeCam){
        this->getPlayer()->rotate(-rotateSpeed);
        this->setCameraPoint();
    }
}

void CameraManager::setCameraPoint() {
    if(_currentCamera == CameraType::freeCam) {
        // Resets freeCam to start position whenever character is changed
        this->getCamera()->setPosition(glm::vec3(0.0f,0.0f,0.0f));
        this->getCamera()->setLookAtPoint(glm::vec3(0.0f,0.0f,0.0f));
    } else if (_currentCamera == CameraType::arcballCam){
        this->getCamera()->setLookAtPoint(this->getPlayer()->getCurrentPosition()+ glm::vec3(0.0f, 5.0f, 0.0f));
    }
    this->getCamera()->recomputeOrientation();

    if (_secondCameraEnabled){
        auto camera = this->getSecondCamera();
        auto player = this->getPlayer();
        GLfloat playerTheta = player->getCharacterAngle();
        camera->setPosition(player->getCurrentPosition() + glm::vec3(-1.15*sin(player->getCharacterAngle()),
                                                                     player->getCharacterHeight(),
                                                                     -1.15*cos(player->getCharacterAngle())));
        camera->setTheta(-playerTheta);

        this->getSecondCamera()->recomputeOrientation();
    }
}

void CameraManager::drawAllCharacters(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx){
    for (auto character : characters){
        character->drawCharacter(modelMtx, viewMtx, projMtx);
    }
}


void CameraManager::zoomOut() {
    if (_currentCamera == CameraType::arcballCam){
        auto arcballptr = (ArcBallCam*)this->getCamera();
        arcballptr->zoomOut();
    }
}

void CameraManager::zoomIn() {
    if(_currentCamera == CameraType::arcballCam){
        auto arcballptr = (ArcBallCam*)this->getCamera();
        arcballptr->zoomIn();
    }
}

bool CameraManager::secondCameraEnabled(){
    return _secondCameraEnabled;
}

void CameraManager::toggleSecondCamera() {
    // first person camera only allowed when Arcball is selected
    if (_currentCamera == CameraType::arcballCam){
        setCameraPoint(); // force a camera attributes update
        _secondCameraEnabled ^= true;
    }
}

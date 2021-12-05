//
// Created by cmmeyers on 11/28/21.
//

#include "Block.hpp"
#include <iostream>
#include <CSCI441/objects.hpp>


Block::Block(glm::vec3 blockLocation){
    this->_blockLocation = blockLocation;
}

static struct ShaderProgramUniformLocations {
    /// \desc location of the precomputed ModelViewProjection matrix
    GLint mvpMtx;
} _shaderProgramUniformLocations;


//void Block::setupBlock(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint vPosAttributeLocation) {
//   //  setup shader and uniform references
//    this->_shaderProgramHandle = shaderProgramHandle;
//    _shaderProgramUniformLocations.mvpMtx = mvpMtxUniformLocation;
//    _blockShaderProgramAttributes.vPos = vPosAttributeLocation;
//
//    // setup Block information
//    struct points{
//        GLfloat x,y,z;
//    };
//
//    /// 1 point for each of the 6 faces on the block
//    // north is +x
//    // east is +z
//    points blockFacesArray[6] = {
//            {0.5f,1.0f,0.5f}, // top
//            {0.5f,0.0f,0.5f}, // bottom
//            {1.0f,0.5f,0.5f}, // north
//            {0.0f,0.5f,0.5f}, // south
//            {1.0f,0.5f,0.5f}, // east
//            {0.5f,0.5f,0.0f}  // west
//    };
//
//
//    // Create VBO/VAO
//    glGenVertexArrays(1, &_staticBlockDescriptors._blockVAO);
//    glGenBuffers(1, &_staticBlockDescriptors._blockVBO);
//    glBindVertexArray(_staticBlockDescriptors._blockVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, _staticBlockDescriptors._blockVBO);
//    glEnableVertexAttribArray( _blockShaderProgramAttributes.vPos );
//    glVertexAttribPointer( _blockShaderProgramAttributes.vPos, 3, GL_FLOAT, GL_FALSE, sizeof(points), (void*)0);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(blockFacesArray), blockFacesArray, GL_STATIC_DRAW);
//}


void Block::setupBlock(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint vPosAttributeLocation) {

    this->_shaderProgramHandle = shaderProgramHandle;
    _shaderProgramUniformLocations.mvpMtx = mvpMtxUniformLocation;
    _blockShaderProgramAttributes.vPos = vPosAttributeLocation;

    glGenVertexArrays(1, &_staticBlockDescriptors._blockVAO);
    glBindVertexArray(_staticBlockDescriptors._blockVAO);

    glGenBuffers( 1, &_staticBlockDescriptors._blockVBO );
    glBindBuffer( GL_ARRAY_BUFFER, _staticBlockDescriptors._blockVBO );

    GLfloat cornerPoint = _sideLength / 2.0f;

    GLfloat vertices[36][3] = {
            // Left Face
            {-cornerPoint, -cornerPoint, -cornerPoint}, {-cornerPoint, -cornerPoint,  cornerPoint}, {-cornerPoint,  cornerPoint, -cornerPoint},
            {-cornerPoint,  cornerPoint, -cornerPoint}, {-cornerPoint, -cornerPoint,  cornerPoint}, {-cornerPoint,  cornerPoint,  cornerPoint},
            // Right Face
            { cornerPoint,  cornerPoint,  cornerPoint}, { cornerPoint, -cornerPoint,  cornerPoint}, { cornerPoint,  cornerPoint, -cornerPoint},
            { cornerPoint,  cornerPoint, -cornerPoint}, { cornerPoint, -cornerPoint,  cornerPoint}, { cornerPoint, -cornerPoint, -cornerPoint},
            // Top Face
            {-cornerPoint,  cornerPoint, -cornerPoint}, {-cornerPoint,  cornerPoint,  cornerPoint}, { cornerPoint,  cornerPoint, -cornerPoint},
            { cornerPoint,  cornerPoint, -cornerPoint}, {-cornerPoint,  cornerPoint,  cornerPoint}, { cornerPoint,  cornerPoint,  cornerPoint},
            // Bottom Face
            { cornerPoint, -cornerPoint,  cornerPoint}, {-cornerPoint, -cornerPoint,  cornerPoint}, { cornerPoint, -cornerPoint, -cornerPoint},
            { cornerPoint, -cornerPoint, -cornerPoint}, {-cornerPoint, -cornerPoint,  cornerPoint}, {-cornerPoint, -cornerPoint, -cornerPoint},
            // Back Face
            { cornerPoint,  cornerPoint, -cornerPoint}, { cornerPoint, -cornerPoint, -cornerPoint}, {-cornerPoint,  cornerPoint, -cornerPoint},
            {-cornerPoint,  cornerPoint, -cornerPoint}, { cornerPoint, -cornerPoint, -cornerPoint}, {-cornerPoint, -cornerPoint, -cornerPoint},
            // Front Face
            {-cornerPoint, -cornerPoint,  cornerPoint}, { cornerPoint, -cornerPoint,  cornerPoint}, {-cornerPoint,  cornerPoint,  cornerPoint},
            {-cornerPoint,  cornerPoint,  cornerPoint}, { cornerPoint, -cornerPoint,  cornerPoint}, { cornerPoint,  cornerPoint,  cornerPoint}
    };
    GLfloat texCoords[36][2] = {
            // Left Face
            {0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f},
            {0.0f, 1.0f}, {1.0f, 0.0f}, {1.0f, 1.0f},
            // Right Face
            {0.0f, 1.0f}, {0.0f, 0.0f}, {1.0f, 1.0f},
            {1.0f, 1.0f}, {0.0f, 0.0f}, {1.0f, 0.0f},
            // Top Face
            {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f},
            {0.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f},
            // Bottom Face
            {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f},
            {0.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f},
            // Back Face
            {0.0f, 1.0f}, {0.0f, 0.0f}, {1.0f, 1.0f},
            {1.0f, 1.0f}, {0.0f, 0.0f}, {1.0f, 0.0f},
            // Front Face
            {0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f},
            {0.0f, 1.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}
    };
    GLfloat normals[36][3] = {
            // Left Face
            {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f},
            // Right Face
            {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
            // Top Face
            {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f},
            // Bottom Face
            {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f},
            // Back Face
            {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f},
            // Front Face
            {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}
    };

    glBufferData( GL_ARRAY_BUFFER, sizeof(GLfloat) * 36 * 8, NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 36 * 3, vertices );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(GLfloat) * 36 * 3, sizeof(GLfloat) * 36 * 3, normals );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(GLfloat) * 36 * 6, sizeof(GLfloat) * 36 * 2, texCoords );
}

void Block::cleanupBlock() {
    // TODO cleanup
}


void Block::drawBlock(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    glUseProgram(_shaderProgramHandle);
    // Send over Uniforms
    glm::mat4 mvpMtx = projMtx * viewMtx * modelMtx;
    glProgramUniformMatrix4fv(_shaderProgramHandle, _shaderProgramUniformLocations.mvpMtx, 1, GL_FALSE, &mvpMtx[0][0]);
    glBindVertexArray(_staticBlockDescriptors._blockVAO);

    //glDrawArrays(GL_POINTS, 0, 6);
    glDrawArrays( GL_TRIANGLES, 0, 36 );
}

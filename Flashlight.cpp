//
// Created by alexk on 10/14/2021.
//

#include "Flashlight.hpp"

Flashlight::Flashlight(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation,
                       GLint materialColorUniformLocation) {

    _shaderProgramHandle = shaderProgramHandle;
    _shaderProgramUniformLocations.mvpMtx = mvpMtxUniformLocation;
    _shaderProgramUniformLocations.normalMtx = normalMtxUniformLocation;
    _shaderProgramUniformLocations.materialColor = materialColorUniformLocation;

    _characterHeading = 0.0f;
    _currentPosition = glm::vec3(10.0f,0.0f,10.0f);
    _color = glm::vec3(1.0f,1.0f,0.0f);
}

void Flashlight::drawCharacter(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    glUseProgram(_shaderProgramHandle);

    modelMtx = glm::translate(modelMtx, _currentPosition);

    modelMtx = glm::translate(modelMtx, glm::vec3(0.0f,0.5f,0.0f));
    modelMtx = glm::rotate(modelMtx, _characterAngle, CSCI441::Y_AXIS);

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_color[0]);

    CSCI441::drawSolidCube(1.0f);
}

void Flashlight::moveForward(GLfloat movementFactor) {
    GenericCharacter::moveForward(movementFactor);
}

void Flashlight::moveBackward(GLfloat movementFactor) {
    GenericCharacter::moveBackward(movementFactor);
}

void Flashlight::rotate(GLfloat rotateSpd) {
    GenericCharacter::rotate(rotateSpd);
    _characterHeading += rotateSpd;
    _direction = glm::vec3(sin(_characterHeading), -3.141/4, cos(_characterHeading));
   // _direction += glm::vec3(cos(rotateSpd), 0, sin(rotateSpd));
}

glm::vec3 Flashlight::getDirection() {
    return _direction;
}

// From Lab05 Plane.cpp
void Flashlight::_computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const {
    // precompute the Model-View-Projection matrix on the CPU
    glm::mat4 mvpMtx = projMtx * viewMtx * modelMtx;
    // then send it to the shader on the GPU to apply to every vertex
    glProgramUniformMatrix4fv( _shaderProgramHandle, _shaderProgramUniformLocations.mvpMtx, 1, GL_FALSE, &mvpMtx[0][0] );

    glm::mat3 normalMtx = glm::mat3( glm::transpose( glm::inverse( modelMtx )));
    glProgramUniformMatrix3fv( _shaderProgramHandle, _shaderProgramUniformLocations.normalMtx, 1, GL_FALSE, &normalMtx[0][0] );
}


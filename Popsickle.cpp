//
// Created by alexk on 10/12/2021.
//

#include "Popsickle.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include "Popsickle.hpp"
#include <iostream>


Popsickle::Popsickle(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation, GLint materialColorUniformLocation) {

    _shaderProgramHandle = shaderProgramHandle;
    _shaderProgramUniformLocations.mvpMtx = mvpMtxUniformLocation;
    _shaderProgramUniformLocations.normalMtx = normalMtxUniformLocation;
    _shaderProgramUniformLocations.materialColor = materialColorUniformLocation;


    _colorPopsickleBody = glm::vec3( 0.564f, 0.403f, 0.254f);
    _colorPopsickleStick = glm::vec3( 0.890f, 0.631f, 0.388f);

    _colorPopsickleOrb = glm::vec3(0.890f, 0.388f, 0.435f);

    _scalePopsickleBody = glm::vec3(0.5f, 2.0f, 1.0f);
    _scalePopsickleStick = glm::vec3(0.8f, .5f, 0.4);

    _orbRotationAngle = 0;
    _orbRotationSpeed = 0.05;

    _characterHeading = 0.0f;

    _currentPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    _characterHeight = 3.4;
}

// Increment the spin angle of the orb by a constant amount
// Also bounds check to prevent overflow
void Popsickle::incrementOrbSpinAngle() {
    if (_orbSpinAngle > 2.0 * M_PI) _orbSpinAngle = 0.0f;
    _orbSpinAngle += (_orbRotationSpeed * .7f);
}

// Begin drawing the character
void Popsickle::drawCharacter(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {

    glUseProgram(_shaderProgramHandle);

    // Move the character to its current position in world space
    modelMtx = glm::translate(modelMtx, _currentPosition);

    // Move the character out of the grid, and rotate the character to correspond user input rotation
    modelMtx = glm::translate(modelMtx, glm::vec3(0.0f, 1.5f, 0.0f));
    modelMtx = glm::rotate(modelMtx, _characterAngle, CSCI441::Y_AXIS);

    // draw the popsickle components
    _drawPopsickleBody(modelMtx, viewMtx, projMtx);
    _drawPopsickleCone(modelMtx, viewMtx, projMtx);
    _drawPopsickleStick(modelMtx, viewMtx, projMtx);
    _drawPopsickleOrb(modelMtx, viewMtx, projMtx);
}


void Popsickle::_drawPopsickleBody(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {

    modelMtx = glm::scale( modelMtx, _scalePopsickleBody );

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorPopsickleBody[0]);

    CSCI441::drawSolidCube( 1.0 );
}

// A "head"
void Popsickle::_drawPopsickleCone(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {

    modelMtx = glm::translate( modelMtx, glm::vec3(0.0f, 1.0f, 0.0f) );
    modelMtx = glm::scale( modelMtx, _scalePopsickleBody );

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorPopsickleBody[0]);

    CSCI441::drawSolidCone( .52, .4, 16, 16 );
}

void Popsickle::_drawPopsickleStick(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx){

    modelMtx = glm::translate( modelMtx, glm::vec3(0.0f, -1.0f, 0.0f) );
    modelMtx = glm::scale(modelMtx, _scalePopsickleBody); // since legs are expressed in radio of torso
    modelMtx = glm::scale( modelMtx, _scalePopsickleStick );

    glUseProgram(_shaderProgramHandle);

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorPopsickleStick[0]);
    CSCI441::drawSolidCube( 1.0 );
}

// A character orb which rotates around the character when moving
// CW if character is moving forward
// CCW if character is moving backwards
void Popsickle::_drawPopsickleOrb(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {

    // rotate the orb, then translate it to outside of the character, then spin the orb
    modelMtx = glm::rotate(modelMtx, _orbRotationAngle, CSCI441::Y_AXIS);
    modelMtx = glm::translate( modelMtx, glm::vec3(1.5f, 0.0f, 0.0f) );
    modelMtx = glm::rotate(modelMtx, _orbSpinAngle, CSCI441::X_AXIS);
    modelMtx = glm::scale( modelMtx, glm::vec3(0.5f, 0.5f, 0.5f) );

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorPopsickleOrb[0]);

    CSCI441::drawSolidSphere(1, 2, 3);

}

void Popsickle::rotate(GLfloat rotationScalar) {
    GenericCharacter::rotate(rotationScalar);

    _characterHeading += rotationScalar;
}


void Popsickle::moveForward(GLfloat movementFactor) {
    GenericCharacter::moveForward(movementFactor);

    _orbRotationAngle += _orbRotationSpeed;
    if (_orbRotationAngle > 2.0f * M_PI){
        _orbRotationAngle = _orbRotationAngle -= 2.0f * M_PI;
    }
}

void Popsickle::moveBackward(GLfloat movementFactor){
    GenericCharacter::moveBackward(movementFactor);

    _orbRotationAngle -= _orbRotationSpeed;
    if (_orbRotationAngle < 0.0f){
        _orbRotationAngle = _orbRotationAngle -= 2.0f * M_PI;
    }
}


void Popsickle::_computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    // pre-compute the Model-View-Projection matrix on the CPU
    glm::mat4 mvpMtx = projMtx * viewMtx * modelMtx;
    // then send it to the shader on the GPU to apply to every vertex
    glProgramUniformMatrix4fv( _shaderProgramHandle, _shaderProgramUniformLocations.mvpMtx, 1, GL_FALSE, &mvpMtx[0][0] );

    glm::mat3 normalMtx = glm::mat3( glm::transpose( glm::inverse( modelMtx )));
    glProgramUniformMatrix3fv( _shaderProgramHandle, _shaderProgramUniformLocations.normalMtx, 1, GL_FALSE, &normalMtx[0][0] );
}
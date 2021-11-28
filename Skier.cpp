//
// Created by Alex Roush on 10/12/2021.
// Draws a SkiFree Skier where his hat bobs up and down.
// Note: this code utilizes some structure and code from the Plane.cpp provided in Lab05
//

#include "Skier.hpp"
//#include "MpEngine"


#ifndef M_PI
#define M_PI 3.14159265
#endif

Skier::Skier(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation,
             GLint materialColorUniformLocation) {

    _characterHeading = 0.0f;
    _currentPosition = glm::vec3(10.0f,0.0f,10.0f);

    _shaderProgramHandle = shaderProgramHandle;
    _shaderProgramUniformLocations.mvpMtx = mvpMtxUniformLocation;
    _shaderProgramUniformLocations.normalMtx = normalMtxUniformLocation;
    _shaderProgramUniformLocations.materialColor = materialColorUniformLocation;

    _scale = 0.3; /// sets overall size of skier

    _greenColor = glm::vec3(0.000f, 1.000f, 0.004f);
    _skinColor = glm::vec3(0.753f, 0.753f, 0.996f);
    _blackColor = glm::vec3(0.000f, 0.004f, 0.000f);
    _blueColor = glm::vec3(0.000f, 0.008f, 0.976f);
    _redColor = glm::vec3(0.976f, 0.000f, 0.000f);
    _pinkColor = glm::vec3(0.988f, 0.000f, 1.000f);

    _scaleHat = glm::vec3(1.0f, 1.0f, 1.0f) * _scale;
    _scaleHead = glm::vec3(1.0f, 1.0f, 1.0f) * _scale;
    _scaleGoggles = glm::vec3(1.9f, 0.6f, 1.0f) * _scale;
    _scaleNose = glm::vec3(1.0f, 1.0f, 1.0f) * _scale;
    _scaleMouth = glm::vec3(1.0f, 0.25f, 0.6f) * _scale;
    _scaleChin = glm::vec3(0.6f, 0.25f, 0.6f) * _scale;
    _scaleBody = glm::vec3(2.5f, 3.5f, 1.0f) * _scale;
    _scaleArm = glm::vec3(1.06f, 3.2f, 1.06f) * _scale;
    _scaleHand = glm::vec3(1.06f, 0.7f, 1.06f) * _scale;
    _scalePantsUp = glm::vec3(2.4f, 1.2f, 0.9f) * _scale;
    _scalePantLeg = glm::vec3(0.9f, 2.8f, 0.9f) * _scale;
    _scaleSki = glm::vec3(1.15f, 0.2f, 10.0f) * _scale;
    _scalePole = glm::vec3(1.0f, 1.0f, 1.0f) * _scale;

    _hatBobDirection = true; //true == up, false == down
    _characterHeight = 3.0f * _scale;
}

void Skier::drawCharacter(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {

    glUseProgram(_shaderProgramHandle);

    modelMtx = glm::translate(modelMtx, _currentPosition);

    modelMtx = glm::translate(modelMtx, glm::vec3(0.0f,0.5f * _scale,0.0f));
    modelMtx = glm::rotate(modelMtx, _characterAngle, CSCI441::Y_AXIS);

    modelMtx = glm::rotate(modelMtx, glm::radians(180.0f), CSCI441::Y_AXIS);

    _drawHatBody(modelMtx, viewMtx, projMtx);
    _drawHatPomPom(modelMtx, viewMtx, projMtx);
    _drawHeadTop(modelMtx, viewMtx, projMtx);
    _drawHeadMid(modelMtx, viewMtx, projMtx);
    _drawHeadBot(modelMtx, viewMtx, projMtx);
    _drawGoggles(modelMtx, viewMtx, projMtx);
    _drawNose(modelMtx, viewMtx, projMtx);
    _drawMouth(modelMtx, viewMtx, projMtx);
    _drawChin(modelMtx, viewMtx, projMtx);
    _drawBody(modelMtx, viewMtx, projMtx);
    _drawArm(1.0f, modelMtx, viewMtx, projMtx);
    _drawArm(-1.0f, modelMtx, viewMtx, projMtx);
    _drawHand(1.0f, modelMtx, viewMtx, projMtx);
    _drawHand(-1.0f, modelMtx, viewMtx, projMtx);
    _drawPantsUp(modelMtx, viewMtx, projMtx);
    _drawPantLeg(1.0f, modelMtx, viewMtx, projMtx);
    _drawPantLeg(-1.0f, modelMtx, viewMtx, projMtx);
    _drawSki(1.0f, modelMtx, viewMtx, projMtx);
    _drawSki(-1.0f, modelMtx, viewMtx, projMtx);
    _drawPoleShaft(1.0f, modelMtx, viewMtx, projMtx);
    _drawPoleShaft(-1.0f, modelMtx, viewMtx, projMtx);
    _drawPoleBasket(1.0f, modelMtx, viewMtx, projMtx);
    _drawPoleBasket(-1.0f, modelMtx, viewMtx, projMtx);
    _drawPoleBasketCover(1.0f,0.075f, modelMtx, viewMtx, projMtx);
    _drawPoleBasketCover(1.0f,-0.075f, modelMtx, viewMtx, projMtx);
    _drawPoleBasketCover(-1.0f,0.075f, modelMtx, viewMtx, projMtx);
    _drawPoleBasketCover(-1.0f,-0.075f, modelMtx, viewMtx, projMtx);
}

void Skier::_drawHatBody(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleHat);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,10.0f,0.0f));

    if (_hatBob > (0.012f / _scale)) {
        _hatBobDirection = false;
        _hatBob -= (0.0002 / _scale);
    } else if (_hatBob < (-0.012f / _scale)) {
        _hatBobDirection = true;
        _hatBob += (0.0002 / _scale);
    } else if (_hatBobDirection) {
        _hatBob += (0.002 / _scale);
    } else if (!_hatBobDirection){
        _hatBob -= (0.002 / _scale);
    }

    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f, _hatBob, 0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_redColor[0]);

    CSCI441::drawSolidCone(1.0,2.0,500,501);
}

void Skier::_drawHatPomPom(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleHat);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,12.0f,0.0f));

    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f, _hatBob, 0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_blueColor[0]);

    CSCI441::drawSolidSphere(0.3, 500, 501);
}

void Skier::_drawHeadTop(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleHead);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,9.5f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_skinColor[0]);

    CSCI441::drawSolidCylinder(1.0,0.8,0.6,200,201);
}

void Skier::_drawHeadMid(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleHead);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,8.0f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_skinColor[0]);

    CSCI441::drawSolidCylinder(1.0,1.0,1.5,200,201);
}

void Skier::_drawHeadBot(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleHead);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,7.0f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_skinColor[0]);

    CSCI441::drawSolidCylinder(0.3,1.0,1.0,200,201);
}

void Skier::_drawGoggles(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleGoggles);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,15.3f,0.6f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_greenColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawNose(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleNose);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,8.4f,1.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_blackColor[0]);

    CSCI441::drawSolidCone(0.25,0.6,50,51);
}

void Skier::_drawMouth(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleMouth);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,32.0f,1.2f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_blackColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawChin(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleChin);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,30.0f,0.6f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_blackColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawBody(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleBody);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,1.5f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_blueColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawArm(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleArm);
    modelMtx = glm::translate(modelMtx,glm::vec3(1.5f * side,1.65f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_pinkColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawHand(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleHand);
    modelMtx = glm::translate(modelMtx,glm::vec3(1.5f * side,4.755f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_skinColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawPantsUp(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scalePantsUp);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f,2.5f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_greenColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawPantLeg(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scalePantLeg);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.83f * side,0.358f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_greenColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawSki(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleSki);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.65f * side,-2.0f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_blueColor[0]);

    CSCI441::drawSolidCube(1.0);
}

void Skier::_drawPoleShaft(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scalePole);
    modelMtx = glm::translate(modelMtx,glm::vec3(1.6f * side,-0.4f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_redColor[0]);

    CSCI441::drawSolidCylinder(0.12,0.12,3.5,20,21);
}

void Skier::_drawPoleBasket(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scalePole);
    modelMtx = glm::translate(modelMtx,glm::vec3(1.6f * side,-0.2f,0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_redColor[0]);

    CSCI441::drawSolidCylinder(0.32,0.32,0.15,20,21);
}

void Skier::_drawPoleBasketCover(float side, float topBottom, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scalePole);
    modelMtx = glm::translate(modelMtx,glm::vec3(1.6f * side,-0.125f + topBottom,0.0f));
    modelMtx = glm::rotate(modelMtx, glm::radians(-90.0f), glm::vec3(1.0,0.0,0.0));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_redColor[0]);

    CSCI441::drawSolidDisk(0.0f, 0.32f, 20, 21);
}

void Skier::moveForward(GLfloat movementFactor) {
    GenericCharacter::moveForward(movementFactor);
}

void Skier::moveBackward(GLfloat movementFactor) {
    GenericCharacter::moveBackward(movementFactor);
}

void Skier::rotate(GLfloat rotateSpd) {
    GenericCharacter::rotate(rotateSpd);
    _characterHeading += rotateSpd;
}

// From Lab05 Plane.cpp
void Skier::_computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const {
    // precompute the Model-View-Projection matrix on the CPU
    glm::mat4 mvpMtx = projMtx * viewMtx * modelMtx;
    // then send it to the shader on the GPU to apply to every vertex
    glProgramUniformMatrix4fv( _shaderProgramHandle, _shaderProgramUniformLocations.mvpMtx, 1, GL_FALSE, &mvpMtx[0][0] );

    glm::mat3 normalMtx = glm::mat3( glm::transpose( glm::inverse( modelMtx )));
    glProgramUniformMatrix3fv( _shaderProgramHandle, _shaderProgramUniformLocations.normalMtx, 1, GL_FALSE, &normalMtx[0][0] );
}


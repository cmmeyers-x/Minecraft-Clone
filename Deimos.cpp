//
// Created by alexk on 10/12/2021.
//


//
// Created by lukewakumoto on 10/11/2021.
//

#ifndef LAB05_Deimos_HPP
#define LAB05_Deimos_HPP

#include "Deimos.hpp"


#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <CSCI441/objects.hpp>
#include <CSCI441/OpenGLUtils.hpp>

Deimos::Deimos( GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation, GLint materialColorUniformLocation ) {
    _propAngle = 0.0f;
    _propAngleRotationSpeed = M_PI / 16.0f;

    _shaderProgramHandle                            = shaderProgramHandle;
    _shaderProgramUniformLocations.mvpMtx           = mvpMtxUniformLocation;
    _shaderProgramUniformLocations.normalMtx        = normalMtxUniformLocation;
    _shaderProgramUniformLocations.materialColor    = materialColorUniformLocation;

    _rotatePlaneAngle = M_PI / 2.0f;

    _colorHead = glm::vec3( 1.0f, 1.0f, 1.0f );
    _scaleHead = glm::vec3( 1.0f, 1.0f, 1.0f );
    _transHead = glm::vec3(_headHeight, 0.0f, 0.0f);

    _colorHand = glm::vec3( 1.0f, 1.0f, 1.0f );
    _scaleHand = glm::vec3( 1.5f, 0.5f, 1.0f );
    _rotateWingAngle = M_PI / 2.0f;

    _colorTorso = glm::vec3(0.53f, 0.53f, 0.53f);
    _transTorso = glm::vec3(_torsoHeight, 0.0f, 0.0f);
    _rotateTorsoAngle = M_PI / 2.0f;

    _colorProp = glm::vec3( 1.0f, 1.0f, 1.0f );
    _scaleProp = glm::vec3( 1.1f, 1.0f, 0.025f );
    _transProp = glm::vec3( 0.1f, 0.0f, 0.0f );

    _colorTail = glm::vec3( 1.0f, 1.0f, 0.0f );

    _colorFoot = glm::vec3(0.53f, 0.53f, 0.53f);

    _colorGun = glm::vec3(0.3254f, 0.3372f, 0.3529f);

    _heading = 0;
    _currentPos = glm::vec3(0,0,0);

    _characterHeight = 10;
    _characterHeading = 0.0f;
}


glm::vec3 Deimos::getCurrentPosition() {
    return _currentPos;
}
void Deimos::drawCharacter( glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) {
    glUseProgram( _shaderProgramHandle );
    // Move the character to its current position in world space
    modelMtx = glm::translate(modelMtx, _currentPosition);

    // Move the character out of the grid, and rotate the character to correspond user input rotation
   // modelMtx = glm::translate(modelMtx, glm::vec3(10.0f, 0.0f, 10.0f));
    modelMtx = glm::rotate(modelMtx, _characterAngle, CSCI441::Y_AXIS);

   // modelMtx = glm::translate(modelMtx, _currentPos);
    modelMtx = glm::rotate( modelMtx, -_rotatePlaneAngle, CSCI441::Y_AXIS );
    modelMtx = glm::rotate( modelMtx, _rotatePlaneAngle, CSCI441::Z_AXIS );
    modelMtx = glm::scale(modelMtx, glm::vec3(0.75, 0.75, 0.75));
    _drawHead(modelMtx, viewMtx, projMtx);        // the body of our plane
    _drawTorso(modelMtx, viewMtx, projMtx);        // the nose
    _drawHand(true, modelMtx, viewMtx, projMtx);  // the left wing
    _drawHand(false, modelMtx, viewMtx, projMtx); // the right wing
    _drawFoot(true, modelMtx, viewMtx, projMtx);
    _drawFoot(false, modelMtx, viewMtx, projMtx);

    //_drawPlanePropeller(modelMtx, viewMtx, projMtx);   // the propeller
    //_drawPlaneTail(modelMtx, viewMtx, projMtx);        // the tail
}

void Deimos::flyForward() {
    _propAngle += _propAngleRotationSpeed;
    if( _propAngle > 2.0f * M_PI ) _propAngle -= 2.0f * M_PI;
}

void Deimos::flyBackward() {
    _propAngle -= _propAngleRotationSpeed;
    if( _propAngle < 0.0f ) _propAngle += 2.0f * M_PI;
}

void Deimos::_drawHead(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const {

    glm::vec3 skyColor(.863f, .78f, .235f);
    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &skyColor[0]);
    CSCI441::drawSolidSphere(1000,64,64);

    modelMtx = glm::translate(modelMtx, _transHead);
    modelMtx = glm::scale( modelMtx, _scaleHead);

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorHead[0]);

    CSCI441::drawSolidSphere(1.5, 32, 32);

    modelMtx = glm::translate(modelMtx, glm::vec3(-.65, 1.0, 0.0));
    modelMtx = glm::rotate(modelMtx,  0.20f, CSCI441::Z_AXIS );
    modelMtx = glm::rotate(modelMtx,  0.10f, CSCI441::X_AXIS );
    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorHead[0]);
    CSCI441::drawSolidCylinder(0.1, 0.1, 1.5, 16, 16);
}

void Deimos::_drawHand(bool leftHand, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const {
    //modelMtx = glm::scale( modelMtx, _scaleHand );
    int shake_magnitude = 4;
    double randDist = (double(rand() % shake_magnitude - shake_magnitude*2)) / 100;
    if( leftHand ) {
        modelMtx = glm::translate(modelMtx, glm::vec3(_torsoHeight / 2.0, 0.0, 2.5));

        modelMtx = glm::translate(modelMtx, glm::vec3(randDist, randDist, randDist));
    }
    else {
        modelMtx = glm::translate(modelMtx, glm::vec3(_characterHeight - 1.5, 5.5, -0.5));

        modelMtx = glm::translate(modelMtx, glm::vec3(randDist, randDist, randDist)); // give random shake to hands
    }
    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorHand[0]);

    CSCI441::drawSolidSphere( 0.5, 16, 16 );

    if (!leftHand){

        modelMtx = glm::translate(modelMtx, glm::vec3(.2,0.0,0.0));
        modelMtx = glm::scale(modelMtx, glm::vec3(4.0,1.0,0.5));

        _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

        glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorGun[0]);

        CSCI441::drawSolidCube(0.40);

        modelMtx = glm::scale(modelMtx, glm::vec3(1/4.0,1.0,1.0));
        modelMtx = glm::translate(modelMtx, glm::vec3(0.5,1.0,0.0));
        modelMtx = glm::scale(modelMtx, glm::vec3(1.5,4.0,0.5));

        _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

        glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorGun[0]);
        CSCI441::drawSolidCube(0.40);

    }

}

void Deimos::_drawFoot(bool leftFoot, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const {
    //modelMtx = glm::scale( modelMtx, _scaleHand );

    if( leftFoot )
        modelMtx = glm::translate(modelMtx, glm::vec3(0.5, 0.5, 1.5));
    else {
        modelMtx = glm::translate(modelMtx, glm::vec3(0.5, 0.5, -1.5));
    }
    modelMtx = glm::scale(modelMtx, glm::vec3(0.75, 2.25, 1.0));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorFoot[0]);

    CSCI441::drawSolidSphere( 0.5, 16, 16 );



}

void Deimos::_drawTorso(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const {
    modelMtx = glm::translate(modelMtx, _transTorso);
    modelMtx = glm::rotate( modelMtx, _rotateTorsoAngle, CSCI441::Z_AXIS );

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorTorso[0]);

    CSCI441::drawSolidCylinder(1.0, 1.0, _torsoLength, 16, 16);


    modelMtx = glm::translate(modelMtx, glm::vec3(0.0, 0.0, 0.0));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorTorso[0]);

    CSCI441::drawSolidSphere(1.0,16,16);
}

void Deimos::moveForward(GLfloat movementFactor){
    GenericCharacter::moveForward(movementFactor);
    //_currentPos += glm::vec3(movementFactor*cos(_heading), 0, movementFactor*sin(_heading));

}

void Deimos::moveBackward(GLfloat movementFactor) {
    GenericCharacter::moveBackward(movementFactor);
    //_currentPos -= glm::vec3(movementFactor*cos(_heading), movementFactor*cos(_heading), movementFactor*sin(_heading));
}



void Deimos::rotate(GLfloat rotationScalar) {
    GenericCharacter::rotate(rotationScalar);

    _characterHeading += rotationScalar;
}

void Deimos::_computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const {


    // precompute the Model-View-Projection matrix on the CPU
    glm::mat4 mvpMtx = projMtx * viewMtx * modelMtx;
    // then send it to the shader on the GPU to apply to every vertex
    glProgramUniformMatrix4fv( _shaderProgramHandle, _shaderProgramUniformLocations.mvpMtx, 1, GL_FALSE, &mvpMtx[0][0] );

    glm::mat3 normalMtx = glm::mat3( glm::transpose( glm::inverse( modelMtx )));
    glProgramUniformMatrix3fv( _shaderProgramHandle, _shaderProgramUniformLocations.normalMtx, 1, GL_FALSE, &normalMtx[0][0] );
}


/*
void Deimos::_drawPlanePropeller(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const {
    glm::mat4 modelMtx1 = glm::translate( modelMtx, _transProp );
    modelMtx1 = glm::rotate( modelMtx1, _propAngle, CSCI441::X_AXIS );
    modelMtx1 = glm::scale( modelMtx1, _scaleProp );

    _computeAndSendMatrixUniforms(modelMtx1, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorProp[0]);

    CSCI441::drawSolidCube( 0.1 );

    glm::mat4 modelMtx2 = glm::translate( modelMtx, _transProp );
    modelMtx2 = glm::rotate( modelMtx2, static_cast<GLfloat>(M_PI / 2.0f) + _propAngle, CSCI441::X_AXIS );
    modelMtx2 = glm::scale( modelMtx2, _scaleProp );

    _computeAndSendMatrixUniforms(modelMtx2, viewMtx, projMtx);

    CSCI441::drawSolidCube( 0.1 );
}

void Deimos::_drawPlaneTail(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const {
    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_colorTail[0]);

    CSCI441::drawSolidCone( 0.02, 0.1, 16, 16 );
}
*/
#endif //LAB05_Deimos_HPP
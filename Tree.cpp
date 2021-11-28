//
// Created by Alex Roush on 10/13/2021.
// Draws a treee.
// Note: this code utilizes some structure and code from the Plane.cpp provided in Lab05.
//

#include "Tree.hpp"
#include "MpEngine.hpp"

#include <CSCI441/objects.hpp>

#ifndef M_PI
#define M_PI 3.14159265
#endif

Tree::Tree(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation,
               GLint materialColorUniformLocation) {

    _shaderProgramHandle = shaderProgramHandle;
    _shaderProgramUniformLocations.mvpMtx = mvpMtxUniformLocation;
    _shaderProgramUniformLocations.normalMtx = normalMtxUniformLocation;
    _shaderProgramUniformLocations.materialColor = materialColorUniformLocation;

    _scale = 0.05; // sets overall size of tree (independent of scaling in engine)

    _greenColor = glm::vec3(0.164f,0.392f,0.149f);
    _brownColor = glm::vec3(0.392f,0.270f,0.149f);

    _scaleLayers = glm::vec3(1.0f, 1.0f, 1.0f);
}

void Tree::drawTree(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    glUseProgram(_shaderProgramHandle);

    modelMtx = glm::scale(modelMtx, glm::vec3(_scale, _scale, _scale));

    _drawLayer(0.0f, 1.0f, modelMtx, viewMtx, projMtx);
    _drawLayer(3.0f, 0.8f, modelMtx, viewMtx, projMtx);
    _drawLayer(5.4f, 0.6f, modelMtx, viewMtx, projMtx);
    _drawLayer(7.1f, 0.4f, modelMtx, viewMtx, projMtx);
    _drawLayer(8.3f, 0.2f, modelMtx, viewMtx, projMtx);
    _drawTrunk(modelMtx, viewMtx, projMtx);
}

void Tree::_drawLayer(GLfloat yOffset, GLfloat diamCoeff, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleLayers);
    modelMtx = glm::translate(modelMtx,glm::vec3(0.0f, 1.0f + yOffset, 0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_greenColor[0]);

    CSCI441::drawSolidCone(4.0f * diamCoeff, 3.0f * diamCoeff, 5, 6);
}

void Tree::_drawTrunk(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    modelMtx = glm::scale(modelMtx, _scaleLayers);
    modelMtx = glm::translate(modelMtx, glm::vec3(0.0f, 0.0f, 0.0f));

    _computeAndSendMatrixUniforms(modelMtx, viewMtx, projMtx);

    glUniform3fv(_shaderProgramUniformLocations.materialColor, 1, &_brownColor[0]);

    CSCI441::drawSolidCylinder(0.5f, 0.15f, 9.79f, 20, 21);
}

// From Lab05 Plane.cpp
void Tree::_computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const {
    // precompute the Model-View-Projection matrix on the CPU
    glm::mat4 mvpMtx = projMtx * viewMtx * modelMtx;
    // then send it to the shader on the GPU to apply to every vertex
    glProgramUniformMatrix4fv( _shaderProgramHandle, _shaderProgramUniformLocations.mvpMtx, 1, GL_FALSE, &mvpMtx[0][0] );

    glm::mat3 normalMtx = glm::mat3( glm::transpose( glm::inverse( modelMtx )));
    glProgramUniformMatrix3fv( _shaderProgramHandle, _shaderProgramUniformLocations.normalMtx, 1, GL_FALSE, &normalMtx[0][0] );
}

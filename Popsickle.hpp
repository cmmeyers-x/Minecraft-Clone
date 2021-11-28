//
// Created by alexk on 10/12/2021.
//

#ifndef MP_POPSICKLE_HPP
#define MP_POPSICKLE_HPP

#include "GenericCharacter.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <CSCI441/objects.hpp>
#include <CSCI441/OpenGLUtils.hpp>

class Popsickle : public GenericCharacter {

public:
    Popsickle( GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation, GLint materialColorUniformLocation );

    void drawCharacter( glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx );

    void moveForward(GLfloat movementFactor);
    void moveBackward(GLfloat movementFactor);
    void rotate(GLfloat rotationScalar);
    void incrementOrbSpinAngle();

private:
    GLuint _shaderProgramHandle;

    struct ShaderProgramUniformLocations {
        /// \desc location of the precomputed ModelViewProjection matrix
        GLint mvpMtx;
        /// \desc location of the precomputed Normal matrix
        GLint normalMtx;
        /// \desc location of the material diffuse color
        GLint materialColor;
    } _shaderProgramUniformLocations;

    glm::vec3 _scalePopsickleBody;
    glm::vec3 _scalePopsickleStick;


    glm::vec3 _colorPopsickleBody;
    glm::vec3 _colorPopsickleStick;
    glm::vec3 _colorPopsickleOrb;

    void _drawPopsickleBody(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPopsickleCone(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPopsickleStick(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPopsickleOrb(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);

    void _computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);

    GLfloat _orbRotationAngle; // rotate around character
    GLfloat _orbSpinAngle; // constantly spin around itself
    GLfloat _orbRotationSpeed;

    // An angle to describe where
    // the character is facing
    GLfloat _characterHeading;

};

#endif //MP_POPSICKLE_HPP



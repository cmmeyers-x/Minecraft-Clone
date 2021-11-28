//
// Created by alexk on 10/14/2021.
//

#ifndef MP_FLASHLIGHT_HPP
#define MP_FLASHLIGHT_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <CSCI441/objects.hpp>

#include "GenericCharacter.hpp"

class Flashlight : public GenericCharacter {
public:
    Flashlight(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation, GLint materialColorUniformLocation);
    void drawCharacter(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void moveForward(GLfloat movementFactor);
    void moveBackward(GLfloat movementFactor);
    void rotate(GLfloat rotateSpd);
    glm::vec3 getDirection();



private:
    GLuint _shaderProgramHandle;

    GLfloat _characterHeading;

    struct ShaderProgramUniformLocations {
        GLint mvpMtx;
        GLint normalMtx;
        GLint materialColor;
    } _shaderProgramUniformLocations;

    glm::vec3 _direction;

    glm::vec3 _color;

    void _computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const;

};

#endif //MP_FLASHLIGHT_HPP

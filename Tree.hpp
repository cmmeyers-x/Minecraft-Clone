//
// Created by Alex Roush on 10/13/2021.
// Draws a treee.
// Note: this code utilizes some structure and code from the Plane.cpp provided in Lab05
//

#ifndef MP_MP_TREE_HPP
#define MP_MP_TREE_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>

class Tree {
public:
    Tree(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation, GLint materialColorUniformLocation);
    void drawTree(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);

private:
    GLfloat _scale;

    GLuint _shaderProgramHandle;

    struct ShaderProgramUniformLocations {
        GLint mvpMtx;
        GLint normalMtx;
        GLint materialColor;
    } _shaderProgramUniformLocations;

    glm::vec3 _greenColor;
    glm::vec3 _brownColor;

    glm::vec3 _scaleLayers;

    void _computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const;

    void _drawLayer(GLfloat yOffset, GLfloat diamCoeff, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawTrunk(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
};

#endif // MP_MP_TREE_HPP

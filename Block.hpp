//
// Created by cmmeyers on 11/28/21.
//

#ifndef MP_BLOCK_HPP
#define MP_BLOCK_HPP
#include <CSCI441/ShaderProgram.hpp>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <CSCI441/OpenGLEngine.hpp>
#include <string>

class Block {



public:
    Block(glm::vec3 blockLocation);
    void drawBlock(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);

    // Creates static VAOs and VBOs send vertex data to gpu for future rendering
    void setupBlock(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint vPosAttributeLocation);
    void cleanupBlock();




private:
    // the position of the block in the world
    glm::vec3 _blockLocation;

    struct BlockDescriptors {
        GLuint _blockVAO;
        GLuint _blockVBO;
    } _staticBlockDescriptors;

    /// \desc handle of the shader program to use when drawing the block
    GLuint _shaderProgramHandle;
    /// \desc stores the uniform locations needed for the plan information
    struct ShaderProgramUniformLocations {
        /// \desc location of the precomputed ModelViewProjection matrix
        GLint mvpMtx;
    } _shaderProgramUniformLocations;

    struct ShaderProgramAttributes {
        /// \desc the vertex position
        GLint vPos;
    } _blockShaderProgramAttributes;

};


#endif //MP_BLOCK_HPP

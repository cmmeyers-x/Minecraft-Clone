//
// Created by cmmeyers on 12/5/21.
//

#ifndef MP_SKYBOX_HPP
#define MP_SKYBOX_HPP
#include <CSCI441/ShaderProgram.hpp>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <CSCI441/OpenGLEngine.hpp>
#include <string>


class Skybox {
public:
    Skybox();
    void drawSky(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);


    // Creates static VAOs and VBOs send vertex data to gpu for future rendering
    void setupSky(GLuint shaderProgramHandle, GLint mvpMatrix, GLint textureMap, GLint vPos, GLint vertexNormal, GLint texCoord);
    void setTexture(std::string name, GLuint handle);
    std::string getTextureName();
    void cleanupSky();


private:
    // the position of the block in the world
   // glm::vec3 _blockLocation;
    std::string textureName;

    struct BlockDescriptors {
        GLuint _skyVAO;
        GLuint _skyVBO;
    } _skyDescriptors;

    /// \desc handle of the shader program to use when drawing the block
    GLuint _shaderProgramHandle;
    /// \desc stores the uniform locations needed for the plan information

    struct shaderUniformLocations {
        GLint mvpMatrix;
        GLint textureMap;
    }_shaderUniformLocations;

    struct BlockShaderAttributeLocations{
        GLint vPos;
        GLint vertexNormal;
        GLint texCoord;
    }_shaderAttributeLocations;


    const GLfloat _skySize = 100.0;
};


#endif //MP_SKYBOX_HPP

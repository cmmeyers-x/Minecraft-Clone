//
// Created by Alex Roush on 10/7/2021.
// Header for cpp that draws the SkiFree Skier where his hat bobs up and down.
// Note: this code utilizes some structure and code from the Plane.cpp provided in Lab05
//

#ifndef MP_MP_SKIER_HPP
#define MP_MP_SKIER_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <CSCI441/objects.hpp>

#include "GenericCharacter.hpp"

class Skier : public GenericCharacter {
public:
    Skier(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation, GLint materialColorUniformLocation);
    void drawCharacter(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void moveForward(GLfloat movementFactor);
    void moveBackward(GLfloat movementFactor);
    void rotateLeft();
    void rotateRight();

    void rotate(GLfloat rotateSpd);

    GLfloat getSkierPhi() const;
    glm::vec3 getHeading();

    glm::vec3 globalPosition;

    GLfloat worldWidth;
    GLfloat worldHeight;

    glm::vec3 getCurrentPosition();

    void setWorldWidth(GLfloat width);
    void setWorldHeight(GLfloat height);

private:
    GLfloat _scale;
    GLuint _shaderProgramHandle;
    GLfloat _skierPhi;

    float _hatBob;
    bool _hatBobDirection;

    GLfloat _characterHeading;

    struct ShaderProgramUniformLocations {
        GLint mvpMtx;
        GLint normalMtx;
        GLint materialColor;
    } _shaderProgramUniformLocations;

    glm::vec3 _scaleHat;
    glm::vec3 _scaleGoggles;
    glm::vec3 _scaleNose;
    glm::vec3 _scaleMouth;
    glm::vec3 _scaleChin;
    glm::vec3 _scaleBody;
    glm::vec3 _scaleArm;
    glm::vec3 _scaleHand;
    glm::vec3 _scalePantsUp;
    glm::vec3 _scalePantLeg;
    glm::vec3 _scaleSki;
    glm::vec3 _scalePole;
    glm::vec3 _scaleHead;

    glm::vec3 _greenColor;
    glm::vec3 _skinColor;
    glm::vec3 _blackColor;
    glm::vec3 _blueColor;
    glm::vec3 _redColor;
    glm::vec3 _pinkColor;

    void _computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const;

    void _drawHatPomPom(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawHatBody(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawGoggles(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawNose(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawMouth(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawChin(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawBody(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawArm(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawHand(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPantsUp(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPantLeg(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawSki(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPoleShaft(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPoleBasket(float side, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawPoleBasketCover(float side, float topBottom, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawHeadTop(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawHeadMid(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void _drawHeadBot(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
};

#endif // MP_MP_SKIER_HPP

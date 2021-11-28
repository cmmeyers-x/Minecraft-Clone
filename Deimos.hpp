//
// Created by alexk on 10/12/2021.
//

#ifndef MP_DEIMOS_HPP
#define MP_DEIMOS_HPP

#include <GL/glew.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "GenericCharacter.hpp"


class Deimos : public GenericCharacter {
public:
    /// \desc creates a simple plane that gives the appearance of flight
    /// \param shaderProgramHandle shader program handle that the plane should be drawn using
    /// \param mvpMtxUniformLocation uniform location for the full precomputed MVP matrix
    /// \param normalMtxUniformLocation uniform location for the precomputed Normal matrix
    /// \param materialColorUniformLocation uniform location for the material diffuse color
    Deimos( GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation, GLint materialColorUniformLocation );

    /// \desc draws the model plane for a given MVP matrix
    /// \param modelMtx existing model matrix to apply to plane
    /// \param viewMtx camera view matrix to apply to plane
    /// \param projMtx camera projection matrix to apply to plane
    /// \note internally uses the provided shader program and sets the necessary uniforms
    /// for the MVP and Normal Matrices as well as the material diffuse color
    void drawDeimos( glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx );

    glm::vec3 getPosition();

    /// \desc simulates the plane flying forward by rotating the propeller clockwise
    void flyForward();
    /// \desc simulates the plane flying backward by rotating the propeller counter-clockwise
    void flyBackward();

    void moveForward(GLfloat movementFactor );
    void moveBackward(GLfloat movementFactor);
    void rotate(GLfloat rotateSpd);

    glm::vec3 getCurrentPosition();

    GLfloat _heading = 0;
    glm::vec3 _currentPos;

private:
    /// \desc current angle of rotation for the propeller
    GLfloat _propAngle;
    /// \desc one rotation step
    GLfloat _propAngleRotationSpeed;

    /// \desc handle of the shader program to use when drawing the plane
    GLuint _shaderProgramHandle;
    /// \desc stores the uniform locations needed for the plan information
    struct ShaderProgramUniformLocations {
        /// \desc location of the precomputed ModelViewProjection matrix
        GLint mvpMtx;
        /// \desc location of the precomputed Normal matrix
        GLint normalMtx;
        /// \desc location of the material diffuse color
        GLint materialColor;
    } _shaderProgramUniformLocations;


    glm::vec3 _colorGun;

    GLfloat _headHeight = 10;

    GLfloat _torsoHeight = 8;
    GLfloat _torsoLength = 6;
    /// \desc angle to rotate our plane at
    GLfloat _rotatePlaneAngle;

    /// \desc color the plane's body
    glm::vec3 _colorHead;
    /// \desc amount to scale the plane's body by
    glm::vec3 _scaleHead;

    glm::vec3 _transHead;

    /// \desc color the plane's wing
    glm::vec3 _colorHand;
    /// \desc amount to scale the plane's wing by
    glm::vec3 _scaleHand;
    /// \desc amount to rotate the plane's wing by
    GLfloat _rotateWingAngle;

    /// \desc color the plane's nose
    glm::vec3 _colorTorso;

    glm::vec3 _scaleTorso;
    glm::vec3 _transTorso;
    GLfloat _rotateTorsoAngle;

    /// \desc amount to rotate the plane's nose by
    GLfloat _rotateNoseAngle;

    /// \desc color the plane's propeller
    glm::vec3 _colorProp;
    /// \desc amount to scale the plane's propeller by
    glm::vec3 _scaleProp;
    /// \desc amount to translate the plane's propeller by
    glm::vec3 _transProp;

    /// \desc color the plane's tail
    glm::vec3 _colorTail;

    glm::vec3 _colorFoot;

    GLfloat _characterHeading;

    /// \desc draws just the plane's body
    /// \param modelMtx existing model matrix to apply to plane
    /// \param viewMtx camera view matrix to apply to plane
    /// \param projMtx camera projection matrix to apply to plane
    void _drawHead(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const;
    /// \desc draws a single wing
    /// \param leftWing true if left wing, false if right wing (controls rotation)
    /// \param modelMtx existing model matrix to apply to plane
    /// \param viewMtx camera view matrix to apply to plane
    /// \param projMtx camera projection matrix to apply to plane
    void _drawHand(bool leftHand, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const;
    /// \desc draws the nose of the plane
    /// \param modelMtx existing model matrix to apply to plane
    /// \param viewMtx camera view matrix to apply to plane
    /// \param projMtx camera projection matrix to apply to plane
    void _drawTorso(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const;
    /// \desc draws the two propeller pieces
    /// \param modelMtx existing model matrix to apply to plane
    /// \param viewMtx camera view matrix to apply to plane
    /// \param projMtx camera projection matrix to apply to plane
    void _drawPlanePropeller(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const;
    /// \desc draws the tail of the plane
    /// \param modelMtx existing model matrix to apply to plane
    /// \param viewMtx camera view matrix to apply to plane
    /// \param projMtx camera projection matrix to apply to plane
    void _drawPlaneTail(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const;

    void _drawFoot(bool leftFoot, glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) const;

    void drawCharacter(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx );

    /// \desc precomputes the matrix uniforms CPU-side and then sends them
    /// to the GPU to be used in the shader for each vertex.  It is more efficient
    /// to calculate these once and then use the resultant product in the shader.
    /// \param modelMtx model transformation matrix
    /// \param viewMtx camera view matrix
    /// \param projMtx camera projection matrix
    void _computeAndSendMatrixUniforms(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) const;
};


#endif //MP_DEIMOS_HPP

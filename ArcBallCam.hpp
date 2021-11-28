//
// Created by alexk on 10/12/2021.
//

#ifndef MP_ARCBALLCAM_HPP
#define MP_ARCBALLCAM_HPP

#endif //MP_ARCBALLCAM_HPP
#include "Camera.hpp"
#include <cmath>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

class ArcBallCam : public CSCI441::Camera {

public:

    ArcBallCam();

    void recomputeOrientation() override;

    void moveForward(GLfloat movementFactor) override;
    void moveBackward(GLfloat movementFactor) override;

    void changeHeading(GLfloat rotationScalar);


    void zoomIn();
    void zoomOut();
    void rotate(GLfloat dTheta, GLfloat dPhi);

private:
    /// \desc updates the look at point and recalculates the view matrix

    const GLint MAX_RADIUS = 200;
    const GLint MIN_RADIUS = 2;
    const GLfloat zoomScalar = 0.25f; // controls how fast the zoom is


    GLfloat _headingAngle;
    GLfloat _characterHeight;
};
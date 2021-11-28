//
// Created by alexk on 10/12/2021.
//

#include "ArcBallCam.hpp"
// Constructor, call parent class constructor
ArcBallCam::ArcBallCam() : Camera() {
    _headingAngle = 0;
    _lookAtPoint = glm::vec3(0.0f, 0.0f, 0.0f);
}

void ArcBallCam::recomputeOrientation(){
    // get a vector going from the center of the sphere to the edge of the sphere
    float x =  sin(_theta) * sin(_phi);
    float y = -cos(_phi);
    float z = -cos(_theta) * sin(_phi);

    // Set the camera to look in that direction
    _direction = glm::normalize(glm::vec3(x,y,z));

    // offset the _position by the look at point and then use the vector / radius to place it on the sphere
    _position = _lookAtPoint + (_radius * _direction);

    // Do the glm::lookatCall to get the _viewMatrix
    computeViewMatrix();
}

void ArcBallCam::rotate(GLfloat dTheta, GLfloat dPhi) {
    _theta += dTheta;
    _phi += dPhi;

    // bounds check phi
    if(_phi <= 0)       _phi = 0+0.001;
    if(_phi >= M_PI)    _phi = M_PI-0.001;

    recomputeOrientation();
}



// move the look at point, and position by a constant amount
// Sin and Cos are used to account for the rotation of the camera, and the character it's attached to
void ArcBallCam::moveForward(GLfloat movementFactor) {

    _lookAtPoint.x -= (sin(_headingAngle) * movementFactor);
    _lookAtPoint.z -= (cos(_headingAngle) * movementFactor);
    recomputeOrientation();
}

// move the look at point, and position by a constant amount
void ArcBallCam::moveBackward(GLfloat movementFactor) {
    _lookAtPoint.x += (sin(_headingAngle) * movementFactor);
    _lookAtPoint.z += (cos(_headingAngle) * movementFactor);
    recomputeOrientation();
}

// rotate the heading which affects how the char moves on the x,y plane
void ArcBallCam::changeHeading(GLfloat rotationScalar) {
    _headingAngle += rotationScalar;
}

// Zoom the camera in by adjusting the radius of the sphere
void ArcBallCam::zoomIn(){
    if (_radius - zoomScalar > MIN_RADIUS){
        _radius -= zoomScalar;
    }
    recomputeOrientation();
}

void ArcBallCam::zoomOut(){

    if (_radius + zoomScalar < MAX_RADIUS){
        _radius += zoomScalar;
    }
    recomputeOrientation();
}
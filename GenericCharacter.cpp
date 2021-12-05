//
// Created by alexk on 10/12/2021.
//

#include "GenericCharacter.hpp"
#include <iostream>

void GenericCharacter::moveForward(GLfloat movementFactor){
    _currentPosition.x -= (sin(_characterAngle) * movementFactor);
    _currentPosition.z -= (cos(_characterAngle) * movementFactor);
}

void GenericCharacter::moveBackward(GLfloat movementFactor){
    _currentPosition.x += (sin(_characterAngle) * movementFactor);
    _currentPosition.z += (cos(_characterAngle) * movementFactor);
}


//
//void GenericCharacter::applyForce(glm::vec3 force){
//    _currentPosition.x += (sin(_characterAngle) * movementFactor);
//    _currentPosition.z += (cos(_characterAngle) * movementFactor);
//}




void GenericCharacter::rotate(GLfloat rotateSpeed) {
    _characterAngle += rotateSpeed;
}

glm::vec3 GenericCharacter::getCurrentPosition() {
    return _currentPosition;
}

GLfloat GenericCharacter::getCharacterAngle() {
  return _characterAngle;
}

GLfloat GenericCharacter::getCharacterHeight() {
    return _characterHeight;
}
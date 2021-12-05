//
// Created by alexk on 10/12/2021.
//

#ifndef MP_GENERICCHARACTER_HPP
#define MP_GENERICCHARACTER_HPP


#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <CSCI441/OpenGLEngine.hpp>


class GenericCharacter{
public:

    virtual void drawCharacter( glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx ) = 0;
    virtual void moveForward(GLfloat movementFactor);
    virtual void moveBackward(GLfloat movementFactor);
    virtual void rotate(GLfloat rotateSped);
 //   virtual void applyForce(glm::vec3 force);
//    virtual void update();


    glm::vec3 getCurrentPosition();
    GLfloat getCharacterAngle(); // returns theta relative to x,z plane
    GLfloat getCharacterHeight();

protected:
    glm::vec3 _currentPosition;
    GLfloat _characterAngle;
    GLfloat _characterHeight;
  //  GLfloat _characterMass;
 //  GLfloat _characterAcceleration;
private:

};

#endif //MP_GENERICCHARACTER_HPP
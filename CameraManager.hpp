//
// Created by cmmeyers on 10/11/21.
//

#ifndef MP_CAMERAMANAGER_HPP
#define MP_CAMERAMANAGER_HPP

#endif //MP_CAMERAMANAGER_HPP

#include <cmath>
#include <CSCI441/OpenGLEngine.hpp>
#include <CSCI441/ShaderProgram.hpp>
#include <CSCI441/FreeCam.hpp>
#include "Camera.hpp"
#include "ArcBallCam.hpp"
#include "GenericCharacter.hpp"
#include "FreeCam.hpp"
#include "Popsickle.hpp"
#include "Skier.hpp"
#include "Deimos.hpp"
#include "Flashlight.hpp"

class CameraManager {
public:
    CameraManager();
    ~CameraManager();

    void initPlayers(GLuint shaderProgramHandle, GLint mvpMtxUniformLocation, GLint normalMtxUniformLocation,
                     GLint materialColorUniformLocation);

    enum CameraType {
        freeCam = 0,
        arcballCam = 1,
        firstPersonCam = 2
    };

    enum Players {
        player1 = 0,
        player2 = 1,
        player3 = 2,
        player4 = 3
    };

    // Iterates through the player Enum and draws all chars
    void drawAllCharacters(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);

    // Switch between camera and Players
    void setCamera(CameraType cameraEnum);
    void setSecondCamera(CameraType cameraEnum);
    void setPlayer(Players playerEnum);

    // Moves both the currently selected camera & player
    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();

    // Only for Arcball
    void zoomOut();
    void zoomIn();

    // Gets the currently selected Camera
    CSCI441::Camera* getCamera();
    CSCI441::Camera* getSecondCamera();
    GenericCharacter* getPlayer();

    void setCameraPoint();

    bool secondCameraEnabled();
    void toggleSecondCamera();

private:
    GLfloat movementSpeed;
    GLfloat rotateSpeed;

    GLboolean _secondCameraEnabled; // tells us whether or not to draw the first person camera

    static const int NUM_CAMS = 3;
    CSCI441::Camera* cameras[NUM_CAMS];

    CameraType _currentCamera;
    Players _currentPlayer;

    static const int NUM_PLAYERS = 4;
    GenericCharacter* characters[NUM_PLAYERS];
};
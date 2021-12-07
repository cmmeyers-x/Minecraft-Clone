/*
 *  CSCI 441, Computer Graphics, Fall 2021
 *
 *  Project: lab04
 *  File: main.cpp
 *
 *  Description:
 *      This file contains the basic setup to work with GLSL shaders.
 *
 *  Author: Dr. Paone, Colorado School of Mines, 2021
 *
 */

#include "MpEngine.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

///*****************************************************************************
//
// Our main function
int main() {

    auto labEngine = new MpEngine(4, 1, 1024, 768, "Dirt Block Simulator");
    labEngine->initialize();
    if (labEngine->getError() == CSCI441::OpenGLEngine::OPENGL_ENGINE_ERROR_NO_ERROR) {
        labEngine->run();
    }
    labEngine->shutdown();
    delete labEngine;

	return EXIT_SUCCESS;
}

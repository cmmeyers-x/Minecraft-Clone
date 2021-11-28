//
// Created by cmmeyers on 11/28/21.
//

#ifndef MP_BLOCK_HPP
#define MP_BLOCK_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <CSCI441/OpenGLEngine.hpp>
#include <string>

class Block {
    bool isVisible;


    struct BlockFaces {
        std::string textureName;
        glm::vec3 top;
        glm::vec3 bottom;
        glm::vec3 north;
        glm::vec3 south;
        glm::vec3 east;
        glm::vec3 west;
    } _blockFaces;


};


#endif //MP_BLOCK_HPP

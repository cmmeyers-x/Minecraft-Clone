//
// Created by cmmeyers on 12/5/21.
//

#ifndef MP_CHUNK_HPP
#define MP_CHUNK_HPP

#include <string>
#include <algorithm>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Block.hpp"
#include "TextureManager.hpp"


class Chunk {

public:
    Chunk();
    Chunk(Block *_block, TextureManager *_textureManager);
    ~Chunk();
    void generateChunk(glm::vec3 center);
    void drawChunk(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx);
    void setGenerationMode();


private:
    struct block_attributes {
        glm::vec3 position;
        // texture type?
    };



    Block *_block = nullptr;
    TextureManager *_textureManager = nullptr;

    glm::vec3 _chunkCenter;
    std::vector<std::vector<block_attributes>> _blocks;

    static const int CHUNK_WIDTH = 16;
    static const int CHUNK_HEIGHT = 32;
    static const int BLOCK_SPACING = 1;


};


#endif //MP_CHUNK_HPP

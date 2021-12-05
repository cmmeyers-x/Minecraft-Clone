//
// Created by cmmeyers on 12/5/21.
//

#include <iostream>
#include "Chunk.hpp"


Chunk::Chunk(Block *_block, TextureManager *_textureManager) {
    this->_block = _block;
    this->_textureManager = _textureManager;
}

Chunk::~Chunk() {
}

void Chunk::generateChunk(glm::vec3 center) {
    this->_chunkCenter = center;

    for (int i = (int)center.x - CHUNK_WIDTH / 2; i < CHUNK_WIDTH / 2; ++i){
        std::vector<block_attributes> row;
        for (int j = (int)center.x - CHUNK_WIDTH / 2; j < CHUNK_WIDTH / 2; ++j){
            block_attributes attr = {glm::vec3(i,center.y,j)};
            row.push_back(attr);
        }
        _blocks.push_back(row);
    }
}

void Chunk::drawChunk(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    for (auto row : _blocks){
        for (auto block_atr : row){
            std::cout << block_atr.position.x << " " << block_atr.position.y << " " << block_atr.position.z << " ";
            _block->drawBlock(glm::translate(modelMtx, block_atr.position), viewMtx, projMtx);
        }
        std::cout << std::endl;
    }
}




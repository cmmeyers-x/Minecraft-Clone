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
    delete(modelMatrices);
}

void Chunk::generateChunk(glm::vec3 center) {
    this->_chunkCenter = center;

    int amount = CHUNK_WIDTH;
    modelMatrices = new glm::mat4[amount];


    for (int i = 0; i < CHUNK_WIDTH; ++i){
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(i,0.0f,0.0f));
        modelMatrices[i] = model;
    }

//    for (int i = (int)center.x - CHUNK_WIDTH / 2; i < CHUNK_WIDTH / 2; ++i){
//        std::vector<glm::mat4> row;
//        for (int j = (int)center.x - CHUNK_WIDTH / 2; j < CHUNK_WIDTH / 2; ++j){
//            glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(i,0.0f,0.0f));
//            row.push_back(model);
//        }
//        _blocks.push_back(row);
//    }


    // configured instanced array to represent those modelMatrices
    glGenBuffers(1, &_instanceMatrix); // Error 1282 pops up here
    glBindBuffer(GL_ARRAY_BUFFER, _instanceMatrix);
    glBufferData(GL_ARRAY_BUFFER, amount * sizeof(glm::mat4), &modelMatrices[0], GL_STATIC_DRAW);


    glBindVertexArray(_block->getBlockVAO());
    std::cout << "37 : " << glGetError() << std::endl;
    // vertex attributes
    std::size_t vec4Size = sizeof(glm::vec4);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)0);
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(1 * vec4Size));
    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(2 * vec4Size));
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(3 * vec4Size));
    std::cout << "48 : " << glGetError() << std::endl;
    glVertexAttribDivisor(3, 1);
    glVertexAttribDivisor(4, 1);
    glVertexAttribDivisor(5, 1);
    glVertexAttribDivisor(6, 1);
    std::cout << "53 : " << glGetError() << std::endl;
    glBindVertexArray(0);


}

void Chunk::drawChunk(glm::mat4 modelMtx, glm::mat4 viewMtx, glm::mat4 projMtx) {
    int amount = CHUNK_WIDTH;
    _block->drawBlock(glm::mat4(1.0f), viewMtx, projMtx);
    glBindVertexArray(0);
    std::cout << "63 : " << glGetError() << std::endl;
}




//
// Created by cmmeyers on 12/5/21.
//

#include "Skybox.hpp"
#include <CSCI441/ShaderProgram.hpp>
#include <iostream>
#include <CSCI441/objects.hpp>


Skybox::Skybox() {

};

void Skybox::setupSky(GLuint shaderProgramHandle, GLint mvpMatrix, GLint textureMap, GLint vPos, GLint vertexNormal,
                      GLint texCoord) {
    int radius = 100;
    int stacks = 16;
    int slices = 16;

    GLint currentPolygonMode[2];
    glGetIntegerv(GL_POLYGON_MODE, currentPolygonMode);

    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray( stacks);
    glBindBuffer( GL_ARRAY_BUFFER,stacks);
    if(CSCI441_INTERNAL::_positionAttributeLocation != -1) {
        glEnableVertexAttribArray( CSCI441_INTERNAL::_positionAttributeLocation );
        glVertexAttribPointer( CSCI441_INTERNAL::_positionAttributeLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    }
    if(CSCI441_INTERNAL::_normalAttributeLocation != -1) {
        glEnableVertexAttribArray( CSCI441_INTERNAL::_normalAttributeLocation );
        glVertexAttribPointer( CSCI441_INTERNAL::_normalAttributeLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(GLfloat)*((slices + 2)*2 + ((stacks - 2)*(slices+1))*2) *3) );
    }
    if(CSCI441_INTERNAL::_texCoordAttributeLocation != -1) {
        glEnableVertexAttribArray( CSCI441_INTERNAL::_texCoordAttributeLocation );
        glVertexAttribPointer( CSCI441_INTERNAL::_texCoordAttributeLocation, 2, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(GLfloat)*((slices + 2)*2 + ((stacks - 2)*(slices+1))*2) *6) );
    }

    glDrawArrays( GL_TRIANGLE_FAN, 0, slices+2 );

    for( int stackNum = 1; stackNum < stacks-1; stackNum++ ) {
        glDrawArrays( GL_TRIANGLE_STRIP, (slices+2) + (stackNum-1)*((slices+1)*2), (slices+1)*2 );
    }

    glDrawArrays( GL_TRIANGLE_FAN, (slices+2) + (stacks-2)*(slices+1)*2, slices+2 );

    glPolygonMode( GL_FRONT, currentPolygonMode[0] );
    glPolygonMode( GL_BACK, currentPolygonMode[1] );


}






/*
 *
 */
#version 410 core



uniform mat4 mvpMatrix;

// attribute inputs
layout(location = 0) in vec3 vPos;
in vec3 vertexNormal;
in vec2 texCoord;



void main() {
    // transform & output the vertex in clip space
    gl_Position = mvpMatrix * vec4(vPos, 1.0);

}
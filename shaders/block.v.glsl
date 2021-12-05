#version 410 core




// attribute inputs
layout(location = 0) in vec3 vPos;
//in vec2 textureMap;

// varying outputs
//out vec2 texCoord;

void main() {
    // transform & output the vertex in clip space
    gl_Position = vec4(vPos, 1.0);

  //  texCoord = textureMap;

}
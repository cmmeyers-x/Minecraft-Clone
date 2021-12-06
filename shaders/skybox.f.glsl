#version 410 core

// uniform inputs
// TODO #E
uniform sampler2D textureMap;

// varying inputs
// TODO #D
in vec2 textureCoord;

// fragment outputs
out vec4 fragColorOut;

void main() {
    // TODO #F
    vec4 texelColor = texture(textureMap, textureCoord);

    // TODO #G
   // fragColorOut = texelColor;
   fragColorOut = vec4(1.0,1.0,1.0,1.0);
}
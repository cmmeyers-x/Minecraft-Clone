#version 410 core

// uniform inputs
//uniform sampler2D blockTexture;
// varying inputs
//layout(location = 0) in vec3 color;     // interpolated color for this fragment
//in vec2 textCoordinateIn;

// outputs
out vec4 fragColorOut;                  // color to apply to this fragment



void main() {
    // pass the interpolated color through as output
//    vec4 fColor = texture(blockTexture, textCoordinateIn);
//
//    fragColorOut = fColor;
    fragColorOut = vec4(1.0,1.0,1.0,1.0);
}
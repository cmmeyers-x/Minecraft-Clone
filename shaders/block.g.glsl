#version 410 core

// uniform inputs
uniform mat4 mvpMatrix;


layout (points) in;
layout(points, max_vertices = 6) out;





void main() {
    //For points
    //gl_Position = mvpMatrix * gl_in[0].gl_Position;
//    texCord = vec2(0.0,0.0);
    //EmitVertex();
    //EndPrimitive();


    // point 1 -> transform -> side 1 face

    for (int i = 0; i < 6; ++i){
        gl_Position = mvpMatrix * (gl_in[i].gl_Position);
        EmitVertex();
    }
    EndPrimitive();



//    gl_Position = mvpMatrix * (gl_in[0].gl_Position);
//
//    EmitVertex();
//
//    gl_Position = mvpMatrix * (gl_in[0].gl_Position);
//
//    EmitVertex();
//
//    gl_Position = mvpMatrix * (gl_in[0].gl_Position);
//
//    EmitVertex();





}
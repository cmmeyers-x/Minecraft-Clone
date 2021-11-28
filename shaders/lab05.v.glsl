#version 410 core

// uniform inputs
uniform mat4 mvpMatrix;                 // the precomputed Model-View-Projection Matrix
// TODO #D: add normal matrix
uniform mat3 normalMatrix;
// TODO #A: add light uniforms
uniform vec3 lightDirection;
uniform vec3 lightColor;

uniform vec3 viewVector;        // V in I_s

uniform vec3 materialSpecular;  // Cms - matrial specular
uniform vec3 lightSpecular;     // Cls - light specular

uniform vec3 materialAmbience;  // Cma - material ambience
uniform vec3 lightAmbience;     // Cla - light ambience

uniform vec3 materialColor;             // the material color for our vertex (& whole object)

uniform vec3 pointLightPosition; // the position of the point light in our world
uniform vec3 pointLightColor; // Tell point light apart from other lights

uniform vec3 flashlightPosition;
uniform vec3 flashlightDirection;
uniform vec3 flashlightColor;
int alpha = 16;


// attribute inputs
layout(location = 0) in vec3 vPos;      // the position of this specific vertex in object space
// TODO #C: add vertex normal
in vec3 vertexNormal;

// varying outputs
layout(location = 0) out vec3 color;    // color to apply to this vertex

vec3 calculatePointLightLightingVals(){
    vec3 pointLightVec = normalize(-(vPos-pointLightPosition));
    vec3 normalVec = normalize(normalMatrix * vertexNormal);
    vec3 normalVector = normalize(normalMatrix * vertexNormal);
    // diffuse
    vec3 Id = pointLightColor * materialColor * max(dot(pointLightVec, normalVec),0);

    float distance = length(vPos - pointLightPosition);
    float attenuation = 1.0f / (1.0f + 1.0f*distance + distance*distance);

    // specular
    vec3 vVec = normalize(viewVector - vPos); // include camera position for reflections
    vec3 rVec = reflect(pointLightVec, normalVector);

    vec3 Is = materialSpecular * lightSpecular * pow(max(dot(vVec, rVec), 0), alpha);

    return((Id + Is) * attenuation);
}

vec3 calculateSpotLight(){

    vec3 normalVector = normalize(normalMatrix * vertexNormal);
    vec3 lightDirec = normalize(-(vPos-flashlightPosition));
    float difference = max(dot(normalVector, lightDirec), 0.0);
    vec3 reflectDirec = reflect(-lightDirec, normalVector);
    float spec = pow(max(dot(viewVector, reflectDirec),0.0), alpha);

    vec3 flashlightVector = normalize(flashlightDirection);

    vec3 Id = flashlightColor * materialColor * max(dot(flashlightVector, normalVector), 0);

    vec3 vVec = normalize(viewVector - vPos); // viewVector is lightPosition
    vec3 rVec = reflect(flashlightVector, normalVector);
    vec3 Is = materialSpecular * lightSpecular * pow(max(dot(vVec, rVec), 0), alpha); // mp

    float distance = length(vPos - flashlightPosition);
    float attenuation = 1.0;// / (1.0 + distance + 0.0001*distance*distance);

    if (difference >= 0.0 && difference <= 3.141/2.0){
        return(Id + Is) * 4.0 * attenuation;
    }
    else{
        return vec3(1.0,1.0,1.0);
    }

}




void main() {
    // transform & output the vertex in clip space
    gl_Position = mvpMatrix * vec4(vPos, 1.0);

    // computer Light vector
    vec3 lightVector = normalize(-lightDirection);
    // transform normal vector
    vec3 normalVector = normalize(normalMatrix * vertexNormal);
    // perform diffuse calculation
    vec3 Id = lightColor * materialColor * max(dot(lightVector, normalVector), 0);

    vec3 vVec = normalize(viewVector - vPos); // viewVector is lightPosition
    vec3 rVec = reflect(-lightVector, normalVector);
    vec3 Is = materialSpecular * lightSpecular * pow(max(dot(vVec, rVec), 0), alpha); // mp

    vec3 Ia = lightAmbience * materialAmbience;
    color = Is + Ia + Id + (calculateSpotLight()*0.00001) + calculatePointLightLightingVals();
}


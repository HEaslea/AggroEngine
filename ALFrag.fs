#version 330 core

in vec3 fPos; 
in vec3 fNorm; 

out vec4 FragColour; 

uniform vec3 lightPos;
uniform vec3 lightCol;
uniform vec3 objColour;


void main() 
{ 
    // Normalize Vertex norm
    vec3 norm = normalize(fNorm);

    // Normalize Light norm
    vec3 lightDir = normalize(lightPos - fPos); // Vertex to Light

    // Ambient Intensity
    float amb = max(dot(norm, lightDir), 0.0); // just take 0 if > 90 away

    // channel scaling 
    // const amb for brightness
    vec3 ambL = amb * lightCol * objColour;

    // homogenous out
    FragColour = vec4(ambL, 1.0);
}
#version 330 core

layout(location = 0) in vec3 aPos; // Vert pos
layout(location = 1) in vec3 aNormal;

out vec3 fPos; 
out vec3 fNorm; 

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() 
{ 
    // GL Normal Transposition
    fNorm = mat3(transpose(inverse(model))) * aNormal;

    // MVP
    fPos = vec3(model * vec4(aPos, 1.0)); // World

    gl_Position = proj * view * vec4(fPos, 1.0); // MVP
}
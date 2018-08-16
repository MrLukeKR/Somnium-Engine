#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normals;
layout (location = 2) in vec2 texCoords;


out vec2 TexCoords;
out vec3 WorldPos;
out vec3 Normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    TexCoords = texCoords;
    WorldPos = vec3(model * vec4(position, 1.0));
    Normal = mat3(model) * normals;   

    gl_Position =  projection * view * vec4(WorldPos, 1.0);
}


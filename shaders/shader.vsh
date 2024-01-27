R"(

#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 translate;
uniform mat4 rotate;
uniform vec3 normal;

void main()
{
    gl_Position = rotate * translate * vec4(aPos, 1.0);
    FragPos = vec3(rotate * translate * vec4(aPos, 1.0));
    Normal = vec3(rotate * translate * vec4(normal, 1.0));
    TexCoord = aTexCoord;
}

)"

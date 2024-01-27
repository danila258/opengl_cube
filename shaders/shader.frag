R"(

#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

uniform sampler2D ourTexture;

void main()
{
    // Environment
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 diffuse = diff * lightColor;

    // vec3 result = (ambient + diffuse) * objectColor;
    vec4 texColor = texture(ourTexture, TexCoord);
    vec3 result = (ambient + diffuse) * vec3(texColor);

    FragColor = vec4(result, 0.1);
}

)"

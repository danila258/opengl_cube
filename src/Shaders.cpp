#include "Shaders.h"

Shader::~Shader()
{
    glDeleteShader(_shader);
}

void Shader::checkShaderError()
{
    GLint success;
    char infoLog[512];
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(_shader, 512, NULL, infoLog);
        std::cerr << "error: shader '" << _shaderName << "' compilation failed" << std::endl << infoLog << std::endl;
    }
}


VertexShader::VertexShader(const char* vertexShaderSource)
{
    _shaderName = "vertex shader";
    _shader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(_shader, 1, &vertexShaderSource, NULL);
    glCompileShader(_shader);

    checkShaderError();
}

VertexShader::operator GLuint() const
{
    return _shader;
}


FragmentShader::FragmentShader(const char* fragmentShaderSource)
{
    _shaderName = "vertex shader";
    _shader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(_shader, 1, &fragmentShaderSource, NULL);
    glCompileShader(_shader);

    checkShaderError();
}

FragmentShader::operator GLuint() const
{
    return _shader;
}


ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader)
{
    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);
}

ShaderProgram::ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
    : ShaderProgram(VertexShader(vertexShaderSource), FragmentShader(fragmentShaderSource))
{}

ShaderProgram::ShaderProgram(const ShaderProgram& other) : _shaderProgram(other._shaderProgram)
{}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(_shaderProgram);
}

ShaderProgram::operator GLuint() const
{
    return _shaderProgram;
}

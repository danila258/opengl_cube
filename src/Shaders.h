#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <iostream>


class Shader
{
public:
    virtual ~Shader();

protected:
    GLuint _shader = 0;
    std::string _shaderName;

    void checkShaderError();
};


struct VertexShader : public Shader
{
    VertexShader(const char* vertexShaderSource);
    operator GLuint() const;
};


struct FragmentShader : public Shader
{
    FragmentShader(const char* fragmentShaderSource);
    operator GLuint() const;
};


class ShaderProgram
{
public:
    ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader);
    ShaderProgram(const char* vertexShader, const char* fragmentShader);
    ShaderProgram(const ShaderProgram& other);
    ~ShaderProgram();

    operator GLuint() const;

private:
    GLuint _shaderProgram = 0;
};


#endif // SHADER_H

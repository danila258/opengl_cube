#ifndef VERTEXOBJECTS_H
#define VERTEXOBJECTS_H

#include <glad/glad.h>

#include <glm/vec3.hpp>

#include <vector>


class Vao
{
public:
    Vao(std::vector<glm::vec3>& vertices);
    Vao(const Vao& other);
    ~Vao();

    operator GLuint();

private:
    GLuint _Vao;
    GLuint _Vbo;
};


#endif // VERTEXOBJECTS_H

#include "VertexObjects.h"

Vao::Vao(std::vector<glm::vec3>& vertices)
{
    std::vector<GLfloat> data;

    int counter = 0;
    for (auto vertex : vertices)
    {
        data.emplace_back(vertex.x);
        data.emplace_back(vertex.y);
        data.emplace_back(vertex.z);


        if (counter == 0)
        {
            data.emplace_back(1.0f);
            data.emplace_back(1.0f);
        }
        else if (counter == 1)
        {
            data.emplace_back(1.0f);
            data.emplace_back(0.0f);
        }
        else if (counter == 2)
        {
            data.emplace_back(0.0f);
            data.emplace_back(0.0f);
        }
        else if (counter == 3)
        {
            data.emplace_back(0.0f);
            data.emplace_back(1.0f);
        }

        ++counter;
        if (counter == 4)
        {
            counter = 0;
        }
    }

    glGenVertexArrays(1, &_Vao);
    glGenBuffers(1, &_Vbo);

    glBindVertexArray(_Vao);
    glBindBuffer(GL_ARRAY_BUFFER, _Vbo);

    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Vao::Vao(const Vao& other) : _Vao(other._Vao), _Vbo(other._Vbo)
{}

Vao::~Vao()
{
    glDeleteVertexArrays(1, &_Vao);
    glDeleteBuffers(1, &_Vbo);
}

Vao::operator GLuint()
{
    return _Vao;
}

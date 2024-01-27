#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "VertexObjects.h"
#include "Shaders.h"
#include "Texture.h"

#include <glad/glad.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../libs/stb_image.h"

#include <vector>
#include <utility>


class SceneObject
{
public:
    SceneObject(const std::vector<glm::vec3>& vertexes, const glm::vec3& centre, const glm::vec3& color,
                GLint drawMethod, const std::string& name);
    SceneObject(const SceneObject& other);

    void render(const glm::vec3& lightColor, const glm::vec3& lightPos);

    glm::vec3 getCentre();
    glm::vec3 getColor();
    glm::vec3 getNormal();

    void setCentre(const glm::vec3& centre);
    void setColor(const glm::vec3& color);
    void enableTransparency();
    void disableTransparency();

    void rotate(float angle, const glm::vec3& vec);
    void translate(const glm::vec3& vec);

public:
    std::vector<glm::vec3> _vertexes;
    glm::vec3 _centre;
    std::string _name;

    Vao _vao;
    Texture _texture;
    GLint _drawMethod;
    ShaderProgram _shaderProg;

    glm::mat4 _translate = glm::mat4(1.0f);
    glm::mat4 _rotate = glm::mat4(1.0f);
    glm::vec3 _color;
};


#endif // SCENEOBJECT_H

#include "SceneObject.h"

const char* shaderFrag =
#include "../shaders/shader.frag"
    ;

const char* shaderVert =
#include "../shaders/shader.vsh"
    ;

SceneObject::SceneObject(const std::vector<glm::vec3>& vertexes, const glm::vec3& centre, const glm::vec3& color,
                         GLint drawMethod, const std::string& name)
    : _vertexes(vertexes), _vao(_vertexes), _centre(centre), _color(color), _shaderProg(shaderVert, shaderFrag),
    _drawMethod(drawMethod), _name(name)
{}

SceneObject::SceneObject(const SceneObject& other) : _vertexes(other._vertexes), _centre(other._centre),
    _name(other._name), _vao(other._vao), _texture(other._texture), _drawMethod(other._drawMethod),
    _shaderProg(other._shaderProg), _translate(other._translate), _rotate(other._rotate), _color(other._color)
{}

void SceneObject::render(const glm::vec3& lightColor, const glm::vec3& lightPos)
{
    GLint objectColorLocation = glGetUniformLocation(_shaderProg, "objectColor");
    GLint objectNormalLocation = glGetUniformLocation(_shaderProg, "normal");

    GLint lightColorLocation = glGetUniformLocation(_shaderProg, "lightColor");
    GLint lightPosLocation = glGetUniformLocation(_shaderProg, "lightPos");

    GLint rotateLocation = glGetUniformLocation(_shaderProg, "rotate");
    GLint transformLocation = glGetUniformLocation(_shaderProg, "translate");

    glUseProgram(_shaderProg);

    glUniform3f(objectColorLocation, _color.x, _color.y, _color.z);
    glUniform3f(objectNormalLocation, getNormal().x, getNormal().y, getNormal().z);

    glUniform3f(lightColorLocation, lightColor.x, lightColor.y, lightColor.z);
    glUniform3f(lightPosLocation, lightPos.x, lightPos.y, lightPos.z);

    glUniformMatrix4fv(rotateLocation, 1, GL_FALSE, glm::value_ptr(_rotate));
    glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(_translate));

    glBindTexture(GL_TEXTURE_2D, _texture);
    glBindVertexArray(_vao);

    glDrawArrays(_drawMethod, 0, _vertexes.size());
    glBindVertexArray(0);
}

glm::vec3 SceneObject::getCentre()
{
    return _centre;
}

glm::vec3 SceneObject::getColor()
{
    return _color;
}

glm::vec3 SceneObject::getNormal()
{
    glm::mat3x3 trans(_translate);
    glm::mat3x3 rot(_rotate);

    glm::vec3 firstVec =  1.f * (_vertexes[1] - _vertexes[0]);
    glm::vec3 secondVec = 1.f * trans * (_vertexes[2] - _vertexes[0]);

    glm::vec3 normal = glm::normalize(glm::cross(firstVec, secondVec));

    if (glm::dot(_vertexes[0], normal) < 0.0f)
    {
        return -normal;
    }

    return normal;
}

void SceneObject::setCentre(const glm::vec3& centre)
{
    translate(centre - _centre);
}

void SceneObject::rotate(float angle, const glm::vec3& vec)
{
    _rotate = glm::rotate(_rotate, angle, vec);
}

void SceneObject::translate(const glm::vec3& vec)
{
    _translate = glm::translate(_translate, vec);
    _centre += vec;
}

void SceneObject::setColor(const glm::vec3& color)
{
    _color = color;
}

void SceneObject::enableTransparency()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
}

void SceneObject::disableTransparency()
{
    glDisable(GL_BLEND);
}

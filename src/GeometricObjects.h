#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "glm/geometric.hpp"

#include <vector>
#include <utility>
#include <cmath>
#include <limits>
#include <iostream>
#include <algorithm>


std::vector<glm::vec2> getCircleArr(const glm::vec2& centre, float radius, int numSegments, float segment = 1.f);
std::vector<glm::vec3> getTriangle(const glm::vec3& pointOne, const glm::vec3& pointTwo, const glm::vec3& pointThree);
std::vector<glm::vec3> getSquare(const glm::vec3& pointOne, const glm::vec3& pointTwo, const glm::vec3& pointThree,
                                 const glm::vec3& pointFour);


#endif // GEOMETRICOBJECT_H

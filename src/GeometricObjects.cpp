#include "GeometricObjects.h"

std::vector<glm::vec2> getCircleArr(const glm::vec2& centre, float radius, int numSegments, float segment)
{
    std::vector<glm::vec2> vertexArr;
    float angle = 0;
    float angle_step = ((float(360) / (float(1) / segment) / float(180)) * 3.14f) / float(numSegments);

    for (int i = 0; i < numSegments + 1; ++i)
    {
        float x = radius * cos(angle) + centre.x;
        float y = radius * sin(angle) + centre.y;
        vertexArr.emplace_back(x, y);

        angle += angle_step;
    }

    return vertexArr;
}

std::vector<glm::vec3> getTriangle(const glm::vec3& pointOne, const glm::vec3& pointTwo, const glm::vec3& pointThree)
{
    std::vector<glm::vec3> vertexArr;

    vertexArr.emplace_back(pointOne);
    vertexArr.emplace_back(pointTwo);
    vertexArr.emplace_back(pointThree);

    return vertexArr;
}

std::vector<glm::vec3> getSquare(const glm::vec3& pointOne, const glm::vec3& pointTwo, const glm::vec3& pointThree,
                                 const glm::vec3& pointFour)
{
    std::vector<glm::vec3> vertexArr = {pointOne, pointTwo, pointThree, pointFour};
    double minSum = std::numeric_limits<double>::max();

    std::vector<int> perm = {0, 1, 2, 3};
    std::vector<int> permCopy;

    while(std::next_permutation(perm.begin(), perm.end()))
    {
        double sum = 0;

        for (size_t i = 0; i < vertexArr.size() - 1; ++i)
        {
            sum += glm::length(glm::vec3(vertexArr[perm[i]] - vertexArr[perm[i + 1]]));
        }

        sum += glm::length(glm::vec3(vertexArr[perm[0]] - vertexArr[perm[3]]));

        if (sum < minSum)
        {
            permCopy = perm;
            minSum = sum;
        }
    }

    std::vector<glm::vec3> sortedVertexArr;

    for (size_t i = 0; i < vertexArr.size(); ++i)
    {
        sortedVertexArr.emplace_back(vertexArr[permCopy[i]]);
    }

    for (size_t i = 0; i < vertexArr.size(); ++i)
    {
        std::cout << sortedVertexArr[i].x << ' ' << sortedVertexArr[i].y << ' ' << sortedVertexArr[i].z << ' ' << std::endl;
    }

    std::vector<glm::vec3> vertexArrOne = getTriangle(vertexArr[0], sortedVertexArr[1], sortedVertexArr[2]);
    std::vector<glm::vec3> vertexArrTwo = getTriangle(sortedVertexArr[0], sortedVertexArr[2], sortedVertexArr[3]);
    vertexArrOne.insert(vertexArrOne.end(), vertexArrTwo.begin(), vertexArrTwo.end());

    return vertexArrOne;
}

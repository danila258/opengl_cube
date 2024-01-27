#ifndef SCENELOGIC_H
#define SCENELOGIC_H

#include "InitWindow.h"
#include "SceneObject.h"
#include "GeometricObjects.h"

#include <glad/glad.h>

#include <iostream>
#include <vector>
#include <algorithm>

extern bool rotateFlag;
extern bool translateFlag;
extern bool reverseTranslateFlag;
extern bool transparencyFlag;
extern bool textureFlag;


void startRenderCycle();
static void processInput(GLFWwindow* window);


#endif // SCENELOGIC_H

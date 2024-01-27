#ifndef INITWINDOW_H
#define INITWINDOW_H

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

static void errorCallback(int code, const char* description);
static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

GLFWwindow* getGlfwWindow();


#endif // INITWINDOW_H

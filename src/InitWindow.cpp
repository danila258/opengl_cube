#include "InitWindow.h"

bool rotateFlag = false;
bool translateFlag = false;
bool reverseTranslateFlag = false;
bool transparencyFlag = false;
bool textureFlag = false;


static void errorCallback(int code, const char* description)
{
    std::cerr << description << std::endl << "code - " << code << std::endl;
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_RELEASE)
    {
        return;
    }

    if (key == GLFW_KEY_1)
    {
        rotateFlag = !rotateFlag;
    }
    else if (key == GLFW_KEY_2)
    {
        translateFlag = !translateFlag;
    }
    else if (key == GLFW_KEY_3)
    {
        transparencyFlag = !transparencyFlag;
    }
    else if (key == GLFW_KEY_4)
    {
        textureFlag = !textureFlag;
    }
}

static void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


GLFWwindow* getGlfwWindow()
{
    glfwSetErrorCallback(errorCallback);

    // Initialize glfw
    if ( !glfwInit() )
    {
        glfwTerminate();
        throw std::runtime_error("error: can't initialize glfw");
    }

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and it's OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 640, "opengl_cube", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("error: can't create glfw window");
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetKeyCallback(window, keyCallback);

    // Load glad
    if ( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) )
    {
        std::cerr << "error: can't load glad" << std::endl;
        glfwTerminate();
        throw std::runtime_error("error: can't load glad");
    }

    glEnable(GL_DEPTH_TEST);

    return window;
}

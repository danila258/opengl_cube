#include "SceneLogic.h"

static void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void startRenderCycle()
{
    GLFWwindow* window = getGlfwWindow();

    SceneObject one({
                     {-0.3f, -0.3f, -0.3f},
                     { 0.3f, -0.3f, -0.3f},
                     { 0.3f,  0.3f, -0.3f},
                     { 0.3f,  0.3f, -0.3f},
                     {-0.3f,  0.3f, -0.3f},
                     {-0.3f, -0.3f, -0.3f},
                    },
                    {0, 0, 0},
                    {1, 1, 1},
                    GL_TRIANGLES, "one");

    SceneObject two({
                     {-0.3f, -0.3f,  0.3f},
                     { 0.3f, -0.3f,  0.3f},
                     { 0.3f,  0.3f,  0.3f},
                     { 0.3f,  0.3f,  0.3f},
                     {-0.3f,  0.3f,  0.3f},
                     {-0.3f, -0.3f,  0.3f},
                    },
                    {0, 0, 0},
                    {1, 1, 1},
                    GL_TRIANGLES, "two");

    SceneObject three({
                     {-0.3f,  0.3f,  0.3f},
                     {-0.3f,  0.3f, -0.3f},
                     {-0.3f, -0.3f, -0.3f},
                     {-0.3f, -0.3f, -0.3f},
                     {-0.3f, -0.3f,  0.3f},
                     {-0.3f,  0.3f,  0.3f},
                    },
                    {0, 0, 0},
                    {1, 1, 1},
                    GL_TRIANGLES, "three");

    SceneObject four({
                     { 0.3f,  0.3f,  0.3f},
                     { 0.3f,  0.3f, -0.3f},
                     { 0.3f, -0.3f, -0.3f},
                     { 0.3f, -0.3f, -0.3f},
                     { 0.3f, -0.3f,  0.3f},
                     { 0.3f,  0.3f,  0.3f},
                    },
                    {0, 0, 0},
                    {1, 1, 1},
                    GL_TRIANGLES, "four");

    SceneObject five({
                     {-0.3f, -0.3f, -0.3f},
                     { 0.3f, -0.3f, -0.3f},
                     { 0.3f, -0.3f,  0.3f},
                     { 0.3f, -0.3f,  0.3f},
                     {-0.3f, -0.3f,  0.3f},
                     {-0.3f, -0.3f, -0.3f},
                    },
                    {0, 0, 0},
                    {1, 1, 1},
                    GL_TRIANGLES, "five");

    SceneObject six({
                     {-0.3f,  0.3f, -0.3f},
                     { 0.3f,  0.3f, -0.3f},
                     { 0.3f,  0.3f,  0.3f},
                     { 0.3f,  0.3f,  0.3f},
                     {-0.3f,  0.3f,  0.3f},
                     {-0.3f,  0.3f, -0.3f},
                    },
                    {0, 0, 0},
                    {1, 1, 1},
                    GL_TRIANGLES, "six");

    SceneObject light({
                       {-0.1f, -0.1f, -0.1f},
                       { 0.1f, -0.1f, -0.1f},
                       { 0.1f,  0.1f, -0.1f},
                       { 0.1f,  0.1f, -0.1f},
                       {-0.1f,  0.1f, -0.1f},
                       {-0.1f, -0.1f, -0.1f},
                      },
                      {0, 0, 0},
                      {1, 1, 1},
                      GL_TRIANGLES, "light");

    std::vector<SceneObject*> objects{&one, &two, &three, &four, &five, &six};

    std::vector<glm::vec2> lightPath = getCircleArr({0, 0}, 0.8, 1000);
    size_t pathIndex = 0;

    // Loop until the user closes the window
    while ( !glfwWindowShouldClose(window) )
    {
        ++pathIndex;
        if (pathIndex >= lightPath.size())
        {
            pathIndex = 0;
        }

        float lightX = lightPath[pathIndex].x;
        float lightY = lightPath[pathIndex].y;

        light.setCentre({lightX, lightY, -0.4});

        processInput(window);

        // Render
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (auto& obj : objects)
        {
            obj->render({1, 1, 1}, {lightX, lightY, -0.8});
        }

        if (rotateFlag)
        {
            for (auto& obj : objects)
            {
                obj->rotate(glm::radians(0.3f), glm::vec3(0.5f, 1.0f, 0.0f));
            }
        }

        if (transparencyFlag)
        {
            for (auto& obj : objects)
            {
                obj->enableTransparency();
            }
        }
        else
        {
            for (auto& obj : objects)
            {
                obj->disableTransparency();
            }
        }

        if (translateFlag && !reverseTranslateFlag)
        {
            for (auto& obj : objects)
            {
                obj->translate(obj->getNormal() * 0.1f);
            }

            reverseTranslateFlag = true;
            translateFlag = false;
        }
        else if (translateFlag && reverseTranslateFlag)
        {
            for (auto& obj : objects)
            {
                obj->translate(-obj->getNormal() * 0.1f);
            }

            reverseTranslateFlag = false;
            translateFlag = false;
        }

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
}

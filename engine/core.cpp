//
// Created by Diego Santos Seabra on 01/02/21.
//

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include "core.h"
#include "log.h"
#include "glshader.h"
#include <OpenGL/gl3.h>

#define numVAOs 1

GLFWwindow *window;
GLuint shaderProgram;
GLuint vao[numVAOs];

// REVIEW: Maybe change this namespace? Could it be window?
void Core::initWindow()
{
    Log::info("Initializing engine...");

    /* Initialize the library */
    if (!glfwInit())
    {
        Log::error("Failed to initialize GLFW");
        exit(EXIT_FAILURE);
    }

    /* Use the most recent OpenGL Version available in the machine */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create the window */
    window = glfwCreateWindow(800, 600, "Magick Engine", nullptr, nullptr);
    if (!window)
    {
        Log::error("Failed to create window");
        glfwTerminate();
    }

    /* Enable V-Sync */
    glfwSwapInterval(1); // TODO: Allow this on the game config (?)

    /* Minimum window size */
    glfwSetWindowSizeLimits(window, 320, 180, GLFW_DONT_CARE, GLFW_DONT_CARE);

    // FIXME: Move this prints to the Log class

    /* Print GLFW Version */
    int major, minor, patch;
    glfwGetVersion(&major, &minor, &patch);
    std::cout << WHITE << "GLFW Version: " << major << "." << minor << "." << patch << RESET << std::endl;

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Print OpenGL Version */
    std::cout << WHITE << "OpenGL Version: " << glGetString(GL_VERSION) << RESET << std::endl;

    /* Print GLSL Version */
    std::cout << WHITE << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << RESET << std::endl;

    /* Shaders */
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);

    // FIXME: Load content dynamically (without having to copy paste on to build directory)
    shaderProgram = LoadShader("shaders/vertex.glsl", "shaders/fragment.glsl");
    // REVIEW: Use program should be called every frame?
    glUseProgram(shaderProgram);
}

void Core::swapBuffers()
{
    /* Swap front and back buffers, e.g. draw on the screen */
    glfwSwapBuffers(window);
}

void Core::pollEvents()
{
    /* Poll for and process events */
    glfwPollEvents();

    /* Makes the screen closes when pressing escape button */
    if (glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int Core::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Core::cleanup()
{
    Log::info("Shutting down engine...");

    glfwDestroyWindow(window);
    glfwTerminate();
}


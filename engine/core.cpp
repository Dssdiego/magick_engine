//
// Created by Diego Santos Seabra on 01/02/21.
//

#define GL_SILENCE_DEPRECATION
#include "core.h"

GLFWwindow *window;

void Core::initWindow()
{
    /* Initialize the library */
    glfwInit(); // TODO: Handle error on init

    /* Create the window */
    window = glfwCreateWindow( 800, 600, "Magick Engine", nullptr, nullptr );
    if (!window)
    {
        glfwTerminate(); // TODO: Handle error on !window
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
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

    // Makes the screen closes when pressing escape button
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int Core::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Core::cleanup()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}


//#define GLFW_INCLUDE_GLCOREARB
//#define GLFW_INCLUDE_GLEXT
#define GL_SILENCE_DEPRECATION

//#define BUFFER_OFFSET(i) ((char *)NULL + (i))

#include <iostream>
#include "engine/core.h"
#include "game/game.h"
#include "engine/renderer.h"

int main()
{
    Core::initWindow();
    Game::init();

    while (!Core::shouldClose())
    {
        // Clear screen with some color
        Renderer::clear(COLOR_BLACK);

        // Draw point
        Renderer::drawPoint();
//        Renderer::drawTriangle();

//        Game::update(glfwGetTime());
        Game::update();
        Game::draw(glfwGetTime());

        Core::swapBuffers();
        Core::pollEvents();
    }

    Core::cleanup();
    exit(EXIT_SUCCESS);

//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if ( !glfwInit() )
//    {
//        return -1;
//    }
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow( 800, 600, "Magick Engine", nullptr, nullptr );
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers
//        glClearColor(1,0,1,1);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
}
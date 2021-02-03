//#define GLFW_INCLUDE_GLCOREARB
//#define GLFW_INCLUDE_GLEXT
#define GL_SILENCE_DEPRECATION
//#include <GLFW/glfw3.h>

//#define BUFFER_OFFSET(i) ((char *)NULL + (i))

#include <iostream>
#include "engine/core.h"
#include "game/game.h"

int main()
{
    Core::initWindow();
    Game::init();

    while (!Core::shouldClose())
    {
        // Clear color
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw point
        glDrawArrays(GL_POINTS, 0, 1);

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
//
// Created by Diego Santos Seabra on 01/02/21.
//

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include "core.h"
#include "log.h"
#include "glshader.h"
#include <OpenGL/gl3.h>
#include <time.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../libs/stb_image/stb_image_write.h"

#define numVAOs 1
#define CHANNEL_NUM 3

// FIXME: Make this dynamic
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

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
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Magick Engine", nullptr, nullptr);
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

    /* Take screenshot */
    if (glfwGetKey(window, GLFW_KEY_F12))
    {
        auto *pixels = new uint8_t[SCREEN_WIDTH * SCREEN_HEIGHT * CHANNEL_NUM];
        glReadPixels(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);

        time_t theTime = time(nullptr);
        struct tm *curTime = localtime(&theTime);
        int day = curTime->tm_mday;
        int month = curTime->tm_mon + 1;
        int year = curTime->tm_year + 1900;
        int hour = curTime->tm_hour;
        int min = curTime->tm_min;
        int sec = curTime->tm_sec;

        std::string screenFileName = "screenshots/" + std::to_string(day) + "_" +
                std::to_string(month) + "_" +
                std::to_string(year) + "_" +
                std::to_string(hour) + std::to_string(min) + std::to_string(sec) +
                ".png";

        stbi_write_png(screenFileName.c_str(), SCREEN_WIDTH, SCREEN_HEIGHT, 3, pixels, SCREEN_WIDTH * 3);
        std::string logString = "Screenshot " + screenFileName + " created!";
        Log::info(logString.c_str());
    }

//    int present = glfwJoystickPresent(GLFW_JOYSTICK_1);
//    int gamepad = glfwJoystickIsGamepad(GLFW_JOYSTICK_1);
//    if(present)
//    {
//        Log::debug("Joystick connected!");
//    }
//
//    if(gamepad)
//    {
//        Log::debug("Joystick is gamepad");
//    }
//    Log::info(glfwJoystickPresent(GLFW_JOYSTICK_1));
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


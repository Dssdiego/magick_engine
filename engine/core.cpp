//
// Created by Diego Santos Seabra on 01/02/21.
//

#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION

#include <iostream>
#include "core.h"
#include "renderer/shader.h"
#include <ctime>
#include <SDL.h>
#include <filesystem>

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../libs/stb_image/stb_image_write.h"
#include "color.h"
#include "renderer/renderer.h"
#include "input/input.h"
#include "tools/maths.h"
#include "tools/log.h"
#include "tools/tools.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <SDL_opengles2.h>
#include <GLES3/gl3.h>
#endif

#define numVAOs 1

SDL_Window *window;
SDL_GLContext glContext;
GLuint shaderProgram;
GLuint vao[numVAOs];
Size windowSize{800, 600};
bool closeWindow = false;

// REVIEW: Maybe change this namespace? Could it be window?
void Core::initWindow()
{
    Log::info("Initializing engine...");

    /* Initialize the library */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        Log::error("Failed to initialize SDL");
        exit(EXIT_FAILURE);
    }

    /* Use the most recent OpenGL Version available in the machine */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
#ifdef __APPLE__
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#endif
    /* Create the window */
    window = SDL_CreateWindow("Magick Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize.width,
                              windowSize.height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (!window)
    {
        Log::error("Failed to create window");
        SDL_Quit();
    }

    /* Creates OpenGL Context */
    glContext = SDL_GL_CreateContext(window);

    /* Enable V-Sync */
    SDL_GL_SetSwapInterval(1); // REVIEW: Allow this on the game config (?)

    /* Sets the viewport */
    // FIXME: Emscripten can't find this
    glViewport(0, 0, windowSize.width, windowSize.height);

    // FIXME: Move this prints to the Log class

    /* Print SDL Version */
    SDL_version sdlVersion;
    SDL_GetVersion(&sdlVersion);
#ifdef __APPLE__
    std::cout << WHITE << "SDL Version: " << unsigned(sdlVersion.major) << "." << unsigned(sdlVersion.minor) << "." << unsigned(sdlVersion.patch) << RESET
              << std::endl;
#endif

    /* Make the window's context current */
    SDL_GL_MakeCurrent(window, glContext);
//    glfwMakeContextCurrent(window);

    /* Print OpenGL Version */
#ifdef __APPLE__
    std::cout << WHITE << "OpenGL Version: " << glGetString(GL_VERSION) << RESET << std::endl;
#endif

    /* Print GLSL Version */
#ifdef __APPLE__
    std::cout << WHITE << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << RESET << std::endl;
#endif

    // REVIEW: Should be Renderer::init() ?
    /* Shaders */
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);

    // FIXME: Load content dynamically (without having to copy paste on to build directory)
//    createShader(Tools::getAssetPath().append("shaders/common.glsl").c_str());
//    createShader("triangle");
//    createShader("triangle_move");
    // REVIEW: 'Use program' should be called every frame?
//    glUseProgram(shaderProgram);
}

void Core::swapBuffers()
{
    /* Swap front and back buffers, e.g. draw on the screen */
    SDL_GL_SwapWindow(window);
}

void Core::pollEvents()
{
    /* Poll for and process events */
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            closeWindow = true;
        }

        else if (event.type == SDL_KEYDOWN)
        {
            if ((Key) event.key.keysym.scancode == Key::Escape)
                closeWindow = true;

            if ((Key) event.key.keysym.scancode == Key::F12)
                Tools::takeScreenshot(windowSize);

            if (event.key.repeat == 0)
                Input::onKeyDown((Key) event.key.keysym.scancode);
        }

        else if (event.type == SDL_KEYUP)
        {
            if (event.key.repeat == 0)
                Input::onKeyUp((Key) event.key.keysym.scancode);
        }

        else if (event.type == SDL_TEXTINPUT)
        {
            Input::onTextUTF8(event.text.text);
        }
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
    return closeWindow;
}

void Core::cleanup()
{
    Log::info("Shutting down engine...");

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


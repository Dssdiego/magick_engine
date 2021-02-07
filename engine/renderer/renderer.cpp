//
// Created by Diego Santos Seabra on 01/02/21.
//

#define GL_SILENCE_DEPRECATION

#include "renderer.h"
#ifdef __APPLE__
#include <SDL_opengl.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
//#include <SDL_opengles2.h>
//#include <SDL_opengles.h>
#include <GLES3/gl3.h>
#endif

void Renderer::clear(Color color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::drawPoint()
{
#ifdef __APPLE__
    glPointSize(100.0f);
#endif
    glDrawArrays(GL_POINTS, 0, 1);
}

void Renderer::drawTriangle()
{
//    clear(COLOR_WHITE);
//    glDrawArrays(GL_TRIANGLES, 0, 1);
}

void Renderer::drawRectangle()
{

}

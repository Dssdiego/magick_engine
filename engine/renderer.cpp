//
// Created by Diego Santos Seabra on 01/02/21.
//

#define GL_SILENCE_DEPRECATION

#include "renderer.h"
#include <GLFW/glfw3.h>

void Renderer::clear(Color color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::drawPoint()
{
    glDrawArrays(GL_POINTS, 0, 1);
}

void Renderer::drawTriangle()
{
//    clear(COLOR_WHITE);
//    glDrawArrays(GL_TRIANGLES, 0, 1);
}



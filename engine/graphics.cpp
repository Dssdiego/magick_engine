//
// Created by Diego Santos Seabra on 01/02/21.
//

#define GL_SILENCE_DEPRECATION

#include "graphics.h"
#include <GLFW/glfw3.h>

void Graphics::clear(Color color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

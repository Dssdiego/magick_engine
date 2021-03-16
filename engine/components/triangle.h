//
// Created by Diego Santos Seabra on 07/03/21.
//

#ifndef MAGICK_ENGINE_TRIANGLE_H
#define MAGICK_ENGINE_TRIANGLE_H

#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#include "../renderer/shader.h"

class Triangle
{
public:
    void init();
    void update();
    void draw();

private:
    float x = 0.0f;
    float inc = 0.01f;
    GLuint shaderProgram;
};

#endif //MAGICK_ENGINE_TRIANGLE_H

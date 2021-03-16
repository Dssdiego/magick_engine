//
// Created by Diego Santos Seabra on 07/03/21.
//

#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION


#include "triangle.h"

void Triangle::init()
{
    shaderProgram = createShader("triangle_move");
}

void Triangle::update()
{
    x += inc;
    if (x > 1.0f)
        inc = -0.01f;

    if (x < -1.0f)
        inc = 0.01f; // switch to moving the triangle to the right

    GLuint offsetLoc = glGetUniformLocation(shaderProgram, "offset");
    glProgramUniform1f(shaderProgram, offsetLoc, x);
}

void Triangle::draw()
{
    glUseProgram(shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

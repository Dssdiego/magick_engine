//
// Created by Diego Santos Seabra on 01/02/21.
//

#ifndef MAGICK_ENGINE_RENDERER_H
#define MAGICK_ENGINE_RENDERER_H

#include "../color.h"
#include "../tools/maths.h"

namespace Renderer
{
    // Clear the screen for the given color
    void clear(Color color);

    // Draws a point
    void drawPoint();

    // Draws a triangle
    void drawTriangle();

    // Draws a rectangle
    // FIXME: How to abstract this for screen coordinates?
    void drawRectangle();

    // Draws a rectangle/quad
    void drawRectangle(Vector2 position, Size size, Color color);

    // Draws a sprite
    void drawSprite(char *fileName, Vector2 position, Color color);
}

#endif //MAGICK_ENGINE_RENDERER_H

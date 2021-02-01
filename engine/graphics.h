//
// Created by Diego Santos Seabra on 01/02/21.
//

#ifndef MAGICK_ENGINE_GRAPHICS_H
#define MAGICK_ENGINE_GRAPHICS_H

typedef struct SColor
{
    int r,g,b,a;
} Color;


namespace Graphics
{
    // Clear the screen for the given color
    void clear(Color color);
}

#endif //MAGICK_ENGINE_GRAPHICS_H

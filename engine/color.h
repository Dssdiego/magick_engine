//
// Created by Diego Santos Seabra on 04/02/21.
//

#ifndef MAGICK_ENGINE_COLOR_H
#define MAGICK_ENGINE_COLOR_H

#include <cstdint>

struct Color
{
    uint8_t r,g,b,a;
};

// FIXME: There is any way that I could access like Color.White ?
const Color COLOR_BLACK { 0, 0, 0, 0};
const Color COLOR_BLUE { 0, 0, 1, 1};
const Color COLOR_GREEN { 0, 1, 0, 1};
const Color COLOR_CYAN { 0, 1, 1, 1};
const Color COLOR_RED { 1, 0, 0, 1};
const Color COLOR_PINK { 1, 0, 1, 1};
const Color COLOR_YELLOW { 1, 1, 0, 1};
const Color COLOR_WHITE { 1, 1, 1, 1};

#endif //MAGICK_ENGINE_COLOR_H

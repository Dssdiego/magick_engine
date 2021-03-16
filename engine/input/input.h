//
// Created by Diego Santos Seabra on 01/02/21.
//

#ifndef MAGICK_ENGINE_INPUT_H
#define MAGICK_ENGINE_INPUT_H

#include "key.h"
#include "./../tools/maths.h"

namespace Input
{
    // maximum number of keys the input will track
    constexpr int maxKeyboardKeys = 512;

    // maximum length of text input that can be received per-frame
    constexpr int maxTextInput = 256;

    // maximum number of mouse buttons the input will track
    constexpr int maxMouseButtons = 16;

    // maximum number of controller buttons the input will track
    constexpr int maxControllerButtons = 64;

    void init();
    void frame();

    /* Keyboard */
    void onKeyDown(Key key);
    void onKeyUp(Key key);
    void onTextUTF8(const char *text);

    /* Mouse */
    void onMouseDown(MouseButton button);
    void onMouseUp(MouseButton button);
    void onMouseWheel(Point wheel);
    // TODO: Implement

    /* Controller */
    // TODO: Implement
}

#endif //MAGICK_ENGINE_INPUT_H

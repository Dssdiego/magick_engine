//
// Created by Diego Santos Seabra on 01/02/21.
//

#ifndef MAGICK_ENGINE_INPUT_H
#define MAGICK_ENGINE_INPUT_H

#include "key.h"

namespace Input
{
    // maximum number of keys the input will track
    constexpr int maxKeyboardKeys = 512;

    // maximum length of text input that can be received per-frame
    constexpr int maxTextInput = 256;

    void init();
    void frame();

    /* Keyboard */
    void onKeyDown(Key key);
    void onKeyUp(Key key);
    void onTextUTF8(const char *text);

    /* Mouse */
    // TODO: Implement

    /* Controller */
    // TODO: Implement
}

#endif //MAGICK_ENGINE_INPUT_H

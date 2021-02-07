//
// Created by Diego Santos Seabra on 01/02/21.
//

#include <cstdint>
#include <cstring>
#include "input.h"
#include "inputstate.h"

InputState lastState;
InputState currentState;
InputState nextState;
InputState emptyState;

void Input::init()
{
    lastState = emptyState;
    currentState = emptyState;
    nextState = emptyState;
}

void Input::frame()
{
    // Cycle states
    lastState = currentState;
    currentState = nextState;

    // Copy states, clear pressed / released values
    for (int i = 0; i < maxKeyboardKeys; ++i)
    {
        nextState.keyboard.pressed[i] = false;
        nextState.keyboard.released[i] = false;
    }

    for (int i = 0; i < maxTextInput; ++i)
    {
        nextState.keyboard.text[i] = 0;
    }
}

/* Keyboard */

void Input::onKeyDown(Key key)
{
    int i = (int)key;
    if (i >= 0 && i < maxKeyboardKeys)
    {
        nextState.keyboard.down[i] = true;
        nextState.keyboard.pressed[i] = true;
//        nextState.keyboard.timestamp[i] = Time::ticks; // TODO: Implement
    }
}

void Input::onKeyUp(Key key)
{
    int i = (int)key;
    if (i >= 0 && i < maxKeyboardKeys)
    {
        nextState.keyboard.down[i] = false;
        nextState.keyboard.released[i] = true;
    }
}

void Input::onTextUTF8(const char *text)
{
    strncat(nextState.keyboard.text, text, maxTextInput);
}


/* Mouse */
// TODO: Implement

/* Controller */
// TODO: Implement


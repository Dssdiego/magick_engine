//
// Created by Diego Santos Seabra on 07/02/21.
//

#ifndef MAGICK_ENGINE_INPUTSTATE_H
#define MAGICK_ENGINE_INPUTSTATE_H

struct KeyboardState
{
    bool pressed[Input::maxKeyboardKeys];
    bool down[Input::maxKeyboardKeys];
    bool released[Input::maxKeyboardKeys];
    uint64_t timestamp[Input::maxKeyboardKeys];
    char text[Input::maxTextInput];
};

// An Input State, which stores the state for gamepads, keyboard, and mouse
struct InputState
{
    // All the Gamepads. Note that not all gamepads are necessarily connected,
    // and each one must be checked before use.
//    ControllerState controllers[Input::max_controllers];

    // The current Keyboard state
    KeyboardState keyboard;

    // The current Mouse state
//    MouseState mouse;
};

#endif //MAGICK_ENGINE_INPUTSTATE_H

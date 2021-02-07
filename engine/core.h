//
// Created by Diego Santos Seabra on 01/02/21.
//

#ifndef MAGICK_ENGINE_CORE_H
#define MAGICK_ENGINE_CORE_H

namespace Core
{
    // Initializes a window
    void initWindow();

    // Whether should close the window or not
    int shouldClose();

    // Draw on the screen
    void swapBuffers();

    // Poll events
    void pollEvents();

    // Cleans the memory used in the process
    void cleanup();
}

#endif //MAGICK_ENGINE_CORE_H

//
// Created by Diego Santos Seabra on 07/02/21.
//

#ifndef MAGICK_ENGINE_TOOLS_H
#define MAGICK_ENGINE_TOOLS_H

#include "maths.h"
#include <iostream>

namespace Tools
{
    // Takes a screenshot of the screen and saves it to the "screenshots/" folder
    void takeScreenshot(Size windowSize);

    std::string getAssetPath();
}

#endif //MAGICK_ENGINE_TOOLS_H

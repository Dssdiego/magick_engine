//
// Created by Diego Santos Seabra on 07/02/21.
//

#define IMAGE_WRITE_IMPLEMENTATION
#include "../../libs/stb_image/stb_image_write.h"

#include <cstdint>
#include "tools.h"
#include "log.h"
#include <ctime>
#include <SDL_opengl.h>
#include <filesystem>

#define CHANNEL_NUM 3

void Tools::takeScreenshot(Size windowSize)
{
    auto *pixels = new uint8_t[windowSize.width * windowSize.height * CHANNEL_NUM];
    glReadPixels(0, 0, windowSize.width, windowSize.height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    time_t theTime = time(nullptr);
    struct tm *curTime = localtime(&theTime);
    int day = curTime->tm_mday;
    int month = curTime->tm_mon + 1;
    int year = curTime->tm_year + 1900;
    int hour = curTime->tm_hour;
    int min = curTime->tm_min;
    int sec = curTime->tm_sec;

    std::string screenFileName = getAssetPath() + "screenshots/" + std::to_string(day) + "_" +
                                 std::to_string(month) + "_" +
                                 std::to_string(year) + "_" +
                                 std::to_string(hour) + std::to_string(min) + std::to_string(sec) +
                                 ".png";


    // Flips the framebuffer vertically
    stbi_flip_vertically_on_write(true);
    stbi_write_png(screenFileName.c_str(), windowSize.width, windowSize.height, 3, pixels,
                   windowSize.width * 3);
    std::string logString = "Screenshot " + screenFileName + " created!";
    Log::info(logString.c_str());
}

std::string Tools::getAssetPath()
{
    auto parentPath = std::filesystem::current_path().parent_path();
    return parentPath.concat("/assets/");
}

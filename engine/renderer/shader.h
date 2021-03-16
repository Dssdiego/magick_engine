//
// Created by Diego Santos Seabra on 03/02/21.
//

#ifndef MAGICK_ENGINE_SHADER_H
#define MAGICK_ENGINE_SHADER_H

#include <SDL_opengl.h>
#include <iostream>

GLuint createShader(const std::string &shaderName);
const char * getShaderAsset(const std::string &shaderName);

#endif //MAGICK_ENGINE_SHADER_H

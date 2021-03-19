//
// Created by Diego Santos Seabra on 03/02/21.
//

#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION

#include "shader.h"
#include "../tools/log.h"
#include "../tools/tools.h"
#include <string>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#include <vector>

#else
#include <GL/gl.h>
#endif

std::vector<std::string> readShaderFile(const char *filePath)
{
    bool getVertex = false;
    bool getFragment = false;

    std::ifstream fileStream(filePath, std::ios::in);

    std::string vertexStr;
    std::string fragmentStr;

    std::vector<std::string> shaderStr;

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return shaderStr;
    }

    std::string line;
    while(!fileStream.eof()) {
        std::getline(fileStream, line);

        if(line == "// vertex")
        {
            getVertex = true;
            getFragment = false;
        }

        if (line == "// fragment")
        {
            getFragment = true;
            getVertex = false;
        }

        if (getVertex && line != "// vertex")
        {
            vertexStr.append(line + "\n");
        }

        if (getFragment && line != "// fragment")
        {
            fragmentStr.append(line + "\n");
        }
    }

    shaderStr.push_back(vertexStr);
    shaderStr.push_back(fragmentStr);

    fileStream.close();

    return shaderStr;
}

const char * getShaderAsset(const std::string &shaderName)
{
    return Tools::getAssetPath().append("shaders/").append(shaderName).append(".glsl").c_str();
}

// NOTE: The use of GLuint is platform independent ;)
GLuint createShader(const std::string &shaderName)
{
    // Get shader path from name
    const char *shaderPath = getShaderAsset(shaderName);

    GLint result = GL_FALSE;
    int logLength;

    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Read shaders

    std::vector<std::string> shaderStr = readShaderFile(shaderPath);
    const char *vertShaderSrc = shaderStr[0].c_str();
    const char *fragShaderSrc = shaderStr[1].c_str();
    // TODO: Implement tesselation and geometry shaders (?)

    // Compile vertex shader

    Log::info("Compiling vertex shader");
    glShaderSource(vertShader, 1, &vertShaderSrc, nullptr);
    glCompileShader(vertShader);

    // Check vertex shader

    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    char *vertShaderError = nullptr;
    glGetShaderInfoLog(vertShader, logLength, nullptr, vertShaderError);
    std::cout << &vertShaderError << std::endl;

    // Compile fragment shader

    Log::info("Compiling fragment shader");
    glShaderSource(fragShader, 1, &fragShaderSrc, nullptr);
    glCompileShader(fragShader);

    // Check fragment shader

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    char *fragShaderError = nullptr;
    glGetShaderInfoLog(fragShader, logLength, nullptr, fragShaderError);
    std::cout << &fragShaderError << std::endl;

    Log::info("Linking shader program");
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    char *programError = nullptr;
    glGetProgramInfoLog(program, logLength, nullptr, programError);
    std::cout << &programError << std::endl;

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}

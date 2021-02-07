//
// Created by Diego Santos Seabra on 03/02/21.
//

#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION

#include "glshader.h"
#include "../tools/log.h"
#include <string>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#else
#include <GL/gl.h>
#endif

std::string readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line;
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}


// NOTE: The use of GLuint is platform independent ;)
GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Read shaders

    std::string vertShaderStr = readFile(vertex_path);
    std::string fragShaderStr = readFile(fragment_path);
    const char *vertShaderSrc = vertShaderStr.c_str();
    const char *fragShaderSrc = fragShaderStr.c_str();

    GLint result = GL_FALSE;
    int logLength;

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
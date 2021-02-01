cmake_minimum_required(VERSION 3.17)
project(magick_engine)

set(CMAKE_CXX_STANDARD 14)

# Don't build glfw docs, tests or examples
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)

add_subdirectory(libs/glfw-3.3.2)

add_executable(magick_engine
        main.cpp
        engine/core.cpp
        engine/core.h

        game/game.cpp game/game.h engine/graphics.cpp engine/graphics.h engine/input.cpp engine/input.h)

target_link_libraries(magick_engine glfw)
target_link_libraries(magick_engine OpenGL::GL)
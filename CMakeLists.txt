cmake_minimum_required(VERSION 3.17)
project(magick_engine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Wno-missing-braces")

if(${EMSCRIPTEN})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -s USE_SDL=2 -std=c++1z")
    file(COPY engine/web/index.html DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
else()
#    file(COPY assets/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    find_package(SDL2 REQUIRED)
    find_package(OpenGL REQUIRED)
endif()

include_directories(SYSTEM libs ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
#include_directories(${PROJECT_SOURCE_DIR}/libs/fmod/core/inc)
#link_directories(${PROJECT_SOURCE_DIR}/libs/fmod/core/lib)
#include_directories(${PROJECT_SOURCE_DIR}/libs/fmod/studio/inc)
#link_directories(${PROJECT_SOURCE_DIR}/libs/fmod/studio/lib)

#include_directories(${CMAKE_SOURCE_DIR}/libs/fmod/core/inc)
#link_directories(${CMAKE_SOURCE_DIR}/libs/fmod/core/lib)
#include_directories(${CMAKE_SOURCE_DIR}/libs/fmod/studio/inc)
#link_directories(${CMAKE_SOURCE_DIR}/libs/fmod/studio/lib)

# FMOD (Core)
include_directories(libs/fmod/core/inc)
link_directories(libs/fmod/core/lib)

# FMOD (Studio)
include_directories(libs/fmod/studio/inc)
link_directories(libs/fmod/studio/lib)

add_subdirectory(libs/stb_image)

add_executable(magick_engine
        main.cpp

        libs/stb_image/stb_image_write.h

        game/game.cpp
        game/game.h

        engine/core.cpp
        engine/core.h
        engine/renderer/renderer.cpp
        engine/renderer/renderer.h
        engine/input/input.cpp
        engine/input/input.h
        engine/tools/log.cpp
        engine/tools/log.h
        engine/renderer/shader.cpp
        engine/renderer/shader.h
        engine/color.h
        engine/tools/maths.h
        engine/input/key.h
        engine/tools/tools.cpp
        engine/tools/tools.h
        engine/input/inputstate.h
        engine/audio/audio.cpp
        engine/audio/audio.h engine/components/triangle.cpp engine/components/triangle.h)

#if(EMSCRIPTEN)
#    set_target_properties(magick_engine PROPERTIES LINK_FLAGS "-s DEMANGLE_SUPPORT=1 --preload-file assets --bind")
#endif()

source_group(libs REGULAR_EXPRESSION libs)
source_group(engine REGULAR_EXPRESSION engine)

set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++17")

target_link_libraries(magick_engine ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} -lfmod -lfmodL -lfmodstudio -lfmodstudioL)

# TODO: When building, remember to copy SDL to build directory!
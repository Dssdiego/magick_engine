//
// Created by Diego Santos Seabra on 03/03/21.
//

// NOTE: Tutorial >> https://codyclaborn.me/tutorials/making-a-basic-fmod-audio-engine-in-c/

#include "audio.h"
#include "../tools/log.h"
#include <fmod_studio.hpp>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <cstdio>

FMOD_RESULT result;
FMOD::Studio::System *system = nullptr;

void Audio::init()
{
    // Creates the studio system object
    result = FMOD::Studio::System::create(&system);

    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
//        Log::error("FMOD Error! (%d) %s\n");
    } else {
        Log::info("FMOD Core init success");
    }

    // Initialize FMOD Studio, which will also initialize FMOD Core
    result = system->initialize(512, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);

    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
    } else {
        Log::info("FMOD Studio init success");
    }
}

void Audio::update()
{
    system->update();
}

void Audio::shutdown()
{
    if (system != nullptr)
        system->release();
}

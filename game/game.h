//
// Created by Diego Santos Seabra on 01/02/21.
//

#ifndef MAGICK_ENGINE_GAME_H
#define MAGICK_ENGINE_GAME_H

// NOTE: Just for example, change it at will
enum GameState
{
    ACTIVE,
    MENU,
    WIN
};

namespace Game
{
    void init();
    void update();
    void draw(double time);
}

#endif //MAGICK_ENGINE_GAME_H

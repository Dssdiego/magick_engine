//
// Created by Diego Santos Seabra on 01/02/21.
//

#include "game.h"
#include "../engine/components/triangle.h"

Triangle triangle;

void Game::init()
{
    // TODO: Make this automatic for "n" number os entities on the game
    triangle.init();
}

void Game::update()
{
    triangle.update();
}

// TODO: Make calculations to run draw on constant speed (delta time)
//  in all machines
void Game::draw() // REVIEW: Is this time or delta time?
{
    triangle.draw();
}

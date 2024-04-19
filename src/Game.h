#pragma once

#include "raylib.h"
#include "Timer.h"
#include "Pony.h"
#include "Highscore.h"
#include "Amunition.h"
#include "InputHandlerInterface.h"
#include "GraphicsRendererInterface.h"
#include "AudioRendererInterface.h"
#include <list>

// class for managing the game state and game logic
class Game
{
public:
    // constructor with input-, graphics- and audiorenderer that the game can call on
    Game(InputHandlerInterface *inputHandler, GraphicsRendererInterface *graphicsRenderer, AudioRendererInterface *audioRenderer);

    // gameplay methods
    void start();
    void pause();
    void resume();
    void end();
    void reset();

    void shoot();
    void reload();
    bool update(); // returns true if game is over

    // getter
    std::list<Pony> *getPonyList();
    int getAmmunition();
    int getScore();
    int getTimeLeft();

private:
    // pointer to handlers
    InputHandlerInterface *inputHandler = nullptr;
    GraphicsRendererInterface *graphicsRenderer = nullptr;
    AudioRendererInterface *audioRenderer = nullptr;

    // game members
    unsigned short int maxEntities; // maxEntitites on screen. Could be used to change difficulty later or other logic stuff
    Timer timer;
    Highscore highscore;
    Amunition ammunition;
    std::list<Pony> ponyList; // list of ponies in the game
};
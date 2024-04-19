#pragma once

#include <raylib.h>
#include <list>
#include "Pony.h"
#include <map>

// interface for renderering graphics
class GraphicsRendererInterface
{
public:
    virtual ~GraphicsRendererInterface(){};

    // ui elements
    virtual int showMenu() = 0;
    virtual int showPause() = 0;
    virtual int showGameOver(int score) = 0;

    // background of in game
    virtual void drawBackground() = 0;
    virtual void resetBackground() = 0;

    // drawing in game componentents
    virtual void drawPony(std::list<Pony> *ponyList) = 0;
    virtual void drawBlood(Pony *pony) = 0;
    virtual void drawAmmunition(int ammoLeft) = 0;
    virtual void drawHighscore(int highscore) = 0;
    virtual void drawTimer(int timeLeft) = 0;
    virtual void drawCrosshair(Vector2 *mousePosition) = 0;

private:
    virtual void loadTextures() = 0; // loading textures from file
};
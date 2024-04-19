#pragma once

#include <raylib.h>

// Interface for InputHandler, could be used to implement different inputHandlers e.g. Controller
// Separating the input handling from the game logic
class InputHandlerInterface
{
public:
    virtual ~InputHandlerInterface(){};

    virtual void handleInput() = 0;
    virtual void reset() = 0;

    virtual bool isShooting() = 0;
    virtual bool isReloading() = 0;
    virtual bool isPaused() = 0;
    virtual Vector2 *getMousePosition() = 0;
    virtual bool toggleFullscreen() = 0;
};
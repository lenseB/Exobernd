#pragma once

#include "InputHandlerInterface.h"

// implementation of InputHandlerInterface for Raylib
class InputHandlerRaylib : public InputHandlerInterface
{
public:
    InputHandlerRaylib();
    ~InputHandlerRaylib();

    void handleInput() override;
    bool toggleFullscreen() override;
    void reset() override;

    bool isShooting() override;
    bool isReloading() override;
    bool isPaused() override;

    Vector2 *getMousePosition() override;

private:
    bool shooting;
    bool reloading;
    bool paused;
    Vector2 mousePosition;
};
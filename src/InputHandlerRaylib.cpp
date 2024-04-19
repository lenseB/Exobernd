#include "InputHandlerRaylib.h"

InputHandlerRaylib::InputHandlerRaylib()
{
    SetExitKey(KEY_Q);
    shooting = false;
    reloading = false;
    paused = false;
    mousePosition = {0, 0};
}

InputHandlerRaylib::~InputHandlerRaylib()
{
}

//
void InputHandlerRaylib::handleInput()
{
    // else cases for resetting  the booleans
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        shooting = true;
    }
    else
    {
        shooting = false;
    }

    if (IsKeyPressed(KEY_R))
    {
        reloading = true;
    }
    else
    {
        reloading = false;
    }

    if (IsKeyPressed(KEY_ESCAPE))
    {
        paused = true;
    }
    else
    {
        paused = false;
    }

    mousePosition = GetMousePosition();
}

void InputHandlerRaylib::reset()
{
    shooting = false;
    reloading = false;
    paused = false;
    mousePosition = {0, 0};
}

bool InputHandlerRaylib::isPaused()
{
    return paused;
}

Vector2 *InputHandlerRaylib::getMousePosition()
{
    return &mousePosition;
}

bool InputHandlerRaylib::isShooting()
{
    return shooting;
}

bool InputHandlerRaylib::isReloading()
{
    return reloading;
}

bool InputHandlerRaylib::toggleFullscreen()
{
    if (IsKeyPressed(KEY_F11))
    {
        return true;
    }
    return false;
}
#pragma once

#include <raylib.h>

enum PonyType
{
    SMALL,
    MEDIUM,
    LARGE
}; // enum for pony types

class Pony
{
public:
    Pony(PonyType type, Vector2 position, Vector2 speed, int radius);
    bool update(); // updates position of pony and returns true if pony is offscreen
    bool isHit(int x, int y);
    Vector2 getPosition();
    int getDirection();
    PonyType getType(); // for renderer

private:
    const PonyType type;
    Vector2 position;
    Vector2 speed;
    const int radius;
};
#include <raylib.h>
#include <stdlib.h>
#include "Pony.h"

Pony::Pony(PonyType type, Vector2 position, Vector2 speed, int radius) : type(type), position(position), speed(speed), radius(radius / 2)
{
}

bool Pony::update()
{
    position.x += speed.x;
    position.y += speed.y;

    if (speed.x > 0)
    {
        if (position.x - radius >= GetScreenWidth())
        {
            return true;
        }
    }
    else
    {
        if (position.x + radius <= 0)
        {
            return true;
        }
    }
    return false;
}

bool Pony::isHit(int x, int y)
{
    if (abs(position.x - x) <= radius && abs(position.y - y) <= radius)
    {
        return true;
    }
    return false;
}

Vector2 Pony::getPosition()
{
    return position;
}

int Pony::getDirection()
{
    return (int)speed.x;
}

PonyType Pony::getType()
{
    return type;
}

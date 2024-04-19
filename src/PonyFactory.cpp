#include "PonyFactory.h"

// Factory Pattern for creating ponies in a certain way

/*
initializes a certain amount of ponies.
*/

std::list<Pony> PonyFactory::initPonies(int numPonies)
{
    std::list<Pony> ponyList;
    for (int i = 0; i < numPonies; i++)
    {
        PonyType ponyType = (PonyType)GetRandomValue(0, 2); // random pony type
        Vector2 speed = ponyTypeMap.at(ponyType).first;     // map.at is const safe, using [] would try to create a new element if it doesn't exist
        int radius = ponyTypeMap.at(ponyType).second;

        int x = GetRandomValue(0, GetScreenWidth()); // ponies can spawn anywhere on the screen at the beginning
        int y = GetRandomValue(radius, GetScreenHeight() - radius);

        // set direction depending on spawn point
        if (x > GetScreenWidth() / 2)
        {
            speed.x *= -1;
        }

        Vector2 position = {(float)x, (float)y}; // random position for pony within screenheight
        Pony pony(ponyType, position, speed, radius);
        ponyList.push_back(pony);
    }
    return ponyList;
}

// create a pony of a random type, random position
Pony PonyFactory::createPony()
{
    PonyType ponyType = (PonyType)GetRandomValue(0, 2); // random pony type
    Vector2 speed = ponyTypeMap.at(ponyType).first;     // map.at is const safe, using [] would try to create a new element if it doesn't exist
    int radius = ponyTypeMap.at(ponyType).second;
    int x = GetRandomValue(0, 1); // spawn pony either on the left or right side of the screen
    int y = GetRandomValue(radius, GetScreenHeight() - radius);

    // set direction depending on spawn side of screen
    if (x) // right side
    {
        x = GetScreenWidth() + ponyTypeMap.at(LARGE).second;
        speed.x *= -1; // so ponies is flying to the left
    }
    else
    {
        x = -ponyTypeMap.at(LARGE).second;
    }

    Vector2 position = {(float)x, (float)y}; // random position for pony within screenheight
    Pony pony(ponyType, position, speed, radius);
    return pony;
}

/*
maps pony type to speed and size
could be adjusted to screen size
*/
const std::map<PonyType, std::pair<Vector2, int>> PonyFactory::ponyTypeMap = {
    {SMALL, std::make_pair(Vector2{4.0f, 0}, 20)},
    {MEDIUM, std::make_pair(Vector2{6.0f, 0}, 30)},
    {LARGE, std::make_pair(Vector2{8.0f, 0}, 40)}};
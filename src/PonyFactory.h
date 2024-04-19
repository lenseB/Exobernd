#pragma once

#include <raylib.h>
#include "Pony.h"
#include <utility>
#include <map>
#include <list>

class PonyFactory
{

public:
    static std::list<Pony> initPonies(int numPonies);
    static Pony createPony();

private:
    static const std::map<PonyType, std::pair<Vector2, int>> ponyTypeMap; // map: PonyType -> speed, radius
};
#pragma once

#include <map>
#include "Pony.h"

// class for managing highscores
class Highscore
{
public:
    Highscore();
    void addPoints(PonyType ponyType);
    void reset();
    int getScore();

private:
    int score;
    std::map<PonyType, int> ponyPoints; // maps pony type to points
};
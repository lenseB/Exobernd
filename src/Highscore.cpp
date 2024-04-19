#include "Highscore.h"

Highscore::Highscore()
{
    score = 0;
    ponyPoints = std::map<PonyType, int>() = {
        {SMALL, 25},
        {MEDIUM, 10},
        {LARGE, 5}};
}

int Highscore::getScore()
{
    return score;
}

void Highscore::addPoints(PonyType ponyType)
{
    score += ponyPoints[ponyType];
}

void Highscore::reset()
{
    score = 0;
}
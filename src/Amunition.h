#pragma once

#include <raylib.h>
#include "Timer.h"

// Amunition handles ammunition of the player, reloading, ...
class Amunition
{
public:
    Amunition(int size);
    bool isEmpty();
    bool isReloading();
    void reload();
    void shoot();
    void update();
    int getAmmoLeft();

private:
    int size = 10;
    int ammoLeft = 10;
    bool reloading;
    Timer reloadTimer; // Timer to delay next reload
};
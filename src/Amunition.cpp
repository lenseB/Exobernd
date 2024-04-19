#include "Amunition.h"

Amunition::Amunition(int size) : size(size), ammoLeft(size), reloading(false), reloadTimer(1)
{
}

bool Amunition::isEmpty()
{
    return !(bool)ammoLeft; // 0 = False => isEmpty is true
}

void Amunition::reload()
{
    ammoLeft = size;
    reloading = true;
    reloadTimer.start();
}

bool Amunition::isReloading()
{
    return reloading;
}

void Amunition::shoot()
{
    ammoLeft--;
}

void Amunition::update()
{
    reloadTimer.update();
    if (!reloadTimer.isRunning()) // nicht mehr am reloaden
    {
        reloading = false;
        reloadTimer.reset();
    }
}

int Amunition::getAmmoLeft()
{
    return ammoLeft;
}

#include "Game.h"
#include "PonyFactory.h"
#include "Timer.h"

Game::Game(InputHandlerInterface *inputHandler, GraphicsRendererInterface *graphicsRenderer, AudioRendererInterface *audioRenderer) : inputHandler(inputHandler), graphicsRenderer(graphicsRenderer), audioRenderer(audioRenderer), maxEntities(20), timer(60), highscore(), ammunition(10)
{
    ponyList = PonyFactory::initPonies(maxEntities);
}

void Game::start()
{
    timer.start();
    audioRenderer->playGameMusic();
}

void Game::resume()
{
    audioRenderer->resumeGameMusic();
    timer.resume();
}

void Game::end()
{
    audioRenderer->stopGameMusic();
    // play game finishing sound depending on score
    if (highscore.getScore() > 750)
    {
        audioRenderer->playHighScoreSound();
    }
    else
    {
        audioRenderer->playLowScoreSound();
    }
}

void Game::reset()
{
    timer.reset();
    highscore.reset();
    ammunition.reload();
    ponyList.clear();
    graphicsRenderer->resetBackground();
    ponyList = PonyFactory::initPonies(maxEntities);
}

void Game::shoot()
{
    if (ammunition.isReloading()) // player is reloading
    {
        // update reloadTimer and do nothing else
        ammunition.update();
        return;
    }
    else if (ammunition.isEmpty()) // no ammunition
    {
        audioRenderer->playEmptyAmmunitionSound();
        return;
    }
    else // player can shoot
    {
        Vector2 *mousePosition = inputHandler->getMousePosition();
        int multiKill = 0;
        ammunition.shoot();
        audioRenderer->playShootSound();
        // check if a pony is hit
        for (std::list<Pony>::iterator it = ponyList.begin(); it != ponyList.end(); it++)
        {
            if (it->isHit(mousePosition->x, mousePosition->y))
            {
                audioRenderer->playHitSound();
                highscore.addPoints(it->getType());
                graphicsRenderer->drawBlood(&(*it));
                multiKill++;
                it = ponyList.erase(it);
                ponyList.push_front(PonyFactory::createPony()); // create new pony at front so it doesn't iterate over it
            }
        }
        if (multiKill > 1) // if more than one pony is hit with one shot
        {
            audioRenderer->playMultiKill();
        }
    }
}

void Game::reload()
{
    if (!ammunition.isReloading())
    {
        ammunition.reload();
        audioRenderer->playReloadSound();
    }
    else
    {
        // update reloadTimer because already reloading
        ammunition.update();
    }
}

// returns true if game is over
bool Game::update()
{
    for (std::list<Pony>::iterator it = ponyList.begin(); it != ponyList.end(); /* increment in else case*/)
    {
        if (it->update()) // if pony is offscreen
        {
            it = ponyList.erase(it); // return iterator to next element of list, so no increment needed
            ponyList.push_back(PonyFactory::createPony());
        }
        else
        {
            it++; // increment here because otherwise it would skip the next element after erasing
        }
    }

    timer.update();
    ammunition.update();
    return !timer.isRunning(); // game is over when timer is not running anymore
}

void Game::pause()
{
    audioRenderer->pauseGameMusic();
    timer.stop();
}

int Game::getScore()
{
    return highscore.getScore();
}

int Game::getAmmunition()
{
    return ammunition.getAmmoLeft();
}

int Game::getTimeLeft()
{
    return timer.getTimeLeft();
}

std::list<Pony> *Game::getPonyList()
{
    return &ponyList;
}

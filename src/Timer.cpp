#include "Timer.h"
#include <raylib.h>

Timer::Timer(float duration) : duration(duration), elapsed(0), running(false) {}

void Timer::start()
{
    running = true;
    elapsed = 0;
}

void Timer::stop()
{
    running = false;
}

void Timer::resume()
{
    running = true;
}

void Timer::update()
{
    if (running)
    {
        elapsed += GetFrameTime();
        // check if the timer has finished
        if (elapsed >= duration)
        {
            running = false;
        }
    }
}

void Timer::reset()
{
    elapsed = 0;
    running = false;
}

int Timer::getTimeLeft() const
{
    // explicitly cast to int, because only whole seconds are relevant
    return (int)duration - elapsed;
}

bool Timer::isRunning() const
{
    return running;
}

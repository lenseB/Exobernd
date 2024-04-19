#pragma once

#include <raylib.h>

// class that manages timer and its state
class Timer
{
public:
    Timer(float duration);

    void start();
    void stop();
    void resume();
    void update();
    void reset();
    int getTimeLeft() const;
    bool isRunning() const;

private:
    float duration;
    float elapsed;
    bool running;
};

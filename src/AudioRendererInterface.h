#pragma once

#include <string>

// interface for audio rendering
class AudioRendererInterface
{
public:
    virtual ~AudioRendererInterface(){};

    // functions for playing Menu Music
    virtual void playMenuMusic() = 0;
    virtual void updateMenuMusic() = 0;
    virtual void stopGameMusic() = 0;

    // functions for playing Game Music
    virtual void playGameMusic() = 0;
    virtual void pauseGameMusic() = 0;
    virtual void resumeGameMusic() = 0;
    virtual void updateGameMusic() = 0;
    virtual void stopMenuMusic() = 0;

    // functions for playing sounds
    virtual void playHitSound() = 0;
    virtual void playMultiKill() = 0;
    virtual void playShootSound() = 0;
    virtual void playReloadSound() = 0;
    virtual void playEmptyAmmunitionSound() = 0;
    virtual void playOptionSound() = 0;
    virtual void playLowScoreSound() = 0;
    virtual void playHighScoreSound() = 0;

private:
    // functions for loading sound from file
    virtual void loadSounds() = 0;
};
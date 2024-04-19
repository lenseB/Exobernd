#pragma once

#include "AudioRendererInterface.h"
#include "raylib.h"

// implementations for AudioRendererInterface with Raylib
class AudioRendererRaylib : public AudioRendererInterface
{
public:
    AudioRendererRaylib();
    ~AudioRendererRaylib();

    void playMenuMusic() override;
    void updateMenuMusic() override; // raylib spezifisch, somit kein override und zum usen des interfaces, müsste man die funktion in der implementierung von playMenuMusic integrieren
    void stopMenuMusic() override;

    void playGameMusic() override;
    void updateGameMusic() override;
    void resumeGameMusic() override;
    void pauseGameMusic() override;
    void stopGameMusic() override;

    void playHitSound() override;
    void playMultiKill() override;
    void playShootSound() override;
    void playReloadSound() override;
    void playEmptyAmmunitionSound() override;
    void playOptionSound() override;
    void playLowScoreSound() override;
    void playHighScoreSound() override;

private:
    void loadSounds() override;
    Sound hitSound;
    Sound shootSound;
    Sound reloadSound;
    Sound emptySound;
    Sound optionSound;
    Sound multiKillSound;
    Sound lowScoreSound;
    Sound highScoreSound;
    Music menuMusic;
    Music gameMusic;
};
#include "AudioRendererRaylib.h"
AudioRendererRaylib::AudioRendererRaylib()
{
    InitAudioDevice();
    loadSounds();
}
AudioRendererRaylib::~AudioRendererRaylib()
{
    UnloadSound(hitSound);
    UnloadSound(shootSound);
    UnloadSound(reloadSound);
    UnloadSound(emptySound);
    UnloadSound(optionSound);
    UnloadSound(multiKillSound);
    UnloadSound(lowScoreSound);
    UnloadSound(highScoreSound);
    UnloadMusicStream(menuMusic);
    UnloadMusicStream(gameMusic);
    CloseAudioDevice();
}

void AudioRendererRaylib::playMenuMusic()
{
    PlayMusicStream(menuMusic);
}

void AudioRendererRaylib::updateMenuMusic()
{
    UpdateMusicStream(menuMusic);
}

void AudioRendererRaylib::stopMenuMusic()
{
    StopMusicStream(menuMusic);
}

void AudioRendererRaylib::pauseGameMusic()
{
    PauseMusicStream(gameMusic);
}

void AudioRendererRaylib::resumeGameMusic()
{
    ResumeMusicStream(gameMusic);
}

void AudioRendererRaylib::playGameMusic()
{
    PlayMusicStream(gameMusic);
}
void AudioRendererRaylib::updateGameMusic()
{
    UpdateMusicStream(gameMusic);
}

void AudioRendererRaylib::stopGameMusic()
{
    StopMusicStream(gameMusic);
}

void AudioRendererRaylib::playHitSound()
{
    PlaySound(hitSound);
}

void AudioRendererRaylib::playMultiKill()
{
    PlaySound(multiKillSound);
}

void AudioRendererRaylib::playLowScoreSound()
{
    PlaySound(lowScoreSound);
}

void AudioRendererRaylib::playHighScoreSound()
{
    PlaySound(highScoreSound);
}

void AudioRendererRaylib::playShootSound()
{
    PlaySound(shootSound);
}

void AudioRendererRaylib::playReloadSound()
{
    PlaySound(reloadSound);
}

void AudioRendererRaylib::playEmptyAmmunitionSound()
{
    PlaySound(emptySound);
}

void AudioRendererRaylib::playOptionSound()
{
    PlaySound(optionSound);
}

void AudioRendererRaylib::loadSounds()
{
    // LoadSound does not throw any errors, just logging... so no error catching
    hitSound = LoadSound("resources/sound/hit.mp3");
    shootSound = LoadSound("resources/sound/shoot.mp3");
    reloadSound = LoadSound("resources/sound/reload.mp3");
    emptySound = LoadSound("resources/sound/empty.mp3");
    optionSound = LoadSound("resources/sound/option.wav");
    multiKillSound = LoadSound("resources/sound/multiKill.mp3");
    lowScoreSound = LoadSound("resources/sound/lowScore.mp3");
    highScoreSound = LoadSound("resources/sound/highScore.mp3");
    menuMusic = LoadMusicStream("resources/sound/menuMusic.mp3");
    gameMusic = LoadMusicStream("resources/sound/gameMusic.mp3");
}
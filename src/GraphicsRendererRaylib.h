#pragma once

#include "GraphicsRendererInterface.h"
#include <raylib.h>

// implementation of the GraphicsRendererInterface for Raylib
class GraphicsRendererRaylib : public GraphicsRendererInterface
{
public:
    GraphicsRendererRaylib(int screenWidth, int screenHeight, const char *title); // constructor for graphics renderer, initializes window and loads textures
    ~GraphicsRendererRaylib();

    int showMenu() override;
    int showPause() override;
    int showGameOver(int score) override;

    void drawBackground() override;
    void resetBackground() override;

    void drawPony(std::list<Pony> *ponyList) override;
    void drawBlood(Pony *pony) override;
    void drawAmmunition(int ammoLeft) override;
    void drawHighscore(int highscore) override;
    void drawTimer(int timeLeft) override;
    void drawCrosshair(Vector2 *mousePosition) override;

private:
    int screenHeight;
    int screenWidth;
    float screenRatio;
    float buttonWidth;  // float because used in rectangle which takes a float
    float buttonHeight; // float because used in rectangle which takes a float
    float buttonXPos;   // x pos to center buttons, float because used in rectangle which takes a float
    int textHeight;
    void loadTextures();
    std::map<PonyType, int> ponySize = {{SMALL, 20}, {MEDIUM, 30}, {LARGE, 40}}; // map with information about the ponies and sizes

    Rectangle sourceRecRight; // sourceRec for ponies flying towards right side
    Rectangle sourceRecLeft;  // sourceRec for ponies flying towards left side

    Vector2 ammunitionPosition;
    Vector2 highscorePosition;
    Vector2 timerPosition;

    Font customFont;

    Texture2D menu;
    Texture2D endScreen;
    Texture2D backgroundTexture;
    RenderTexture2D backgroundRenderTexture; // for drawing bloodstains
    Texture2D crosshairTexture;
    Texture2D ponyTexture;
    Texture2D bloodTexture;
    Texture2D bulletTexture;
};
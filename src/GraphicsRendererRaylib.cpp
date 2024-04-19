#include "GraphicsRendererRaylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "guiStyle.h"
#include <stdexcept>
#include <iostream>

GraphicsRendererRaylib::GraphicsRendererRaylib(int width, int height, const char *title) : screenHeight(height), screenWidth(width)
{

    InitWindow(screenWidth, screenHeight, "Exobernd"); // needs to be called first, because it initializes the OpenGL context which is required by loadTextures
    SetTargetFPS(60);

    screenRatio = screenWidth / screenHeight;

    buttonHeight = screenHeight * 0.05;
    buttonWidth = screenWidth * 0.15;
    buttonXPos = (screenWidth - buttonWidth) / 2;

    loadTextures();

    sourceRecRight = {0.0f, 0.0f, (float)ponyTexture.width, (float)ponyTexture.height};
    sourceRecLeft = {0.0f, 0.0f, -(float)ponyTexture.width, (float)ponyTexture.height};

    ammunitionPosition = {(float)(screenWidth - bulletTexture.width), (float)(screenHeight - bulletTexture.width)};
    highscorePosition = {(float)(screenWidth * 0.85), (float)(screenHeight * 0.03)};
    timerPosition = {(float)(screenWidth * 0.85), (float)(screenHeight * 0.08)};
    textHeight = (int)screenHeight * 0.05;
}

GraphicsRendererRaylib::~GraphicsRendererRaylib()
{
    UnloadTexture(menu);
    UnloadTexture(endScreen);
    UnloadTexture(backgroundTexture);
    UnloadTexture(crosshairTexture);
    UnloadTexture(ponyTexture);
    UnloadTexture(bloodTexture);
    UnloadTexture(bulletTexture);
    CloseWindow();
}

void GraphicsRendererRaylib::loadTextures()
{
    /*
    loading a texture does not throw an error, only logs it.
    Playing without a pony texture would be pretty shit, so a bit of try and catch
    */

    // resize image to have a fitting texture size (could be done with DrawTexturePro)
    int bulletDimension = (int)screenHeight / 20;
    Image bulletImg = LoadImage("resources/img/bullet.png");
    if (bulletImg.data == NULL)
    {
        throw std::runtime_error("resources/img/bulllet.png could not be loaded!");
    }
    ImageResize(&bulletImg, bulletDimension, bulletDimension);
    bulletTexture = LoadTextureFromImage(bulletImg);

    int crosshairDimension = (int)screenHeight / 20;
    Image crosshairImage = LoadImage("resources/img/crosshair.png");
    if (crosshairImage.data == NULL)
    {
        throw std::runtime_error("resources/img/crosshair.png could not be loaded!");
    }
    ImageResize(&crosshairImage, crosshairDimension, crosshairDimension);
    crosshairTexture = LoadTextureFromImage(crosshairImage);

    Image menuImage = LoadImage("resources/img/Menu.png");
    if (menuImage.data == NULL)
    {
        throw std::runtime_error("resources/img/Menu.png could not be loaded!");
    }
    ImageResize(&menuImage, screenWidth, screenHeight);
    menu = LoadTextureFromImage(menuImage);

    Image endScreenImage = LoadImage("resources/img/endScreen.png");
    if (endScreenImage.data == NULL)
    {
        throw std::runtime_error("resources/img/endScreen.png could not be loaded!");
    }
    ImageResize(&endScreenImage, screenWidth, screenHeight);
    endScreen = LoadTextureFromImage(endScreenImage);

    Image backgroundImage = LoadImage("resources/img/background.png");
    if (backgroundImage.data == NULL)
    {
        throw std::runtime_error("resources/img/background.png could not be loaded!");
    }
    ImageResize(&backgroundImage, screenWidth, screenHeight);
    backgroundTexture = LoadTextureFromImage(backgroundImage);

    Image bloodImage = LoadImage("resources/img/blood.png");
    if (bloodImage.data == NULL)
    {
        throw std::runtime_error("resources/img/blood.png could not be loaded!");
    }
    ImageResize(&bloodImage, 30, 30);
    bloodTexture = LoadTextureFromImage(bloodImage);

    ponyTexture = LoadTexture("resources/img/pony.png");
    if (ponyTexture.id == 0) // would have to look into OpenGL library further
    {
        throw std::runtime_error("resources/img/pony.png could not be loaded!");
    }

    // RenderTexture to draw blood stains on
    backgroundRenderTexture = LoadRenderTexture(screenWidth, screenHeight);
    BeginTextureMode(backgroundRenderTexture);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    EndTextureMode();

    // load Gui with colors + font
    GuiLoadStyleLight();
    customFont = LoadFont("resources/fonts/DoubleHomicide.ttf");
    if (customFont.texture.id == 0)
    {
        throw std::runtime_error("resources/fonts/DoubleHommicide.ttf could not be loaded!");
    }
    GuiSetFont(customFont);
}

// draw background with the blood stains
void GraphicsRendererRaylib::drawBackground()
{
    ClearBackground(WHITE);
    DrawTexturePro(backgroundRenderTexture.texture, (Rectangle){0.0f, 0.0f, (float)backgroundRenderTexture.texture.width, (float)-backgroundRenderTexture.texture.height}, (Rectangle){0.0f, 0.0f, (float)screenWidth, (float)screenHeight}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
}

// reset blood stains
void GraphicsRendererRaylib::resetBackground()
{
    BeginTextureMode(backgroundRenderTexture);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    EndTextureMode();
}

void GraphicsRendererRaylib::drawAmmunition(int ammoLeft)
{
    for (int i = 0; i < ammoLeft; i++)
        DrawTexture(bulletTexture, ammunitionPosition.x - i * bulletTexture.width, ammunitionPosition.y, WHITE);
}

void GraphicsRendererRaylib::drawCrosshair(Vector2 *mousePosition)
{
    DrawTexture(crosshairTexture, mousePosition->x - crosshairTexture.width / 2, mousePosition->y - crosshairTexture.width / 2, WHITE);
}

// leider nicht ganz richtig Single Responsibility, da Input in GuiButton gehandlet wird und deshalb returned werden muss, welcher Button gedrückt wurde, aber leider lässt die library es nicht anders zu
// returns index of buttot that has been pressed or 0 for no input
int GraphicsRendererRaylib::showMenu()
{
    ClearBackground(WHITE);
    DrawTexture(menu, 0, 0, WHITE);
    if (GuiButton((Rectangle){buttonXPos, 300, buttonWidth, buttonHeight}, "Start"))
        return 1;
    if (GuiButton((Rectangle){buttonXPos, 350, buttonWidth, buttonHeight}, "Quit"))
        return 2;
    return 0;
}

void GraphicsRendererRaylib::drawHighscore(int highscore)
{
    DrawTextEx(customFont, TextFormat("HiScore: %05i", highscore), Vector2{highscorePosition.x, highscorePosition.y}, textHeight, 0, GOLD);
}

void GraphicsRendererRaylib::drawTimer(int timeLeft)
{
    DrawTextEx(customFont, TextFormat("Timer: %4i", timeLeft), Vector2{timerPosition.x, timerPosition.y}, textHeight, 0, RED);
}

void GraphicsRendererRaylib::drawPony(std::list<Pony> *ponyList)
{
    for (std::list<Pony>::iterator it = ponyList->begin(); it != ponyList->end(); it++)
    {
        Vector2 position = it->getPosition();
        PonyType type = it->getType();
        Vector2 origin = {(float)(ponySize.at(type) / 2), (float)(ponySize.at(type) / 2)};                // set origin to center of pony, depends on type of pony
        Rectangle destRec = {position.x, position.y, (float)ponySize.at(type), (float)ponySize.at(type)}; // set destination to position of pony and draw texture in size of pony

        if (it->getDirection() > 0) // flying to the right
        {
            DrawTexturePro(ponyTexture, sourceRecRight, destRec, origin, 0, WHITE); // DrawTexture (texture, which part of Texture, where to draw, offset, rotation, tint)
        }
        else
        {
            DrawTexturePro(ponyTexture, sourceRecLeft, destRec, origin, 0, WHITE);
        }
    }
}

// draw blood the the background, stain size depending on pony size/type
void GraphicsRendererRaylib::drawBlood(Pony *pony)
{
    Vector2 position = pony->getPosition();
    PonyType type = pony->getType();
    Vector2 origin = {(float)ponySize.at(type) / 2, (float)ponySize.at(type) / 2};
    Rectangle destRec = {position.x, position.y, (float)ponySize.at(type), (float)ponySize.at(type)};

    BeginTextureMode(backgroundRenderTexture);
    DrawTexturePro(bloodTexture, (Rectangle){0.0f, 0.0f, (float)bloodTexture.width, (float)bloodTexture.height}, destRec, origin, 0.0f, WHITE);
    EndTextureMode();
}

// returns index of buttot that has been pressed or 0 for no input
int GraphicsRendererRaylib::showPause()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, (Color){255, 255, 255, 100}); // transparend white overlay
    if (GuiButton((Rectangle){buttonXPos, 300, buttonWidth, buttonHeight}, "Resume"))
        return 1;
    if (GuiButton((Rectangle){buttonXPos, 350, buttonWidth, buttonHeight}, "Menu"))
        return 2;
    return 0;
}

// returns index of buttot that has been pressed or 0 for no input
int GraphicsRendererRaylib::showGameOver(int score)
{
    DrawTexture(endScreen, 0, 0, WHITE);
    DrawTextEx(customFont, TextFormat("Score: %05i", score), Vector2{(float)buttonXPos, 135}, textHeight + 10, 0, GOLD);
    if (GuiButton((Rectangle){buttonXPos, 300, buttonWidth, buttonHeight}, "Restart"))
        return 1;
    if (GuiButton((Rectangle){buttonXPos, 350, buttonWidth, buttonHeight}, "Menu"))
        return 2;
    return 0;
}
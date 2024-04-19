#include <raylib.h>

#include "InputHandlerRaylib.h"
#include "GraphicsRendererRaylib.h"
#include "AudioRendererRaylib.h"
#include "Game.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main()
{
    GraphicsRendererInterface *graphicsRenderer = new GraphicsRendererRaylib(SCREEN_WIDTH, SCREEN_HEIGHT, "Exobernd");
    AudioRendererInterface *audioRenderer = new AudioRendererRaylib();
    InputHandlerInterface *inputHandler = new InputHandlerRaylib();

    Game *game;

    enum GameState
    {
        MENU,
        GAME,
        PAUSE,
        GAMEOVER
    };

    GameState gameState = MENU;
    audioRenderer->playMenuMusic();
    int menuInput = 0;
    int pauseInput = 0;
    int gameOverInput = 0;

    while (!WindowShouldClose())
    {
        if (inputHandler->toggleFullscreen())
        {
            ToggleFullscreen();
        }
        switch (gameState)
        {
        case MENU:
            BeginDrawing();
            menuInput = graphicsRenderer->showMenu(); // draw Menu and save input
            EndDrawing();
            audioRenderer->updateMenuMusic();
            if (menuInput == 1) // "Play"
            {
                audioRenderer->playOptionSound();
                audioRenderer->stopMenuMusic();
                gameState = GAME;
                HideCursor();
                game = new Game(inputHandler, graphicsRenderer, audioRenderer);
                game->start();
            }
            else if (menuInput == 2) // "Quit"
            {
                CloseWindow();
                delete inputHandler;
                delete graphicsRenderer;
                delete audioRenderer;
                delete game;
                return 0;
            }
            break;

        case GAME:
            // get input
            inputHandler->handleInput(); // set state of inputHandler

            if (inputHandler->isShooting())
            {
                game->shoot();
            }
            else if (inputHandler->isReloading())
            {
                game->reload();
            }
            else if (inputHandler->isPaused())
            {
                audioRenderer->playOptionSound();
                game->pause();
                gameState = PAUSE;
                ShowCursor();
                break;
            }
            // update objects
            if (game->update()) // return true if game is over
            {
                gameState = GAMEOVER;
                game->end();
                ShowCursor();
                break;
            }

            // update music
            audioRenderer->updateGameMusic();
            // render image
            BeginDrawing();
            // could also put this code into game.draw function. Makes it reusable and dont need to call on the game.getXXX functions
            graphicsRenderer->drawBackground();
            graphicsRenderer->drawPony(game->getPonyList());
            graphicsRenderer->drawCrosshair(inputHandler->getMousePosition());
            graphicsRenderer->drawHighscore(game->getScore());
            graphicsRenderer->drawTimer(game->getTimeLeft());
            graphicsRenderer->drawAmmunition(game->getAmmunition());
            EndDrawing();
            break;

        case PAUSE:
            BeginDrawing();
            // could use RenderTexture. for increasing performance (would be rendered when pausing the game)
            graphicsRenderer->drawBackground();
            graphicsRenderer->drawPony(game->getPonyList());
            graphicsRenderer->drawCrosshair(inputHandler->getMousePosition());
            graphicsRenderer->drawHighscore(game->getScore());
            graphicsRenderer->drawTimer(game->getTimeLeft());
            graphicsRenderer->drawAmmunition(game->getAmmunition());
            pauseInput = graphicsRenderer->showPause();
            EndDrawing();

            if (pauseInput == 1) // "Resume"
            {
                audioRenderer->playOptionSound();
                game->resume();
                gameState = GAME;
                HideCursor();
            }
            else if (pauseInput == 2) // "Menu"
            {
                audioRenderer->playOptionSound();
                game->reset();
                audioRenderer->stopGameMusic();
                audioRenderer->playMenuMusic();
                gameState = MENU;
            }
            break;

        case GAMEOVER:
            BeginDrawing();
            gameOverInput = graphicsRenderer->showGameOver(game->getScore());
            EndDrawing();
            if (gameOverInput == 1) // "Restart"
            {
                audioRenderer->playOptionSound();
                HideCursor();
                gameState = GAME;
                game->reset();
                game->start();
            }
            else if (gameOverInput == 2) // "Menu"
            {
                audioRenderer->playOptionSound();
                game->reset();
                gameState = MENU;
                audioRenderer->playMenuMusic();
            }
            break;
        }
    }
    delete inputHandler;
    delete graphicsRenderer;
    delete audioRenderer;
    delete game;
    return 0;
}
# Exobernd
small c++ game made in raylib.

You play as Bernd das Brot and shoot flying My little ponies.
Moorhuhn remake

[Project template](https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2)

## Installation
This project uses a Makefile for building and installing. To install the project, follow these steps:
### 1 way
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Run the make command.
```bash
git clone <https://github.com/lenseB/Exobernd.git>
cd <Exobernd>
make
```
### 2 way
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Open the workspace
4. Press F5 (in VS Code) to Run(+ Debugging) the game
```bash
git clone <https://github.com/lenseB/Exobernd.git>
cd <Exobernd>
```

### 3 way
1. Clone the repository to your local machine.
2. Excute the Exobernd.exe (This will start the game)
```bash
git clone <https://github.com/lenseB/Exobernd.git>
```

## Game Controls
F11: Toggle Fullscreen  
Q: Quit  
Esc: Pause the game  
  
Everything else is controlled with the Mouse.

## Dependencies
This project depends on the following libraries:  
  
[raylib](https://www.raylib.com/): A simple and easy-to-use library that makes programming games enjoyable.  
[raygui](https://github.com/raysan5/raygui): Library for creating simple GUI interfaces using raylib graphic style. It is a single-file header-only library
Please ensure these dependencies are installed on your system before building and running the project. (raygui is part of the repository!)

## Graphics
Bernd das Brot - from r/place 2023  
Ponies - idk pls don't sue me 👉👈  
The rest is free to use.  
## Classes and Functions
GraphicsRendererRaylib: This class handles all the graphics rendering using the raylib library. It includes functions for loading and unloading textures, and for drawing the game objects on the screen.  

InputHandler: This class is responsible for handling user input. It captures the state of various inputs (like shooting or reloading) and provides an interface for other parts of the program to react to these inputs.  

AudioRenderer: This class is responsible for handling all audio-related tasks in the game. It can play, stop, and update sounds and music. It also provides an interface to play specific sounds when certain actions are performed in the game, like selecting an option in the menu.  

Game: This class represents the main game logic. It uses the InputHandler, GraphicsRenderer, and AudioRenderer to create a complete game.  

Timer: This class manages a timer and its state. It includes functions for starting, stopping, resuming, updating, and resetting the timer. It also provides functions to get the time left and check if the timer is running.  

PonyFactory: This class is a factory for creating Pony objects. It includes static methods for initializing a list of ponies and creating a single pony.  

Pony: This class represents a Pony in the game. It includes methods for updating the pony's position, checking if the pony has been hit, and retrieving the pony's position, direction, and type.  

Highscore: This class manages the game's highscore. It includes methods for adding points based on the type of pony, resetting the score, and retrieving the current score.
The class also contains private variables for the score and a map ponyPoints that maps PonyType to points.  

This class manages the ammunition of the player in the game. It includes methods for checking if the ammunition is empty or reloading, reloading the ammunition, shooting, updating the ammunition state, and getting the amount of ammunition left.  


Please refer to the source code for more details about the classes and functions.

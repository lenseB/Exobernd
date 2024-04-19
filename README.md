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
The rest wherre free to use.

## Classes and Functions
GraphicsRendererRaylib: This class handles all the graphics rendering using the raylib library. It includes functions for loading and unloading textures, and for drawing the game objects on the screen.

loadTextures(): This function is responsible for loading all the necessary textures from the disk. It throws a std::runtime_error if a texture cannot be loaded.

UnloadTexture(): This function unloads a texture from memory.

CloseWindow(): This function closes the game window.

Please refer to the source code for more details about the classes and functions.

License
This project is licensed under the MIT License - see the LICENSE.md file for details.

Acknowledgments
Thanks to raylib for their easy-to-use game programming library.

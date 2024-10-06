#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <stdbool.h>

// Forward declaration of ldtk_level structure
typedef struct ldtk_level ldtk_level;

// Initializes the engine with a window title and dimensions
bool engineInit(const char* title, int width, int height);

// Cleans up the engine resources
void engineCleanup();

// Renders the current level
void engineRender(ldtk_level* level);

// Handles user input and updates the running state
void handleInput(bool* running);

// Loads a level from a specified file
ldtk_level loadLevel(const char* filename);

// Gets the SDL renderer
SDL_Renderer* getRenderer();

#endif // ENGINE_H


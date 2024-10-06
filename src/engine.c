#include <SDL.h>
#include <stdio.h>
#include "engine.h"

// Include the LDtk loader directly as a .c file
#include "loader.c"  // Adjust the path if necessary

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

bool engineInit(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void engineCleanup() {
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (window != NULL) {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    SDL_Quit();
}

void engineRender(ldtk_level* level) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Example rendering code for level tiles
    for (int i = 0; i < level->tiles_count; i++) {
        SDL_Rect rect;
        rect.x = level->tiles[i].x; // Assuming your tile structure has x and y
        rect.y = level->tiles[i].y;
        rect.w = level->tiles[i].width;  // Set the appropriate width
        rect.h = level->tiles[i].height; // Set the appropriate height

        SDL_SetRenderDrawColor(renderer, level->tiles[i].color.r, level->tiles[i].color.g, level->tiles[i].color.b, 255); // Assuming your tile has a color property
        SDL_RenderFillRect(renderer, &rect);
    }

    // Update the screen
    SDL_RenderPresent(renderer);
}

void handleInput(bool* running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:  // Escape key
                    *running = false;
                    break;
                // Add more keys as needed
            }
        }
    }
}

ldtk_level loadLevel(const char* filename) {
    ldtk_level level;
    // Assuming your loader has a function to initialize the level
    level = load_ldtk_level(filename); // Load the level directly from the loader
    if (level == NULL) {
        printf("Failed to load level from %s\n", filename);
        // Handle error appropriately, you may want to return an empty or default level
    }
    return level;
}


#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "engine.h"
#include "level.h" // Inclure level.h pour utiliser la structure Level

SDL_Window* window;
SDL_Renderer* renderer;

void engineInit() {
    // ... (le même code d'initialisation)
}

void engineLoadLevel(const char* levelPath, Level* level) {
    loadLevel(levelPath, level); // Utiliser loadLevel pour charger le niveau
}

void engineRun() {
    Level level;
    engineLoadLevel("./level1.txt", &level);

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanc
        SDL_RenderClear(renderer);
        
        engineRenderLevel(&level); // Rendre le niveau
        
        SDL_RenderPresent(renderer);
    }

    freeLevel(&level); // Libérer la mémoire
}

void engineCleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


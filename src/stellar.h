#ifndef STELLAR_H
#define STELLAR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

// Prototypes des fonctions
void stellarInit(S);
void stellarMusic(const char* filename);
void stellarCleanup();

#endif

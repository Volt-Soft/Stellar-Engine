// src/engine.h
#ifndef ENGINE_H
#define ENGINE_H

#include "level.h" // Inclure level.h pour utiliser la structure Level

void engineInit();
void engineLoadLevel(const char* levelPath, Level* level); // Déclaration correcte
void engineRenderLevel(Level* level); // Déclaration correcte
void engineRun();
void engineCleanup();
int engineGetKeyState(int key);

#endif // ENGINE_H


// src/level.h
#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
    int width;
    int height;
    int* tiles;  // Tableau des tuiles
} Level;

// Prototypes des fonctions
void loadLevel(const char* path, Level* level);
void freeLevel(Level* level); // Libérer la mémoire d'un niveau
void engineRenderLevel(Level* level); // Déclaration de la fonction pour le rendu du niveau

#endif // LEVEL_H


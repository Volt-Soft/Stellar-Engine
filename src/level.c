#include <stdio.h>
#include <stdlib.h>
#include "level.h"

// Fonction pour charger un niveau depuis un fichier
void loadLevel(const char* path, Level* level) {
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Erreur d'ouverture du fichier de niveau: %s\n", path);
        return;
    }

    // Lire la largeur et la hauteur du niveau
    fscanf(file, "%d %d", &level->width, &level->height);
    level->tiles = (int*)malloc(level->width * level->height * sizeof(int));
    
    // Lire les tuiles du niveau
    for (int i = 0; i < level->width * level->height; ++i) {
        fscanf(file, "%d", &level->tiles[i]);
    }

    fclose(file);
}

// Fonction pour libérer la mémoire allouée pour un niveau
void freeLevel(Level* level) {
    free(level->tiles);
    level->tiles = NULL; // Éviter les pointeurs pendants
}

// Fonction pour rendre le niveau
void engineRenderLevel(Level* level) {
    // Code de rendu des tuiles
    for (int y = 0; y < level->height; ++y) {
        for (int x = 0; x < level->width; ++x) {
            int tile = level->tiles[y * level->width + x];
            // Rendre chaque tuile ici (par exemple, utiliser SDL pour dessiner)
        }
    }
}


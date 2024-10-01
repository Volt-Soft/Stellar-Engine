#include "engine.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float x, y, z;  // Coordonnées des sommets
} Vertex;

typedef struct {
    Vertex* vertices;  // Tableau des sommets
    unsigned int* indices;  // Tableau des indices des faces
    size_t vertexCount;  // Nombre de sommets
    size_t indexCount;  // Nombre d'indices
} Model;

SDL_Window* window;
SDL_GLContext glContext;
Model model;  // Le modèle 3D courant

void engineInit() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    window = SDL_CreateWindow("Stellar Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    glContext = SDL_GL_CreateContext(window);
    glEnable(GL_DEPTH_TEST);  // Activer le test de profondeur pour un rendu 3D correct
}

void engineLoadModel(const char* modelPath) {
    FILE* file = fopen(modelPath, "r");
    if (!file) {
        printf("Impossible de charger le fichier %s\n", modelPath);
        return;
    }

    // Initialiser les structures pour stocker les sommets et indices
    model.vertices = NULL;  
    model.indices = NULL;  
    model.vertexCount = 0;
    model.indexCount = 0;

    char line[128];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "v ", 2) == 0) {  // Ligne contenant un sommet
            model.vertices = realloc(model.vertices, sizeof(Vertex) * (model.vertexCount + 1));
            if (!model.vertices) {
                printf("Erreur d'allocation mémoire\n");
                fclose(file);
                return;
            }
            Vertex vertex;
            if (sscanf(line, "v %f %f %f", &vertex.x, &vertex.y, &vertex.z) != 3) {
                printf("Erreur de format dans le fichier de sommet: %s\n", line);
                fclose(file);
                return;
            }
            model.vertices[model.vertexCount++] = vertex;
        } else if (strncmp(line, "f ", 2) == 0) {  // Ligne contenant une face
            unsigned int vertexIndex[3];
            if (sscanf(line, "f %d %d %d", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]) != 3) {
                printf("Erreur de format dans le fichier de face: %s\n", line);
                fclose(file);
                return;
            }
            model.indices = realloc(model.indices, sizeof(unsigned int) * (model.indexCount + 3));
            if (!model.indices) {
                printf("Erreur d'allocation mémoire\n");
                fclose(file);
                return;
            }
            model.indices[model.indexCount++] = vertexIndex[0] - 1;  // Les indices commencent à 1 dans les fichiers OBJ
            model.indices[model.indexCount++] = vertexIndex[1] - 1;
            model.indices[model.indexCount++] = vertexIndex[2] - 1;
        }
    }

    fclose(file);
    printf("Modèle %s chargé avec %zu sommets et %zu faces\n", modelPath, model.vertexCount, model.indexCount / 3);
}

void engineRenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Effacer l'écran et le buffer de profondeur

    if (model.vertexCount > 0 && model.indexCount > 0) {
        glBegin(GL_TRIANGLES);
        for (size_t i = 0; i < model.indexCount; i++) {
            if (model.indices[i] < model.vertexCount) {  // Vérifie si l'indice est valide
                Vertex vertex = model.vertices[model.indices[i]];
                glVertex3f(vertex.x, vertex.y, vertex.z);
            } else {
                printf("Indice %d est hors limites!\n", model.indices[i]);
            }
        }
        glEnd();
    } else {
        printf("Aucun modèle à rendre.\n");
    }

    SDL_GL_SwapWindow(window);  // Afficher à l'écran
}

void engineProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            // Gérer la fermeture de la fenêtre
            SDL_Quit();
            exit(0);
        }
        // Gérer les autres événements clavier/souris
    }
}

void engineCleanup() {
    free(model.vertices);  // Libérer la mémoire des sommets
    free(model.indices);   // Libérer la mémoire des indices
}

int engineGetKeyState(int key) {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    return keystate[key];
}

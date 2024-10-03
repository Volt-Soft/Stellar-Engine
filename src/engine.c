#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>    // Inclure la bibliothèque SDL
#include <GL/gl.h>  // Inclure OpenGL
#include "engine.h"

SDL_Window* window;
SDL_GLContext glContext;

// Fonction d'initialisation
void engineInit() {
    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // Créer une fenêtre avec un contexte OpenGL
    window = SDL_CreateWindow("Stellar Engine",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                800, 600,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur de création de la fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    // Créer le contexte OpenGL
    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        printf("Erreur de création du contexte OpenGL: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // Initialiser les paramètres d'OpenGL
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Couleur de fond (noir)
}

// Fonction pour charger un modèle 3D
void engineLoadModel(const char* modelPath, Model* model) {
    // TODO : Implémenter engineLoadModel
}

// Fonction pour rendre la scène avec le modèle
void engineRenderScene(Model* model) {
    // TODO : Implémenter engineRenderScene
}

// Fonction pour traiter les inputs (clavier/souris)
void engineProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            engineCleanup();
            exit(0);
        }
    }
}

// Fonction pour libérer la mémoire
void engineCleanup() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Fonction pour récupérer l'état d'une touche
int engineGetKeyState(int key) {
    const Uint8* state = SDL_GetKeyboardState(NULL);
    return state[key];
}


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
    // TODO : Implémenter
}

// Fonction pour rendre la scène avec le modèle
void engineRenderScene(Model* model) {
    // Effacer le tampon de couleur et le tampon de profondeur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Rendre le modèle
    glBegin(GL_QUADS);
    // Face avant
    glColor3f(1.0f, 0.0f, 0.0f);  // Rouge
    for (int i = 0; i < 4; i++) {
        glVertex3fv(model->vertices[i]);  // Utiliser les sommets du modèle
    }
    glEnd();

    // Vous pouvez ajouter d'autres faces ici

    // Échanger les tampons pour afficher la scène
    SDL_GL_SwapWindow(window);
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
    printf("Nettoyage du moteur.\n");
}

// Fonction pour récupérer l'état d'une touche
int engineGetKeyState(int key) {
    const Uint8* state = SDL_GetKeyboardState(NULL);
    return state[key];
}


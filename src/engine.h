#ifndef ENGINE_H
#define ENGINE_H

typedef struct {
    float vertices[8][3];  // Coordonnées des sommets (8 sommets pour un cube par exemple)
} Model;

void engineInit();  // Initialiser le moteur et la fenêtre
void engineLoadModel(const char* modelPath, Model* model);  // Charger un modèle 3D
void engineRenderScene(Model* model);  // Rendre la scène avec le modèle
void engineProcessInput();  // Traiter les inputs (clavier/souris)
void engineCleanup();  // Libérer la mémoire
int engineGetKeyState(int key);  // Récupérer l'état d'une touche

#endif


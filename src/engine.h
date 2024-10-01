#ifndef ENGINE_H
#define ENGINE_H

void engineInit();  // Initialiser le moteur et la fenêtre
void engineLoadModel(const char* modelPath);  // Charger un modèle 3D
void engineRenderScene();  // Rendre la scène
void engineProcessInput();  // Traiter les inputs (clavier/souris)
void engineCleanup();  // Libérer la mémoire
int engineGetKeyState(int key);  // Récupérer l'état d'une touche

#endif


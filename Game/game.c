#include "../src/engine.h"

int main() {
    engineInit();  // Initialiser le moteur

    engineLoadModel("test.obj");  // Charger un modèle de carte

    while (1) {
        engineProcessInput();  // Gérer les inputs
        engineRenderScene();  // Rendre la scène
    }

    engineCleanup();  // Libérer la mémoire avant de quitter

    return 0;
}


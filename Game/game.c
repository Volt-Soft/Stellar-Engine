#include <stdio.h>
#include "../src/engine.h"

int main(int argc, char* argv[]) {
    Model model;  // Créer une instance du modèle

    engineInit();
    engineLoadModel("./test.obj", &model);  // Charger le modèle

    // Boucle principale
    while (1) {
        engineProcessInput();
        engineRenderScene(&model);  // Rendre la scène avec le modèle
    }

    engineCleanup();
    return 0;
}


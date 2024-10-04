// game/game.c
#include "../src/engine.h"

int main(int argc, char* argv[]) {
    engineInit(); // Initialiser le moteur
    engineRun();  // Exécuter le moteur
    engineCleanup(); // Nettoyer avant de quitter
    return 0;
}


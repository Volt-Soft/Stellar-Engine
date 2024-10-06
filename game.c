#include "./src/engine.h"

int main(int argc, char* argv[]) {
    if (!engineInit("Stellar Engine", 800, 600)) {
        return -1;
    }

    bool running = true;
    ldtk_level level = loadLevel("level1.ldtk");

    while (running) {
        handleInput(&running);
        engineRender(&level);
    }

    engineCleanup();
    return 0;
}


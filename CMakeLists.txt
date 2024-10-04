cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(StellarEngine)

# Trouver SDL2
find_package(SDL2 REQUIRED)

# Définir le répertoire de build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Inclure les fichiers sources
set(SOURCES
    src/engine.c
    src/level.c
    game/game.c
)

# Créer l'exécutable
add_executable(stellar_engine ${SOURCES})

# Lier SDL2
target_include_directories(stellar_engine PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(stellar_engine PRIVATE ${SDL2_LIBRARIES})


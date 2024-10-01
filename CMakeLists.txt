cmake_minimum_required(VERSION 3.10)

# Nom du projet global
project(StellarEngineProject)

# Cible le standard C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Spécifie les chemins des dossiers pour les sources du moteur et du jeu
set(ENGINE_DIR ${CMAKE_SOURCE_DIR}/src)
set(GAME_DIR ${CMAKE_SOURCE_DIR}/Game)

# Ajoute les fichiers sources pour le moteur
add_library(stellarengine STATIC
    ${ENGINE_DIR}/engine.c
)

# Trouve SDL2 et OpenGL
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# Ajoute les chemins d'inclusion et lie les bibliothèques
target_include_directories(stellarengine PRIVATE ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})
target_link_libraries(stellarengine ${SDL2_LIBRARIES} ${OPENGL_gl_LIBRARY})

# Ajoute l'exécutable pour le jeu
add_executable(game
    ${GAME_DIR}/game.c
)

# Lie l'exécutable du jeu à la bibliothèque du moteur
target_link_libraries(game stellarengine)


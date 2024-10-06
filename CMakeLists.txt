cmake_minimum_required(VERSION 3.10)

# Set the project name
project(StellarEngine)

# Find the SDL2 library
find_package(SDL2 REQUIRED)

# Set the source files for the engine and game
set(ENGINE_SOURCES
    src/engine.c
    src/loader.c
)

set(GAME_SOURCES
    game.c
)

# Create the executable
add_executable(StellarEngine ${ENGINE_SOURCES} ${GAME_SOURCES})

# Link SDL2 to the executable
target_include_directories(StellarEngine PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(StellarEngine PRIVATE ${SDL2_LIBRARIES})

# Set C11 standard
set_property(TARGET StellarEngine PROPERTY C_STANDARD 11)


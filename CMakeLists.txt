cmake_minimum_required(VERSION 3.29)
project(StellarGame C)

set(CMAKE_C_STANDARD 23)

# SDL
include_directories(C:/SDL2/include)

# Engine Library
add_library(StellarEngine STATIC src/stellar.c
        src/stellar.h)

# Final Game
add_executable(StellarGame game.c)

# Stellar Documentation
add_custom_target(StellarDoc doc.tex)
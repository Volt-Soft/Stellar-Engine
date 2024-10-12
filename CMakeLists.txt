cmake_minimum_required(VERSION 3.29)
project(StellarGame C)

set(CMAKE_C_STANDARD 23)

# Engine Library
add_library(StellarEngine STATIC src/stellar.c
        src/stellar.h)

# Final Game
add_executable(StellarGame game.c)
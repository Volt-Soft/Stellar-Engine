cmake_minimum_required(VERSION 3.28)

project(sdl_example C)

# C Standard
set(CMAKE_C_STANDARD 23)

# Define the executable
add_executable(sdl_example "src/sdl.c")

# Find and link the TMX library
find_package(tmx REQUIRED)
target_link_libraries(sdl_example PRIVATE tmx)

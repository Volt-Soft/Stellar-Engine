cmake_minimum_required(VERSION 3.28)

project(StellarEngine C)

# Set C standard to C23
set(CMAKE_C_STANDARD 23)

# Define the executable
add_executable(StellarEngine "src/loader.c")

# Find and link the TMX library
find_package(tmx REQUIRED)
target_link_libraries(StellarEngine PRIVATE tmx)

# Handle different toolchains and dependencies
if(MSVC AND NOT VCPKG_TOOLCHAIN)
  message(FATAL_ERROR "MSVC is only supported when using vcpkg")
endif()

if(VCPKG_TOOLCHAIN)
  # Use vcpkg to find and link SDL2_image
  find_package(sdl2-image REQUIRED)
  target_link_libraries(StellarEngine PRIVATE sdl2-image)
else()
  # Use PkgConfig to find and link SDL2_image and SDL2
  find_package(PkgConfig REQUIRED)
  pkg_search_module(SDL2_IMAGE REQUIRED IMPORTED_TARGET SDL2_image) # Transitively includes SDL2
  target_link_libraries(StellarEngine PRIVATE PkgConfig::SDL2_IMAGE)
endif()

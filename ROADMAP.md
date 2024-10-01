# Stellar Engine Roadmap

This document outlines the development plan for **Stellar Engine**, a simple 3D rendering engine focused on rendering 3D models and managing keyboard/mouse inputs. The gameplay logic, such as collisions and movement, will be handled by the game.

## Phase 1: Initial Configuration and Project Setup
1. **Create the basic project structure**:
   - Create a folder for the project.
   - Inside this folder, create a subfolder `StellarEngine` for the engine and another folder `Game` for the game.
   - Files to create:
     - `StellarEngine/engine.h`
     - `StellarEngine/engine.c`
     - `Game/game.c`

2. **Configure the development tools**:
   - Install SDL2, OpenGL (or GLUT), and a C compiler (GCC).
   - Test a simple SDL project to ensure everything is set up correctly.

3. **Create a Makefile (or equivalent)** to manage the compilation.

## Phase 2: Engine Development
### Step 1: Engine Initialization
- Create `engineInit()` to initialize the SDL window and OpenGL context.
- Checklist:
  - [ ] SDL window opens correctly.
  - [ ] OpenGL context is initialized.
  - [ ] `engineRenderScene()` added for basic rendering tests (like changing the background color).

### Step 2: 3D Rendering Management
- Implement basic OpenGL rendering.
- Checklist:
  - [ ] `engineLoadModel()` to load simple 3D models (like `.obj` files).
  - [ ] `engineRenderScene()` renders the models each frame.
  - [ ] Model displays correctly on screen.

### Step 3: Input Management
- Add keyboard and mouse input handling with SDL in `engineProcessInput()`.
- Checklist:
  - [ ] Capture key states with `engineGetKeyState()`.
  - [ ] Implement a basic camera using WASD for movement.

## Phase 3: Integration with the Game
### Step 4: Engine-Game Integration
- Create a program in `game.c` that includes `engine.h`.
- Checklist:
  - [ ] Call `engineInit()` to initialize the engine.
  - [ ] Use `engineLoadModel()` to load the 3D map.
  - [ ] Capture inputs with `engineProcessInput()` and apply them in-game.

### Step 5: Test the Game Loop
- Ensure the game can call functions from the engine and the 3D model is correctly rendered.
- Checklist:
  - [ ] Movements are handled with inputs from the engine.

## Phase 4: Improvements and Finalization
### Step 6: Rendering and Camera Improvements
- Improve OpenGL rendering (e.g., perspective, camera movement).
- Checklist:
  - [ ] Add zoom and rotation to the camera.
  - [ ] Optimize rendering for complex 3D maps.

### Step 7: Resource Management
- Add a resource manager for loading multiple 3D models.
- Checklist:
  - [ ] Ensure multiple objects can be rendered in the scene.

### Step 8: Enhanced Input Management
- Improve input handling to include mouse events.
- Checklist:
  - [ ] Mouse controls for camera movement.

## Phase 5: Adding Extra Features (Optional)
- Checklist:
  - [ ] Add sound management (music and sound effects).
  - [ ] Improve rendering by adding lighting, shadows, or other effects.
  - [ ] Implement basic physics for collisions if needed.

---

## Global Checklist for Each Phase:
- [ ] **Phase 1**: Initial configuration.
- [ ] **Phase 2**: Basic engine initialization and rendering.
- [ ] **Phase 3**: Integration of the engine with the game.
- [ ] **Phase 4**: Rendering and input management improvements.
- [ ] **Phase 5**: Adding extra features.

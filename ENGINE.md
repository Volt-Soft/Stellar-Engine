
# Stellar Engine

Le jeu aura son propre moteur de jeu, le Stellar Engine. 

## Technologie

Le moteur utilisera [SDL](https://libsdl.com).

## Render, load 

## Étapes
- [ ] Getstion des I/O
- [ ] Chargements d'objets 2D
- [ ] Rendu des objets 2D
- [ ] Collisions
- [ ] Gestion et affichage des niveaux

### Détails des étapes

#### Chargement

Pour charger des niveaux, l'utilisateur apellera `engineLoadLevel`.

#### Rendu

Pour rendre la scène 3D, l'utlisateur apellera `engineRenderLevel`.

#### Inputs

Pour gérer les entrées et sorties, le moteur utilisera SDL.

## Fonctionnement et structure

Le moteur sera dans un dossier séparé, qui aura `engine.h`, `engine.c`, et qui seront inclus dans le fichier principal du jeu.

### Fonctions

- void engineInit();
- void engineRun();
- void engineCleanup();
- void engineLoadLevel(const char* levelPath, Level* level);
- void engineRenderLevel(Level* level);



# Stellar Engine

Un moteur de jeu pour Super Stars Align.

## Technologie

Le moteur utilisera [SDL](https://libsdl.com) et [LDtk](https://ldtk.io).

## Étapes
- [ ] Getstion des I/O
- [ ] Collisions
- [ ] Niveaux

## Chargement

Pour charger des niveaux, l'utilisateur apellera `engineLoadLevel`.

## Rendu

Pour rendre le niveau, l'utlisateur apellera `engineRenderLevel`.

## Inputs

Pour gérer les entrées et sorties, le moteur utilisera SDL.

## Fonctionnement et structure

Le moteur sera dans un dossier séparé, qui aura `engine.h`, `engine.c`, et qui seront inclus dans le fichier principal du jeu.

### Fonctions

- void engineInit();
- void engineRun();
- void engineCleanup();
- void engineLoadLevel(const char* levelPath, Level* level);
- void engineRenderLevel(Level* level);

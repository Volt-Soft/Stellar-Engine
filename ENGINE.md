
# Stellar Engine

Un moteur de jeu pour Super Stars Align.

## Technologie

Le moteur utilisera [SDL](https://libsdl.com) et [LDtk](https://ldtk.io).

## Étapes

- [ ] Getstion des I/O
- [ ] Niveaux
- [ ] API
- [ ] Musique

## Niveaux

Pour jouer le niveau, le moteur utilisera `cLDTK`.

## Inputs

Pour gérer les entrées et sorties, le moteur utilisera SDL.

## Structure

Le moteur sera composé d'`engine.c/h` et de `cLDTK`.
Il sera inclus par le développeur tiers et utilisera l'API du moteur.

### Fonctions

- void engineInit();
- void engineRun("level");
- void engineCleanup();

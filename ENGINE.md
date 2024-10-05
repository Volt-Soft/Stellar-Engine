
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

Pour charger les niveaux, le moteur utilisera `tmx`, un importer de maps Tiled.

## Structure

Le moteur sera composé d'`engine.c/h`.
Il sera inclus par le développeur tiers et utilisera l'API du moteur.

### API

- void engineInit();
- void engineRun("level");
- void engineClean();
- void engineMusic("path");
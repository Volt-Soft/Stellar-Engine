
# Stellar Engine

Un moteur de jeu pour Super Stars Align.

## Technologie

Le moteur utilisera [SDL](https://libsdl.com) en tant que technologie graphique.
[Tiled](https://www.mapeditor.org/) et [LDtk](https://ldtk.io) seront les éditeurs de niveaux pour le moteur.

## Étapes

- [ ] Getstion des I/O
- [ ] API
- [ ] Musique
- [x] Niveaux : Finalisation

## Structure

Le moteur sera composé de `stellar.c/h`.
Il sera inclus par le développeur tiers et utilisera l'API du moteur.

### API

- void stellarInit();
- void stellarClean();
- void stellarMusic("file.mp3");
- void stellarLevel("level.tmx");


# Stellar Engine

Un moteur de jeu pour Super Stars Align.

## Technologie

Le moteur utilisera [SDL](https://libsdl.com) en tant que technologie graphique.

## Étapes

- [ ] Getstion des I/O
- [ ] API
- [ ] Musique

## Structure

Le framework sera composé d'`stellar.c/h`.
Il sera inclus par le développeur tiers et utilisera l'API du moteur.

### API

- void stellarInit();
- void stellarClean();
- void stellarMusic("path");

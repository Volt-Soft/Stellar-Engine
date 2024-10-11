
# Stellar Engine

Un moteur de jeu pour Super Stars Align.

## Technologie

Le moteur utilisera [SDL](https://libsdl.com) en tant que technologie graphique.
[Tiled](https://www.mapeditor.org/) et [LDtk](https://ldtk.io) seront les éditeurs de niveaux pour le moteur.

## Étapes

- [ ] I/O
- [ ] TOML Config
- [ ] API
- [ ] Musique
- [x] Niveaux

## Configuration

Pseudocode :
```toml
[window]
width = 800
height = 600
fullscreen = false
title = "Stellar Game"

```
## Structure

Le moteur sera composé de `stellar.c/h` ainsi que `game.c`, qui comporte le loader et la logique du jeu.
Il sera inclus par le développeur tiers et utilisera l'API du moteur.

### API

- [ ] `void stellarCleanup()`
- [ ] `void stellarMusic("file.mp3")`
- [ ] `void stellarConfig("config.toml")`
- [ ] `stellarPlayer("player.png")`

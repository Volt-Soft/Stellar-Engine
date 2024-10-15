
# Stellar Engine

Un moteur de jeu pour Super Stars Align.

## Technologie

Le moteur utilisera [Haxe](https://haxe.org) et [OpenFL](https://openfl.org/).
Le moteur chargera des niveaux [LDtk](https://ldtk.io).

## Étapes

- [ ] I/O
- [ ] TOML Config
- [ ] Musique
- [ ] Niveaux
- [ ] Apprendre Haxe

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

Le moteur sera une librairie à inclure dans `game.hx`. Il sera dans le répertoire `stellar`.

### API

- [ ] `stellarConfig("config.toml")`
- [ ] `stellarPlayer("player.png")`
- [ ] `stellarMusic("file.mp3")`

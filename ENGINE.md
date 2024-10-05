
# Stellar Engine

Un moteur de jeu pour Super Stars Align.

## Technologie

Le moteur utilisera [Haxe](https://haxe.org) et [LDtk](https://ldtk.io).

## Étapes

- [ ] Getstion des I/O
- [ ] Niveaux
- [ ] API
- [ ] Musique

## Niveaux

Pour jouer le niveau, le moteur utilisera le loader officiel pour Haxe.

## Structure

Le moteur sera composé d'`engine.haxe`.
Il sera inclus par le développeur tiers et utilisera l'API du moteur.

### Fonctions

- void engineInit();
- void engineRun("level");
- void engineCleanup();

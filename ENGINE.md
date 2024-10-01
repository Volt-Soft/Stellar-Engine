# Stellar Engine

Le jeu aura son propre moteur de jeu, le Stellar Engine. 

## Technologie

![OpenGL](https://img.shields.io/badge/OpenGL-FFFFFF?style=for-the-badge&logo=OpenGL)

Le moteur utilisera SDL pour le cœur et OpenGL pour le rendering.

## Render, load et collisions

Le moteur sera centré sur le load et rendu de modèles 3D, pour faciliter son développement.

Mais, il aura un système de collisions avec soit :

- Des sphères autour des blocs
- AABB

Le moteur chargera des objets 3D provenant de logiciels de Modélisation comme [Blender](https://fr.m.wikipedia.org/wiki/Blender), qui seront la carte du jeu, ainsi que le modèle du joueur.


## Étapes

1. Loader d'objets 3D
2. Rendu avec OpenGL (et Glut)
3. Gestions des entrées (Input) 

### Détails des étapes

#### Load

Pour charger des fichiers 3D, le moteur aura une UI, avec un bouton pour charger le fichier via l'explorateur.

#### Rendu

Le jeu utilisera comme mentionné ci-dessus OpenGL et [GLut](https://en.m.wikipedia.org/wiki/OpenGL_Utility_Toolkit) pour faire le rendu, qui sera affiché au milieu de l'UI.

#### Inputs

Le moteur utilisera SDL pour gérer les entrées.

## Notes

Le moteur sera dans un dossier séparé, qui aura `engine.h`, `engine.c`, et qui seront inclus dans le fichier principal du jeu.

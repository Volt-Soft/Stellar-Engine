# Stellar Engine

Le jeu aura son propre moteur de jeu, le Stellar Engine. 

## Technologie

Le moteur utilisera SDL pour le cœur et OpenGL pour le rendering.

## Render, load et collisions

Le moteur sera centré sur le load et rendu de modèles 3D, pour faciliter son développement.

Mais, il aura un système de collisions avec soit :

- Des sphères autour des blocs
- AABB

Le moteur chargera des objets 3D provenant de logiciels de Modélisation comme [Blender](https://fr.m.wikipedia.org/wiki/Blender), qui seront la carte du jeu, ainsi que le modèle du joueur.
# Stellar Engine

Le jeu aura son propre moteur de jeu, le Stellar Engine. 

## Technologie

Le moteur utilisera SDL pour le cœur et OpenGL pour le rendering.

## Physique

Le Moteur gèrera les aspects suivants :

- Saut
- Double Saut
- Saut sur les murs
- Plongeon
- Accroupissement
- Plateformes
- Collision

## Render, load et collisions

Le moteur sera centré sur le load et rendu de modèles 3D, pour faciliter son développement.

Mais, il aura un système de collisions avec soit :

- Des sphères autour des blocs
- AABB

Le moteur chargera des fichiers 3D `.obj` ou `.fbx`.
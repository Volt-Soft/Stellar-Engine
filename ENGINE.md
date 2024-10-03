
# Stellar Engine

Le jeu aura son propre moteur de jeu, le Stellar Engine. 

## Technologie

Le moteur utilisera [SDL](https://libsdl.com), [OpenGL](https://opengl.org/) and [GLut](https://www.opengl.org/resources/libraries/glut/glut_downloads.php).

## Render, load 

Le moteur sera centré sur le chargement et rendu de modèles 3D, pour faciliter son développement.
Le moteur chargera des objets 3D provenant de logiciels de modélisation comme [Blender](https://fr.m.wikipedia.org/wiki/Blender), pouvant être la carte du jeu, par exemple.

## Étapes
- [ ] Getstion des I/O
- [ ] Chargements d'objets 3D
- [ ] Rendu des objets 3D
      
### Détails des étapes

#### Chargement

Pour charger des fichiers 3D, l'utilisateur apellera `engineLoadModel`.

#### Rendu

Pour rendre la scène 3D, l'utlisateur apellera `engineRenderScene`.

#### Inputs

Pour gérer les entrées et sorties, le moteur utilisera SDL.

## Fonctionnement et structure

Le moteur sera dans un dossier séparé, qui aura `engine.h`, `engine.c`, et qui seront inclus dans le fichier principal du jeu.

### Fonctions

- engineInit
- engineLoadModel
- engineRenderScene
- engineSetCameraPosition
- engineProcessInput
- engineGetKeyState
- engineClean

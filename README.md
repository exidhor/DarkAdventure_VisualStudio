# DarkAdventure_VisualStudio

Projet de Moteur graphique 2D en C++, en utilisant le pattern Component, gérant notamment les animations. Le moteur se base sur le noyau de la SFML pour gérer l'OpenGL. Au final, l'utilisation de la SFML se limite aux appels à l'OpenGL.
L'objectif de ce moteur est l'optimisation, c'est pourquoi on groupe les éléments en Layers, que l'on peut ordonner. Ainsi, on limite le nombre d'appels à la carte graphique.

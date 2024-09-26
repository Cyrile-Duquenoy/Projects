Le but de ce projet est de réaliser en python et à l’aide de pyGtk, un jeu (ou
plutôt un simulateur) d’épidémie de zombies.

Dans ce jeu, à chaque début de partie, chaque joueur est placé sur une case
libre d’une grille. Certains des joueurs sont désignés comme un humain et doivent
échapper aux autres joueurs qui sont désignés comme zombies. À chaque tour de
jeu, un par un, les joueurs peuvent décider de se déplacer d’une case vers le haut,
le bas, la gauche ou la droite ou de rester sur place. Certaines cases sont occupées
par des murs et les joueurs ne peuvent pas s’y déplacer. De plus, deux joueurs
ne peuvent pas être à la même position (sur la même case). Quand un zombie
rattrape un humain (qu’il est sur la case adjacente d’un joueur et qu’il essaye de
se déplacer dans sa direction), l’humain se transforme en zombie. Chaque joueur
est omniscient et peut voir l’intégralité de la carte (les cases libres ou occupées),
des autres joueurs et de leurs états (zombies ou non). Les joueurs humains
gagnent des points à chaque tour où ils restent humains. Les zombies perdent
des points à chaque tour de jeu et gagnent des points quand ils contaminent un
humain. La partie s’arrête quand tous les joueurs se transforment en zombi ou
qu’un certain nombre de tours se sont écoulés et le but du jeu et de maximiser
le nombre de points gagnés.

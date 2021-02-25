#include<time.h>
#include"commandepilep2d.h"
#define N 100

//@ requires nothing 
//@ assigns un tableau d'entiers et trois entier
//@ ensures retourne une valeur entière aléatoire entre 0 et 7
int aleatoire();

//@ requires un entier hauteur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en la déplaçant d'un cran vers le haut ou en la replaçant tout en bas si elle était initialement au plus haut point, ne modifie que la variable x de la position
void deplacement_haut(int hauteur,coord* position);

//@ requires un entier hauteur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en la déplaçant d'un cran vers le bas ou en la replaçant tout en haut si elle était initialement au plus bas point, ne modifie que la variable x de la position
void deplacement_bas(int hauteur, coord* position);

//@ requires un entier hauteur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en la déplaçant d'un cran vers la gauche ou en la replaçant tout à droite si elle était initialement à l'extremum gauche, ne modifie que la variable y de la position
void deplacement_gauche(int largeur, coord* position);
 
//@ requires un entier hauteur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en la déplaçant d'un cran vers la droite ou en la replaçant tout à gauche si elle était initialement à l'extremum droit, ne modifie que la variable y de la position
void deplacement_droit(int largeur, coord* position);

//@ requires deux entiers hauteur et largeur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en appelant deplacement_haut et deplacement_gauche, modifie les deux variable de la position
void deplacement_diagonal_haut_gauche(int largeur, int hauteur, coord* position);

//@ requires deux entiers hauteur et largeur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en appelant deplacement_haut et deplacement_droit, modifie les deux variable de la position
void deplacement_diagonal_haut_droit(int largeur, int hauteur, coord* position);

//@ requires deux entiers hauteur et largeur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en appelant deplacement_bas et deplacement_gauche, modifie les deux variable de la position
void deplacement_diagonal_bas_gauche(int largeur, int hauteur, coord* position);

//@ requires deux entiers hauteur et largeur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en appelant deplacement_bas et deplacement_droit, modifie les deux variable de la position
void deplacement_diagonal_bas_droit(int largeur, int hauteur, coord* position);

//@ requires trois entiers hauteur et largeur et une coordonnée 
//@ assigns nothing
//@ ensures modifie la position en appelant une des huit fonctions de déplacement ci-dessus en fonction de la valeur de direction
void deplacement(int direction, int largeur,int hauteur, coord* position);  
  

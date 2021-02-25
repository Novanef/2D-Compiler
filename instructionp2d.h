#include"deplacementp2d.h"

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur somme
void addition(pile* p);

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur différence
void soustraction(pile* p);

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur produit
void multiplication(pile* p);

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur quotient ou 42 si a est nul
void division(pile* p);

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile b modulo a ou 0xbadc0de si a est nul
void reste(pile* p);

//@ requires un pointeur sur une pile *p 
//@ assigns un entier a
//@ ensures depile un entier de p et empile 0 s'il est non nul ou 1 s'il est nu
void non_logique(pile* p);

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile 1 si b>a ou 0 sinon
void plus_grand_que(pile* p);

//@ requires un pointeur sur un entier direction 
//@ assigns noting
//@ ensures change direction en un entier aléatoire
void hasard_direction(int* direction);

//@ requires un pointeur sur un entier direction et sur une pile p
//@ assigns un entier x
//@ ensures dépile un entier x de p et change *direction en x modulo 8
void entier_direction(int* direction, pile* p);

//@ requires un pointeur sur un entier direction 
//@ assigns nothing
//@ ensures change *direction en (*direction - 1) modulo 8
void gauche_45(int* direction);

//@ requires un pointeur sur un entier direction 
//@ assigns nothing
//@ ensures change *direction en (*direction + 1) modulo 8
void droite_45(int* direction);

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 2 si x est nul ou 6 sinon
void conditionnelle_horizontale(int* direction, pile* p);

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 4 si x est nul ou 0 sinon
void conditionnelle_verticale(int* direction, pile* p);

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 1 si x est nul ou 5 sinon
void conditionnelle_diagonale_droite(int* direction, pile* p);

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 3 si x est nul ou 7 sinon
void conditionnelle_diagonale_gauche(int* direction, pile* p);

//@ requires un pointeur sur une pile p
//@ assigns un entier x
//@ ensures dupplique le sommet de p
void dupliquer(pile* p);

//@ requires un pointeur sur une pile p
//@ assigns deux entiers x
//@ ensures échange la position des deux entiers au sommet de p
void echanger(pile *p);

//@ requires un pointeur sur une pile p
//@ assigns nothing
//@ ensures dépile un entier de p et l'affiche sur le flux stdout
void afficher_entier(pile* p);

//@ requires un pointeur sur une pile p
//@ assigns nothing
//@ ensures dépile un entier de p et affiche le caractère correspondant (code ASCII) sur le flux stdout
void afficher_caractere(pile* p);

//@ requires trois entiers directoin, largeur et hauteur et deux pointeurs sur une coordonnée position et une pile p
//@ assigns un entier n
//@ ensures dépile un entier n de *p et appelle n fois la fonction deplacement
void pont(int direction, int largeur, int hauteur,coord* position, pile* p);

//@ requires une grille de caractères grille, deux entiers largeur et hauteur correspondant à la grille et un pointeur sur une pile p
//@ assigns deux entiers x et y
//@ ensures dépile deux entiers x et y et empile le code ASCII du caractère de grille[x][y] si grille[x][y] existe, empile 0 sinon
void get(char** grille, int largeur, int hauteur, pile *p);

//@ requires une grille de caractères grille, deux entiers largeur et hauteur correspondant à la grille et un pointeur sur une pile p
//@ assigns trois entiers x, y et z
//@ ensures dépile trois entiers x, y et z et remplace le caractère de grille[x][y] par celui ayant z comme code ASCII si grille[x][y] existe, ne fait rien sinon
void put(char** grille, int largeur, int hauteur, pile *p);

//@ requires un pointeur sur une pile p 
//@ assigns un entier x
//@ ensures demande un entier x à l'utilisateur et l'empile sur *p
void demander_entier(pile *p);

//@ requires un pointeur sur une pile p 
//@ assigns un caractère c
//@ ensures demande un caractère c à l'utilisateur et empile son code ASCII sur *p
void demander_caractere(pile *p);

//@ requires une grille de caractère grille, deux entier largeur et hauteur et trois pointeur sur une coordonée position, deux entiers direction et mode_ascii et une pile p
//@ assigns nothing
//@ ensures si *ode_ascii vaut 1, empile le code ASCII du caractère présent à *position dans grille, sauf si c'est '"'. Dans ce cas, change *mode_ascii en 0. Si *mode_ascii vaut 0, appelle une des fonctions ci-dessus en fonction du caractère présent à *position dans grille. Si c'est '"', change *mode_ascii en 1
void pas(char** grille, int largeur, int hauteur, coord* position,int* direction, pile* p, int* mode_ascii);

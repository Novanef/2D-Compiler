#include"structurep2d.h"

//@ requires nothing
//@ assigns nothing
//@ ensures retourne une pile vide
pile creerpile();

//@ requires une pile p
//@ assigns un element
//@ ensures affiche les éléments de la pile les un au dessus des autres dans l'ordre
void affpile(pile p);

//@ requires un pointeur sur une pile p et un entier x
//@ assigns une pile
//@ ensures empile x au sommet de *p
void empile(pile* p, int x);

//@ requires un pointeur sur une pile p
//@ assigns un entier
//@ ensures retourne 0 si p est vide, sinon dépile le sommet de p et le retourne
int depile(pile* p);

//@ requires un pointeur sur une pile de sauvegarde p_s, une grille de caractères grille, des coordonnées position, un entier direction, une pile p, un entier mode_ascii
//@ assigns une sauvegarde, une pile et un entier
//@ ensures empile la sauvegarde formée à partir des arguments au dessus de la pile de *p_svoid empile_sauvegarde(pile_sauvegarde* p_s, char** grille, coord position, int direction, pile p, int mode_ascii );
void empile_sauvegarde(pile_sauvegarde* p_s, char** grille, coord position, int direction, pile p, int mode_ascii );

//@ requires un pointeur sur une pile de sauvegade p_s
//@ assigns deux sauvegardes
//@ ensures dépile la sauvegarde au-dessus de *p_s, la retourne et libère la mémoire qu'elle occupait
sauvegarde depile_sauvegarde(pile_sauvegarde* p_s);

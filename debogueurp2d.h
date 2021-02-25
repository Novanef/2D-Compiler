#include<string.h>
#include"instructionp2d.h"
#define MAX 1000

//@ requires une grille de caractere char, sa largeur, sa hauteur, une coordonnée position et une pile p 
//@ assigns nothing
//@ ensures affiche char avec des axes gradués de 5 en 5, indique la position sur les axes et en dessous de la grille et affiche la pile
void affichage(char** grille, int largeur, int hauteur, coord position, pile p);

//@ requires un chemin de fichier correct chemin et une pile p 
//@ assigns un pointeur sur le fichier, neuf entiers, une grille de caractères, sept tableaux de caractères, une grille d'entier, une coordonnée, une pile_sauvegarde, deux sauvegardes 
//@ ensures lance le debuggeur sur le fichier correspondant au chemin chemin s'il existe et attends les commandes entrées par l'utilisateur. Se termine lorsque le programme p2d se termine (ie l'arrivée sur le caractère '@') ou lorsque l'utilisateur entre "quit". Si le chemin est incorrect, affiche l'erreur et met fin au programme en retournant EXIT_FAILURE
void exec(char* chemin, pile* p);	

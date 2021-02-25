#include"instructionp2d.h"
#define MAX 1000

//@ requires un chemin de fichier correct chemin et un pointeur vers une pile p
//@ assigns  un pointeur vers un fichier, quatre entiers, une grille de caractères, un tableau de caractères et une coordonnée
//@ ensures interprète le fichier correspondant à chemin s'il existe. Si le chemin est incorrect, affiche l'erreur et met fin au programme en retournant EXIT_FAILURE
void exec(char* chemin, pile* p);

int main(int argc, char*argv[]);

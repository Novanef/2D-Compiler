#include<stdio.h>
#include<stdlib.h>

// définition du type pile à taille variable (liste chaînée)

typedef struct element element;

struct element {
  int val;
  element* next;
};

typedef struct element* pile;

struct coord {
  int x;
  int y;
};

typedef struct coord coord;

//les deux structures suivantes sont uniquement utilisées dans le cadre de la commande "prec" du debuggeur afin de sauvegarder les étapes précédentes
typedef struct sauvegarde sauvegarde;

struct sauvegarde {
  char** grille;
  coord position;
  int direction;
  pile p;
  int mode_ascii;
  sauvegarde* next;
};

typedef struct sauvegarde* pile_sauvegarde;


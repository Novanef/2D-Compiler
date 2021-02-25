#include"deplacementp2d.h"

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur somme
void addition(pile* p) {
  int a = depile(p);
  int b = depile(p);
  empile(p,a+b);
}

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur différence
void soustraction(pile* p) {
  int a = depile(p);
  int b = depile(p);
  empile(p,b-a);
}

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur produit
void multiplication(pile* p){
  int a = depile(p);
  int b = depile(p);
  empile(p,a*b);
}

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile leur quotient ou 42 si a est nul
void division(pile* p){
  int a = depile(p);
  if (a == 0) {
    empile(p,42);
  }
  else {
    int b = depile(p);
    empile(p,b/a);
  }
}

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile b modulo a ou 0xbadc0de si a est nul
void reste(pile* p) {
  int a = depile(p);
  if (a == 0) {
    empile(p,0xbadc0de);
  }
  else {
    int b = depile(p);
    empile(p,b%a);
  }
}

//@ requires un pointeur sur une pile *p 
//@ assigns un entier a
//@ ensures depile un entier de p et empile 0 s'il est non nul ou 1 s'il est nul
void non_logique(pile* p) {
  int a = depile(p);
  empile(p,!(a));
}

//@ requires un pointeur sur une pile *p 
//@ assigns deux entiers a et b
//@ ensures depile deux entiers de p et empile 1 si b>a ou 0 sinon
void plus_grand_que(pile* p) {
  int a = depile(p);
  int b = depile(p);
  empile(p,b>a);
}

//@ requires un pointeur sur un entier direction 
//@ assigns noting
//@ ensures change direction en un entier aléatoire
void hasard_direction(int* direction) {
  *direction = aleatoire();
}

//@ requires un pointeur sur un entier direction et sur une pile p
//@ assigns un entier x
//@ ensures dépile un entier x de p et change *direction en x modulo 8
void entier_direction(int* direction, pile* p) {
  int x = depile(p);
  *direction = x%8;
}

//@ requires un pointeur sur un entier direction 
//@ assigns nothing
//@ ensures change *direction en (*direction - 1) modulo 8
void gauche_45(int* direction) {
  *direction = (*direction - 1) %8;
}

//@ requires un pointeur sur un entier direction 
//@ assigns nothing
//@ ensures change *direction en (*direction + 1) modulo 8
void droite_45(int* direction) {
  *direction = (*direction + 1) %8;
}

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 2 si x est nul ou 6 sinon
void conditionnelle_horizontale(int* direction, pile* p) {
  int x = depile(p);
  if (x) {
    *direction = 6;
  }
  else {
    *direction = 2;
  }
}

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 4 si x est nul ou 0 sinon
void conditionnelle_verticale(int* direction, pile* p) {
  int x = depile(p);
  if (x) {
    *direction = 0;
  }
  else {
    *direction = 4;
  }
}

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 1 si x est nul ou 5 sinon
void conditionnelle_diagonale_droite(int* direction, pile* p) {
  int x = depile(p);
  if (x) {
    *direction = 5;
  }
  else {
    *direction = 1;
  }
}

//@ requires un pointeur sur un entier direction et une pile p 
//@ assigns un entier x
//@ ensures dépile x de *p et change *direction en 3 si x est nul ou 7 sinon
void conditionnelle_diagonale_gauche(int* direction, pile* p) {
  int x = depile(p);
  if (x) {
    *direction = 7;
  }
  else {
    *direction = 3;
  }
}

//@ requires un pointeur sur une pile p
//@ assigns un entier x
//@ ensures dupplique le sommet de p
void dupliquer(pile* p){
  int x = depile(p);
  empile(p,x);
  empile(p,x);
}

//@ requires un pointeur sur une pile p
//@ assigns deux entiers x
//@ ensures échange la position des deux entiers au sommet de p
void echanger(pile *p) {
  int a = depile(p);
  int b = depile(p);
  empile(p,a);
  empile(p,b);
}

//@ requires un pointeur sur une pile p
//@ assigns nothing
//@ ensures dépile un entier de p et l'affiche sur le flux stdout
void afficher_entier(pile* p) {
  printf("%i",depile(p));
}

//@ requires un pointeur sur une pile p
//@ assigns nothing
//@ ensures dépile un entier de p et affiche le caractère correspondant (code ASCII) sur le flux stdout
void afficher_caractere(pile* p) {
  printf("%c",depile(p));
}

//@ requires trois entiers directoin, largeur et hauteur et deux pointeurs sur une coordonnée position et une pile p
//@ assigns un entier n
//@ ensures dépile un entier n de *p et appelle n fois la fonction deplacement
void pont(int direction, int largeur, int hauteur,coord* position, pile* p) {
  int n = depile(p);
  for (int i = 0; i < n; i++) {
    deplacement(direction, largeur, hauteur, position);
  }
}

//@ requires une grille de caractères grille, deux entiers largeur et hauteur correspondant à la grille et un pointeur sur une pile p
//@ assigns deux entiers x et y
//@ ensures dépile deux entiers x et y et empile le code ASCII du caractère de grille[x][y] si grille[x][y] existe, empile 0 sinon
void get(char** grille, int largeur, int hauteur, pile *p) {
  int x = depile(p);
  int y = depile(p);
  if (0 <= x && x < hauteur && 0 <= y && y< largeur){
    empile(p,grille[x][y]);
  }
  else {
    empile(p,0);
  }
}

//@ requires une grille de caractères grille, deux entiers largeur et hauteur correspondant à la grille et un pointeur sur une pile p
//@ assigns trois entiers x, y et z
//@ ensures dépile trois entiers x, y et z et remplace le caractère de grille[x][y] par celui ayant z comme code ASCII si grille[x][y] existe, ne fait rien sinon
void put(char** grille, int largeur, int hauteur, pile *p) {
  int x = depile(p);
  int y = depile(p);
  int z = depile(p);
  if ((0 <= x && x < hauteur) && (0 <= y && y < largeur) ){
    grille[x][y] = z;
  }
}

//@ requires un pointeur sur une pile p 
//@ assigns un entier x
//@ ensures demande un entier x à l'utilisateur et l'empile sur *p
void demander_entier(pile *p) {
  int x;
  printf("entrez un entier : ");
  scanf("%i",&x);
  empile(p,x);
}

//@ requires un pointeur sur une pile p 
//@ assigns un caractère c
//@ ensures demande un caractère c à l'utilisateur et empile son code ASCII sur *p
void demander_caractere(pile *p) {
  char c;
  printf("entrez un caractère : ");
  scanf("%c",&c);
  empile(p,c);
}

//@ requires une grille de caractère grille, deux entier largeur et hauteur et trois pointeur sur une coordonée position, deux entiers direction et mode_ascii et une pile p
//@ assigns nothing
//@ ensures si *ode_ascii vaut 1, empile le code ASCII du caractère présent à *position dans grille, sauf si c'est '"'. Dans ce cas, change *mode_ascii en 0. Si *mode_ascii vaut 0, appelle une des fonctions ci-dessus en fonction du caractère présent à *position dans grille. Si c'est '"', change *mode_ascii en 1
void pas(char** grille, int largeur, int hauteur, coord* position,int* direction, pile* p, int* mode_ascii) {
  if (*mode_ascii == 1) {
      if (grille[position->x][position->y] == '"') {
	*mode_ascii = 0;
      }
      else {
	empile(p,grille[position->x][position->y]);
      }
    }
    else {
      switch (grille[position->x][position->y]) {
      case '+' : addition(p); break;
      case '-' : soustraction(p); break;
      case '*' : multiplication(p); break;
      case ':' : division(p); break;
      case '%' : reste(p); break;
      case '!' : non_logique(p); break;
      case '`' : plus_grand_que(p); break;
      case '>' : *direction = 2; break;
      case '<' : *direction = 6; break;
      case '^' : *direction = 0; break;
      case 'v' : *direction = 4; break;
      case '?' : hasard_direction(direction); break;
      case '\'' : entier_direction(direction, p); break;
      case ']' : gauche_45(direction); break;
      case '[' : droite_45(direction); break;
      case '_' : conditionnelle_horizontale(direction, p); break;
      case '|' : conditionnelle_verticale(direction, p); break;
      case '/' : conditionnelle_diagonale_droite(direction, p); break;
      case '\\' : conditionnelle_diagonale_gauche(direction, p); break;
      case '"' : *mode_ascii = 1; break;
      case '=' : dupliquer(p); break;
      case '$' : echanger(p); break;
      case ';' : depile(p); break;
      case '.' : afficher_entier(p); break;
      case ',' : afficher_caractere(p); break;
      case '#' : pont(*direction, largeur, hauteur, position, p); break;
      case 'g' : get(grille, largeur, hauteur, p); break;
      case 'p' : put(grille, largeur, hauteur, p); break;
      case '&' : demander_entier(p); break;
      case '~' : demander_caractere(p); break;
      case '0' : 
      case '1' : 
      case '2' : 
      case '3' : 
      case '4' : 
      case '5' : 
      case '6' : 
      case '7' : 
      case '8' : 
      case '9' : empile(p, grille[position->x][position->y] - 48); break;
      default : break;
      }
    }
}

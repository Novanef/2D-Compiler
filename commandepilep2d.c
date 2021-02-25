#include"structurep2d.h"

//@ requires nothing
//@ assigns nothing
//@ ensures retourne une pile vide
pile creerpile(){
  pile p = NULL;
  return p;
}

//@ requires une pile p
//@ assigns un element
//@ ensures affiche les éléments de la pile les un au dessus des autres dans l'ordre
void affpile(pile p) {
  if (p == NULL){
    printf("|");
  }
  else {
    element e = *p;
    printf(" %i (%c) |",e.val,e.val);
    while(e.next != NULL){//se termine lorsque l'on atteint le bout de la pile
      e = *e.next;
      printf(" %i (%c) |",e.val,e.val);
    }
  }
  printf("|\n");
}

//@ requires un pointeur sur une pile p et un entier x
//@ assigns une pile
//@ ensures empile x au sommet de *p
void empile(pile* p, int x){
  element* e = malloc(sizeof(*e));
  e->val = x;
  e->next = *p;
  *p = e;
}

//@ requires un pointeur sur une pile p
//@ assigns un entier et un element
//@ ensures retourne 0 si p est vide, sinon dépile le sommet de p et le retourne
int depile(pile* p){
  if (p == NULL || *p == NULL) {
    return 0;
  }
  element* e = *p;
  int x = (*p)->val;
  *p = (*p)->next;
  free(e);
  return x;
}

//@ requires un pointeur sur une pile de sauvegarde p_s, une grille de caractères grille, des coordonnées position, un entier direction, une pile p, un entier mode_ascii
//@ assigns une sauvegarde, une pile et un entier
//@ ensures empile la sauvegarde formée à partir des arguments au dessus de la pile de *p_s
void empile_sauvegarde(pile_sauvegarde* p_s, char** grille, coord position, int direction, pile p, int mode_ascii ){
  sauvegarde* s = malloc(sizeof(*s));
  s->grille = grille;
  s->position = position;
  s->direction = direction;
  s->p = NULL;
  pile temp = NULL;
  int x;
  while(p != NULL) {//se termine lorsque l'on atteint le bout de la pile p
    x = p->val;
    p = p->next;
    empile(&temp,x);
  }
  while (temp != NULL) {//se termine lorsque l'on atteint le bout de la pile temp
    x = depile(&temp);
    empile(&(s->p),x);
  }
  s->mode_ascii = mode_ascii;
  s->next = *p_s;
  *p_s = s;
}

//@ requires un pointeur sur une pile de sauvegade p_s
//@ assigns deux sauvegardes
//@ ensures dépile la sauvegarde au-dessus de *p_s, la retourne et libère la mémoire qu'elle occupait
sauvegarde depile_sauvegarde(pile_sauvegarde* p_s){
  sauvegarde s = **p_s;
  sauvegarde* temp = *p_s;
  *p_s = (*p_s)->next;
  free(temp);
  return s;
}

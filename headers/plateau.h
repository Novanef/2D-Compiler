#include "../headers/carte.h"

/*retourne 0 si le tour est pair ou 1 si il est impair */
int ParityTurn(board b);

/*Affiche les cartes contenues dans une structure*/
void print_deck(ensiie e);

/*Affiche les cartes contenues dans une structure*/
void print_discard(ensiie e);

/*Affiche les cartes contenues dans une structure*/
void print_hand(ensiie e);

/*Affiche les cartes contenues dans une structure*/
void print_field(ensiie e);

/*retourne le nb max de Personnel pouvant être présent simultanément sur un coté du terrain*/
int NbMaxPersonnel(board b);

/*retourne le nombre de cartes personnel sur le terrain d'une ensiie*/
int NbPersonnel(ensiie e);

/*change les valeurs du développement (si mode==0) ou de la durabilité (mode==1)
des cartes élèves de la pile d'une ensiie*/
void ChangeStudent(queue_student* eleves,int value,int mode);

/*active l'effet d'une carte*/
void TriggerEffect(card c,ensiie *player,ensiie* opponent);


/*renvoie le personnel correspondant à l'effet d'une carte*/
Personnel FindEffect(card c);

/*Joue la carte personnel c et la pose sur le champ, en enlevant la carte personnel la plus ancienne du plateau si besoin*/
void PlayPersonnel(card c,ensiie* player,ensiie* opponent,board b);

/*mélange une pile*/
pile shuffle(pile *p);

/*Joue la carte action c et l'envoie dans la défausse*/
void PlayAction(card c, ensiie* player,ensiie* opponent);

/*Joue la carte c*/
void PlayCard(card c,ensiie* e,ensiie* o,board b);


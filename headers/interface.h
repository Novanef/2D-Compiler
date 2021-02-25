#include "../headers/structures.h"

/*demande au joueur s'il veut jouer une carte FISE ou FISA,
 renvoie 1 pour FISE, 2 pour FISA et 0 pour RIEN*/
int AskStudent();

/*retourne la position de la carte que le joueur souhaite jouer depuis sa main 
ou bien 0 pour finir la phase du joueur*/
int AskAction(ensiie *e);

/*afficher toutes les informations*/
void show_information(board b);

/*afficher qu'une nouvelle phase commence*/
void show_begin(board b,ensiie e);

/*afficher le plateau*/
void show_board(board b);

/*demander à un joueur qui reçoit une nouvelle carte Elève s’il souhaite ajouter une carte FISE ou FISA*/
int ask_fisefisa(ensiie e);

/*demander à un joueur de choisir une carte de sa main, renvoie l'adresse de la carte ou -1 si le joueur choisit de finir son tour*/
void* ask_choosecard(ensiie e);

/*afficher le gagnant du jeu ou egalite le cas echeant*/
void show_winner(int i);

#include "../headers/interface.h"
#include "../headers/plateau.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*demande au joueur s'il veut jouer une carte FISE ou FISA,
 renvoie 1 pour FISE, 2 pour FISA et 0 pour RIEN*/
int AskStudent(){
    char ask[5];
    printf(" FISE OU FISA OU RIEN?\n");
    printf("-FISE   -FISA   -RIEN\n");
    while(!strncmp(ask,"FISE",5)||!strncmp(ask,"FISA",5)|| !strncmp(ask,"RIEN",5)){
    fgets(ask,256,stdin);
    if(strcmp(ask,"FISE")==0){
        return 1;
        }
    if(strcmp(ask,"FISA")==0){
        return 2;
    }
    }
    return 0;
}

/*demander à un joueur de choisir une carte de sa main, renvoie l'adresse de la carte ou -1 si le joueur choisit de finir sa phase*/
void* ask_choosecard(ensiie e){
    char ask[256];
    printf("Choisissez une action à mener :\n");
    printf("-play x : joue la carte à la position x de votre main\n");
    printf("-play: joue un eleve\n");
    printf("-hand: montre les cartes en main et leurs caractéristiques\n");
    printf("-field: montre les cartes sur le terrain\n");
    printf("-eleve: donne le nombre d'eleves dans les piles\n");
    printf("-end : mets fin à votre tour\n");
    while(strncmp(ask,"end",5)||strncmp(ask,"play",5)){
        fgets(ask,256,stdin);
        if( !strncmp(ask,"play",5) && strnlen(ask,256)>=7){
            int position=0;
            char askbis[256];
            sscanf(ask,"%s %d",askbis,&position);
            if(position<=length_pile(e.hand)){
                queue *temp=&e.hand;
                for(int i=0;i<position-1;i++){
                    *temp=(*temp)->next;
                }
                return &((*temp)->value);
            }
        }
        if(!strncmp(ask,"play",4)==0){
            AskStudent();
        }
        if(strncmp(ask,"hand",4)==0){
            print_hand(e);
        }
        if(strncmp(ask,"field",5)==0){
            print_field(e);
        }
        if(strncmp(ask,"eleve",5)==0){
            printf("la queue FISE comporte %i eleves et la queue FISA %i\n",length_queue_student((&e)->FISE),length_queue_student((&e)->FISA));
        }
        if(strncmp(ask,"end",3)==0){
            return -1;
        }
        else{
            printf("Entrez une nouvelle commande\n");
        }
    }
    return -1;
}

/*afficher toutes les informations*/
void show_information(board b){
    print_discard(b.player1);
    print_discard(b.player2);
    print_hand(b.player1);
    print_hand(b.player2);
    print_field(b.player1);
    print_field(b.player2);
}

/*afficher qu'une nouvelle phase commence*/
void show_begin(board b,ensiie e){
    printf("Nouvelle phase, tour %i\n",b.turn);
    if(&b.player1==&e){
        printf("au tour de Player 1 de jouer !\n");
    }
    else{
        printf("au tour de Player 2 de jouer !\n");
    }
}

/*afficher le gagnant du jeu ou egalite le cas echeant*/
void show_winner(int i){
    if (i == 1)
        printf("Le joueur 1 a gagné !\n");
    if (i == 2)
        printf("Le joueur 2 a gagné !\n");
    if (i == 3)
        printf("Égalité !");
}

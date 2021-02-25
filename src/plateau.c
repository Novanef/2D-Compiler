#include "../headers/plateau.h"
#include "../headers/carte.h"
#include <stdio.h>
#include <stdlib.h>

/*retourne 0 si le tour est pair ou 1 si il est impair */
int ParityTurn(board b){
    return(b.turn%2);
}

/*Affiche les cartes contenues dans une structure*/
void print_deck(ensiie e){
    printf("Deck:\n");
    while(e.deck!=NULL){
        print_card(e.deck->value);
        e.deck=e.deck->next;
    }
    printf("\n");
}

/*Affiche les cartes contenues dans une structure*/
void print_discard(ensiie e){
    printf("Discard:\n");
    while(e.discard!=NULL){
        print_card(e.discard->value);
        e.discard=e.discard->next;
    }
    printf("\n");
}

/*Affiche les cartes contenues dans une structure*/
void print_hand(ensiie e){
    printf("Hand:\n");
    while(e.hand!=NULL){
        print_card(e.hand->value);
        e.hand=e.hand->next;
    }
    printf("\n");
}

/*Affiche les cartes contenues dans une structure*/
void print_field(ensiie e){
  while(e.field!=NULL){
        print_card(e.field->value);
        e.field=e.field->next;
    }  
    printf("\n");
}
/*retourne le nb max de Personnel pouvant être présent simultanément sur un coté du terrain*/
int NbMaxPersonnel(board b){
    if(b.turn<6){
        return 1;
    }
    if(b.turn<11){
        return 2;
    }
    return 3;
}
/*retourne le nombre de cartes personnel sur le terrain d'une ensiie*/
int NbPersonnel(ensiie e){
    return length_queue(e.field);
}
/*change les valeurs du développement (si mode==0) ou de la durabilité (mode==1)
des cartes élèves de la pile d'une ensiie*/
void ChangeStudent(queue_student* eleves,int value,int mode){
    if(mode==0){
        while(eleves!=NULL){
            ((*eleves)->value).development+=value;
            *eleves = (*eleves)->next;
        }
    }
    if(mode==1){
       while(eleves!=NULL){
            ((*eleves)->value).durability+=value;
            *eleves=(*eleves)->next;
        } 
    }
}

/*renvoie l'entier correspondant à l'effet d'une carte*/
Personnel FindEffect(card c){
    if(c.type==1){
        Personnel EffetsPerso[20] = {
        (Personnel) {1,1,{1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {2,1,{2,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {3,1,{3,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {4,1,{4,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {5,1,{5,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {6,1,{6,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {7,1,{7,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {8,1,{8,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0}},
        {9,2,{1,3,0,0,0,0,0,0},{1,1,0,0,0,0,0,0}},
        {10,2,{2,4,0,0,0,0,0,0},{1,1,0,0,0,0,0,0}},
        {11,2,{5,7,0,0,0,0,0,0},{1,1,0,0,0,0,0,0}},
        {12,2,{6,8,0,0,0,0,0,0},{1,1,0,0,0,0,0,0}},
        {13,1,{11,0,0,0,0,0,0,0},{2,0,0,0,0,0,0,0}},
        {14,3,{9,10,11,0,0,0,0,0},{2,1,1,0,0,0,0,0}},
        {15,3,{10,11,12,0,0,0,0,0},{2,1,1,0,0,0,0,0}},
        {16,4,{1,2,6,10,0,0,0,0},{1,1,1,1,0,0,0,0}},
        {17,4,{3,4,8,10,0,0,0,0},{1,1,1,1,0,0,0,0}},
        {18,3,{1,2,12,0,0,0,0,0},{2,2,1,0,0,0,0,0}},
        {19,3,{3,4,12,0,0,0,0,0},{2,2,1,0,0,0,0,0}},
        {20,8,{1,2,3,4,9,10,11,12},{2,2,2,2,1,1,1,2}},
        };
        for(int i=0;i<20;i++){
            if(c.ID==EffetsPerso[i].ID){
                return EffetsPerso[i];
            }
        }
    }
    return( (Personnel) {0,0,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}});
}

/*active l'effet d'une carte*/
void TriggerEffect(card c,ensiie *player,ensiie* opponent){
    if(c.type==1){
        Personnel Played=FindEffect(c);
        for(int i=0;i<Played.number;i++){
            switch(Played.effect[i]){
                case 1:ChangeStudent(&player->FISE,Played.value[i],0); break;
                case 2:ChangeStudent(&player->FISE,Played.value[i],1); break;
                case 3:ChangeStudent(&player->FISA,Played.value[i],0); break;
                case 4:ChangeStudent(&player->FISA,Played.value[i],1); break;
                case 5:ChangeStudent(&opponent->FISE,-Played.value[i],0); break;
                case 6:ChangeStudent(&opponent->FISE,-Played.value[i],1); break;
                case 7:ChangeStudent(&opponent->FISA,-Played.value[i],0); break;
                case 8:ChangeStudent(&opponent->FISA,-Played.value[i],1); break;
                case 9:player->DD+=Played.value[i]; break;
                case 10:opponent->DD-=Played.value[i]; break;
                case 11:player->bonuscard += Played.value[i]; break;
                case 12:player->Student_Nbr += Played.value[i];
            }
        }
    }
}



/*Joue la carte personnel c et la pose sur le champ, en enlevant la carte personnel la plus ancienne du plateau si besoin*/
void PlayPersonnel(card c,ensiie* player,ensiie* opponent,board b){
    if(NbPersonnel(*player)==NbMaxPersonnel(b)){
       stack(&player->discard,unthread(&player->field));
       stack(&player->field,c);
    }
    else{
        stack(&player->field,pick(&player->hand,c));
    }
    TriggerEffect(c,player,opponent);
}

/*mélange une pile*/
pile shuffle(pile *p){
    pile shuffled = (pile) malloc(sizeof(shuffled));
    pile copy = *p;
    int n = length_pile(*p);
    card* temp[n];
    for (int i = 0; i < n; i++){
        temp[i] = &copy->value;
        copy = copy->next;
    }
    int i;
    while (length_pile(shuffled) < n){
        i = random(n-1);
        while (temp[i] == NULL && i<n){
            i = i+1;
        }
        while (temp[i] == NULL && i>=0){
            i = i-1;
        }
        stack(&shuffled,*temp[i]);
        temp[i] = NULL;
    }
    return shuffled;
}

/*Joue la carte action c et l'envoie dans la défausse*/
void PlayAction(card c, ensiie* player,ensiie* opponent){
    switch(c.ID){
        case 21: player->DD+=1; break;
        case 22: draw(player,1); break;
        case 23: addFISECard(player); break;
        case 24: addFISACard(player); break;
        case 25: player->PE+=1; break;
        case 26: unstack_student(&opponent->FISE);unstack_student(&opponent->FISA); break;
        case 27: stack(&opponent->discard,unthread(&opponent->field)); break;
        case 28:
        while(player->discard!=NULL){
          stack(&player->deck,unstack(&player->discard));
        }
        card recyclage={28,"Recyclage",10,2};
        stack(&player->deck,recyclage);
        shuffle(&player->deck);
        break;
        case 29: player->FISE_Development += 1;player->FISA_Development += 1; break;
        case 30: player->FISE_Durability += 1;player->FISA_Durability += 1; break;
        case 31: free_queue_student(&player->FISE);free_queue_student(&player->FISA);free_queue_student(&opponent->FISE);free_queue_student(&opponent->FISA); break;
    }
    if (c.ID != 28)
    stack(&player->discard,pick(&player->hand,c));
}

/*Joue la carte c*/
void PlayCard(card c,ensiie* e,ensiie* o,board b){
    if(c.type==1){
        PlayPersonnel(c,e,o,b);
    }
    if(c.type==2){
        PlayAction(c,e,o);
    }
    e->PE -= c.cost;
}


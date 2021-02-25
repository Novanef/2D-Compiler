#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/structures.h"

/*affiche les paramètres de c*/
void print_card(card c){
    printf("| Id = %i, nom = %s, cost = %i, type = %i |",c.ID,c.name,c.cost,c.type);
}

/*@requires: rien
@assigns: *p
@ensures: ajoute par effet une carte à une pile */
void stack(pile *p, card value){
    pile h = (pile) malloc(sizeof(struct element)); /* Nouvel element */
    h->value = value; /* valeur du nouvel element */
    h->next = *p; /* Le element suivant est p */
    *p = h;
}

/*enlève et retourne la dernière carte ajoutée à p*/
card unstack(pile *p){
    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }
    pile next_card=(*p)->next;
    card ret=(*p)->value;
    free(*p);
    *p=next_card;
    return ret;
}

/*enlève et retourne le premier élève ajouté à q*/
student unstack_student(queue_student* q){
    if (q == NULL)
    {
        exit(EXIT_FAILURE);
    }
    queue_student next_student=(*q)->next;
    student ret=(*q)->value;
    free(*q);
    *q=next_student;
    return ret;    
}

/*supprime les éléments de la queue_student ainsi que les allocations mémoire*/
void free_queue_student(queue_student *q){
    queue_student l;
    queue_student tmp;
    l = *q;
    while(l != NULL) {
        tmp = l;
        l = l->next;
        free(tmp);
    }
    q = NULL;
}

/*retourne la longueur de la queue_student q*/
int length_queue_student(queue_student q){
    int i = 0;
    while(q != NULL) {
        i++;
        q = q->next;
    }
    return i;
}


/*supprime les éléments de la pile ainsi que les allocations mémoire*/
void free_pile(pile *p){
    pile l;
    pile tmp;
    l = *p;
    while(l != NULL) {
        tmp = l;
        l = l->next;
        free(tmp);
    }
    p = NULL;
}

/*affiche p*/
void display_pile(pile p){
    if (p == NULL){
        printf("|______________________|");
    }
    else {
        while (p->next != NULL){
            printf("|");
            print_card(p->value);
            printf("|\n");
            p = p-> next;
        }
        printf("|______________________|");
    }
}

/*retourne la longueur de la pile p*/
int length_pile(pile p){
    int i = 0;
    while(p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

/*ajoute value à queue*/
void thread(queue *q, card value){
    element *new = malloc(sizeof(*new));
    if (q == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = NULL;
    if (q != NULL){
        element *elementActuel = *q;
        while (elementActuel->next != NULL){
            elementActuel = elementActuel->next;
        }
        elementActuel->next = new;
    }
    else{
        *q = new;
    }
}

/*enlève et retourne la première carte ajoutée à queue*/
card unthread(queue *q){
    if (q == NULL){
        exit(EXIT_FAILURE);
    }
    queue next_card=(*q)->next;
    card ret=(*q)->value;
    free(*q);
    *q=next_card;
    return ret;
}

/* enlève et retourne la carte c d"une queue q*/
card pick(queue* q, card c){
    if (q == NULL)
        exit(EXIT_FAILURE);
    queue temp =*q;
    queue next = temp->next;
    while(next != NULL){
        if( &(next->value) == &c){
            temp->next = next->next;
            return(next->value);
        }
        temp = temp->next;
        next = next->next;
    }
    exit(EXIT_FAILURE);
}

/* enlève la carte c d"une queue q*/
void display_queue(queue q){
    if (q == NULL){
    printf("[]");
    }
    else {
        printf("[");
        while (q->next != NULL){
         print_card(q->value);
        printf(", ");
         q = q-> next;
        }
    printf("]");
    }
}

/*@requires: rien
@assigns: rien
@ensures: retourne la longueur de la queue q*/
int length_queue(queue q){
    int i = 0;
    while(q != NULL) {
        i++;
        q = q->next;
    }
    return i;
}

/*donne un nombre aléatoire entre 0 et n*/
int random (int n){
   static int tab[100];
   static int first = 0;
   int index;
   double rn;
   if (first == 0)
   {
      int i;
      srand (time (NULL));
      for (i = 0; i < 100; i++)
         tab[i] = rand();
      first = 1;
   }
   index = rand() / RAND_MAX * 99;
   rn = tab[index];
   tab[index] = rand();
   return ((int)(rn/ RAND_MAX * n));
}

/* retourne un deck contenant les 31 cartes du jeu dans un ordre aléatoire*/
pile init_deck(){
    card test = {0,"",0,0};
    card collection[31] ={
    {1,"Tomas Lim",3,1},
   {2,"Marie Szafranski",3,1},
    {3,"Alain Faye",3,1},
    {4,"Christophe Mouilleron",3,1},
    {5,"Stefania Dumbrava",3,1},
    {6,"Julien Forest",3,1},
    {7,"Nicolas Brunel",3,1},
    {8,"Laurence Bourard",3,1},
    {9,"Dimitri Watel",5,1},
    {10,"Vitera Y",5,1},
    {11,"Kevin Goilard",5,1},
    {12,"Vincent Jeannas",5,1},
    {13,"Massinissa Merabet",7,1},
    {14,"Anne-Laure Ligozat",8,1},
    {15,"Catherine Dubois",8,1},
    {16,"Eric Lejeune",10,1},
    {17,"Christine Mathias",10,1},
    {18,"Katrin Salhab",15,1},
    {19,"Abass Sagna",15,1},
    {20,"Laurent Prével",20,1},
    {21,"Cours Développement durable",2,2},
    {22,"Recrutement",2,2},
    {23,"Rentrée FISE",3,2},
    {24,"Rentrée FISA",3,2}, 
    {25,"Energie Verte",4,2},
    {26,"Diplomation",5,2},
    {27,"Décharge",5,2},
    {28,"Recyclage",10,2},
    {29,"Zero papier",10,2},
    {30,"Repas végétarien",10,2},
    {31,"Fermeture annuelle",10,2}};
    pile deck = NULL;
    int i;
    while (length_pile(deck)<31) {
        i = random(30);
        while (collection[i].ID == test.ID && i<30){
            i = i+1;
        }
        while (collection[i].ID == test.ID && i>0){
            i = i-1;
        }
        stack(&deck,collection[i]);
        collection[i] = test;
    }
    return deck;
}

/*création d"un joueur*/
ensiie create_ensiie(){
    ensiie* player = (ensiie*) malloc(sizeof(player));
    player->deck = init_deck();
    player->discard = NULL;
    player->hand = NULL;
    player->field = NULL;
    player->Student_Nbr = 1;
    player->PE = 0;
    player->DD = 0;
    player->bonuscard = 0;
    player->FISE = NULL;
    player->FISA = NULL;
    player->FISE_Development = 1;
    player->FISA_Development = 1;
    player->FISE_Durability = 1;
    player->FISA_Durability = 1;
    return *player;
}

/* création d"un plateau vierge */
board create_board(){
    ensiie player1 = create_ensiie();
    ensiie player2 = create_ensiie();
    board* b = (board*) malloc(sizeof(b));
    b->player1 = player1;
    b->player2 = player2;
    b->turn = 0;
    return *b;
}

/*suppression d"un plateau à la fin de la partie */
void erase(board *b){
    free(b);
}

/*incrémentation du compteur de tour */
void newturn(board *b){
    b->turn = b->turn+1;
}

/*détermine et renvoie le nombre de cartes à piocher au début du tour d"un joueur */
int nbdraw(ensiie e, board b){
    if (b.turn == 0) {
        return 3;
    }
    else {
        return 1 + e.bonuscard;
    }
}
/*fait piocher le nombre de cartes défini par nbdraw */
void draw(ensiie *e,int d){
    for (int i = 0; i < d; i++) {
        stack(&e->hand,unstack(&e->deck));
    }
}

/* ajoute une carte FISE sur le plateau de l"ENSIIE p*/
void addFISECard(ensiie *e){
    queue_student FISE_plus = malloc(sizeof(FISE_plus));
    FISE_plus->value = (student) {1,1};
    FISE_plus->next = e->FISE;
}

/* ajoute une carte FISA sur le plateau de l"ENSIIE p*/
void addFISACard(ensiie *e){
    queue_student FISA_plus = malloc(sizeof(FISA_plus));
    FISA_plus->value = (student) {1,1};
    FISA_plus->next = e->FISA;
}

/* compte le nombre de PE disponible pour l"ENSIIE P*/
int countPE(ensiie e, board b){
    if (b.turn % 2 == 0)
    return length_queue_student(e.FISE);
    else return length_queue_student(e.FISE)+ length_queue_student(e.FISA) * 2;
}

/* permet à l"ENSIIE e de jouer la carte c*/
int allowPlayCard(ensiie e,card c){
    if (e.PE >= c.cost)
        return 1;
    return 0;
}

/* renvoie 1 si le tour est terminé, 0 sinon*/
void endTurn(board *b){
    int Dev_player1 = 0;
    queue_student FISE1 = b->player1.FISE;
    while (FISE1 != NULL){
        Dev_player1 += FISE1->value.development + b->player1.FISE_Development;
        FISE1 = FISE1->next;
    }
    int Dev_player2 = 0;
    queue_student FISE2 = b->player2.FISE;
    while (FISE2 != NULL){
        Dev_player2 += FISE2->value.development + b->player2.FISE_Development;
        FISE2 = FISE2->next;
    }
    if (b->turn %2 == 1){   
        queue_student FISA1 = b->player1.FISA;
        while (FISA1 != NULL){
            Dev_player1 += FISA1->value.development + b->player1.FISA_Development;
            FISA1 = FISA1->next;
        }
        queue_student FISA2 = b->player2.FISA;
        while (FISA2 != NULL){
            Dev_player2 += FISA2->value.development + b->player2.FISA_Development;
            FISA2 = FISA2->next;
        }        
    }
    int Dur_player1 = 0;
    FISE1 = b->player1.FISE;
    while (FISE1 != NULL){
        Dur_player1 += FISE1->value.development + b->player1.FISE_Durability;
        FISE1 = FISE1->next;
    }
    int Dur_player2 = 0;
    FISE2 = b->player2.FISE;
    while (FISE2 != NULL){
        Dur_player2 += FISE2->value.development + b->player2.FISE_Durability;
        FISE2 = FISE2->next;
    }
    if (b->turn %2 == 1){   
        queue_student FISA1 = b->player1.FISA;
        while (FISA1 != NULL){
            Dur_player1 += FISA1->value.development + b->player1.FISA_Durability;
            FISA1 = FISA1->next;
        }
        queue_student FISA2 = b->player2.FISA;
        while (FISA2 != NULL){
            Dur_player2 += FISA2->value.development + b->player2.FISA_Durability;
            FISA2 = FISA2->next;
        }        
    }
    if (Dev_player1 >= Dur_player2)
        b->player1.DD += Dev_player1 - Dur_player2;
    if (Dev_player2 >= Dur_player1)
        b->player2.DD += Dev_player2 - Dur_player1;
}

/* renvoie 1 si le joueur 1 a gagné, 2 si le joueur 2 a gagné, 3 s"il y a égalité, 0 sinon*/
int endGame(board b){
    if (b.player1.DD > 20) {
        if (b.player1.DD > b.player2.DD)
            return 1;
        else {
            if (b.player1.DD < b.player2.DD) return 2;
            else return 3;
        }
    }
    else {
        if (b.player2.DD > 20) return 2;
        else {
            if (b.turn == 30) {
                if (b.player1.DD > b.player2.DD) return 1;
                else {
                    if (b.player1.DD < b.player2.DD) return 2;
                    else return 3;
                }
            }
            else return 0;
        }
    }
}
/*prendre en compte quantité des cartes actions dans le deck, structure de Field=First in First out*/
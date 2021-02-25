#include <stdio.h>
#include <stdlib.h>
#include "../headers/plateau.h"
#include "../headers/interface.h"
#include "../headers/structures.h"

int main() {
    board plateau = create_board();
    while (!endGame(plateau))
    {
        show_begin(plateau, plateau.player1);
        show_information(plateau);
        draw(&plateau.player1, nbdraw(plateau.player1, plateau));
        int fisefisa = AskStudent(plateau.player1);
        if (fisefisa == 1)
        {
            addFISECard(&plateau.player1);
        }
        if (fisefisa == 2)
            addFISACard(&plateau.player1);
        void *ask;
        card *c;
        while (ask = ask_choosecard(plateau.player1) != -1)
        {
            show_information(plateau);
            if (ask != -1)
            {
                c = ask;
                if (allowPlayCard(plateau.player1, *c))
                    PlayCard(*c, &plateau.player1, &plateau.player2, plateau);
                else
                    printf("Pas assez de PE");
            }
        }
        show_begin(plateau, plateau.player2);
        show_information(plateau);
        draw(&plateau.player2, nbdraw(plateau.player2, plateau));
        fisefisa = AskStudent(plateau.player2);
        if (fisefisa == 1)
        {
            addFISECard(&plateau.player2);
        }
        if (fisefisa == 2)
        {
            addFISACard(&plateau.player2);
        }
        while (ask = ask_choosecard(plateau.player2) != -1)
        {
            show_information(plateau);
            if (ask != -1)
            {
                c = ask;
                if (allowPlayCard(plateau.player2, *c))
                    PlayCard(*c, &plateau.player2, &plateau.player2, plateau);
                else
                    printf("Pas assez de PE");
            }
        }
        newturn(&plateau);
    }
    show_winner(endGame(plateau));
    erase(&plateau);
    return 1;
}

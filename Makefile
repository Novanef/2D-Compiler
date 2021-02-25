CC = gcc -Wall -Wextra -g
commandepilep2d.o : commandepilep2d.h 
deplacementp2d.o : deplacementp2d.h
instructionp2d.o : instructionp2d.h
debogueurp2d.o : debogueurp2d.h
interpreteurp2d.o : interpreteurp2d.h

debogueurp2d : debogueurp2d.o deplacementp2d.o instructionp2d.o commandepilep2d.o
	$(CC) -o $@ $^ 

interpreteurp2d : interpreteurp2d.o  deplacementp2d.o instructionp2d.o commandepilep2d.o
	$(CC) -o $@ $^

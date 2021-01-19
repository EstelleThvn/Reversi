# makefile du jeu Reversi

jeu_reversi: main.o fonctions.o
	g++ -o jeu_reversi.exe main.o fonctions.o

code.o: main.cpp fonctions.h
	g++ -o main.o -c main.cpp -Wall

fonctions.o: fonctions.cpp fonctions.h
	g++ -o fonctions.o -c fonctions.cpp -Wall
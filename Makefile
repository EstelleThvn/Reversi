# makefile du jeu Reversi


jeu_reversi: main.o initetaffichage.o partie.o tour.o
	g++ -o jeu_reversi.exe main.o initetaffichage.o partie.o tour.o

code.o: main.cpp main.h initetaffichage.h partie.h tour.h
	g++ -o main.o -c main.cpp -Wall

initetaffichage.o: initetaffichage.cpp main.h initetaffichage.h partie.h tour.h
	g++ -o initetaffichage.o -c initetaffichage.cpp -Wall

partie.o: partie.cpp main.h initetaffichage.h partie.h tour.h
	g++ -o partie.o -c partie.cpp -Wall

tour.o: tour.cpp main.h initetaffichage.h partie.h tour.h
	g++ -o tour.o -c tour.cpp -Wall
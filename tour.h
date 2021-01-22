#ifndef TOUR_H
#define TOUR_H

bool jouerUnTour(Jeu *jeu, Joueur *joueur, bool joueurCourant, int* nbToursLoupesConsecutifs);
bool possibleJouerTourCaseDispo(Jeu *jeu, Joueur *joueur, int rowNewJeton, int columnNewJeton);
bool possibleJouerTourCondition1(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, int rowNewJeton, int columnNewJeton);
bool possibleJouerTourCondition2(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton);
int getLigne();
int getColonne();
void capturePionsAdverses(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton, bool joueurCourant);
bool casesDisposTour(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, bool joueurCourant);

#endif /* TOUR_H */
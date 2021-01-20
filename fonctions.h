#ifndef FONCTIONS_H
#define FONCTIONS_H

const int MAXJETONS = 64;

struct Jeton {
char couleur;
int coordonnees[2];
};

struct Joueur {
char nom[25];
int jetons;
int nbJetonsActuels;
};

struct Jeu {
Joueur *joueur1;
Joueur *joueur2;
Jeton* tableauPointeurJetons[8][8];
};

void initialiseJoueur(Joueur *joueur, int n);
void afficheJoueur(Joueur *joueur);
void initialiseJeu(Jeu *jeu, Joueur *joueur1, Joueur *joueur2);
void affichePlateauJeu(Jeu *jeu);
bool possibleJouerTourCaseDispo(Jeu *jeu, Joueur *joueur, int rowNewJeton, int columnNewJeton);
bool possibleJouerTourCondition1(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, int rowNewJeton, int columnNewJeton);
int getLigne();
int getColonne();
bool jouerUnTour(Jeu *jeu, Joueur *joueur, bool joueurCourant);
void PartieDeJeu(Jeu *jeu);
bool possibleJouerTourCondition2(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton);
void capturePionsAdverses(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton, bool joueurCourant);
void finDePartie(Jeu *jeu);
bool casesDisposTour(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, bool joueurCourant);

#endif /* FONCTIONS_H */
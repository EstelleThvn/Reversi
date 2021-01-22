#ifndef MAIN_H
#define MAIN_H

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

#endif /* MAIN_H */
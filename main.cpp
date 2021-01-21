#include <iostream>
using namespace std;
#include "fonctions.h"


int main() {

    regleDuJeu();

    Joueur* joueur1 = (Joueur*)malloc(25*sizeof(char) + 2*sizeof(int));
    Joueur* joueur2 = (Joueur*)malloc(25*sizeof(char) + 2*sizeof(int));
    
    Jeu* plateauJeuTest = (Jeu*)malloc(64*sizeof(Jeton) + 2 *sizeof(Joueur));

    initialiseJoueur(joueur1,1);
    afficheJoueur(joueur1);
    initialiseJoueur(joueur2,2);
    afficheJoueur(joueur2);

    initialiseJeu(plateauJeuTest, joueur1, joueur2);
    affichePlateauJeu(plateauJeuTest);

    PartieDeJeu(plateauJeuTest);

    return 0;
}
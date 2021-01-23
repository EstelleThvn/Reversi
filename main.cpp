#include <iostream>
using namespace std;
#include "main.h"
#include "initetaffichage.h"
#include "partie.h"
#include "tour.h"


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

    PartieDeJeu(plateauJeuTest);

    free(joueur1);
    free(joueur2);
    free(plateauJeuTest);

    return 0;
}
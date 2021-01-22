#include <iostream>
using namespace std;
#include "main.h"
#include "initetaffichage.h"
#include "partie.h"
#include "tour.h"

//présente le jeu au début d'une partie
void regleDuJeu(){
    cout << endl << "JEU DE REVERSI" << endl;
    cout << "Vous allez devoir jouer tour a tour en posant un jeton sur le plateau de jeu : un joueur possede les jetons noirs 'N', l'autre les jetons blancs 'B'." << endl << "Les cases disponibles lors de votre tour sont indiquees par un point '.'." << endl << endl;
}

// fonction qui fait une partie de jeu, du début à la fin quand plus personne ne peut poser de jetons
void PartieDeJeu(Jeu *jeu) {

    bool joueurCourant = true;
    int nbJetonsPoses = jeu->joueur1->nbJetonsActuels + jeu->joueur2->nbJetonsActuels;
    int nbToursLoupesConsecutifs = 0;


    // jeu->tableauPointeurJetons[1][1]->couleur='B';
    // // jeu->tableauPointeurJetons[1][2]->couleur='B';
    // jeu->tableauPointeurJetons[1][3]->couleur='N';
    // jeu->tableauPointeurJetons[1][4]->couleur='N';
    // jeu->tableauPointeurJetons[1][5]->couleur='N';
    // jeu->tableauPointeurJetons[1][6]->couleur='N';
    // jeu->tableauPointeurJetons[1][7]->couleur='N';
    // jeu->tableauPointeurJetons[1][8]->couleur='N';
    // jeu->tableauPointeurJetons[2][1]->couleur='B';
    // jeu->tableauPointeurJetons[2][2]->couleur='B';
    // jeu->tableauPointeurJetons[2][3]->couleur='N';
    // jeu->tableauPointeurJetons[2][4]->couleur='N';
    // jeu->tableauPointeurJetons[2][5]->couleur='N';
    // jeu->tableauPointeurJetons[2][6]->couleur='N';
    // jeu->tableauPointeurJetons[2][7]->couleur='N';
    // jeu->tableauPointeurJetons[2][8]->couleur='N';
    // jeu->tableauPointeurJetons[3][1]->couleur='B';
    // jeu->tableauPointeurJetons[3][2]->couleur='B';
    // jeu->tableauPointeurJetons[3][3]->couleur='B';
    // jeu->tableauPointeurJetons[3][4]->couleur='N';
    // jeu->tableauPointeurJetons[3][5]->couleur='N';
    // jeu->tableauPointeurJetons[3][6]->couleur='N';
    // jeu->tableauPointeurJetons[3][7]->couleur='N';
    // jeu->tableauPointeurJetons[3][8]->couleur='N';
    // jeu->tableauPointeurJetons[4][1]->couleur='B';
    // jeu->tableauPointeurJetons[4][2]->couleur='B';
    // jeu->tableauPointeurJetons[4][3]->couleur='N';
    // jeu->tableauPointeurJetons[4][4]->couleur='B';
    // jeu->tableauPointeurJetons[4][5]->couleur='N';
    // jeu->tableauPointeurJetons[4][6]->couleur='N';
    // jeu->tableauPointeurJetons[4][7]->couleur='N';
    // jeu->tableauPointeurJetons[4][8]->couleur='N';
    // jeu->tableauPointeurJetons[5][1]->couleur='B';
    // jeu->tableauPointeurJetons[5][2]->couleur='B';
    // jeu->tableauPointeurJetons[5][3]->couleur='B';
    // jeu->tableauPointeurJetons[5][4]->couleur='N';
    // jeu->tableauPointeurJetons[5][5]->couleur='B';
    // jeu->tableauPointeurJetons[5][6]->couleur='N';
    // jeu->tableauPointeurJetons[5][7]->couleur='N';
    // jeu->tableauPointeurJetons[5][8]->couleur='N';
    // jeu->tableauPointeurJetons[6][1]->couleur='B';
    // jeu->tableauPointeurJetons[6][2]->couleur='B';
    // jeu->tableauPointeurJetons[6][3]->couleur='N';
    // jeu->tableauPointeurJetons[6][4]->couleur='B';
    // jeu->tableauPointeurJetons[6][5]->couleur='N';
    // jeu->tableauPointeurJetons[6][6]->couleur='B';
    // jeu->tableauPointeurJetons[6][7]->couleur='N';
    // jeu->tableauPointeurJetons[6][8]->couleur='N';
    // jeu->tableauPointeurJetons[7][1]->couleur='B';
    // jeu->tableauPointeurJetons[7][2]->couleur='B';
    // jeu->tableauPointeurJetons[7][3]->couleur='N';
    // jeu->tableauPointeurJetons[7][4]->couleur='N';
    // jeu->tableauPointeurJetons[7][5]->couleur='B';
    // jeu->tableauPointeurJetons[7][6]->couleur='N';
    // jeu->tableauPointeurJetons[7][7]->couleur='B';
    // jeu->tableauPointeurJetons[7][8]->couleur='N';
    // jeu->tableauPointeurJetons[8][1]->couleur='B';
    // jeu->tableauPointeurJetons[8][2]->couleur='B';
    // jeu->tableauPointeurJetons[8][3]->couleur='B';
    // jeu->tableauPointeurJetons[8][4]->couleur='B';
    // jeu->tableauPointeurJetons[8][5]->couleur='B';
    // jeu->tableauPointeurJetons[8][6]->couleur='B';
    // jeu->tableauPointeurJetons[8][7]->couleur='B';
    // jeu->tableauPointeurJetons[8][8]->couleur='B';

    // jeu->joueur1->nbJetonsActuels= 34;
    // jeu->joueur2->nbJetonsActuels= 29;
    // affichePlateauJeu(jeu);

    // jeu->tableauPointeurJetons[3][4]->couleur='N';
    // jeu->tableauPointeurJetons[4][3]->couleur='N';
    // jeu->tableauPointeurJetons[4][4]->couleur='N';
    // jeu->tableauPointeurJetons[4][5]->couleur='N';
    // jeu->tableauPointeurJetons[5][1]->couleur='N';
    // jeu->tableauPointeurJetons[5][2]->couleur='N';
    // jeu->tableauPointeurJetons[5][3]->couleur='N';
    // jeu->tableauPointeurJetons[5][4]->couleur='N';
    // jeu->tableauPointeurJetons[5][5]->couleur='N';
    // jeu->tableauPointeurJetons[5][6]->couleur='N';
    // jeu->tableauPointeurJetons[6][2]->couleur='N';
    // jeu->tableauPointeurJetons[6][3]->couleur='N';
    // jeu->tableauPointeurJetons[6][4]->couleur='N';
    // jeu->tableauPointeurJetons[7][1]->couleur='B';
    // jeu->tableauPointeurJetons[7][2]->couleur='B';
    // jeu->tableauPointeurJetons[7][3]->couleur='N';
    // jeu->tableauPointeurJetons[7][4]->couleur='N';
    // jeu->tableauPointeurJetons[7][5]->couleur='N';
    // jeu->tableauPointeurJetons[8][1]->couleur='B';
    // jeu->tableauPointeurJetons[8][2]->couleur='B';
    // jeu->tableauPointeurJetons[8][3]->couleur='B';
    // jeu->tableauPointeurJetons[8][4]->couleur='N';

    // jeu->joueur1->nbJetonsActuels= 17;
    // jeu->joueur2->nbJetonsActuels= 5;
    // affichePlateauJeu(jeu);


    //si le plateau est rempli ou que les deux joueurs ne peuvent plus jouer (deux tours consécutifs où les joueurs ne peuvent rien faire)
    while (nbJetonsPoses<64 && nbToursLoupesConsecutifs<2) {
        if(joueurCourant==true){
            joueurCourant = jouerUnTour(jeu, jeu->joueur1, joueurCourant, &nbToursLoupesConsecutifs);
        }
        else{
            joueurCourant = jouerUnTour(jeu, jeu->joueur2, joueurCourant, &nbToursLoupesConsecutifs);
        }

        nbJetonsPoses = jeu->joueur1->nbJetonsActuels + jeu->joueur2->nbJetonsActuels;

    }

    affichePlateauJeu(jeu);

    if(nbToursLoupesConsecutifs==2){
        cout << "Plus aucun joueur ne peut poser de jeton " << endl << endl;
    }

    finDePartie(jeu);

}

//annonce la fin de la partie et le vainqueur
void finDePartie(Jeu *jeu){
    cout << "La partie est finie !" << endl << endl;

    if(jeu->joueur1->nbJetonsActuels > jeu->joueur2->nbJetonsActuels){
        cout << jeu->joueur1->nom << " a gagne ! :)" << endl << endl;
    }
    else if(jeu->joueur2->nbJetonsActuels > jeu->joueur1->nbJetonsActuels){
        cout << jeu->joueur2->nom << " a gagne ! :)" << endl << endl;
    }
    else if(jeu->joueur2->nbJetonsActuels == jeu->joueur1->nbJetonsActuels){
        cout << jeu->joueur1->nom << " et " << jeu->joueur2->nom << " ont le meme nombre de points ! Ex aequo :)" << endl << endl;
    }

    cout << "SCORE : " << endl;
    cout << jeu->joueur1->nom << " : " << jeu->joueur1->nbJetonsActuels << " jetons" << endl;
    cout << jeu->joueur2->nom << " : " << jeu->joueur2->nbJetonsActuels << " jetons" << endl;
}
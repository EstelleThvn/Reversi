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
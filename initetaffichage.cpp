#include <iostream>
using namespace std;
#include "main.h"
#include "initetaffichage.h"
#include "partie.h"
#include "tour.h"


// initialise un joueur
void initialiseJoueur(Joueur *joueur, int n) {
    cout << "Joueur " << n << endl;
    cout << "Entrez le nom du joueur : ";
    cin >> joueur->nom;
    joueur->jetons=30;
    joueur->nbJetonsActuels = 2;
}

//affiche le nom et le nombre de jetons sur le plateau d'un joueur
void afficheJoueur(Joueur *joueur) {
    cout << joueur->nom << " possede " << joueur->nbJetonsActuels << " jetons " << endl << endl;
}

//initialise le jeu
void initialiseJeu(Jeu *jeu, Joueur *joueur1, Joueur *joueur2) {

    jeu->joueur1=joueur1;
    jeu->joueur2=joueur2;


    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
                    Jeton *newJeton = new Jeton;
                    newJeton = (Jeton*) malloc (sizeof(Jeton));
                    newJeton->couleur=' ';
                    newJeton->coordonnees[0]=i;
                    newJeton->coordonnees[1]=j;

                    jeu->tableauPointeurJetons[i][j] = newJeton;
        }
    }

    jeu->tableauPointeurJetons[4][4]->couleur = 'N';
    jeu->tableauPointeurJetons[5][5]->couleur = 'N';
    jeu->tableauPointeurJetons[4][5]->couleur = 'B';
    jeu->tableauPointeurJetons[5][4]->couleur = 'B';

}


//affiche le plateau avec les jetons
void affichePlateauJeu(Jeu *jeu) {
 
    cout << endl;
    cout<<"    1   2   3   4   5   6   7   8  "<<endl; 
    for(int i=1;i<=8;i++) { 
        cout<<"  +---+---+---+---+---+---+---+---+"<<endl; 
        cout<<i<<" | ";
        for(int j=1;j<=8;j++) {
                cout <<jeu->tableauPointeurJetons[i][j]->couleur<<" | ";
        }
        cout<<endl; 
    } 
    cout<<"  +---+---+---+---+---+---+---+---+"<<endl << endl; 
}
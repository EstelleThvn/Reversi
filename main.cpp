#include <iostream>
using namespace std;
// #include <math.h>

const int MAXJETONS = 64;

struct Jeton {
char couleur[1];
int coordonnees[2];
};

struct Joueur {
char nom[25];
int jetons[MAXJETONS];
int nbJetonsActuels;
};

struct Jeu {
Joueur *joueur1;
Joueur *joueur2;
int tableauPointeurJetons[8][8];
};

void initialiseJoueur(Joueur *joueur, int n);
void afficheJoueur(Joueur joueur);
void initialiseJeu(Jeu *jeu, Joueur *joueur1, Joueur *joueur2);
void affichePlateauJeu(Jeu *jeu);

int main() {

    // Jeu plateauJeuTest;
    Joueur joueur1;
    Joueur joueur2;

    initialiseJoueur(&joueur1, 1);
    initialiseJoueur(&joueur1, 2);
    afficheJoueur(joueur1);
    afficheJoueur(joueur2);

    // char BoardTest[8][8];
    // affichePlateauJeu(BoardTest);

    // initialiseJeu(&plateauJeuTest, &joueur1, &joueur2);

    // affichePlateauJeu(&plateauJeuTest);

    return 0;
}

void initialiseJoueur(Joueur *joueur, int n) {
    cout << "Joueur " << n << endl;

    cout << "Entrez le nom du joueur : ";
    cin >> joueur->nom;
    joueur->nbJetonsActuels = 2;

}

void afficheJoueur(Joueur joueur) {
    cout << joueur.nom << " " << joueur.nbJetonsActuels << endl;
}

void initialiseJeu(Jeu *jeu, Joueur *joueur1, Joueur *joueur2) {
    jeu->joueur1=joueur1;
    jeu->joueur2=joueur2;
}

void affichePlateauJeu(Jeu *jeu) {
    int i; 
    for(i=0;i<8;i++) { 
        cout<<"  +---+---+---+---+---+---+---+---+"<<endl; 
        cout<<i+1<<" | "<<jeu->tableauPointeurJetons[i][0]<<" | "<<jeu->tableauPointeurJetons[i][1]<<" | "<<jeu->tableauPointeurJetons[i][2]<<" | "<<jeu->tableauPointeurJetons[i][3]<<" | "<<jeu->tableauPointeurJetons[i][4]<<" | "<<jeu->tableauPointeurJetons[i][5]<<" | "<<jeu->tableauPointeurJetons[i][6]<<" | "<<jeu->tableauPointeurJetons[i][7]<<" |"<<endl; 
    } 
    cout<<"  +---+---+---+---+---+---+---+---+"<<endl; 
    cout<<"    A   B   C   D   E   F   G   H  "<<endl; 
}
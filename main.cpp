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
float jetons[MAXJETONS];
int nbJetonsActuels;
};

struct Jeu {
Joueur *joueurs;
Jeton *jetons;
};

void initialiseJoueur(Joueur *joueur);
void afficheJoueur(Joueur joueur);
void affichePlateauJeu(char Board[8][8]);

int main() {

    // Jeu plateauJeuTest;
    // Joueur joueur1;
    // Joueur joueur2;

    char BoardTest[8][8];
    affichePlateauJeu(BoardTest);

    // initialiseJoueur(&joueur1);
    // initialiseJoueur(&joueur2);
    // afficheJoueur(joueur1);
    // afficheJoueur(joueur2);

    // cout 
    // << "     A   B   C   D   E   F   G   H " << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 1 |   |   |   |   |   |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 2 |   |   |   |   |   |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 3 |   |   |   |   |   |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 4 |   |   |   | O | X |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 5 |   |   |   | X | O |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 6 |   |   |   |   |   |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 7 |   |   |   |   |   |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl 
    // << " 8 |   |   |   |   |   |   |   |   |" << endl 
    // << "   +---+---+---+---+---+---+---+---+" << endl;


    

    return 0;
}

// void initialiseJoueur(Joueur *joueur) {
//     cout << "Entrez le nom du joueur : ";
//     cin >> joueur->nom;
//     joueur->jetons = 
//     joueur->nbJetonsActuels = 2;
// }

// void afficheJoueur(Joueur joueur) {
//     cout << joueur.nom << " " << joueur.jetons << " " << joueur.nbJetonsActuels << endl;
// }


void affichePlateauJeu(char Board[8][8]) {
    int i; 
    for(i=0;i<8;i++) { 
        cout<<"  +---+---+---+---+---+---+---+---+"<<endl; 
        cout<<i+1<<" | "<<Board[i][0]<<" | "<<Board[i][1]<<" | "<<Board[i][2]<<" | "<<Board[i][3]<<" | "<<Board[i][4]<<" | "<<Board[i][5]<<" | "<<Board[i][6]<<" | "<<Board[i][7]<<" |"<<endl; 
    } 
    cout<<"  +---+---+---+---+---+---+---+---+"<<endl; 
    cout<<"    A   B   C   D   E   F   G   H  "<<endl; 
}
#include <iostream>
using namespace std;

const int MAXJETONS = 64;

struct Jeton {
int couleur[1];
int coordonnees[2];
};

struct Joueur {
char nom[25];
Jeton *jetons;
int nbJetonsActuels;
};

struct Jeu {
Joueur *joueur1;
Joueur *joueur2;
int tableauPointeurJetons[8][8];
};

// void ajouteCoordonneesJeton(Jeton **jeton, char color, int coordonnees[2]);
void ajouterJeton(Jeton *jeton, char color, int coordonnees[2]);
void afficheJeton(Jeton jeton);

void initialiseJoueur(Joueur *joueur, int n) {
    cout << "Joueur " << n << endl;

    cout << "Entrez le nom du joueur : ";
    cin >> joueur->nom;
    joueur->nbJetonsActuels = 2;

    Jeton jeton1, jeton2;

    joueur->jetons = (Jeton*) malloc (sizeof(Jeton)*2);

    joueur->jetons[0] = jeton1;
    joueur->jetons[1] = jeton2;

    if(n==1){
        int coordonneesJeton1[2]={4,4};
        int coordonneesJeton2[2]={5,5};
        int color = 7;
        ajouterJeton(&joueur->jetons[0], color, coordonneesJeton1);
        ajouterJeton(&joueur->jetons[1], color, coordonneesJeton2);
    }

}

void ajouterJeton(Jeton *jeton, char color, int coordonnees[2]) {

    jeton->couleur[1] = color;
    jeton->coordonnees[0]=coordonnees[0];
    jeton->coordonnees[1]=coordonnees[1];
}

void afficheJoueur(Joueur joueur) {
    cout << joueur.nom << " possede " << joueur.nbJetonsActuels << " jetons " << endl;

    for(int i=0; i<joueur.nbJetonsActuels; i++){
            afficheJeton(joueur.jetons[i]);
        }
}

void afficheJeton(Jeton jeton) {
    cout << "Couleur : " << jeton.couleur << endl;

    cout << "coordonnees : ";
    for(int i=0; i<2; i++){
        cout << jeton.coordonnees[i] << " ";
    }
    cout << endl;
}

int main() {

    Joueur joueur1;

    initialiseJoueur(&joueur1,1);
    afficheJoueur(joueur1);

    Jeton jetonTest;
    int coorJetonTest[2]={4,4};
    // char colorJetonTest[1]={8};
    ajouterJeton(&jetonTest, 8, coorJetonTest);
    afficheJeton(jetonTest);

    return 0;
}
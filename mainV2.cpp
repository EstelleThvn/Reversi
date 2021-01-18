#include <iostream>
using namespace std;

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


void ajouterJeton(Jeton *jeton, char color, int coordonnees[2]);
void afficheJeton(Jeton jeton);

void initialiseJoueur(Joueur *joueur, int n) {
    cout << "Joueur " << n << endl;
    cout << "Entrez le nom du joueur : ";
    cin >> joueur->nom;
    joueur->jetons=30;
    joueur->nbJetonsActuels = 2;
}

// void ajouterJeton(Jeton *jeton, char color, int coordonnees[2]) {

//     jeton->couleur[1] = color;
//     jeton->coordonnees[0]=coordonnees[0];
//     jeton->coordonnees[1]=coordonnees[1];
// }

void afficheJoueur(Joueur *joueur) {
    cout << joueur->nom << " possede " << joueur->nbJetonsActuels << " jetons " << endl;
}

// void afficheJeton(Jeton jeton) {
//     cout << "Couleur : " << jeton.couleur[1] << endl;

//     cout << "coordonnees : ";
//     for(int i=0; i<2; i++){
//         cout << jeton.coordonnees[i] << " ";
//     }
//     cout << endl;
// }

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

    // cout << jeu->tableauPointeurJetons[4][4]->couleur;
    // cout << jeu->tableauPointeurJetons[1][1]->couleur;

    // free(jeu);

}

void affichePlateauJeu(Jeu *jeu) {
    // char couleurJeton; 
    cout << endl;
    // cout << jeu->tableauPointeurJetons[4][4]->couleur[1];
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

bool possibleJouerTour(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, int rowNewJeton, int columnNewJeton) {

    if (rowNewJeton<1 || rowNewJeton>8 || columnNewJeton<1 || columnNewJeton>8) {
        cout << "vous ne pouvez pas jouer ce coup, la case n'est pas valable" << endl;
        return false;
    }
    else if (jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur!=' '){
        cout << "vous ne pouvez pas jouer ce coup, la case est deja prise" << endl;
        return false;
    }
    else {
        int nbJetonAdverseAlentour = 0;

        for(int i=rowNewJeton-1;i<=rowNewJeton+1;i++) {
            if(i>=1 && i<=8){
                for(int j=columnNewJeton-1;j<=columnNewJeton+1;j++) {
                    if(j>=1 && j<=8){
                        if(jeu->tableauPointeurJetons[i][j]!=NULL && jeu->tableauPointeurJetons[i][j]->couleur==couleurJoueurAdverse) {
                                nbJetonAdverseAlentour++;
                                // break;
                        }
                        cout << i << " " << j << " ; ";
                    }
                }
            }
        }

        cout << "couleur joueur adverse" << couleurJoueurAdverse;

        cout << nbJetonAdverseAlentour;

        if(nbJetonAdverseAlentour>=1) {
            cout << "le coup peut etre joue" << endl;
            return true;
        }
        else {
            cout << "vous ne pouvez pas jouer ce coup, il n'y a aucun jeton adverse aux alentours" << endl;
            return false;
        }
    }
}

void placerJetonTour(Jeu *jeu, Joueur *joueur, bool joueurCourant) {

    char couleurJoueurAdverse, couleurJoueur;
    if(joueurCourant == true){
        couleurJoueurAdverse = 'B';
        couleurJoueur = 'N';
    }
    else{
        couleurJoueurAdverse = 'N';
        couleurJoueur = 'B';
    }

    cout << couleurJoueurAdverse;

    int rowNewJeton, columnNewJeton;

    cout << "C'est au tour de " << joueur->nom <<endl;
    cout << "quelle case voulez vous prendre ?" << endl;
    cout << "ligne : ";
    cin >> rowNewJeton;

    cout << "colonne : ";
    cin >> columnNewJeton;

    bool possibleOuPas = possibleJouerTour(jeu, joueur, couleurJoueurAdverse, rowNewJeton, columnNewJeton);
    if (possibleOuPas == true) {
        cout << "il faut placer le jeton !" << endl;
        // joueur->jetons = (Jeton*) malloc (sizeof(Jeton)*1);
        // int coordonneesJeton[2]={rowNewJeton,columnNewJeton};
        // ajouterJeton(&joueur->jetons[3], joueur->jetons[0].couleur[1], coordonneesJeton);
        jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur=couleurJoueur;
        joueur->nbJetonsActuels++;
        joueur->jetons--;
        cout << endl << joueurCourant << endl;
    }
    else if (possibleOuPas == false) {
        placerJetonTour(jeu, joueur, joueurCourant);
    }
}

void PartieDeJeu(Jeu *jeu) {
    bool joueurCourant = true;
    int nbJetonsPoses = jeu->joueur1->jetons+jeu->joueur2->jetons;

    while (nbJetonsPoses>0) {
        if(joueurCourant==true){
            placerJetonTour(jeu, jeu->joueur1, joueurCourant);
            joueurCourant=!joueurCourant;
        }
        else{
            placerJetonTour(jeu, jeu->joueur2, joueurCourant);
            joueurCourant=!joueurCourant;
        }
        affichePlateauJeu(jeu);
    }
}

int main() {

    Joueur* joueur1 = (Joueur*)malloc(25*sizeof(char) + 2*sizeof(int));
    Joueur* joueur2 = (Joueur*)malloc(25*sizeof(char) + 2*sizeof(int));
    
    Jeu* plateauJeuTest = (Jeu*)malloc(64*sizeof(Jeton) + 2 *sizeof(Joueur));

    initialiseJoueur(joueur1,1);
    afficheJoueur(joueur1);
    initialiseJoueur(joueur2,2);
    afficheJoueur(joueur2);

    initialiseJeu(plateauJeuTest, joueur1, joueur2);
    // cout << plateauJeuTest->tableauPointeurJetons[4][4]->couleur;
    affichePlateauJeu(plateauJeuTest);

    // placerJetonTour(plateauJeuTest, plateauJeuTest->joueur1, moduloAlternanceJoueur);

    PartieDeJeu(plateauJeuTest);

    afficheJoueur(joueur2);

    afficheJoueur(joueur1);

    return 0;
}

    
    

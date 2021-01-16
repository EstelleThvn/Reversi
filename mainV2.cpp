#include <iostream>
using namespace std;

const int MAXJETONS = 64;

struct Jeton {
char couleur[1];
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
Jeton* tableauPointeurJetons[8][8];
};


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
        int color = 'B';
        ajouterJeton(&joueur->jetons[0], color, coordonneesJeton1);
        ajouterJeton(&joueur->jetons[1], color, coordonneesJeton2);
    }

    else if(n==2){
        int coordonneesJeton1[2]={4,5};
        int coordonneesJeton2[2]={5,4};
        int color = 'W';
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
    cout << "Couleur : " << jeton.couleur[1] << endl;

    cout << "coordonnees : ";
    for(int i=0; i<2; i++){
        cout << jeton.coordonnees[i] << " ";
    }
    cout << endl;
}

void initialiseJeu(Jeu *jeu, Joueur *joueur1, Joueur *joueur2) {
    jeu->joueur1=joueur1;
    jeu->joueur2=joueur2;

    Joueur *joueurTotalTemp = new Joueur;
    joueurTotalTemp->nbJetonsActuels = joueur1->nbJetonsActuels + joueur2->nbJetonsActuels;
    // cout << joueurTotalTemp->nbJetonsActuels;

    joueurTotalTemp->jetons = (Jeton*) malloc (sizeof(Jeton)*joueurTotalTemp->nbJetonsActuels);

    int compteurTemp;
    for(compteurTemp=0; compteurTemp<joueur1->nbJetonsActuels;compteurTemp++) {
        joueurTotalTemp->jetons[compteurTemp]=joueur1->jetons[compteurTemp];
    }
    int compteurTempAprJ1 = compteurTemp;
    for(compteurTemp=0; compteurTemp<joueur2->nbJetonsActuels;compteurTemp++) {
        joueurTotalTemp->jetons[compteurTempAprJ1]=joueur2->jetons[compteurTemp];
        compteurTempAprJ1++;
    }

    // for(int a=0; a<joueurTotalTemp->nbJetonsActuels ; a++){
    //     cout << joueurTotalTemp->jetons[a].couleur[1] << endl;
    // }

    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
            for(int k=0; k<joueurTotalTemp->nbJetonsActuels ; k++) {
                if(i==joueurTotalTemp->jetons[k].coordonnees[0] && j==joueurTotalTemp->jetons[k].coordonnees[1]) {
                    //si le jeton avec ces coordonnees existe, pointer sur lui
                    jeu->tableauPointeurJetons[i][j]=&joueurTotalTemp->jetons[k];
                    break;
                }
                else {
                    jeu->tableauPointeurJetons[i][j] = NULL;
                }
            }
        }
    }

}

void affichePlateauJeu(Jeu *jeu) {
    // char couleurJeton; 
    cout << endl << endl;
    cout<<"    1   2   3   4   5   6   7   8  "<<endl; 
    for(int i=1;i<=8;i++) { 
        cout<<"  +---+---+---+---+---+---+---+---+"<<endl; 
        cout<<i<<" | ";
        for(int j=1;j<=8;j++) {
            if(jeu->tableauPointeurJetons[i][j]==NULL){
                cout<<" "<<" | ";
            }
            else {
                // cout<<jeu->tableauPointeurJetons[i][j]->couleur[1]<<" | ";
                cout<<jeu->tableauPointeurJetons[i][j]->couleur[1]<<" | ";
            }
        }
        cout<<endl; 
    } 
    cout<<"  +---+---+---+---+---+---+---+---+"<<endl; 

    // cout << jeu->tableauPointeurJetons[4][4]<<endl;
    // cout << jeu->tableauPointeurJetons[4][4]->couleur[1]<<endl;
}

// void isJetonAdverseAlentour(Jeu *jeu, int coordonneesJeton) {
// }

void jouerTour(Jeu *jeu, Joueur *joueur) {
    int rowNewJeton, columnNewJeton;

    char couleurJoueurAdverse[1];
    if(joueur->jetons[0].couleur[1]=='B'){
        couleurJoueurAdverse[1] = 'W';
    }
    else{
        couleurJoueurAdverse[1] = 'B';
    }

    cout << couleurJoueurAdverse[1];


    cout << "C'est au tour de " << joueur->nom <<endl;
    cout << "quelle case voulez vous prendre ?" << endl;
    cout << "ligne : ";
    cin >> rowNewJeton;

    cout << "colonne : ";
    cin >> columnNewJeton;

    // cout << coordonneesNewJeton[0]-1;

    int nbJetonAdverseAlentour = 0;

    cout << columnNewJeton;

    cout << jeu->tableauPointeurJetons[4][5]->couleur[1];
    cout << couleurJoueurAdverse[1];

    if (jeu->tableauPointeurJetons[4][5]->couleur[1]==couleurJoueurAdverse[1]){
        cout << endl << "ca marche" << endl;
    }

    for(int i=rowNewJeton-1;i<=rowNewJeton+1;i++) {
        for(int j=columnNewJeton-1;j<=columnNewJeton+1;j++) {
            if(jeu->tableauPointeurJetons[i][j]!=NULL) {
                if(jeu->tableauPointeurJetons[i][j]->couleur[1]==couleurJoueurAdverse[1]) {
                    nbJetonAdverseAlentour++;
                    break;
                }
            }
            cout << i << " " << j << " ; ";
        }
    }

    cout << nbJetonAdverseAlentour;

    if(nbJetonAdverseAlentour>=1) {
        cout << "le coup peut etre joue" << endl;
    }
    else {
        cout << "vous ne pouvez pas jouer ce coup, il n'y a aucun jeton adverse aux alentours" << endl;
    }

    
}

int main() {

    Joueur joueur1, joueur2;

    Jeu plateauJeuTest;

    initialiseJoueur(&joueur1,1);
    afficheJoueur(joueur1);
    initialiseJoueur(&joueur2,2);
    afficheJoueur(joueur2);

    initialiseJeu(&plateauJeuTest, &joueur1, &joueur2);
    affichePlateauJeu(&plateauJeuTest);

    jouerTour(&plateauJeuTest, &joueur1);

    return 0;
}
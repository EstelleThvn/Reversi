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

void afficheJoueur(Joueur *joueur) {
    cout << joueur->nom << " possede " << joueur->nbJetonsActuels << " jetons " << endl;
}

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

bool possibleJouerTourCaseDispo(Jeu *jeu, Joueur *joueur, int rowNewJeton, int columnNewJeton){
    if (jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur!=' '){
        cout << "vous ne pouvez pas jouer ce coup, la case est deja prise" << endl;
        return false;
    }
    else{
        return true;
    }
}

bool possibleJouerTourCondition1(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, int rowNewJeton, int columnNewJeton) {

        int nbJetonAdverseAlentour = 0;

        for(int i=rowNewJeton-1;i<=rowNewJeton+1;i++) {
            if(i>=1 && i<=8){
                for(int j=columnNewJeton-1;j<=columnNewJeton+1;j++) {
                    if(j>=1 && j<=8){
                        if(jeu->tableauPointeurJetons[i][j]!=NULL && jeu->tableauPointeurJetons[i][j]->couleur==couleurJoueurAdverse) {
                                nbJetonAdverseAlentour++;
                        }
                    }
                }
            }
        }

        // cout << "couleur joueur adverse" << couleurJoueurAdverse;

        // cout << nbJetonAdverseAlentour;

        if(nbJetonAdverseAlentour>=1) {
            // cout << "le coup peut etre joue" << endl;
            return true;
        }
        else {
            cout << "vous ne pouvez pas jouer ce coup, il n'y a aucun jeton adverse aux alentours" << endl;
            return false;
        }
}

int getLigne(){
    bool vrai = true;
    int rowNewJeton;
    while(vrai) {
        cout << "ligne : ";
        cin >> rowNewJeton;

        if (rowNewJeton>=1 && rowNewJeton<=8) {
            vrai = false;
        }
        else {
            cout << "valeur incorrecte reessayez, rentrez un nombre entre 1 et 8" << endl;
            cin.clear();
            fflush(stdin);
        }
    }

    return rowNewJeton;
}

int getColonne(){
    bool vrai = true;
    int columnNewJeton;
    while(vrai) {
        cout << "colonne : ";
        cin >> columnNewJeton;

        if (columnNewJeton>=1 && columnNewJeton<=8) {
            vrai = false;
        }
        else {
            cout << "valeur incorrecte, rentrez un nombre entre 1 et 8" << endl;
            cin.clear();
            fflush(stdin);
        }
    }

    return columnNewJeton;
}

//on pose un jeton et on alterne le joueur si toutes les conditions sont réunis, sinon on ne fait rien et on alterne pas de joueur
bool jouerUnTour(Jeu *jeu, Joueur *joueur, bool joueurCourant) {

    char couleurJoueurAdverse, couleurJoueur;
    if(joueurCourant == true){
        couleurJoueurAdverse = 'B';
        couleurJoueur = 'N';
    }
    else{
        couleurJoueurAdverse = 'N';
        couleurJoueur = 'B';
    }

    cout << "C'est au tour de " << joueur->nom << " (jetons " << couleurJoueur << ")" << endl;
    cout << "quelle case voulez vous prendre ?" << endl;

    int ligne = getLigne();
    int colonne = getColonne();


    bool PoseJetonPossibleOuPas = possibleJouerTourCaseDispo(jeu, joueur, ligne, colonne);
    if(PoseJetonPossibleOuPas == true){
        PoseJetonPossibleOuPas = possibleJouerTourCondition1(jeu, joueur, couleurJoueurAdverse, ligne, colonne);

        if(PoseJetonPossibleOuPas == true) {
            jeu->tableauPointeurJetons[ligne][colonne]->couleur=couleurJoueur;
            joueur->nbJetonsActuels++;
            joueur->jetons--;
            cout << joueurCourant << endl;
            joueurCourant=!joueurCourant;
            cout << joueurCourant << endl;

            afficheJoueur(jeu->joueur1);
            afficheJoueur(jeu->joueur2);
            affichePlateauJeu(jeu);
        }
    }

    return joueurCourant;
}

void PartieDeJeu(Jeu *jeu) {
    bool joueurCourant = true;
    int nbJetonsPoses = jeu->joueur1->jetons+jeu->joueur2->jetons;

    while (nbJetonsPoses>0) {
        if(joueurCourant==true){
            joueurCourant = jouerUnTour(jeu, jeu->joueur1, joueurCourant);
        }
        else{
            joueurCourant = jouerUnTour(jeu, jeu->joueur2, joueurCourant);
        }
        
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
    affichePlateauJeu(plateauJeuTest);

    PartieDeJeu(plateauJeuTest);

    return 0;
}
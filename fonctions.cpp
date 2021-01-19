#include <iostream>
using namespace std;
#include "fonctions.h"

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

//vérifie que la case que l'utilisateur veut prendre est bien disponible et pas déjà occupée par un autre pion
bool possibleJouerTourCaseDispo(Jeu *jeu, Joueur *joueur, int rowNewJeton, int columnNewJeton){
    if (jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur!=' '){
        cout << "vous ne pouvez pas jouer ce coup, la case est deja prise" << endl;
        return false;
    }
    else{
        return true;
    }
}

//Vérifie que le pion est bien à côté d'un pion adverse
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

//vérifie que le joueur peut capturer au moins un jeton adverse
bool possibleJouerTourCondition2(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton){
    //vérifier si dans au moins une direction, il y a au moins un jetons adverse à la case suivante (ou plusieurs à la suite) et un autre jeton de la couleur du joueur

    int i = rowNewJeton;
    int j = columnNewJeton;
    int nbDeplacementDirection = 0;

    bool continuerDeplacement = true;

    bool cestPossible = false;

    // cout << continuerDeplacement << endl;

    // cout << i << j << jeu->tableauPointeurJetons[i+1][j]->couleur << couleurJoueurAdverse << endl;

    int changementDirection = 0;

    //ordre des directions :
    // droite
    // gauche
    // bas
    // haut
    // bas droite
    // bas gauche
    // haut droite
    // haut gauche
    int infosDirections[8][2]={
        {0,1},
        {0,-1},
        {1,0},
        {-1,0},
        {1,1},
        {1,-1},
        {-1,1},
        {-1,-1},

    };

    while(changementDirection<8 && cestPossible == false ){
        while(j>=1 && j<=8 && i>=1 && i<=8 && continuerDeplacement == true){

            nbDeplacementDirection++;

            i = i+infosDirections[changementDirection][0];
            j = j+infosDirections[changementDirection][1];
            
            //si on se retrouve avec des i ou j égaux à 0 ou à 9, c'est que c'est pas la bonne direction du tableau, donc on sort du while et on change de direction 
            if(i==0 || i==9 || j==0 || j==9){
                break;
            }

            cout << "direction : " << changementDirection << endl;
            cout << "i : " << i << endl;
            cout << "j : " << j << endl;
            cout << nbDeplacementDirection << endl;
            

            if(nbDeplacementDirection == 1){
                if(jeu->tableauPointeurJetons[i][j]->couleur==couleurJoueurAdverse){
                    continuerDeplacement = true;
                }
                else{
                    continuerDeplacement = false;
                }
            }
            else{
                if(jeu->tableauPointeurJetons[i][j]->couleur==couleurJoueurAdverse){
                    continuerDeplacement = true;
                }
                else if(jeu->tableauPointeurJetons[i][j]->couleur==couleurJoueur){
                    cestPossible = true;
                    continuerDeplacement = false;
                }
                else{
                    continuerDeplacement = false;
                }
            }

            if(infosDirections[changementDirection][0]==1){
                if(i==8){
                    continuerDeplacement = false;
                }
            }
            else if(infosDirections[changementDirection][0]==-1){
                if(i==1){
                    continuerDeplacement = false;
                }
            }
            if(infosDirections[changementDirection][1]==1){
                if(j==8){
                    continuerDeplacement = false;
                }
            }
            else if(infosDirections[changementDirection][0]==-1){
                if(j==1){
                    continuerDeplacement = false;
                }
            }

        }

        if(cestPossible == true){
            cout << "direction de la capture : " << changementDirection << endl;
        }

        changementDirection++;
        nbDeplacementDirection = 0;
        i = rowNewJeton;
        j = columnNewJeton;
        continuerDeplacement = true;
        // cout << "direction apres changement : " << changementDirection << endl;
        // cout << "cest possible : " << cestPossible << endl;
        // cout << "i : " << i << endl;
        // cout << "j : " << j << endl;
        // cout << nbDeplacementDirection << endl;
        // cout << "continuer deplacement : " << continuerDeplacement << endl;

    }

    if(cestPossible == true){
        return true;
    }
    else {
        cout << "vous ne pouvez pas jouer ce coup, vous ne pouvez pas capturer de pion adverse" << endl;
        return false;
    }
}

//Récupère la ligne où l'utilisateur veut poser son pion, et vérifie que c'est une case qui existe
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

//Récupère la colonne où l'utilisateur veut poser son pion, et vérifie que c'est une case qui existe
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

//capture les jetons de l'adversaire quand toutes les conditions sont remplis
void capturePionsAdverses(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton){

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
            PoseJetonPossibleOuPas = possibleJouerTourCondition2(jeu, joueur, couleurJoueurAdverse, couleurJoueur, ligne, colonne);

            if(PoseJetonPossibleOuPas == true){
                jeu->tableauPointeurJetons[ligne][colonne]->couleur=couleurJoueur;
                joueur->nbJetonsActuels++;
                joueur->jetons--;
                // cout << joueurCourant << endl;
                joueurCourant=!joueurCourant;
                // cout << joueurCourant << endl;

                afficheJoueur(jeu->joueur1);
                afficheJoueur(jeu->joueur2);
                affichePlateauJeu(jeu);

            }
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
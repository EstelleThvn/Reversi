#include <iostream>
using namespace std;
#include "main.h"
#include "initetaffichage.h"
#include "partie.h"
#include "tour.h"

//on pose un jeton et on alterne le joueur si toutes les conditions sont réunies, sinon on ne fait rien et on alterne pas de joueur
bool jouerUnTour(Jeu *jeu, Joueur *joueur, bool joueurCourant, int* nbToursLoupesConsecutifs) {

    char couleurJoueurAdverse, couleurJoueur;
    if(joueurCourant == true){
        couleurJoueurAdverse = 'B';
        couleurJoueur = 'N';
    }
    else{
        couleurJoueurAdverse = 'N';
        couleurJoueur = 'B';
    }

    cout << endl << "C'est au tour de " << joueur->nom << " (jetons " << couleurJoueur << ")" << endl;

    //on affiche les cases jouables par le joueur courant s'il y en a, sinon on finit le tour et on change de joueur
    bool tourJoueurValide = casesDisposTour(jeu, joueur, couleurJoueurAdverse, couleurJoueur, joueurCourant);


    if(tourJoueurValide == false){
        cout << "Vous n'avez aucun coup possible, vous devez passer votre tour " << joueur->nom << endl;

        *nbToursLoupesConsecutifs = *nbToursLoupesConsecutifs+1;

        joueurCourant=!joueurCourant;
    }
    else{
        //si le tour est valide, on affiche le plateau avec les cases jouables et on demande au joueur la case qu'il veut jouer

        affichePlateauJeu(jeu);

        cout << "Quelle case voulez-vous prendre ?" << endl;

        int ligne = getLigne();
        int colonne = getColonne();


        bool PoseJetonPossibleOuPas = possibleJouerTourCaseDispo(jeu, joueur, ligne, colonne);

        if(PoseJetonPossibleOuPas == true){
            PoseJetonPossibleOuPas = possibleJouerTourCondition1(jeu, joueur, couleurJoueurAdverse, ligne, colonne);

            if(PoseJetonPossibleOuPas == true) {
                PoseJetonPossibleOuPas = possibleJouerTourCondition2(jeu, joueur, couleurJoueurAdverse, couleurJoueur, ligne, colonne);

                if(PoseJetonPossibleOuPas == true){
                    // si toutes les conditions pour poser le jetons sont ok, on pose le jetons, change le nombre de jeton du joueur et on capture les jetons adverses à capturer, et on change de joueur.

                    jeu->tableauPointeurJetons[ligne][colonne]->couleur=couleurJoueur;
                    joueur->nbJetonsActuels++;
                    joueur->jetons--;

                    capturePionsAdverses(jeu, joueur, couleurJoueurAdverse, couleurJoueur, ligne, colonne, joueurCourant);


                    joueurCourant=!joueurCourant;
                    *nbToursLoupesConsecutifs = 0;


                    cout << endl;
                    afficheJoueur(jeu->joueur1);
                    afficheJoueur(jeu->joueur2);
                    // affichePlateauJeu(jeu);

                }
                else{
                    cout << "Vous ne pouvez pas jouer ce coup, vous ne pouvez pas capturer de pion adverse" << endl;
                }
            }
            else {
                cout << "Vous ne pouvez pas jouer ce coup, il n'y a aucun jeton adverse aux alentours" << endl;
            }
        }
        else{
            cout << "Vous ne pouvez pas jouer ce coup, la case est deja prise" << endl;
        }

    }

    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
            if(jeu->tableauPointeurJetons[i][j]->couleur=='.'){
                jeu->tableauPointeurJetons[i][j]->couleur = ' ';
            } 
        }
    }

    return joueurCourant;
}


//vérifie que la case que l'utilisateur veut prendre est bien disponible et pas déjà occupée par un autre pion
bool possibleJouerTourCaseDispo(Jeu *jeu, Joueur *joueur, int rowNewJeton, int columnNewJeton){
    if (jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur==' ' || jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur=='.'){
        return true;
    }
    else{
        return false;
    }
}

//Vérifie que le jeton est bien à côté d'un jeton adverse
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

        if(nbJetonAdverseAlentour>=1) {
            // cout << "le coup peut etre joue" << endl;
            return true;
        }
        else {
            return false;
        }
}

//vérifie que le joueur peut capturer au moins un jeton adverse
bool possibleJouerTourCondition2(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton){
    //vérifie dans au moins une direction, il y a au moins un jeton adverse à la case suivante (ou plusieurs à la suite) et un autre jeton de la couleur du joueur

    int i = rowNewJeton;
    int j = columnNewJeton;
    int nbDeplacementDirection = 0;

    bool continuerDeplacement = true;

    bool cestPossible = false;


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
            else if(infosDirections[changementDirection][1]==-1){
                if(j==1){
                    continuerDeplacement = false;
                }
            }

        }

        changementDirection++;
        nbDeplacementDirection = 0;
        i = rowNewJeton;
        j = columnNewJeton;
        continuerDeplacement = true;

    }

    //si cestPossible = true, c'est qu'il y a au moins une direction de capture faisable
    if(cestPossible == true){
        return true;
    }
    else {
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
            cout << "Valeur incorrecte, rentrez un nombre entre 1 et 8" << endl;
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
            cout << "Valeur incorrecte, rentrez un nombre entre 1 et 8" << endl;
            cin.clear();
            fflush(stdin);
        }
    }

    return columnNewJeton;
}

//capture les jetons de l'adversaire quand toutes les conditions sont remplies
//ressemble à la fonction condition 2, sauf que là on vérifie toutes les directions où on peut capturer, on ne s'arrête pas à la premiere direction possible
void capturePionsAdverses(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton, bool joueurCourant){
    int i = rowNewJeton;
    int j = columnNewJeton;
    int nbDeplacementDirection = 0;

    bool continuerDeplacement = true;

    bool cestPossible = false;

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

    while(changementDirection<8){
        while(j>=1 && j<=8 && i>=1 && i<=8 && continuerDeplacement == true){

            nbDeplacementDirection++;

            i = i+infosDirections[changementDirection][0];
            j = j+infosDirections[changementDirection][1];
            
            //si on se retrouve avec des i ou j égaux à 0 ou à 9, c'est que c'est pas la bonne direction du tableau, donc on sort du while et on change de direction 
            if(i==0 || i==9 || j==0 || j==9){
                break;
            }
            

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
            else if(infosDirections[changementDirection][1]==-1){
                if(j==1){
                    continuerDeplacement = false;
                }
            }

        }

        i = rowNewJeton;
        j = columnNewJeton;

        if(cestPossible == true){

            i = i+infosDirections[changementDirection][0];
            j = j+infosDirections[changementDirection][1];

            while(jeu->tableauPointeurJetons[i][j]->couleur==couleurJoueurAdverse){
                jeu->tableauPointeurJetons[i][j]->couleur=couleurJoueur;
                joueur->jetons--;
                joueur->nbJetonsActuels++;
                if(joueurCourant == true){
                    jeu->joueur2->nbJetonsActuels--;
                    jeu->joueur2->jetons++;
                }
                else{
                    jeu->joueur1->nbJetonsActuels--;
                    jeu->joueur1->jetons++;
                }

                i = i+infosDirections[changementDirection][0];
                j = j+infosDirections[changementDirection][1];
            }
        }

        i = rowNewJeton;
        j = columnNewJeton;
        changementDirection++;
        nbDeplacementDirection = 0;

        //permet de continuer de vérifier les directions suivantes
        continuerDeplacement = true;
        cestPossible = false;

    }
}





// indique la position des jetons qui sont jouables par le joueur lors de son tour, si c'est possible
bool casesDisposTour(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, bool joueurCourant){

    bool CaseDispoExiste = false;

    // cout << "CASES JOUABLES : " << endl;

    for(int i=1;i<=8;i++) {
        for(int j=1;j<=8;j++) {
            bool PoseJetonPossibleOuPas = possibleJouerTourCaseDispo(jeu, joueur, i, j);

            if(PoseJetonPossibleOuPas == true){
                PoseJetonPossibleOuPas = possibleJouerTourCondition1(jeu, joueur, couleurJoueurAdverse, i, j);

                if(PoseJetonPossibleOuPas == true) {
                    PoseJetonPossibleOuPas = possibleJouerTourCondition2(jeu, joueur, couleurJoueurAdverse, couleurJoueur, i, j);

                    if(PoseJetonPossibleOuPas == true){
                        
                        jeu->tableauPointeurJetons[i][j]->couleur='.';

                        // cout << i << " ; " << j << endl;


                        CaseDispoExiste = true;
                    }
                }
            }
        }
    }

    return CaseDispoExiste;
}
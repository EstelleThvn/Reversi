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
    // if (jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur!=' '){
    //     return false;
    // }
    // else{
    //     return true;
    // }
    if (jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur==' ' || jeu->tableauPointeurJetons[rowNewJeton][columnNewJeton]->couleur=='.'){
        return true;
    }
    else{
        return false;
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

            // cout << "direction : " << changementDirection << endl;
            // cout << "i : " << i << endl;
            // cout << "j : " << j << endl;
            // cout << nbDeplacementDirection << endl;
            

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

        // if(cestPossible == true){
        //     cout << "direction de la capture : " << changementDirection << endl;
        // }

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

//capture les jetons de l'adversaire quand toutes les conditions sont remplis
void capturePionsAdverses(Jeu *jeu, Joueur *joueur, char couleurJoueurAdverse, char couleurJoueur, int rowNewJeton, int columnNewJeton, bool joueurCourant){
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

    while(changementDirection<8){
        while(j>=1 && j<=8 && i>=1 && i<=8 && continuerDeplacement == true){

            nbDeplacementDirection++;

            i = i+infosDirections[changementDirection][0];
            j = j+infosDirections[changementDirection][1];
            
            //si on se retrouve avec des i ou j égaux à 0 ou à 9, c'est que c'est pas la bonne direction du tableau, donc on sort du while et on change de direction 
            if(i==0 || i==9 || j==0 || j==9){
                break;
            }

            // cout << "direction : " << changementDirection << endl;
            // cout << "i : " << i << endl;
            // cout << "j : " << j << endl;
            // cout << nbDeplacementDirection << endl;
            

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
            // cout << "direction de la capture : " << changementDirection << endl;

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
        continuerDeplacement = true;
        cestPossible = false;
        // cout << "direction apres changement : " << changementDirection << endl;
        // cout << "cest possible : " << cestPossible << endl;
        // cout << "i : " << i << endl;
        // cout << "j : " << j << endl;
        // cout << nbDeplacementDirection << endl;
        // cout << "continuer deplacement : " << continuerDeplacement << endl;

    }
}

//on pose un jeton et on alterne le joueur si toutes les conditions sont réunis, sinon on ne fait rien et on alterne pas de joueur
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

    //assistance : afficher les cases jouables par le joueur courant s'il y en a, sinon finir le tour
    bool tourJoueurValide = casesDisposTour(jeu, joueur, couleurJoueurAdverse, couleurJoueur, joueurCourant);

    // cout << "est-ce que le tour est valide : " << tourJoueurValide << endl;

    if(tourJoueurValide == false){
        cout << "Vous n'avez aucun coup possible, vous devez passer votre tour " << joueur->nom << endl;

        // cout << endl << "NB TOUR CONSEC : " << *nbToursLoupesConsecutifs << endl;
        *nbToursLoupesConsecutifs = *nbToursLoupesConsecutifs+1;

        joueurCourant=!joueurCourant;
    }
    else{
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

void regleDuJeu(){
    cout << endl << "JEU DE REVERSI" << endl;
    cout << "Vous allez devoir jouer tour a tour en posant un jeton sur le plateau de jeu : un joueur possede les jetons noirs 'N', l'autre les jetons blancs 'B'." << endl << "Les cases disponibles lors de votre tour sont indiquees par un point '.'." << endl << endl;
}

void PartieDeJeu(Jeu *jeu) {

    bool joueurCourant = true;
    int nbJetonsPoses = jeu->joueur1->nbJetonsActuels + jeu->joueur2->nbJetonsActuels;
    int nbToursLoupesConsecutifs = 0;


    // jeu->tableauPointeurJetons[1][1]->couleur='B';
    // // jeu->tableauPointeurJetons[1][2]->couleur='B';
    // jeu->tableauPointeurJetons[1][3]->couleur='N';
    // jeu->tableauPointeurJetons[1][4]->couleur='N';
    // jeu->tableauPointeurJetons[1][5]->couleur='N';
    // jeu->tableauPointeurJetons[1][6]->couleur='N';
    // jeu->tableauPointeurJetons[1][7]->couleur='N';
    // jeu->tableauPointeurJetons[1][8]->couleur='N';
    // jeu->tableauPointeurJetons[2][1]->couleur='B';
    // jeu->tableauPointeurJetons[2][2]->couleur='B';
    // jeu->tableauPointeurJetons[2][3]->couleur='N';
    // jeu->tableauPointeurJetons[2][4]->couleur='N';
    // jeu->tableauPointeurJetons[2][5]->couleur='N';
    // jeu->tableauPointeurJetons[2][6]->couleur='N';
    // jeu->tableauPointeurJetons[2][7]->couleur='N';
    // jeu->tableauPointeurJetons[2][8]->couleur='N';
    // jeu->tableauPointeurJetons[3][1]->couleur='B';
    // jeu->tableauPointeurJetons[3][2]->couleur='B';
    // jeu->tableauPointeurJetons[3][3]->couleur='B';
    // jeu->tableauPointeurJetons[3][4]->couleur='N';
    // jeu->tableauPointeurJetons[3][5]->couleur='N';
    // jeu->tableauPointeurJetons[3][6]->couleur='N';
    // jeu->tableauPointeurJetons[3][7]->couleur='N';
    // jeu->tableauPointeurJetons[3][8]->couleur='N';
    // jeu->tableauPointeurJetons[4][1]->couleur='B';
    // jeu->tableauPointeurJetons[4][2]->couleur='B';
    // jeu->tableauPointeurJetons[4][3]->couleur='N';
    // jeu->tableauPointeurJetons[4][4]->couleur='B';
    // jeu->tableauPointeurJetons[4][5]->couleur='N';
    // jeu->tableauPointeurJetons[4][6]->couleur='N';
    // jeu->tableauPointeurJetons[4][7]->couleur='N';
    // jeu->tableauPointeurJetons[4][8]->couleur='N';
    // jeu->tableauPointeurJetons[5][1]->couleur='B';
    // jeu->tableauPointeurJetons[5][2]->couleur='B';
    // jeu->tableauPointeurJetons[5][3]->couleur='B';
    // jeu->tableauPointeurJetons[5][4]->couleur='N';
    // jeu->tableauPointeurJetons[5][5]->couleur='B';
    // jeu->tableauPointeurJetons[5][6]->couleur='N';
    // jeu->tableauPointeurJetons[5][7]->couleur='N';
    // jeu->tableauPointeurJetons[5][8]->couleur='N';
    // jeu->tableauPointeurJetons[6][1]->couleur='B';
    // jeu->tableauPointeurJetons[6][2]->couleur='B';
    // jeu->tableauPointeurJetons[6][3]->couleur='N';
    // jeu->tableauPointeurJetons[6][4]->couleur='B';
    // jeu->tableauPointeurJetons[6][5]->couleur='N';
    // jeu->tableauPointeurJetons[6][6]->couleur='B';
    // jeu->tableauPointeurJetons[6][7]->couleur='N';
    // jeu->tableauPointeurJetons[6][8]->couleur='N';
    // jeu->tableauPointeurJetons[7][1]->couleur='B';
    // jeu->tableauPointeurJetons[7][2]->couleur='B';
    // jeu->tableauPointeurJetons[7][3]->couleur='N';
    // jeu->tableauPointeurJetons[7][4]->couleur='N';
    // jeu->tableauPointeurJetons[7][5]->couleur='B';
    // jeu->tableauPointeurJetons[7][6]->couleur='N';
    // jeu->tableauPointeurJetons[7][7]->couleur='B';
    // jeu->tableauPointeurJetons[7][8]->couleur='N';
    // jeu->tableauPointeurJetons[8][1]->couleur='B';
    // jeu->tableauPointeurJetons[8][2]->couleur='B';
    // jeu->tableauPointeurJetons[8][3]->couleur='B';
    // jeu->tableauPointeurJetons[8][4]->couleur='B';
    // jeu->tableauPointeurJetons[8][5]->couleur='B';
    // jeu->tableauPointeurJetons[8][6]->couleur='B';
    // jeu->tableauPointeurJetons[8][7]->couleur='B';
    // jeu->tableauPointeurJetons[8][8]->couleur='B';

    // jeu->joueur1->nbJetonsActuels= 34;
    // jeu->joueur2->nbJetonsActuels= 29;

    // cout << "IL FAUT AFFICHER LE PLATEAU REMPLIE" << endl;
    // affichePlateauJeu(jeu);

    // jeu->tableauPointeurJetons[3][4]->couleur='N';
    // jeu->tableauPointeurJetons[4][3]->couleur='N';
    // jeu->tableauPointeurJetons[4][4]->couleur='N';
    // jeu->tableauPointeurJetons[4][5]->couleur='N';
    // jeu->tableauPointeurJetons[5][1]->couleur='N';
    // jeu->tableauPointeurJetons[5][2]->couleur='N';
    // jeu->tableauPointeurJetons[5][3]->couleur='N';
    // jeu->tableauPointeurJetons[5][4]->couleur='N';
    // jeu->tableauPointeurJetons[5][5]->couleur='N';
    // jeu->tableauPointeurJetons[5][6]->couleur='N';
    // jeu->tableauPointeurJetons[6][2]->couleur='N';
    // jeu->tableauPointeurJetons[6][3]->couleur='N';
    // jeu->tableauPointeurJetons[6][4]->couleur='N';
    // jeu->tableauPointeurJetons[7][1]->couleur='B';
    // jeu->tableauPointeurJetons[7][2]->couleur='B';
    // jeu->tableauPointeurJetons[7][3]->couleur='N';
    // jeu->tableauPointeurJetons[7][4]->couleur='N';
    // jeu->tableauPointeurJetons[7][5]->couleur='N';
    // jeu->tableauPointeurJetons[8][1]->couleur='B';
    // jeu->tableauPointeurJetons[8][2]->couleur='B';
    // jeu->tableauPointeurJetons[8][3]->couleur='B';
    // jeu->tableauPointeurJetons[8][4]->couleur='N';

    // jeu->joueur1->nbJetonsActuels= 17;
    // jeu->joueur2->nbJetonsActuels= 5;

    // cout << "IL FAUT AFFICHER LE PLATEAU REMPLIE" << endl;
    // affichePlateauJeu(jeu);



    while (nbJetonsPoses<64 && nbToursLoupesConsecutifs<2) {
        if(joueurCourant==true){
            joueurCourant = jouerUnTour(jeu, jeu->joueur1, joueurCourant, &nbToursLoupesConsecutifs);
        }
        else{
            joueurCourant = jouerUnTour(jeu, jeu->joueur2, joueurCourant, &nbToursLoupesConsecutifs);
        }

        nbJetonsPoses = jeu->joueur1->nbJetonsActuels + jeu->joueur2->nbJetonsActuels;
        
        // cout << endl << jeu->joueur1->nbJetonsActuels << endl;
        // cout << endl << jeu->joueur2->nbJetonsActuels << endl;
        // cout << endl << "jetons sur le plateau : " << nbJetonsPoses << endl << endl;

        // cout << endl << "NOMBRE DE TOURS CONSECUTIFS LOUPES " << nbToursLoupesConsecutifs << endl;
    }

    affichePlateauJeu(jeu);

    if(nbToursLoupesConsecutifs==2){
        cout << "Plus aucun joueur ne peut poser de jeton " << endl << endl;
    }

    // cout << nbJetonsPoses;

    finDePartie(jeu);

}

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
                        
                        // cout << "IL FAUT MODIFIER LA COULEUR DE LA CASE " << i << j << endl;
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
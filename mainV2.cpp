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
int tableauPointeurJetons[8][8];
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

    jeu->tableauPointeurJetons;
    // for(int i=0 ; i<8 ; i++) { 
    //     for(int j=0 ; j<8 ; j++) { 
    //         if(joueur->coordonnees[0]==jeu->tableauPointeurJetons[i][] && joueur->coordonnees[1]==jeu->tableauPointeurJetons[][j]){
    //             jeu->tableauPointeurJetons[i][j]=
    //         }
    //         j++;
    //     }
    //     i++;
    // } 
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

int main() {

    Joueur joueur1, joueur2;

    Jeu plateauJeuTest;

    initialiseJoueur(&joueur1,1);
    afficheJoueur(joueur1);
    initialiseJoueur(&joueur2,2);
    afficheJoueur(joueur2);

    affichePlateauJeu(&plateauJeuTest);

    // Jeton jetonTest;
    // int coorJetonTest[2]={4,4};
    // ajouterJeton(&jetonTest, 'B', coorJetonTest);
    // afficheJeton(jetonTest);


    return 0;
}
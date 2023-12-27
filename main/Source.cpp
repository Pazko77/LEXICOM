#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Pile.h"

using namespace std;


// Structure représentant une carte
//struct Carte {
//    char lettre;
//    int points;
//};

// Fonction pour initialiser le jeu de cartes
void initialiserJeu(Item jeu[], int taille) {
    // Définition des points pour chaque lettre
    int points[] = { 10, 2, 8, 6, 10, 2, 4, 8, 10, 6, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 2, 4, 2 };

    // Définition des quantités pour chaque lettre
    int quantites[] = { 2, 2, 2, 2, 5, 1, 2, 2, 4, 1, 1, 2, 1, 3, 2, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1 };

    // Initialisation du jeu de cartes en fonction des quantités
    int index = 0;
    for (int i = 0; i < sizeof(quantites) / sizeof(quantites[0]); ++i) {
        for (int j = 0; j < quantites[i]; ++j) {
            jeu[index].lettre = 'A' + i;
            jeu[index].points = points[i];
            ++index;
        }
    }
}

int main() {
    enum { CARTE_MAX = 51, MAX_MAIN = 10 };
    Item jeuDeCartes[CARTE_MAX];

    // Initialisation du jeu de cartes
    initialiserJeu(jeuDeCartes,CARTE_MAX);

    // Affichage du jeu de cartes
    // std::cout << "Jeu de cartes initialisé :" << std::endl;
    // for (const auto& carte : jeuDeCartes) {
    //     std::cout << "Lettre : " << carte.lettre << ", Points : " << carte.points << std::endl;
    // }

    //Set a random seed
    srand(time(NULL));

	for (int i = 0; i < CARTE_MAX; ++i)
	{
		int index = rand() % CARTE_MAX;
		Item Temp;
		Temp = jeuDeCartes[i];
		jeuDeCartes[i] = jeuDeCartes[index];
		jeuDeCartes[index] = Temp;
	}
    // affichage 

	for (int i = 0; i < CARTE_MAX; ++i) {
        cout<<i<<" - Lettre : "<< jeuDeCartes[i].lettre << " Points : " << jeuDeCartes[i].points << endl;
    }
    
    Pile talon;
    initialiser(talon, CARTE_MAX);
    cout << "empiler";
    for (int i = 0; i < CARTE_MAX; ++i) {
        cout << "Lettre : " << jeuDeCartes[i].lettre << " Points : " << jeuDeCartes[i].points << endl;
        empiler(talon, jeuDeCartes[i]);
    }
    cout << "Depiler";
    for (int i = 0; i < CARTE_MAX; ++i)
    {
        Item objet = depiler(talon);
        cout <<"Lettre : " << objet.lettre << " Points : " << objet.points << endl;
    }

    struct Joueurs {
        enum {JOUEUR1, JOUEUR2};
        Item Carte[MAX_MAIN];
        int point;
    };

    ifstream dico;
    dico.open("ods4.txt");
    if(dico.fail())
		cerr << "Impossible de lire le fichier\n";
    else {
        dico.seekg(0);
        int countmots = 0;
        do {
            char mot[50];
            dico >> mot;
            //Ajouter une fonction pour comparer
            ++countmots;
        } while (!dico.eof());
        cout << countmots << endl;
    }
    dico.close();
    return 0;
}

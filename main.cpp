#include <iostream>
#include <string>
#include "type_def.h"
#include "utilitaires.h"
using namespace std;

int main() {
    cout << "--- Test de creation de personnes ---" << endl;
    
    // 1. On crée deux personnes
    personne* p1 = creerPersonne("Dupont", "Jean", 1990, 0);
    personne* p2 = creerPersonne("Durand", "Marie", 1992, 1);

    // 2. On affiche leur état avant le mariage
    cout << "Avant le mariage :" << endl;
    affichagePersonne(p1);
    affichagePersonne(p2);
    cout << "------------------------------------" << endl;

    // 3. Test de la fonction mariage
    cout << "Celebration du mariage..." << endl;
    mariage(p1, p2);

    // 4. On affiche leur état après le mariage
    cout << "Apres le mariage :" << endl;
    affichagePersonne(p1);
    affichagePersonne(p2);
    
    // Nettoyage de la mémoire (si tes fonctions utilisent 'new')
    delete p1;
    delete p2;

    return 0;
}
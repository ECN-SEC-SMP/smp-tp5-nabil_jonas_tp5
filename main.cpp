#include <iostream>
#include <string>
#include "type_def.h"
#include "utilitaires.h"

using namespace std;

int main() {
    cout << "--- 1. TEST DE CREATION ---" << endl;
    personne* p1 = creerPersonne("Dupont", "Jean", 1960, 1);
    personne* p2 = creerPersonne("Durand", "Marie", 1965, 2);
    personne* enfant1 = creerPersonne("Dupont", "Lucas", 1990, 1);
    personne* enfant2 = creerPersonne("Dupont", "Sophie", 1992, 2);

    // --- ETAPE CRUCIALE : ETABLIR LES LIENS DE PARENTE ---
    // On lie Lucas à ses parents
    enfant1->pere = p1;
    enfant1->mere = p2;
    
    // On lie Sophie à ses parents
    enfant2->pere = p1;
    enfant2->mere = p2;
    // -----------------------------------------------------

    affichagePersonne(p1);
    affichagePersonne(p2);
    cout << "---------------------------\n" << endl;

    cout << "--- 2. TEST DE MARIAGE ---" << endl;
    mariage(p1, p2);
    affichagePersonne(p1);
    cout << "---------------------------\n" << endl;

    cout << "--- 3. TEST D'IDENTITE ET PARENTE ---" << endl;
    
    // Test memePersonne
    if (memePersonne(p1, p1)) {
        cout << "OK : La fonction detecte bien que p1 est la meme personne que p1." << endl;
    }

    // Test Frere/Soeur 
    if (IsFrereSoeur(enfant1, enfant2)) {
        cout << "OK : Lucas et Sophie sont reconnus comme frere/soeur." << endl;
    } else {
        cout << "ERREUR : Lucas et Sophie devraient etre frere/soeur." << endl;
    }
    cout << "---------------------------\n" << endl;

    cout << "--- 4. TEST D'ANCETRE (Recursivite) ---" << endl;
    
    // --- 4. TEST D'ANCETRE ---

    // Test avec le Père : On cherche si p1 est l'ancêtre de enfant1
    if (IsAncetre(enfant1, p1)) { // <--- INVERSION ICI
        cout << "OK : Jean est bien l'ancetre de Lucas." << endl;
    } else {
    cout << "ERREUR : Jean (pere) devrait etre detecte comme ancetre." << endl;
    }

    // Test avec la Mère : On cherche si p2 est l'ancêtre de enfant1
    if (IsAncetre(enfant1, p2)) { // <--- INVERSION ICI
        cout << "OK : Marie est bien l'ancetre de Lucas." << endl;
    } else {
        cout << "INFO : Marie n'est pas detectee comme ancetre." << endl;
    }
    // Nettoyage de la mémoire
    delete p1;
    delete p2;
    delete enfant1;
    delete enfant2;

    return 0;
}
#include "type_def.h"
#include "utilitaires.h"
#include <iostream>

using namespace std;

int main(){
    // --- Création des grands-parents ---
    personne* gp1 = creePersonne("Bernard", "Louis", 1940, 1);
    personne* gm1 = creePersonne("Bernard", "Anne", 1942, 0);
    personne* gp2 = creePersonne("Petit", "Jean", 1938, 1);
    personne* gm2 = creePersonne("Petit", "Marie", 1941, 0);

    // --- Création des parents ---
    personne* pere = creePersonne("Bernard", "Marc", 1970, 1);
    personne* mere = creePersonne("Petit", "Sophie", 1972, 0);

    parente(pere, gp1, gm1);
    parente(mere, gp2, gm2);

    // --- Création des enfants ---
    personne* enfant = creePersonne("Bernard", "Paul", 2000, 1);
    parente(enfant, pere, mere);

    personne* frere = creePersonne("Bernard", "Pierre", 2002, 1);
    parente(frere, pere, mere);

    personne* cousine = creePersonne("Petit", "Claire", 2001, 0);
    parente(cousine, gp2, gm2);

    // --- Tests affichage individuel ---
    cout << "\n--- Affichage individu ---\n";
    affichage(enfant);

    // --- Test fratrie ---
    cout << "\n--- Test fratrie ---\n";
    fraterie(enfant, frere); // devrait dire frère
    fraterie(enfant, cousine); // pas frère/soeur

    // --- Test même personne ---
    cout << "\n--- Test memePersonne ---\n";
    cout << (memePersonne(enfant, frere) ? "Vrai" : "Faux") << endl;
    cout << (memePersonne(enfant, enfant) ? "Vrai" : "Faux") << endl;

    // --- Test ancetre ---
    cout << "\n--- Test ancetre ---\n";
    cout << (ancetre(enfant, gp1) ? "Vrai" : "Faux") << endl;
    cout << (ancetre(enfant, cousine) ? "Vrai" : "Faux") << endl;

    // --- Test générations ---
    cout << "\n--- Test generations ---\n";
    cout << "Enfant : " << generations(enfant) << endl;
    cout << "Père : " << generations(pere) << endl;
    cout << "Mère : " << generations(mere) << endl;

    // --- Test nombre de personnes ---
    cout << "\n--- Test nombrePersonne ---\n";
    cout << "Enfant : " << nombrePersonne(enfant) << endl;
    cout << "Père : " << nombrePersonne(pere) << endl;
    cout << "Mère : " << nombrePersonne(mere) << endl;

    // --- Test mariages ---
    cout << "\n--- Test Mariages ---\n";
    Mariage(enfant, frere);      // frère/soeur, devrait échouer
    Mariage(enfant, cousine);    // possible
    Mariage(enfant, cousine);    // déjà mariés, devrait échouer

    // --- Test affichage de l'arbre ---
    cout << "\n--- Affichage de l'arbre ---\n";
    affichageArbre(enfant);

    // --- Nettoyage mémoire ---
    delete enfant;
    delete frere;
    delete cousine;
    delete pere;
    delete mere;
    delete gp1;
    delete gm1;
    delete gp2;
    delete gm2;


    return 0;
}

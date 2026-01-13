#include "type_def.h"
#include "utilitaires.h"
#include <iostream>

using namespace std;

int main(){
    // Génération 3
    personne* gp1 = creePersonne("Bernard", "Louis", 1940, 1);
    personne* gm1 = creePersonne("Bernard", "Anne", 1942, 0);

    personne* gp2 = creePersonne("Petit", "Jean", 1938, 1);
    personne* gm2 = creePersonne("Petit", "Marie", 1941, 0);

    // Génération 2
    personne* pere = creePersonne("Bernard", "Marc", 1970, 1);
    personne* mere = creePersonne("Bernard", "Sophie", 1972, 0);

    parente(pere, gp1, gm1);
    parente(mere, gp2, gm2);

    // Génération 1
    personne* enfant = creePersonne("Bernard", "Paul", 2000, 1);
    parente(enfant, pere, mere);

    cout << "Nombre de generations (enfant) : "
         << generations(enfant) << endl;

    cout << "Nombre de generations (pere) : "
         << generations(pere) << endl;

    cout << "Nombre de generations (mere) : "
         << generations(mere) << endl;

    cout << "Nombre de generations (gp1) : "
         << generations(gp1) << endl;

    cout << "=== TEST NOMBRE DE PERSONNES ===" << endl;
    cout << "Nombre de personnes depuis enfant : "
         << nombrePersonne(enfant) << endl;

    cout << "Nombre de personnes depuis père : "
         << nombrePersonne(pere) << endl;

    cout << "Nombre de personnes depuis mère : "
         << nombrePersonne(mere) << endl;

    cout << "Nombre de personnes depuis gp1 : "
         << nombrePersonne(gp1) << endl;

    // Nettoyage mémoire
    delete enfant;
    delete pere;
    delete mere;
    delete gp1;
    delete gm1;
    delete gp2;
    delete gm2;

    return 0;
}

#ifndef TYPE_DEF_H // Pareille qu'un pragram once
#define TYPE_DEF_H

#include <string>

using namespace std;

typedef struct personne {
    string nom;
    string prenom;
    int annee_naissance;
    int sexe; //  1 pour homme, 2 pour femme
    personne* conjoint;
    personne* pere;
    personne* mere;
} personne;

#endif
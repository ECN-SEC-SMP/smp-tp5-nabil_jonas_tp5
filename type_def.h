#include <cstring>
#include <iostream>
using namespace std;
#ifndef TYPE_DEF.H
#define TYPE_DEF.H

typedef struct personne{
    string nom;
    string prenom;
    int naissance;
    int sexe;
    personne *conjoints;
};

#endif
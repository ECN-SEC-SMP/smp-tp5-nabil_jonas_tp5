#include <cstring>
#include <iostream>
using namespace std;
#ifndef TYPE_DEF
#define TYPE_DEF

// en C ajouter : typedef
struct personne{
    string nom;
    string prenom;
    int naissance;
    int sexe;
    personne *conjoints;
    personne *pere;
    personne *mere;
};

#endif
#include <iostream>
#include <cstring>
#include "type_def.h"
#ifndef UTILITAIRES.H
#define UTILITAIRES.H

personne * creerPersonne (string nom, string prenom, int naissance,int sexe);

void mariage(personne *personne1, personne *personne2);

void affichagePersonne(personne *personne);



#endif
#include <iostream>
#include <cstring>
#include "type_def.h"
#ifndef UTILITAIRES
#define UTILITAIRES
using namespace std;

personne *creerPersonne (string nom, string prenom, int naissance,int sexe);

void mariage(personne *personne1, personne *personne2);

void affichagePersonne(personne *personne);

bool IsFrereSoeur(personne *personne1, personne *personne2);

bool memePersonne(personne *personne1, personne *personne2);

bool IsAncetre(personne *personne1, personne *personne2);


#endif
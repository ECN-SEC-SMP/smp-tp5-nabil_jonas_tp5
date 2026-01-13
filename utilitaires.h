#include "type_def.h"


personne* creePersonne (string nom, string prenom,int annee_naissance,int sexe );
void Mariage (personne* mari, personne* femme);
void affichage(personne* bob);
void parente(personne* enfant, personne* pere, personne* mere);
bool memePersonne(personne* p1, personne* p2);
void fraterie(personne* p1, personne* p2);
bool ancetre(personne* p1, personne* p2);
int generations(personne* p1);
int nombrePersonne(personne* p1);
bool peuventSeMarier(personne* p1, personne* p2);
void affichageArbre(personne* p1);
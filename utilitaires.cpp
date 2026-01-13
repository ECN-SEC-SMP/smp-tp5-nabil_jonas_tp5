using namespace std;
#include "type_def.h"
#include <iostream>
#include <cstring>

personne * creerPersonne (string nom, string prenom, int naissance,int sexe){
    personne* nouv = new personne;
    
    nouv->nom = nom;
    nouv->prenom = prenom;
    nouv->naissance = naissance;
    nouv->sexe = sexe;
    nouv->conjoints = nullptr;

    return nouv;
};

void mariage(personne *personne1, personne *personne2){

    personne1->conjoints = personne2;
    personne2->conjoints = personne1;

};


void affichagePersonne(personne *personne){
    string sexe1;
    string info1;
    string info2;
    string sexe2;

    if (personne->conjoints == nullptr){
        cout << personne->prenom + " " + personne->nom << " est célibataire" << endl;
        return;
    }
    if (personne->sexe == 2){
        sexe1 = "Madame ";
        info1 = "épouse ";
    }
    else{
        sexe1 = "Monsieur ";
        info1 = "époux ";
    }

    if (personne->conjoints->sexe == 2){
        sexe2 = "Madame ";
        info2 = "épouse ";
    }
    else{
        sexe2 = "Monsieur ";
        info2 = "époux ";
    }

    cout << sexe1 + personne->prenom + " " + personne->nom + " " + info1  << " " + personne->conjoints->nom << endl;
    
};
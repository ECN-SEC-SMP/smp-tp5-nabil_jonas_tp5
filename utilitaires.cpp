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
    nouv->mere = nullptr;
    nouv->pere = nullptr;

    return nouv;
};

void mariage(personne *personne1, personne *personne2){

    personne1->conjoints = personne2;
    personne2->conjoints = personne1;

};

bool memePersonne(personne *personne1, personne *personne2){
if ((personne1->nom == personne2->nom) && (personne1->prenom == personne2->prenom) && (personne1->naissance == personne2->naissance) && (personne1->sexe == personne2->sexe)){
    return true;
}
else{
    return false;
}
};

bool IsFrereSoeur(personne *personne1, personne *personne2){
    if (memePersonne(personne1, personne2)){
        return false;
    }
    if (not(personne1->pere == nullptr || personne2->pere == nullptr || personne1->mere == nullptr || personne2->mere == nullptr)){
        if (memePersonne(personne1->pere, personne2->pere) && memePersonne(personne1->mere, personne2->mere)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void affichagePersonne(personne *personne){
    string sexe1;
    string info1;
    string pere;
    string mere;


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


    if (personne->pere == nullptr){
        pere = "INCONNU";
    }
    else{
        pere = personne->pere->prenom +" " + personne->pere->nom; 
    }
    if (personne->mere == nullptr){
        mere = "INCONNUE";
    }
    else{
        mere = personne->mere->prenom +" " + personne->mere->nom; 

    }
    cout << sexe1 + personne->prenom + " " + personne->nom + " " + info1  << " " + personne->conjoints->nom << endl;
    cout << "De père " + pere <<endl;
    cout << "De mère " + mere << endl;
};

bool IsAncetre(personne *pers, personne *potAncetre){
    if(pers == nullptr){
        return false;
    }
    if(pers->mere == potAncetre || pers->pere == potAncetre){
        return true;
    }
    return IsAncetre(pers->mere,potAncetre) || IsAncetre(pers->pere,potAncetre);
};

int nbGenerations(personne *personne){
    int compt = 1;
    if (personne->pere == nullptr || personne->mere == nullptr){
        return compt;
    }
    return (nbGenerations(personne->mere) || nbGenerations(personne->pere)) + 1;
};
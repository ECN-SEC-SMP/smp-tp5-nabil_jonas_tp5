#include "type_def.h"
#include <string>
#include <iostream>

using namespace std;


personne* creePersonne (string nom, string prenom,int annee_naissance,int sexe ){
    personne* nouvelle_personne = new personne;
    nouvelle_personne->prenom = prenom;
    nouvelle_personne->nom = nom;
    nouvelle_personne->annee_naissance = annee_naissance;
    nouvelle_personne->sexe = sexe;
    nouvelle_personne->conjoint = nullptr;
    
    return nouvelle_personne;

}





void parente(personne* enfant, personne* pere, personne* mere){
    enfant->pere = pere;
    enfant->mere = mere;
    
}

void affichage(personne* bob){
    cout<< bob->prenom << endl;
    cout<< bob->nom << endl;
    cout<< bob->annee_naissance << endl;
    cout<< bob->sexe << endl;
    if (bob->conjoint != nullptr){
        if (bob->sexe == 1){
            cout << "Monsieur " << bob->prenom << " " << bob->nom << " épouse " << bob->conjoint->nom << endl;
         } else {
            cout << "Madame " << bob->prenom << " " << bob->nom << " épouse " << bob->conjoint->nom << endl;
         }
    } else {
        if (bob->sexe == 1){
            cout << "Pas d'épouse" << endl;
         }else{ 
            cout << "Pas d'époux" << endl;
         }
    }

    // Père
    if (bob->pere != nullptr) {
        cout << "Père : " << bob->pere->prenom << " " << bob->pere->nom << endl;
    } else {
        cout << "Pas de père renseigné" << endl;
    }

    // Mère
    if (bob->mere != nullptr) {
        cout << "Mère : " << bob->mere->prenom << " " << bob->mere->nom << endl;
    } else {
        cout << "Pas de mère renseignée" << endl;
    }

}

bool fraterie(personne* p1, personne* p2) {
    if (p1->pere == p2->pere && p1->mere == p2->mere) {

        if (p1->sexe == 1 && p2->sexe == 1) {
            cout << p1->prenom << " est le frère de " << p2->prenom << endl;
        }
        else if (p1->sexe == 1 && p2->sexe == 0) {
            cout << p1->prenom << " est le frère de " << p2->prenom << endl;
        }
        else if (p1->sexe == 0 && p2->sexe == 1) {
            cout << p1->prenom << " est la soeur de " << p2->prenom << endl;
        }
        else {
            cout << p1->prenom << " est la soeur de " << p2->prenom << endl;
        }
        return true;
    } else {
        return false;
    }
}


bool memePersonne(personne* p1, personne* p2){
    if(p1->prenom == p2->prenom && p1->nom == p2->nom && p1->annee_naissance == p2->annee_naissance && p1->sexe == p2->sexe){
        return true;
    } else {
        return false;
    }
}

bool ancetre(personne* p1, personne* p2) {
    if (p1 == nullptr) return false;
    if (p1->pere == p2 || p1->mere == p2) return true;

    return ancetre(p1->pere, p2) || ancetre(p1->mere, p2);
}

int generations(personne* p1){
    int nbtemp1 = 0;
    int nbtemp2 = 0;
    
    if(p1==nullptr) return 0;
    nbtemp1 = 1+generations(p1->pere);
    nbtemp2 = 1+generations(p1->mere);

    if(nbtemp1>nbtemp2){
        return nbtemp1;
    } else {
        return nbtemp2;
    }
}

int nombrePersonne(personne* p1){
    int nbtemp1 = 0;
    int nbtemp2 = 0;
    
    if(p1==nullptr) return 0;
    

    if(p1->pere!=nullptr && p1->mere!=nullptr){
        nbtemp1 = nombrePersonne(p1->pere);
        nbtemp2 = nombrePersonne(p1->mere);
    }
   

    return 1 + nbtemp1 + nbtemp2;
}

bool peuventSeMarier(personne* p1, personne* p2){
    if (ancetre(p1,p2)){
        return false;
    }
    if(ancetre(p2,p1)){
        return false;
    }

    if(fraterie(p1,p2)){
        return false;
    }

    if(p1->conjoint!=nullptr){
        return false;
    }
    if(p1->conjoint!=nullptr){
        return false;
    }
    return true;
}

void Mariage (personne* mari, personne* femme){
    if(peuventSeMarier(mari,femme)){
        mari->conjoint = femme;
        femme->conjoint = mari;
        cout << "Ils peuvent se marier." << endl;
    } else {
        cout << "Ils ne peuvent pas se marier." << endl;
    }
    
}

void affichageArbre(personne* p1){
    if(p1->pere == nullptr){

    } else {
        affichageArbre(p1->pere);
   
    }
    if(p1->mere == nullptr){

    } else {
        affichageArbre(p1->mere);
    }

    cout<< p1->prenom << endl;
    cout<< p1->nom << endl;
    cout << "----------------------" << endl;
    // cout<< p1->annee_naissance << endl;
    // cout<< p1->sexe << endl;
    // if (p1->conjoint != nullptr){
    //     if (p1->sexe == 1){
    //         cout << "Monsieur " << p1->prenom << " " << p1->nom << " épouse " << p1->conjoint->nom << endl;
    //      } else {
    //         cout << "Madame " << p1->prenom << " " << p1->nom << " épouse " << p1->conjoint->nom << endl;
    //      }
    // } else {
    //     if (p1->sexe == 1){
    //         cout << "Pas d'épouse" << endl;
    //      }else{ 
    //         cout << "Pas d'époux" << endl;
    //      }
    // }

    // // Père
    // if (p1->pere != nullptr) {
    //     cout << "Père : " << p1->pere->prenom << " " << p1->pere->nom << endl;
    // } else {
    //     cout << "Pas de père renseigné" << endl;
    // }

    // // Mère
    // if (p1->mere != nullptr) {
    //     cout << "Mère : " << p1->mere->prenom << " " << p1->mere->nom << endl;
    // } else {
    //     cout << "Pas de mère renseignée" << endl;
    // }

    
}
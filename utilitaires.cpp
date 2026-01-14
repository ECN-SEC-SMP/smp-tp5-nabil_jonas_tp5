#include "type_def.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

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
    // Sécurité de base
    if (p1 == nullptr || p2 == nullptr) return false;

    // Si l'un des deux n'a pas de père ou de mère enregistré (cas des racines/grands-parents),
    // ils ne peuvent pas être considérés comme frères/sœurs via ce lien.
    if (p1->pere == nullptr || p2->pere == nullptr || 
        p1->mere == nullptr || p2->mere == nullptr) {
        return false;
    }

    // Ils sont frères/sœurs SI : Même père ET Même mère
    if (p1->pere == p2->pere && p1->mere == p2->mere) {
        // Optionnel : Vous pouvez garder ou enlever le cout selon vos préférences
        cout << p1->prenom << " est le frere/soeur de " << p2->prenom << endl;
        return true;
    }

    return false;
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
    if(p2->conjoint!=nullptr){
        return false;
    }
    return true;
}

void Mariage(personne* mari, personne* femme) {
    // 1. Sécurité : Vérifier que les personnes existent
    if (mari == nullptr || femme == nullptr) {
        cout << "Erreur : Impossible de marier une personne inexistante (pointeur NULL)." << endl;
        return;
    }

    // 2. Sécurité : On ne peut pas se marier avec soi-même
    if (mari == femme) {
        cout << "Mariage impossible : Une personne ne peut pas se marier avec elle-meme." << endl;
        return;
    }

    // 3. Vérification des règles (inceste, bigamie...)
    if (peuventSeMarier(mari, femme)) {
        // Application du mariage
        mari->conjoint = femme;
        femme->conjoint = mari;
        
        cout << "Mariage reussi entre " << mari->prenom << " et " << femme->prenom << "." << endl;
    } else {
        cout << "Mariage impossible entre " << mari->prenom << " et " << femme->prenom 
             << " (Lien de parente ou deja marie)." << endl;
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

void collecterToutesLesPersonnes(personne* p, std::set<personne*>& visites, std::vector<personne*>& liste) {
    if (p == nullptr || visites.find(p) != visites.end()) {
        return; // Déjà traité ou vide
    }
    
    visites.insert(p);
    liste.push_back(p);
    
    // On explore récursivement les liens
    collecterToutesLesPersonnes(p->pere, visites, liste);
    collecterToutesLesPersonnes(p->mere, visites, liste);
    collecterToutesLesPersonnes(p->conjoint, visites, liste);
}

// =========================================================
// VERSION CORRIGEE : PRIORITE AU SANG
// =========================================================

// --- FONCTIONS AUXILIAIRES ---

string formatRoleSimple(int generation, int sexe) {
    if (generation == 0) return "Enfant"; // Plus clair que "Enfant"
    if (generation == 1) return (sexe == 1) ? "Pere" : "Mere";
    if (generation == 2) return (sexe == 1) ? "Grand-Pere" : "Grand-Mere";
    return (sexe == 1) ? "Arriere-GP" : "Arriere-GM";
}

// Cette fonction ne parcourt QUE les parents (le sang)
void mapperRolesSang(personne* p, std::map<personne*, string>& mapRoles, int gen) {
    if (p == nullptr) return;

    // On assigne le rôle seulement s'il n'existe pas encore
    if (mapRoles.find(p) == mapRoles.end()) {
        mapRoles[p] = formatRoleSimple(gen, p->sexe);
    }

    // On monte vers les ancêtres uniquement
    mapperRolesSang(p->pere, mapRoles, gen + 1);
    mapperRolesSang(p->mere, mapRoles, gen + 1);
}

// --- SAUVEGARDE AMELIOREE ---

void sauvegardeArbre(personne* racine, string nomFichier) {
    if (racine == nullptr) {
        cout << "Erreur : Racine vide." << endl;
        return;
    }

    // 1. Récupérer tout le monde
    std::set<personne*> visites;
    std::vector<personne*> tous;
    collecterToutesLesPersonnes(racine, visites, tous);

    // 2. Assigner les IDs
    std::map<personne*, int> ptrVersId;
    int idCpt = 1;
    for (personne* p : tous) ptrVersId[p] = idCpt++;

    // 3. Calculer les Rôles (NOUVELLE LOGIQUE)
    std::map<personne*, string> roles;
    
    // Etape A : On parcourt d'abord les ancêtres (pour que Maman soit "Mere" et pas "Conjoint")
    mapperRolesSang(racine, roles, 0);

    // Etape B : On regarde les autres (Cousins mariés, Conjoints de GP...)
    for (personne* p : tous) {
        // Si la personne a déjà un rôle (ex: Mere), on ne touche à rien.
        if (roles.find(p) != roles.end()) continue;

        // Sinon, on regarde si c'est un conjoint de quelqu'un
        if (p->conjoint != nullptr) {
            // Si son mari/femme a un rôle, on peut dire "Conjoint de X" ou juste "Conjoint"
            roles[p] = "Conjoint"; 
        } else {
            roles[p] = "Parente"; // Ni ancêtre, ni conjoint (ex: cousine non mariée)
        }
    }

    // 4. Ecriture
    ofstream fichier(nomFichier);
    if (!fichier.is_open()) return;

    fichier << tous.size() << " " << ptrVersId[racine] << endl;
    fichier << "# ID Role Nom Prenom Annee Sexe [ID_Pere ID_Mere ID_Conjoint]" << endl;

    for (personne* p : tous) {
        int idP = (p->pere) ? ptrVersId[p->pere] : 0;
        int idM = (p->mere) ? ptrVersId[p->mere] : 0;
        int idC = (p->conjoint) ? ptrVersId[p->conjoint] : 0;
        
        string roleStr = (roles.count(p) ? roles[p] : "Autre");

        fichier << ptrVersId[p] << " "
                << roleStr << " "
                << p->nom << " "
                << p->prenom << " "
                << p->annee_naissance << " "
                << p->sexe << " "
                << idP << " " << idM << " " << idC << endl;
    }
    fichier.close();
    cout << "Sauvegarde terminee dans : " << nomFichier << endl;
}

personne* lectureArbre(string nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) return nullptr;

    int nb, idRacine;
    string buffer; 
    
    if (!(fichier >> nb >> idRacine)) return nullptr;
    getline(fichier, buffer); 
    getline(fichier, buffer); 

    std::map<int, personne*> idVersPtr;
    struct Relations { int p, m, c; };
    std::map<int, Relations> mapRel;

    // PASSE 1 : Création
    for (int i = 0; i < nb; i++) {
        int id, annee, sexe, idP, idM, idC;
        string nom, prenom, roleInutile;

        // On lit tout, y compris les IDs à la fin
        fichier >> id >> roleInutile >> nom >> prenom >> annee >> sexe >> idP >> idM >> idC;

        personne* p = creePersonne(nom, prenom, annee, sexe);
        idVersPtr[id] = p;
        mapRel[id] = {idP, idM, idC};
    }

    // PASSE 2 : Reconstruction des liens (C'est ça qui répare votre erreur)
    for (auto const& [id, p] : idVersPtr) {
        if (mapRel[id].p != 0) p->pere = idVersPtr[mapRel[id].p];
        if (mapRel[id].m != 0) p->mere = idVersPtr[mapRel[id].m];
        if (mapRel[id].c != 0) p->conjoint = idVersPtr[mapRel[id].c];
    }

    cout << "Arbre charge avec succes (Liens restaures)." << endl;
    return idVersPtr[idRacine];
}
#include "type_def.h"
#include "utilitaires.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // =========================================================
    // 1. CRÉATION ET REMPLISSAGE DE L'ARBRE (Comme avant)
    // =========================================================
    cout << "=== 1. CREATION DE LA FAMILLE ===" << endl;

    // --- Grands-parents ---
    personne* gp1 = creePersonne("Bernard", "Louis", 1940, 1);
    personne* gm1 = creePersonne("Bernard", "Anne", 1942, 0);
    personne* gp2 = creePersonne("Petit", "Jean", 1938, 1);
    personne* gm2 = creePersonne("Petit", "Marie", 1941, 0);

    // --- Parents ---
    personne* pere = creePersonne("Bernard", "Marc", 1970, 1);
    personne* mere = creePersonne("Petit", "Sophie", 1972, 0);

    // Liens de parenté parents -> grands-parents
    parente(pere, gp1, gm1);
    parente(mere, gp2, gm2);

    // --- Enfants ---
    personne* enfant = creePersonne("Bernard", "Paul", 2000, 1);
    parente(enfant, pere, mere); // Paul est fils de Marc et Sophie

    personne* frere = creePersonne("Bernard", "Pierre", 2002, 1);
    parente(frere, pere, mere);  // Pierre est aussi fils de Marc et Sophie

    personne* cousine = creePersonne("Petit", "Claire", 2001, 0);
    parente(cousine, gp2, gm2);  // Claire est fille de Jean et Marie (pour l'exemple, disons que c'est une tante/cousine directe via les GP)

    // =========================================================
    // 2. TESTS DES FONCTIONS STANDARD (utilitaires.cpp existant)
    // =========================================================
    cout << "\n=== 2. TESTS DES FONCTIONS EXISTANTES ===" << endl;

    // A. Affichage individuel
    cout << "\n[Test Affichage Individuel]" << endl;
    affichage(enfant);

    // B. Mariages
    cout << "\n[Test Mariages]" << endl;
    Mariage(gp1, gm1); // Devrait marcher
    Mariage(pere, mere); // Devrait marcher
    Mariage(enfant, frere); // Devrait échouer (frères)
    Mariage(enfant, cousine); // Devrait fonctionner (cousins peuvent souvent se marier selon les règles simples implémentées, ou échouer selon votre logique ancêtre)

    // C. Fratrie
    cout << "\n[Test Fratrie]" << endl;
    fraterie(enfant, frere);   // "Frère de..."
    fraterie(enfant, cousine); // Rien ou false

    // D. Même personne
    cout << "\n[Test MemePersonne]" << endl;
    if (memePersonne(enfant, enfant)) cout << "OK: Paul est Paul." << endl;
    if (!memePersonne(enfant, pere)) cout << "OK: Paul n'est pas Marc." << endl;

    // E. Ancêtre
    cout << "\n[Test Ancetre]" << endl;
    if (ancetre(enfant, gp1)) cout << "OK: Louis est bien l'ancetre de Paul." << endl;
    else cout << "ERREUR: Louis devrait etre ancetre de Paul." << endl;

    // F. Générations et Nombre de personnes
    cout << "\n[Test Statistiques]" << endl;
    cout << "Generations (profondeur) pour l'enfant : " << generations(enfant) << " (Attendu: ~3)" << endl;
    cout << "Nombre de personnes liees a l'enfant (ascendants) : " << nombrePersonne(enfant) << endl;

    // G. Affichage Arbre
    cout << "\n[Test Affichage Arbre Complet - Original]" << endl;
    affichageArbre(enfant);


    // =========================================================
    // 3. TESTS DES NOUVELLES FONCTIONS (Sauvegarde / Lecture)
    // =========================================================
    cout << "\n=========================================" << endl;
    cout << "=== 3. TESTS SAUVEGARDE ET LECTURE ===" << endl;
    cout << "=========================================" << endl;

    string nomFichier = "test_famille_tp5.txt";

    // --- TEST SAUVEGARDE ---
    cout << "\n-> Sauvegarde de l'arbre dans '" << nomFichier << "'..." << endl;
    // On sauvegarde à partir de l'enfant (la fonction doit parcourir tout l'arbre connecté)
    sauvegardeArbre(enfant, nomFichier);

    // --- TEST LECTURE ---
    cout << "\n-> Lecture de l'arbre depuis '" << nomFichier << "'..." << endl;
    personne* racineRelue = lectureArbre(nomFichier);

    if (racineRelue != nullptr) {
        cout << "SUCCES : Arbre charge en memoire !" << endl;

        // Vérification sommaire
        cout << "Racine relue : " << racineRelue->prenom << " " << racineRelue->nom << endl;

        // Comparaison simple pour voir si les liens sont là
        if (racineRelue->pere != nullptr) {
            cout << "Pere de la racine relue : " << racineRelue->pere->prenom << endl;
        } else {
            cout << "ERREUR : Le pere n'a pas ete relie correctement." << endl;
        }

        cout << "\n[Affichage Arbre Relu]" << endl;
        // On affiche l'arbre chargé pour vérifier visuellement qu'il est identique à l'original
        affichageArbre(racineRelue);

    } else {
        cout << "ECHEC : Impossible de charger l'arbre." << endl;
    }

    // =========================================================
    // 4. NETTOYAGE
    // =========================================================
    cout << "\n=== 4. NETTOYAGE MEMOIRE ===" << endl;
    // Suppression de l'arbre original
    delete enfant; delete frere; delete cousine;
    delete pere; delete mere;
    delete gp1; delete gm1; delete gp2; delete gm2;

    // Note : Pour l'arbre relu, comme tous les nœuds ont été alloués dynamiquement par lectureArbre,
    // il faudrait idéalement une fonction de suppression récursive complète.
    // Ici, on ne supprime pas tout pour ne pas alourdir le code de test, 
    // mais dans un vrai projet, il faudrait delete chaque nœud de 'racineRelue'.
    
    return 0;
}
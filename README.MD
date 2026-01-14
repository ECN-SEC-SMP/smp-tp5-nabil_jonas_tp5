# RAPPORT SMP - TP5
## Arbre Généalogique

**Date:** 14 Janvier 2026  
**Auteurs:** Nabil Khouani - Jonas Maouche

---

## Introduction

Ce TP a pour but de créer et manipuler une structure d'**arbre généalogique** en C++. Nous implémentons des fonctions permettant de créer des personnes, établir des liens de parenté (père, mère, conjoint), vérifier des relations familiales et sauvegarder/charger l'arbre dans un fichier. L'objectif est de comprendre le fonctionnement des **pointeurs** et des **structures récursives** pour modéliser des relations complexes.

---

## Structure de données

Le fichier `type_def.h` contient la structure de données principale utilisée dans ce TP.

### Structure `personne`

La structure `personne` permet de représenter les informations relatives à une personne dans l'arbre généalogique :

| Champ | Type | Description |
|-------|------|-------------|
| `nom` | `string` | Le nom de famille de la personne |
| `prenom` | `string` | Le prénom de la personne |
| `annee_naissance` | `int` | L'année de naissance |
| `sexe` | `int` | 1 pour homme, 2 pour femme |
| `conjoint` | `personne*` | Pointeur vers le conjoint (ou `nullptr`) |
| `pere` | `personne*` | Pointeur vers le père (ou `nullptr`) |
| `mere` | `personne*` | Pointeur vers la mère (ou `nullptr`) |

Cette structure utilise des **pointeurs auto-référentiels** pour créer des liens entre les membres de la famille, formant ainsi un arbre généalogique bidirectionnel.

---

## Utilitaires

Le fichier `utilitaires.cpp` contient les fonctions essentielles pour la manipulation de l'arbre.

### Fonction `creePersonne`

Cette fonction crée dynamiquement une nouvelle personne avec les informations fournies. Elle alloue la mémoire via `new` et initialise tous les pointeurs relationnels à `nullptr`.

- **Entrée :** `nom`, `prenom`, `annee_naissance`, `sexe`
- **Sortie :** Un pointeur vers la nouvelle `personne` créée

### Fonction `parente`

Cette fonction établit les liens de parenté entre un enfant et ses parents biologiques.

- **Entrée :** Pointeurs vers l'enfant, le père et la mère
- **Sortie :** Mise à jour des champs `pere` et `mere` de l'enfant

### Fonction `affichage`

Cette fonction affiche les informations complètes d'une personne : nom, prénom, année de naissance, sexe, informations sur le conjoint et les parents.

- **Entrée :** Un pointeur vers une `personne`
- **Sortie :** Affichage formaté dans la console

### Fonction `memePersonne`

Cette fonction vérifie si deux personnes sont identiques en comparant tous leurs attributs (nom, prénom, année de naissance, sexe).

- **Entrée :** Deux pointeurs vers des `personne`
- **Sortie :** `true` si identiques, `false` sinon

### Fonction `fraterie`

Cette fonction détermine si deux personnes sont frères/sœurs en vérifiant qu'elles partagent le même père ET la même mère.

- **Entrée :** Deux pointeurs vers des `personne`
- **Sortie :** `true` si frères/sœurs, `false` sinon

### Fonction `ancetre`

Cette fonction vérifie récursivement si une personne `p2` est un ancêtre de `p1`. Elle parcourt l'arbre en remontant via les pointeurs `pere` et `mere`.

- **Entrée :** Deux pointeurs vers des `personne`
- **Sortie :** `true` si `p2` est ancêtre de `p1`, `false` sinon

### Fonction `generations`

Cette fonction calcule la profondeur maximale de l'arbre généalogique à partir d'une personne, en comptant récursivement les générations d'ancêtres.

- **Entrée :** Un pointeur vers une `personne`
- **Sortie :** Le nombre maximal de générations

### Fonction `nombrePersonne`

Cette fonction compte le nombre total de personnes dans l'arbre ascendant d'une personne donnée.

- **Entrée :** Un pointeur vers une `personne`
- **Sortie :** Le nombre de personnes liées

### Fonction `peuventSeMarier`

Cette fonction vérifie si deux personnes peuvent légalement se marier selon les règles implémentées :
1. Pas de lien d'ascendance/descendance
2. Pas de fratrie
3. Aucun des deux n'est déjà marié

- **Entrée :** Deux pointeurs vers des `personne`
- **Sortie :** `true` si le mariage est autorisé, `false` sinon

### Fonction `Mariage`

Cette fonction effectue le mariage entre deux personnes si les conditions sont remplies. Elle vérifie d'abord les règles via `peuventSeMarier`, puis met à jour les pointeurs `conjoint` de chaque personne.

- **Entrée :** Pointeurs vers le mari et la femme
- **Sortie :** Mise à jour des liens ou message d'erreur

### Fonction `affichageArbre`

Cette fonction affiche récursivement tout l'arbre généalogique en parcourant d'abord les ancêtres (parcours en profondeur préfixe inversé).

- **Entrée :** Un pointeur vers la racine de l'arbre
- **Sortie :** Affichage hiérarchique de toutes les personnes

---

## Sauvegarde et Lecture

### Fonction `sauvegardeArbre`

Cette fonction sauvegarde l'intégralité de l'arbre généalogique dans un fichier texte. L'algorithme :

1. **Collecte** toutes les personnes de l'arbre (via `collecterToutesLesPersonnes`)
2. **Assigne un ID unique** à chaque personne
3. **Calcule les rôles** (Enfant, Père, Mère, Grand-Père, Grand-Mère, Conjoint, Parenté)
4. **Écrit** chaque personne avec ses attributs et liens (IDs des père, mère, conjoint)

Le format du fichier sauvegardé :
```
[NombrePersonnes] [ID_Racine]
# ID Role Nom Prenom Annee Sexe [ID_Pere ID_Mere ID_Conjoint]
1 Enfant Bernard Paul 2000 1 2 5 8
2 Pere Bernard Marc 1970 1 3 4 5
...
```

### Fonction `lectureArbre`

Cette fonction reconstruit l'arbre généalogique à partir d'un fichier sauvegardé. L'algorithme en **deux passes** :

1. **Passe 1 - Création :** Lecture de chaque ligne et création des objets `personne` sans liens
2. **Passe 2 - Reconstruction :** Établissement des liens (père, mère, conjoint) via les IDs

- **Entrée :** Nom du fichier à lire
- **Sortie :** Pointeur vers la racine de l'arbre reconstruit

---

## Tests et Résultats

Le fichier `main.cpp` contient une suite de tests pour valider toutes les fonctions.

### 1. Création de la Famille

```
Famille créée :
- Grands-parents paternels : Louis et Anne Bernard
- Grands-parents maternels : Jean et Marie Petit
- Parents : Marc Bernard et Sophie Petit
- Enfants : Paul et Pierre Bernard
- Cousine : Claire Petit
```

### 2. Tests des Fonctions

| Test | Fonction | Résultat Attendu | Résultat Obtenu |
|------|----------|------------------|-----------------|
| Affichage individuel | `affichage()` | Infos complètes | ✅ OK |
| Mariage valide | `Mariage(gp1, gm1)` | Mariage réussi | ✅ OK |
| Mariage entre frères | `Mariage(enfant, frere)` | Refusé (fratrie) | ✅ OK |
| Test fratrie | `fraterie(enfant, frere)` | true | ✅ OK |
| Test ancêtre | `ancetre(enfant, gp1)` | true | ✅ OK |
| Générations | `generations(enfant)` | ~3 | ✅ OK |

### 3. Tests Sauvegarde/Lecture

Le fichier `test_famille_tp5.txt` généré contient :
- 8 personnes avec leurs rôles respectifs
- Liens de parenté correctement encodés
- IDs cohérents pour la reconstruction

**Vérification après lecture :**
- Racine relue : Paul Bernard ✅
- Père correctement lié : Marc Bernard ✅
- Arbre complet reconstruit avec tous les liens ✅

---

## Analyse des Choix d'Implémentation

### Utilisation des Pointeurs

L'utilisation de pointeurs pour les liens familiaux présente plusieurs avantages :
- **Flexibilité :** Liens bidirectionnels possibles (conjoint ↔ conjoint)
- **Efficacité mémoire :** Une personne n'est stockée qu'une seule fois
- **Parcours récursif naturel :** Remontée vers les ancêtres simplifiée

### Algorithme de Sauvegarde

La stratégie en deux étapes (collecte + écriture avec IDs) permet de :
- Gérer les **références circulaires** (mari ↔ femme)
- Reconstruire fidèlement l'arbre à la lecture
- Assigner des **rôles sémantiques** pour une meilleure lisibilité

### Gestion de la Mémoire

- Allocation dynamique via `new` pour chaque personne
- Libération manuelle via `delete` dans le main
- **Note :** Une fonction de nettoyage récursif serait nécessaire pour un projet complet

---

## Conclusion

Ce TP nous a permis de mettre en pratique :
- La manipulation de **structures auto-référentielles** en C++
- Les **algorithmes récursifs** pour parcourir des arbres
- La **sérialisation/désérialisation** de structures de données complexes
- La gestion des **pointeurs** et de la mémoire dynamique

L'arbre généalogique implémenté permet de modéliser des relations familiales réalistes et de vérifier des contraintes (mariage, fratrie, ascendance) de manière efficace grâce aux parcours récursifs.

# c-learning-projects

Collection de 31 projets pédagogiques en langage C, organisés par niveau de difficulté.  
Chaque projet contient un fichier `main.c` corrigé et un `README.md` explicatif.

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi, Bénin

---

## Structure 

```
c-learning-projects/
├── 01-facturation-photocopies/
├── 02-verification-inscription/
├── 03-ajout-seconde/
├── 04-somme-nombres/
├── 05-menu-code/
├── 06-somme-trois-nombres/
├── 07-annee-bissextile/
├── 08-valeur-absolue/
├── 09-calcul-ttc/
├── 10-pair-impair/
├── 11-jour-semaine/
├── 12-verification-pin/
├── 13-equation-premier-degre/
├── 14-ordre-alphabetique/
├── 15-min-max/
├── 16-code-chiffres/
├── 17-tri-etudiants/
├── 18-maximum-trois-nombres/
├── 19-maximum-n-nombres/
├── 20-nombre-premier/
├── 21-minimum-tableau/
├── 22-minimum-sentinelle/
├── 23-valeurs-impaires/
├── 24-maximum-tableau/
├── 25-maximum-matrice/
├── 26-recherche-matrice/
├── 27-comptage-matrice/
├── 28-rationnels/
├── 29-commande-produit/
├── 30-comptes-bancaires/
└── 31-bulletins-scolaires/
```

---

## Projets par niveau

### Débutant (01–12)

| # | Projet | Concepts clés |
|---|---|---|
| 01 | Facturation de photocopies | `if/else`, `#define`, fonctions |
| 02 | Vérification d'inscription | Tableaux de chaînes, `strcmp`, `toupper` |
| 03 | Ajout d'une seconde | Pointeurs, cascade de retenues |
| 04 | Somme de deux nombres | Réels, `fabsf`, epsilon |
| 05 | Menu avec code | `switch/case`, validation |
| 06 | Somme de trois nombres | Comparaison flottants, epsilon |
| 07 | Année bissextile | Conditions imbriquées, modulo |
| 08 | Valeur absolue | Opérateur ternaire, fonctions |
| 09 | Calcul TTC | Calculs en cascade, `#define` |
| 10 | Pair / Impair | Modulo, entiers négatifs |
| 11 | Jour de la semaine | `switch`, tableaux de chaînes |
| 12 | Vérification PIN | `do-while`, compteur de tentatives |

### Débutant / Intermédiaire (13–16)

| # | Projet | Concepts clés |
|---|---|---|
| 13 | Équation 1er degré | 3 cas mathématiques, substitution |
| 14 | Ordre alphabétique | Comparaison `char`, `isalpha` |
| 15 | Min et Max | Composition de fonctions, ternaire |
| 16 | Code à 4 chiffres | Division entière, modulo, extraction |

### Intermédiaire (17–24)

| # | Projet | Concepts clés |
|---|---|---|
| 17 | Tri d'étudiants | `struct`, tri à bulles |
| 18 | Maximum de 3 nombres | Fonction de comparaison |
| 19 | Maximum de N nombres | Boucle + mise à jour du max |
| 20 | Nombre premier | O(√n), saut des pairs |
| 21 | Minimum d'un tableau | Tableaux, parcours linéaire |
| 22 | Minimum sentinelle | Valeur sentinelle, `while` infini |
| 23 | Valeurs impaires | Filtrage, ratio |
| 24 | Maximum d'un tableau | Affichage conditionnel |

### Intermédiaire / Avancé (25–31)

| # | Projet | Concepts clés |
|---|---|---|
| 25 | Maximum d'une matrice | Tableaux 2D, boucles imbriquées |
| 26 | Recherche dans matrice | Taille variable, epsilon |
| 27 | Comptage dans matrice | Compteurs multiples, pourcentages |
| 28 | Rationnels | `struct`, PGCD, Euclide |
| 29 | Commande de produit | `enum`, borne dynamique |
| 30 | Comptes bancaires | Tableau de structs, CRUD |
| 31 | Bulletins scolaires | Structs imbriqués, rang, mentions |

---

## Compilation

Chaque projet se compile avec :
```bash
gcc -o nom_binaire main.c
# Ou pour les projets utilisant <math.h> :
gcc -o nom_binaire main.c -lm
```

## Conventions appliquées

- Validation systématique des saisies avec messages d'erreur précis
- Boucle de relance `do-while` avec `demander_continuation()`
- Comparaison de flottants via `fabsf() < EPSILON` (jamais `==`)
- Constantes de configuration avec `#define`
- Pas de `while(getchar()!='\n')` superflu

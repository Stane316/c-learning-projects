# Vérification d'Inscription en C

## Description
Programme qui vérifie si un nom figure dans la liste des inscrits.
Si absent, propose un choix de langage (Java ou C).

## Objectif pédagogique
- Tableau de chaînes (`const char *[]`)
- Comparaison avec `strcmp()`
- Insensibilité à la casse avec `toupper()`
- Recherche linéaire dans une liste

## Exemple

```
Nom : dupont
→ Bienvenue ! dupont est bien inscrit(e).

Nom : TOTO
→ TOTO n'est pas dans la liste.
  Choisissez : Java ou C
```

## Compilation

```bash
gcc -o inscription main.c
./inscription
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

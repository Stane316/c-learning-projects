# Ordre Alphabétique de 3 Lettres en C

## Description
Vérifie si 3 lettres sont en ordre alphabétique croissant.
Insensible à la casse, distingue ordre strict et ordre avec doublons.

## Objectif pédagogique
- Comparaison de `char` (valeurs ASCII)
- Insensibilité à la casse avec `toupper()`
- Validation précise avec `isalpha()`, `isdigit()`, `ispunct()`
- Ordre strict (`<`) vs non strict (`<=`)

## Exemple

```
A, C, F  →  Ordre alphabetique STRICT : A < C < F
a, A, b  →  Ordre alphabetique (doublons) : A <= A <= B
Z, A, M  →  PAS en ordre alphabetique.
```

## Compilation

```bash
gcc -o ordre_alpha main.c
./ordre_alpha
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

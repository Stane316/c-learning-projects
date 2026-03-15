# Équation du Premier Degré en C

## Description
Résout `ax + b = 0` avec gestion des 3 cas mathématiques,
et vérification de la solution par substitution.

## Objectif pédagogique
- Conditions multiples pour les cas mathématiques
- Comparaison sécurisée à zéro avec `fabsf()` + epsilon
- Vérification d'une solution par substitution

## Cas traités

```
a ≠ 0             →  x = -b/a  (solution unique)
a = 0, b ≠ 0      →  aucune solution
a = 0, b = 0      →  infinite de solutions
```

## Exemple

```
2x + 6 = 0  →  x = -3.000000  ✓
0x + 5 = 0  →  Aucune solution
0x + 0 = 0  →  Infinite de solutions
```

## Compilation

```bash
gcc -o equation main.c -lm
./equation
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

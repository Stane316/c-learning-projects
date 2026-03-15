# Test Pair / Impair en C

## Description
Détermine si un entier est pair ou impair avec l'opérateur modulo.
Fonctionne aussi pour les nombres négatifs.

## Objectif pédagogique
- Opérateur modulo `%`
- Comportement de `%` sur les entiers négatifs en C
- Cas limite : `0` est pair par convention

## Comportement sur les négatifs

```c
-3 % 2 == -1  (≠ 0)  →  impair  ✓
-4 % 2 ==  0         →  pair    ✓
```

## Exemple

```
Entier : 7    →  7 est IMPAIR.
Entier : -4   →  -4 est PAIR.
Entier : 0    →  0 est NUL (pair par convention).
```

## Compilation

```bash
gcc -o pair_impair main.c
./pair_impair
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

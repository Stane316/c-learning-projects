# Détection d'un Nombre Premier en C

## Description
Détermine si un entier est premier. Algorithme optimisé
O(√n) avec saut des pairs.

## Objectif pédagogique
- Algorithme de détection de nombre premier
- Optimisation : tester jusqu'à `√n` seulement
- Saut des pairs pour réduire les itérations

## Algorithme

```c
if (n < 2)  → non premier
if (n == 2) → premier
if (n % 2 == 0) → non premier
for i=3; i*i<=n; i+=2 → tester uniquement les impairs
```

## Compilation

```bash
gcc -o nombre_premier main.c -lm
./nombre_premier
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

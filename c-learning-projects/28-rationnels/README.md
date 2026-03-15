# Opérations sur les Rationnels en C

## Description
Addition, soustraction, multiplication et division de fractions
avec simplification automatique par le PGCD (algorithme d'Euclide).

## Objectif pédagogique
- `struct` pour représenter une fraction
- Algorithme d'Euclide pour le PGCD
- Normalisation du signe et simplification

## Algorithme d'Euclide

```c
int pgcd(int a, int b) {
    while (b != 0) { int t=b; b=a%b; a=t; }
    return a;
}
```

## Compilation

```bash
gcc -o rationnels main.c
./rationnels
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

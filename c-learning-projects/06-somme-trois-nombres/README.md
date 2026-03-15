# Somme de Trois Nombres en C

## Description
Vérifie si l'un des 3 nombres saisis est égal à la somme des
deux autres. Utilise une comparaison sécurisée avec epsilon.

## Objectif pédagogique
- Conditions multiples `if/else if`
- **Comparaison sécurisée** de flottants avec `fabsf()` + epsilon
- Pourquoi `==` est dangereux avec `float`

## Exemple

```
Nombres : 3.00 | 2.00 | 1.00
OUI : 3.00 = 2.00 + 1.00

Nombres : 5.00 | 3.00 | 4.00
NON : aucun nombre n'est egal a la somme des deux autres.
```

## Compilation

```bash
gcc -o somme_trois main.c -lm
./somme_trois
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

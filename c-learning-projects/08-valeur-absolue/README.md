# Valeur Absolue en C

## Description
Calcule la valeur absolue d'un réel de façon manuelle
(sans `fabsf()`), à des fins pédagogiques.

## Objectif pédagogique
- Opérateur ternaire `(condition) ? a : b`
- Encapsulation dans une fonction
- Comparaison avec la fonction standard `fabsf()` de `<math.h>`

## Implémentation

```c
float valeur_absolue(float x) {
    return (x < 0) ? -x : x;
    /* Equivalent a fabsf(x) */
}
```

## Exemple

```
Nombre : -3.70
|-3.70| = 3.70

Nombre : 5.00
|+5.00| = 5.00
```

## Compilation

```bash
gcc -o valeur_absolue main.c
./valeur_absolue
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

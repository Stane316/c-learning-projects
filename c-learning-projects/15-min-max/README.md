# Fonctions Min et Max en C

## Description
Programme avec menu qui teste `Min`/`Max` pour 2 nombres
et `Min_4`/`Max_4` pour 4 nombres, construits par composition.

## Objectif pédagogique
- **Composition de fonctions** : `Min_4` bâti sur `Min`
- Opérateur ternaire
- Menu interactif avec validation

## Composition

```c
float Min_4(float a, float b, float c, float d) {
    return Min(Min(a, b), Min(c, d));  /* reutilise Min ! */
}
```

## Compilation

```bash
gcc -o min_max main.c
./min_max
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

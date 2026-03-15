# Détection d'une Année Bissextile en C

## Description
Détermine si une année est bissextile selon les règles du
calendrier grégorien.

## Objectif pédagogique
- Conditions imbriquées avec ordre de priorité
- Opérateur modulo `%`
- Encapsulation dans une fonction `est_bissextile()`

## Règle grégorienne

```
Bissextile si :
  divisible par 400  → OUI
  divisible par 100  → NON
  divisible par 4    → OUI
  sinon              → NON
```

## Exemples

```
2000 → bissextile   (400)
1900 → non          (100, pas 400)
2024 → bissextile   (4, pas 100)
2023 → non
```

## Compilation

```bash
gcc -o annee_bissextile main.c
./annee_bissextile
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

# Bulletins Scolaires en C

## Description
Gère les bulletins de N élèves avec M matières.
Calcule la moyenne, le rang et la mention de chaque élève.

## Objectif pédagogique
- Tableau de `struct` avec champs variables
- Calcul de rang par double boucle
- Mention selon une échelle (Insuffisant → Très Bien)
- `snprintf` pour construire un libellé dynamique

## Mentions

| Moyenne | Mention |
|---|---|
| ≥ 16 | Très Bien |
| ≥ 14 | Bien |
| ≥ 12 | Assez Bien |
| ≥ 10 | Passable |
| < 10 | Insuffisant |

## Compilation

```bash
gcc -o bulletins main.c
./bulletins
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

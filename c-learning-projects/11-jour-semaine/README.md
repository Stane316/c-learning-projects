# Jour de la Semaine en C

## Description
Lit un numéro de jour (1-7) et affiche le nom correspondant
via un `switch`. Inclut une alternative avec tableau en commentaire.

## Objectif pédagogique
- `switch/case` avec 7 cas
- Alternative : tableau `const char *[]` indexé

## Alternative avec tableau

```c
const char *jours[7] = {
    "Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi","Dimanche"
};
printf("%s\n", jours[jour - 1]);  /* plus concis */
```

## Exemple

```
Numero du jour : 3  →  Mercredi
Numero du jour : 7  →  Dimanche
```

## Compilation

```bash
gcc -o jour_semaine main.c
./jour_semaine
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

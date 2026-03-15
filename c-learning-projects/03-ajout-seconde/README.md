# Ajout d'une Seconde à l'Heure en C

## Description
Programme qui ajoute 1 seconde à une heure saisie (HH:MM:SS)
avec gestion complète des cascades de retenues.

## Objectif pédagogique
- Passage par **pointeurs** pour modifier plusieurs valeurs
- Cascade de retenues (59→00 pour secondes, minutes, heures)
- Validation d'entrée avec plage bornée
- Cas limite : 23:59:59 → 00:00:00

## Algorithme

```c
void ajouter_une_seconde(int *h, int *m, int *s) {
    (*s)++;
    if (*s == 60) { *s = 0; (*m)++;
        if (*m == 60) { *m = 0; (*h)++;
            if (*h == 24) *h = 0;
        }
    }
}
```

## Exemple

```
Heure initiale : 12:59:59
Heure + 1 sec  : 13:00:00

Heure initiale : 23:59:59
Heure + 1 sec  : 00:00:00  (passage a minuit)
```

## Compilation

```bash
gcc -o ajout_seconde main.c
./ajout_seconde
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

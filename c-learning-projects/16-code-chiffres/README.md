# Vérification d'un Code à 4 Chiffres en C

## Description
Extrait les 4 chiffres d'un code entier et les compare
au code secret chiffre par chiffre avec affichage positionnel.

## Objectif pédagogique
- Extraction de chiffres par division entière et modulo
- Comparaison positionnelle avec tableau `int[4]`
- Affichage visuel `v` / `x` par position

## Extraction des chiffres

```c
chiffre[0] = code / 1000;        /* milliers  */
chiffre[1] = (code / 100) % 10;  /* centaines */
chiffre[2] = (code / 10)  % 10;  /* dizaines  */
chiffre[3] = code % 10;          /* unites    */
```

## Compilation

```bash
gcc -o code_chiffres main.c
./code_chiffres
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

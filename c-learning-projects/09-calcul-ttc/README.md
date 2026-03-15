# Calcul du Prix TTC en C

## Description
Calcule le prix TTC à partir du prix HT en appliquant
une réduction de 15%, puis une TVA de 20%.

## Objectif pédagogique
- Calculs en cascade avec constantes `#define`
- Affichage formaté avec `%10.2f` pour alignement
- Boucle de relance `do-while`

## Formule

```
Prix remisé = Prix HT × (1 - 0.15)
Prix TTC    = Prix remisé × (1 + 0.20)
```

## Exemple

```
Prix HT              :    100.00
Reduction (15%)      :     -15.00
Prix apres reduction :     85.00
TVA (20%)            :     +17.00
Prix TTC             :    102.00
```

## Compilation

```bash
gcc -o calcul_ttc main.c
./calcul_ttc
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

# Facturation de Photocopies en C

## Description
Programme en langage C qui calcule le coût de photocopies selon
un tarif dégressif en 3 tranches.

## Objectif pédagogique
- Conditions `if/else if/else`
- Constantes `#define`
- Fonctions utilitaires (`calculer_facture`)
- Boucle de relance `do-while`

## Tarif dégressif

| Tranche | Tarif |
|---|---|
| 1 à 10 copies | 0.30 Dh / copie |
| 11 à 50 copies | 0.25 Dh / copie |
| 51+ copies | 0.20 Dh / copie |

## Exemple

```
Nombre de copies : 35
Tarif applique   : 0.25 Dh / copie
Montant total    : 8.75 Dh
```

## Compilation

```bash
gcc -o facturation main.c
./facturation
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

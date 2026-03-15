# Gestion de Comptes Bancaires en C

## Description
Crée des comptes bancaires, effectue dépôt/retrait et
liste tous les comptes. Données stockées en mémoire.

## Objectif pédagogique
- Tableau de `struct` globaux
- Recherche d'un enregistrement par numéro
- Gestion de cas d'erreur (solde insuffisant, compte introuvable)
- `strncpy` pour copier dans les champs de struct

## Fonctionnalités

| Option | Action |
|---|---|
| 1 | Créer un compte |
| 2 | Déposer de l'argent |
| 3 | Retirer de l'argent |
| 4 | Lister tous les comptes |

## Compilation

```bash
gcc -o comptes_bancaires main.c
./comptes_bancaires
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

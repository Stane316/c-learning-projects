# Vérification de Code PIN en C

## Description
Simule la vérification d'un code PIN avec 3 tentatives maximum.
Après 3 échecs, l'accès est refusé.

## Objectif pédagogique
- Boucle `do-while` avec double condition d'arrêt
- Compteur de tentatives avec messages restants
- Importance du **choix de type** (`int` vs `float` pour un PIN)
- Constantes `#define` pour les valeurs de configuration

## ⚠️ Note sécurité
PIN stocké en clair à des fins pédagogiques. En production : hachage cryptographique.

## Pourquoi `int` et pas `float` ?

```c
/* ❌ float peut échouer par approximation binaire */
float code = 5454;  if (saisi == code) ...

/* ✅ int est exact */
int code = 5454;    if (saisi == code) ...
```

## Exemple

```
Tentative 1/3 : 1234  →  Il vous reste 2 tentatives.
Tentative 2/3 : 9999  →  Il vous reste 1 tentative.
Tentative 3/3 : 5454  →  Acces autorise.
```

## Compilation

```bash
gcc -o verification_pin main.c
./verification_pin
```

## Auteur
**ANIAMBOSSOU Stane** — IFRI, Université d'Abomey-Calavi

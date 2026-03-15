/*
 * =============================================================================
 * Projet     : Somme de deux nombres reels
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Programme qui lit deux reels, calcule leur somme et affiche
 *              le signe du resultat (positif, negatif ou nul).
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EPSILON 1e-6f

/* --------------------------------------------------------------------------
 * Lit et valide un nombre reel avec libelle
 * -------------------------------------------------------------------------- */
float lire_reel(const char *label) {
    float nombre;
    char  caractere;

    while (1) {
        printf("  %s : ", label);
        if (scanf("%f%c", &nombre, &caractere) == 2 && caractere == '\n') {
            return nombre;
        }
        printf("Erreur ! Veuillez entrer un nombre reel valide (ex: 3.5, -2).\n");
        while (getchar() != '\n');
    }
}

/* --------------------------------------------------------------------------
 * Demande si l'utilisateur veut relancer le programme (O/N)
 * -------------------------------------------------------------------------- */
char demander_continuation() {
    char buffer[100];
    char reponse;

    while (1) {
        printf("\n=============================================================\n");
        printf("Voulez-vous relancer le programme ? (O/N) : ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strlen(buffer) == 1) {
                reponse = toupper(buffer[0]);
                if (reponse == 'O' || reponse == 'N') return reponse;
                printf("Erreur ! Veuillez entrer 'O' ou 'N'.\n");
            } else if (strlen(buffer) == 0) {
                printf("Erreur ! Vous n'avez rien entre.\n");
            } else {
                printf("Erreur ! Une seule lettre (O ou N).\n");
            }
        }
    }
}

/* --------------------------------------------------------------------------
 * Programme principal
 * -------------------------------------------------------------------------- */
int main() {
    float n1, n2, somme;
    char  continuer;

    do {
        printf("\n===========================================\n");
        printf("       SOMME DE DEUX NOMBRES REELS\n");
        printf("===========================================\n\n");

        n1    = lire_reel("Nombre 1");
        n2    = lire_reel("Nombre 2");
        somme = n1 + n2;

        printf("\n-------------------------------------------\n");
        printf("  %.2f + %.2f = %.2f\n", n1, n2, somme);

        if (fabsf(somme) < EPSILON)
            printf("  Resultat : NUL\n");
        else if (somme > 0)
            printf("  Resultat : POSITIF\n");
        else
            printf("  Resultat : NEGATIF\n");

        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

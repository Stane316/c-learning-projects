/*
 * =============================================================================
 * Projet     : Detection d'une annee bissextile
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Determine si une annee est bissextile selon les regles
 *              gregoriennes : divisible par 400 OU (divisible par 4
 *              ET non divisible par 100).
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------------------------------
 * Retourne 1 si l'annee est bissextile, 0 sinon
 * Ordre de priorite : 400 -> 100 -> 4 -> sinon
 * -------------------------------------------------------------------------- */
int est_bissextile(int annee) {
    if (annee % 400 == 0) return 1;
    if (annee % 100 == 0) return 0;
    if (annee % 4   == 0) return 1;
    return 0;
}

/* --------------------------------------------------------------------------
 * Lit et valide une annee (>= 1)
 * -------------------------------------------------------------------------- */
int lire_annee() {
    int  annee;
    char caractere;

    while (1) {
        printf("  Annee : ");
        if (scanf("%d%c", &annee, &caractere) == 2 && caractere == '\n') {
            if (annee >= 1) return annee;
            printf("Erreur ! L'annee doit etre positive.\n");
        } else {
            printf("Erreur ! Veuillez entrer un entier valide.\n");
            while (getchar() != '\n');
        }
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
    int  annee;
    char continuer;

    do {
        printf("\n===========================================\n");
        printf("       DETECTION D'ANNEE BISSEXTILE\n");
        printf("===========================================\n\n");

        annee = lire_annee();

        printf("\n-------------------------------------------\n");
        if (est_bissextile(annee)) {
            printf("  %d est une annee BISSEXTILE.\n", annee);
            printf("  Fevrier a 29 jours — soit %d jours au total.\n",
                   366);
        } else {
            printf("  %d n'est PAS une annee bissextile.\n", annee);
            printf("  Fevrier a 28 jours — soit %d jours au total.\n",
                   365);
        }
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

/*
 * =============================================================================
 * Projet     : Calcul du prix TTC
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Calcule le prix TTC a partir du prix HT en appliquant
 *              une reduction de 15%, puis une TVA de 20%.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAUX_REDUCTION 0.15f
#define TAUX_TVA       0.20f

/* --------------------------------------------------------------------------
 * Lit et valide un prix strictement positif
 * -------------------------------------------------------------------------- */
float lire_prix_ht() {
    float prix;
    char  caractere;

    while (1) {
        printf("  Prix HT : ");
        if (scanf("%f%c", &prix, &caractere) == 2 && caractere == '\n') {
            if (prix > 0) return prix;
            printf("Erreur ! Le prix doit etre strictement positif.\n");
        } else {
            printf("Erreur ! Veuillez entrer un reel valide.\n");
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
    float prix_ht, remise, prix_remise, tva, prix_ttc;
    char  continuer;

    do {
        printf("\n===========================================\n");
        printf("           CALCUL DU PRIX TTC\n");
        printf("===========================================\n\n");
        printf("  Reduction : %.0f%%  |  TVA : %.0f%%\n\n",
               TAUX_REDUCTION * 100, TAUX_TVA * 100);

        prix_ht     = lire_prix_ht();
        remise      = prix_ht * TAUX_REDUCTION;
        prix_remise = prix_ht - remise;
        tva         = prix_remise * TAUX_TVA;
        prix_ttc    = prix_remise + tva;

        printf("\n-------------------------------------------\n");
        printf("  Prix HT             : %10.2f\n", prix_ht);
        printf("  Reduction (15%%)     : -%9.2f\n", remise);
        printf("  Prix apres reduction: %10.2f\n", prix_remise);
        printf("  TVA (20%%)           : +%9.2f\n", tva);
        printf("  ---\n");
        printf("  Prix TTC            : %10.2f\n", prix_ttc);
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

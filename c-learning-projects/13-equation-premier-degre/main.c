/*
 * =============================================================================
 * Projet     : Resolution d'equation du premier degre
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Resout ax + b = 0 avec 3 cas :
 *              - solution unique  : x = -b/a  (si a != 0)
 *              - aucune solution  : (si a == 0 et b != 0)
 *              - infinite de sol. : (si a == 0 et b == 0)
 *              Verifie la solution par substitution.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EPSILON 1e-6f

/* --------------------------------------------------------------------------
 * Lit et valide un reel avec message
 * -------------------------------------------------------------------------- */
float lire_reel(const char *message) {
    float nombre;
    char  caractere;

    while (1) {
        printf("%s", message);
        if (scanf("%f%c", &nombre, &caractere) == 2 && caractere == '\n') {
            return nombre;
        }
        printf("Erreur ! Veuillez entrer un nombre reel valide.\n");
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
    float a, b, x;
    float verification;
    char  continuer;

    do {
        printf("\n===========================================\n");
        printf("    EQUATION DU PREMIER DEGRE : ax + b = 0\n");
        printf("===========================================\n\n");

        a = lire_reel("  Coefficient a : ");
        b = lire_reel("  Coefficient b : ");

        printf("\n-------------------------------------------\n");
        printf("  Equation : %.2fx + %.2f = 0\n\n", a, b);

        if (fabsf(a) < EPSILON) {
            /* a == 0 : equation devient b = 0 */
            if (fabsf(b) < EPSILON)
                printf("  Infinite de solutions (0x + 0 = 0 toujours vrai).\n");
            else
                printf("  Aucune solution (%.2f = 0 impossible).\n", b);
        } else {
            x = -b / a;
            printf("  Solution unique : x = %.6f\n", x);

            /* Verification par substitution */
            verification = a * x + b;
            if (fabsf(verification) < EPSILON)
                printf("  Verification : %.2f * %.6f + %.2f = %.2e ✓\n",
                       a, x, b, verification);
            else
                printf("  Verification : ecart = %.2e (approximation flottante)\n",
                       verification);
        }
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

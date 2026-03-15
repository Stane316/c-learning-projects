/*
 * =============================================================================
 * Projet     : Valeur absolue
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Calcule la valeur absolue d'un reel de facon manuelle
 *              (sans fabsf()), a des fins pedagogiques.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------------------------------
 * Retourne la valeur absolue d'un reel (implementation manuelle)
 * Equivalent pedagogique de fabsf() de <math.h>
 * -------------------------------------------------------------------------- */
float valeur_absolue(float x) {
    return (x < 0) ? -x : x;
    /* Version equivalente avec fabsf() : return fabsf(x); */
}

/* --------------------------------------------------------------------------
 * Lit et valide un nombre reel
 * -------------------------------------------------------------------------- */
float lire_reel(const char *label) {
    float nombre;
    char  caractere;

    while (1) {
        printf("  %s : ", label);
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
    float nombre;
    char  continuer;

    do {
        printf("\n===========================================\n");
        printf("            VALEUR ABSOLUE\n");
        printf("===========================================\n\n");

        nombre = lire_reel("Nombre");

        printf("\n-------------------------------------------\n");
        printf("  |%+.2f| = %.2f\n", nombre, valeur_absolue(nombre));
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

/*
 * =============================================================================
 * Projet     : Test de parite (pair ou impair)
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Determine si un entier est pair ou impair avec l'operateur
 *              modulo. Fonctionne aussi pour les nombres negatifs.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------------------------------
 * Lit et valide un entier (positif, negatif ou nul)
 * -------------------------------------------------------------------------- */
int lire_entier(const char *label) {
    int  nombre;
    char caractere;

    while (1) {
        printf("  %s : ", label);
        if (scanf("%d%c", &nombre, &caractere) == 2 && caractere == '\n') {
            return nombre;
        }
        printf("Erreur ! Veuillez entrer un nombre entier valide.\n");
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
    int  nombre;
    char continuer;

    do {
        printf("\n===========================================\n");
        printf("          TEST PAIR / IMPAIR\n");
        printf("===========================================\n\n");

        nombre = lire_entier("Entier");

        printf("\n-------------------------------------------\n");
        /*
         * nombre % 2 fonctionne aussi pour les negatifs en C :
         * -3 % 2 == -1 (different de 0) → impair ✓
         * -4 % 2 ==  0                  → pair   ✓
         */
        if (nombre == 0)
            printf("  %d est NUL (pair par convention).\n", nombre);
        else if (nombre % 2 == 0)
            printf("  %d est PAIR.\n", nombre);
        else
            printf("  %d est IMPAIR.\n", nombre);
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

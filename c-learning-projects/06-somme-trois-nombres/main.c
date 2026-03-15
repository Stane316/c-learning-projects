/*
 * =============================================================================
 * Projet     : Somme de trois nombres - verification
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Verifie si l'un des 3 nombres saisis est egal a la somme
 *              des deux autres. Comparaison securisee avec epsilon.
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
    float n1, n2, n3;
    char  continuer;

    do {
        printf("\n===========================================\n");
        printf("   VERIFICATION : UN = SOMME DES DEUX AUTRES\n");
        printf("===========================================\n\n");

        n1 = lire_reel("Nombre 1");
        n2 = lire_reel("Nombre 2");
        n3 = lire_reel("Nombre 3");

        printf("\n-------------------------------------------\n");
        printf("  Nombres : %.2f | %.2f | %.2f\n", n1, n2, n3);

        /*
         * Comparaison securisee avec epsilon :
         * on evite == sur des float.
         */
        if (fabsf(n1 - (n2 + n3)) < EPSILON)
            printf("  OUI : %.2f = %.2f + %.2f\n", n1, n2, n3);
        else if (fabsf(n2 - (n1 + n3)) < EPSILON)
            printf("  OUI : %.2f = %.2f + %.2f\n", n2, n1, n3);
        else if (fabsf(n3 - (n1 + n2)) < EPSILON)
            printf("  OUI : %.2f = %.2f + %.2f\n", n3, n1, n2);
        else
            printf("  NON : aucun nombre n'est egal a la somme des deux autres.\n");

        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

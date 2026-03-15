/*
 * =============================================================================
 * Projet     : Verification de l'ordre alphabetique de 3 lettres
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Verifie si 3 lettres saisies sont en ordre alphabetique
 *              croissant, insensible a la casse.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------------------------------
 * Lit et valide une lettre unique avec diagnostic precis
 * -------------------------------------------------------------------------- */
char lire_lettre(const char *label) {
    char buffer[100];
    char c;

    while (1) {
        printf("  %s : ", label);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strlen(buffer) == 1) {
                c = buffer[0];
                if (isalpha(c)) return toupper(c);
                if (isdigit(c))
                    printf("Erreur ! '%c' est un chiffre — entrez une lettre.\n", c);
                else if (ispunct(c))
                    printf("Erreur ! '%c' est un signe — entrez une lettre.\n", c);
                else
                    printf("Erreur ! Caractere non reconnu.\n");
            } else if (strlen(buffer) == 0) {
                printf("Erreur ! Vous n'avez rien entre.\n");
            } else {
                printf("Erreur ! Entrez une seule lettre.\n");
            }
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
    char l1, l2, l3;
    char continuer;

    do {
        printf("\n===========================================\n");
        printf("     ORDRE ALPHABETIQUE DE 3 LETTRES\n");
        printf("===========================================\n\n");

        l1 = lire_lettre("Lettre 1");
        l2 = lire_lettre("Lettre 2");
        l3 = lire_lettre("Lettre 3");

        printf("\n-------------------------------------------\n");
        printf("  Lettres (maj.) : %c, %c, %c\n", l1, l2, l3);

        if (l1 < l2 && l2 < l3)
            printf("  Ordre alphabetique STRICT : %c < %c < %c\n", l1, l2, l3);
        else if (l1 <= l2 && l2 <= l3)
            printf("  Ordre alphabetique (avec doublons) : %c <= %c <= %c\n",
                   l1, l2, l3);
        else
            printf("  PAS en ordre alphabetique.\n");

        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

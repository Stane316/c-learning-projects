/*
 * =============================================================================
 * Projet     : Menu avec code de selection
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Programme qui affiche un menu, lit un code (1/2/3) et
 *              execute l'action correspondante via un switch.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------------------------------
 * Lit et valide un choix de menu (1, 2 ou 3)
 * -------------------------------------------------------------------------- */
int lire_choix() {
    int  choix;
    char caractere;

    while (1) {
        printf("  Votre choix (1-3) : ");
        if (scanf("%d%c", &choix, &caractere) == 2 && caractere == '\n') {
            if (choix >= 1 && choix <= 3) return choix;
            printf("Erreur ! Veuillez choisir 1, 2 ou 3.\n");
        } else {
            printf("Erreur ! Veuillez entrer un nombre entier.\n");
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
    int  choix;
    char continuer;

    do {
        printf("\n===========================================\n");
        printf("         MENU DE SELECTION\n");
        printf("===========================================\n\n");
        printf("  1. Afficher un message de bienvenue\n");
        printf("  2. Afficher la date du jour\n");
        printf("  3. Quitter le menu\n\n");

        choix = lire_choix();

        printf("\n-------------------------------------------\n");
        switch (choix) {
            case 1:
                printf("  Bonjour et bienvenue dans ce programme C !\n");
                printf("  Nous esperons que vous apprenez bien.\n");
                break;
            case 2:
                printf("  Fonctionnalite : affichage de la date.\n");
                printf("  (Utilisez <time.h> en production.)\n");
                break;
            case 3:
                printf("  Vous avez choisi de quitter le menu.\n");
                break;
            default:
                printf("  Choix non reconnu.\n");
                break;
        }
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

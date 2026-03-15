/*
 * =============================================================================
 * Projet     : Affichage du jour de la semaine
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Lit un numero de jour (1-7) et affiche le nom correspondant
 *              via un switch. Alternative avec tableau de chaines en commentaire.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------------------------------
 * Lit et valide un numero de jour (1-7)
 * -------------------------------------------------------------------------- */
int lire_jour() {
    int  jour;
    char caractere;

    while (1) {
        printf("  Numero du jour (1=Lundi ... 7=Dimanche) : ");
        if (scanf("%d%c", &jour, &caractere) == 2 && caractere == '\n') {
            if (jour >= 1 && jour <= 7) return jour;
            printf("Erreur ! Valeur entre 1 et 7 requise.\n");
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
    int  jour;
    char continuer;

    /*
     * Alternative avec tableau (commentee a des fins pedagogiques) :
     * const char *jours[7] = {
     *     "Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi","Dimanche"
     * };
     * printf("%s\n", jours[jour - 1]);
     */

    do {
        printf("\n===========================================\n");
        printf("       JOUR DE LA SEMAINE\n");
        printf("===========================================\n\n");

        jour = lire_jour();

        printf("\n-------------------------------------------\n");
        printf("  Jour %d : ", jour);
        switch (jour) {
            case 1: printf("Lundi\n");     break;
            case 2: printf("Mardi\n");     break;
            case 3: printf("Mercredi\n");  break;
            case 4: printf("Jeudi\n");     break;
            case 5: printf("Vendredi\n");  break;
            case 6: printf("Samedi\n");    break;
            case 7: printf("Dimanche\n");  break;
            default: printf("Inconnu\n");  break;
        }
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

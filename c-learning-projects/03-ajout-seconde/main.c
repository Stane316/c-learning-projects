/*
 * =============================================================================
 * Projet     : Ajout d'une seconde a une heure
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Programme qui ajoute 1 seconde a une heure saisie au format
 *              HH:MM:SS avec cascade de retenues (59->00, 23->00).
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------------------------------
 * Lit et valide un entier dans une plage [min, max] avec libelle
 * -------------------------------------------------------------------------- */
int lire_entier_borne(int min, int max, const char *label) {
    int  nombre;
    char caractere;

    while (1) {
        printf("  %s (%d-%d) : ", label, min, max);
        if (scanf("%d%c", &nombre, &caractere) == 2 && caractere == '\n') {
            if (nombre >= min && nombre <= max) return nombre;
            printf("Erreur ! Valeur entre %d et %d requise.\n", min, max);
        } else {
            printf("Erreur ! Veuillez entrer un entier valide.\n");
            while (getchar() != '\n');
        }
    }
}

/* --------------------------------------------------------------------------
 * Ajoute une seconde a l'heure (h, m, s) avec cascade de retenues
 * -------------------------------------------------------------------------- */
void ajouter_une_seconde(int *h, int *m, int *s) {
    (*s)++;
    if (*s == 60) {
        *s = 0;
        (*m)++;
        if (*m == 60) {
            *m = 0;
            (*h)++;
            if (*h == 24) {
                *h = 0;  /* Passage a minuit */
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
    int  heures, minutes, secondes;
    int  h2, m2, s2;
    char continuer;

    do {
        printf("\n===========================================\n");
        printf("       AJOUT D'UNE SECONDE A L'HEURE\n");
        printf("===========================================\n\n");

        heures   = lire_entier_borne(0, 23, "Heures  ");
        minutes  = lire_entier_borne(0, 59, "Minutes ");
        secondes = lire_entier_borne(0, 59, "Secondes");

        /* Copie pour modification */
        h2 = heures;
        m2 = minutes;
        s2 = secondes;

        ajouter_une_seconde(&h2, &m2, &s2);

        printf("\n-------------------------------------------\n");
        printf("  Heure initiale  : %02d:%02d:%02d\n",
               heures, minutes, secondes);
        printf("  Heure + 1 sec   : %02d:%02d:%02d\n", h2, m2, s2);

        if (heures == 23 && minutes == 59 && secondes == 59)
            printf("  (passage a minuit)\n");

        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

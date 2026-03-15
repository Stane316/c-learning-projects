/*
 * =============================================================================
 * Projet     : Verification d'inscription
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Programme qui verifie si un nom figure dans la liste des
 *              inscrits, et propose Java ou C si l'etudiant n'est pas inscrit.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NB_INSCRITS 5

/* Liste des etudiants inscrits */
const char *inscrits[NB_INSCRITS] = {
    "DUPONT", "MARTIN", "DURAND", "LEROY", "BERNARD"
};

/* --------------------------------------------------------------------------
 * Convertit une chaine en majuscules dans le buffer dest
 * -------------------------------------------------------------------------- */
void vers_majuscules(const char *src, char *dest, int taille) {
    int i;
    for (i = 0; i < taille - 1 && src[i] != '\0'; i++)
        dest[i] = toupper(src[i]);
    dest[i] = '\0';
}

/* --------------------------------------------------------------------------
 * Retourne 1 si le nom est dans la liste des inscrits, 0 sinon
 * -------------------------------------------------------------------------- */
int est_inscrit(const char *nom) {
    int i;
    char nom_maj[50];
    vers_majuscules(nom, nom_maj, sizeof(nom_maj));
    for (i = 0; i < NB_INSCRITS; i++) {
        if (strcmp(nom_maj, inscrits[i]) == 0)
            return 1;
    }
    return 0;
}

/* --------------------------------------------------------------------------
 * Lit un nom de famille via fgets
 * -------------------------------------------------------------------------- */
void lire_nom(char *dest, int taille) {
    while (1) {
        if (fgets(dest, taille, stdin) != NULL) {
            dest[strcspn(dest, "\n")] = '\0';
            if (strlen(dest) > 0) return;
            printf("Erreur ! Le nom ne peut pas etre vide.\n");
            printf("Nom : ");
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
    char nom[50];
    char choix_langage[10];
    char continuer;

    do {
        printf("\n===========================================\n");
        printf("       VERIFICATION D'INSCRIPTION\n");
        printf("===========================================\n\n");

        printf("  Entrez votre nom (insensible a la casse) : ");
        lire_nom(nom, sizeof(nom));

        printf("\n-------------------------------------------\n");
        if (est_inscrit(nom)) {
            printf("  Bienvenue ! %s est bien inscrit(e).\n", nom);
        } else {
            printf("  %s n'est pas dans la liste des inscrits.\n\n", nom);
            printf("  Choisissez un langage pour vous inscrire :\n");
            printf("    1. Java\n");
            printf("    2. C\n");
        }
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

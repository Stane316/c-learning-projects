/*
 * =============================================================================
 * Projet     : Facturation de photocopies
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Programme qui calcule le cout de photocopies selon un tarif
 *              degressif en 3 tranches, avec boucle de relance.
 *
 *  Tarif :
 *    1  a  10 copies  : 0.30 Dh / copie
 *   11  a  50 copies  : 0.25 Dh / copie
 *   51+    copies     : 0.20 Dh / copie
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TARIF_1  0.30f
#define TARIF_2  0.25f
#define TARIF_3  0.20f
#define SEUIL_1  10
#define SEUIL_2  50

/* --------------------------------------------------------------------------
 * Calcule le montant selon le tarif degressif
 * -------------------------------------------------------------------------- */
float calculer_facture(int nb_copies) {
    if (nb_copies <= SEUIL_1)
        return nb_copies * TARIF_1;
    else if (nb_copies <= SEUIL_2)
        return nb_copies * TARIF_2;
    else
        return nb_copies * TARIF_3;
}

/* --------------------------------------------------------------------------
 * Lit et valide un entier strictement positif
 * -------------------------------------------------------------------------- */
int lire_entier_positif(const char *message) {
    int  nombre;
    char caractere;

    while (1) {
        printf("%s", message);
        if (scanf("%d%c", &nombre, &caractere) == 2 && caractere == '\n') {
            if (nombre > 0) return nombre;
            printf("Erreur ! Le nombre doit etre strictement positif (> 0).\n");
        } else {
            printf("Erreur ! Veuillez entrer un nombre entier valide.\n");
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
                printf("Erreur ! Veuillez entrer 'O' pour Oui ou 'N' pour Non.\n");
            } else if (strlen(buffer) == 0) {
                printf("Erreur ! Vous n'avez rien entre.\n");
            } else {
                printf("Erreur ! Entrez une seule lettre (O ou N).\n");
            }
        }
    }
}

/* --------------------------------------------------------------------------
 * Programme principal
 * -------------------------------------------------------------------------- */
int main() {
    int   nb_copies;
    float montant;
    float tarif_applique;
    char  continuer;

    do {
        printf("\n===========================================\n");
        printf("       FACTURATION DE PHOTOCOPIES\n");
        printf("===========================================\n\n");
        printf("  Tarif degressif :\n");
        printf("    1  a  10 copies : %.2f Dh / copie\n", TARIF_1);
        printf("   11  a  50 copies : %.2f Dh / copie\n", TARIF_2);
        printf("   51+    copies    : %.2f Dh / copie\n\n", TARIF_3);

        nb_copies = lire_entier_positif("Nombre de copies : ");
        montant   = calculer_facture(nb_copies);

        if      (nb_copies <= SEUIL_1) tarif_applique = TARIF_1;
        else if (nb_copies <= SEUIL_2) tarif_applique = TARIF_2;
        else                           tarif_applique = TARIF_3;

        printf("\n-------------------------------------------\n");
        printf("  Nombre de copies : %d\n", nb_copies);
        printf("  Tarif applique   : %.2f Dh / copie\n", tarif_applique);
        printf("  Montant total    : %.2f Dh\n", montant);
        printf("-------------------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

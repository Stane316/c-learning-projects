/*
 * =============================================================================
 * Projet     : Verification de code PIN
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Simule la verification d'un code PIN avec 3 tentatives
 *              maximum. Apres 3 echecs, l'acces est refuse.
 *
 * AVERTISSEMENT PEDAGOGIQUE : Dans ce programme d'apprentissage, le code
 * PIN est stocke en clair comme constante. En production, on utiliserait
 * un hachage cryptographique (bcrypt, SHA-256...).
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CODE_PIN_CORRECT  5454
#define MAX_TENTATIVES    3

/* --------------------------------------------------------------------------
 * Lit et valide un code PIN (entier)
 * -------------------------------------------------------------------------- */
int lire_code_pin() {
    int  code;
    char caractere;

    while (1) {
        if (scanf("%d%c", &code, &caractere) == 2 && caractere == '\n') {
            return code;
        }
        printf("Erreur ! Code PIN invalide. Entrez uniquement des chiffres.\n");
        printf("Code PIN : ");
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
    int  code_saisi;
    int  tentatives;
    int  acces_autorise;
    char continuer;

    do {
        printf("\n================================\n");
        printf("    VERIFICATION CODE PIN\n");
        printf("================================\n");
        printf("  Tentatives maximum : %d\n\n", MAX_TENTATIVES);

        tentatives     = 0;
        acces_autorise = 0;

        do {
            tentatives++;
            printf("  Tentative %d/%d — Code PIN : ", tentatives, MAX_TENTATIVES);
            code_saisi = lire_code_pin();

            if (code_saisi == CODE_PIN_CORRECT) {
                acces_autorise = 1;
            } else {
                int restantes = MAX_TENTATIVES - tentatives;
                if (restantes > 0) {
                    printf("  Code incorrect ! Il vous reste %d tentative%s.\n\n",
                           restantes, restantes > 1 ? "s" : "");
                } else {
                    printf("  Code incorrect !\n");
                }
            }

        } while (!acces_autorise && tentatives < MAX_TENTATIVES);

        printf("\n--------------------------------\n");
        if (acces_autorise) {
            printf("  Code correct — Acces autorise.\n");
        } else {
            printf("  Tentatives epuisees.\n");
            printf("  Acces refuse — Carte bloquee.\n");
        }
        printf("--------------------------------\n");

        continuer = demander_continuation();

    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");

    return 0;
}

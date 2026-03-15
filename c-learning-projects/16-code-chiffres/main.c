/*
 * =============================================================================
 * Projet     : Verification d'un code a 4 chiffres
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Extrait les 4 chiffres d'un code entier et les compare
 *              a un code secret chiffre par chiffre.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CODE_SECRET 4827
#define NB_CHIFFRES 4

int lire_code() {
    int code; char c;
    while (1) {
        printf("  Code (4 chiffres) : ");
        if (scanf("%d%c", &code, &c) == 2 && c == '\n') {
            if (code >= 1000 && code <= 9999) return code;
            printf("Erreur ! Le code doit avoir exactement 4 chiffres.\n");
        } else { printf("Erreur ! Entier requis.\n"); while (getchar()!='\n'); }
    }
}

char demander_continuation() {
    char buf[100]; char r;
    while (1) {
        printf("\n=============================================================\n");
        printf("Voulez-vous relancer le programme ? (O/N) : ");
        if (fgets(buf, sizeof(buf), stdin)) {
            buf[strcspn(buf,"\n")]='\0';
            if (strlen(buf)==1) { r=toupper(buf[0]); if(r=='O'||r=='N') return r; }
            printf("Erreur ! O ou N uniquement.\n");
        }
    }
}

int main() {
    int code, secret[NB_CHIFFRES], saisi[NB_CHIFFRES];
    int i, tmp, correct;
    char continuer;

    /* Extraire les chiffres du code secret */
    tmp = CODE_SECRET;
    secret[0] = tmp / 1000;       /* milliers */
    secret[1] = (tmp / 100) % 10; /* centaines */
    secret[2] = (tmp / 10)  % 10; /* dizaines */
    secret[3] = tmp % 10;         /* unites */

    do {
        printf("\n===========================================\n");
        printf("     VERIFICATION CODE A 4 CHIFFRES\n");
        printf("===========================================\n\n");

        code = lire_code();
        tmp = code;
        saisi[0] = tmp / 1000;
        saisi[1] = (tmp / 100) % 10;
        saisi[2] = (tmp / 10)  % 10;
        saisi[3] = tmp % 10;

        correct = 1;
        printf("\n-------------------------------------------\n");
        printf("  Position :  [1]  [2]  [3]  [4]\n");
        printf("  Saisi    :  ");
        for (i = 0; i < NB_CHIFFRES; i++) printf("  %d  ", saisi[i]);
        printf("\n  Resultat :  ");
        for (i = 0; i < NB_CHIFFRES; i++) {
            if (saisi[i] == secret[i]) printf("  v  ");
            else { printf("  x  "); correct = 0; }
        }
        printf("\n");
        if (correct) printf("  Code CORRECT — Acces autorise.\n");
        else         printf("  Code INCORRECT — Acces refuse.\n");
        printf("-------------------------------------------\n");

        continuer = demander_continuation();
    } while (continuer == 'O');

    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

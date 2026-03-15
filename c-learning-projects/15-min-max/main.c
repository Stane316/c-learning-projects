/*
 * =============================================================================
 * Projet     : Fonctions Min et Max (2 et 4 nombres)
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Programme avec menu qui teste des fonctions de recherche du
 *              minimum et du maximum. Min_4 et Max_4 sont construits par
 *              composition de Min et Max — principe de reutilisabilite.
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

float Min(float a, float b) { return (a < b) ? a : b; }
float Max(float a, float b) { return (a > b) ? a : b; }
float Min_4(float a, float b, float c, float d) { return Min(Min(a,b), Min(c,d)); }
float Max_4(float a, float b, float c, float d) { return Max(Max(a,b), Max(c,d)); }

float lire_reel(const char *label) {
    float nombre; char caractere;
    while (1) {
        printf("%s", label);
        if (scanf("%f%c", &nombre, &caractere) == 2 && caractere == '\n') return nombre;
        printf("Erreur ! Nombre reel valide requis.\n");
        while (getchar() != '\n');
    }
}

int lire_choix() {
    int choix; char caractere;
    while (1) {
        printf("Votre choix (1 ou 2) : ");
        if (scanf("%d%c", &choix, &caractere) == 2 && caractere == '\n') {
            if (choix == 1 || choix == 2) return choix;
            printf("Erreur ! Choisir 1 ou 2.\n");
        } else { printf("Erreur ! Entier requis.\n"); while (getchar() != '\n'); }
    }
}

char demander_continuation() {
    char buffer[100]; char reponse;
    while (1) {
        printf("\n=============================================================\n");
        printf("Voulez-vous relancer le programme ? (O/N) : ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strlen(buffer) == 1) {
                reponse = toupper(buffer[0]);
                if (reponse == 'O' || reponse == 'N') return reponse;
                printf("Erreur ! Entrez 'O' ou 'N'.\n");
            } else if (strlen(buffer) == 0) {
                printf("Erreur ! Rien saisi.\n");
            } else {
                printf("Erreur ! Une seule lettre.\n");
            }
        }
    }
}

void test_2_nombres() {
    float n1, n2;
    printf("\n=============================================\n");
    printf("  TEST MIN ET MAX — 2 NOMBRES\n");
    printf("=============================================\n\n");
    n1 = lire_reel("  Nombre 1 : ");
    n2 = lire_reel("  Nombre 2 : ");
    printf("\n---------------------------------------------\n");
    printf("  Nombres : %.2f  et  %.2f\n", n1, n2);
    printf("  Minimum : %.2f\n", Min(n1, n2));
    printf("  Maximum : %.2f\n", Max(n1, n2));
    printf("---------------------------------------------\n");
}

void test_4_nombres() {
    float n1, n2, n3, n4;
    printf("\n=============================================\n");
    printf("  TEST MIN_4 ET MAX_4 — 4 NOMBRES\n");
    printf("=============================================\n\n");
    n1 = lire_reel("  Nombre 1 : ");
    n2 = lire_reel("  Nombre 2 : ");
    n3 = lire_reel("  Nombre 3 : ");
    n4 = lire_reel("  Nombre 4 : ");
    printf("\n---------------------------------------------\n");
    printf("  Nombres : %.2f | %.2f | %.2f | %.2f\n", n1, n2, n3, n4);
    printf("  Minimum : %.2f\n", Min_4(n1, n2, n3, n4));
    printf("  Maximum : %.2f\n", Max_4(n1, n2, n3, n4));
    printf("  Etapes Min_4 : Min(%.2f,%.2f)=%.2f | Min(%.2f,%.2f)=%.2f\n",
           n1, n2, Min(n1,n2), n3, n4, Min(n3,n4));
    printf("  Etapes Max_4 : Max(%.2f,%.2f)=%.2f | Max(%.2f,%.2f)=%.2f\n",
           n1, n2, Max(n1,n2), n3, n4, Max(n3,n4));
    printf("---------------------------------------------\n");
}

int main() {
    int choix; char continuer;
    do {
        printf("\n=============================================================\n");
        printf("         FONCTIONS MIN ET MAX — MENU PRINCIPAL\n");
        printf("=============================================================\n\n");
        printf("  1. Tester Min et Max   avec 2 nombres\n");
        printf("  2. Tester Min_4 et Max_4 avec 4 nombres\n\n");
        choix = lire_choix();
        if (choix == 1) test_2_nombres();
        else            test_4_nombres();
        continuer = demander_continuation();
    } while (continuer == 'O');

    printf("\n=============================================================\n");
    printf("        Merci d'avoir utilise ce programme. Au revoir !\n");
    printf("=============================================================\n\n");
    return 0;
}

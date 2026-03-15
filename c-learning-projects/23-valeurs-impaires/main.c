/*
 * =============================================================================
 * Projet     : Extraction des valeurs impaires d'un tableau
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAILLE 10

char demander_continuation() {
    char buf[100]; char r;
    while (1) {
        printf("\n=============================================================\n");
        printf("Voulez-vous relancer le programme ? (O/N) : ");
        if (fgets(buf,sizeof(buf),stdin)) {
            buf[strcspn(buf,"\n")]='\0';
            if (strlen(buf)==1){r=toupper(buf[0]);if(r=='O'||r=='N')return r;}
            printf("Erreur ! O ou N.\n");
        }
    }
}

int main() {
    int tab[TAILLE], i, nb_impairs; char c, continuer;
    do {
        printf("\n===========================================\n");
        printf("  VALEURS IMPAIRES D'UN TABLEAU\n");
        printf("===========================================\n\n");
        for (i=0; i<TAILLE; i++) {
            while (1) {
                printf("  tab[%d] : ", i);
                if (scanf("%d%c",&tab[i],&c)==2&&c=='\n') break;
                printf("Erreur ! Entier requis.\n"); while(getchar()!='\n');
            }
        }
        printf("\n-------------------------------------------\n");
        printf("  Tableau   : ");
        for (i=0; i<TAILLE; i++) printf("%d ", tab[i]);
        printf("\n  Impairs   : ");
        nb_impairs=0;
        for (i=0; i<TAILLE; i++) if (tab[i]%2!=0) { printf("%d ", tab[i]); nb_impairs++; }
        if (nb_impairs==0) printf("(aucun)");
        printf("\n  Ratio     : %d/%d impairs\n", nb_impairs, TAILLE);
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

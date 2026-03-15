/*
 * =============================================================================
 * Projet     : Minimum d'un tableau de 10 entiers
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
    int tab[TAILLE], i, min, pos; char c, continuer;
    do {
        printf("\n===========================================\n");
        printf("  MINIMUM D'UN TABLEAU DE %d ENTIERS\n", TAILLE);
        printf("===========================================\n\n");
        for (i=0; i<TAILLE; i++) {
            while (1) {
                printf("  tab[%d] : ", i);
                if (scanf("%d%c",&tab[i],&c)==2&&c=='\n') break;
                printf("Erreur ! Entier requis.\n");
                while(getchar()!='\n');
            }
        }
        min=tab[0]; pos=0;
        for (i=1; i<TAILLE; i++) if (tab[i]<min) { min=tab[i]; pos=i; }

        printf("\n-------------------------------------------\n");
        printf("  Tableau : ");
        for (i=0; i<TAILLE; i++) {
            if (i==pos) printf("[%d] ", tab[i]);
            else        printf("%d ", tab[i]);
        }
        printf("\n  Minimum : %d  (position %d, indice %d)\n", min, pos+1, pos);
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

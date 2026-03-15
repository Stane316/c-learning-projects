/*
 * =============================================================================
 * Projet     : Maximum d'une matrice 3x3
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIGNES   3
#define COLONNES 3

void afficher_matrice(int m[LIGNES][COLONNES], int li, int ci) {
    int i,j;
    for (i=0;i<LIGNES;i++) {
        printf("  ");
        for (j=0;j<COLONNES;j++) {
            if (i==li&&j==ci) printf("[%3d] ", m[i][j]);
            else              printf("%4d  ", m[i][j]);
        }
        printf("\n");
    }
}

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
    int mat[LIGNES][COLONNES], i, j, max, li_max, ci_max; char c, continuer;
    do {
        printf("\n===========================================\n");
        printf("   MAXIMUM D'UNE MATRICE %dx%d\n", LIGNES, COLONNES);
        printf("===========================================\n\n");
        for (i=0;i<LIGNES;i++)
            for (j=0;j<COLONNES;j++) {
                while (1) {
                    printf("  mat[%d][%d] : ",i,j);
                    if (scanf("%d%c",&mat[i][j],&c)==2&&c=='\n') break;
                    printf("Erreur ! Entier requis.\n"); while(getchar()!='\n');
                }
            }
        max=mat[0][0]; li_max=0; ci_max=0;
        for (i=0;i<LIGNES;i++)
            for (j=0;j<COLONNES;j++)
                if (mat[i][j]>max) { max=mat[i][j]; li_max=i; ci_max=j; }

        printf("\n-------------------------------------------\n");
        printf("  Matrice (max entre crochets) :\n\n");
        afficher_matrice(mat, li_max, ci_max);
        printf("\n  Maximum : %d  (ligne %d, colonne %d)\n", max, li_max+1, ci_max+1);
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

/*
 * =============================================================================
 * Projet     : Comptage de valeurs dans une matrice
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Compte les valeurs positives, negatives et nulles d'une matrice.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LIGNES   5
#define MAX_COLONNES 5
#define EPSILON 1e-6f

int lire_dim(const char *label, int max) {
    int n; char c;
    while (1) {
        printf("  %s (1-%d) : ", label, max);
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=1&&n<=max) return n;
        printf("Erreur ! Valeur entre 1 et %d.\n",max); while(getchar()!='\n');
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
    float mat[MAX_LIGNES][MAX_COLONNES];
    int lignes, colonnes, i, j, pos, neg, nuls, total; char c, continuer;
    do {
        printf("\n===========================================\n");
        printf("   COMPTAGE DE VALEURS DANS UNE MATRICE\n");
        printf("===========================================\n\n");
        lignes   = lire_dim("Lignes",   MAX_LIGNES);
        colonnes = lire_dim("Colonnes", MAX_COLONNES);
        total = lignes * colonnes;
        printf("\n");
        for (i=0;i<lignes;i++)
            for (j=0;j<colonnes;j++) {
                while(1){
                    printf("  mat[%d][%d] : ",i,j);
                    if (scanf("%f%c",&mat[i][j],&c)==2&&c=='\n') break;
                    printf("Erreur !\n"); while(getchar()!='\n');
                }
            }
        pos=0; neg=0; nuls=0;
        for (i=0;i<lignes;i++)
            for (j=0;j<colonnes;j++) {
                if      (fabsf(mat[i][j]) < EPSILON) nuls++;
                else if (mat[i][j] > 0)              pos++;
                else                                  neg++;
            }
        printf("\n-------------------------------------------\n");
        printf("  Matrice %dx%d (%d elements) :\n\n",lignes,colonnes,total);
        for (i=0;i<lignes;i++) {
            printf("  ");
            for (j=0;j<colonnes;j++) printf("%7.2f ", mat[i][j]);
            printf("\n");
        }
        printf("\n  Positifs : %d  (%.1f%%)\n", pos,  100.0f*pos/total);
        printf("  Negatifs : %d  (%.1f%%)\n", neg,  100.0f*neg/total);
        printf("  Nuls     : %d  (%.1f%%)\n", nuls, 100.0f*nuls/total);
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

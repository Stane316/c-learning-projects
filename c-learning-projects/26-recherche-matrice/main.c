/*
 * =============================================================================
 * Projet     : Recherche d'une valeur dans une matrice
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
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
    float mat[MAX_LIGNES][MAX_COLONNES], val;
    int lignes, colonnes, i, j, trouve, occurrences; char c, continuer;
    do {
        printf("\n===========================================\n");
        printf("   RECHERCHE DANS UNE MATRICE\n");
        printf("===========================================\n\n");
        lignes   = lire_dim("Lignes",   MAX_LIGNES);
        colonnes = lire_dim("Colonnes", MAX_COLONNES);
        printf("\n");
        for (i=0;i<lignes;i++)
            for (j=0;j<colonnes;j++) {
                while(1){
                    printf("  mat[%d][%d] : ",i,j);
                    if (scanf("%f%c",&mat[i][j],&c)==2&&c=='\n') break;
                    printf("Erreur !\n"); while(getchar()!='\n');
                }
            }
        printf("  Valeur a rechercher : ");
        while (scanf("%f%c",&val,&c)!=2||c!='\n') { printf("Erreur !\n"); while(getchar()!='\n'); printf("  Valeur : "); }

        occurrences=0; trouve=0;
        printf("\n-------------------------------------------\n");
        printf("  Matrice (occurrences entre [*]) :\n\n");
        for (i=0;i<lignes;i++) {
            printf("  ");
            for (j=0;j<colonnes;j++) {
                if (fabsf(mat[i][j]-val)<EPSILON) { printf("[%6.2f] ",mat[i][j]); occurrences++; trouve=1; }
                else printf("%7.2f  ", mat[i][j]);
            }
            printf("\n");
        }
        printf("\n  Valeur %.2f : ", val);
        if (trouve) printf("trouvee %d fois.\n", occurrences);
        else        printf("ABSENTE.\n");
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

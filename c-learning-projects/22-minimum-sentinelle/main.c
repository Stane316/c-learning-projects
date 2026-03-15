/*
 * =============================================================================
 * Projet     : Minimum avec sentinelle (saisie terminee par 0)
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Lit des reels jusqu'a la sentinelle 0, puis affiche le min.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EPSILON 1e-6f

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
    float nombre, min; int premier, count; char c, continuer;
    do {
        printf("\n===========================================\n");
        printf("   MINIMUM AVEC SENTINELLE (0 pour finir)\n");
        printf("===========================================\n\n");
        printf("  Saisissez des reels non nuls. Entrez 0 pour terminer.\n\n");
        premier=1; count=0;
        while (1) {
            printf("  Nombre %d (0 = fin) : ", count+1);
            if (scanf("%f%c",&nombre,&c)==2&&c=='\n') {
                if (fabsf(nombre)<EPSILON) break;
                if (premier) { min=nombre; premier=0; }
                else if (nombre<min) min=nombre;
                count++;
            } else { printf("Erreur ! Reel requis.\n"); while(getchar()!='\n'); }
        }
        printf("\n-------------------------------------------\n");
        if (count==0) printf("  Aucune valeur saisie.\n");
        else printf("  %d valeur(s) — Minimum : %.2f\n", count, min);
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

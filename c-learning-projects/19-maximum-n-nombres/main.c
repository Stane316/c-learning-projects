/*
 * =============================================================================
 * Projet     : Maximum de N nombres
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Lit N nombres saisis par l'utilisateur et trouve le maximum.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMBRES 100

int lire_entier_borne(int min, int max, const char *label) {
    int n; char c;
    while (1) {
        printf("  %s (%d-%d) : ", label, min, max);
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=min&&n<=max) return n;
        printf("Erreur ! Valeur entre %d et %d.\n",min,max);
        while(getchar()!='\n');
    }
}

float lire_reel(int rang) {
    float n; char c;
    while (1) {
        printf("  Nombre %d : ", rang);
        if (scanf("%f%c",&n,&c)==2&&c=='\n') return n;
        printf("Erreur ! Reel valide requis.\n");
        while(getchar()!='\n');
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
    int n, i, position_max; float val, max; char continuer;
    do {
        printf("\n===========================================\n");
        printf("       MAXIMUM DE N NOMBRES\n");
        printf("===========================================\n\n");
        n=lire_entier_borne(2,MAX_NOMBRES,"Combien de nombres");
        printf("\n");
        max=lire_reel(1); position_max=1;
        for (i=2; i<=n; i++) {
            val=lire_reel(i);
            if (val>max) { max=val; position_max=i; }
        }
        printf("\n-------------------------------------------\n");
        printf("  Nombre de valeurs : %d\n",n);
        printf("  Maximum           : %.2f  (position %d)\n",max,position_max);
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

/*
 * =============================================================================
 * Projet     : Detection d'un nombre premier
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Determine si un entier est premier. Algorithme optimise
 *              O(sqrt(n)) avec saut des pairs.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int est_premier(int n) {
    int i;
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (i=3; i*i<=n; i+=2)
        if (n%i==0) return 0;
    return 1;
}

int lire_entier_positif() {
    int n; char c;
    while (1) {
        printf("  Entier (>= 0) : ");
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=0) return n;
        printf("Erreur ! Entier >= 0 requis.\n");
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
    int n; char continuer;
    do {
        printf("\n===========================================\n");
        printf("       DETECTION D'UN NOMBRE PREMIER\n");
        printf("===========================================\n\n");
        n=lire_entier_positif();
        printf("\n-------------------------------------------\n");
        if (est_premier(n))
            printf("  %d est PREMIER.\n",n);
        else {
            printf("  %d n'est PAS premier.\n",n);
            if (n<2) printf("  (Les nombres < 2 ne sont pas premiers.)\n");
            else     printf("  (Divisible par un entier autre que 1 et %d.)\n",n);
        }
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

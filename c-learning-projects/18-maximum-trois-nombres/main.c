/*
 * =============================================================================
 * Projet     : Maximum de trois nombres
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Trouve le maximum parmi 3 reels via une fonction dediee.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

float maximum_trois(float a, float b, float c) {
    float max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

float lire_reel(const char *label) {
    float n; char c;
    while (1) {
        printf("  %s : ", label);
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
    float n1,n2,n3,max; char continuer;
    do {
        printf("\n===========================================\n");
        printf("       MAXIMUM DE TROIS NOMBRES\n");
        printf("===========================================\n\n");
        n1=lire_reel("Nombre 1");
        n2=lire_reel("Nombre 2");
        n3=lire_reel("Nombre 3");
        max=maximum_trois(n1,n2,n3);
        printf("\n-------------------------------------------\n");
        printf("  Nombres : %.2f | %.2f | %.2f\n",n1,n2,n3);
        printf("  Maximum : %.2f", max);
        if (max==n1) printf("  (Nombre 1)\n");
        else if (max==n2) printf("  (Nombre 2)\n");
        else printf("  (Nombre 3)\n");
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

/*
 * =============================================================================
 * Projet     : Tri d'etudiants par moyenne
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Saisit N etudiants (nom, prenom, moyenne), les trie par
 *              moyenne decroissante (tri a bulles) et affiche le classement.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ETUDIANTS 20

typedef struct {
    char  nom[50];
    char  prenom[50];
    float moyenne;
} Etudiant;

void lire_chaine(const char *label, char *dest, int taille) {
    printf("  %s : ", label);
    if (fgets(dest, taille, stdin)) dest[strcspn(dest,"\n")]='\0';
}

float lire_note(const char *label) {
    float n; char c;
    while (1) {
        printf("  %s (0-20) : ", label);
        if (scanf("%f%c",&n,&c)==2 && c=='\n' && n>=0 && n<=20) return n;
        printf("Erreur ! Note entre 0 et 20.\n");
        while(getchar()!='\n');
    }
}

int lire_nb_etudiants() {
    int n; char c;
    while (1) {
        printf("  Nombre d'etudiants (1-%d) : ", MAX_ETUDIANTS);
        if (scanf("%d%c",&n,&c)==2 && c=='\n' && n>=1 && n<=MAX_ETUDIANTS) return n;
        printf("Erreur ! Valeur entre 1 et %d.\n", MAX_ETUDIANTS);
        while(getchar()!='\n');
    }
}

void tri_bulles_decroissant(Etudiant tab[], int n) {
    int i, j; Etudiant tmp;
    for (i=0; i<n-1; i++)
        for (j=0; j<n-1-i; j++)
            if (tab[j].moyenne < tab[j+1].moyenne) {
                tmp=tab[j]; tab[j]=tab[j+1]; tab[j+1]=tmp;
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
            printf("Erreur ! O ou N uniquement.\n");
        }
    }
}

int main() {
    Etudiant etudiants[MAX_ETUDIANTS];
    int n, i; char continuer;

    do {
        printf("\n===========================================\n");
        printf("     TRI D'ETUDIANTS PAR MOYENNE\n");
        printf("===========================================\n\n");

        n = lire_nb_etudiants();
        printf("\n");
        for (i=0; i<n; i++) {
            printf("  --- Etudiant %d ---\n", i+1);
            lire_chaine("Nom",    etudiants[i].nom,    50);
            lire_chaine("Prenom", etudiants[i].prenom, 50);
            etudiants[i].moyenne = lire_note("Moyenne");
            printf("\n");
        }

        tri_bulles_decroissant(etudiants, n);

        printf("-------------------------------------------\n");
        printf("  CLASSEMENT (ordre decroissant)\n");
        printf("-------------------------------------------\n");
        printf("  Rang  Nom              Prenom           Moy\n");
        printf("  ----  ---------------  ---------------  -----\n");
        for (i=0; i<n; i++)
            printf("  %3d.  %-15s  %-15s  %.2f\n",
                   i+1, etudiants[i].nom, etudiants[i].prenom, etudiants[i].moyenne);
        printf("-------------------------------------------\n");

        continuer = demander_continuation();
    } while (continuer == 'O');

    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

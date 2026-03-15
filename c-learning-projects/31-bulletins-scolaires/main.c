/*
 * =============================================================================
 * Projet     : Bulletins scolaires
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Gere les bulletins de N eleves avec M matieres.
 *              Calcule moyenne, rang, mention.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEVES   20
#define MAX_MATIERES 10

typedef struct {
    char  nom[50];
    float notes[MAX_MATIERES];
    float moyenne;
    int   rang;
} Eleve;

int lire_entier_borne(const char *label, int min, int max) {
    int n; char c;
    while(1) {
        printf("  %s (%d-%d) : ", label, min, max);
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=min&&n<=max) return n;
        printf("Erreur ! Valeur entre %d et %d.\n",min,max); while(getchar()!='\n');
    }
}

float lire_note(const char *label) {
    float n; char c;
    while(1) {
        printf("  %s (0-20) : ", label);
        if (scanf("%f%c",&n,&c)==2&&c=='\n'&&n>=0&&n<=20) return n;
        printf("Erreur ! Note entre 0 et 20.\n"); while(getchar()!='\n');
    }
}

const char* mention(float moy) {
    if (moy>=16)  return "Tres Bien";
    if (moy>=14)  return "Bien";
    if (moy>=12)  return "Assez Bien";
    if (moy>=10)  return "Passable";
    return "Insuffisant";
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
    Eleve eleves[MAX_ELEVES];
    char matieres[MAX_MATIERES][30];
    int nb_eleves, nb_matieres, i, j, k; char continuer;

    do {
        printf("\n===========================================\n");
        printf("         BULLETINS SCOLAIRES\n");
        printf("===========================================\n\n");

        nb_matieres = lire_entier_borne("Nombre de matieres", 1, MAX_MATIERES);
        printf("\n");
        for (j=0;j<nb_matieres;j++) {
            printf("  Nom matiere %d : ", j+1);
            if (fgets(matieres[j],30,stdin)) matieres[j][strcspn(matieres[j],"\n")]='\0';
        }

        nb_eleves = lire_entier_borne("Nombre d'eleves", 1, MAX_ELEVES);
        printf("\n");
        for (i=0;i<nb_eleves;i++) {
            printf("  --- Eleve %d ---\n", i+1);
            printf("  Nom : ");
            if (fgets(eleves[i].nom,50,stdin)) eleves[i].nom[strcspn(eleves[i].nom,"\n")]='\0';
            float somme=0;
            for (j=0;j<nb_matieres;j++) {
                char label[60];
                snprintf(label,60,"Note %s",matieres[j]);
                eleves[i].notes[j]=lire_note(label);
                somme+=eleves[i].notes[j];
            }
            eleves[i].moyenne = somme / nb_matieres;
            printf("\n");
        }

        /* Calcul des rangs */
        for (i=0;i<nb_eleves;i++) {
            eleves[i].rang=1;
            for (k=0;k<nb_eleves;k++)
                if (eleves[k].moyenne > eleves[i].moyenne) eleves[i].rang++;
        }

        printf("===================================================\n");
        printf("  BULLETINS SCOLAIRES\n");
        printf("===================================================\n");
        for (i=0;i<nb_eleves;i++) {
            printf("\n  Eleve : %s\n", eleves[i].nom);
            for (j=0;j<nb_matieres;j++)
                printf("    %-15s : %.2f\n", matieres[j], eleves[i].notes[j]);
            printf("    ---\n");
            printf("    Moyenne : %.2f  |  Rang : %d  |  %s\n",
                   eleves[i].moyenne, eleves[i].rang, mention(eleves[i].moyenne));
        }
        printf("===================================================\n");

        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

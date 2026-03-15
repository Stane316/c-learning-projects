/*
 * =============================================================================
 * Projet     : Gestion de comptes bancaires
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Cree des comptes bancaires, effectue depot/retrait,
 *              affiche le solde et liste tous les comptes.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPTES 10

typedef struct {
    int   numero;
    char  nom[50];
    char  prenom[50];
    float solde;
} Compte;

Compte comptes[MAX_COMPTES];
int nb_comptes = 0;

void lire_nom(char *dest, int taille, const char *label) {
    printf("  %s : ", label);
    if (fgets(dest, taille, stdin)) dest[strcspn(dest,"\n")]='\0';
}

float lire_montant(const char *label) {
    float m; char c;
    while(1) {
        printf("  %s : ", label);
        if (scanf("%f%c",&m,&c)==2&&c=='\n'&&m>0) return m;
        printf("Erreur ! Montant > 0 requis.\n"); while(getchar()!='\n');
    }
}

int lire_numero(const char *label) {
    int n; char c;
    while(1) {
        printf("  %s : ", label);
        if (scanf("%d%c",&n,&c)==2&&c=='\n') return n;
        printf("Erreur !\n"); while(getchar()!='\n');
    }
}

int trouver_compte(int numero) {
    int i;
    for(i=0;i<nb_comptes;i++) if(comptes[i].numero==numero) return i;
    return -1;
}

void creer_compte() {
    if (nb_comptes>=MAX_COMPTES) { printf("  Limite de %d comptes atteinte.\n",MAX_COMPTES); return; }
    Compte *c = &comptes[nb_comptes];
    c->numero = nb_comptes+1;
    lire_nom(c->nom,    50, "Nom");
    lire_nom(c->prenom, 50, "Prenom");
    c->solde = lire_montant("Solde initial");
    nb_comptes++;
    printf("  Compte N°%d cree pour %s %s.\n", c->numero, c->prenom, c->nom);
}

void deposer() {
    int num = lire_numero("Numero de compte"); int idx=trouver_compte(num);
    if (idx<0) { printf("  Compte N°%d introuvable.\n",num); return; }
    float m=lire_montant("Montant a deposer");
    comptes[idx].solde+=m;
    printf("  Depot %.2f — Nouveau solde : %.2f\n",m,comptes[idx].solde);
}

void retirer() {
    int num=lire_numero("Numero de compte"); int idx=trouver_compte(num);
    if (idx<0) { printf("  Compte N°%d introuvable.\n",num); return; }
    float m=lire_montant("Montant a retirer");
    if (m>comptes[idx].solde) { printf("  Solde insuffisant (%.2f).\n",comptes[idx].solde); return; }
    comptes[idx].solde-=m;
    printf("  Retrait %.2f — Nouveau solde : %.2f\n",m,comptes[idx].solde);
}

void lister() {
    int i;
    if (nb_comptes==0) { printf("  Aucun compte.\n"); return; }
    printf("  N°  Nom              Prenom           Solde\n");
    printf("  --  ---------------  ---------------  --------\n");
    for(i=0;i<nb_comptes;i++)
        printf("  %2d  %-15s  %-15s  %8.2f\n",
               comptes[i].numero,comptes[i].nom,comptes[i].prenom,comptes[i].solde);
}

int lire_choix() {
    int n; char c;
    while(1) {
        printf("  Choix (1-5) : ");
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=1&&n<=5) return n;
        printf("Erreur ! 1 a 5.\n"); while(getchar()!='\n');
    }
}

char demander_continuation() {
    char buf[100]; char r;
    while (1) {
        printf("\n=============================================================\n");
        printf("Voulez-vous revenir au menu ? (O/N) : ");
        if (fgets(buf,sizeof(buf),stdin)) {
            buf[strcspn(buf,"\n")]='\0';
            if (strlen(buf)==1){r=toupper(buf[0]);if(r=='O'||r=='N')return r;}
            printf("Erreur ! O ou N.\n");
        }
    }
}

int main() {
    int choix; char continuer;
    do {
        printf("\n===========================================\n");
        printf("      GESTION DE COMPTES BANCAIRES\n");
        printf("===========================================\n\n");
        printf("  1. Creer un compte\n");
        printf("  2. Deposer de l'argent\n");
        printf("  3. Retirer de l'argent\n");
        printf("  4. Lister tous les comptes\n");
        printf("  5. Quitter\n\n");
        choix=lire_choix();
        printf("\n-------------------------------------------\n");
        switch(choix) {
            case 1: creer_compte(); break;
            case 2: deposer();      break;
            case 3: retirer();      break;
            case 4: lister();       break;
            case 5: printf("  Au revoir !\n"); return 0;
        }
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

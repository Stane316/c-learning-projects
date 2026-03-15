/*
 * =============================================================================
 * Projet     : Commande de produits
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Choisit un type de produit et commande une quantite.
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum { PRODUIT_A=1, PRODUIT_B, PRODUIT_C } TypeProduit;

const char* nom_du_type(TypeProduit t) {
    switch(t) {
        case PRODUIT_A: return "Produit A (10.00)";
        case PRODUIT_B: return "Produit B (25.50)";
        case PRODUIT_C: return "Produit C (5.99)";
        default:        return "Inconnu";
    }
}

float prix_du_type(TypeProduit t) {
    switch(t) { case PRODUIT_A: return 10.00f; case PRODUIT_B: return 25.50f; case PRODUIT_C: return 5.99f; default: return 0; }
}

int lire_type() {
    int n; char c;
    while(1) {
        printf("  Type (1=A, 2=B, 3=C) : ");
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=1&&n<=3) return n;
        printf("Erreur ! 1, 2 ou 3.\n"); while(getchar()!='\n');
    }
}

int lire_quantite(int stock) {
    int n; char c;
    while(1) {
        printf("  Quantite (1-%d) : ", stock);
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=1&&n<=stock) return n;
        printf("Erreur ! Quantite entre 1 et %d.\n", stock); while(getchar()!='\n');
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
    int type, quantite; float total; char continuer;
    int stock = 50;
    do {
        printf("\n===========================================\n");
        printf("         COMMANDE DE PRODUITS\n");
        printf("===========================================\n\n");
        printf("  1. Produit A — 10.00\n");
        printf("  2. Produit B — 25.50\n");
        printf("  3. Produit C —  5.99\n\n");
        printf("  Stock disponible : %d unites\n\n", stock);

        type     = lire_type();
        quantite = lire_quantite(stock);
        total    = prix_du_type((TypeProduit)type) * quantite;

        printf("\n-------------------------------------------\n");
        printf("  Produit    : %s\n", nom_du_type((TypeProduit)type));
        printf("  Quantite   : %d\n", quantite);
        printf("  Total      : %.2f\n", total);
        printf("  Stock rest.: %d\n", stock - quantite);
        printf("-------------------------------------------\n");

        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

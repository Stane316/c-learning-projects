/*
 * =============================================================================
 * Projet     : Operations sur les nombres rationnels
 * Fichier    : main.c
 * Auteur     : ANIAMBOSSOU Stane
 * Description: Addition, soustraction, multiplication, division de fractions.
 *              Simplification par le PGCD (algorithme d'Euclide).
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct { int num; int den; } Fraction;

int pgcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) { int t=b; b=a%b; a=t; }
    return a;
}

Fraction simplifier(Fraction f) {
    int g;
    if (f.den < 0) { f.num = -f.num; f.den = -f.den; }
    if (f.num == 0) { f.den = 1; return f; }
    g = pgcd(abs(f.num), f.den);
    f.num /= g; f.den /= g;
    return f;
}

Fraction add(Fraction a, Fraction b) { Fraction r; r.num=a.num*b.den+b.num*a.den; r.den=a.den*b.den; return simplifier(r); }
Fraction sub(Fraction a, Fraction b) { Fraction r; r.num=a.num*b.den-b.num*a.den; r.den=a.den*b.den; return simplifier(r); }
Fraction mul(Fraction a, Fraction b) { Fraction r; r.num=a.num*b.num; r.den=a.den*b.den; return simplifier(r); }
Fraction dvd(Fraction a, Fraction b) { Fraction r; r.num=a.num*b.den; r.den=a.den*b.num; return simplifier(r); }

void afficher(Fraction f) {
    if (f.den==1) printf("%d", f.num);
    else          printf("%d/%d", f.num, f.den);
}

Fraction lire_fraction(const char *label) {
    Fraction f; char c;
    while (1) {
        printf("  %s (num/den) : ", label);
        if (scanf("%d/%d%c",&f.num,&f.den,&c)==3&&c=='\n') {
            if (f.den!=0) return simplifier(f);
            printf("Erreur ! Denominateur nul interdit.\n");
        } else { printf("Erreur ! Format num/den requis (ex: 3/4).\n"); while(getchar()!='\n'); }
    }
}

int lire_choix() {
    int n; char c;
    while(1) {
        printf("  Choix (1-4) : ");
        if (scanf("%d%c",&n,&c)==2&&c=='\n'&&n>=1&&n<=4) return n;
        printf("Erreur ! 1 a 4.\n"); while(getchar()!='\n');
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
    Fraction a, b, res; int choix; char continuer;
    do {
        printf("\n===========================================\n");
        printf("   OPERATIONS SUR LES RATIONNELS\n");
        printf("===========================================\n\n");
        printf("  1. Addition\n  2. Soustraction\n  3. Multiplication\n  4. Division\n\n");
        choix = lire_choix();
        a = lire_fraction("Fraction A");
        b = lire_fraction("Fraction B");
        printf("\n-------------------------------------------\n");
        printf("  A = "); afficher(a);
        printf("   B = "); afficher(b); printf("\n\n");
        switch(choix) {
            case 1: res=add(a,b); printf("  A + B = "); break;
            case 2: res=sub(a,b); printf("  A - B = "); break;
            case 3: res=mul(a,b); printf("  A x B = "); break;
            case 4:
                if (b.num==0) { printf("  Division par zero impossible.\n"); goto fin; }
                res=dvd(a,b); printf("  A / B = "); break;
        }
        afficher(res); printf("\n");
        fin:
        printf("-------------------------------------------\n");
        continuer=demander_continuation();
    } while (continuer=='O');
    printf("\nMerci. Au revoir !\n\n");
    return 0;
}

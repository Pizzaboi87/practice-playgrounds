/***********************************************************************
* A PROGRAMBAN NEM SZEREPELHETNEK AZ ALÁBBI SOROK:
* #include <string.h>
* #include <math.h>
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
************************************************************************
**  ETTŐL A PONTTÓL DOLGOZHATSZ A FELADATOKON
************************************************************************
***********************************************************************/

/*
1. feladat (3 pont)

Irj egy programot, amely a magassagbol es a sugarbol kiszamolja
egy henger felszinet es terfogatat!

A program beolvas ketto nemnegativ valos szamot a standard inputrol.
Az elso szam a henger korlapjanak sugara, a masodik szam pedig a henger magassaga.
A program csak jo inputot kaphat, igy hibakezelessel nem kell foglalkozni.
A program kimenete/outputja ket sor.
Az elso sorban a "V = " szoveg utan a henger terfogata,
a masodik sorban az "A = " szoveg utan a henger felulete
keruljon kiirasra (egy-egy szokoz van az egyenlosegjelek elott es utan!).
Mindket szamot 11 karakteren jobbra igazitva 4 tizedesjegy pontossaggal
kell kiiratni.

Ugyelj ra, hogy a kiirast sorvege jel zarja!
A program az elvart ket soron kivul semmi mast ne irjon ki a kepernyore!

A programot "main" helyett "main_t" neven keszitsd el,
de a tartalma olyan legyen, mintha egy programot irnal!

Matematikai segitseg: Ha "r" a sugar es "h" a magassag,
akkor egy henger felszine "2*PI*r^2 + 2*PI*r*h".
A henger terfogata pedig "PI*r^2*h".
A szamolas soran PI=3.140625 legyen.
*/

int main_t() {
    double r, h, A, V;
    const double PI = 3.140625;

    scanf("%lf%lf", &r, &h);

    A = (2 * PI * r * r) + (2 * PI * r * h);
    V = PI * r * r * h;

    printf("V = %11.4lf\n", V);
    printf("A = %11.4lf\n", A);

    return 0;
}
/***********************************************************************
************************************************************************
**
**  EZEN A PONTON TÚL NE VÁLTOZTASS SEMMIT SEM A FÁJLON!
**
************************************************************************
***********************************************************************/

void call_1()
{
  int check;
  if((check = fgetc(stdin)) == EOF) {
    fprintf(stderr, "HIBA: Nem olvasható adat!\n");
    return;
  }
  if(main_t() && (check == 'R')) {
    fputs("RETURNS NONZERO", stdout);
  }
}
void test_1()
{
    main_t();
}

typedef void (*call_function)();

call_function call_table[] = {
	call_1,
	NULL
};


call_function test_table[] = {
	test_1,
	NULL
};

static int __arg_check_helper(const char * exp, const char * arg) {
    while (*exp && *arg && *exp == *arg) {
        ++exp;
        ++arg;
    }
    return *exp == *arg;
}

int main(int argc, char *argv[])
{
    int feladat, calltabsize;
    if ((argc > 1) && !(__arg_check_helper("-t", argv[1]) && __arg_check_helper("--test", argv[1]))) {
        if (argc > 2) {
            feladat = atoi(argv[2]);
            for (calltabsize=0; test_table[calltabsize]; calltabsize++);
            if (feladat <= 0 || calltabsize < feladat) {
                fprintf(stderr, "HIBA: rossz feladat sorszám: %d!\n", feladat);
                return 1;
            }
            (*test_table[feladat-1])();
        } else {
            for (feladat=0; test_table[feladat]; ++feladat) {
                (*test_table[feladat])();
            }
        }
        return 0;
    }
    if (!freopen("be.txt", "r", stdin)) {
        fprintf(stderr, "HIBA: Hiányzik a `be.txt'!\n");
        return 1;
    }
    if (!freopen("ki.txt", "w", stdout)) {
        fprintf(stderr, "HIBA: A `ki.txt' nem írható!\n");
        return 1;
    }
    for (calltabsize=0; call_table[calltabsize]; calltabsize++);
    if (fscanf(stdin, "%d%*[^\n]", &feladat)!=1) {
        fprintf(stderr, "HIBA: Nem olvasható a feladat sorszám!\n");
        return 1;
    }
    fgetc(stdin);
    if (0<feladat && feladat<=calltabsize) {
        (*call_table[feladat-1])();
    } else {
        fprintf(stderr, "HIBA: Rossz feladat sorszám: %d!\n", feladat);
        return 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

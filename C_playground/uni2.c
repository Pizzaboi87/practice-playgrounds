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
1. feladat (5 pont)

A feladat meghatarozni ket egesz szam kozotti zart intervallumba eso nem primszamok osszeget.
A fuggveny ket parametere sorban az intervallum also (a) es felso (b) vegpontja.
Visszateresi erteke az intervallumba eso nem primszamok osszege.
(Mivel az intervallum zart, ezert a vegpontok meg az intervallum reszei.)

A feladat a math.h hasznalata nelkul megoldhato ket ciklussal.
A kulso ciklus a-tol indul, es b-ig tart.
A kulso ciklus magjaban ellenorizzuk a ciklusvaltozorol, hogy prim-e.
Ez az ellenorzes egy belso ciklusban zajlik, ahol a belso ciklusvaltozo 2-tol indul, es addig tart amig kisebb a kulso ciklusvaltozonal.
A belso ciklus magjaban ellenorizzuk, hogy a belso ciklusvaltozo osztja-e a kulso ciklusvaltozot.
Ha igen, akkor a kulso ciklusvaltozo nem prim, ezt eltaroljuk.
(Peldaul egy nullara inicializalt segedvaltozoban, amit ekkor egyre allitunk.)

Ha a kulso ciklusvaltozo nem prim, akkor hozzaadjuk egy osszeget tartalmazo valtozohoz.
A fuggveny ezzel az eredetileg 0-ra inicializalt osszeg valtozoval ter vissza.
(Nulla darab ertek osszege 0, tovabba ne feledjuk a megfelelo ponton a segedvaltozot visszaallitani nullara.)

A feladat megoldhato ugy is, hogy a primtesztelest kiszervezzuk fuggvenybe.

Fontos: az 1-et jelen feladatban tekintsuk prim szamnak.

Kodold le C nyelven a fuggvenyt!
A fuggveny fejlecen ne valtoztass!
A fuggveny inputjai a parameterek, outputja a visszateresi ertek.
A fuggveny nem vegez IO muveleteket!
*/

int nemprimosszeg(int a, int b) {
    int i;
    int y;
    int sum = 0;
    
    for(y = a; y <= b; y++){
        for(i = 2; i < y; i++ ) {
            if(y % i == 0) {
                sum += y;
                break;
            }
        }
    }
    
    return sum;
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
	int a, b, eredmeny;
	if (fscanf(stdin, "%d %d", &a, &b) != 2) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	eredmeny = nemprimosszeg(a, b);
	fprintf(stdout, "%d\n", eredmeny);
}
void test_1()
{
	int eredmeny, i;
	struct {int a; int b; int eredmeny;} testlist[2] = {{1, 13, 49}, {4, 15, 78}};
	for (i = 0; i < 2; ++i) {
		eredmeny = nemprimosszeg(testlist[i].a, testlist[i].b);
		if (eredmeny != testlist[i].eredmeny) {
			fprintf(stderr, "HIBA: primosszeg(%d, %d)\n"
							"\telvárt eredmény: %d\n"
							"\tkapott eredmény: %d\n",
				testlist[i].a, testlist[i].b, testlist[i].eredmeny, eredmeny);
		}
	}
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

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
1. feladat (1 pont)

Keszits egy programot, amely kiirja az ``Xray'' szoveget a kepernyore
ugy, hogy az ezt koveto kiiratas a sor elejen kezdodjon majd!

A programot main helyett main_p neven keszitsd el, de a tartalma olyan
legyen, mintha egy programot irnal!
*/

int main_p() {
    printf("Xray\n");
}

/*
2. feladat (2 pont)
* 
Keszits egy programot, amely a standard inputrol beolvas harom egesz
szamot (a, b es c), majd az a*b*c kifejezes erteket kiirja a kepernyore!
A kiiratast sorvege jel zarja! A program mast ne irjon ki!

A programot main helyett main_e neven keszitsd el,
de a tartalma olyan legyen, mintha egy programot irnal!
*/

int main_e() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", a*b*c);
}

/*
3. feladat (3 pont)

Keszits egy programot, amely a standard inputrol beolvas ket valos
szamot, majd a ket szam osszeget kiirja a kepernyore!
A kiiratast sorvege jel zarja! A program mast ne irjon ki!

A programot main helyett main_v neven keszitsd el,
de a tartalma olyan legyen, mintha egy programot irnal!
*/

int main_v() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%lf\n", a+b);
}

/*
4. feladat (3 pont)

A feladat egy maximum fuggveny megirasa. A fuggveny a harom parametere
kozul a legnagyobb sorszamaval ter vissza (a:1, b:2, c:3).
A harom kapott szam paronkent kulonbozo lesz.

Kodold le C nyelven a fuggvenyt! A fuggveny fejlecen ne valtoztass!
A fuggveny inputjai a parameterek, outputja a visszateresi ertek.
A fuggveny nem vegez IO muveleteket!

The task is to write a maximum function. The function returns
the index of the number that is the largest of its three parameters (a:1, b:2, c:3).
The three numbers obtained will be different from each other.

Write the function in C. Do not change the header of the function.
The inputs of the function are the parameters, the output is the return value.
The function does not perform IO operations.

*/

int maximum(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return 1;
        } else {
            return 3;
        }
    } else {
        if (b > c) {
            return 2;
        } else {
            return 3;
        }
    }
}

/*
5. feladat (6 pont)

A feladat meghatarozni ket egesz szam kozotti zart intervallumba eso
negyzetszamok darabszamat. A fuggveny ket parametere sorban az
intervallum also (a) es felso (b) vegpontja.
Visszateresi erteke az intervallumba eso negyzetszamok darabszama. A
vegpontok meg az intervallum reszei.

A feladat a math.h hasznalata nelkul megoldhato egy ciklussal,
amely 0-tol indul, es addig tart amig a ciklusvaltozo negyzete nagyobb
nem lesz b-nel. A ciklusmagban ellenorizzuk, hogy a ciklusvaltozo
negyzete nagyobb-egyenlo-e mint a, es ha igen, akkor noveljuk a
negyzetszamok darabszamat tarolo valtozo erteket eggyel.
A fuggveny ezzel az eredetileg 0-ra inicializalt valtozoval ter vissza.

Kodold le C nyelven a fuggvenyt! A fuggveny fejlecen ne valtoztass!
A fuggveny inputjai a parameterek, outputja a visszateresi ertek.
A fuggveny nem vegez IO muveleteket!
*/

int negyzetszam(int a, int b) {
    int i, db = 0;
    for (i = 0; i*i <= b; ++i) {
        if (i*i >= a) {
            ++db;
        }
    }
    return db;
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
	main_p();
}
void test_1()
{
	main_p();
}

void call_2()
{
	main_e();
}
void test_2()
{
	main_e();
}

void call_3()
{
	int check;
	if((check = fgetc(stdin)) == EOF) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	if(main_v() && (check == 'R')) {
		fputs("RETURNS NONZERO", stdout);
	}
}
void test_3()
{
	main_v();
}


void call_4()
{
    int a, b, c, eredmeny;
    if(fscanf(stdin, "%d %d %d", &a, &b, &c)!=3) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }
    eredmeny=maximum(a, b, c);
    fprintf(stdout, "%d\n", eredmeny);
}
void test_4()
{
    int eredmeny, i;
    struct {int a; int b; int c; int eredmeny;} testlist[2] = {{1, 2, 3, 3}, {-1, -2, -3, 1}};
    for (i = 0; i < 2; ++i) {
        eredmeny = maximum(testlist[i].a, testlist[i].b, testlist[i].c);
        if (eredmeny != testlist[i].eredmeny) {
            fprintf(stderr, "HIBA: maximum(%d, %d, %d)\n"
                            "\telvárt eredmény: %d\n"
                            "\tkapott eredmény: %d\n",
                testlist[i].a, testlist[i].b, testlist[i].c, testlist[i].eredmeny, eredmeny);
        }
    }
}

void call_5()
{
	int a, b, eredmeny;
	if(fscanf(stdin, "%d %d", &a, &b)!=2) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	eredmeny=negyzetszam(a, b);
	fprintf(stdout, "%d\n", eredmeny);
}
void test_5()
{
	int eredmeny, i;
	struct {int a; int b; int eredmeny;} testlist[2] = {{100, 400, 11}, {5, 20, 2}};
	for (i = 0; i < 2; ++i) {
		eredmeny = negyzetszam(testlist[i].a, testlist[i].b);
		if (eredmeny != testlist[i].eredmeny) {
			fprintf(stderr, "HIBA: negyzetszam(%d, %d)\n"
							"\telvárt eredmény: %d\n"
							"\tkapott eredmény: %d\n",
				testlist[i].a, testlist[i].b, testlist[i].eredmeny, eredmeny);
		}
	}
}

typedef void (*call_function)();

call_function call_table[] = {
	call_1,
	call_2,
	call_3,
	call_4,
	call_5,
	NULL
};


call_function test_table[] = {
	test_1,
	test_2,
	test_3,
	test_4,
	test_5,
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

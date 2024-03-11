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

Nancy es Jane a kovetkezo titkosirassal leveleztek A. A. Milne "Micsoda negy
nap!" cimu regenyeben: Megszamoltak, hany betubol allanak a titkositando
uzenet szavai, majd minden szo betuit veletlenszeruen osszezagyvaltak,
leirtak folyo irassal, és ebbe a szovegbe szintén sorrendet tartva, de
véletlenlenszeru helyekre beszurtak a szavak hosszat jelzo szamokat.

Peldaul: "Haho, ez egy uzenet!" => "haohzeg4ye2t3nez6eu"

Valositsuk meg ennek a titkosirasnak az egyszerusitett verziojat!

A titkosito fuggveny parametere ket karaktertomb, egy bemenet es egy
kimenet. A titkositando uzenet a bemenetben van, a titkositottat a kimenetbe
kell elkesziteni. A fuggveny szamolja meg, hogy a bemenet szavai hany
betusek, es ezeket a szamokat írja sorrendet tartva a kimenet elejere. Az
egyszeruseg kedveert minden bemenet maximum 9 betus szavakat tartalmaz. Egy
szonak szamitunk minden karaktert ket space kozott. (Tehat pl. az irasjelek
a szohoz tartoznak. A maganyos karakterek, mint pl. a gondolatjel, egybetus
szonak szamitanak.) Ez utan a fuggveny a bemenet minden szavat forditsa meg,
es space nelkul, sorrendet tartva irja be a kimenetbe.

Peldaul: "Haho, ez egy uzenet!" => "5237,ohaHzeyge!tenezu"
*/

int szokozSzamlalo(char string[]) {
    int szokozSzam = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            szokozSzam++;
        }
    }
    return szokozSzam;
}

int mondatHosszSzamlalo(char string[]){
    int mondatHossz = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') {
            mondatHossz++;
        }
    }
    return mondatHossz;
}

void fordit(char szo[], int hossz) {
    int bal = 0;
    int jobb = hossz - 1;
    while (bal < jobb) {
        char tmp = szo[bal];
        szo[bal] = szo[jobb];
        szo[jobb] = tmp;
        bal++;
        jobb--;
    }
}

void titkosit(char bemenet[], char kimenet[]){
    int szohossztombhossz = szokozSzamlalo(bemenet);
    int szohossztomb[szohossztombhossz+1];
    char szo[szohossztombhossz+1][20];
    
    int j = 0;
    int k = 0;
    int szoHossz = 0;
    for (int i = 0; bemenet[i] != '\0'; i++) {
        if (bemenet[i] != ' ') {
            szoHossz++;
            szo[j][k] = bemenet[i];
            k++;
        } else {
            szo[j][k] = '\0';
            szohossztomb[j] = szoHossz;
            szoHossz = 0;
            j++;
            k = 0;
        }
    }
    szo[j][k] = '\0';
    szohossztomb[j] = szoHossz;

    int index = 0;
    for (int i = 0; i <= szohossztombhossz; i++) {
        int szoHossz = szohossztomb[i];
        kimenet[index] = szoHossz + '0';
        index++;
    }

    for (int i = 0; i <= szohossztombhossz; i++){
        fordit(szo[i], szohossztomb[i]);
        for (int j = 0; j < szohossztomb[i]; j++) {
            kimenet[index] = szo[i][j];
            index++;
        }
    }
    kimenet[index] = '\0';
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
    char *p, bemenet[256] = "", kimenet[256] = "";
    for (int i = 0; i < 32; bemenet[i] = kimenet[i] = '#', ++i);
    if (fgets(bemenet, 256, stdin) == NULL) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }
    for (p = bemenet; *p && *p != '\n'; ++p);
    *p = '\0';
    titkosit(bemenet, kimenet);
    fprintf(stdout,"%s\n", kimenet);
}
void test_1()
{
    struct {
        char *text;
        char *code;
    } testlist[] = {
        { "Haho, ez egy uzenet!", "5237,ohaHzeyge!tenezu" },
        { NULL, NULL }
    };
    for (int i = 0; testlist[i].text; ++i) {
        char r[256]={0};
        int j;
        for (j = 0; j < 255; r[j++] = '#');
        titkosit(testlist[i].text, r);
        for(j = 0; r[j] != '\0' && testlist[i].code[j] != '\0' && r[j] == testlist[i].code[j]; ++j);
        if (r[j] != testlist[i].code[j]) {
            fprintf(stderr, "HIBA: titkosit(\"%s\")\n"
                            "\tkapott eredmény: \"%s\"\n"
                            "\telvárt eredmény: \"%s\"\n",
                            testlist[i].text, r, testlist[i].code);
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

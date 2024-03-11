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
1. feladat (4 pont)

Az alabbi fuggveny elso parametere egy sztring. A feladat a harmadik
parameterben kapott erteku elemek torlese. A feladat megoldhato egy
ciklus es ket szamlalo hasznalataval. Az elso szamlalo azt mutatja,
hogy eppen hanyadik elemet dolgozzuk fel az eredeti sztringnek, a
masodik pedig azt, hogy az eredmeny-sztringben hova kerul ez az elem.
Nyilvanvalo, hogy ha az aktualisan feldolgozott elem megegyezik a
harmadik parameterben kapott ertekkel, akkor ezt az eredmeny-sztringbol
ki kell hagyni. Figyelj arra, hogy az eredmeny-sztring veget lezard a
sztring veget jelzo 0 kodu karakterrel!
Az eredmenyt a masodik parameterben kapott eredmeny nevu sztringben
kell elkesziteni.
Kodold le a fuggvenyt C nyelven. A fuggveny fejlecen ne valtoztass!
*/
void strertektorles(char str[], char eredmeny[], char torlendo) {
  int i, j;
  for(i=0, j=0; str[i] != 0; ++i) {
    if(str[i] != torlendo) {
      eredmeny[j++] = str[i];
    }
  }
  eredmeny[j] = 0;
}

/*
2. feladat (4 pont)

Irj egy intervallum nevu strukturat, ami az
a es b nevu int tipusu mezoiben
egy intervallum also illetve felso vegpontjat tarolja.
Irj egy compare nevu fuggvenyt, ami ket ilyen
intervallumot kap parameterul, es a rovidebbel ter vissza.
Amennyiben a ket intervallum egyforma hosszu, akkor a fuggveny
az elso parameterben kapott intervallumot adja vissza.
Az [a,b] intervallum hossza: b - a + 1.
Mindket parameter intervallumra igaz, hogy 0 <= a <= b.
*/
/****************************************************
 * A kovetkezo sor programba illesztese eseten      *
 * (// torlese a #define elol) a feladat nem okoz   *
 * forditasi hibat, de pontot sem fog erni.         *
 ****************************************************/
//#define KIHAGY_2
#if ! (defined(KIHAGY_2) || defined(KIHAGY_MIND))

/*Irj egy intervallum nevu strukturat, ami az
a es b nevu int tipusu mezoiben
egy intervallum also illetve felso vegpontjat tarolja.
Irj egy compare nevu fuggvenyt, ami ket ilyen
intervallumot kap parameterul, es a rovidebbel ter vissza.
Amennyiben a ket intervallum egyforma hosszu, akkor a fuggveny
az elso parameterben kapott intervallumot adja vissza.
Az [a,b] intervallum hossza: b - a + 1.
Mindket parameter intervallumra igaz, hogy 0 <= a <= b.
*/

typedef struct {
  int a;
  int b;
} intervallum;

intervallum compare(intervallum i1, intervallum i2) {
  int h1 = i1.b - i1.a + 1;
  int h2 = i2.b - i2.a + 1;
  if(h1 < h2) {
    return i1;
  } else {
    return i2;
  }
}

#endif

/*
3. feladat (6 pont)

Az alabbi fuggveny feladata helyet foglalni egy ketdimenzios char tombnek.
A tomb sor- es oszlopszama megegyezik.
A tomb N meretet a fuggveny parameterkent kapja.
A helyfoglalas ugy tortenjen, hogy eloszor helyet foglalunk az N sor
pointereinek, majd megfelelo modon minden sor N-N darab elemenek is.
A helyfoglalas utan toltsuk fel a tomb elemeit ertekekkel a kovetkezo modon:
A tomb szelen levo elemek, azaz a 0. es utolso sor, illetve 0. es utolso oszlop
elemei legyenek 'h', belso elemek pedig 'i' ertekuek.
A fuggveny terjen vissza a tombre mutato pointerrel. A memoria felszabaditasaval
nem kell foglalkoznod.
*/

char **foglal(int n) {
  int i, j;
  char **ptr = (char**)malloc(n * sizeof(char*));
  for(i=0; i<n; ++i) {
    ptr[i] = (char*)malloc(n * sizeof(char));
    for(j=0; j<n; ++j) {
      if(i == 0 || i == n-1 || j == 0 || j == n-1) {
        ptr[i][j] = 'h';
      } else {
        ptr[i][j] = 'i';
      }
    }
  }
  return ptr;
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
	char x=0, c=0, src[128]="#####", dst[128]="#####", *p;
	int  N=-1;
	int i;
	for(i=0;i<128;++i) dst[i]='#';
	if(fscanf(stdin, "%c", &x)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	if(x=='E' || x=='R') {
		if(fscanf(stdin, ":%d", &N)!=1) {
			fprintf(stderr, "HIBA: Nem olvasható adat!\n");
			return;
		}
	}
	if(!(fscanf(stdin, "%*[^\n]") || (fgetc(stdin) != EOF))) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	if(fscanf(stdin, "%c:", &c)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	if(fgets(src, 128, stdin)==NULL) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	for(p=src;*p&&*p!=10;p++);
	*p=0;
	strertektorles(src, dst, c);
	if(x=='R') {
		fprintf(stdout, "%d\n", dst[N]);
	} else if(x=='E') {
		int i;
		for(i=0; i<N; i++) {
			fprintf(stdout, "%c", dst[i]);
		}
		fputc('\n', stdout);
	} else {
		fprintf(stdout, "%s\n", dst);
	}
}

void test_1()
{
    int i, j;
    char str[] = "####################", eredmeny[] = "####################";
    struct {char str[20]; char torlendo; char eredmeny[20];} testlist[2] = {
        {"progalap",        'a', "proglp"      },
        {"(0(._(-_-)_.)0)", '_', "(0(.(--).)0)"},
    };
    for (i = 0; i < 2; ++i) {
        for(j = 0; testlist[i].str[j] != 0; str[j] = testlist[i].str[j], ++j);
        str[j] = 0;
        strertektorles(str, eredmeny, testlist[i].torlendo);
        for(j = 0; eredmeny[j] != 0 && testlist[i].eredmeny[j] != 0 && eredmeny[j] == testlist[i].eredmeny[j]; ++j);
        if (eredmeny[j] != testlist[i].eredmeny[j]) {
            fprintf(stderr, "HIBA: strertektorles(\"%s\", \"...\", '%c')\n", testlist[i].str, testlist[i].torlendo);
            fprintf(stderr, "\telvárt eredmény: \"%s\"\n", testlist[i].eredmeny);
            fprintf(stderr, "\tkapott eredmény: \"%s\"\n", eredmeny);
        }
    }
}

void call_2(){
#if ! (defined(KIHAGY_2) || defined(KIHAGY_MIND))
  int v;
  intervallum a, b, x;
  if(fscanf(stdin, "%d", &v)!=1) {
    fprintf(stderr, "HIBA: Nem olvasható adat!\n");
    return;
  }
  switch(v) {
  case 1:
    if(fscanf(stdin, "%d", &v)!=1) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    fprintf(stdout, "fordul%d\n", v);
    break;
  default:
    if(fscanf(stdin, "%d %d", &a.a, &a.b)!=2) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    if(a.a > a.b) {
      fprintf(stderr, "HIBA: Hibás input [%d,%d]!\n", a.a, a.b);
      return;
    }
    if(fscanf(stdin, "%d %d", &b.a, &b.b)!=2) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    if(b.a > b.b) {
      fprintf(stderr, "HIBA: Hibás input [%d,%d]!\n", b.a, b.b);
      return;
    }
    x = compare(a, b);
    fprintf(stdout, "[%d,%d]\n", x.a, x.b);
    break;
  }
#endif
}
void test_2(){
#if ! (defined(KIHAGY_2) || defined(KIHAGY_MIND))
  int i;
  intervallum eredmeny;
  struct {intervallum a, b, eredmeny;} testlist[2] = {
    {{.a=3, .b=10}, {.a=0, .b=7 }, {.a=3, .b=10}},
    {{.a=2, .b=5 }, {.a=3, .b=14}, {.a=2, .b=5 }}
  };
  for (i = 0; i < 2; ++i) {
    eredmeny = compare(testlist[i].a, testlist[i].b);
    if (eredmeny.a != testlist[i].eredmeny.a || eredmeny.b != testlist[i].eredmeny.b) {
      fprintf(stderr, "HIBA: compare([%d,%d], [%d,%d])\n"
		      "\telvárt eredmény: [%d,%d]\n"
		      "\tkapott eredmény: [%d,%d]\n",
		      testlist[i].a.a, testlist[i].a.b, testlist[i].b.a, testlist[i].b.b,
		      testlist[i].eredmeny.a, testlist[i].eredmeny.b,
		      eredmeny.a, eredmeny.b
      );
    }
  }
#endif
}

void call_3()
{
	int chck;
	int n, i, j;
	char **ptr = NULL;
	if(fscanf(stdin, "%d %d", &chck, &n)!=2) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	ptr = foglal(n);
	switch (chck) {
		case 1:
			if (ptr != NULL) {
				free(ptr);
				fprintf(stdout,"%d\n", n);
			} else {
				fprintf(stdout,"NULL\n");
			}
			break;
		case 2:
			for(i=0; i<n; i++) {
				free(ptr[i]);
				fprintf(stdout,"%d", n);
			}
			fputc('\n', stdout);
			break;
		case 3:
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					fputc(ptr[i][j], stdout);
				}
				fputc('\n', stdout);
			}
			break;
		default:
			if(fscanf(stdin, "%d %d", &i, &j)!=2) {
				fprintf(stderr, "HIBA: Nem olvasható adat!\n");
				return;
			}
			fprintf(stdout,"%c\n", ptr[i][j]);
			break;
	}
}
void test_3()
{
	const int n = 4;
	int i, j, k;
  char **ptr = NULL;
  struct {char ptr[4][4];} testlist[1] = {
  	{
  		{
  			{"hhhh"},
  			{"hiih"},
  			{"hiih"},
  			{"hhhh"}
  		}
  	}
  };
  for (i = 0; i < 1; ++i) {
    ptr = foglal(n);
    if (ptr == NULL) {
    	fprintf(stderr, "HIBA: NULL pointer\n");
    	return;
    } else {
    	for (j = 0; j < n; ++j) {
    		if (ptr[j] == NULL) {
		    	fprintf(stderr, "HIBA: NULL pointer\n");
		    	return;
    		} else {
	    		for (k = 0; k < n; ++k) {
	    			if (ptr[j][k] != testlist[i].ptr[j][k]) {
	    				fprintf(stderr, "HIBA a(z) (%d,%d) pozíción\n"
	    					              "\telvárt eredmény: %c\n"
	    					              "\tkapott eredmény: %c\n",
	    					              j, k, testlist[i].ptr[j][k], ptr[j][k]);
	    				return;
	    			}
	    		}
	    	}
    	}
    }
    for (j = 0; j < n; free(ptr[j++]));
    free(ptr);
  }
}

typedef void (*call_function)();

call_function call_table[] = {
	call_1,
	call_2,
	call_3,
	NULL
};


call_function test_table[] = {
	test_1,
	test_2,
	test_3,
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

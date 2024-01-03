#include <stdio.h>
#include <string.h>
#include "ts.h"
typedef struct quad quad;
struct quad
{
	char* opr;
	char* op1;
	char* op2;
	char* res;
};

struct quad liste[2000];
int qc = 0;


/***********************************G�n�ration de quadruplets************************************************/
void generer(char *a, char *b, char *c, char *d)
{
	liste[qc].opr = strdup(a);
	liste[qc].op1 = strdup(b);
	liste[qc].op2 = strdup(c);
	liste[qc].res = strdup(d);
	qc++;
}

/**********************************conversion d'un int en chaine de caractere******************************/
char *convert(int i)
{
	char s[15];
	sprintf(s, "%d", i);
	return strdup(s);
}
/***********************************Quads Expression logiques************************************************/
void quadL(int i, char *b, char *c, char *d)
{
	switch (i)
	{
	case 1:
		generer("BNZ", convert(qc + 3), b, "");
		generer("=", "", "1", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "0", d);
		break;
	case 2:
		generer("BNZ", convert(qc + 4), b, "");
		generer("BNZ", convert(qc + 3), c, "");
		generer("=", "", "0", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "1", d);
		break;
	case 3:
		generer("BZ", convert(qc + 4), b, "");
		generer("BZ", convert(qc + 3), c, "");
		generer("=", "", "1", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "0", d);
		break;
	}
}

/***********************************Quads Expressions de comparaison************************************************/
void quadC(int i, char *b, char *c, char *d)
{
	switch (i)
	{
	case 1:
		generer("-", b, c, d);
		generer("BG", convert(qc + 3), d, "");
		generer("=", "", "0", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "1", d);
		break;
	case 2:
		generer("-", b, c, d);
		generer("BGE", convert(qc + 3), d, "");
		generer("=", "", "0", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "1", d);
		break;
	case 3:
		generer("-", b, c, d);
		generer("BL", convert(qc + 3), d, "");
		generer("=", "", "0", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "1", d);
		break;
	case 4:
		generer("-", b, c, d);
		generer("BLE", convert(qc + 3), d, "");
		generer("=", "", "0", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "1", d);
		break;
	case 5:
		generer("-", b, c, d);
		generer("BZ", convert(qc + 3), d, "");
		generer("=", "", "0", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "1", d);
		break;
	case 6:

		generer("-", b, c, d);
		generer("BNZ", convert(qc + 3), d, "");
		generer("=", "", "0", d);
		generer("BR", convert(qc + 2), "", "");
		generer("=", "", "1", d);
		break;
	}
}


/***********************************Fonction d'affichage des quadruplets************************************************/

void afficher_qdr()
{
	printf("*********************Quadruplet***********************\n");

	int i;

	for (i = 0; i < qc; i++)
	{

		printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )", i, liste[i].opr, liste[i].op1, liste[i].op2, liste[i].res);
		printf("\n---------------------------------------------------\n");
	}
}
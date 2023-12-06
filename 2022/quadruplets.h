#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct qdr{

    char oper[30];
    char op1[30];
    char op2[30];
    char res[30];

  }qdr;
  qdr quad[1000];
  
extern int qc;





void quadruplet(char opr[],char op1[],char op2[],char res[])
{

	strcpy(quad[qc].oper,opr);
	strcpy(quad[qc].op1,op1);
	strcpy(quad[qc].op2,op2);
	strcpy(quad[qc].res,res);


qc++;

}

void maj_quad(int num_quad, int colon_quad, char val [])
{
if (colon_quad==0) strcpy(quad[num_quad].oper,val);
else if (colon_quad==1) strcpy(quad[num_quad].op1,val);
         else if (colon_quad==2) strcpy(quad[num_quad].op2,val);
                   else if (colon_quad==3) strcpy(quad[num_quad].res,val);

}

void afficher_qdr()
{
printf("\n\n*********************Les Quadruplets***********************\n");

int i;

for(i=0;i<qc;i++)
		{

 printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )",i,quad[i].oper,quad[i].op1,quad[i].op2,quad[i].res);
 printf("\n--------------------------------------------------------\n");

}
}

char ope1[12];
char ope2[12];


void ajout_quad_opbinaire(char op , float *opa,float * opb)
{
            sprintf(ope1,"%f",*opa);
            sprintf(ope2,"%f",*opb);
            switch (op)
            {
            case '+': quadruplet("+",ope1,ope2,"<tmporaire>"); break;
            case '-': quadruplet("-",ope1,ope2,"<tmporaire>");break;
            case '*': quadruplet("*",ope1,ope2,"<tmporaire>");  break;
            case '/': quadruplet("+",ope1,ope2,"<tmporaire>"); break;
            }
            
}

// - op
void ajout_quad_opunaire(float * opb)
{
            
            sprintf(ope2,"%f",*opb);
            quadruplet("-","0",ope2,"<temporaire>");
            
}

void ajout_quad_affect_val(char entite[],float *val){

               sprintf(ope1,"%f",*val);
               quadruplet("=",ope1,"",entite)  ;
}


           


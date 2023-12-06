/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
   int state;
   char name[20];
   char code[20];
   char type[20];
   float val;
   char valstr[50];
 } element;

typedef struct
{ 
   int state; 
   char name[20];
   char type[20];
} elt;

element tab[1000]; //table des symboles IDF et CONST
elt tabs[40],tabm[40]; // tabs: table des separateurs, tabm: table des mots cles
extern char sav[20];
char chaine [] = "";
int cpt, cpts, cptm;


/***Step 2: initialisation de l'état des cases des tables des symbloles***/
/*0: la case est libre    1: la case est occupée*/

void initialisation()
{
  int i;
  for (i=0;i<1000;i++)  tab[i].state=0; 	   
  for (i=0;i<40;i++) {tabs[i].state=0; tabm[i].state=0;}
cpt=0; cpts=0; cptm=0;
}


/***Step 3: insertion des entititées lexicales dans les tables des symboles ***/

void inserer (char entite[], char code[],char type[],float val, char valstr[], int i,int y)
{
  switch (y)
 { 
   case 0:/*insertion dans la table des IDF et CONST*/
       tab[i].state=1;
       strcpy(tab[i].name,entite);
       strcpy(tab[i].code,code);
	   strcpy(tab[i].type,type);
	   tab[i].val=val;
       strcpy(tab[i].valstr,valstr);
       cpt++;
	   break;

   case 1:/*insertion dans la table des mots clés*/
       tabm[i].state=1;
       strcpy(tabm[i].name,entite);
       strcpy(tabm[i].type,code);
       cptm++;
       break; 
    
   case 2:/*insertion dans la table des séparateurs*/
      tabs[i].state=1;
      strcpy(tabs[i].name,entite);
      strcpy(tabs[i].type,code);
      cpts++;
      break;
 }

}

/***Step 4: La fonction Rechercher permet de verifier  si l'entité existe dèja dans la table des symboles */
void rechercher (char entite[], char code[],char type[],float val,char valstr[], int y)	
{

int j,i;

switch(y) 
  {
   case 0:
      /*verifier si la case dans la tables des IDF et CONST est libre*/
        if(cpt==0)  inserer(entite,code,type,val,valstr,0,0); 
        else{
        for (i=0; ((i<1000)&&(tab[i].state==1))&&(strcmp(entite,tab[i].name)!=0);i++); 
        if((i<1000)&&(strcmp(entite,tab[i].name)!=0))
        { 
	        
			inserer(entite,code,type,val,valstr,i,0); 
	      
         }
       // else
         // printf("entité existe déjà\n");
        }
        break;

   case 1:/*verifier si la case dans la tables des mots clés est libre*/
       if(cptm==0) inserer(entite,code,type,val,valstr,0,1); 
       else{
       for (i=0;((i<40)&&(tabm[i].state==1))&&(strcmp(entite,tab[i].name)!=0);i++); 
        if(i<40)
          inserer(entite,code,type,val,valstr,i,1);
        //else
         // printf("entité existe déjà\n");
       }
        break; 
    
   case 2:/*verifier si la case dans la tables des séparateurs est libre*/
         if(cpts==0) inserer(entite,code,type,val,valstr,0,2);
         else{
         for (i=0;((i<40)&&(tabs[i].state==1))&&(strcmp(entite,tab[i].name)!=0);i++); 
        if(i<40)
         inserer(entite,code,type,val,valstr,i,2);
        //else
   	     //  printf("entité existe déjà\n");
         }
        break;

  }

}


/***Step 5 L'affichage du contenue de la table des symboles ***/

void afficher()
{int i;
 
printf("\n\n/****************** Table des symboles ******************/\n\n");
printf("\n/*************** Table des symboles IDF ***************/\n");
printf("_______________________________________________________________________________\n");
printf("\t|   Nom_Entite   |  Code_Entite   |   Type_Entite   |   Val_Entite    |\n");
printf("_______________________________________________________________________________\n");
  
  // si idf or cst a une valeur numerique on affiche val sinon on affiche val_string 

for(i=0;i<cpt;i++)
{	
	
    if(tab[i].state==1)
      { 
		if((strcmp(tab[i].type,"chainec")==0) || (strcmp(tab[i].type,"LOGICAL")==0))
		{
        	printf("\t|%15s |%15s | %15s | %15s | \n",tab[i].name,tab[i].code,tab[i].type,tab[i].valstr);}
		else{
			printf("\t|%15s |%15s | %15s | %15f |  \n",tab[i].name,tab[i].code,tab[i].type,tab[i].val);
		}	
         
      }
}

 
printf("\n/*************** Table des symboles mots cles ***************\n");

printf("___________________________________________\n");
printf("\t|    NomEntite   |    CodeEntite  | \n");
printf("___________________________________________\n");
  
for(i=0;i<cptm;i++)
    if(tabm[i].state==1)
      { 
        printf("\t|%15s |%15s | \n",tabm[i].name, tabm[i].type);
               
      }

printf("\n/*************** Table des symboles separateurs ***************\n");

printf("___________________________________________\n");
printf("\t|    NomEntite   |    CodeEntite  | \n");
printf("___________________________________________\n");
  
for(i=0;i<cpts;i++)
    if(tabs[i].state==1)
      { 
        printf("\t|%15s |%15s | \n",tabs[i].name,tabs[i].type );
        
      }

}

		
    int Recherche_position(char entite[])
		{
		int i=0;
		while(i<1000)
		{
		
		if (strcmp(entite,tab[i].name)==0) return i;	
		i++;
		}
 
		return -1;
		
		}

	 void insererTYPE(char entite[], char type[])
	{
       int pos;
	   pos=Recherche_position(entite);
	   if(pos!=-1)  { strcpy(tab[pos].type,type); }
	}
    
	
	int doubleDeclaration(char entite[]){
	int pos;
	pos= Recherche_position(entite);
	if(strcmp(tab[pos].type,"")==0) return 0;
	   else return -1;
	  
	
	}



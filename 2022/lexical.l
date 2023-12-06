%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ts.h"
#include "syn.tab.h"


// semligne semcol est pour stocker la vrai valeur de nb_ligne et col
//car l'affichage des erreurs syntax et semantique  se fait apres le saut de ligne 


int nb_ligne=1 ,semligne; 				
char tmps_signed_numbers[20];
char 
extern  Col,semcol;
extern  pile_tmps;
 extern YYSTYPE yylval;
 int cpt;

%}

/* regex de base */

num [0-9]
lettre [a-zA-Z]
lettre_maj [A-Z]

/*IDF et CST */

unsigned_int {num}+ 
unsigned_float   {num}*[.]{num}+ 

signed_int "\("[+-]{num}+"\)"
signed_float (\([+-]{num}+"."{num}+\))


char \'[^']\'
boolean true|false
IDF{lettre_maj}({lettre}|{num})*
comment \#(.*\n)


%%
"if"    { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_if ;} 
"else"   { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_else;} 
"while"   { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_while;} 
"for"    { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_for;} 
"range"    { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext); Col=Col+strlen(yytext); return mc_range; } 
"and"    { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_and ; } 
"or"    { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_or; } 
"not"    { rechercher(yytext,"Mot cle","",0,"", 1); yylval.str=strdup(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_not;} 
"in"    { rechercher(yytext,"Mot cle","",0,"", 1); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_in; } 
"int"    { rechercher(yytext,"Mot cle","",0,"", 1); yylval.str=strdup(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_int;} 
"float"    { rechercher(yytext,"Mot cle","",0,"", 1); yylval.str=strdup(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_float;} 
"bool"    { rechercher(yytext,"Mot cle","",0,"", 1); yylval.str=strdup(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_bool;} 
"char"    { rechercher(yytext,"Mot cle","",0,"", 1); yylval.str=strdup(yytext); printf ("ligne %d : mot cle  reconnue est %s \n", nb_ligne,yytext);  Col=Col+strlen(yytext); return mc_char;} 
{unsigned_int} { yylval.entier=atoi(yytext); 
                       Col = Col + strlen(yytext);
                       if(yylval.entier>32767 || yylval.entier<(-32768)){
						     printf ("Erreur lexicale: depassement de la taille des entiers  a la Ligne %d et a la colonne %d \n", nb_ligne, Col);	
					   }
					   else {
						     rechercher (yytext,"Cst_entier","INTEGER",atoi(yytext),"", 0);
						     printf("Ligne %d integer reconnu %s \n" ,nb_ligne, yytext );   return cst_int; 
					   }
	}
{signed_int} { 		   strcpy(tmps_signed_numbers, substring(yytext,1,strlen(yytext)-1));
					   yylval.entier=atoi(tmps_signed_numbers); 
                       Col = Col + strlen(yytext);
                       if(yylval.entier>32767 || yylval.entier<(-32768)){
						     printf ("Erreur lexicale: depassement de la taille des entiers  a la Ligne %d et a la colonne %d \n", nb_ligne, Col);
					   }
					   else {
						     rechercher (tmps_signed_numbers,"Cst entier ","INTEGER",atoi(tmps_signed_numbers),"", 0);
						     printf("Ligne %d  signed integer reconnu %s \n" ,nb_ligne, yytext );   return cst_int; 
					   }
	}	
{unsigned_float} { rechercher (yytext,"cst_reel","FLOAT",atof(yytext),"",0); yylval.reel=atof(yytext);printf("Ligne %d  float reconnu %s \n" ,nb_ligne, yytext );  Col = Col + strlen(yytext); return cst_reel;}

{signed_float} { strcpy(tmps_signed_numbers, substring(yytext,1,strlen(yytext)-1));
					   yylval.entier=atoi(tmps_signed_numbers); 

				
				rechercher (tmps_signed_numbers,"Cst reel ","FLOAT",atof(tmps_signed_numbers),"",0);
				yylval.reel=atof(tmps_signed_numbers); printf("Ligne %d  signed float reconnu %s \n" ,nb_ligne, yytext ); 
				Col = Col + strlen(yytext); return cst_reel;}


{char}  { rechercher (yytext,"cst_char","CHAR",0,yytext, 0); yylval.car=strdup(yytext); printf("Ligne %d char reconnu %s \n" ,nb_ligne, yytext );  Col = Col + strlen(yytext); return cst_car;}
{boolean} {rechercher(yytext,"cst_bool","BOOLEAN",0,yytext, 0);yylval.car=strdup(yytext); printf("ligne %d : boolean reconnu %s \n",nb_ligne,yytext);Col=Col+strlen(yytext); return cst_bool; }
{IDF} {   
			       Col= Col+ strlen (yytext); 
                   if (yyleng<=8) {   
				                    rechercher (yytext,"IDF ","",0,"", 0);
			                        printf("Ligne %d IDF reconnu %s \n" ,nb_ligne, yytext ); 
                                    yylval.str=strdup(yytext);									
									return idf;
							      }
                    else printf ("Erreur lexicale Ligne %d colonne %d , IDF %s trop long   \n", nb_ligne, Col,yytext);
 }
{comment} {nb_ligne++;}
"," { rechercher (yytext,"Virgule","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return virgule; }
";" { rechercher (yytext,"point_Virgule","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return point_Virgule ;}
"." { rechercher (yytext,"Point","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext); return point; }
":" { rechercher (yytext,"deux_Point","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext);  return deux_Point; }
"+" { rechercher (yytext,"addition","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext);  return addition;}
"-" { rechercher (yytext,"substraction","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );   Col=Col+strlen(yytext); return substraction;}
"/" { rechercher (yytext,"division","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return division; }
"*" { rechercher (yytext,"multiplication","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext);  return multiplication;}
"=" { rechercher (yytext,"affectation","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return affectation;  }
"(" { rechercher (yytext,"parenthese_ouvr","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return parenthese_ouvr; }
")" { rechercher (yytext,"parenthese_ferm","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);   return parenthese_ferm;}
"[" { rechercher (yytext,"crocht_ouvr","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return crocht_ouvr; }
"]" { rechercher (yytext,"crocht_ferm","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext); return crocht_ferm; }
"{" { rechercher (yytext,"accolade_ouvr","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext);  return accolade_ouvr;}
"}" { rechercher (yytext,"accolade_ferm ","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return accolade_ferm; }
"%" { rechercher (yytext,"modulo","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext); return  modulo;}
"@" { rechercher (yytext,"address" , "",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext); return address;} 
"&" { rechercher (yytext,"ampersand" , "",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext); return ampersand;} 
"#" { rechercher (yytext,"diese","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext);  return diese;}
"<" { rechercher (yytext,"inf ","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext); return inf ;}
">" { rechercher (yytext,"sup ","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return  sup;}
">=" { rechercher (yytext,"sup_equal","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext);  return sup_equal;}
"<=" { rechercher (yytext,"inf_equal ","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext );  Col=Col+strlen(yytext);  return inf_equal;}
"==" { rechercher (yytext,"equal ","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);   return equal;}
"!=" { rechercher (yytext,"not_equal ","",0,"", 2); printf("ligne %d : separateur reconnu   %s \n" , nb_ligne,yytext ); Col=Col+strlen(yytext);  return not_equal; }
[ \t ] { Col = Col + strlen(yytext); }
"    " {Col = Col + 4;return tabulation;}

\n {semligne=nb_ligne;semcol=Col; nb_ligne++;Col = 1; return sautdligne;}


. printf("Erreur lexicale ligne %d colonne %d sur l'entite %s\n",nb_ligne,Col,yytext);
%%



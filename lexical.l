%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "synt.tab.h"
#include "ts.h"

int nb_ligne = 1;
int nb_colonne = 1;
extern YYSTYPE yylval;
%}
lettre [a-zA-Z]
chiffre [0-9]
IDF {lettre}({lettre}|{chiffre})*
UNSIGNED_INT [0-9]+
UNSIGNED_REAL [0-9]+\.[0-9]+
SIGNED_INT [-]?[0-9]+
SIGNED_REAL [-]?[0-9]+\.[0-9]+
LOGICAL "TRUE"|"FALSE" 
chainec \"[^\"]*\"
COMMENTAIRE %[^;]*;	
%%
"=" { rechercher (yytext,"egalite","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return aff;}
"-" { rechercher (yytext,"soustraction","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return opar_moins;}
"+" { rechercher (yytext,"addition","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return opar_plus;}
"*" { rechercher (yytext,"multiplication","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return opar_mult;}
"/" { rechercher (yytext,"division","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return opar_div;}
"." { rechercher (yytext,"point","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return point;}
"(" { rechercher (yytext,"par_ouvr","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return po;}
")" { rechercher (yytext,"par_ferm","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return pf;}
"," { rechercher (yytext,"virgule","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return vg;}
";" { rechercher (yytext,"point_virgule","",0,"", 2); nb_colonne=nb_colonne+strlen(yytext); return pvg;}
"THEN" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_then;}
"IF" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_if;}
"ELSE" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_else;}
"PROGRAM" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_program;}
"ENDIF" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_endif;}
"CHARACTER" {yylval.str=strdup(yytext);rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_character;}
"REAL" {yylval.str=strdup(yytext);rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_real;}
"ENDDO" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_enddo;}
"READ" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_read;}
"WRITE" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_write;}
"INTEGER" {yylval.str=strdup(yytext);rechercher (yytext,"Mot cle","",0, "", 1); yylval.str=strdup(yytext); rechercher (yytext,"Mot cle","",0, "", 1);  nb_colonne=nb_colonne+strlen(yytext); return mc_integer;}
"ENDR" {rechercher (yytext,"Mot cle","",0, "", 1);nb_colonne=nb_colonne+strlen(yytext); return mc_endr;}
"ROUTINE" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_routine;}
"EQUIVALENCE" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_equivalence;}
"GT" {rechercher (yytext,"Mot Cle","",0,"", 1); nb_colonne=nb_colonne+strlen(yytext); return op_gt;}
"LT" {rechercher (yytext,"Mot Cle","",0,"", 1); nb_colonne=nb_colonne+strlen(yytext); return op_lt;}
"GE" {rechercher (yytext,"Mot Cle","",0,"", 1); nb_colonne=nb_colonne+strlen(yytext); return op_ge;}
"NE" {rechercher (yytext,"Mot Cle","",0,"", 1); nb_colonne=nb_colonne+strlen(yytext); return op_ne;}
"LE" {rechercher (yytext,"Mot Cle","",0,"", 1); nb_colonne=nb_colonne+strlen(yytext); return op_le;}
"OR" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return op_or;}
"AND" {rechercher (yytext,"Mot cle","",0, "", 1);nb_colonne=nb_colonne+strlen(yytext); return op_and;}
"DOWHILE" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_dowhile;}
"END" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_end;}
"CALL" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_call;}
"DIMENSION" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_dimension;}
"EQ" {rechercher (yytext,"mot cle","",0,"", 1); nb_colonne=nb_colonne+strlen(yytext); return op_eq;}
"LOGICAL" {rechercher (yytext,"Mot cle","",0, "", 1); nb_colonne=nb_colonne+strlen(yytext); return mc_logical;}
{LOGICAL} {yylval.str=strdup(yytext);rechercher (yytext,"cst LOGICAL","LOGICAL",0,yytext, 0); nb_colonne=nb_colonne+strlen(yytext); return cst_bool;}
{COMMENTAIRE} {nb_colonne = nb_colonne + strlen(yytext);}
{chainec} {rechercher (yytext,"CST CHARACTER","chainec",0,yytext, 0); yylval.str=strdup(yytext); nb_colonne=nb_colonne+strlen(yytext); return cst_char;}
{UNSIGNED_INT} {
    if (atoi(yytext) > 32767) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        rechercher (yytext,"Cst INTEGER ","INTEGER",atoi(yytext),"", 0);
        nb_colonne = nb_colonne + strlen(yytext);
        yylval.entier= atoi(yytext);
        return cst_int;
    }
}
{UNSIGNED_REAL} {
    if (atof(yytext) > 32767 || atof(yytext) < -32768) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        rechercher (yytext,"Cst REAL","REAL",atof(yytext),"", 0);
        nb_colonne = nb_colonne + strlen(yytext);
        yylval.str=strdup(yytext);
        return cst_real;
    }
}
{SIGNED_INT} {
    if (atoi(yytext) > 32767 || atoi(yytext) < -32768) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        rechercher (yytext,"Cst INTEGER ","INTEGER",atoi(yytext),"", 0);
        nb_colonne = nb_colonne + strlen(yytext);
        yylval.reel= atof(yytext);
        return cst_int;
    }
}
{SIGNED_REAL} {
    if (atof(yytext) > 32767 || atof(yytext) < -32768) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        rechercher (yytext,"Cst REEL","REEL",atof(yytext),"",0);
        nb_colonne = nb_colonne + strlen(yytext);
        yylval.reel=atof(yytext);
        return cst_real;
    }
}
{IDF} {
    if(yyleng > 10){
        printf("WARNING: identificateur trop long\n");
    }
    else{
            rechercher (yytext,"IDF ","",0,"", 0); 
			yylval.str=strdup(yytext); }
            nb_colonne=nb_colonne+strlen(yytext);
    return idf;

}
[ \t] nb_colonne=nb_colonne+strlen(yytext);
\n  nb_ligne++; nb_colonne = 1; 
. { printf("erreur lexicale (non reconnu)\n"); nb_colonne=nb_colonne+strlen(yytext); }
%%




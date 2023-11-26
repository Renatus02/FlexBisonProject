%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "synt.tab.h"
int nb_ligne = 1;
int nb_colonne = 1;
%}
lettre [a-zA-Z]
chiffre [0-9]
IDF {lettre}({lettre}|{chiffre})*
UNSIGNED_INT [0-9]+
UNSIGNED_FLOAT [0-9]+\.[0-9]+
SIGNED_INT [-]?[0-9]+
SIGNED_FLOAT [-]?[0-9]+\.[0-9]+
LOGICAL "TRUE"|"FALSE" 
chainec \"[^\"]*\"
COMMENTAIRE %[^;]*;	
%%
"=" {printf("= reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return aff;}
"+" {printf("+ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar_plus;}
"-" {printf("- reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar_moins;}
"*" {printf("* reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar_mult;}
"/" {printf("/ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar_div;}
"." {printf(". reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return point;}
"(" {printf("( reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return po;}
")" {printf(") reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return pf;}
"," {printf(", reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return vg;}
";" {printf("; reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return pvg;}
"THEN" {printf("keyword THEN reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_then;}
"IF" {printf("keyword IF reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_if;}
"ELSE" {printf("keyword ELSE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_else;}
"PROGRAM" {printf("keyword PROGRAM reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_program;}
"ENDIF" {printf("keyword ENDIF reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_endif;}
"CHARACTER" {printf("keyword CHARACTER reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_character;}
"REAL" {printf("keyword REAL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_real;}
"ENDDO" {printf("keyword ENDDO reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_enddo;}
"READ" {printf("keyword READ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_read;}
"WRITE" {printf("keyword WRITE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_write;}
"INTEGER" {printf("keyword INTEGER reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_integer;}
"ENDR" {printf("keyword ENDR reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_endr;}
"ROUTINE" {printf("keyword ROUTINE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_routine;}
"EQUIVALENCE" {printf("keyword EQUIVALENCE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_equivalence;}
"GT" {printf(" GT reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_gt;}
"LT" {printf(" LT reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_lt;}
"GE" {printf(" GE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_ge;}
"NE" {printf(" NE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_ne;}
"LE" {printf(" LE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_le;}
"OR" {printf("keyword OR reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_or;}
"AND" {printf("keyword AND reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_and;}
"DOWHILE" {printf("keyword DOWHILE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_dowhile;}
"END" {printf("keyword END reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_end;}
"CALL" {printf("keyword CALL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_call;}
"DIMENSION" {printf("DIMENSION reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_dimension;}
"EQ" {printf("EQ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return op_eq;}
"LOGICAL" {printf("LOGICAL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_logical;}
{LOGICAL} {printf("LOGICAL reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return cst_bool;}
{COMMENTAIRE} { nb_colonne = nb_colonne + strlen(yytext); }
{chainec} { printf("CHAINE DE CHARACTERS reconnu %s a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return cst_char;}
{UNSIGNED_INT} {
    if (atoi(yytext) > 32767) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        nb_colonne = nb_colonne + strlen(yytext);
        printf("UNSIGNED_INT reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
        return cst_int;
    }
}
{UNSIGNED_FLOAT} {
    if (atof(yytext) > 32767 || atof(yytext) < -32768) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        nb_colonne = nb_colonne + strlen(yytext);
        printf("UNSIGNED_FLOAT reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
        return cst_float;
    }
}
{SIGNED_INT} {
    if (atoi(yytext) > 32767 || atoi(yytext) < -32768) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        nb_colonne = nb_colonne + strlen(yytext);
        printf("SIGNED_INT reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
        return cst_int;
    }
}
{SIGNED_FLOAT} {
    if (atof(yytext) > 32767 || atof(yytext) < -32768) {
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        nb_colonne = nb_colonne + strlen(yytext);
        printf("SIGNED_FLOAT reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
        return cst_float;
    }
}
{IDF} {
    if(yyleng > 10){
        printf("WARNING: identificateur trop long\n");
    }
    else{
			printf("IDF reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
	}
    nb_colonne=nb_colonne+strlen(yytext);
    return idf;

}
[ \t] nb_colonne=nb_colonne+strlen(yytext);
\n  nb_ligne++; nb_colonne = 1; 
. { printf("erreur lexicale (non reconnu)\n"); nb_colonne=nb_colonne+strlen(yytext); }
%%

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
cst [+-]?{chiffre}+([.]{chiffre}+)?
LOGICAL "TRUE"|"FALSE" 
chainec \"[^\"]*\"
COMMENTAIRE %[^;]*;
%%
"=" {printf(" = reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return aff;}
"+" {printf(" + reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar;}
"-" {printf(" - reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar;}
"*" {printf(" * reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar;}
"/" {printf(" / reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opar;}
"." {printf(" . reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return point;}
"(" {printf(" ( reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return po;}
")" {printf(" ) reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return pf;}
"," {printf(" , reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return vg;}
";" {printf(" ; reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return pvg;}
"THEN" {printf("keyword THEN reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_then;}
"IF" {printf("keyword IF reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_if;}
"ELSE" {printf("keyword ELSE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_else;}
"PROGRAM" {printf("keyword PROGRAM reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_program;}
"ENDIF" {printf("keyword ENDIF reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_endif;}
"CHARACTER" {printf("keyword CHARACTER reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_character;}
"REAL" {printf("keyword REAL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_real;}
"ENDDO" {printf("keyword ENDDO reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);	return mc_enddo;}
"READ" {printf("keyword READ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_read;}
"WRITE" {printf("keyword WRITE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_write;}
"INTEGER" {printf("keyword INTEGER reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_integer;}
"ENDR" {printf("keyword ENDR reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_endr;}
"ROUTINE" {printf("keyword ROUTINE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_routine;}
"RETURN" {printf("keyword RETURN reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_return;}
"EQUIVALENCE" {printf("keyword EQUIVALENCE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_equivalence;}
"GT" {printf(" GT reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opcomp;}
"LT" {printf(" LT reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opcomp;}
"GE" {printf(" GE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opcomp;}
"NE" {printf(" NE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opcomp;}
"LE" {printf(" LE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return opcomp;}
"OR" {printf("keyword OR reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return oplog;}
"AND" {printf("keyword AND reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return oplog;}
"DOWHILE" {printf("keyword DOWHILE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_dowhile;}
"END" {printf("keyword END reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_end;}
"CALL" {printf("keyword CALL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_call;}
"DIMENSION" {printf("DIMENSION reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_dimension;}
"EQ" {printf("EQ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); 
nb_colonne=nb_colonne+strlen(yytext); return opcomp;}
"LOGICAL" {printf("LOGICAL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return mc_logical;}
{LOGICAL} {printf("LOGICAL reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext); return cst;}
{COMMENTAIRE} {
	nb_colonne = nb_colonne + strlen(yytext);
}
{chainec} {
	printf("CHAINE DE CHARACTERS reconnu %s a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
	nb_colonne=nb_colonne+strlen(yytext);
	return cst_char;
}
{cst} {
    if(atof(yytext) > 32767 || atof(yytext) < -32768){
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        printf("CST reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
	nb_colonne=nb_colonne+strlen(yytext);
	return cst;
    }
}
{IDF} {
	if(yyleng > 60){
		printf("WARNING: ligne %d, identificateur trop long\n",nb_ligne);
	}
	else{
		printf("IDF reconnu %s a la ligne %d, colonne %d\n",yytext, nb_ligne, nb_colonne);
	}
	nb_colonne=nb_colonne+strlen(yytext);
	return idf;
}
[ \t] nb_colonne=nb_colonne+strlen(yytext);
[\n] { nb_ligne++; nb_colonne = 1; return saut_ligne;}
. printf("erreur lexicale %s a la ligne %d, colonne %d (non reconnu) \n",yytext, nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);
%%

%{
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
"=" {printf(" = reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"+" {printf(" + reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"-" {printf(" - reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"*" {printf(" * reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"/" {printf(" / reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"." {printf(" . reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"(" {printf(" ( reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
")" {printf(" ) reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"," {printf(" , reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
";" {printf(" ; reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"THEN" {printf("keyword THEN reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"IF" {printf("keyword IF reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"ELSE" {printf("keyword ELSE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"PROGRAM" {printf("keyword PROGRAM reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"ENDIF" {printf("keyword ENDIF reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"CHARACTER" {printf("keyword CHARACTER reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"REAL" {printf("keyword REAL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"ENDDO" {printf("keyword ENDDO reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"READ" {printf("keyword READ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"WRITE" {printf("keyword WRITE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"INTEGER" {printf("keyword INTEGER reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"ENDR" {printf("keyword ENDR reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"ROUTINE" {printf("keyword ROUTINE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"RETURN" {printf("keyword RETURN reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"EQUIVALENCE" {printf("keyword EQUIVALENCE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"GT" {printf(" GT reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"LT" {printf(" LT reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"GE" {printf(" GE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"NE" {printf(" NE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"LE" {printf(" LE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"OR" {printf("keyword OR reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"AND" {printf("keyword AND reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"DOWHILE" {printf("keyword DOWHILE reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"END" {printf("keyword END reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"CALL" {printf("keyword CALL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"DIMENSION" {printf("DIMENSION reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"EQ" {printf("EQ reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
"LOGICAL" {printf("Keyword LOGICAL reconnu a la ligne %d, colonne %d\n", nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
{LOGICAL} {printf("LOGICAL reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);}
{COMMENTAIRE} {
	nb_colonne = nb_colonne + strlen(yytext);
}
{chainec} {
	printf("CHAINE DE CHARACTERS reconnu %s a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
	nb_colonne=nb_colonne+strlen(yytext);
}
{cst} {
    if(atof(yytext) > 32767 || atof(yytext) < -32768){
        printf("WARNING: ligne %d, colonne %d, nombre trop grand\n", nb_ligne, nb_colonne);
    } else {
        printf("CST reconnu(%s) a la ligne %d, colonne %d\n", yytext, nb_ligne, nb_colonne);
	nb_colonne=nb_colonne+strlen(yytext);
    }
}
{IDF} {
	if(yyleng > 10){
		printf("WARNING: ligne %d, identificateur trop long\n",nb_ligne);
	}
	else{
		printf("IDF reconnu %s a la ligne %d, colonne %d\n",yytext, nb_ligne, nb_colonne);
	}
	nb_colonne=nb_colonne+strlen(yytext);
}
[ \t] nb_colonne=nb_colonne+strlen(yytext);
\n { nb_ligne++; nb_colonne = 1;}
. printf("erreur lexicale %s a la ligne %d, colonne %d (non reconnu) \n",yytext, nb_ligne, nb_colonne); nb_colonne=nb_colonne+strlen(yytext);
%%
int main (){
	yylex();
	return 0;
}

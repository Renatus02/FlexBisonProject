%{
#include "pgm.tab.h"
extern YYSTYPE yylval;
#include "quads.h"
%}

idf [A-Z][a-zA-Z]*
cst [0-9]+

%%
if  { ECHO; return mc_if;}
else { ECHO;return mc_else;}
{idf} { ECHO;yylval.str=strdup(yytext);return idf;}
{cst} { ECHO;yylval.num=atoi(yytext);return cst;}
[=;()v] {ECHO; return yytext[0];}
[ \t\n]  {ECHO;}
. printf ("erreur lexicale");


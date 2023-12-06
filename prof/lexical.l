%{
   
   #include "synt.tab.h"
   extern nb_ligne;
   extern Col;
   #include "ts.h"
   extern YYSTYPE yylval;
   
%}
lettreM [A-Z]
lettre [a-zA-Z]
chiffre [0-9]                                  
IDF {lettreM}({lettre}|{chiffre})*
cst [+-]?{chiffre}+
%%
Programme    {  rechercher (yytext,"Mot cle "," ",0, 1); Col= Col+ strlen (yytext);  return mc_pgm;}
INTEGER      {  yylval.str=strdup(yytext); 
                rechercher (yytext,"Mot cle "," ",0, 1); 
                Col= Col+ strlen (yytext); 
				return mc_entier;
    		}
REAL         {  yylval.str=strdup(yytext);
                rechercher (yytext,"Mot cle "," ",0, 1); 
				Col= Col+ strlen (yytext);  
				return mc_reel;
			}
STRING       {  yylval.str=strdup(yytext); rechercher (yytext,"Mot cle "," ",0, 1); Col= Col+ strlen (yytext);  return mc_str;}
ARRAY        {  rechercher (yytext,"Mot cle "," ",0, 1); Col= Col+ strlen (yytext);  return mc_array;}
VAR          {  rechercher (yytext,"Mot cle "," ",0, 1); Col= Col+ strlen (yytext);  return mc_var;}
CONST        {  rechercher (yytext,"Mot cle "," ",0, 1); Col= Col+ strlen (yytext);  return mc_const;}
EG           {  rechercher (yytext,"Mot cle "," ",0, 1); Col= Col+ strlen (yytext);  return mc_eg;}
{IDF}        { 
               rechercher (yytext,"IDF ","",88888888, 0); 
			   Col= Col+ strlen (yytext); 
               if (yyleng<10) { yylval.str=strdup(yytext);
			                    return idf;
							  }
                else printf ("Erreur lexicale: IDF trop long %s a la ligne %d et a la colonne %d \n", yytext, nb_ligne, Col);
			 }

{cst}        {
               rechercher (yytext,"Cst entiere ","Entier",atoi(yytext), 0); 
               Col= Col+ strlen (yytext); 
			   yylval.entier= atoi(yytext);
			   return cst;
        	 }		  
"##"         {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return dz;}
"/"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return division;}
"+"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return addition;}
"-"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return soustraction;}
"*"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return multi;}
"::"         {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return dpts;}
"="          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return egale;}
":="         {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return aff;}
"{"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return acco;}
"}"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return accf;}
"["          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return crov;}
"]"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return crof;}
";"          {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return fin;}
","         {rechercher (yytext,"Separateur",0,0, 2); Col= Col+ strlen (yytext);return sep;}
[ \t]        {Col= Col+ strlen (yytext);}   
\n    {nb_ligne++; Col=1;}
. printf ("Erreur lexicale : Entite lexicale non reconnue %s a la ligne %d et a la colonne %d\n",yytext, nb_ligne, Col);
%%

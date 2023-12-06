%{
   int nb_ligne=1, Col=1;
   char sauvType[25];
        
        
%}

%union 
{ 
   int entier; 
   char* str;
}

%token mc_pgm  soustraction <str>mc_entier  <str>mc_reel <str>mc_str  mc_array mc_var  mc_const mc_eg <str>idf <entier>cst dz division addition multi dpts egale aff acco accf crov crof fin sep 
%start S
%%
S:  mc_pgm idf  acco  PGM  accf 
    {printf ("programme syntaxiquement correcte \n"); YYACCEPT;}
;
PGM :  mc_var    LIST_DEC        mc_const  LIST_DEC_CST    LIST_INST
     | mc_const  LIST_DEC_CST    mc_var    LIST_DEC        LIST_INST
     | mc_const  LIST_DEC_CST                              LIST_INST
	 | mc_var    LIST_DEC                                  LIST_INST
;
LIST_INST: INST LIST_INST
         |
;		 
INST: INST_AFF 
      | INST_ARITH
;
INST_AFF: idf  aff   EXPRESSION    fin
           {
   			  if(doubleDeclaration($1)==0) 
			  printf("Erreur semantique: %s variable non declaree a la ligne %d\n",$1,nb_ligne);
							
                             							   
		}

		| idf crov cst crof  aff   EXPRESSION    fin
		  {
   			  if(doubleDeclaration($1)==0) 
			  printf("Erreur semantique: %s variable non declaree a la ligne %d\n",$1,nb_ligne);
					
                             							   
		}
;

EXPRESSION: idf	
            |cst
;
	
		  
INST_ARITH: idf aff idf division  cst fin 
              {   if ($5==0)
			      {
				    printf ("Erreur semantique division par 0 à la ligne %d et a la colonne %d \n",nb_ligne,Col); 
				  }
				  else 
				  printf ( "L operation  %s = %s / %d \n", $1,$3,$5);
				  
				  if(doubleDeclaration($1)==0) 
					printf("Erreur semantique: %s variable non declaree a la ligne %d\n",$1,nb_ligne);
				  if(doubleDeclaration($3)==0) 
						       printf("Erreur semantique: %s variable non declaree a la ligne %d\n",$3,nb_ligne);
                             	
			  }
           |idf aff idf addition cst fin 
		                 {
   						    if(doubleDeclaration($1)==0) 
						       printf("Erreur semantique: %s variable non declaree a la ligne %d\n",$1,nb_ligne);
							if(doubleDeclaration($3)==0) 
						       printf("Erreur semantique: %s variable non declaree a la ligne %d\n",$3,nb_ligne);
                             							   
						 }
		   
           |idf aff cst addition cst fin
		                  {
   						    if(doubleDeclaration($1)==0) 
						       printf("erreur semantique %s variable non declaree a la ligne %d\n",$1,nb_ligne);
						 }
           |idf aff cst addition idf fin		   
                         {
   						    if(doubleDeclaration($1)==0) 
						       printf("erreur semantique %s variable non declaree a la ligne %d\n",$1,nb_ligne);
							if(doubleDeclaration($5)==0) 
						       printf("erreur semantique %s variable non declaree a la ligne %d\n",$5,nb_ligne);   
						 }
;
LIST_DEC_CST : DEC_CST LIST_DEC_CST
          |
;		  
	 
DEC_CST: TYPE dpts LIST_IDF_CONST  fin
;			 
LIST_IDF_CONST: idf egale cst sep 	LIST_IDF_CONST
              |		 idf egale cst
;			  
LIST_DEC : DEC LIST_DEC 
         |
;		 
DEC: DEC_VAR
    | DEC_TAB
;   
DEC_TAB: TYPE dpts idf crov cst crof fin
      {
	    if ($5<0)
	    printf("Erreur semantique: la taille de tableau %d doit etre positive a la ligne %d a la colonne %d\n ",$5,nb_ligne, Col);
      }
;
DEC_VAR: TYPE dpts LIST_IDF fin

;
LIST_IDF: idf sep LIST_IDF    { if(doubleDeclaration($1)==0)   { insererTYPE($1,sauvType);}
							    else 
								printf("Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d\n",$1,nb_ligne,Col);
							  }
        |idf                  { 
		                        if(doubleDeclaration($1)==0)   
								    { 
   									    insererTYPE($1,sauvType);
								    }
							    else 
								printf("Erreur semantique: double declaration  de %s a la ligne %d et la colonne %d \n",$1,nb_ligne, Col);
							  }
;		

TYPE: mc_reel      {strcpy(sauvType,$1);} 
     |mc_entier    {strcpy(sauvType,$1);} 
;	 
        
   
%%
main()
{
  initialisation();
  afficher();
  yyparse();
  afficher();
  
}
yywrap()
{}
yyerror (char*msg)
{
   printf("Erreur syntaxique a la ligne %d et a la colonne %d", nb_ligne, Col);
}
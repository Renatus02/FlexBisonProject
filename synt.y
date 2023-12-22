%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    extern char currentScope[10];
    extern char typeidf[10];
    int nb_ligne = 1;
    int nb_colonne = 1;

%}

%union 
{ 
   int entier; 
   float reel;
   char* str;
}

%token aff point po pf vg <str>idf pvg mc_then mc_if mc_else mc_program mc_endif mc_character mc_real mc_enddo mc_read mc_write mc_integer mc_endr mc_routine mc_equivalence mc_dowhile mc_end mc_call mc_dimension mc_logical <str>cst_char opar_plus opar_moins opar_div opar_mult <str>cst_bool <entier>cst_int <reel>cst_real op_gt op_lt op_eq op_ge op_le op_and op_or op_ne;
%left op_and op_or;
%left op_gt op_ge op_eq op_ne op_le op_lt;
%left opar_plus opar_moins;
%left opar_mult opar_div;
%start PROG
%%

//l'axiome de la grammaire
PROG: ROUTINE PROG | PP {printf("syntaxe correcte\n"); YYACCEPT;}



//la grammaire

PP: mc_program idf {
    strcpy(currentScope, "main");

} 
CORP_PROGRAM



CORP_PROGRAM: LIST_DECLARATION LIST_INSTRUCTION mc_end;



ROUTINE: TYPE mc_routine idf {
    strcpy(currentScope, $3);

if (doubleDeclaration($3, currentScope)) {
        
        printf("double declaration de la variable %s\n", $3);
        
    }
    else 
    insererTYPE($3, typeidf, currentScope);

} po LIST_PARAMETRE pf CORP_FONCTION 

       | mc_character mc_routine idf{
        strcpy(currentScope, $3);
        if (doubleDeclaration($3, currentScope)) {
        
        printf("double declaration de la variable %s\n", $3);
        
    }
    else 
    insererTYPE($3, typeidf, currentScope);
        } opar_mult CST po LIST_PARAMETRE pf CORP_FONCTION 
       
       | mc_character mc_routine idf{
        strcpy(currentScope, $3);
        if (doubleDeclaration($3, currentScope)) {
        
        printf("double declaration de la variable %s\n", $3);
        
    }
    else 
    insererTYPE($3, typeidf, currentScope);
        } po LIST_PARAMETRE pf CORP_FONCTION 



CORP_FONCTION: LIST_DECLARATION LIST_INSTRUCTION RETURN mc_endr {strcpy(currentScope, "");}



RETURN: idf aff EXPRESSION;



OPAR: opar_plus

    | opar_moins 
 
    | opar_mult;



TYPE: mc_integer {strcpy(typeidf, "INTEGER");}

    | mc_real {strcpy(typeidf, "REAL");}
    
    | mc_logical {strcpy(typeidf, "LOGICAL");}



LIST_PARAMETRE: idf  

              | LIST_PARAMETRE vg idf 

              | CST 

              | LIST_PARAMETRE vg CST 

              | LIST_PARAMETRE vg idf po CST pf 

              | LIST_PARAMETRE vg idf po CST vg CST pf 

              | ;



LIST_DECLARATION: LIST_DECLARATION TYPE DECLARATION pvg 

                | LIST_DECLARATION mc_character DECLARATION pvg 
                
                | ;



DECLARATION: idf {
    
    if (doubleDeclaration($1, currentScope)) {
        
        printf("double declaration de la variable %s\n", $1);
        
    }
    else 
    insererTYPE($1, typeidf, currentScope);
    
    }

           | DECLARATION vg idf {
    
    if (doubleDeclaration($3, currentScope)) {
        
        printf("double declaration de la variable %s\n", $3);
        
    }
    else 
    insererTYPE($3, typeidf, currentScope);
    
    }
           
           | DECLARATION mc_dimension po CST pf 
           
           | DECLARATION mc_dimension po CST vg CST pf; 
        
           | DECLARATION opar_mult CST;



AFFECT: idf aff EXPRESSION {if(!doubleDeclaration($1, currentScope)) printf("la variable %s n'est pas declarer\n", $1);}
| idf po CST pf aff EXPRESSION {if(!doubleDeclaration($1, currentScope)) printf("la variable %s n'est pas declarer\n", $1);}
| idf po CST vg CST pf aff EXPRESSION {if(!doubleDeclaration($1, currentScope)) printf("la variable %s n'est pas declarer\n", $1);};



EXPRESSION: CST 

          | idf 
          
          | cst_char 
          
          | cst_bool 
          
          | EXPRESSION OPAR idf 
          |EXPRESSION opar_div idf
          
          | EXPRESSION OPAR CST 

          | EXPRESSION opar_div cst_int  {   if ($3==0)
			      {
				    printf ("Erreur semantique division par 0 a la ligne %d et a la colonne %d \n",nb_ligne,nb_colonne); 
				  }
          }
          
          | po EXPRESSION pf 
          
          | CALL 
          

          | EXPRESSION OPAR cst_char 
          | EXPRESSION opar_div cst_char
          
          | EXPRESSION po CST pf 
          
          | EXPRESSION po CST vg CST pf 
          
          | EXPRESSION OPAR po EXPRESSION pf;



CALL: mc_call idf po LIST_PARAMETRE pf;



READ: mc_read po idf pf;



WRITE: mc_write po WRITE_ARGS pf;



WRITE_ARGS: cst_char 

          | idf 
          
          | WRITE_ARGS vg cst_char 
          
          | WRITE_ARGS vg idf;



CONDITION: mc_if po exp_cnd pf mc_then LIST_INSTRUCTION mc_else LIST_INSTRUCTION mc_endif 

         | mc_if po cst_bool pf mc_then LIST_INSTRUCTION mc_else LIST_INSTRUCTION mc_endif;



exp_cnd: EXPRESSION point OPCOMP point EXPRESSION 

       | exp_cnd point OPLOG point LALR 
       
       | LALR;



LALR: po exp_cnd pf;



INSTRUCTION: AFFECT pvg 

           | WRITE pvg 
           
           | READ pvg 
           
           | CONDITION 
           
           | BOUCLE 
           
           | EQ pvg;       



LIST_INSTRUCTION: LIST_INSTRUCTION INSTRUCTION 

                | ;



BOUCLE: mc_dowhile po exp_cnd pf LIST_INSTRUCTION mc_enddo;



EQ: mc_equivalence po LIST_PARAMETRE pf vg po LIST_PARAMETRE pf 

  | mc_equivalence po LIST_PARAMETRE pf;



CST: cst_int 

   | cst_real;



OPLOG: op_and 
     
     | op_or;



OPCOMP: op_gt 

      | op_lt 
      
      | op_eq 
      
      | op_ge 
      
      | op_le 
      
      | op_ne;




%%

#include <stdio.h>
int yyerror(char *msg) {
    printf(" ------------------------------- Erreur Syntaxique at ligne: %d et colonne: %d -------------------------------", nb_ligne, nb_colonne);
    return 1;
}

int yywrap() {
    return 1;
}

int main() {
    initialisation();
    yyparse();
    afficher();
    return 0;
}
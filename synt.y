%{
    #include <string.h>
    char sauv[20];
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

PP: mc_program idf CORP_PROGRAM {if(doubleDeclaration($2) == 1) printf("Erreur Semantique: %s idf deja declaree pour un routine\n", $2);};



CORP_PROGRAM: LIST_DECLARATION LIST_INSTRUCTION mc_end;



ROUTINE: TYPE mc_routine idf po LIST_PARAMETRE pf CORP_FONCTION {
    
    if(doubleDeclaration($3) == 1)
     printf("Erreur Semantique: %s routine deja declaree\n", $3);
    
    
    }

       | mc_character mc_routine idf opar_mult CST po LIST_PARAMETRE pf CORP_FONCTION {if(doubleDeclaration($3) == 1) printf("Erreur Semantique: %s routine deja declaree\n", $3);}
       
       | mc_character mc_routine idf po LIST_PARAMETRE pf CORP_FONCTION {if(doubleDeclaration($3) == 1) printf("Erreur Semantique: %s routine deja declaree\n", $3); else insererTYPE($3, sauv);};



CORP_FONCTION: LIST_DECLARATION LIST_INSTRUCTION RETURN mc_endr;



RETURN: idf aff EXPRESSION {if(doubleDeclaration($1) == 0) printf("Erreur Semantique: %s routine non declaree\n", $1);}



OPAR: opar_plus

    | opar_moins 
 
    | opar_div 
 
    | opar_mult;



TYPE: mc_integer {strcpy(sauv, $1);}

    | mc_real {strcpy(sauv, $1);}
    
    | mc_logical {strcpy(sauv, $1);};



LIST_PARAMETRE: idf {if(doubleDeclaration($1) == 0) printf("Erreur Semantique: %s variable non declare\n", $1);}

              | LIST_PARAMETRE vg idf { if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declare\n", $3);}

              | CST 

              | LIST_PARAMETRE vg CST 

              | LIST_PARAMETRE vg idf po CST pf  {if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declare\n", $3);}

              | LIST_PARAMETRE vg idf po CST vg CST pf {if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declare\n", $3);}

              | ;



LIST_DECLARATION: LIST_DECLARATION TYPE DECLARATION pvg 

                | LIST_DECLARATION mc_character DECLARATION pvg 
                
                | ;



DECLARATION: idf {if(doubleDeclaration($1) == 1) printf("Erreur Semantique: %s variable deja declaree\n", $1); else insererTYPE($1, sauv);}

       | DECLARATION vg idf {if(doubleDeclaration($3) == 1) printf("Erreur Semantique: %s variable deja declaree\n", $3); else insererTYPE($3, sauv);}
           
           | DECLARATION mc_dimension po CST pf 
           
           | DECLARATION mc_dimension po CST vg CST pf; 
           
           | DECLARATION opar_mult CST;



AFFECT: idf aff EXPRESSION {
if(doubleDeclaration($1) == 0) 
    printf("Erreur Semantique: %s variable non declaree\n", $1);

};

EXPRESSION: CST 

          | idf {if(doubleDeclaration($1) == 0) printf("Erreur Semantique: %s variable non declaree\n", $1);}
          
          | cst_char {if(doubleDeclaration($1) == 0) printf("Erreur Semantique: %s variable non declaree\n", $1);}
          
          | cst_bool {if(doubleDeclaration($1) == 0) printf("Erreur Semantique: %s variable non declaree\n", $1);}
          
          | EXPRESSION OPAR idf {if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declaree\n", $3);}
          
          | EXPRESSION OPAR CST 
          
          | po EXPRESSION pf 
          
          | CALL 
          
          | EXPRESSION OPAR cst_char {if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declaree\n", $3);}
          
          | EXPRESSION po CST pf 
          
          | EXPRESSION po CST vg CST pf 
          
          | EXPRESSION OPAR po EXPRESSION pf;



CALL: mc_call idf po LIST_PARAMETRE pf;



READ: mc_read po idf pf {if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declaree\n", $3);};



WRITE: mc_write po WRITE_ARGS pf;



WRITE_ARGS: cst_char

          | idf {if(doubleDeclaration($1) == 0) printf("Erreur Semantique: %s variable non declaree\n", $1);} 
          
          | WRITE_ARGS vg cst_char {if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declaree\n", $3);}
          
          | WRITE_ARGS vg idf {if(doubleDeclaration($3) == 0) printf("Erreur Semantique: %s variable non declaree\n", $3);};



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
    printf(" ------------------------------------------ Erreur Syntaxique ------------------------------------------");
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
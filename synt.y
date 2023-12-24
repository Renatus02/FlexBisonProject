%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    extern char currentScope[10];
    extern char typeidf[10];
    void erreur_dd(char* idf);
    void erreur_nondec(char* idf);
    char *determiner_type(char* type1, char* type2);
    char *getidfType(char entite[], char scope[]);
    int nb_ligne = 1;
    int nb_colonne = 1;

%}

%union 
{ 
   int entier; 
   float reel;
   char* str;
   struct 
   {
       char *type;
   }exp;
}

%token aff point po pf vg <str>idf pvg mc_then mc_if mc_else mc_program mc_endif mc_character mc_real mc_enddo mc_read mc_write mc_integer mc_endr mc_routine mc_equivalence mc_dowhile mc_end mc_call mc_dimension mc_logical <str>cst_char opar_plus opar_moins opar_div opar_mult <str>cst_bool <entier>cst_int <reel>cst_real op_gt op_lt op_eq op_ge op_le op_and op_or op_ne;
%type <exp> EXPRESSION AFFECT CALL CST;
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
    if (doubleDeclaration($1, currentScope)) erreur_dd($1);
    else insererTYPE($1, typeidf, currentScope);
    }

           | DECLARATION vg idf {
    
    if (doubleDeclaration($3, currentScope)) erreur_dd($3); 
    else insererTYPE($3, typeidf, currentScope);
    
    }
           
           | DECLARATION mc_dimension po CST pf 
           
           | DECLARATION mc_dimension po CST vg CST pf; 
        
           | DECLARATION opar_mult CST;



AFFECT: idf aff EXPRESSION {
    determiner_type(getidfType($1, currentScope), $3.type);

    }


      | idf po CST pf aff EXPRESSION {
        determiner_type(getidfType($1, currentScope), $6.type);

}
      

      | idf po CST vg CST pf aff EXPRESSION {
        determiner_type(getidfType($1, currentScope), $8.type);

}
      




EXPRESSION: CST {$$ = $1;}

          | idf { 
            if(!doubleDeclaration($1, currentScope)) erreur_nondec($1);
            $$.type = getidfType($1, currentScope);
          }
          
          | cst_char {$$.type = "CHARACTER";}
          
          | cst_bool {$$.type = "LOGICAL";}
          
          | EXPRESSION OPAR idf { 
            $$.type = determiner_type($1.type, getidfType($3, currentScope));
          }

          | EXPRESSION opar_div idf { 
            $$.type = determiner_type($1.type, getidfType($3, currentScope));
          }
          
          | EXPRESSION OPAR CST { 
            $$.type = determiner_type($1.type, $3.type);
          }

          | EXPRESSION opar_div cst_real { 
            $$.type = determiner_type($1.type, "REAL");
          }

          | EXPRESSION opar_div cst_int  { if ($3==0) 
          printf ("Erreur semantique division par 0 a la ligne %d et a la colonne %d \n",nb_ligne,nb_colonne); 
          $$.type = determiner_type($1.type, "INTEGER");
          }
          
          | po EXPRESSION pf { $$ = $2; }
          
          | CALL { $$ = $1; }
          

          | EXPRESSION OPAR cst_char { 
            $$.type = determiner_type($1.type, "CHARACTER");}

          | EXPRESSION opar_div cst_char { 
            $$.type = determiner_type($1.type, "CHARACTER");}
          
          | EXPRESSION po CST pf { 
            $$.type = determiner_type($1.type, $3.type);}
          
          | EXPRESSION po CST vg CST pf { 
            $$.type = determiner_type($1.type, $3.type);}
          
      | EXPRESSION OPAR po EXPRESSION pf 

          | EXPRESSION opar_div po EXPRESSION pf { 
            $$.type = determiner_type($1.type, $4.type);}



CALL: mc_call idf po LIST_PARAMETRE pf { 
    if(!doubleDeclaration($2, currentScope)) erreur_nondec($2);
    $$.type = getidfType($2, currentScope);
    }



READ: mc_read po idf pf;



WRITE: mc_write po WRITE_ARGS pf;



WRITE_ARGS: cst_char 

          | idf { if(!doubleDeclaration($1, currentScope)) erreur_nondec($1);}
          
          | WRITE_ARGS vg cst_char 
          
          | WRITE_ARGS vg idf { if(!doubleDeclaration($3, currentScope)) erreur_nondec($3);}



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



CST: cst_int {$$.type = "INTEGER"; }

   | cst_real {$$.type = "REAL"; }



OPLOG: op_and 
     
     | op_or;



OPCOMP: op_gt 

      | op_lt 
      
      | op_eq 
      
      | op_ge 
      
      | op_le 
      
      | op_ne;




%%

void erreur_dd(char *idf){
    printf("Erreur semantique: double declaration de la variable %s a la ligne %d et la colonne %d\n", idf, nb_ligne, nb_colonne);
}

void erreur_nondec(char *idf){
    printf("Erreur semantique: variable %s non declarer dans %s a la ligne %d et la colonne %d\n", idf, currentScope, nb_ligne, nb_colonne);
}

char *determiner_type(char* type1, char* type2) {
    // Handle cases where either type is unspecified
    if (type1[0] == ' ' || type2[0] == ' ') {
        return type1[0] == ' ' ? type2 : type1;
    }

    // Handle cases where types are compatible or both are the same
    if (strcmp(type1, type2) == 0) {
        return type1;
    }

    // Handle cases where types are incompatible
    printf("Erreur semantique: incompatibilite de types a la ligne %d et a la colonne %d\n", nb_ligne, nb_colonne);
    return " ";
}
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
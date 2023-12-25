%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    extern char currentScope[10];
    extern char typeidf[10];
    char arr[100];
    void erreur_dd(char* idf);
    void erreur_dim(char* idf);
    int getDimension(char entite[], char scope[]);
    void erreur_nondec(char* idf);
    char *incomp_type(char* type1, char* type2);
    char *type_idf(char entite[], char scope[]);
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
       float val;
   }exp;
}

%token aff point po pf vg <str>idf pvg mc_then mc_if mc_else mc_program mc_endif mc_character mc_real mc_enddo mc_read mc_write mc_integer mc_endr mc_routine mc_equivalence mc_dowhile mc_end mc_call mc_dimension mc_logical <str>cst_char opar_plus opar_moins opar_div opar_mult <str>cst_bool <entier>cst_int <reel>cst_real op_gt op_lt op_eq op_ge op_le op_and op_or op_ne;
%type <str> TYPE;
%type <exp> EXPRESSION AFFECT CALL CST DECLARATION;
%left op_and op_or;
%left op_gt op_ge op_eq op_ne op_le op_lt;
%left opar_plus opar_moins;
%left opar_mult opar_div;
%start PROG
%%

//l'axiome de la grammaire
PROG: {strcpy(currentScope, "main");} ROUTINE PROG | PP {printf("syntaxe correcte\n"); YYACCEPT;}



//la grammaire

PP: mc_program idf {
    strcpy(currentScope, "main");

} CORP_PROGRAM



CORP_PROGRAM: LIST_DEC LIST_INSTRUCTION mc_end;



ROUTINE: TYPE mc_routine idf {
    strcpy(currentScope, $3);

if (doubleDeclaration($3, currentScope)) {
        
        printf("double declaration de la routine %s\n", $3);
        
    }
    else 
    insererTYPE($3, typeidf, currentScope);

} po LIST_PARAMETRE_RT pf CORP_FONCTION



CORP_FONCTION: LIST_DEC LIST_INSTRUCTION RETURN mc_endr {strcpy(currentScope, "main");}



RETURN: idf aff EXPRESSION 



OPAR: opar_plus

    | opar_moins 
 
    | opar_mult;



TYPE: mc_integer {strcpy(typeidf, "INTEGER");}

    | mc_real {strcpy(typeidf, "REAL");}
    
    | mc_logical {strcpy(typeidf, "LOGICAL");}
    | mc_character {strcpy(typeidf, "CHARACTER");}



LIST_PARAMETRE_RT: idf 

              | LIST_PARAMETRE_RT vg idf 

              | CST 

              | LIST_PARAMETRE_RT vg CST 

              | LIST_PARAMETRE_RT vg idf po CST pf 

              | LIST_PARAMETRE_RT vg idf po CST vg CST pf 

              | ;



LIST_DECLARATION_IDF: DECLARATION 
                
                | | DECLARATION vg LIST_DECLARATION_IDF;

DEC: TYPE LIST_DECLARATION_IDF;

LIST_DEC: | DEC pvg LIST_DEC;

DECLARATION: idf {
    if (doubleDeclaration($1, currentScope)) erreur_dd($1);
    else insererTYPE($1, typeidf, currentScope);
    }
           
       | idf mc_dimension po cst_int pf {
       if(doubleDeclaration($1, currentScope)) erreur_dd($1); 
       else
           {
            strcpy(arr, typeidf);
            strcat(arr, "()");
            insererTYPE($1, arr, currentScope);
           }
           
           }
           | idf mc_dimension po cst_int vg cst_int pf 
           {
            if(doubleDeclaration($1, currentScope)) erreur_dd($1); 
            else
            {
            strcpy(arr, typeidf);
            strcat(arr, "(,)");
            insererTYPE($1, arr, currentScope);
            }
           }

           | idf opar_mult cst_int {if(doubleDeclaration($1, currentScope)) erreur_dd($1);
            else insererTYPE($1, typeidf, currentScope);
            }



AFFECT: idf aff EXPRESSION {
    if(!doubleDeclaration($1, currentScope)) erreur_nondec($1);
    else
    incomp_type(type_idf($1, currentScope), $3.type);

    }


| idf po CST pf aff EXPRESSION {
    if (!doubleDeclaration($1, currentScope)) 
        erreur_nondec($1); else
        incomp_type(type_idf($1, currentScope), $6.type);
        if (getDimension($1, currentScope) != 1) 
            erreur_dim($1);
            
    } 

| idf po CST vg CST pf aff EXPRESSION {
    if (!doubleDeclaration($1, currentScope)) erreur_nondec($1);
    else
     incomp_type(type_idf($1, currentScope), $8.type);
    if (getDimension($1, currentScope) != 2) erreur_dim($1);

}
      




EXPRESSION: CST {$$ = $1;}

          | idf { 
            if(!doubleDeclaration($1, currentScope)) erreur_nondec($1);
            $$.type = type_idf($1, currentScope);
          }
          
          | cst_char {$$.type = "CHARACTER";}
          
          | cst_bool {$$.type = "LOGICAL";}
          
          | EXPRESSION OPAR idf { 
            if(!doubleDeclaration($3, currentScope)) erreur_nondec($3);
            $$.type = incomp_type($1.type, type_idf($3, currentScope));
          }

          | EXPRESSION opar_div idf { 
             if (!doubleDeclaration($3, currentScope)) erreur_nondec($3);
            $$.type = incomp_type($1.type, type_idf($3, currentScope));
          }
          
          | EXPRESSION OPAR CST { 
            $$.type = incomp_type($1.type, $3.type);
          }

          | EXPRESSION opar_div cst_real { 
            $$.type = incomp_type($1.type, "REAL");
          }

          | EXPRESSION opar_div cst_int  { if ($3==0) 
          printf ("Erreur semantique division par 0 a la ligne %d et a la colonne %d \n",nb_ligne,nb_colonne); 
          $$.type = incomp_type($1.type, "INTEGER");
          }
          
          | po EXPRESSION pf { $$ = $2; }
          
          | CALL { $$ = $1; }
          

          | EXPRESSION OPAR cst_char { 
            $$.type = incomp_type($1.type, "CHARACTER");}

          | EXPRESSION opar_div cst_char { 
            $$.type = incomp_type($1.type, "CHARACTER");}
          
          | EXPRESSION po CST pf { 
            $$.type = type_idf($1.type, currentScope);}
          
          | EXPRESSION po CST vg CST pf { 
            $$.type = type_idf($1.type, currentScope);}
          
      | EXPRESSION OPAR po EXPRESSION pf 

          | EXPRESSION opar_div po EXPRESSION pf { 
            $$.type = incomp_type($1.type, $4.type);}



CALL: mc_call idf po LIST_PARAMETRE_RT pf { 
    if(!doubleDeclaration($2, currentScope)) erreur_nondec($2);
    $$.type = type_idf($2, currentScope);
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

LIST_PARAMETRE_EQ: idf { if(!doubleDeclaration($1, currentScope)) erreur_nondec($1);}

              | LIST_PARAMETRE_EQ vg idf { if(!doubleDeclaration($3, currentScope)) erreur_nondec($3);}

              | CST 

              | LIST_PARAMETRE_EQ vg CST 

              | LIST_PARAMETRE_EQ vg idf po CST pf { if(!doubleDeclaration($3, currentScope)) erreur_nondec($3);}

              | LIST_PARAMETRE_EQ vg idf po CST vg CST pf { if(!doubleDeclaration($3, currentScope)) erreur_nondec($3);}

              | ;

EQ: mc_equivalence po LIST_PARAMETRE_EQ pf vg po LIST_PARAMETRE_EQ pf 

  | mc_equivalence po LIST_PARAMETRE_EQ pf;



CST: cst_int {$$.type = "INTEGER"; $$.val = $1;} 

   | cst_real {$$.type = "REAL"; $$.val = $1;}



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
char *incomp_type(char* type1, char* type2) {
    if (type1[0] == ' ' || type1[0] == '\0') {
        return type2;
    }
    if (type2[0] == ' ' || type2[0] == '\0') {
        return type1;
    }

    if (type1[0] == type2[0]) {
        return type1;
    }
    printf("Erreur semantique: incompatibilite de types a la ligne %d et a la colonne %d\n", nb_ligne, nb_colonne);
    return " ";
}




void erreur_dim(char* idf) {
    printf("Erreur semantique: dimension de la variable %s incorrecte a la ligne %d et a la colonne %d\n", idf, nb_ligne, nb_colonne);
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
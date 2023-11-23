%{
    #include <string.h>
%}


%token saut_ligne aff point po pf vg cst idf pvg mc_then mc_if mc_else mc_program mc_endif mc_character mc_real mc_enddo mc_read mc_write mc_integer mc_endr mc_routine mc_return mc_equivalence opcomp oplog mc_dowhile mc_end mc_call mc_dimension mc_logical cst_char opar_plus opar_moins opar_div opar_mult cst_bool
%start S
%%
S: ROUTINE saut S | pp S | {printf("syntaxe correcte"); YYACCEPT;};
saut: saut_ligne saut | saut_ligne;
pp: mc_program idf saut corp_program;
corp_program: list_declaration list_instruction mc_end;
ROUTINE: type mc_routine idf po list_parametre pf saut corp_fonction; | mc_character mc_routine idf opar_mult cst po list_parametre pf saut corp_fonction;
corp_fonction: list_declaration list_instruction mc_endr; 
opar: opar_plus | opar_moins | opar_div | opar_mult;
type: mc_integer | mc_real | mc_logical;
list_parametre: idf | list_parametre vg idf | ;
list_declaration: list_declaration type list_idf pvg saut | list_declaration mc_character list_idf pvg saut | list_declaration type list_idf pvg | list_declaration mc_character list_idf pvg | ;
list_idf: idf | list_idf vg idf | list_idf mc_dimension po cst pf | list_idf mc_dimension po cst vg cst pf; | list_idf opar_mult cst;
affect: idf aff expression;
expression: cst | idf | cst_char | cst_bool | expression opar idf | expression opar cst | po expression pf | call | expression opar cst_char | expression po cst pf | expression po cst vg cst pf;
call: mc_call idf po list_parametre pf;
read: mc_read po idf pf;
write: mc_write po write_args pf;
write_args: cst_char | idf | write_args vg cst_char | write_args vg idf;
condition: mc_if po exp_cnd pf mc_then list_instruction mc_else list_instruction mc_endif;
exp_cnd: ;
instruction: affect | write | read | condition | boucle | eq;
list_instruction: list_instruction instruction pvg saut | list_instruction instruction pvg | ;
boucle: mc_dowhile po exp_cnd pf list_instruction mc_enddo;
eq: mc_equivalence po list_parametre pf vg list_parametre pf pvg;
%%

#include <stdio.h>
int yyerror(char *msg) {
    printf("%s\n", msg);
    return 1;
}

int yywrap() {
    return 1;
}

int main() {
    yyparse();
    return 0;
}

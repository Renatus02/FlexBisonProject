%{
  #include<stdio.h>
  #include "syntaxe-copy.tab.h"
  int yylex(void);
  int yyerror(char* msg);
%}

%token idf cst opl opc opa po pf vg pnt aff pvg mc_program mc_end mc_routine mc_endr mc_integer mc_character mc_real mc_logical mc_dimension mc_read mc_write mc_if mc_then mc_else mc_endif mc_dowhile mc_enddo mc_call mc_equivalence;
%start S
%%

S: f S | p S |  { printf("syntaxe correct."); YYACCEPT;};

f: typ mc_routine idf list_prms list_dec list_inst mc_endr;

p: mc_program idf list_dec list_inst mc_end;


typ: mc_integer | mc_real | mc_logical | mc_character;
list_idf: idf | idf vg list_idf;
list_prms: po pf | po list_idf pf;

dec: typ idf pvg | typ list_idf pvg | typ tab pvg;
tab: idf mc_dimension po cst pf | idf mc_dimension po cst vg cst pf;
list_dec: dec list_dec;

inst: Aff | call | entr | sort | cond | boucle | eqival;
list_inst: | inst list_inst;

Aff: idf aff exp pvg;
idx: idf po cst pf | idf po cst vg cst pf;

sort: mc_write po cst vg idf vg cst pf pvg;
entr: mc_read po idf pf pvg;
exp: exp opa exp | po exp pf | idf | cst;

call: mc_call idf list_prms;

cond: mc_if po exp_cond pf mc_then list_inst mc_else list_inst mc_endif;
exp_cond: exp | po exp_cond pf | exp_cond pnt opc pnt exp_cond | exp_cond pnt opl pnt exp_cond;

boucle: mc_dowhile po exp_cond pf list_inst mc_enddo;
eqival: mc_equivalence po list_idf pf vg po list_idf pf pvg;

%%

int yyerror(char *msg) {
  printf("%s", msg);
  return 1;
}

int main() {
  yyparse();
  return 0;
}


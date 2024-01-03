%{
    int Fin_if=0,  deb_else=0;
    int qc=0;
    char tmp [20]; 
%}

%union {
int num;
char* str;
   }

%token <str>idf <num>cst mc_if mc_else
%type <str>inst_if
%type <str>inst_aff
%% 
// ON OUBLIGER De COUPER LA GRAMMAIRE POUR INSERER LES ROUTINES
inst_if: B mc_else inst_aff  {  sprintf(tmp,"%d",qc);  
                                ajour_quad(Fin_if,1,tmp);
								printf("\n qc dans INST_IF %d \n", qc);
								printf("pgm juste");
}
;
                                                                  		
B: A inst_aff  {  
				   Fin_if=qc; 
                   printf("\n Fin_if%d \n", Fin_if);				   
				   printf("\n qc dans B %d \n", qc);
                   quadr("BR", "","vide", "vide");   
				   sprintf(tmp,"%d",qc);    
                   ajour_quad(deb_else,1,tmp); 
				   }
;    
                                 
A: mc_if '(' cond ')'
    {  deb_else=qc; // J'ai laisser le champs 2 vide. Je dois le remplir apres
	printf("\n qc deb_else  %d \n", deb_else);
       quadr("BZ", "","temp_cond", "vide"); 
	   printf("\n qc dans A %d \n", qc);
                                                                       		
	}
;
inst_aff: idf '=' cst ';' {  
                              
                              printf("cst %d",$3); 
                              sprintf(tmp,"%d",$3);  
                              quadr("=",tmp,"vide",$1); 
                              printf("\n qc dans INST_AFF %d \n", qc);							  } 
													
;



cond: 'v';
%%
main()
{
yyparse();
afficher_qdr();
}

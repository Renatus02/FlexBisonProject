

Les taches faites : 
- la reconaissance lexical 
-la reconaissance syntaxique 
- les routines : - la double déclaration des idf 
                 - la compatibilité de type en cas d'affectation 
                 - la division par 0 
                 - la gestion des expression arithmétique et conditionnels
                 - la déclaration d'un tableau
                 - la mise à jour de type de idf 
                 - la mise à jour de valeur de idf 

-la gestion des tabulation saut de ligne dans le cas des bloc non imbrique                  

-les quadruplet : quad des exp_arth , condition , if , for_range , while , affectation

Les taches non faites : 
- les condition sont de type simple , pas de traitement logique avec or et and 

- pas de if , while , for  imbriqué , le contenu de leurs bloc instruction est une affectation 

- l'exécution de if , while , for ne fait pas son vrai travail , on a pas su faire les branchements
    if : pas de choix de bloc , mais tester la condition et exécuter les 2 bloc then et else
    for : initialisation , test , exécution du bloc une seule fois
    while : test condition , exécution du bloc une seule fois

- Risque de ne pas avoir la ligne exacte de l'erreur a cause de saut de ligne 

- chaque ligne d'instruction doit se terminer directement par un saut de ligne , risque d'erreur syntaxique au cas ou espace puis saut 
- une ligne vide en fin de fichier est nécessaire pour avoir un program correct syntaxiquement



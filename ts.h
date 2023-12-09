#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct listidf listidf;
struct listidf {
    int state;  
    char name[20];
    char code[20];
    char type[20];
    float val;
    char valstr[50];
    int scope;  //cet variable pour savoir si la variable est locale ou globale (0: global, >0: local)
    struct listidf* next;
};
typedef struct m m;

    struct m {
        int state;
        char name[20];
        char type[20];
        struct m* next;
    };

typedef struct s s;
    struct s {
        int state;
        char name[20];
        char type[20];
        struct s* next;
    };

int currentScope = 0;
listidf* symbolTable;
m* keywordTable;
s* separatorTable;
extern char sauv[20];
char chaine[] = "";
int cpt = 0;
int cptm = 0;
int cpts = 0;
void initialisation() {
    symbolTable = NULL;
    keywordTable = NULL;
    separatorTable = NULL;
}

void inserer(char entite[], char code[], char type[], float val, char valstr[], int y) {
    if (y == 0) {
        listidf *newEntry = (listidf*)malloc(sizeof(listidf));
        newEntry->state = 1;
        strcpy(newEntry->name, entite);
        strcpy(newEntry->code, code);
        strcpy(newEntry->type, type);
        newEntry->val = val;
        newEntry->scope = currentScope;
        strcpy(newEntry->valstr, valstr);
        newEntry->next = NULL;

        if (symbolTable == NULL) {
            symbolTable = newEntry;
        } else {
            listidf* last = symbolTable;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newEntry;
        }
        cpt++;
    } else if (y == 1) {
        m* newEntry = (m*)malloc(sizeof(m));
        newEntry->state = 1;
        strcpy(newEntry->name, entite);
        strcpy(newEntry->type, code);
        newEntry->next = NULL;

        if (keywordTable == NULL) {
            keywordTable = newEntry;
        } else {
            m* last = keywordTable;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newEntry;
        }
        cptm++;
    } else if (y == 2) {
        s* newEntry = (s*)malloc(sizeof(s));
        newEntry->state = 1;
        strcpy(newEntry->name, entite);
        strcpy(newEntry->type, code);
        newEntry->next = NULL;

        if (separatorTable == NULL) {
            separatorTable = newEntry;
        } else {
            s* last = separatorTable;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newEntry;
        }
        cpts++;
    }

}



void afficher() {
    listidf* courant = symbolTable;
    printf("\n\n/****************** Table des symboles ******************/\n\n");
    printf("\n/*************** Table des symboles IDF ***************/\n");
    printf("___________________________________________________________________________________________\n");
    printf("\t|   Nom_Entite   |  Code_Entite   |   Type_Entite   |   Val_Entite    |    Scope   |\n");
    printf("___________________________________________________________________________________________\n");

    while (courant != NULL) {
        if ((strcmp(courant->type, "chainec") == 0) || (strcmp(courant->type, "LOGICAL") == 0)) {
            printf("\t|%15s |%15s | %15s | %15s | %10d |\n", courant->name, courant->code, courant->type, courant->valstr, courant->scope);
        } else {
            printf("\t|%15s |%15s | %15s | %15f | %10d |\n", courant->name, courant->code, courant->type, courant->val, courant->scope);
        }
        courant = courant->next;
    }

    
    m* current1 = keywordTable;
printf("\n/*************** Table des symboles mots cles ***************\n");
printf("___________________________________________\n");
printf("\t|    NomEntite   |    CodeEntite  | \n");
printf("___________________________________________\n");


    while (current1 != NULL) {
        printf("\t|%15s |%15s | \n", current1->name, current1->type);
        current1 = current1->next;
    }


    s* current2 = separatorTable;
printf("\n/*************** Table des symboles separateurs ***************\n");
printf("___________________________________________\n");
printf("\t|    NomEntite   |    CodeEntite  | \n");
printf("___________________________________________\n");

    while (current2 != NULL) {
        printf("\t|%15s |%15s | \n", current2->name, current2->type);
        current2 = current2->next;
    }

    printf("\n");


 

}


void rechercher(char entite[], char code[], char type[], float val, char valstr[], int y) {
    int i;

    switch (y) {
        case 0: 
            if (cpt == 0) {
                inserer(entite, code, type, val, valstr, 0);
            } else {
                listidf* current = symbolTable;
                while (current != NULL && strcmp(entite, current->name) != 0) {
                    current = current->next;
                }

                if (current == NULL) {
                    inserer(entite, code, type, val, valstr, 0);
                }
                else if(strcmp(entite, current->name) == 0 && currentScope != current->scope)
                {
                        inserer(entite, code, type, val, valstr, 0);
            }
            break;

        case 1: 
            if(strcmp("ROUTINE", entite) == 0){
                currentScope++;
              }
            if(strcmp("PROGRAM", entite) == 0){
                currentScope = 0;
            }
            if(cptm==0) {
                inserer(entite, code, type, val, valstr, 1);
            }
            else {
                m* current = keywordTable;
                while (current != NULL && strcmp(entite, current->name) != 0) {
                    current = current->next;
                }

                if (current == NULL) {

                    inserer(entite, code, type, val, valstr, 1);
                }
                }
            }
            break;

        case 2: 
            if(cpts==0) {
                inserer(entite, code, type, val, valstr, 2);
            }
            else {
                s* current = separatorTable;
                while (current != NULL && strcmp(entite, current->name) != 0) {
                    current = current->next;
                }

                if (current == NULL) {
 
                inserer(entite, code, type, val, valstr, 2);
                }
                // else
                // printf("Entity already exists\n");
            }
            break;
    }
}


int Recherche_position(char entite[]) {
    int i = 0;
    listidf* current = symbolTable;
    while (current != NULL) {
        if (strcmp(entite, current->name) == 0) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}

void insererTYPE(char entite[], char type[]) {
    int pos = Recherche_position(entite);
    if (pos != -1) {
        strcpy(symbolTable[pos].type, type);
    }
}

int doubleDeclaration(char entite[], int currentScope) {
    listidf* current = symbolTable;

    while (current != NULL) {
        if (strcmp(entite, current->name) == 0) {
            if (current->state == 0 && current->scope != currentScope) {
                // The entity is declared but not yet used and is in a different scope
                return 0;
            }
            
            // The entity is either declared and used in the same scope (double declaration) or not used in a different scope
            return -1;
        }
        current = current->next;
    }

    // The entity is not found, so there is no double declaration error
    return 0;
}

     
     
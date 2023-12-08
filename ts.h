#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct listidf listidf;
struct listidf {
    int state;  // 0: not used, 1: used
    char name[20];
    char code[20];
    char type[20];
    float val;
    char valstr[50];
    int scope;  // 0: global, >0: local scope
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
// Head pointers for the linked lists
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

// Function to insert an entity into the symbol table
void inserer(char entite[], char code[], char type[], float val, char valstr[], int y) {
    if (y == 0) {
        // Insert into symbolTable as FIFO
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
            // If symbolTable is empty, set the new entry as the head
            symbolTable = newEntry;
        } else {
            // Find the last element in the list and add the new entry
            listidf* last = symbolTable;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newEntry;
        }
        cpt++;
    } else if (y == 1) {
        // Insert into keywordTable as FIFO
        m* newEntry = (m*)malloc(sizeof(m));
        newEntry->state = 1;
        strcpy(newEntry->name, entite);
        strcpy(newEntry->type, code);
        newEntry->next = NULL;

        if (keywordTable == NULL) {
            // If keywordTable is empty, set the new entry as the head
            keywordTable = newEntry;
        } else {
            // Find the last element in the list and add the new entry
            m* last = keywordTable;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newEntry;
        }
        cptm++;
    } else if (y == 2) {
        // Insert into separatorTable as FIFO
        s* newEntry = (s*)malloc(sizeof(s));
        newEntry->state = 1;
        strcpy(newEntry->name, entite);
        strcpy(newEntry->type, code);
        newEntry->next = NULL;

        if (separatorTable == NULL) {
            // If separatorTable is empty, set the new entry as the head
            separatorTable = newEntry;
        } else {
            // Find the last element in the list and add the new entry
            s* last = separatorTable;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newEntry;
        }
        cpts++;
    }

    // Set the scope for local variables
}



// Function to display the contents of the symbol table
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
                    // Entity not found, insert into the symbol table with the current scope information
                    inserer(entite, code, type, val, valstr, 0);
                }
                else if(strcmp(entite, current->name) == 0 && currentScope != current->scope)
                {
                    // Entity found with different scope, insert into the symbol table with the current scope information
                        inserer(entite, code, type, val, valstr, 0);
            }
            break;

        case 1: // Check if the case in the keyword table is free
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
                    // Entity not found, insert into the keyword table
                    inserer(entite, code, type, val, valstr, 1);
                }
                }
            }
            break;

        case 2: // Check if the case in the separator table is free
            if(cpts==0) {
                inserer(entite, code, type, val, valstr, 2);
            }
            else {
                s* current = separatorTable;
                while (current != NULL && strcmp(entite, current->name) != 0) {
                    current = current->next;
                }

                if (current == NULL) {
                    // Entity not found, insert into the separator table
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
    int pos = Recherche_position(entite);
    
    if (pos == -1) {
        return 0;  // Not found, not a double declaration
    }

    if (symbolTable[pos].state == 0) {
        // Variable is not in the current scope, so it's not a double declaration
        return 0;
    }

    if (symbolTable[pos].state == currentScope) {
        // Variable is in the same scope, it's a double declaration
        return -1;
    }

    return 0;  // Variable is in a different scope, not a double declaration
}

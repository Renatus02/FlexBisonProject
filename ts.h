#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct listidf listidf;
struct listidf {
    int state;  
    char name[20];
    char code[20];
    char type[20];
    float val;
    char valstr[50];
    char scope[20];
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

void inserer(char entite[], char code[], char type[], float val, char valstr[], int y, char scope[]) {
    if (y == 0) {
        listidf *newEntry = (listidf*)malloc(sizeof(listidf));
        newEntry->state = 1;
        strcpy(newEntry->name, entite);
        strcpy(newEntry->code, code);
        strcpy(newEntry->type, type);
        newEntry->val = val;
        strcpy(newEntry->scope, scope);
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
    printf("\t|   Nom_Entite   |  Code_Entite   |   Type_Entite   |   Val_Entite    |    scope   |\n");
    printf("___________________________________________________________________________________________\n");

    while (courant != NULL) {
        if ((strcmp(courant->type, "chainec") == 0) || (strcmp(courant->type, "LOGICAL") == 0)) {
            printf("\t|%15s |%15s | %15s | %15s | %10s |\n", courant->name, courant->code, courant->type, courant->valstr, courant->scope);
        } else {
            printf("\t|%15s |%15s | %15s | %15f | %10s |\n", courant->name, courant->code, courant->type, courant->val, courant->scope);
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


void rechercher(char entite[], char code[], char type[], float val, char valstr[], int y, char scope[]) {
    int i;

    switch (y) {
   case 0: 
    if (cpt == 0) {
        inserer(entite, code, type, val, valstr, 0, scope);
    } else {
        listidf* current = symbolTable;
        while (current != NULL && current->state == 1) {
            if (strcmp(entite, current->name) == 0 && strcmp(current->scope, scope) == 0) {
                // variable existe deja avec le meme scope et le meme nom
                return;
            }
            current = current->next;
        }

        // variable n'existe pas
        inserer(entite, code, type, val, valstr, 0, scope);
    }
    break;
    case 1:
            if(cptm == 0) {
                inserer(entite, code, type, val, valstr, 1, "");
            }
            else {
                m* current = keywordTable;
                while (current != NULL && strcmp(entite, current->name) != 0 && current->state == 1) {
                    current = current->next;
                }

                if (current == NULL) {
                    inserer(entite, code, type, val, valstr, 1, "");
                }
            }
            break;

        case 2: 
            if(cpts == 0) {
                inserer(entite, code, type, val, valstr, 2, "");
            }
            else {
                s* current = separatorTable;
                while (current != NULL && strcmp(entite, current->name) != 0 && current->state == 1) {
                    current = current->next;
                }

                if (current == NULL) {
                    inserer(entite, code, type, val, valstr, 2, "");
                }
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

void insererTYPE(char entite[], char type[], char scope[]) {
    listidf* current = symbolTable;
    while (current != NULL) {
        if (strcmp(entite, current->name) == 0 && strcmp(current->scope, scope) == 0) {
            strcpy(current->type, type);
        }
        current = current->next;
    }
}


bool doubleDeclaration(char entite[], char scope[]) {
    listidf* current = symbolTable;
    bool trouve = false;
    while (current != NULL) {
        if (strcmp(current->type, "") != 0 && strcmp(entite, current->name) == 0 && strcmp(current->scope, scope) == 0) {
            trouve = true;
        }
        current = current->next;
    }
    return trouve;
}






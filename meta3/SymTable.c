 
 
#include "SymTable.h"
#include "STree.h"


Sym * global;

Sym * createSym(char * name, char * type, char * param) {
    Sym * newSym = (Sym *) malloc(sizeof(Sym));

    newSym->name = name;
    newSym->type = type;
    if (strlen(param) != 0) {
        newSym->param = param;
    }

    newSym->prev = NULL;
    newSym->next = NULL;
    newSym->child = NULL;

    return newSym;
}

Sym * insertSym(Sym * last, Sym * new) {
    last->next = new;
    new->prev = last;
    return new;
}

void createTable (Sym * last, struct node * root) {

    if (strcmp(root->var, "Program") == 0) {
        if (root->child) {
            global = last;
            createTable(last, root->child);
        }
    } else if (strcmp(root->var, "FieldDecl") == 0) {
        
    } else if (strcmp(root->var, "MethodDecl") == 0) {

    }

    while (last->next != NULL) {
        last = last->next;
    }

    if (root->brother) {
        createTable(last, root->brother);
    }
}

void FieldDecl (struct node * root, Sym * last, Sym * first, int aux) {
    Sym * temp;
    if (root) {
        //falta strcmp do FieldDecl
        if (CheckIfAlreadyDefined(first, root)) {
            
        }
    }
}


Sym * CheckIfAlreadyDefined(Sym * simTab, char * name, int aux) {

    while(simTab) {
        if (strcmp(simTab->name, name) == 0) {
            return simTab;
        } else {
            if (aux == 0) {
                simTab = simTab->next;
            } else {
                simTab = simTab->child;
            }
        }
    }

    return NULL;
}

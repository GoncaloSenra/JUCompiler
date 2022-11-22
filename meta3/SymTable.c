 
 
#include "SymTable.h"


Sym * table;

Sym * createSym(char * name, char * type, char * param, int line, int col, int variable) {
    Sym * newSym = (Sym *) malloc(sizeof(Sym));

    newSym->name = name;
    newSym->type = type;
    newSym->param = param;

    newSym->line = line;
    newSym->col = col;

    newSym->variable = variable;

    newSym->prev = NULL;
    newSym->next = NULL;
    newSym->in = NULL;

    return newSym;
}

Sym * insertSym(Sym * last, Sym * new) {
    last->next = new;
    new->prev = last;
    return new;
}

void createTable (Sym * last, struct node * root) {
    printf("%s\n", root->var);
    if (strcmp(root->var, "Program") == 0) {
        if (root->child) {
            /*last->name = root->child->value;
            table = last;
            last->next = createSym("", "", "", 0, 0, 0);*/
            createTable(last, root->child);
        }
    } else if (strcmp(root->var, "FieldDecl") == 0) {
        //printf("Field\n");
        FieldDecl(root, last, table, 0);
    } else if (strcmp(root->var, "MethodDecl") == 0) {
        MethodDecl(last, table, root);
    }

    while (last->next != NULL) {
        last = last->next;
    }

    if (root->brother) {
        createTable(last, root->brother);
    }
}



void FieldDecl (struct node * root, Sym * last, Sym * first, int aux) {
    Sym * aux2;
    if (root) {
        if (strcmp(root->var, "FieldDecl") == 0) {
            if (CheckIfAlreadyDefined(first, root->child->brother->value, 0) == NULL) {
                //FIXME: if is alphanumeric
                printf("cheked\n");
                if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }
                aux2 = createSym(root->child->brother->value, root->child->var, "", 0, 0, 1);
                insertSym(last, aux2);
            } else {
                printf("ERROR ALREADY DEFINED\n");
            }
        }    
    }
}

void Vardecl (struct node * root, Sym * func) {

    Sym * aux = func;
    while (aux->in != NULL) {
        aux = aux->in;
    }

    Sym * aux_func;
    if (root != NULL) {
        if (strcmp(root->var, "VarDecl") == 0) {
            if (CheckIfAlreadyDefined(func, root->child->brother->value, 1) == NULL) {
                //FIXME: if is alphanumeric
                printf("cheked\n");
                if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }
                aux_func = createSym(root->child->brother->value, root->brother->var, "", 0, 0, 1);
                aux->in = aux_func;
                aux = aux_func;
            }
        }
        
        if (root->brother != NULL)
            Vardecl(root->brother, func);
    }

}

char* myStrCat(char* s1, char* s2/*, bool free1, bool free2*/){
    static char* temps1;
    static char* temps2;
    temps1 = (char*)malloc((strlen(s1) + strlen(s2)) * sizeof(char));
    temps2 = (char*)malloc(strlen(s2) * sizeof(char));
    temps1 = strdup(s1);
    temps2 = strdup(s2);
    strcat(temps1, temps2);
    /*if (free1)
        free(s1);
    //free(temps2);
    if(free2)
        free(s2);
    return temps1;
    */
}


void Header(struct node * root, Sym * first){
    first->in = createSym("return", first->type, "", 0, 0, 0); //FIXME: verificar se correto
    Sym * aux_first = first->in;

    node * aux_root = root->child->brother->brother->child;
    char * param = "";
    printf("Header -------------- %s\n", root->child->brother->var);
    
    while(aux_root != NULL && aux_root->child != NULL){

        if(CheckIfAlreadyDefined(first->in, aux_root->child->brother->value,1)!= NULL){
            
            printf("ERROR ALREADY DEFINED\n"); //FIXME: mensagem de erro de simbolo já definido
            break;
        }else{
            
            //if
                if(strcmp(aux_root->child->var,"Bool")==0){
                    aux_root->child->var = "boolean";
                }

                if(strcmp(aux_root->child->var,"StringArray")==0){
                    aux_root->child->var = "String[]";
                }

                Sym * aux;

                aux = createSym(aux_root->child->brother->value, aux_root->child->var,"", 0, 0, 0); //FIXME: Verificar se correto
                aux_first->in = aux;
                aux_first = aux;
                
            //else
                //FIXME: é alfa numerico (detetar este erro)
        }

        printf(":::::::%s\n", param);
        if(strlen(param) == 0){
            param = myStrCat(param, aux_root->child->var);
        }else{
            param = myStrCat(param, ",");
            param = myStrCat(param, aux_root->child->var);
        }
        printf("4\n");
        aux_root = aux_root->brother;
    }
    printf("%s-----> %s\n", first->name, param);
    first->param = param;
}

void MethodDecl(Sym * last, Sym * first, struct node * root) {

    //return type and func name
    //Sym * newMethod = createSym(root->child->child->brother->value, root->child->child->var, "", 0, 0, 0);
    
    char * func_name = root->child->child->brother->value;

    if (CheckIfAlreadyDefined(first, func_name, 0) != NULL) {
        printf("ERROR ALREADY DEFINED\n");
    } else {
        printf("MethodDecl\n");
        Sym * newMethod = createSym(func_name, root->child->child->var, "", 0, 0, 0);

        last->next = newMethod;

        //(MethodHeader, ...)
        Header(root->child, newMethod);


    }

}

void printTable(Sym * elem) {
    Sym* copy = elem;

    // Tabela Global
    printf("===== Class %s Symbol Table =====\n", elem->name);
    elem = elem->next;
    while (elem != NULL) {
        if (elem->variable== 1)
            printf("%s\t%s\n", elem->name, elem->type);
        else if (elem->variable == 0)
            printf("%s\t(%s)\t%s\n", elem->name, elem->param, elem->type);
        elem = elem->next;
    }
    
    // Tabelas de funcoes
    
    while (copy != NULL) {
        if (copy->in != NULL) {
            if (strcmp(copy->param, "") == 0)
                printf("\n===== Function %s() Symbol Table =====\n", copy->name);
            else
                printf("\n===== Function %s(%s) Symbol Table =====\n", copy->name, copy->param);
            
            int aux = 0;
            Sym * func = copy->in;

            while (func != NULL) {
                if (aux == 0) {
                    printf("%s\t\t%s\n", func->name, func->type);
                    aux = 1;
                } else {
                    if (func->variable == 0) {
                        printf("%s\t\t%s param\n", func->name, func->type);
                    } else {
                        printf("%s\t\t%s\n", func->name, func->type);
                    }
                }
                func = func->in;
            }

            /*while (func != NULL) {
                if (func->variable == 1 || func->variable == 2) {
                    if (strcmp(func->param, "") == 0)
                        printf("%s\t\t%s\n", func->name, func->type);
                    else
                        printf("%s\t\t%s\t%s\n", func->name, func->type, func->param);
                }
                else if (func->variable == 0)
                    printf("%s\t(%s)\t%s\t%s\n", func->name, func->param, func->type, func->param);
                func = func->in;
            }*/
        }
        copy = copy->next;
    }
    printf("\n");
}

Sym * CheckIfAlreadyDefined(Sym * simTab, char * name, int aux) {
    printf("-----%s-----\n", name);
    while(simTab) {
        if (strcmp(simTab->name, name) == 0) {
            printf("igual\n");     
            return simTab;
        } else {
            if (aux == 0) {
                simTab = simTab->next;
            } else {
                simTab = simTab->in;
            }
        }
    }
    //printf("endcheck\n");
    return NULL;
}

 
 
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
    if (strcmp(root->var, "Program") == 0) {
        if (root->child) {
            /*last->name = root->child->value;
            table = last;
            last->next = createSym("", "", "", 0, 0, 0);*/
            createTable(last, root->child);
        }
    } else if (strcmp(root->var, "FieldDecl") == 0) {
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
                if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }
                aux2 = createSym(root->child->brother->value, root->child->var, "", 0, 0, 1);
                insertSym(last, aux2);
            } else {
                printf("FD ERROR ALREADY DEFINED %s\n", root->child->brother->value);
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
                if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }
                aux_func = createSym(root->child->brother->value, root->child->var, "", 0, 0, 1);
                aux->in = aux_func;
                aux = aux_func;
            } else {
                printf("VD ERROR ALREADY DEFINED %s : %d %d\n", root->child->brother->value, root->child->brother->line, root->child->brother->col);
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
    
    while(aux_root != NULL && aux_root->child != NULL){

        if(CheckIfAlreadyDefined(first->in, aux_root->child->brother->value,1)!= NULL){
            
            printf("HD ERROR ALREADY DEFINED %s : %d %d\n", aux_root->child->brother->value, aux_root->child->brother->line, aux_root->child->brother->col); //FIXME: mensagem de erro de simbolo já definido
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

        if(strlen(param) == 0){
            param = myStrCat(param, aux_root->child->var);
        }else{
            param = myStrCat(param, ",");
            param = myStrCat(param, aux_root->child->var);
        }
        aux_root = aux_root->brother;
    }
    first->param = param;
}

void MethodDecl(Sym * last, Sym * first, struct node * root) {

    //return type and func name
    //Sym * newMethod = createSym(root->child->child->brother->value, root->child->child->var, "", 0, 0, 0);
    
    char * func_name = root->child->child->brother->value;

    if (CheckIfAlreadyDefined(first, func_name, 0) != NULL) {
        printf("MD ERROR ALREADY DEFINED %s\n", func_name);
    } else {
        Sym * newMethod = createSym(func_name, root->child->child->var, "", 0, 0, 0);

        last->next = newMethod;

        //(MethodHeader, ...)

        //printf("Header\n");
        Header(root->child, newMethod);


        //printf("VarDecl\n");
        Vardecl(root->child->brother->child, last->next);

    }

}

void printTable(Sym * elem) {
    Sym* copy = elem;

    // Tabela Global
    printf("===== Class %s Symbol Table =====\n", elem->name);
    elem = elem->next;
    while (elem != NULL) {
        char * temp_type = tolower_word(elem->type);
        if (elem->variable== 1){
            printf("%s\t%s\n", elem->name, temp_type);
        } else if (elem->variable == 0){
            printf("%s\t(%s)\t%s\n", elem->name, tolower_word(elem->param), temp_type);
        }
        elem = elem->next;
    }
    
    // Tabelas de funcoes
    
    while (copy != NULL) {
        if (copy->in != NULL) {
            if (strcmp(copy->param, "") == 0)
                printf("\n===== Function %s() Symbol Table =====\n", copy->name);
            else
                printf("\n===== Function %s(%s) Symbol Table =====\n", copy->name, tolower_word(copy->param));
            
            int aux = 0;
            Sym * func = copy->in;

            while (func != NULL) {
                char * temp_type = tolower_word(func->type);
                if (aux == 0) {
                    printf("%s\t\t%s\n", func->name, temp_type);
                    aux = 1;
                } else {
                    if (func->variable == 0) {
                        printf("%s\t\t%s param\n", func->name, temp_type);
                    } else {
                        printf("%s\t\t%s\n", func->name, temp_type);
                    }
                }
                func = func->in;
            }
        }
        copy = copy->next;
    }
    printf("\n");
}

Sym * CheckIfAlreadyDefined(Sym * simTab, char * name, int aux) {
    while(simTab) {
        if (strcmp(simTab->name, name) == 0) {
            return simTab;
        } else {
            if (aux == 0) {
                simTab = simTab->next;
            } else {
                simTab = simTab->in;
            }
        }
    }
    return NULL;
}

char * tolower_word(char * param){
    char * temp = (char *) malloc(sizeof(char) * strlen(param));
    for(int i= 0; i< strlen(param); i++){
        if(param[i] >= 65 && param[i]<=90){
            temp[i] = param[i] + 32;
        }
        else {
            temp[i] = param[i];
        }
    }
    return temp;
}

int isTwoMemberOperation(char* type){
    if(strcmp(type, "Add") == 0)
        return true;
    else if(strcmp(type, "Sub") == 0)
        return true;
    else if(strcmp(type, "Mul") == 0)
        return true;
    else if(strcmp(type, "Div") == 0)
        return true;
    else if(strcmp(type, "Mod") == 0)
        return true;
    else if(strcmp(type, "Assign")==0)
        return true;
    else if(strcmp(type, "ParseArgs")==0)
        return true;
    else 
        return false;
}

int isOneMemberOperationLogical(char* type){
    if(strcmp(type, "Not") == 0)
        return true;
    if(strcmp(type, "If") == 0)
        return true;
    else if(strcmp(type, "While") == 0)
        return true;
    else
        return false;
}

int isOneMemberOperationNonLogical(char* type){
    if(strcmp(type, "Minus") == 0)
        return true;
    else if(strcmp(type, "Plus") == 0)
        return true;
    else if(strcmp(type, "Print") == 0)
        return true;
    else if(strcmp(type, "Return") == 0)
        return true;
    else 
        return false;
}

int isLogicalOperator(char* type){
    if(strcmp(type, "Or") == 0)
        return true;
    else if(strcmp(type, "Eq") == 0)
        return true;
    else if(strcmp(type, "Ne") == 0)
        return true;
    else if(strcmp(type, "Lt") == 0)
        return true;
    else if(strcmp(type, "Gt") == 0)
        return true;
    else if(strcmp(type, "Le") == 0)
        return true;
    else if(strcmp(type, "Ge") == 0)
        return true;
    else if(strcmp(type, "And") == 0)
        return true;
    else 
        return false;
}

int isStatement(char* type){
    if(strcmp(type, "If") == 0)
        return true;
    else
        return false;
}


void checkTypes(struct node * root, Sym * first, char * name) {
    
    if (strcmp("MethodHeader", root->var) == 0){ 
        //printf("MethodHeader: %s\n", root->child->brother->value);
        name = root->child->brother->value;
    }
    if (root->child != NULL)
        checkTypes(root->child, first, name);
    if (root->brother != NULL)
        checkTypes(root->brother, first, name);
         
    if(isTwoMemberOperation(root->var)){
        printf("1%s\n", root->var); 
    }
    else if(isLogicalOperator(root->var)){
        printf("2%s\n", root->var);         // Eq Lt Gt etc
    }

    //else if(isNewValue(root));                                            // se estiver só Intlit Reallit
        
    else if(isOneMemberOperationNonLogical(root->var)){
        printf("3%s:%s\n", root->child->var, root->child->value);
        //printf("NAME2: %s\n", methodName);
        //printf("NAME3: %s\n", name);
        checkOneMemberOperationNL(root, first, name);
    }

    else if(isOneMemberOperationLogical(root->var)){
        printf("4%s\n", root->var);
    }
    else if(strcmp(root->var, "Call") == 0){
        printf("5%s\n", root->var);
    }
    
}

void checkOneMemberOperationNL(struct node * root, Sym * first, char * name){
    char * type;
    printf("NAME %s\n", root->child->value);
    if(root->child == NULL){
        type = "NULL";
    } else if ((root->child->var[0] == 'I')){
        //printf("INT: %s\n", type);
        type = searchType(root, first, name, type);
        printf("type: %s\n", type);
        root->child->anotation = type;
        sprintf(root->child->var, "%s - %s", root->child->var, tolower_word(type));      
    }

}

char * searchType(struct node * root, Sym * first, char * name, char * type) {
    //printf("searchType----%s\n", name);

    while (first != NULL) {
        //printf("first->name: %s---%s\n", first->name, name);
        if (strcmp(name, first->name) == 0){
            Sym * aux = first->in;
            while (aux != NULL) {
                printf("first->name: %s\n", aux->name);
                //printf("aux->name: %s---%s\n", aux->name, root->child->value);
                if (strcmp(root->child->value, aux->name) == 0) {
                    //printf("11111type: %s\n", aux->type);
                    type = aux->type;
                    return type;
                }
                aux = aux->in;
                //printf("22222type: %s\n", type);
            }
        }



        if (first != NULL)
            first = first->next;                                
    }
}



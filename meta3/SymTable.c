 #include "SymTable.h"

Sym * table;
int test = 0;

Sym * createSym(char * name, char * type, char * param, int line, int col, int variable) {
    Sym * newSym = (Sym *) malloc(sizeof(Sym));

    newSym->name = name;
    newSym->type = type;
    newSym->param = param;

    newSym->line = line;
    newSym->col = col;

    newSym->variable = variable;
    newSym->next = NULL;
    newSym->in = NULL;

    return newSym;
}

char * changeType(char * aux){
    if (strcmp(aux, "Bool")==0)
        return "boolean";
    else if (strcmp(aux, "StringArray") == 0)
        return "String[]";
    else 
        return aux;
}

void createTable (Sym * last, struct node * root) {
    if (test == 0) {
        table = last;
        test = 1;
    }
    int null = 0;
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
        null = MethodDecl(last, table, root);
    }

    while (null == 0 && last->next != NULL) {
        last = last->next;
    }

    if (root->brother) {
        createTable(last, root->brother);
    }
}


void FieldDecl (struct node * root, Sym * last, Sym * first, int aux) {
    Sym * aux2;
    //printf("-----%s------\n", last->name);
    Sym * aux3;
    if (root) {
        if (strcmp(root->var, "FieldDecl") == 0) {
            if(strcmp(root->child->brother->value,"_")==0){
                //printf("error underscore\n");
            }
            else if ((aux3 = CheckIfAlreadyDefined(first, root->child->brother->value, 0)) == NULL || (aux3 != NULL && aux3->variable == 0)) {
                //printf("Line %d, col %d: Variable %s already defined\n", root->child->brother->line, root->child->brother->col, root->child->brother->value);
                /*if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }*/
                
                aux2 = createSym(root->child->brother->value, changeType(root->child->var), "", 0, 0, 1);
                last->next = aux2;
            } else {
                //ERROR : printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, root->child->brother->value);
            }
        }    
    }
}

void Vardecl (struct node * root, Sym * func) {

    Sym * aux = func;

    while (aux->in ) {
        aux = aux->in;
    }

    Sym * aux_func;
    if (root) {
        if (strcmp(root->var, "VarDecl") == 0) {
            if(strcmp(root->child->brother->value,"_")==0){
                //ERROR : printf("Line %d, col %d: Symbol _ is reserved\n", root->child->brother->line, root->child->brother->col);            
            }
            //printf("VARDECL %s\n", root->child->brother->value);
            else if (CheckIfAlreadyDefined(func, root->child->brother->value, 1) == NULL) {
                //printf("aqui\n");
                /*if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }*/
                aux_func = createSym(root->child->brother->value, changeType(root->child->var), "", 0, 0, 1);
                //printf("---%s\n", aux_func->type);
                aux->in = aux_func;
                aux = aux_func;
            } else {
                //ERROR : printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, root->child->brother->value);            
            }
        }
        
        if (root->brother)
            Vardecl(root->brother, func);
    }
}

char* StringCat(char* aux, char* aux2){
    char * temp;
    char * temp2;
    temp = (char*)malloc((strlen(aux) + strlen(aux2)) * sizeof(char));
    temp2 = (char*)malloc(strlen(aux2) * sizeof(char));
    temp = strdup(aux);
    temp2 = strdup(aux2);
    strcat(temp, temp2);
}


void Header(struct node * root, Sym * first){
    /*if(strcmp(first->type,"Bool")==0){
        first->type = "boolean";
    }

    if(strcmp(first->type,"StringArray")==0){
        first->type = "String[]";
    }*/

    first->in = createSym("return", changeType(first->type), "", 0, 0, 0); 
    //printf("---%s\n", first->in->type);
    char * param = "";
    node * aux_root = root->child->brother->brother->child;
    Sym * aux_first = first->in;
    int aux_param = 0;
    
    while(aux_root != NULL && aux_root->child != NULL){
        if(strcmp(aux_root->child->brother->value,"_")==0){
            //printf("error underscore\n");
            aux_param = 1;
        }
        else if (CheckIfAlreadyDefined(first->in, aux_root->child->brother->value,1)!= NULL){
            aux_param = 1;
            //ERROR : printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, aux_root->child->brother->value);            
        }
            
        //printf("----%s : %d\n", aux_root->child->brother->value, aux_param);
        /*if(strcmp(aux_root->child->var,"Bool")==0){
            aux_root->child->var = "boolean";
        }
        if(strcmp(aux_root->child->var,"StringArray")==0){
            aux_root->child->var = "String[]";
        }*/

        if (aux_param == 0) {
            Sym * aux;

            aux = createSym(aux_root->child->brother->value, changeType(aux_root->child->var),"", 0, 0, 0); //FIXME: Verificar se correto
            //printf("----%s\n", aux->type);
            aux_first->in = aux;
            aux_first = aux;
        }
        
        if(strlen(param) == 0){
            param = StringCat(param, changeType(aux_root->child->var));
        }else{
            param = StringCat(param, ",");
            param = StringCat(param, changeType(aux_root->child->var));
        }
        aux_root = aux_root->brother;
        aux_param = 0;
    }
    first->param = param;
    //printf("PARAM: %s\n", param);
}

int MethodDecl(Sym * last, Sym * first, struct node * root) {

    //return type and func name
    //Sym * newMethod = createSym(root->child->child->brother->value, root->child->child->var, "", 0, 0, 0);
    
    char * func_name = root->child->child->brother->value;
    Sym * aux = CheckIfAlreadyDefined(first, func_name, 0);
    int flag = 0;
    if (aux != NULL) {
        //printf("MD ERROR ALREADY DEFINED %s : %d %d\n", func_name, root->child->child->brother->line, root->child->child->brother->col);
        //printf("----Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, func_name);            
        flag = 1;
    }
    
    Sym * newMethod = createSym(func_name, changeType(root->child->child->var), "", 0, 0, 0);
    //printf("++++%s\n", newMethod->type);
    last->next = newMethod;

    //(MethodHeader, ...)

    //printf("Header\n");
    Header(root->child, newMethod);
    
    if (flag == 1 && strcmp(aux->param, newMethod->param) == 0) {
        //printf("AUX_PARAM: %s\n", aux->param);
        //printf("newmehod: %s\n", newMethod->param);
        //printf("Deus %d\n", flag);
        //ERROR : printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, func_name);
        newMethod = NULL;
        return 1;
    }
    //printf("here %d\n", flag);
    //printf("VarDecl\n");
    Vardecl(root->child->brother->child, last->next);

    return 0;
}

void printTable(Sym * first) {

    Sym* aux = first;

    printf("===== Class %s Symbol Table =====\n", first->name);
    first = first->next;
    while (first) {
        char * temptype ;
        if (strcmp(first->type, "String[]") != 0)
            temptype = tolower_word(first->type);
        else 
            temptype = first->type; //printf("...%s", temptype);

        if (first->variable== 1){
            printf("%s\t\t%s\n", first->name, temptype);
        } else if (first->variable == 0){
        if (strcmp(first->param, "String[]") == 0){
            printf("%s\t(%s)\t%s\n", first->name, first->param, temptype);
        }else{
            printf("%s\t(%s)\t%s\n", first->name, tolower_word(first->param), temptype);
        }
            
        }
        first = first->next;
    }
    //printf("aqui2\n");
    
    
    while (aux != NULL) {
        //printf("aqui\n");
        if (aux->in != NULL) {
            if (strcmp(aux->param, "") != 0){
                if (strcmp(aux->param, "String[]") != 0)
                    printf("\n===== Method %s(%s) Symbol Table =====\n", aux->name, tolower_word(aux->param));
                else 
                    printf("\n===== Method %s(%s) Symbol Table =====\n", aux->name, aux->param);
            }else
                printf("\n===== Method %s() Symbol Table =====\n", aux->name);
            
            
            
            Sym * method = aux->in;
            int contador = 0;

            while (method) {
                char * temp_type ;
                if (strcmp(method->type, "String[]") != 0)
                    temp_type = tolower_word(method->type);
                else 
                    temp_type = method->type;
                if (contador == 0) {
                    printf("%s\t\t%s\n", method->name, temp_type);
                    contador = 1;
                } else {
                    if (method->variable == 0) {
                        printf("%s\t\t%s\tparam\n", method->name, temp_type);
                    } else {
                        printf("%s\t\t%s\n", method->name, temp_type);
                    }
                }
                method = method->in;
            }
        }
        aux = aux->next;
    }
    printf("\n");
}

Sym * CheckIfAlreadyDefined(Sym * simTab, char * name, int aux) {
    int flag = 0;

    while(simTab) {
        //printf("simTab->name: %s | %s\n", simTab->name, name);
        if (strcmp(simTab->name, name) == 0 && flag == 1) {
            return simTab;
        } else {
            if (aux == 0) {
                simTab = simTab->next;
                flag = 1;
            } else {
                simTab = simTab->in;
                flag = 1;
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

int TwoMemberOp(char* type){
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

int NotLogical(char* type){
    if(strcmp(type, "Plus") == 0)
        return true;
    else if(strcmp(type, "Minus") == 0)
        return true;
    else if(strcmp(type, "Print") == 0)
        return true;
    else if(strcmp(type, "Return") == 0)
        return true;
    else 
        return false;
}

int Logical(char* type){
    if(strcmp(type, "And") == 0)
        return true;
    else if(strcmp(type, "Or") == 0)
        return true;
    else if(strcmp(type, "Lt") == 0)
        return true;
    else if(strcmp(type, "Gt") == 0)
        return true;
    else if(strcmp(type, "Le") == 0)
        return true;
    else if(strcmp(type, "Ge") == 0)
        return true;
    else if(strcmp(type, "Eq") == 0)
        return true;
    else if(strcmp(type, "Ne") == 0)
        return true;
    
    else 
        return false;
}



void checkTypes(struct node * root, Sym * first, char * name) {
    //printf("CHECK TYPES %s\n", root->var);
    if (strcmp("MethodHeader", root->var) == 0){ 
        //printf("MethodHeader: %s\n", root->child->brother->value);
        name = root->child->brother->value;
    }
    if (root->child != NULL)
        checkTypes(root->child, first, name);
    if (root->brother != NULL)
        checkTypes(root->brother, first, name);
         
    if(TwoMemberOp(root->var)){
        //printf("1%s\n", root->var); 
        TwoMember(root, first, name, false);
        
    } else if(Logical(root->var)){
        TwoMember(root, first, name, true);
        //printf("2%s\n", root->var);      
        //printf(" ");
    } else if(isVAR(root));                                       
        
    else if(NotLogical(root->var)){
        //printf("3%s:%s\n", root->child->var, root->child->value);
        //printf("NAME2: %s\n", methodName);
        //printf("NAME3: %s\n", name);
        OneMemberNL(root, first, name);
    }
    else if(strcmp(root->var, "Call") == 0){
        //printf("CALL:  %s\n", root->var);
        Calls(root, first, name);
        //printf(" ");
    }
    
}

void Calls(struct node * root, Sym * first, char * name){
    char *type = "undef";
    char * param_aux = "\0";
    Sym * first_aux = first;
    int at_least_one = 0;
    char * param = "\0";
    
    while(first != NULL){
        if(strcmp(first->name, root->child->value) == 0 && first->variable == 0){

            char* aux_p = "(";
            at_least_one =1;
            
            type = first->type;
         
            param = tolower_word(first->param);
 
            aux_p = StringCat(aux_p, param);
            aux_p = StringCat(aux_p, ")");

            root->child->anotation = tolower_word(aux_p);
           
            break;
        }
        first = first->next;
    }
    
    struct node * aux = root->child->brother;
    //printf("AUX: %s\n", aux->var);
    char * tvar;
    while(aux != NULL){
        
        if((aux->var[0] == 'I') && (aux->var[1] == 'd')){
            tvar = searchType(aux, first_aux, name, tvar, 1);
            
            aux->anotation = tvar;
           
        }
        
       
        //printf("-------------->aux->var: %s\n", aux->var);
        if(strcmp(aux->var,"Call")== 0 && aux->anotation == NULL){
          
            //printf("CAll node\n");
            if(strlen(param_aux) == 0){
                param_aux = StringCat(param_aux, "NULL");
                //printf("---> %s  param:aux: %s\n", aux->var ,param_aux);
            }
            else{
                param_aux = StringCat(param_aux, ",");
                param_aux = StringCat(param_aux, "NULL");
            }
        }else{
            //printf("entrei no lese\n");
            //printf("aux->var: %s\n", aux->var);
            //printf("PARAM_AUX: %s\n",param_aux);
            if(strlen(param_aux) == 0){
                //printf("teste:  %s\n", aux->var);
                //printf("anotacao:  %s\n", aux->anotation);
                //printf("aqui1\n");
                //printf("PARAM_AUX: %s\n",param_aux);
                
                param_aux = StringCat(param_aux, aux->anotation);
                //printf("fimm\n");
            }
            else{
                //printf("aqui2\n");
                param_aux = StringCat(param_aux, ",");
                param_aux = StringCat(param_aux, aux->anotation);
                
            }
        }
        aux = aux->brother;
        
    }
    //printf("_____________________\n");
    
    //printf("at_:  %d\n", at_least_one);
    
    if(strcmp(param,param_aux) != 0){
        //printf("ATENÇAO ATENÇAO MEU PAU ESTA DURAO %s | %s\n", param, param_aux);
        type = "undef";
        root->child->anotation = "undef";
    }

    
    if(at_least_one == 0){

        root->child->anotation = "undef";
        type = "undef";
    }
    
    if(strcmp(type, "NULL")!= 0){
        root->anotation = type;
    }
    //free
}

void TwoMember(struct node * root, Sym * first, char * name, int flag){
    //printf("2MEMBER: %s\n", root->var);
    char * type, * type2;
    if ((root->child->var[0] == 'I')){
        //printf("INT: %s\n", type);
        type = searchType(root, first, name, type, 0);
        //printf("type: %s\n", type);
        root->child->anotation = tolower_word(type);
        //sprintf(root->child->var, "%s - %s", root->child->var, tolower_word(type)); 
    } else {
        type = root->child->anotation;
    }

    if ((root->child->brother->var[0] == 'I')){
        //printf("INT: %s\n", type);
        type2 = searchType(root, first, name, type, 0);
        //printf("type: %s\n", type);
        root->child->brother->anotation = tolower_word(type2);
        //sprintf(root->child->var, "%s - %s", root->child->var, tolower_word(type)); 
    } else {
        type2 = root->child->brother->anotation;
    }

    if (flag == false) {
        if (strcmp(root->var, "Assign") == 0) {
            root->anotation = tolower_word(type);
        } else if (strcmp(root->var, "ParseArgs") == 0) {
            if (strcmp(type, "int") == 0){
                root->anotation = tolower_word(type);
            } else {
                //ERROR
            }
        } else {
            if (strcmp(type, "bool") != 0) {
                root->anotation = tolower_word(type);
            } else {
                //ERROR
                root->anotation = "undef";
            }
        }
    } else {
        if (strcmp(root->var, "And") == 0 || strcmp(root->var, "Or") == 0) {
            if (strcmp(type, "bool") != 0) {
                //ERROR
            }
        } else if (strcmp(root->var, "Eq") == 0 || strcmp(root->var, "Ne") == 0 || strcmp(root->var, "Lt") == 0 || strcmp(root->var, "Gt") == 0 || strcmp(root->var, "Le") == 0 || strcmp(root->var, "Ge") == 0) {
            if (strcmp(type, "bool") == 0) {
                //ERROR
            }
        }
        root->anotation = "bool";
    }

    

    


}

void OneMemberNL(struct node * root, Sym * first, char * name){
    char * type;
    //printf("NAME %s\n", root->child->value);
    
    if(root->child == NULL){
        type = "NULL";
    } else if ((root->child->var[0] == 'I')){
        //printf("INT: %s\n", type);
        type = searchType(root, first, name, type, 0);
        //printf("type: %s\n", type);
        root->child->anotation = tolower_word(type);
        //sprintf(root->child->var, "%s - %s", root->child->var, tolower_word(type));      
    }else {
        type = "NULL2";
        //printf("type: %s\n", type);
        //root->child->anotation = type;
        //sprintf(root->child->var, "%s - %s", root->child->var, type);
        //printf("NAME2 %s\n", root->child->var);
    }
    

}

char * searchType(struct node * root, Sym * first, char * name, char * type, int val) {
    //printf("searchType----%s:::::%s\n", name, root->var);
    while (first != NULL) {
        //printf("first->name: %s---%s\n", first->name, name);
        /*if(strcmp(first->name, root->value)== 0){
            type = first->type;
        }
         else 
         */
         if (strcmp(name, first->name) == 0){
            Sym * aux = first->in;
            while (aux != NULL) {
                //printf("first->name: %s\n", aux->name);
                //printf("cvbnm,.cvbnm,.\n");
                //printf("aux->name: %s---%s\n", aux->name, root->value);
                if (val == 0 && strcmp(root->child->value, aux->name) == 0) {
                    //printf("11111type: %s\n", aux->type);
                    type = aux->type;
                    return type;

                } else if (val == 1 && strcmp(root->value, aux->name) == 0) {
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

int isVAR(struct node * root) {
    char * type;
    //if (strcmp(root->var, "BoolLit") == 0) printf("LEN: %d\n", strlen(root->var));
    if (root->value != NULL) {
            //printf("isVAR: %s\n", root->var);
        if (root->var[0] == 'D' && root->var[1] == 'e') {
            type = "int";
            //printf("type: %s\n", type);
            root->anotation = type;
            //sprintf(root->var, "%s - %s", root->var, type);
            return true;
        } else if (root->var[0] == 'B' && root->var[1] == 'o' ) {   //FIXME: BoolLit e Bool, uma historia de amor...
            type = "boolean";
            //printf("type: %s\n", type);
            root->anotation = type;
            //sprintf(root->var, "%s - %s", root->var, type);
            return true;
        } else if (root->var[0] == 'R' && root->var[1] == 'e' && root->var[2] == 'a') {
            type = "double";
            //printf("type: %s\n", type);
            root->anotation = type;
            //sprintf(root->var, "%s - %s", root->var, type);
            return true;
        }
    }    
    return false;
}



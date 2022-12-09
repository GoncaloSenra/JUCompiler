 #include "SymTable.h"

Sym * table;
int test = 0;
int funcline = 0;

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

    newSym->auxparam = 0;

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
            else if ((aux3 = CheckIfAlreadyDefined(first, root->child->brother->value, 1, 0)) == NULL || (aux3 != NULL && aux3->variable == 0)) {
                //printf("Line %d, col %d: Variable %s already defined\n", root->child->brother->line, root->child->brother->col, root->child->brother->value);
                /*if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }*/
                
                aux2 = createSym(root->child->brother->value, changeType(root->child->var), "", root->child->brother->line, root->child->brother->col, 1);
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
            else if (CheckIfAlreadyDefined(func, root->child->brother->value, 1, 1) == NULL) {
                //printf("aqui\n");
                /*if(strcmp(root->child->var,"Bool")==0){
                    root->child->var = "boolean";
                }
                if(strcmp(root->child->var,"StringArray")==0){
                    root->child->var = "String[]";
                }*/
                aux_func = createSym(root->child->brother->value, changeType(root->child->var), "", root->child->brother->line, root->child->brother->col, 1);
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
    
    char * temp;
    temp = (char*) malloc(sizeof(char) * 1024);
    //strcpy(temp, "");
    first->in = createSym("return", changeType(first->type), "", 0, 0, 0); 
    //printf("---%s\n", first->in->type);
    char * param = NULL;
    node * aux_root = root->child->brother->brother->child;
    Sym * aux_first = first->in;
    Sym * aux2;
    int aux_param = 0;
    
    while(aux_root != NULL && aux_root->child != NULL){
        if(strcmp(aux_root->child->brother->value,"_")==0){
            //printf("error underscore\n");
            aux_param = 1;
        }
        else if ((aux2 = CheckIfAlreadyDefined(first->in, aux_root->child->brother->value, 1, 1)) != NULL){
            //printf("----->%s\n",aux2->param);
            aux_param = 1;
            //ERROR : printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, aux_root->child->brother->value);            
        }
            

        if (aux_param == 0) {
            Sym * aux;

            aux = createSym(aux_root->child->brother->value, changeType(aux_root->child->var),"", aux_root->child->brother->line, aux_root->child->brother->col, 1); //FIXME: Verificar se correto
            aux->auxparam = 1;
            aux_first->in = aux;
            aux_first = aux;
        }
        //printf("AAFAFAFSA\n");
        if(strcmp(temp, "") == 0){
            
            temp = StringCat(temp, changeType(aux_root->child->var));

        }else{

            temp = StringCat(temp, ",");
            temp = StringCat(temp, changeType(aux_root->child->var));

        }
        aux_root = aux_root->brother;
        aux_param = 0;
    }
    //printf("param: %s\n", temp);
    
    //printf("temp: %s\n", temp);
    //strcpy(temp2, temp);

    //printf("---------> %s\n", temp);
    //if (strcmp(tolower_word(temp2), aux2.) )
    first->param = strdup(temp);
    //printf("PARAM: %s\n", first->param);
}

int MethodDecl(Sym * last, Sym * first, struct node * root) {

    //return type and func name
    //Sym * newMethod = createSym(root->child->child->brother->value, root->child->child->var, "", 0, 0, 0);
    
    char * func_name = root->child->child->brother->value;
    
    Sym * newMethod = createSym(func_name, changeType(root->child->child->var), "", root->child->child->brother->line, root->child->child->brother->col, 0);
    //printf("++++%s\n", newMethod->type);
    last->next = newMethod;

    //(MethodHeader, ...)

    //printf("Header\n");
    Header(root->child, newMethod);
    
    /*
    Sym * aux= CheckIfAlreadyDefined(last, func_name, 1, 1);
    if(aux ==NULL){
        printf("Sou nulo!!\n");
    }


    if (aux != NULL){
    printf("AUX_PARAM: %s\n", aux->in->param);
    printf("newmehod: %s\n-------------------------------\n", newMethod->param);

    }*/

    while (first) {
        if (first->variable == 0) {
            if (strcmp (first->name, func_name) == 0 && strcmp(newMethod->param, first->param) == 0 && first->next != NULL){
                root->child->child->brother->valid = 0;
                //printf("ENTREI AHAHAHAHHHAHAHA %s -- %s | %s -- %s |\n", first->name, func_name, newMethod->param, first->param);
                return 1;
            }
        }
        first = first->next;
    }

    /*if ((aux ) != NULL && strcmp(aux->param, newMethod->param) == 0) {
        printf("AUX_PARAM1: %s\n", aux->param);
        printf("newmehod1: %s\n", newMethod->param);
        //printf("Deus %d\n", flag);
        //ERROR : printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, func_name);
        //newMethod = NULL;
        return 1;
    }*/
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
            //printf("param: %s\n", first->param);
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
                    if (method->auxparam == 1) {
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

Sym * CheckIfAlreadyDefined(Sym * simTab, char * name, int aux, int flag) {

    while(simTab) {
        //printf("simTab->name: %s | %s - aux: %d - var: %d - flag: %d\n", simTab->name, name, aux, simTab->variable, flag);
        if (aux == 1) {
            if (simTab->variable == 1){
                if (strcmp(simTab->name, name) == 0) {
                    //printf("AQUI\n");
                    return simTab;
                }
            }
        } else {
            if (simTab->variable == 0) {
                if (strcmp(name, simTab->name) == 0) {
                    //printf("ALI\n");
                    return simTab;
                }
            }
        }

        if (flag == 0)
            simTab = simTab->next;
        else
            simTab = simTab->in;
    }
    return NULL;
}

char * tolower_word(char * param){
    char * temp = (char *) malloc(sizeof(char) * 1024);
    if (strcmp(param, "String[]") == 0)
        return "String[]";

    for(int i= 0; i< strlen(param); i++){
        if(param[i] >= 65 && param[i]<=90){
            temp[i] = param[i] + 32;
        }
        else {
            temp[i] = param[i];
        }
    }
    return strdup(temp);
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
    else if(strcmp(type, "Lshift")==0)
        return true;
    else if(strcmp(type, "Rshift")==0)
        return true;
    else 
        return false;
}

int OneLogical(char* type){
    if(strcmp(type, "Not") == 0)
        return true;
    else if(strcmp(type, "While") == 0)
        return true;
    else if(strcmp(type, "If") == 0)
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
    else if(strcmp(type, "Length") == 0)
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
    else if(strcmp(type, "Xor") == 0)
        return true;
    else 
        return false;
}

void checkTypes(struct node * root, Sym * first, char * name) {
    
    //printf("CHECK TYPES %s\n", root->var);
    if (strcmp("MethodHeader", root->var) == 0){ 
        //printf("MethodHeader: %s\n", root->child->brother->value);
        name = root->child->brother->value;
        funcline = root->line;
        if (root->child->brother->valid == 0)
            return;
    }


    if (root->child != NULL)
        checkTypes(root->child, first, name);
    if (root->brother != NULL)
        checkTypes(root->brother, first, name);
         
    if(TwoMemberOp(root->var)){
        //printf("1%s = %s -- %s\n", root->var, root->child->var, root->child->brother->var); 
        TwoMember(root, first, name, false);
        
    } else if(Logical(root->var)){
        //printf("2%s = %s -- %s\n", root->var, root->child->var, root->child->brother->var);  
        TwoMember(root, first, name, true);
             
        //printf(" ");
    } else if(isVAR(root));                                       
        
    else if(NotLogical(root->var)){
        //printf("3%s:%s\n", root->child->var, root->child->value);
        //printf("NAME2: %s\n", methodName);
        //printf("NAME3: %s\n", name);
        //printf("NL============> %s\n", root->var);
        OneMemberNL(root, first, name, 0);
    } else if(OneLogical(root->var)){
        //printf("3%s:%s\n", root->child->var, root->child->value);
        //printf("NAME2: %s\n", methodName);
        //printf("NAME3: %s\n", name);
        //printf("OL============> %s\n", root->var);
        OneMemberNL(root, first, name, 1);
    }
    else if(strcmp(root->var, "Call") == 0){
        //printf("CALL:  %s\n", root->var);
        
        Calls(root, first, name);
        //printf(" ");
    }
    
}

int checkParameters(char * param, char * auxparam){
    char * tok;
    char * tok2;

    char * tok3;
    char * tok4;

    //printf("<===== %s----%s\n", param, auxparam);
    tok = strtok_r(param, ",", &tok3);
    tok2 = strtok_r(auxparam, ",", &tok4);
    //printf("UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU (%s) -----> %s\n", auxparam, param);
    while(tok != NULL && tok2 != NULL) {
        //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        //if (strcmp(param, "int,int,int,double") == 0)
        //printf("--->param2:%s    paramuax2:%s \n", tok, tok2);
        if (!(strcmp(tok, "int") == 0 && strcmp(tok2, "double") == 0) && strcmp(tok, tok2) != 0){
            //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            return false;
        }

        //printf("param2:%s    paramuax2:%s \n", tok, tok2);
        
        tok = strtok_r(NULL, ",", &tok3);
        tok2 = strtok_r(NULL, ",", &tok4);

    }


    //printf("param3:%s    paramuax3:%s \n", tok, tok2);
    if (tok == NULL && tok2 == NULL){
        //printf("ACERTOUUUUUUUUUUUUUU MISERAVELLLLLLLLLLL: %s------%s\n", param , auxparam);
        return true;
        
    }
    return false;
}

void Calls(struct node * root, Sym * first, char * name){
    char *type = "undef";
    char * param_aux = "\0";
    Sym * first_aux = first;
    int at_least_one = 0;
    char * param = "\0";
    int count = 0;

   struct node * aux = root->child->brother;
    //printf("AUX: %s\n", aux->var);
    char * tvar;

    //printf("pila\n");
    while(aux != NULL){
        //printf("pila2\n");
        if((aux->var[0] == 'I') && (aux->var[1] == 'd')){
            //printf("pila3\n");
            tvar = searchType(aux, first_aux, name, aux->value, aux->line, 1);
            //printf("pila3.5\n");
            //printf("%s\n", tvar);
            
            //if (strcasecmp(tvar, "String[]") != 0)      // se for strcmp() dá segfault nao sei porquê
            aux->anotation = tolower_word(tvar);
            //printf("tvar: %s  root: %s\n",aux->anotation, aux->value);
            //printf("pila4\n");
        }
        
        //printf("pila5\n");
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
        //printf("parammm: %s\n",param_aux);
        aux = aux->brother;
        
    }
    
    while(first != NULL){
        //printf("------>%s %s\n", param_aux,first->param);
        if(strcmp(first->name, root->child->value) == 0 && first->variable == 0 ){
            //printf("-->%d\n", count);
            //printf("CONAAAAAAAAAAAAAAAAA---%s---%s\n", param_aux, first->param);
            

           // printf("-->param: %s\n",param_aux);
            if (strcmp(param_aux, tolower_word(first->param)) == 0) {

                char* aux_p = "(";
                at_least_one =1;
                //printf("pilaaaaaaaaaaaaaaaaaa\n");
                type = first->type;
            
                //if (strcasecmp("String[]", first->param) != 0)  // se for strcmp() dá segfault nao sei porquê
                param = tolower_word(first->param);
        
                //printf("---->%s\n", param);
                aux_p = StringCat(aux_p, param);
                aux_p = StringCat(aux_p, ")");

                root->child->anotation = aux_p;
                count = 0;
                //printf("PILA PILA PILA : %s +++++ %s \n", aux_p, tolower_word(first->param));
                break;
                
            } else { 
                char* temp = strdup(param_aux); 
                char* temp2 = strdup(tolower_word(first->param));      
                //strcpy(temp, param_aux);
                //strcpy(temp2, tolower_word(first->param));
                if (checkParameters(temp, temp2) == true) {
                    char* aux_p2 = "(";
                    at_least_one =1;
                    //printf("pilaaaaaaaaaaaaaaaaaa\n");
                    type = first->type;
                
                    //if (strcasecmp("String[]", first->param) != 0)  // se for strcmp() dá segfault nao sei porquê
                    param = tolower_word(first->param);
            
                    //printf("---->%s\n", param);
                    aux_p2 = StringCat(aux_p2, param);
                    aux_p2 = StringCat(aux_p2, ")");

                    if (count == 0)
                        root->child->anotation = aux_p2;
                    else {
                        //ERROR
                        //root->anotation = "undef";
                        root->child->anotation = "undef";
                    }
                    //printf("ATENCAO ATENCAO : %s +++++ %s \n", aux_p2, tolower_word(first->param));
                    count ++;
                }   
            }
        }
        first = first->next;
    }
    
    
    //printf("_____________________\n");
    
    //printf("at_:  %d\n", at_least_one);
    /*
    if(strcmp(param,param_aux) != 0){
        type = "undef";
        root->child->anotation = "undef";
    }*/

    
    if(at_least_one == 0){

        root->child->anotation = "undef";
        type = "undef";
    }

    
    
    if(strcmp(type, "NULL")!= 0){
        if(count > 1 ){  //HERERERERE
            root->anotation = "undef";
        }else{
            root->anotation = tolower_word(type);
        }
        
    }
    //free
}

void TwoMember(struct node * root, Sym * first, char * name, int flag){
    //printf("dfghjklç: name %s\n", name);
    //printf("2MEMBER: %s\n", root->var);
    char * type="", * type2="";
    if ((root->child->var[0] == 'I')){
        //printf("INT: %s\n", type);
        //printf("RIII\n");
        type = searchType(root, first, name, root->child->value, root->child->line, 1);
        //printf("1 %s-----------------------------------> %s\n",root->child->value, type);
        //printf("type: %s\n", type);
        root->child->anotation = tolower_word(type);

        //printf("root %s %s\n", root->child->var, root->child->anotation);
        //sprintf(root->child->var, "%s - %s", root->child->var, tolower_word(type)); 
    } else {
        type = root->child->anotation;
    }

    if ((root->child->brother->var[0] == 'I')){
        //printf("INT: %s\n", type);
        //printf("Fudi-me\n");
        //printf("++++++ %s\n", root->child->brother->value);
        type2 = searchType(root, first, name, root->child->brother->value, root->child->brother->line,1);
        //printf("2 %s-----------------------------------> %s\n",root->child->value,  type2);

        //printf("type: %s\n", type);
        root->child->brother->anotation = tolower_word(type2);
        //printf("root21 %s %s\n", root->child->brother->var, root->child->brother->anotation);
        //sprintf(root->child->var, "%s - %s", root->child->var, tolower_word(type)); 
    } else {
        type2 = root->child->brother->anotation;
    } 

    //printf("types: 1->%s  2->%s var->%s\n", type, type2, root->var);
    if(type != NULL && type2 != NULL && strcmp(tolower_word(type), tolower_word(type2))==0){
        if(strcmp(tolower_word(type), "undef") == 0 && strcmp(tolower_word(type2), "undef") == 0 && strcmp(root->var, "ParseArgs") != 0){
            if(flag == false){
                root->anotation = "undef";
            }else{
                root->anotation = "boolean";
            }
        }else{
            if(flag == true){
                if (strcmp(root->var, "And") == 0 || strcmp(root->var, "Or") == 0) {
                    if (strcmp(tolower_word(type), "boolean") != 0) {
                        //ERROR
                        root->anotation = "boolean";
                    }else {
                        root->anotation = "boolean";
                    }
                } else if (strcmp(root->var, "Eq") == 0 || strcmp(root->var, "Ne") == 0 || strcmp(root->var, "Lt") == 0 || strcmp(root->var, "Gt") == 0 || strcmp(root->var, "Le") == 0 || strcmp(root->var, "Ge") == 0) {
                    if (strcmp(tolower_word(type), "boolean") == 0) {
                        //ERROR ???
                        root->anotation = "boolean";
                    }else {
                        root->anotation = "boolean";
                    }
                } else if (strcmp(root->var, "Xor") == 0) {
                    if (strcmp(tolower_word(type), "int") != 0 && strcmp(tolower_word(type), "boolean") != 0) {
                        root->anotation = "undef";
                        //ERROR
                    } else if (strcmp(tolower_word(type), "int") == 0){
                        root->anotation = "int";
                    }else if (strcmp(tolower_word(type), "boolean") == 0){
                        root->anotation = "boolean";
                    }
                }
                

            }else{
                //printf("BOIOLA!!! %s\n", root->var);
                //printf("OOOOOOOOOOOOOOO %s\n", root->var);
                //printf("antes assign: %s\n", root->var);
                if (strcmp(root->var, "Assign") == 0 ) {
                    //printf("ASSIGN - anotation: %s\n", type);
                    root->anotation = tolower_word(type);
                } else if (strcmp(root->var, "Add") == 0 || strcmp(root->var, "Sub") == 0 || strcmp(root->var, "Div") == 0 || strcmp(root->var, "Mul") == 0 || strcmp(root->var, "Mod") == 0){ 
                    //printf("BOIOLA!!!\n");
                    if (strcmp(tolower_word(type), "int") == 0) {
                        //printf("roooto: %s\n", root->var);
                        root->anotation = "int";
                    } else if (strcmp(tolower_word(type), "double") == 0) {
                        //printf("roooto: %s\n", root->var);
                        root->anotation = "double";    
                    } else {
                        root->anotation = "undef";
                    }
                    
                } else if (strcmp(root->var, "Lshift") == 0 || strcmp(root->var, "Rshift") == 0) {
                    //printf("ASSIGN - anotation: %s\n", type);
                    if (strcmp(tolower_word(type), "int") == 0)
                        root->anotation = tolower_word(type);
                    else {
                        root->anotation = "undef";
                        //ERROR
                    }
                } else if (strcmp(root->var, "ParseArgs") == 0) {
                    //ERROR
                    root->anotation = "int";
                } else {
                    //printf("AQUIIIIIIIIIIIIIII\n");
                    if (strcmp(tolower_word(type), "boolean") != 0) {
                        
                        root->anotation = tolower_word(type);
                    } else {
                        //ERROR
                        root->anotation = "undef";
                    }
                }
            }
        }
    }else{
        if(type == NULL)
            type = "NULL";
        if(type2 == NULL)
            type2 = "NULL";
            //ERROR 
            
        if(flag == true)
            root->anotation = "boolean";
        else{
            if (strcmp(root->var, "Add") == 0 || strcmp(root->var, "Sub") == 0 || strcmp(root->var, "Div") == 0 || strcmp(root->var, "Mul") == 0 || strcmp(root->var, "Mod") == 0){ 
                //printf("BOIOLA!!!\n");
                if ((strcmp(tolower_word(type), "double") == 0 && strcmp(tolower_word(type2), "int") == 0) || (strcmp(tolower_word(type), "int") == 0 && strcmp(tolower_word(type2), "double") == 0)) {
                    //printf("roooto: %s\n", root->var);
                    root->anotation = "double";    
                } else {
                    root->anotation = "undef";
                }
            }else if (strcmp(root->var, "Assign") == 0 && strcmp(type, "undef") != 0) {
                //printf("ASSIGN - anotation: %s\n", type);
                root->anotation = tolower_word(type);
                //printf("%s ---- %s\n", type, type2);
                if(!(strcmp(type, "Double") == 0 && strcmp(type2, "int") == 0))
                    printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n", root->line, root->col, tolower_word(type), tolower_word(type2));
            }else if (strcmp(root->var, "ParseArgs") == 0) {
                    if (strcmp(tolower_word(type), "String[]") == 0 && strcmp(tolower_word(type2), "int") == 0){
                        root->anotation = "int";
                    } else {
                        root->anotation = "int";
                        //ERROR
                    }
                    
            }else {
                root->anotation = "undef";
            }
        }
            
    }

}

void OneMemberNL(struct node * root, Sym * first, char * name, int flag){
    char * type="";
    //printf("NAME %s\n", root->child->value);
    
    if(root->child == NULL){
        type = "NULL";
    } else if ((root->child->var[0] == 'I')){
        //printf("INT: %s\n", type);
        type = searchType(root, first, name, root->child->value, root->child->line,1);
        //printf("type: %s\n", type);
        root->child->anotation = tolower_word(type);
        //sprintf(root->child->var, "%s - %s", root->child->var, tolower_word(type));      
    }else {
        type = root->child->anotation;
        //printf("type: %s\n", type);
        //root->child->anotation = type;
        //sprintf(root->child->var, "%s - %s", root->child->var, type);
        //printf("NAME2 %s\n", root->child->var);
    }
    
    if(type != NULL){
        if (strcmp(root->var, "Length") == 0) {
            if (strcmp(root->child->anotation, "int") != 0){
                root->anotation = "int";
            }else {
                //ERROR
                root->anotation = "int";
            }
        }else if (strcmp(root->var, "Return") == 0){
            return;
        }else if (strcmp(root->var, "While") == 0){
            return;
        }else if (strcmp(root->var, "If") == 0){
            return;
        }
        else if(strcmp(tolower_word(type),"undef") == 0 && strcmp(root->var,"Print") != 0){
            if(flag == false){
                root->anotation = "undef";
            }else{
                root->anotation = "boolean";
            }
        }else{
            if(flag == false){
                if (strcmp(root->var, "Plus") == 0 || strcmp(root->var, "Minus") == 0) {
                    
                    if (strcmp(root->child->anotation, "int") == 0 || strcmp(root->child->anotation, "double") == 0){
                        root->anotation = tolower_word(type);
                    } else {
                        //ERROR
                        root->anotation = "undef"; //PRINT ENTRA AQUI E FODESSE
                    }
                }
            } else{
                if (strcmp(root->var, "Not") == 0) {
                    if (strcmp(root->child->anotation, "boolean") == 0){
                        root->anotation = "boolean";
                    } else {
                        root->anotation = "boolean";
                        //ERRO
                    }
                }
            }
        }
    }

}

char * searchType(struct node * root, Sym * first, char * name, char * id, int line, int val) {
    //printf("----%s:::::%s\n", name, root->var);
    char * type = "";
    //printf("----->%s\n", id);
    while (first != NULL) {
        //printf("first->name: %s---%s\n", first->name, name);
        /*if(strcmp(first->name, root->value)== 0){
            type = first->type;
        }
         else 
         */
        if (strcmp(id, first->name) == 0) {
            type = first->type;
        }
        //printf("OOOOO%s: %d -- %d\n", name, funcline, first->line);
        if (strcmp(name, first->name) == 0 && first->line == funcline){

            Sym * aux = first->in;
            //printf("aux: %s\n", aux->name);
            while (aux != NULL) {
                //printf("first->name: %s\n", aux->name);
                //printf("cvbnm,.cvbnm,.\n");
                //printf("aux->name: %s---%s\n", aux->name, root->child->value);
                //printf("-------> %s : %s\n", id , aux->name);
                if (strcmp(id, aux->name) == 0 && line > aux->line) {
                    type = aux->type;
                    return type;
                }

               // printf("22222type: %s\n", type);
                aux = aux->in;
                if (aux == NULL && strcmp(type, "") == 0){
                    //printf("MUITO UNDEF MANO\n");
                    type = "undef";
                }
                
            }
        }

        if (first != NULL)
            first = first->next;                                
    }
    return type;
}

int isVAR(struct node * root) {
    char * type;
    //if (strcmp(root->var, "BoolLit") == 0) printf("LEN: %d\n", strlen(root->var));
    if (root->value != NULL) {
            //printf("isVAR: %s\n", root->var);
        if (root->var[0] == 'D' && root->var[1] == 'e') {
            type = "int";
            root->anotation = type;
            char * dec_aux = strdup(root->value);
            int len = strlen(dec_aux);
            int is_negative = 0;

            for (int i = 0; i < len; i++){
                if (dec_aux[i] == '_'){
                    for (int j = i; j < strlen(dec_aux); j++){
                        dec_aux[j] = dec_aux[j+1];
                    }
                    len--;
                    i--;
                }
            }
            //convert string to signed long
            long dec = atol(dec_aux);
            if (dec >= 2147483648) {
                //ERROR
                printf("Line %d, col %d: Number %s out of bounds\n", root->line, root->col, root->value);
            }
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
        } else if (root->var[0] == 'S' && root->var[1] == 't' && root->var[2] == 'r') {
            type = "String";
            //printf("type: %s\n", type);
            root->anotation = type;
            //sprintf(root->var, "%s - %s", root->var, type);
            return true;
        }
    }    
    return false;
}



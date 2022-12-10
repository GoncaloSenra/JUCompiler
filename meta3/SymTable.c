 #include "SymTable.h"

Sym * table;
int test = 0;
int funcline = 0;
char * auxreturn = "";

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
    Sym * aux3;
    if (root) {
        if (strcmp(root->var, "FieldDecl") == 0) {
            if(strcmp(root->child->brother->value,"_")==0){
                printf("Line %d, col %d: Symbol _ is reserved\n", root->child->brother->line, root->child->brother->col);            
            }
            else if ((aux3 = CheckIfAlreadyDefined(first, root->child->brother->value, 1, 0)) == NULL || (aux3 != NULL && aux3->variable == 0)) {
                aux2 = createSym(root->child->brother->value, changeType(root->child->var), "", root->child->brother->line, root->child->brother->col, 1);
                last->next = aux2;
            } else {
                printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line , root->child->brother->col, root->child->brother->value);
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
                printf("Line %d, col %d: Symbol _ is reserved\n", root->child->brother->line, root->child->brother->col);            
            }
            else if (CheckIfAlreadyDefined(func, root->child->brother->value, 1, 1) == NULL) {

                aux_func = createSym(root->child->brother->value, changeType(root->child->var), "", root->child->brother->line, root->child->brother->col, 1);
                aux->in = aux_func;
                aux = aux_func;
            } else {
                printf("Line %d, col %d: Symbol %s already defined\n", root->child->brother->line, root->child->brother->col, root->child->brother->value);            
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
    first->in = createSym("return", changeType(first->type), "", 0, 0, 0);

    char * param = NULL;
    node * aux_root = root->child->brother->brother->child;
    Sym * aux_first = first->in;
    Sym * aux2;
    int aux_param = 0;
    
    while(aux_root != NULL && aux_root->child != NULL){
        if(strcmp(aux_root->child->brother->value,"_")==0){
            //printf("________ %s ---- %d\n", aux_root->child->brother->var, aux_root->child->brother->col);
            printf("Line %d, col %d: Symbol _ is reserved\n", aux_root->child->brother->line, aux_root->child->brother->col);            
            
            aux_param = 1;
        }
        else if ((aux2 = CheckIfAlreadyDefined(first->in, aux_root->child->brother->value, 1, 1)) != NULL){
            aux_param = 1;
            printf("Line %d, col %d: Symbol %s already defined\n", aux_root->child->brother->line, aux_root->child->brother->col, aux_root->child->brother->value);            
        }
            

        if (aux_param == 0) {
            Sym * aux;

            aux = createSym(aux_root->child->brother->value, changeType(aux_root->child->var),"", aux_root->child->brother->line, aux_root->child->brother->col, 1); //FIXME: Verificar se correto
            aux->auxparam = 1;
            aux_first->in = aux;
            aux_first = aux;
        }
        if(strcmp(temp, "") == 0){
            
            temp = StringCat(temp, changeType(aux_root->child->var));

        }else{

            temp = StringCat(temp, ",");
            temp = StringCat(temp, changeType(aux_root->child->var));

        }
        aux_root = aux_root->brother;
        aux_param = 0;
    }
 
    first->param = strdup(temp);
}

int MethodDecl(Sym * last, Sym * first, struct node * root) {

    char * func_name = root->child->child->brother->value;
    
    Sym * newMethod = createSym(func_name, changeType(root->child->child->var), "", root->child->child->brother->line, root->child->child->brother->col, 0);

    last->next = newMethod;

    Header(root->child, newMethod);

    while (first) {
        if (first->variable == 0) {
            if (strcmp (first->name, func_name) == 0 && strcmp(newMethod->param, first->param) == 0 && first->next != NULL){
                root->child->child->brother->valid = 0;
                return 1;
            }
        }
        first = first->next;
    }
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
            temptype = first->type;

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
    
    while (aux != NULL) {
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
        if (aux == 1) {
            if (simTab->variable == 1){
                if (strcmp(simTab->name, name) == 0) {
                    return simTab;
                }
            }
        } else {
            if (simTab->variable == 0) {
                if (strcmp(name, simTab->name) == 0) {
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

char* Operadores(char* string){
    if(strcmp(string, "Assign")==0)
        return "=";
    else if(strcmp(string, "Add")==0)
        return "+";
    else if(strcmp(string, "Sub")==0)
        return "-";
    else if(strcmp(string, "Mul")==0)
        return "*";
    else if(strcmp(string, "Div")==0)
        return "/";
    else if(strcmp(string, "Mod")==0)
        return "%";
    else if(strcmp(string, "And")==0)
        return "&&";
    else if(strcmp(string, "Or")==0)
        return "||";
    else if(strcmp(string, "Ne")==0)
        return "!=";
    else if(strcmp(string, "Lt")==0)
        return "<";
    else if(strcmp(string, "Gt")==0)
        return ">";
    else if(strcmp(string, "Ge")==0)
        return ">=";
    else if(strcmp(string, "Le")==0)
        return "<=";
    else if(strcmp(string, "Return")==0)
        return "return";
    else if(strcmp(string, "Not") == 0)
        return "!";
    else if(strcmp(string, "Plus") == 0)
        return "+";
    else if(strcmp(string, "Minus") == 0)
        return "-";
    else if(strcmp(string, "Eq") == 0)
        return "==";
    else if(strcmp(string, "Xor") == 0)
        return "^";
    else return NULL;    
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

    if (strcmp("MethodHeader", root->var) == 0){ 
        name = root->child->brother->value;
        funcline = root->line;
        auxreturn = strdup(root->child->var);
        if (root->child->brother->valid == 0)
            return;
    }

    if (root->child != NULL)
        checkTypes(root->child, first, name);
    if (root->brother != NULL)
        checkTypes(root->brother, first, name);
         
    if(TwoMemberOp(root->var)){
        TwoMember(root, first, name, false);
        
    } else if(Logical(root->var)){
        TwoMember(root, first, name, true);
    } else if(isVAR(root));                                       
        
    else if(NotLogical(root->var)){
        OneMemberNL(root, first, name, 0);
    } else if(OneLogical(root->var)){
        OneMemberNL(root, first, name, 1);
    }
    else if(strcmp(root->var, "Call") == 0){     
        Calls(root, first, name);

    }
    
}

int checkParameters(char * param, char * auxparam){
    char * tok;
    char * tok2;

    char * tok3;
    char * tok4;

    tok = strtok_r(param, ",", &tok3);
    tok2 = strtok_r(auxparam, ",", &tok4);
    while(tok != NULL && tok2 != NULL) {
        if (!(strcmp(tok, "int") == 0 && strcmp(tok2, "double") == 0) && strcmp(tok, tok2) != 0){
            return false;
        }

        
        tok = strtok_r(NULL, ",", &tok3);
        tok2 = strtok_r(NULL, ",", &tok4);

    }


    if (tok == NULL && tok2 == NULL){
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

    char * tvar;


    while(aux != NULL){

        if((aux->var[0] == 'I') && (aux->var[1] == 'd')){

            tvar = searchType(aux, first_aux, name, aux->value, aux->line, 1);

            aux->anotation = tolower_word(tvar);
            
            if (strcmp(tvar, "NULL") == 0 || strcmp(tvar, "undef") == 0) {
                printf("Line %d, col %d: Cannot find symbol %s\n", aux->line, aux->col, aux->value);
            }
            

        }

        if(strcmp(aux->var,"Call")== 0 && aux->anotation == NULL){
          

            if(strlen(param_aux) == 0){
                param_aux = StringCat(param_aux, "NULL");

            }
            else{
                param_aux = StringCat(param_aux, ",");
                param_aux = StringCat(param_aux, "NULL");
            }
        }else{

            if(strlen(param_aux) == 0){
                param_aux = StringCat(param_aux, aux->anotation);
            }
            else{
                param_aux = StringCat(param_aux, ",");
                param_aux = StringCat(param_aux, aux->anotation);
                
            }
            
        }
        aux = aux->brother;
        
    }
    
    while(first != NULL){
        if(strcmp(first->name, root->child->value) == 0 && first->variable == 0 ){
            
            if (strcmp(param_aux, tolower_word(first->param)) == 0) {

                char* aux_p = "(";
                at_least_one =1;
                type = first->type;
            
                param = tolower_word(first->param);
        
                aux_p = StringCat(aux_p, param);
                aux_p = StringCat(aux_p, ")");

                root->child->anotation = aux_p;
                count = 0;
                break;
                
            } else { 
                char* temp = strdup(param_aux); 
                char* temp2 = strdup(tolower_word(first->param));      

                if (checkParameters(temp, temp2) == true) {
                    char* aux_p2 = "(";
                    at_least_one =1;

                    type = first->type;
                
                    param = tolower_word(first->param);
            
                    aux_p2 = StringCat(aux_p2, param);
                    aux_p2 = StringCat(aux_p2, ")");

                    if (count == 0)
                        root->child->anotation = aux_p2;
                    else {
                        //ERROR

                        root->child->anotation = "undef";
                    }
                    count ++;
                }   
            }
        }
        first = first->next;
    }
    
    if(at_least_one == 0){
        printf("Line %d, col %d: Cannot find symbol %s(%s)\n", root->child->line, root->child->col, root->child->value, param_aux);
        root->child->anotation = "undef";
        type = "undef";
    }

    
    
    if(strcmp(type, "NULL")!= 0){
        if(count > 1 ){ 
            root->anotation = "undef";
        }else{
            root->anotation = tolower_word(type);
        }
        
    }

}

void TwoMember(struct node * root, Sym * first, char * name, int flag){

    char * type="", * type2="";
    if ((root->child->var[0] == 'I')){

        type = searchType(root, first, name, root->child->value, root->child->line, 1);

        root->child->anotation = tolower_word(type);

        if (strcmp(type, "NULL") == 0 || strcmp(type, "undef") == 0) {
            printf("Line %d, col %d: Cannot find symbol %s\n", root->child->line, root->child->col, root->child->value);
        }

    } else {
        type = root->child->anotation;
    }

    if ((root->child->brother->var[0] == 'I')){

        type2 = searchType(root, first, name, root->child->brother->value, root->child->brother->line,1);

        root->child->brother->anotation = tolower_word(type2);

        if (strcmp(type2, "NULL") == 0 || strcmp(type2, "undef") == 0) {
            printf("Line %d, col %d: Cannot find symbol %s\n", root->child->brother->line, root->child->brother->col, root->child->brother->value);
        }
        

    } else {
        type2 = root->child->brother->anotation;
    } 


    if(type != NULL && type2 != NULL && strcmp(tolower_word(type), tolower_word(type2))==0){
        if(strcmp(tolower_word(type), "undef") == 0 && strcmp(tolower_word(type2), "undef") == 0 && strcmp(root->var, "ParseArgs") != 0){
            if(flag == false){
                root->anotation = "undef";
                
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, Operadores(root->var), tolower_word(type), tolower_word(type2));
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
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, Operadores(root->var), tolower_word(type), tolower_word(type));
                    } else if (strcmp(tolower_word(type), "int") == 0){
                        root->anotation = "int";
                    }else if (strcmp(tolower_word(type), "boolean") == 0){
                        root->anotation = "boolean";
                    }
                }
                

            }else{

                if (strcmp(root->var, "Assign") == 0 ) {

                    root->anotation = tolower_word(type);
                } else if (strcmp(root->var, "Add") == 0 || strcmp(root->var, "Sub") == 0 || strcmp(root->var, "Div") == 0 || strcmp(root->var, "Mul") == 0 || strcmp(root->var, "Mod") == 0){ 

                    if (strcmp(tolower_word(type), "int") == 0) {
                        root->anotation = "int";
                    } else if (strcmp(tolower_word(type), "double") == 0) {
                        root->anotation = "double";    
                    } else {
                        root->anotation = "undef";
                        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, Operadores(root->var), tolower_word(type), tolower_word(type2));
                    }
                    
                } else if (strcmp(root->var, "Lshift") == 0 || strcmp(root->var, "Rshift") == 0) {
                    if (strcmp(tolower_word(type), "int") == 0)
                        root->anotation = tolower_word(type);
                    else {
                        root->anotation = "undef";
                        //ERROR
                        
                    }
                } else if (strcmp(root->var, "ParseArgs") == 0) {
                    //ERROR
                    printf("Line %d, col %d: Operator Integer.parseInt cannot be applied to types %s, %s\n",root->child->line, root->child->col-17,tolower_word(type), type2);

                    root->anotation = "int";
                } else {
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
                if ((strcmp(tolower_word(type), "double") == 0 && strcmp(tolower_word(type2), "int") == 0) || (strcmp(tolower_word(type), "int") == 0 && strcmp(tolower_word(type2), "double") == 0)) {
                    root->anotation = "double";    
                } else {
                    root->anotation = "undef";
                }
                if (!((strcmp(tolower_word(type), "int") == 0 && strcmp(tolower_word(type2), "double") == 0) || (strcmp(tolower_word(type), "double") == 0 && strcmp(tolower_word(type2), "int") == 0)))
                    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", root->line, root->col, Operadores(root->var), tolower_word(type), tolower_word(type2));
            }else if (strcmp(root->var, "Assign") == 0) {

                if(!(strcmp(tolower_word(type), "double") == 0 && strcmp(tolower_word(type2), "int") == 0))
                    printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n", root->line, root->col, tolower_word(type), tolower_word(type2));
            
                root->anotation = tolower_word(type);
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
    

    if(root->child == NULL){
        type = "NULL";
    } else if ((root->child->var[0] == 'I')){

        type = searchType(root, first, name, root->child->value, root->child->line,1);

        root->child->anotation = tolower_word(type);

        if (strcmp(type, "NULL") == 0 || strcmp(type, "undef") == 0) {
            printf("Line %d, col %d: Cannot find symbol %s\n", root->child->line, root->child->col, root->value);
        }
      
    }else {
        type = root->child->anotation;

    }
   
    if(type != NULL){
        if (strcmp(root->var, "Length") == 0) {
            if (strcmp(root->child->anotation, "int") != 0){
                root->anotation = "int";
            }else {
                //ERROR (tive de adicionar 1 à coluna)
                printf("Line %d, col %d: Operator .%s cannot be applied to type %s\n", root->child->line,root->child->col + 1,tolower_word(root->var),tolower_word(type));
                root->anotation = "int";
            }
        }else if (strcmp(root->var, "Return") == 0){
            if (root->child == NULL){
                //printf("-------> %s\n", auxreturn);
                if (strcmp(auxreturn, "Void") != 0)
                    printf("Line %d, col %d: Incompatible type void in return statement\n", root->line, root->col);
            } else if (strcmp(tolower_word(root->child->anotation), tolower_word(auxreturn)) != 0 && !(strcmp(auxreturn, "Double") == 0 && strcmp(root->child->anotation, "int") == 0)) {
                //printf("VAR: %s\n", root->child->var);
                printf("Line %d, col %d: Incompatible type %s in return statement\n", root->child->line, root->child->col, tolower_word(root->child->anotation));
            }
        }else if (strcmp(root->var, "While") == 0){
            return;
        }else if (strcmp(root->var, "If") == 0 ){
            if (root->child != NULL && (root->child->anotation, "boolean") != 0)
                printf("Line %d, col %d: Incompatible type %s in if statement\n",root->child->line, root->child->col,  type);
        }else if(strcmp(tolower_word(type),"undef") == 0 && strcmp(root->var,"Print") != 0){
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
                        root->anotation = "undef";
                    }
                }
            } else{
                if (strcmp(root->var, "Not") == 0) {
                    if (strcmp(root->child->anotation, "boolean") == 0){
                        root->anotation = "boolean";
                    } else {
                        root->anotation = "boolean";
                        //erro
                    }
                }
            }
        }
    }

}

char * searchType(struct node * root, Sym * first, char * name, char * id, int line, int val) {

    char * type = "";

    while (first != NULL) {

        if (strcmp(id, first->name) == 0) {
            type = first->type;
        }

        if (strcmp(name, first->name) == 0 && first->line == funcline){

            Sym * aux = first->in;

            while (aux != NULL) {

                if (strcmp(id, aux->name) == 0 && line > aux->line) {
                    type = aux->type;
                    return type;
                }

                aux = aux->in;
                if (aux == NULL && strcmp(type, "") == 0){
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
    if (root->value != NULL) {

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
            long dec = atol(dec_aux);
            if (dec >= 2147483648) {
                //ERROR
                printf("Line %d, col %d: Number %s out of bounds\n", root->line, root->col, root->value);
            }
            return true;
        } else if (root->var[0] == 'B' && root->var[1] == 'o' ) {   //FIXME: BoolLit e Bool, uma historia de amor...
            type = "boolean";
            root->anotation = type;
            return true;
        } else if (root->var[0] == 'R' && root->var[1] == 'e' && root->var[2] == 'a') {
            type = "double";
            root->anotation = type;
            return true;
        } else if (root->var[0] == 'S' && root->var[1] == 't' && root->var[2] == 'r') {
            type = "String";
            root->anotation = type;
            return true;
        }
    }    
    return false;
}



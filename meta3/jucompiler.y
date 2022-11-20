%{

    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    
    #include "SymTable.h"

    int yylex(void);
    

    char aux3[1024]; 
    char aux4[1024]; 

    int error;
    struct node * prog;
    int debug = false;

    void yyerror (const char *s);
%}


%union{
    char* id;
    struct node * no;
};


%token  <id> ID
%token  <id> INTLIT
%token  <id> STRLIT
%token  <id> REALLIT    
%token  <id> BOOLLIT
%token AND
%token ASSIGN
%token STAR
%token COMMA
%token DIV
%token EQ
%token GE
%token GT
%token LBRACE
%token LE
%token LPAR
%token LSQ
%token LT
%token MINUS
%token MOD
%token NE
%token NOT
%token OR
%token PLUS
%token RBRACE
%token RPAR
%token RSQ
%token SEMICOLON
%token ARROW
%token LSHIFT
%token RSHIFT
%token XOR
%token BOOL
%token CLASS
%token DOTLENGTH
%token DOUBLE
%token ELSE
%token IF
%token INT
%token PRINT
%token PARSEINT
%token PUBLIC
%token RETURN
%token STATIC
%token STRING
%token VOID
%token WHILE
%token RESERVED


%right  ASSIGN
%left   OR
%left   AND
%left   XOR
%left   EQ NE
%left   LE LT GE GT
%left   LSHIFT RSHIFT
%left   PLUS MINUS
%left   STAR DIV MOD
%right  NOT
%left   LPAR RPAR LSQ RSQ


%nonassoc ELSE


%type <no> Program
%type <no> recPR
%type <no> MethodDecl
%type <no> FieldDecl
%type <no> recCOMMAID
%type <no> Type
%type <no> MethodHeader
%type <no> FormalParams
%type <no> recFP
%type <no> MethodBody
%type <no> recMD
%type <no> VarDecl
%type <no> Statement
%type <no> MethodInvocation
%type <no> recCOMMAEXP
%type <no> Assignment
%type <no> ParseArgs
%type <no> Expr
%type <no> Expr2
%type <no> recVAR
%type <no> recSTAT



%%
Program                     :   CLASS ID LBRACE recPR RBRACE                    {$$ = prog = createNode(NULL,"Program"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode($2, strdup(aux3)); newBrother($$->child, $4); if(debug)printf("Program\n");}                           
                            ;

recPR                       :   MethodDecl recPR                               {$$ = $1; newBrother($$, $2);if(debug)printf("recPR4\n");}
                            |   FieldDecl recPR                                {$$ = $1; newBrother($$, $2);if(debug)printf("recPR5\n");}
                            |   SEMICOLON recPR                                {$$ = $2;if(debug)printf("recPR6\n");}
                            |                                                  {$$ = NULL;}
                            ;

MethodDecl                  :   PUBLIC STATIC MethodHeader MethodBody           {$$ = createNode(NULL,"MethodDecl"); $$->child = $3; newBrother($3, $4);if(debug)printf("MethodDecl\n");}
                            ;

FieldDecl                   :   PUBLIC STATIC Type ID recCOMMAID SEMICOLON      {$$ = createNode(NULL,"FieldDecl"); $$->child = $3; sprintf(aux3, "Id(%s)", $4); newBrother($3, createNode($4, strdup(aux3))); newBrother($$, $5);
                                                                                    struct node * auxnode = $5, * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode(NULL,$3->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("FieldDecl\n");
                                                                                }
                            |   error SEMICOLON                                 {$$=createNode(NULL,NULL);error=true;if(debug)printf("FieldDecl3\n");}
                            ;

recCOMMAID                  :   COMMA ID recCOMMAID                             {$$ = createNode(NULL,"FieldDecl"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode($2, strdup(aux3)); newBrother($$, $3);if(debug)printf("recCommaId2(%s)\n", aux3);}
                            |                                                   {$$ = NULL;}
                            ;           

Type                        :   BOOL                                            {$$ = createNode(NULL,"Bool");if(debug)printf("Bool\n");}
                            |   INT                                             {$$ = createNode(NULL,"Int");if(debug)printf("Int\n");}
                            |   DOUBLE                                          {$$ = createNode(NULL,"Double");if(debug)printf("Double\n");}
                            ;           

MethodHeader                :   Type ID LPAR FormalParams RPAR                  {$$ = createNode(NULL,"MethodHeader"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode($2, strdup(aux3))); newBrother($1, $4);if(debug)printf("MethodHeader\n");}
                            |   Type ID LPAR RPAR                               {$$ = createNode(NULL,"MethodHeader"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode($2, strdup(aux3))); newBrother($1, createNode(NULL,"MethodParams"));if(debug)printf("MethodHeader2\n");}
                            |   VOID ID LPAR FormalParams RPAR                  {$$ = createNode(NULL,"MethodHeader"); $$->child = createNode(NULL,"Void"); sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode($2, strdup(aux3))); newBrother($$->child, $4);if(debug)printf("MethodHeader3\n");}
                            |   VOID ID LPAR RPAR                               {$$ = createNode(NULL,"MethodHeader");$$->child = createNode(NULL,"Void"); sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode($2, strdup(aux3)));newBrother($$->child,createNode(NULL,"MethodParams"));if(debug)printf("MethodHeader4\n");}
                            ;           

FormalParams                :   Type ID recFP                                   {$$ = createNode(NULL,"MethodParams"); $$->child = createNode(NULL,"ParamDecl"); $$->child->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode($2, strdup(aux3))); newBrother($$->child, $3);

                                                                                    if(debug)printf("FormalParams\n");
                                                                                }
                            
                            |   STRING LSQ RSQ ID                               {$$ = createNode(NULL,"MethodParams"); $$->child = createNode(NULL,"ParamDecl"); $$->child->child = createNode(NULL,"StringArray"); sprintf(aux3, "Id(%s)", $4); newBrother($$->child->child, createNode($4, strdup(aux3)));if(debug)printf("FormalParams3\n");}
                            ;           

recFP                       :   COMMA Type ID recFP                             {$$ = createNode(NULL,"ParamDecl"); newBrother($$, $4); $$->child = $2; sprintf(aux3, "Id(%s)", $3); newBrother($2, createNode($3, strdup(aux3)));if(debug)printf("recFP\n");}
                            |                                                   {$$ = NULL;if(debug)printf("recFP2\n");} 
                            ;           

MethodBody                  :   LBRACE recMD RBRACE                             {$$ = createNode(NULL,"MethodBody"); $$->child = $2;if(debug)printf("MethodBody\n");}
                            ;           

recMD                       :   Statement recMD                                 {if($1) {$$ = $1; newBrother($$, $2);}else{$$=$2;}if(debug)printf("recMD3\n");}
                            |   VarDecl recMD                                   {$$ = $1; newBrother($$, $2);if(debug)printf("recMD4\n");}
                            |                                                   {$$ = NULL;}
                            ;           

VarDecl                     :   Type ID recVAR SEMICOLON                        {$$ = createNode(NULL,"VarDecl"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode($2, strdup(aux3))); newBrother($$, $3);
                                                                                    struct node * auxnode = $3, * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode(NULL,$1->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("VarDecl\n");
                                                                                }
                            ;           

recVAR                      :   COMMA ID recVAR                                 {$$ = createNode(NULL,"VarDecl"); newBrother($$, $3); sprintf(aux3, "Id(%s)", $2); $$->child = createNode($2, strdup(aux3));if(debug)printf("recVAR2\n");}
                            |                                                   {$$ = NULL;}
                            ;                        

Statement                   :   LBRACE recSTAT RBRACE                           {if ($2!=NULL){if ($2->brother != NULL){$$ = createNode(NULL,"Block"); $$->child = $2;} else {$$ = $2;}} else {$$ = $2;}; if(debug)printf("Statement\n");}
                            |   IF LPAR Expr RPAR Statement ELSE Statement      {$$ = createNode(NULL,"If"); $$->child = $3;
                                                                                    if ($5 != NULL && numBrothers($5) == 1) {
                                                                                        newBrother($3, $5);
                                                                                        if ($7 != NULL && numBrothers($7) == 1){
                                                                                            newBrother($5, $7);
                                                                                        } else {
                                                                                            newBrother($5, createNode(NULL,"Block"));
                                                                                            $5->brother->child = $7;
                                                                                        }
                                                                                    } else {
                                                                                        struct node * temp = createNode(NULL,"Block");
                                                                                        newBrother($3, temp);
                                                                                        temp->child = $5;
                                                                                        if($7 != NULL && numBrothers($7) == 1){
                                                                                            newBrother(temp, $7); 
                                                                                        }
                                                                                        else{
                                                                                            newBrother(temp, createNode(NULL,"Block"));
                                                                                            temp->brother->child = $7;
                                                                                        }
                                                                                    }
                                                                                if(debug)printf("Statement3\n");}                            
                            |   IF LPAR Expr RPAR Statement                     {$$ = createNode(NULL,"If"); $$->child = $3;
                                                                                    if ($5!=NULL && numBrothers($5) == 1) {
                                                                                        newBrother($3, $5);
                                                                                        newBrother($5, createNode(NULL,"Block"));
                                                                                    } else {
                                                                                        struct node * temp = createNode(NULL,"Block");
                                                                                        newBrother($3, temp);
                                                                                        temp->child = $5;
                                                                                        newBrother(temp, createNode(NULL,"Block"));
                                                                                    }
                                                                                if(debug)printf("Statement4\n");}
                            |   WHILE LPAR Expr RPAR Statement                  {$$ = createNode(NULL,"While"); $$->child = $3; 
                                                                                    if($5 != NULL && numBrothers($5) < 2){
                                                                                        newBrother($3, $5);
                                                                                    } else{
                                                                                        newBrother($3, createNode(NULL,"Block"));
                                                                                        $3->brother->child = $5;
                                                                                    }
                                                                                if(debug)printf("Statement5\n");}
                            |   RETURN Expr SEMICOLON                           {$$ = createNode(NULL,"Return"); $$->child = $2;if(debug)printf("Statement6\n");}                            
                            |   RETURN SEMICOLON                                {$$ = createNode(NULL,"Return");if(debug)printf("Statement7\n");}
                            |   MethodInvocation SEMICOLON                      {$$ = $1;if(debug)printf("Statement8\n");}
                            |   Assignment SEMICOLON                            {$$ = $1;if(debug)printf("Statement9\n");}
                            |   ParseArgs SEMICOLON                             {$$ = $1;if(debug)printf("Statement10\n");}
                            |   SEMICOLON                                       {$$ = NULL;if(debug)printf("Statement11\n");}                            
                            |   PRINT LPAR Expr RPAR SEMICOLON                  {$$ = createNode(NULL,"Print"); $$->child = $3;if(debug)printf("Statement12\n");}
                            |   PRINT LPAR STRLIT RPAR SEMICOLON                {$$ = createNode(NULL,"Print"); sprintf(aux3, "StrLit(\"%s)", $3); $$->child = createNode($3, strdup(aux3));if(debug)printf("Statement13\n");}
                            |   error SEMICOLON                                 {$$=createNode(NULL,NULL);error=true;if(debug)printf("Statement15\n");}
                            ;

recSTAT                     :   Statement recSTAT                               {if($$!=NULL){$$=$1; newBrother($$,$2);} else{$$=$2;}}
                            |                                                   {$$ = NULL;}
                            ;

MethodInvocation            :   ID LPAR Expr recCOMMAEXP RPAR                   {$$ = createNode(NULL,"Call"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode($1, strdup(aux3)); newBrother($$->child, $3); newBrother($3, $4);if(debug)printf("MethodInvocation\n");}
                            |   ID LPAR RPAR                                    {$$ = createNode(NULL,"Call"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode($1, strdup(aux3));if(debug)printf("MethodInvocation3\n");}
                            |   ID LPAR error RPAR                              {$$=createNode(NULL, NULL);error=true;if(debug)printf("MethodInvocation4\n");}
                            ;

recCOMMAEXP                 :   COMMA Expr recCOMMAEXP                          {$$ = $2; newBrother($2, $3);if(debug)printf("recCOMMAEXP\n");}
                            |                                                   {$$ = NULL;}
                            ;

Assignment                  :   ID ASSIGN Expr                                  {$$ = createNode(NULL,"Assign"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode($1, strdup(aux3)); newBrother($$->child, $3);if(debug)printf("Assign\n");}
                            ;

ParseArgs                   :   PARSEINT LPAR ID LSQ Expr RSQ RPAR              {$$ = createNode(NULL,"ParseArgs"); sprintf(aux3, "Id(%s)", $3); $$->child = createNode($3, strdup(aux3)); newBrother($$->child, $5);if(debug)printf("ParseArgs + id(%s)\n",aux3);}
                            |   PARSEINT LPAR error RPAR                        {$$ = NULL;$$=createNode(NULL,NULL);error=true;if(debug)printf("ParseArgs2\n");}
                            ;

Expr2                       :   Expr2 PLUS Expr2                                  {$$ = createNode(NULL,"Add"); $$->child=$1; newBrother($1,$3);if(debug)printf("PLUS\n");}
                            |   Expr2 MINUS Expr2                                 {$$ = createNode(NULL,"Sub"); $$->child=$1; newBrother($1,$3);if(debug)printf("MINUS\n");}
                            |   Expr2 STAR Expr2                                  {$$ = createNode(NULL,"Mul"); $$->child=$1; newBrother($1,$3);if(debug)printf("STAR\n");}
                            |   Expr2 DIV Expr2                                   {$$ = createNode(NULL,"Div"); $$->child=$1; newBrother($1,$3);if(debug)printf("DIV\n");}
                            |   Expr2 MOD Expr2                                   {$$ = createNode(NULL,"Mod"); $$->child=$1; newBrother($1,$3);if(debug)printf("MOD\n");}
                            |   Expr2 AND Expr2                                   {$$ = createNode(NULL,"And"); $$->child=$1; newBrother($1,$3);if(debug)printf("AND\n");}
                            |   Expr2 OR Expr2                                    {$$ = createNode(NULL,"Or"); $$->child=$1; newBrother($1,$3);if(debug)printf("OR\n");}
                            |   Expr2 XOR Expr2                                   {$$ = createNode(NULL,"Xor"); $$->child=$1; newBrother($1,$3);if(debug)printf("XOR\n");}
                            |   Expr2 LSHIFT Expr2                                {$$ = createNode(NULL,"Lshift"); $$->child=$1; newBrother($1,$3);if(debug)printf("LSHIFT\n");}
                            |   Expr2 RSHIFT Expr2                                {$$ = createNode(NULL,"Rshift"); $$->child=$1; newBrother($1,$3);if(debug)printf("RSHIFT\n");}
                            |   Expr2 EQ Expr2                                    {$$ = createNode(NULL,"Eq"); $$->child=$1; newBrother($1,$3);if(debug)printf("EQ\n");}
                            |   Expr2 GE Expr2                                    {$$ = createNode(NULL,"Ge"); $$->child=$1; newBrother($1,$3);if(debug)printf("GE\n");}
                            |   Expr2 GT Expr2                                    {$$ = createNode(NULL,"Gt"); $$->child=$1; newBrother($1,$3);if(debug)printf("GT\n");}
                            |   Expr2 LE Expr2                                    {$$ = createNode(NULL,"Le"); $$->child=$1; newBrother($1,$3);if(debug)printf("LE\n");}
                            |   Expr2 LT Expr2                                    {$$ = createNode(NULL,"Lt"); $$->child=$1; newBrother($1,$3);if(debug)printf("LT\n");}
                            |   Expr2 NE Expr2                                    {$$ = createNode(NULL,"Ne"); $$->child=$1; newBrother($1,$3);if(debug)printf("NE\n");}
                            |   MINUS Expr2              %prec NOT               {$$ = createNode(NULL,"Minus"); $$->child=$2;if(debug)printf("MINUS2\n");}
                            |   PLUS Expr2               %prec NOT               {$$ = createNode(NULL,"Plus"); $$->child=$2;if(debug)printf("PLUS2\n");}
                            |   NOT Expr2                                        {$$ = createNode(NULL,"Not"); $$->child=$2;if(debug)printf("NOT\n");}
                            |   LPAR Expr RPAR                                  {$$ = $2;if(debug)printf("EXPR\n");}
                            |   MethodInvocation                                {$$ = $1;if(debug)printf("MI\n");}
                            |   ParseArgs                                       {$$ = $1;if(debug)printf("PA\n");}
                            |   ID                                              {sprintf(aux3, "Id(%s)", $1); $$ = createNode($1, strdup(aux3));if(debug)printf("%s_ID111\n", aux3);}
                            |   ID DOTLENGTH                                    {$$ = createNode(NULL, "Length"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode($1, strdup(aux3));if(debug)printf("DOT\n");}
                            |   INTLIT                                          {sprintf(aux3, "DecLit(%s)", $1); $$ = createNode($1, strdup(aux3));if(debug)printf("DEC2\n");}
                            |   REALLIT                                         {sprintf(aux3, "RealLit(%s)", $1); $$ = createNode($1, strdup(aux3));if(debug)printf("REAL2\n");}
                            |   BOOLLIT                                         {sprintf(aux3, "BoolLit(%s)", $1); $$ = createNode($1, strdup(aux3));if(debug)printf("BOOL2\n");}
                            |   LPAR error RPAR                                 {$$=createNode(NULL,NULL);error=true;if(debug)printf("666\n");}
                            ;

Expr                        :   Assignment                                      {$$ = $1;}
                            |   Expr2                                            {$$ = $1;}
                            ;

%%
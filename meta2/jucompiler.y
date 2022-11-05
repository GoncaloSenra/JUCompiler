
%{

    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    #include "STree.h"
    int yylex(void);
    #define true 1
    #define false 0

    char aux3[1024]; 
    char aux4[1024]; 
    struct node * prog;
    int hasError;
    int printTree= true;
    int debug = false;

    void yyerror (const char *s);
%}


%union{
    char* id;
    int intlit;
    float reallit;
    struct node * no;
};

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
%type <no> recVAR
%type <no> recSTAT


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

%left   COMMA
%right  ASSIGN
%left   OR
%left   AND
%left   XOR
%left   EQ NE
%left   LE LT GE GT
%left   PLUS MINUS
%left   MUL DIV MOD
%left   STAR LSHIFT RSHIFT
%right  NOT
%left   LPAR
%left   RPAR

%nonassoc LOWER
%nonassoc ELSE
%nonassoc HIGHER

%%
Program                     :   CLASS ID LBRACE recPR RBRACE                    {$$ = createNode("Program"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3)); newBrother($$->child, $4); if (printTree==true && hasError==false){printASTree($$,0);} else{freeASTree($$);}  if(debug)printf("Program\n");}                           
                            |   CLASS ID LBRACE RBRACE                          {$$ = createNode("Program"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3));if(debug)printf("Program2\n");}
                            ;

recPR                       :   MethodDecl                                      {$$ = $1;if(debug)printf("recPR\n");}
                            |   FieldDecl                                       {$$ = $1;if(debug)printf("recPR2\n");}    
                            |   SEMICOLON                                       {;if(debug)printf("recPR3\n");}
                            |   MethodDecl recPR                               {$$ = $1; newBrother($$, $2);if(debug)printf("recPR4\n");}
                            |   FieldDecl recPR                                {$$ = $1; newBrother($$, $2);if(debug)printf("recPR5\n");}
                            |   SEMICOLON recPR                                {$$ = $2;if(debug)printf("recPR6\n");}
                            ;

MethodDecl                  :   PUBLIC STATIC MethodHeader MethodBody           {$$ = createNode("MethodDecl"); $$->child = $3; newBrother($3, $4);if(debug)printf("MethodDecl\n");}
                            ;

FieldDecl                   :   PUBLIC STATIC Type ID recCOMMAID SEMICOLON      {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux3, "Id(%s)", $4); newBrother($3, createNode(strdup(aux3))); newBrother($$, $5);
                                                                                    struct node * auxnode = $5, * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode($3->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("FieldDecl\n");
                                                                                }
                            |   PUBLIC STATIC Type ID SEMICOLON                 {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux3, "Id(%s)", $4); newBrother($3, createNode(strdup(aux3)));if(debug)printf("FieldDecl2\n");}
                            |   error SEMICOLON                                 {hasError=true;if(debug)printf("FieldDecl3\n");}
                            ;

recCOMMAID                  :   COMMA ID                                        {$$ = createNode("FieldDecl"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3));if(debug)printf("recCommaId(%s)\n", aux3);}
                            |   COMMA ID recCOMMAID                             {$$ = createNode("FieldDecl"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3)); newBrother($$, $3);if(debug)printf("recCommaId2(%s)\n", aux3);}
                            ;           

Type                        :   BOOL                                            {$$ = createNode("Bool");if(debug)printf("Bool\n");}
                            |   INT                                             {$$ = createNode("Int");if(debug)printf("Int\n");}
                            |   DOUBLE                                          {$$ = createNode("Double");if(debug)printf("Double\n");}
                            ;           

MethodHeader                :   Type ID LPAR FormalParams RPAR                  {$$ = createNode("MethodHeader"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3))); newBrother($1, $4);if(debug)printf("MethodHeader\n");}
                            |   Type ID LPAR RPAR                               {$$ = createNode("MethodHeader"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3))); newBrother($1, createNode("MethodParams"));if(debug)printf("MethodHeader2\n");}
                            |   VOID ID LPAR FormalParams RPAR                  {$$ = createNode("MethodHeader"); $$->child = createNode("Void"); sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode(strdup(aux3))); newBrother($$->child, $4);if(debug)printf("MethodHeader3\n");}
                            |   VOID ID LPAR RPAR                               {$$ = createNode("MethodHeader");$$->child = createNode("Void"); sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode(strdup(aux3)));newBrother($$->child,createNode("MethodParams"));if(debug)printf("MethodHeader4\n");}
                            ;           

FormalParams                :   Type ID recFP                                   {$$ = createNode("MethodParams"); $$->child = createNode("ParamDecl"); $$->child->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3))); newBrother($$->child, $3);

                                                                                    if(debug)printf("FormalParams\n");
                                                                                }
                            
                            |   STRING LSQ RSQ ID                               {$$ = createNode("MethodParams"); $$->child = createNode("ParamDecl"); $$->child->child = createNode("StringArray"); sprintf(aux3, "Id(%s)", $4); newBrother($$->child->child, createNode(strdup(aux3)));if(debug)printf("FormalParams3\n");}
                            ;           

recFP                       :   COMMA Type ID recFP                             {$$ = createNode("ParamDecl"); newBrother($$, $4); $$->child = $2; sprintf(aux3, "Id(%s)", $3); newBrother($2, createNode(strdup(aux3)));if(debug)printf("recFP\n");}
                            |    /*vazio*/                                      {$$ = NULL;if(debug)printf("recFP2\n");} 
                            ;           

MethodBody                  :   LBRACE recMD RBRACE                             {$$ = createNode("MethodBody"); $$->child = $2;if(debug)printf("MethodBody\n");}
                            |   LBRACE RBRACE                                   {$$ = createNode("MethodBody");if(debug)printf("MethodBody2\n");}
                            ;           

recMD                       :   Statement                                       {$$ = $1;if(debug)printf("recMD\n");}
                            |   VarDecl                                         {$$ = $1;if(debug)printf("recMD2\n");}
                            |   Statement recMD                                 {if($1) {$$ = $1; newBrother($$, $2);}else{$$=$2;}if(debug)printf("recMD3\n");}
                            |   VarDecl recMD                                   {$$ = $1; newBrother($$, $2);if(debug)printf("recMD4\n");}
                            ;           

VarDecl                     :   Type ID recVAR SEMICOLON                        {$$ = createNode("VarDecl"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode(strdup(aux3))); newBrother($$, $3);
                                                                                    struct node * auxnode = $3, * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode($1->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("VarDecl\n");
                                                                                }
                            |   Type ID SEMICOLON                               {$$ = createNode("VarDecl"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3)));if(debug)printf("VarDecl2\n");}
                            ;           

recVAR                      :   COMMA ID                                        {$$ = createNode("VarDecl"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3));if(debug)printf("recVAR\n");}
                            |   COMMA ID recVAR                                 {$$ = createNode("VarDecl"); newBrother($$, $3); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3));if(debug)printf("recVAR2\n");}
                            ;                        

Statement                   :   LBRACE recSTAT RBRACE                           {if($2 != NULL){if($2->brother != NULL){$$ = createNode("Block");$$->child = $2;}else{$$ = $2;}}else $$ = $2;if(debug)printf("Statement\n");}
                            |   LBRACE RBRACE                                   {$$ = NULL;if(debug)printf("Statement2\n");}
                            |   IF LPAR Expr RPAR Statement ELSE Statement      {$$ = createNode("If"); $$->child = $3; if(!$5){newBrother($3, createNode("Block"));newBrother($3, createNode("Block"));} else{newBrother($3, $5); newBrother($3, createNode("Block"));}; newBrother($3, $7);if(debug)printf("Statement3\n");}                            
                            |   IF LPAR Expr RPAR Statement                     {$$ = createNode("If"); $$->child = $3; if(!$5){newBrother($3, createNode("Block"));newBrother($3, createNode("Block"));} else{newBrother($3, $5); newBrother($3, createNode("Block"));};if(debug)printf("Statement4\n");}
                            |   WHILE LPAR Expr RPAR Statement                  {$$ = createNode("While"); $$->child = $3; newBrother($3, $5);if(debug)printf("Statement5\n");}
                            |   RETURN Expr SEMICOLON                           {$$ = createNode("Return"); $$->child = $2;if(debug)printf("Statement6\n");}                            
                            |   RETURN SEMICOLON                                {$$ = createNode("Return");if(debug)printf("Statement7\n");}
                            |   MethodInvocation SEMICOLON                      {$$ = $1;if(debug)printf("Statement8\n");}
                            |   Assignment SEMICOLON                            {$$ = $1;if(debug)printf("Statement9\n");}
                            |   ParseArgs SEMICOLON                             {$$ = $1;if(debug)printf("Statement10\n");}
                            |   SEMICOLON                                       {$$ = NULL;if(debug)printf("Statement11\n");}                            
                            |   PRINT LPAR Expr RPAR SEMICOLON                  {$$ = createNode("Print"); $$->child = $3;if(debug)printf("Statement12\n");}
                            |   PRINT LPAR STRLIT RPAR SEMICOLON                {$$ = createNode("Print"); sprintf(aux3, "StrLit(\"%s\")", $3); $$->child = createNode(strdup(aux3));if(debug)printf("Statement13\n");}
                            |   PRINT LPAR RPAR SEMICOLON                       {$$ = createNode("Print");if(debug)printf("Statement14\n");}                            
                            |   error SEMICOLON                                 {hasError=true;if(debug)printf("Statement15\n");}
                            ;

recSTAT                     :   Statement                                       {$$=$1;}
                            |   Statement recSTAT                               {if($1!=NULL){$$=$1; newBrother($1,$2);} else{$$=$2;}}
                            ;

MethodInvocation            :   ID LPAR Expr recCOMMAEXP RPAR                   {$$ = createNode("Call"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3)); newBrother($$->child, $3); newBrother($3, $4);if(debug)printf("MethodInvocation\n");}
                            |   ID LPAR Expr RPAR                               {$$ = createNode("Call"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3)); newBrother($$->child, $3);if(debug)printf("MethodInvocation2\n");}                                                    
                            |   ID LPAR RPAR                                    {$$ = createNode("Call"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3));if(debug)printf("MethodInvocation3\n");}
                            |   ID LPAR error RPAR                              {hasError=true;if(debug)printf("MethodInvocation4\n");}
                            ;

recCOMMAEXP                 :   recCOMMAEXP COMMA Expr                          {$$ = $1; newBrother($1, $3);if(debug)printf("recCOMMAEXP\n");}
                            |   COMMA Expr                                      {$$ = $2;if(debug)printf("recCOMMAEXP2\n");}
                            ;

Assignment                  :   ID ASSIGN Expr                                  {$$ = createNode("Assign"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3)); newBrother($$->child, $3);if(debug)printf("Assign\n");}
                            ;

ParseArgs                   :   PARSEINT LPAR ID LSQ Expr RSQ RPAR              {$$ = createNode("ParseArgs"); sprintf(aux3, "Id(%s)", $3); $$->child = createNode(strdup(aux3)); newBrother($$->child, $5);if(debug)printf("ParseArgs + id(%s)\n",aux3);}
                            |   PARSEINT LPAR error RPAR                        {$$ = NULL;hasError=true;if(debug)printf("ParseArgs2\n");}
                            ;

Expr                        :   Expr PLUS Expr                                  {$$ = createNode("Add"); $$->child=$1; newBrother($1,$3);if(debug)printf("PLUS\n");}
                            |   Expr MINUS Expr                                 {$$ = createNode("Sub"); $$->child=$1; newBrother($1,$3);if(debug)printf("MINUS\n");}
                            |   Expr STAR Expr                                  {$$ = createNode("Mul"); $$->child=$1; newBrother($1,$3);if(debug)printf("STAR\n");}
                            |   Expr DIV Expr                                   {$$ = createNode("Div"); $$->child=$1; newBrother($1,$3);if(debug)printf("DIV\n");}
                            |   Expr MOD Expr                                   {$$ = createNode("Mod"); $$->child=$1; newBrother($1,$3);if(debug)printf("MOD\n");}
                            |   Expr AND Expr                                   {$$ = createNode("And"); $$->child=$1; newBrother($1,$3);if(debug)printf("AND\n");}
                            |   Expr OR Expr                                    {$$ = createNode("Or"); $$->child=$1; newBrother($1,$3);if(debug)printf("OR\n");}
                            |   Expr XOR Expr                                   {$$ = createNode("Xor"); $$->child=$1; newBrother($1,$3);if(debug)printf("XOR\n");}
                            |   Expr LSHIFT Expr                                {$$ = createNode("Lshift"); $$->child=$1; newBrother($1,$3);if(debug)printf("LSHIFT\n");}
                            |   Expr RSHIFT Expr                                {$$ = createNode("Rshift"); $$->child=$1; newBrother($1,$3);if(debug)printf("RSHIFT\n");}
                            |   Expr EQ Expr                                    {$$ = createNode("Eq"); $$->child=$1; newBrother($1,$3);if(debug)printf("EQ\n");}
                            |   Expr GE Expr                                    {$$ = createNode("Ge"); $$->child=$1; newBrother($1,$3);if(debug)printf("GE\n");}
                            |   Expr GT Expr                                    {$$ = createNode("Gt"); $$->child=$1; newBrother($1,$3);if(debug)printf("GT\n");}
                            |   Expr LE Expr                                    {$$ = createNode("Le"); $$->child=$1; newBrother($1,$3);if(debug)printf("LE\n");}
                            |   Expr LT Expr                                    {$$ = createNode("Lt"); $$->child=$1; newBrother($1,$3);if(debug)printf("LT\n");}
                            |   Expr NE Expr                                    {$$ = createNode("Ne"); $$->child=$1; newBrother($1,$3);if(debug)printf("NE\n");}
                            |   MINUS Expr              %prec NOT               {$$ = createNode("Minus"); $$->child=$2;if(debug)printf("MINUS2\n");}
                            |   PLUS Expr               %prec NOT               {$$ = createNode("Plus"); $$->child=$2;if(debug)printf("PLUS2\n");}
                            |   NOT Expr                                        {$$ = createNode("Not"); $$->child=$2;if(debug)printf("NOT\n");}
                            |   LPAR Expr RPAR                                  {$$ = $2;if(debug)printf("EXPR\n");}
                            |   MethodInvocation                                {$$ = $1;if(debug)printf("MI\n");}
                            |   Assignment                                      {$$ = $1;if(debug)printf("ASS\n");}
                            |   ParseArgs                                       {$$ = $1;if(debug)printf("PA\n");}
                            |   ID                                              {sprintf(aux3, "Id(%s)", $1); $$ = createNode(strdup(aux3));if(debug)printf("%s_ID111\n", aux3);}
                            |   ID DOTLENGTH                                    {$$ = createNode("Length"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3));if(debug)printf("DOT\n");}
                            |   INTLIT                                          {sprintf(aux3, "DecLit(%s)", $1); $$ = createNode(strdup(aux3));if(debug)printf("DEC2\n");}
                            |   REALLIT                                         {sprintf(aux3, "RealLit(%s)", $1); $$ = createNode(strdup(aux3));if(debug)printf("REAL2\n");}
                            |   BOOLLIT                                         {sprintf(aux3, "BoolLit(%s)", $1); $$ = createNode(strdup(aux3));if(debug)printf("BOOL2\n");}
                            |   LPAR error RPAR                                 {hasError=true;if(debug)printf("666\n");}
                            ;


%%



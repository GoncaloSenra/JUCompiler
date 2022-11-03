
%{

    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    #include "STree.h"
    int yylex(void);

    char * aux; 

    void yyerror (const char *s);
%}

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

%define parse.error verbose



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

%union{
    char* id;
    int intlit;
    float reallit;
    struct node * no;
};

%%
Program                     :   CLASS ID LBRACE recPR RBRACE    {$$ = createNode("Program"); $$->child = $4;}                           
                            |   CLASS ID LBRACE RBRACE          {$$ = createNode("Program");}
                            ;

recPR                       :   MethodDecl                      {$$ = $1;}
                            |   FieldDecl                       {$$ = $1;}    
                            |   SEMICOLON                       {;}
                            |   recPR MethodDecl                {$$ = $1; newBrother($$, $2);}
                            |   recPR FieldDecl                 {$$ = $1; newBrother($$, $2);}
                            |   recPR SEMICOLON                 {$$ = $1;}
                            ;

MethodDecl                  :   PUBLIC STATIC MethodHeader MethodBody   {$$ = createNode("MethodDecl"); $$->child = $3; newBrother($3, $4)}
                            ;

FieldDecl                   :   PUBLIC STATIC Type ID recCOMMAID SEMICOLON      {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux, "Id(%s)", $4); newBrother($3, createNode(aux)); newBrother($3, $5);
                                                                                    node * auxnode = $4, auxnode2;
                                                                                    char * var = $3;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode(var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                }
                            |   PUBLIC STATIC Type ID SEMICOLON                 {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux, "Id(%s)", $4); newBrother($3, createNode(aux));}
                            |   error SEMICOLON                                 {;}
                            ;

recCOMMAID                  :   COMMA ID                    {$$ = createNode("FieldDecl"); sprintf(aux, "Id(%s)", $2); $$->child = createNode(aux);}
                            |   recCOMMAID COMMA ID         {$$ = createNode("FieldDecl"); addBrother($$, $1); sprintf(aux, "Id(%s)", $2); $$->child = createNode(aux);}
                            ;

Type                        :   BOOL                                {$$ = createNode("Bool");}
                            |   INT                                 {$$ = createNode("Int");}
                            |   DOUBLE                              {$$ = createNode("Double");}
                            ;

MethodHeader                :   Type ID LPAR FormalParams RPAR      {$$ = createNode("MethodHeader"); $$->child = $1; sprintf(aux, "Id(%s)", $2); addBrother($1, createNode(aux)); addBrother($1, $4);}
                            |   Type ID LPAR RPAR                   {printf("Void\n");}
                            |   VOID ID LPAR FormalParams RPAR      {printf("MethodHeader\n");}
                            |   VOID ID LPAR RPAR                   {printf("MethodHeader\n");}
                            ;

FormalParams                :   Type ID recFP                       {printf("FormalParams\n");}
                            |   Type ID                             {printf("FormalParams\n");}
                            |   STRING LSQ RSQ ID                   {printf("FormalParams\n");}
                            ;

recFP                       :   COMMA Type ID {;}
                            |   recFP COMMA Type ID {;}
                            ;

MethodBody                  :   LBRACE recMD RBRACE                 {printf("MethodBody\n");}
                            |   LBRACE RBRACE                       {printf("MethodBody\n");}
                            ;

recMD                       :   Statement {;}
                            |   VarDecl {;}
                            |   recMD Statement {;}
                            |   recMD VarDecl {;}
                            ;
                        
VarDecl                     :   Type ID recCOMMAID SEMICOLON        {printf("VarDecl\n");}
                            |   Type ID SEMICOLON                   {printf("VarDecl\n");}
                            ;

Statement                   :   LBRACE Statement RBRACE                         {printf("Statement\n");}
                            |   LBRACE RBRACE                                   {printf("Statement\n");}
                            |   IF LPAR Expr RPAR Statement ELSE Statement      {printf("Statement\n");}                            
                            |   IF LPAR Expr RPAR Statement                     {printf("Statement\n");}
                            |   WHILE LPAR Expr RPAR Statement                  {printf("Statement\n");}
                            |   RETURN Expr SEMICOLON                           {printf("Statement\n");}                            
                            |   RETURN SEMICOLON                                {printf("Statement\n");}
                            |   MethodInvocation SEMICOLON                      {printf("Statement\n");}
                            |   Assignment SEMICOLON                            {printf("Statement\n");}
                            |   ParseArgs SEMICOLON                             {printf("Statement\n");}
                            |   SEMICOLON                                       {printf("Statement\n");}                            
                            |   PRINT LPAR Expr RPAR SEMICOLON                  {printf("Statement\n");}
                            |   PRINT LPAR STRLIT RPAR SEMICOLON                {printf("Statement\n");}
                            |   PRINT LPAR RPAR SEMICOLON                       {printf("Statement\n");}                            
                            |   error SEMICOLON                                 {;}
                            ;

MethodInvocation            :   ID LPAR Expr recCOMMAEXP RPAR                            {printf("MethodInvocation\n");}
                            |   ID LPAR RPAR {;}
                            |   ID LPAR error RPAR {;}
                            ;

recCOMMAEXP                 :   COMMA Expr {;}
                            |   recCOMMAEXP COMMA Expr {;}
                            ;

Assignment                  :   ID ASSIGN Expr                          {printf("Assign\n");}
                            ;

ParseArgs                   :   PARSEINT LPAR ID LSQ Expr RSQ RPAR      {printf("ParseArgs\n");}
                            |   PARSEINT LPAR error RPAR {;}
                            ;

Expr                        :   Expr PLUS Expr          {$$ = createNode("Plus"); $$->child=$1; newBrother($1,$3);}
                            |   Expr MINUS Expr         {$$ = createNode("Minus"); $$->child=$1; newBrother($1,$3);}
                            |   Expr STAR Expr          {$$ = createNode("Star"); $$->child=$1; newBrother($1,$3);}
                            |   Expr DIV Expr           {$$ = createNode("Div"); $$->child=$1; newBrother($1,$3);}
                            |   Expr MOD Expr           {$$ = createNode("Mod"); $$->child=$1; newBrother($1,$3);}
                            |   Expr AND Expr           {$$ = createNode("And"); $$->child=$1; newBrother($1,$3);}
                            |   Expr OR Expr            {$$ = createNode("Or"); $$->child=$1; newBrother($1,$3);}
                            |   Expr XOR Expr           {$$ = createNode("Xor"); $$->child=$1; newBrother($1,$3);}
                            |   Expr LSHIFT Expr        {$$ = createNode("Lshift"); $$->child=$1; newBrother($1,$3);}
                            |   Expr RSHIFT Expr        {$$ = createNode("Rshift"); $$->child=$1; newBrother($1,$3);}
                            |   Expr EQ Expr            {$$ = createNode("Eq"); $$->child=$1; newBrother($1,$3);}
                            |   Expr GE Expr            {$$ = createNode("Ge"); $$->child=$1; newBrother($1,$3);}
                            |   Expr GT Expr            {$$ = createNode("Gt"); $$->child=$1; newBrother($1,$3);}
                            |   Expr LE Expr            {$$ = createNode("Le"); $$->child=$1; newBrother($1,$3);}
                            |   Expr LT Expr            {$$ = createNode("Lt"); $$->child=$1; newBrother($1,$3);}
                            |   Expr NE Expr            {$$ = createNode("Ne"); $$->child=$1; newBrother($1,$3);}
                            |   MINUS Expr              {$$ = createNode("Minus"); $$->child=$2;}
                            |   NOT Expr                {$$ = createNode("Not"); $$->child=$2;}
                            |   PLUS Expr               {$$ = createNode("Plus"); $$->child=$2;}
                            |   LPAR Expr RPAR          {$$ = $2;}
                            |   MethodInvocation        {$$ = $1;}
                            |   Assignment              {$$ = createNode("Assign");}
                            |   ParseArgs               {$$ = createNode("ParseArgs");}
                            |   ID                      {sprintf(aux, "Id(%s)", $1); $$ = createNode(aux);}
                            |   ID DOTLENGTH            {$$ = newNode("Call"); sprintf(aux, "Id(%s)", $1); $$->child = newNode(aux); addBrother($$->child,$2);}
                            |   INTLIT                  {sprintf(aux, "IntLit(%s)", $1); $$ = createNode(aux);}
                            |   REALLIT                 {sprintf(aux, "RealLit(%s)", $1); $$ = createNode(aux);}
                            |   BOOLLIT                 {sprintf(aux, "BoolLit(%s)", $1); $$ = createNode(aux);}
                            |   LPAR error RPAR         {;}
                            ;


%%



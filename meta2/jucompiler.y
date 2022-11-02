
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
%token BOOLLIT
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

FieldDecl                   :   PUBLIC STATIC Type ID recCOMMAID SEMICOLON      {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux, "Id(%s)", $4); newBrother($3, createNode(aux)); newBrother($3, $5);}
                            |   PUBLIC STATIC Type ID SEMICOLON                 {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux, "Id(%s)", $4); newBrother($3, createNode(aux));}
                            |   error SEMICOLON                                 {;}
                            ;

recCOMMAID                  :   COMMA ID {$$ = $2;}
                            |   recCOMMAID COMMA ID {;}
                            ;

Type                        :   BOOL                                {printf("Bool\n");}
                            |   INT                                 {printf("Int\n");}
                            |   DOUBLE                              {printf("Double\n");}
                            ;

MethodHeader                :   Type ID LPAR FormalParams RPAR      {printf("Type\n");}
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

Expr                        :   Expr PLUS Expr          {printf("Expr\n");}
                            |   Expr MINUS Expr         {printf("Expr\n");}
                            |   Expr STAR Expr          {printf("Expr\n");}
                            |   Expr DIV Expr           {printf("Expr\n");}
                            |   Expr MOD Expr           {printf("Expr\n");}
                            |   Expr AND Expr           {printf("Expr\n");}
                            |   Expr OR Expr            {printf("Expr\n");}
                            |   Expr XOR Expr           {printf("Expr\n");}
                            |   Expr LSHIFT Expr        {printf("Expr\n");}
                            |   Expr RSHIFT Expr        {printf("Expr\n");}
                            |   Expr EQ Expr            {printf("Expr\n");}
                            |   Expr GE Expr            {printf("Expr\n");}
                            |   Expr GT Expr            {printf("Expr\n");}
                            |   Expr LE Expr            {printf("Expr\n");}
                            |   Expr LT Expr            {printf("Expr\n");}
                            |   Expr NE Expr            {printf("Expr\n");}
                            |   MINUS Expr              {printf("Expr\n");}
                            |   NOT Expr                {printf("Expr\n");}
                            |   PLUS Expr               {printf("Expr\n");}
                            |   LPAR Expr RPAR          {printf("Expr\n");}
                            |   MethodInvocation        {printf("MethodInvocation\n");}
                            |   Assignment              {printf("Assign\n");}
                            |   ParseArgs               {printf("ParseArgs\n");}
                            |   ID                      {printf("Id()\n");}
                            |   ID DOTLENGTH            {printf("Length\n");}
                            |   INTLIT                  {printf("IntLit()\n");}
                            |   REALLIT                 {printf("RealLit()\n");}
                            |   BOOLLIT                 {printf("BoolLit()\n");}
                            |   LPAR error RPAR {;}
                            ;


%%



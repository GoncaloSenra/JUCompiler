
%{

    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    
    int yylex(void);
    void yyerror (const char *s);
    char* yytext;
%}

%{
    /*
%type <node> Program
%type <node> MethodDecl
%type <node> FieldDecl
%type <node> Type
%type <node> MethodHeader
%type <node> FormalParams
%type <node> MethodBody
%type <node> VarDecl
%type <node> Statement
%type <node> MethodInvocation
%type <node> Assignment
%type <node> ParseArgs
%type <node> Expr
    */
%}

%token  <id> ID
%token  <id> INTLIT
%token  <id> STRLIT
%token  <id> REALLIT    /* %token  <reallit> REALLIT*/
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


%%
Program                     :   CLASS ID LBRACE RBRACE         {printf("Program\n");}                           
                            |   Program MethodDecl RBRACE       {printf("Program\n");}
                            |   Program FieldDecl RBRACE        {printf("Program\n");}
                            |   Program SEMICOLON RBRACE        {printf("Program\n");}
                            ;

MethodDecl                  :   PUBLIC STATIC MethodHeader MethodBody   {printf("MethodDecl\n");}
                            ;

FieldDecl                   :   PUBLIC STATIC Type ID SEMICOLON     {printf("FieldDecl\n");}
                            |   FieldDecl COMMA ID SEMICOLON        {printf("FieldDecl\n");}
                            ;

Type                        :   BOOL    {printf("Bool\n");}
                            |   INT     {printf("Int\n");}
                            |   DOUBLE  {printf("Double\n");}
                            ;

MethodHeader                :   Type    {printf("Type\n");}
                            |   VOID    {printf("Void\n");}
                            |   MethodHeader ID LPAR RPAR   {printf("MethodHeader\n");}
                            |   MethodHeader ID LPAR FormalParams RPAR {printf("MethodHeader\n");}
                            ;

FormalParams                :   Type ID {printf("FormalParams\n");}
                            |   FormalParams COMMA Type ID  {printf("FormalParams\n");}
                            |   STRING LSQ RSQ ID   {printf("FormalParams\n");}
                            ;

MethodBody                  :   LBRACE RBRACE   {printf("MethodBody\n");}
                            |   MethodBody Statement RBRACE {printf("MethodBody\n");}
                            |   MethodBody VarDecl RBRACE   {printf("MethodBody\n");}
                            ;
                        
VarDecl                     :   Type ID SEMICOLON   {printf("VarDecl\n");}
                            |   VarDecl COMMA ID SEMICOLON {printf("VarDecl\n");}
                            ;

Statement                   :   LBRACE RBRACE   {printf("Statement\n");}
                            |   Statement RBRACE    {printf("Statement\n");}
                            |   IF LPAR Expr RPAR Statement {printf("Statement\n");}
                            |   IF LPAR Expr RPAR Statement ELSE Statement  {printf("Statement\n");}
                            |   WHILE LPAR Expr RPAR Statement  {printf("Statement\n");}
                            |   RETURN SEMICOLON    {printf("Statement\n");}
                            |   RETURN Expr SEMICOLON   {printf("Statement\n");}
                            |   SEMICOLON   {printf("Statement\n");}
                            |   MethodInvocation SEMICOLON  {printf("Statement\n");}
                            |   Assignment SEMICOLON    {printf("Statement\n");}
                            |   ParseArgs SEMICOLON {printf("Statement\n");}
                            |   PRINT LPAR RPAR SEMICOLON   {printf("Statement\n");}
                            |   PRINT LPAR Expr RPAR SEMICOLON  {printf("Statement\n");}
                            |   PRINT LPAR STRLIT RPAR SEMICOLON    {printf("Statement\n");}
                            ;

MethodInvocation            :   ID LPAR RPAR
                            |   ID LPAR Expr MethodInvocation RPAR
                            |   MethodInvocation COMMA Expr
                            ;

Assignment                  :   ID ASSIGN Expr
                            ;

ParseArgs                   :   PARSEINT LPAR ID LSQ Expr RSQ RPAR
                            ;

Expr                        :   Expr PLUS Expr
                            |   Expr MINUS Expr
                            |   Expr STAR Expr
                            |   Expr DIV Expr
                            |   Expr MOD Expr
                            |   Expr AND Expr
                            |   Expr OR Expr
                            |   Expr XOR Expr
                            |   Expr LSHIFT Expr
                            |   Expr RSHIFT Expr
                            |   Expr EQ Expr
                            |   Expr GE Expr
                            |   Expr GT Expr
                            |   Expr LE Expr
                            |   Expr LT Expr
                            |   Expr NE Expr
                            |   MINUS Expr
                            |   NOT Expr
                            |   PLUS Expr
                            |   LPAR Expr RPAR
                            |   MethodInvocation
                            |   Assignment
                            |   ParseArgs
                            |   ID
                            |   ID DOTLENGTH
                            |   INTLIT                  {printf("INTLIT");}
                            |   REALLIT                 {printf("REALLIT");}
                            |   BOOLLIT                 {printf("BoolLit(%s)", $1);}
                            ;


%%

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
Program                     :   CLASS ID LBRACE RBRACE                                    
                            |   Program MethodDecl RBRACE
                            |   Program FieldDecl RBRACE
                            |   Program SEMICOLON RBRACE
                            ;

MethodDecl                  :   PUBLIC STATIC MethodHeader MethodBody
                            ;

FieldDecl                   :   PUBLIC STATIC Type ID SEMICOLON
                            |   FieldDecl COMMA ID SEMICOLON
                            ;

Type                        :   BOOL
                            |   INT
                            |   DOUBLE
                            ;

MethodHeader                :   Type
                            |   VOID
                            |   MethodHeader ID LPAR RPAR
                            |   MethodHeader ID LPAR FormalParams RPAR 
                            ;

FormalParams                :   Type ID
                            |   FormalParams COMMA Type ID
                            |   STRING LSQ RSQ ID
                            ;

MethodBody                  :   LBRACE RBRACE
                            |   MethodBody Statement RBRACE
                            |   MethodBody VarDecl RBRACE
                            ;
                        
VarDecl                     :   Type ID SEMICOLON
                            |   VarDecl COMMA ID SEMICOLON
                            ;

Statement                   :   LBRACE RBRACE
                            |   Statement RBRACE
                            |   IF LPAR Expr RPAR Statement
                            |   IF LPAR Expr RPAR Statement ELSE Statement
                            |   WHILE LPAR Expr RPAR Statement
                            |   RETURN SEMICOLON
                            |   RETURN Expr SEMICOLON
                            |   SEMICOLON
                            |   MethodInvocation SEMICOLON
                            |   Assignment SEMICOLON
                            |   ParseArgs SEMICOLON
                            |   PRINT LPAR RPAR SEMICOLON
                            |   PRINT LPAR Expr RPAR SEMICOLON
                            |   PRINT LPAR STRLIT RPAR SEMICOLON
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

%{

    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    
    int yylex(void);
    void yyerror (const char *s);
    char* yytext;
%}


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


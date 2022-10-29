
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



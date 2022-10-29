
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

MethodInvocation            :   ID LPAR RPAR                            {printf("MethodInvocation\n");}
                            |   ID LPAR Expr MethodInvocation RPAR      {printf("MethodInvocation\n");}
                            |   MethodInvocation COMMA Expr             {printf("MethodInvocation\n");}
                            ;

Assignment                  :   ID ASSIGN Expr                          {printf("Assign\n");}
                            ;

ParseArgs                   :   PARSEINT LPAR ID LSQ Expr RSQ RPAR      {printf("ParseArgs\n");}
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
                            |   ID                      {printf("Id(%s)\n", $1);}
                            |   ID DOTLENGTH            {printf("Length\n");}
                            |   INTLIT                  {printf("IntLit(%s)\n", $1);}
                            |   REALLIT                 {printf("RealLit(%s)\n", $1);}
                            |   BOOLLIT                 {printf("BoolLit(%s)\n", $1);}
                            ;


%%


int main() {
  yyparse();
  return 0;
}

void yyerror (const char *s) { 
  printf ("%s: %s\n", s, yytext);
}
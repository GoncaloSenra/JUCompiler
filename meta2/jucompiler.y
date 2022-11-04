
%{

    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    #include "STree.h"
    int yylex(void);

    char aux3[1024]; 
    char aux4[1024]; 
    struct node * prog;

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
Program                     :   CLASS ID LBRACE recPR RBRACE                    {$$ = createNode("Program"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3)); newBrother($$->child, $4); printASTree($$, 0); freeASTree($$); printf("Program\n");}                           
                            |   CLASS ID LBRACE RBRACE                          {$$ = createNode("Program"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3));printf("Program2\n");}
                            ;

recPR                       :   MethodDecl                                      {$$ = $1;printf("recPR\n");}
                            |   FieldDecl                                       {$$ = $1;printf("recPR2\n");}    
                            |   SEMICOLON                                       {;printf("recPR3\n");}
                            |   recPR MethodDecl                                {$$ = $1; newBrother($$, $2);printf("recPR4\n");}
                            |   recPR FieldDecl                                 {$$ = $1; newBrother($$, $2);printf("recPR5\n");}
                            |   recPR SEMICOLON                                 {$$ = $1;printf("recPR6\n");}
                            ;

MethodDecl                  :   PUBLIC STATIC MethodHeader MethodBody           {$$ = createNode("MethodDecl"); $$->child = $3; newBrother($3, $4);printf("MethodDecl\n");}
                            ;

FieldDecl                   :   PUBLIC STATIC Type ID recCOMMAID SEMICOLON      {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux3, "Id(%s)", $4); newBrother($3, createNode(strdup(aux3))); newBrother($$, $5);
                                                                                    struct node * auxnode = $5, * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode($3->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    printf("FieldDecl\n");
                                                                                }
                            |   PUBLIC STATIC Type ID SEMICOLON                 {$$ = createNode("FieldDecl"); $$->child = $3; sprintf(aux3, "Id(%s)", $4); newBrother($3, createNode(strdup(aux3)));printf("FieldDecl2\n");}
                            |   error SEMICOLON                                 {;printf("FieldDecl3\n");}
                            ;

recCOMMAID                  :   COMMA ID                                        {$$ = createNode("FieldDecl"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3));printf("recCommaId\n");}
                            |   recCOMMAID COMMA ID                             {$$ = createNode("FieldDecl"); newBrother($$, $1); sprintf(aux3, "Id(%s)", $3); $$->child = createNode(strdup(aux3));printf("recCommaId2\n");}
                            ;           

Type                        :   BOOL                                            {$$ = createNode("Bool");printf("Bool\n");}
                            |   INT                                             {$$ = createNode("Int");printf("Int\n");}
                            |   DOUBLE                                          {$$ = createNode("Double");printf("Double\n");}
                            ;           

MethodHeader                :   Type ID LPAR FormalParams RPAR                  {$$ = createNode("MethodHeader"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3))); newBrother($1, $4);printf("MethodHeader\n");}
                            |   Type ID LPAR RPAR                               {$$ = createNode("MethodHeader"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3)));printf("MethodHeader2\n");}
                            |   VOID ID LPAR FormalParams RPAR                  {$$ = createNode("MethodHeader"); $$->child = createNode("Void"); sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode(strdup(aux3))); newBrother($$->child, $4);printf("MethodHeader3\n");}
                            |   VOID ID LPAR RPAR                               {$$ = createNode("MethodHeader"); $$->child = createNode("Void"); sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode(strdup(aux3)));printf("MethodHeader4\n");}
                            ;           

FormalParams                :   Type ID recFP                                   {$$ = createNode("MethodParams"); $$->child = createNode("ParamDecl"); $$->child->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3))); newBrother($$, $3);
                                                                                    struct node * auxnode = $3, * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode($1->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    printf("FormalParams\n");
                                                                                }
                            |   Type ID                                         {$$ = createNode("MethodParams"); $$->child = createNode("ParamDecl"); $$->child->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3)));printf("FormalParams2\n");}
                            |   STRING LSQ RSQ ID                               {$$ = createNode("MethodParams"); $$->child = createNode("ParamDecl"); $$->child->child = createNode("StringArray"); sprintf(aux3, "Id(%s)", $4); newBrother($$->child->child, createNode(strdup(aux3)));printf("FormalParams3\n");}
                            ;           

recFP                       :   COMMA Type ID                                   {$$ = createNode("ParamDecl"); $$->child = $2; sprintf(aux3, "Id(%s)", $3); newBrother($2, createNode(strdup(aux3)));printf("recFP\n");}
                            |   recFP COMMA Type ID                             {$$ = createNode("ParamDecl"); newBrother($$, $1); $$->child = $3; sprintf(aux3, "Id(%s)", $4); newBrother($3, createNode(strdup(aux3)));printf("recFP2\n");}
                            ;           

MethodBody                  :   LBRACE recMD RBRACE                             {$$ = createNode("MethodBody"); $$->child = $2;printf("MethodBody\n");}
                            |   LBRACE RBRACE                                   {$$ = createNode("MethodBody");printf("MethodBody2\n");}
                            ;           

recMD                       :   Statement                                       {$$ = $1;printf("recMD\n");}
                            |   VarDecl                                         {$$ = $1;printf("recMD2\n");}
                            |   recMD Statement                                 {$$ = $1; newBrother($$, $2);printf("recMD3\n");}
                            |   recMD VarDecl                                   {$$ = $1; newBrother($$, $2);printf("recMD4\n");}
                            ;           

VarDecl                     :   Type ID recVAR SEMICOLON                        {$$ = createNode("VarDecl"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($$->child, createNode(strdup(aux3))); newBrother($$, $3);
                                                                                    struct node * auxnode = $3, * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode($1->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    printf("VarDecl\n");
                                                                                }
                            |   Type ID SEMICOLON                               {$$ = createNode("VarDecl"); $$->child = $1; sprintf(aux3, "Id(%s)", $2); newBrother($1, createNode(strdup(aux3)));printf("VarDecl2\n");}
                            ;           

recVAR                      :   COMMA ID                                        {$$ = createNode("VarDecl"); sprintf(aux3, "Id(%s)", $2); $$->child = createNode(strdup(aux3));printf("recVAR\n");}
                            |   recVAR COMMA ID                                 {$$ = createNode("VarDecl"); newBrother($$, $1); sprintf(aux3, "Id(%s)", $3); $$->child = createNode(strdup(aux3));printf("recVAR2\n");}
                            ;                            

Statement                   :   LBRACE Statement RBRACE                         {$$ = $2;printf("Statement\n");}
                            |   LBRACE RBRACE                                   {;printf("Statement2\n");}
                            |   IF LPAR Expr RPAR Statement ELSE Statement      {$$ = createNode("If"); $$->child = $3; newBrother($3, $5); newBrother($5, createNode("Block")); newBrother($5, $7);printf("Statement3\n");}                            
                            |   IF LPAR Expr RPAR Statement                     {$$ = createNode("If"); $$->child = $3; newBrother($3, $5); newBrother($5, createNode("Block"));printf("Statement4\n");}
                            |   WHILE LPAR Expr RPAR Statement                  {$$ = createNode("While"); $$->child = $3; newBrother($3, $5);printf("Statement5\n");}
                            |   RETURN Expr SEMICOLON                           {$$ = createNode("Return"); $$->child = $2;printf("Statement6\n");}                            
                            |   RETURN SEMICOLON                                {$$ = createNode("Return");printf("Statement7\n");}
                            |   MethodInvocation SEMICOLON                      {$$ = $1;printf("Statement8\n");}
                            |   Assignment SEMICOLON                            {$$ = $1;printf("Statement9\n");}
                            |   ParseArgs SEMICOLON                             {$$ = $1;printf("Statement10\n");}
                            |   SEMICOLON                                       {;printf("Statement11\n");}                            
                            |   PRINT LPAR Expr RPAR SEMICOLON                  {$$ = createNode("Print"); $$->child = $3;printf("Statement12\n");}
                            |   PRINT LPAR STRLIT RPAR SEMICOLON                {$$ = createNode("Print"); sprintf(aux3, "StrLit(\"%s\")", $3); $$->child = createNode(strdup(aux3));printf("Statement13\n");}
                            |   PRINT LPAR RPAR SEMICOLON                       {$$ = createNode("Print");printf("Statement14\n");}                            
                            |   error SEMICOLON                                 {;printf("Statement15\n");}
                            ;

MethodInvocation            :   ID LPAR Expr recCOMMAEXP RPAR                   {$$ = createNode("Call"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3)); newBrother($$->child, $3); newBrother($3, $4);printf("MethodInvocation\n");}
                            |   ID LPAR RPAR                                    {$$ = createNode("Call"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3));printf("MethodInvocation2\n");}
                            |   ID LPAR error RPAR                              {;printf("MethodInvocation3\n");}
                            ;

recCOMMAEXP                 :   recCOMMAEXP COMMA Expr                          {$$ = $1; newBrother($1, $3);printf("recCOMMAEXP\n");}
                            |                                                   {$$ = NULL;printf("recCOMMAEXP2\n");}
                            ;

Assignment                  :   ID ASSIGN Expr                                  {$$ = createNode("Assign"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3)); newBrother($$->child, $3);printf("Assign\n");}
                            ;

ParseArgs                   :   PARSEINT LPAR ID LSQ Expr RSQ RPAR              {$$ = createNode("ParseArgs"); sprintf(aux3, "Id(%s)", $3); $$->child = createNode(strdup(aux3)); newBrother($$->child, $5);printf("ParseArgs\n");}
                            |   PARSEINT LPAR error RPAR                        {$$ = NULL;printf("ParseArgs2\n");}
                            ;

Expr                        :   Expr PLUS Expr                                  {$$ = createNode("Plus"); $$->child=$1; newBrother($1,$3);printf("PLUS\n");}
                            |   Expr MINUS Expr                                 {$$ = createNode("Sub"); $$->child=$1; newBrother($1,$3);printf("MINUS\n");}
                            |   Expr STAR Expr                                  {$$ = createNode("Mul"); $$->child=$1; newBrother($1,$3);printf("STAR\n");}
                            |   Expr DIV Expr                                   {$$ = createNode("Div"); $$->child=$1; newBrother($1,$3);printf("DIV\n");}
                            |   Expr MOD Expr                                   {$$ = createNode("Mod"); $$->child=$1; newBrother($1,$3);printf("MOD\n");}
                            |   Expr AND Expr                                   {$$ = createNode("And"); $$->child=$1; newBrother($1,$3);printf("AND\n");}
                            |   Expr OR Expr                                    {$$ = createNode("Or"); $$->child=$1; newBrother($1,$3);printf("OR\n");}
                            |   Expr XOR Expr                                   {$$ = createNode("Xor"); $$->child=$1; newBrother($1,$3);printf("XOR\n");}
                            |   Expr LSHIFT Expr                                {$$ = createNode("Lshift"); $$->child=$1; newBrother($1,$3);printf("LSHIFT\n");}
                            |   Expr RSHIFT Expr                                {$$ = createNode("Rshift"); $$->child=$1; newBrother($1,$3);printf("RSHIFT\n");}
                            |   Expr EQ Expr                                    {$$ = createNode("Eq"); $$->child=$1; newBrother($1,$3);printf("EQ\n");}
                            |   Expr GE Expr                                    {$$ = createNode("Ge"); $$->child=$1; newBrother($1,$3);printf("GE\n");}
                            |   Expr GT Expr                                    {$$ = createNode("Gt"); $$->child=$1; newBrother($1,$3);printf("GT\n");}
                            |   Expr LE Expr                                    {$$ = createNode("Le"); $$->child=$1; newBrother($1,$3);printf("LE\n");}
                            |   Expr LT Expr                                    {$$ = createNode("Lt"); $$->child=$1; newBrother($1,$3);printf("LT\n");}
                            |   Expr NE Expr                                    {$$ = createNode("Ne"); $$->child=$1; newBrother($1,$3);printf("NE\n");}
                            |   MINUS Expr                                      {$$ = createNode("Minus"); $$->child=$2;printf("MINUS2\n");}
                            |   NOT Expr                                        {$$ = createNode("Not"); $$->child=$2;printf("NOT\n");}
                            |   PLUS Expr                                       {$$ = createNode("Plus"); $$->child=$2;printf("PLUS2\n");}
                            |   LPAR Expr RPAR                                  {$$ = $2;printf("EXPR\n");}
                            |   MethodInvocation                                {$$ = $1;printf("MI\n");}
                            |   Assignment                                      {$$ = $1;printf("ASS\n");}
                            |   ParseArgs                                       {$$ = $1;printf("PA\n");}
                            |   ID                                              {sprintf(aux3, "Id(%s)", $1); $$ = createNode(strdup(aux3));printf("ID111\n");}
                            |   ID DOTLENGTH                                    {$$ = createNode("Length"); sprintf(aux3, "Id(%s)", $1); $$->child = createNode(strdup(aux3));printf("DOT\n");}
                            |   INTLIT                                          {sprintf(aux3, "DecLit(%s)", $1); $$ = createNode(strdup(aux3));printf("DEC2\n");}
                            |   REALLIT                                         {sprintf(aux3, "RealLit(%s)", $1); $$ = createNode(strdup(aux3));printf("REAL2\n");}
                            |   BOOLLIT                                         {sprintf(aux3, "BoolLit(%s)", $1); $$ = createNode(strdup(aux3));printf("BOOL2\n");}
                            |   LPAR error RPAR                                 {;printf("666\n");}
                            ;


%%



%{
    //Gonçalo Senra 2020213750
    //Henrique Costa 2020214120
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #include "y.tab.h"
    
    #include "SymTable.h"

    int yyparse(void);

    int printTree;

    int line = 1;
    int col = 1;
    int aux = 0;

    extern struct node * prog;
    extern int error;

    int yacc;
    int lexicalError = 0;

    int auxline=0;
    int auxcol=0;
%}

INTLIT3     ([1-9][0-9]*)|([1-9]("_"|[0-9])*[0-9])|0
INTLIT4     ([0-9][0-9]*)|([0-9]("_"|[0-9])*[0-9])|0

VALIDESCAPES ("\\"("n"|"r"|"t"|"f"|"\""|"\\"))

RESERVED_WORDS  ("abstract"|"continue"|"switch"|"assert"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"++"|"--"|"null"|"Integer"|"System"|"break"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"protected"|"short"|"strictfp"|"super"|"this"|"throw"|"throws"|"transient"|"try"|"volatile")

BOOLLIT                 ("true"|"false")  
AND                     "&&"              
ASSIGN                  "="               
STAR                    "*"               
COMMA                   ","               
DIV                     "/"               
EQ                      "=="              
GE                      ">="              
GT                      ">"               
LBRACE                  "{"
LE                      "<="              
LPAR                    "("               
LSQ                     "["               
LT                      "<"               
MINUS                   "-"               
MOD                     "%"               
NE                      "!="              
NOT                     "!"               
OR                      "||"              
PLUS                    "+"               
RBRACE                  "}"               
RPAR                    ")"               
RSQ                     "]"               
SEMICOLON               ";"               
ARROW                   "->"              
LSHIFT                  "<<"              
RSHIFT                  ">>"              
XOR                     "^"               
BOOL                    "boolean"         
CLASS                   "class"           
DOTLENGTH               ".length"         
DOUBLE                  "double"          
ELSE                    "else"            
IF                      "if"              
INT                     "int"             
PRINT                   "System.out.print"
PARSEINT                "Integer.parseInt"
PUBLIC                  "public"          
RETURN                  "return"          
STATIC                  "static"          
STRING                  "String"          
VOID                    "void"            
WHILE                   "while"
INTLIT                  {INTLIT3}
REALLIT                 {INTLIT4}((e|E)("+"|"-")?{INTLIT4}+)|{INTLIT4}(("."{INTLIT4}?)((e|E)("+"|"-")?{INTLIT4}+)?)|{INTLIT4}?(("."{INTLIT4})((e|E)("+"|"-")?{INTLIT4}+)?)
RESERVED                {RESERVED_WORDS}
ID                      ([a-z]|[A-Z]|"_"|"$")([a-z]|[A-Z]|"$"|"_"|[0-9])*
STRLIT                  ([^\\\r\n\"]|{VALIDESCAPES})*"\""

%X COMMENT
%X COMMENT2
%X STRING1
%X STRING2


%%
                          
"/*"                        {auxline = line; auxcol= col;BEGIN COMMENT;col += yyleng;}
<COMMENT>"\n"|"\r"|"\r\n"   {line++;col =1;}
<COMMENT>.                  {col += yyleng;}
<COMMENT><<EOF>>            {col += yyleng;printf("Line %d, col %d: unterminated comment\n", auxline, auxcol);yyterminate();}
<COMMENT>"*/"               {BEGIN 0;col += yyleng;}

"//"                                          {BEGIN COMMENT2;col += yyleng;}
<COMMENT2>[^\n\r]*("\n"|"\r"|"\r\n")          {;col = 1;line++;BEGIN 0;}
<COMMENT2>[^\n\r]*                            {;}

"\""                                                                    {auxline = line; auxcol= col;BEGIN STRING1;col += yyleng;}
<STRING1>([^\\\r\n\"]|{VALIDESCAPES})*(\\)([^nftr\\\r\n"])               {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-2, &yytext[yyleng-2]);BEGIN STRING2;}
<STRING1>([^\\\r\n\"]|{VALIDESCAPES})*(\\)                               {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-1, &yytext[yyleng-1]);BEGIN STRING2;}
<STRING1>{STRLIT}                                                        {if(aux == 0) printf("STRLIT(\"%s)\n", yytext);col+=yyleng;BEGIN 0;if(yacc == 0){yylval.id = strdup(yytext);return STRLIT;}}
<STRING1>([^\\\r\n\"]|{VALIDESCAPES})*("\n"|"\r"|"\r\n")                 {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);col = 1;line++;BEGIN 0;}
<STRING1>.                                                               {;}
<STRING1><<EOF>>                                                         {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);yyterminate();}

<STRING2>("\n"|"\r"|"\r\n")                  {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);col = 1;line++;BEGIN 0;}
<STRING2>(\\)([^nftr\\\r\n"])                {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-2, &yytext[yyleng-2]);}
<STRING2>(\\)                                {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-1, &yytext[yyleng-1]);}
<STRING2>"\""                                {col += yyleng; BEGIN 0;}
<STRING2>([^\\\r\n\"]|{VALIDESCAPES})*       {col += yyleng;}
<STRING2><<EOF>>                             {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);yyterminate();}


{BOOLLIT}           {if(aux == 0) printf("BOOLLIT(%s)\n", yytext);col += yyleng;if(yacc == 0){yylval.id = strdup(yytext); return BOOLLIT;}}
{AND}               {if(aux == 0) printf("AND\n");col += yyleng;if(yacc == 0) return AND;}
{ASSIGN}            {if(aux == 0) printf("ASSIGN\n");col += yyleng;if(yacc == 0) return ASSIGN;}
{STAR}              {if(aux == 0) printf("STAR\n");col += yyleng;if(yacc == 0) return STAR;}
{COMMA}             {if(aux == 0) printf("COMMA\n");col += yyleng;if(yacc == 0) return COMMA;}
{DIV}               {if(aux == 0) printf("DIV\n");col += yyleng;if(yacc == 0) return DIV;}
{EQ}                {if(aux == 0) printf("EQ\n");col += yyleng;if(yacc == 0) return EQ;}        
{GE}                {if(aux == 0) printf("GE\n");col += yyleng;if(yacc == 0) return GE;}
{GT}                {if(aux == 0) printf("GT\n");col += yyleng;if(yacc == 0) return GT;}
{LBRACE}            {if(aux == 0) printf("LBRACE\n");col += yyleng;if(yacc == 0) return LBRACE;}
{LE}                {if(aux == 0) printf("LE\n");col += yyleng;if(yacc == 0) return LE;}
{LPAR}              {if(aux == 0) printf("LPAR\n");col += yyleng;if(yacc == 0) return LPAR;}
{LSQ}               {if(aux == 0) printf("LSQ\n");col += yyleng;if(yacc == 0) return LSQ;}
{LT}                {if(aux == 0) printf("LT\n");col += yyleng;if(yacc == 0) return LT;}
{MINUS}             {if(aux == 0) printf("MINUS\n");col += yyleng;if(yacc == 0) return MINUS;}
{MOD}               {if(aux == 0) printf("MOD\n");col += yyleng;if(yacc == 0) return MOD;}
{NE}                {if(aux == 0) printf("NE\n");col += yyleng;if(yacc == 0) return NE;}
{NOT}               {if(aux == 0) printf("NOT\n");col += yyleng;if(yacc == 0) return NOT;}
{OR}                {if(aux == 0) printf("OR\n");col += yyleng;if(yacc == 0) return OR;}
{PLUS}              {if(aux == 0) printf("PLUS\n");col += yyleng;if(yacc == 0) return PLUS;}
{RBRACE}            {if(aux == 0) printf("RBRACE\n");col += yyleng;if(yacc == 0) return RBRACE;}
{RPAR}              {if(aux == 0) printf("RPAR\n");col += yyleng;if(yacc == 0) return RPAR;}
{RSQ}               {if(aux == 0) printf("RSQ\n");col += yyleng;if(yacc == 0) return RSQ;}
{SEMICOLON}         {if(aux == 0) printf("SEMICOLON\n");col += yyleng;if(yacc == 0) return SEMICOLON;}
{ARROW}             {if(aux == 0) printf("ARROW\n");col += yyleng;if(yacc == 0) return ARROW;}
{LSHIFT}            {if(aux == 0) printf("LSHIFT\n");col += yyleng;if(yacc == 0) return LSHIFT;}
{RSHIFT}            {if(aux == 0) printf("RSHIFT\n");col += yyleng;if(yacc == 0) return RSHIFT;}
{XOR}               {if(aux == 0) printf("XOR\n");col += yyleng;if(yacc == 0) return XOR;}
{BOOL}              {if(aux == 0) printf("BOOL\n");col += yyleng;if(yacc == 0) return BOOL;}
{CLASS}             {if(aux == 0) printf("CLASS\n");col += yyleng;if(yacc == 0) return CLASS;}
{DOTLENGTH}         {if(aux == 0) printf("DOTLENGTH\n");col += yyleng;if(yacc == 0) return DOTLENGTH;}
{DOUBLE}            {if(aux == 0) printf("DOUBLE\n");col += yyleng;if(yacc == 0) return DOUBLE;}
{ELSE}              {if(aux == 0) printf("ELSE\n");col += yyleng;if(yacc == 0) return ELSE;}
{IF}                {if(aux == 0) printf("IF\n");col += yyleng;if(yacc == 0) return IF;}
{INT}               {if(aux == 0) printf("INT\n");col += yyleng;if(yacc == 0) return INT;}
{PRINT}             {if(aux == 0) printf("PRINT\n");col += yyleng;if(yacc == 0) return PRINT;}
{PARSEINT}          {if(aux == 0) printf("PARSEINT\n");col += yyleng;if(yacc == 0) return PARSEINT;}
{PUBLIC}            {if(aux == 0) printf("PUBLIC\n");col += yyleng;if(yacc == 0) return PUBLIC;}
{RETURN}            {if(aux == 0) printf("RETURN\n");col += yyleng;if(yacc == 0) return RETURN;}
{STATIC}            {if(aux == 0) printf("STATIC\n");col += yyleng;if(yacc == 0) return STATIC;}
{STRING}            {if(aux == 0) printf("STRING\n");col += yyleng;if(yacc == 0) return STRING;}
{VOID}              {if(aux == 0) printf("VOID\n");col += yyleng;if(yacc == 0) return VOID;}
{WHILE}             {if(aux == 0) printf("WHILE\n");col += yyleng;if(yacc == 0) return WHILE;}
{INTLIT}            {if(aux == 0) printf("INTLIT(%s)\n", yytext);col += yyleng;if(yacc == 0){yylval.id = strdup(yytext);return INTLIT;}} 
{REALLIT}           {if(aux == 0) printf("REALLIT(%s)\n", yytext);col += yyleng;if(yacc == 0){yylval.id = strdup(yytext);return REALLIT;}}    

{RESERVED}          {if(aux == 0) printf("RESERVED(%s)\n", yytext);col += yyleng;if(yacc == 0){yylval.id = strdup(yytext);return RESERVED;}}
{ID}                {if(aux == 0) printf("ID(%s)\n", yytext);col += yyleng;if(yacc == 0){yylval.id = strdup(yytext);return ID;} }

(" "|"\t"|"\f")             {;col += yyleng;}
("\n"|"\r\n"|"\r")          {line++;col = 1;}
.                           {printf("Line %d, col %d: illegal character (%s)\n", line, col, &yytext[yyleng-1]);col += yyleng;}

<<EOF>>                     {col += yyleng; yyterminate();}

%%


    
int main(int argc, char * argv[])
{
    
    if (argc == 1) {
        aux = 1;
        yacc = 0;
        yyparse();
    } else if (argc == 2) {
        if (strcmp(argv[1], "-l") == 0){
            aux = 0;
            yacc = 1;
            yylex();
        }else if (strcmp(argv[1], "-e1") == 0){
            aux = 1;
            yacc = 0;
            yylex();
        }else if (strcmp(argv[1], "-t") == 0){
            aux = 1;
            yacc = 0;
            yyparse();
            if (lexicalError != 1)
                if (error==false){
                    printSTree(prog,0);
                } else{
                    freeSTree(prog);
                }
        }else if (strcmp(argv[1], "-e2") == 0){
            aux = 1;
            yacc = 0;
            yyparse();
        }else if (strcmp(argv[1], "-s") == 0){
            aux = 1;
            yacc = 0;
            yyparse();
            if (lexicalError != 1) {
                Sym * table = createSym(prog->child->value, "", "", 0, 0, 0);
                createTable(table, prog);
                printTable(table);
                if (error==false){
                    //printSTree(prog,0);
                } else{
                    freeSTree(prog);
                }
            }
        }
    }
    

    return 0;
}

int yywrap()
{
    return 1;
}

void yyerror (char *s) { 
    lexicalError = 1;

	char straux[yyleng+1];
	strcpy(straux, yytext-1);
	if(col-yyleng == 0){
		col++;
	}
	if (strcmp(yytext, "\n") != 0) {
		if(yytext[yyleng-1] == '\"' && straux[0] == '\"')
			printf ("Line %d, col %d: %s: %s\n", line, col-yyleng-1, s, yytext-1);
		else
			printf ("Line %d, col %d: %s: %s\n", line, col-yyleng, s, yytext);
	}
	else {
        printf ("Line %d, col %d: %s: %s\n", line, col, s, yytext); 
	}
}
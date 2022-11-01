%{
    //Gonçalo Senra 2020213750
    //Henrique Costa 2020214120
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int yyparse(void);

    int line = 1;
    int col = 1;
    int aux = 0;

    int auxline=0;
    int auxcol=0;
%}

INTLIT3     ([1-9][0-9]*)|([1-9]("_"|[0-9])*[0-9])|0
INTLIT4     ([0-9][0-9]*)|([0-9]("_"|[0-9])*[0-9])|0

VALIDESCAPES ("\\"("n"|"r"|"t"|"f"|"\""|"\\"))

RESERVED_WORDS  ("abstract"|"continue"|"switch"|"assert"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"++"|"--"|"null"|"Integer"|"System"|"break"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"protected"|"short"|"strictfp"|"super"|"this"|"throw"|"throws"|"transient"|"try"|"volatile")

%X COMMENT
%X COMMENT2
%X STRING
%X STRING2


%%
                          
"/*"                        {auxline = line; auxcol= col;BEGIN COMMENT;col += yyleng;}
<COMMENT>"\n"|"\r"|"\r\n"   {line++;col =1;}
<COMMENT>.                  {col += yyleng;}
<COMMENT><<EOF>>            {col += yyleng;printf("Line %d, col %d: unterminated comment\n", auxline, auxcol);BEGIN 0;}
<COMMENT>"*/"               {BEGIN 0;col += yyleng;}

"//"                                          {BEGIN COMMENT2;col += yyleng;}
<COMMENT2>[^\n\r]*("\n"|"\r"|"\r\n")          {;col = 1;line++;BEGIN 0;}
<COMMENT2>[^\n\r]*                            {;}

"\""                                                                    {auxline = line; auxcol= col;BEGIN STRING;col += yyleng;}
<STRING>([^\\\r\n\"]|{VALIDESCAPES})*(\\)([^nftr\\\r\n"])               {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-2, &yytext[yyleng-2]);BEGIN STRING2;}
<STRING>([^\\\r\n\"]|{VALIDESCAPES})*(\\)                               {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-1, &yytext[yyleng-1]);BEGIN STRING2;}
<STRING>([^\\\r\n\"]|{VALIDESCAPES})*"\""                               {if(aux == 0) printf("STRLIT(\"%s)\n", yytext);col+=yyleng;BEGIN 0;return STRLIT;}
<STRING>([^\\\r\n\"]|{VALIDESCAPES})*("\n"|"\r"|"\r\n")                 {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);col = 1;line++;BEGIN 0;}
<STRING>.                                                               {;}
<STRING><<EOF>>                                                         {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);BEGIN 0;}

<STRING2>("\n"|"\r"|"\r\n")                  {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);col = 1;line++;BEGIN 0;}
<STRING2>(\\)([^nftr\\\r\n"])                {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-2, &yytext[yyleng-2]);}
<STRING2>(\\)                                {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-1, &yytext[yyleng-1]);}
<STRING2>"\""                                {col += yyleng; BEGIN 0;}
<STRING2>([^\\\r\n\"]|{VALIDESCAPES})*       {col += yyleng;}
<STRING2><<EOF>>                             {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);BEGIN 0;}


("true"|"false")            {if(aux == 0) printf("BOOLLIT(%s)\n", yytext);col += yyleng;return BOOLLIT;}
"&&"                        {if(aux == 0) printf("AND\n");col += yyleng;return AND;}
"="                         {if(aux == 0) printf("ASSIGN\n");col += yyleng;return ASSIGN;}
"*"                         {if(aux == 0) printf("STAR\n");col += yyleng;return STAR;}
","                         {if(aux == 0) printf("COMMA\n");col += yyleng;return COMMA;}
"/"                         {if(aux == 0) printf("DIV\n");col += yyleng;return DIV;}
"=="                        {if(aux == 0) printf("EQ\n");col += yyleng;return EQ;}        
">="                        {if(aux == 0) printf("GE\n");col += yyleng;return GE;}
">"                         {if(aux == 0) printf("GT\n");col += yyleng;return GT;}
"{"                         {if(aux == 0) printf("LBRACE\n");col += yyleng;return LBRACE;}
"<="                        {if(aux == 0) printf("LE\n");col += yyleng;return LE;}
"("                         {if(aux == 0) printf("LPAR\n");col += yyleng;return LPAR;}
"["                         {if(aux == 0) printf("LSQ\n");col += yyleng;return LSQ;}
"<"                         {if(aux == 0) printf("LT\n");col += yyleng;return LT;}
"-"                         {if(aux == 0) printf("MINUS\n");col += yyleng;return MINUS;}
"%"                         {if(aux == 0) printf("MOD\n");col += yyleng;return MOD;}
"!="                        {if(aux == 0) printf("NE\n");col += yyleng;return NE;}
"!"                         {if(aux == 0) printf("NOT\n");col += yyleng;return NOT;}
"||"                        {if(aux == 0) printf("OR\n");col += yyleng;return OR;}
"+"                         {if(aux == 0) printf("PLUS\n");col += yyleng;return PLUS;}
"}"                         {if(aux == 0) printf("RBRACE\n");col += yyleng;return RBRACE;}
")"                         {if(aux == 0) printf("RPAR\n");col += yyleng;return RPAR;}
"]"                         {if(aux == 0) printf("RSQ\n");col += yyleng;return RSQ;}
";"                         {if(aux == 0) printf("SEMICOLON\n");col += yyleng;return SEMICOLON;}
"->"                        {if(aux == 0) printf("ARROW\n");col += yyleng;return ARROW;}
"<<"                        {if(aux == 0) printf("LSHIFT\n");col += yyleng;return LSHIFT;}
">>"                        {if(aux == 0) printf("RSHIFT\n");col += yyleng;return RSHIFT;}
"^"                         {if(aux == 0) printf("XOR\n");col += yyleng;return XOR;}
"boolean"                   {if(aux == 0) printf("BOOL\n");col += yyleng;return BOOL;}
"class"                     {if(aux == 0) printf("CLASS\n");col += yyleng;return CLASS;}
".length"                   {if(aux == 0) printf("DOTLENGTH\n");col += yyleng;return DOTLENGTH;}
"double"                    {if(aux == 0) printf("DOUBLE\n");col += yyleng;return DOUBLE;}
"else"                      {if(aux == 0) printf("ELSE\n");col += yyleng;return ELSE;}
"if"                        {if(aux == 0) printf("IF\n");col += yyleng;return IF;}
"int"                       {if(aux == 0) printf("INT\n");col += yyleng;return INT;}
"System.out.print"          {if(aux == 0) printf("PRINT\n");col += yyleng;return PRINT;}
"Integer.parseInt"          {if(aux == 0) printf("PARSEINT\n");col += yyleng;return PARSEINT;}
"public"                    {if(aux == 0) printf("PUBLIC\n");col += yyleng;return PUBLIC;}
"return"                    {if(aux == 0) printf("RETURN\n");col += yyleng;return RETURN;}
"static"                    {if(aux == 0) printf("STATIC\n");col += yyleng;return STATIC;}
"String"                    {if(aux == 0) printf("STRING\n");col += yyleng;return STRING;}
"void"                      {if(aux == 0) printf("VOID\n");col += yyleng;return VOID;}
"while"                     {if(aux == 0) printf("WHILE\n");col += yyleng;return WHILE;}
{INTLIT3}                                                           {if(aux == 0) printf("INTLIT(%s)\n", yytext);col += yyleng;return INTLIT;} 
{INTLIT4}((e|E)("+"|"-")?{INTLIT4}+)|{INTLIT4}(("."{INTLIT4}?)((e|E)("+"|"-")?{INTLIT4}+)?)|{INTLIT4}?(("."{INTLIT4})((e|E)("+"|"-")?{INTLIT4}+)?)            {if(aux == 0) printf("REALLIT(%s)\n", yytext);col += yyleng;return REALLIT;}    

{RESERVED_WORDS}                                                    {if(aux == 0) printf("RESERVED(%s)\n", yytext);col += yyleng;return RESERVED;}
([a-z]|[A-Z]|"_"|"$")([a-z]|[A-Z]|"$"|"_"|[0-9])*                   {if(aux == 0) printf("ID(%s)\n", yytext);col += yyleng;return ID;}

(" "|"\t"|"\f")             {;col += yyleng;}
("\n"|"\r\n"|"\r")          {line++;col = 1;}
.                           {printf("Line %d, col %d: illegal character (%s)\n", line, col, &yytext[yyleng-1]);col += yyleng;}

%%


    
int main(int argc, char * argv[])
{
    
    if (argc == 2) {
        if (strcmp(argv[1], "-l") == 0)
            aux = 0;
        else if (strcmp(argv[1], "-e1") == 0)
            aux = 1;
    }
    
    yylex();
    
    int val = yyparse();

    printf("--->%d\n", val);
    return 0;
}

int yywrap()
{
    return 1;
}

void yyerror (char *s)
{
    printf ("%s\n", s);
}
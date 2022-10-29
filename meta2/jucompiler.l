%{
    //Gonçalo Senra 2020213750
    //Henrique Costa 2020214120
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

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
<STRING>([^\\\r\n\"]|{VALIDESCAPES})*"\""                               {if(aux == 0) printf("STRLIT(\"%s)\n", yytext);col+=yyleng;BEGIN 0;}
<STRING>([^\\\r\n\"]|{VALIDESCAPES})*("\n"|"\r"|"\r\n")                 {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);col = 1;line++;BEGIN 0;}
<STRING>.                                                               {;}
<STRING><<EOF>>                                                         {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);BEGIN 0;}

<STRING2>("\n"|"\r"|"\r\n")                  {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);col = 1;line++;BEGIN 0;}
<STRING2>(\\)([^nftr\\\r\n"])                {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-2, &yytext[yyleng-2]);}
<STRING2>(\\)                                {col += yyleng;printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col-1, &yytext[yyleng-1]);}
<STRING2>"\""                                {col += yyleng; BEGIN 0;}
<STRING2>([^\\\r\n\"]|{VALIDESCAPES})*       {col += yyleng;}
<STRING2><<EOF>>                             {col += yyleng;printf("Line %d, col %d: unterminated string literal\n", auxline, auxcol);BEGIN 0;}


("true"|"false")            {if(aux == 0) printf("BOOLLIT(%s)\n", yytext);col += yyleng;}
"&&"                        {if(aux == 0) printf("AND\n");col += yyleng;}
"="                         {if(aux == 0) printf("ASSIGN\n");col += yyleng;}
"*"                         {if(aux == 0) printf("STAR\n");col += yyleng;}
","                         {if(aux == 0) printf("COMMA\n");col += yyleng;}
"/"                         {if(aux == 0) printf("DIV\n");col += yyleng;}
"=="                        {if(aux == 0) printf("EQ\n");col += yyleng;}        
">="                        {if(aux == 0) printf("GE\n");col += yyleng;}
">"                         {if(aux == 0) printf("GT\n");col += yyleng;}
"{"                         {if(aux == 0) printf("LBRACE\n");col += yyleng;}
"<="                        {if(aux == 0) printf("LE\n");col += yyleng;}
"("                         {if(aux == 0) printf("LPAR\n");col += yyleng;}
"["                         {if(aux == 0) printf("LSQ\n");col += yyleng;}
"<"                         {if(aux == 0) printf("LT\n");col += yyleng;}
"-"                         {if(aux == 0) printf("MINUS\n");col += yyleng;}
"%"                         {if(aux == 0) printf("MOD\n");col += yyleng;}
"!="                        {if(aux == 0) printf("NE\n");col += yyleng;}
"!"                         {if(aux == 0) printf("NOT\n");col += yyleng;}
"||"                        {if(aux == 0) printf("OR\n");col += yyleng;}
"+"                         {if(aux == 0) printf("PLUS\n");col += yyleng;}
"}"                         {if(aux == 0) printf("RBRACE\n");col += yyleng;}
")"                         {if(aux == 0) printf("RPAR\n");col += yyleng;}
"]"                         {if(aux == 0) printf("RSQ\n");col += yyleng;}
";"                         {if(aux == 0) printf("SEMICOLON\n");col += yyleng;}
"->"                        {if(aux == 0) printf("ARROW\n");col += yyleng;}
"<<"                        {if(aux == 0) printf("LSHIFT\n");col += yyleng;}
">>"                        {if(aux == 0) printf("RSHIFT\n");col += yyleng;}
"^"                         {if(aux == 0) printf("XOR\n");col += yyleng;}
"boolean"                   {if(aux == 0) printf("BOOL\n");col += yyleng;}
"class"                     {if(aux == 0) printf("CLASS\n");col += yyleng;}
".length"                   {if(aux == 0) printf("DOTLENGTH\n");col += yyleng;}
"double"                    {if(aux == 0) printf("DOUBLE\n");col += yyleng;}
"else"                      {if(aux == 0) printf("ELSE\n");col += yyleng;}
"if"                        {if(aux == 0) printf("IF\n");col += yyleng;}
"int"                       {if(aux == 0) printf("INT\n");col += yyleng;}
"System.out.print"          {if(aux == 0) printf("PRINT\n");col += yyleng;}
"Integer.parseInt"          {if(aux == 0) printf("PARSEINT\n");col += yyleng;}
"public"                    {if(aux == 0) printf("PUBLIC\n");col += yyleng;}
"return"                    {if(aux == 0) printf("RETURN\n");col += yyleng;}
"static"                    {if(aux == 0) printf("STATIC\n");col += yyleng;}
"String"                    {if(aux == 0) printf("STRING\n");col += yyleng;}
"void"                      {if(aux == 0) printf("VOID\n");col += yyleng;}
"while"                     {if(aux == 0) printf("WHILE\n");col += yyleng;}
{INTLIT3}                                                           {if(aux == 0) printf("INTLIT(%s)\n", yytext);col += yyleng;} 
{INTLIT4}((e|E)("+"|"-")?{INTLIT4}+)|{INTLIT4}(("."{INTLIT4}?)((e|E)("+"|"-")?{INTLIT4}+)?)|{INTLIT4}?(("."{INTLIT4})((e|E)("+"|"-")?{INTLIT4}+)?)            {if(aux == 0) printf("REALLIT(%s)\n", yytext);col += yyleng;}    

{RESERVED_WORDS}                                                    {if(aux == 0) printf("RESERVED(%s)\n", yytext);col += yyleng;}
([a-z]|[A-Z]|"_"|"$")([a-z]|[A-Z]|"$"|"_"|[0-9])*                   {if(aux == 0) printf("ID(%s)\n", yytext);col += yyleng;}

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
    return 0;
}

int yywrap()
{
    return 1;
}
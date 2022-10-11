%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int line = 1;
    int col = 1;
    int aux = 0;
%}

INTLIT      ([0-9]([0-9]|"_")*[0-9])|[0-9]
VALIDESCAPES ()

%X COMMENT
%X STRING

%%
                          
"/*"                        {BEGIN COMMENT;col += yyleng;}
<COMMENT>.|"\n"             {;col += yyleng;}
<COMMENT><<EOF>>            {printf("Line <%d>, col <%d>: unterminated comment\n", line, col);BEGIN 0;col += yyleng;}
<COMMENT>"*/"               {BEGIN 0;col += yyleng;}



"\""                        {BEGIN STRING;col += yyleng;}
<STRING>(\\.|[^"\\])*\" {if(aux == 0) printf("STRLIT(\"%s)\n", yytext);BEGIN 0;col += yyleng;}
<STRING><<EOF>>             {printf("Line <%d>, col <%d>: unterminated string literal\n", line, col);BEGIN 0;col += yyleng;}
<STRING>"\n"                {printf("Line <%d>, col <%d>: unterminated string literal\n", line, col);BEGIN 0;col += yyleng;line++;}

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
{INTLIT}                                                {if(aux == 0) printf("INTLIT(%s)\n", yytext);col += yyleng;} 
{INTLIT}*"."?{INTLIT}*((e|E)("+"|"-")?{INTLIT}+)*       {if(aux == 0) printf("REALLIT\n");col += yyleng;}    
([a-z]|[A-Z]|"$"|"_")+                                  {if(aux == 0) printf("ID(%s)\n", yytext);col += yyleng;}
("++"|"--"|"null"|"Integer"|"System")                   {if(aux == 0) printf("RESERVED(%s)\n", yytext);col += yyleng;}


(" "|"\t"|"\r"|"\f"|"\r\n")   {;col += yyleng;}

"//".*"\n"                  {col += yyleng;line++;}
"//".*                      {;}


"\n"                   {line++;col = 1;}
(\\.)                  {printf("Line <%d>, col <%d>: invalid escape sequence (%s)\n", line, col, yytext);col += yyleng;}     
.                      {printf("Line <%d>, col <%d>: illegal character (%s)\n", line, col, yytext);col += yyleng;}

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
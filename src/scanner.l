%option noyywrap
%{
#include "../tests/test_tree.h" // remove warnings, needed for submission
#include "parser.h"

int line_num = 1;
int lexerror = 0;    /* to be used in later tasks */
%}

%%

"else"                  { return ELSE; }
"functions"             { return FUNCTIONS; }
"goto"                  { return GOTO; }
"if"                    { return IF; }
"labels"                { return LABELS; }
"return"                { return RETURN; }
"types"                 { return TYPES; }
"var"                   { return VAR; }
"vars"                  { return VARS; }
"void"                  { return VOID; }
"while"                 { return WHILE; }
"("                     { return OPEN_PAREN; }
")"                     { return CLOSE_PAREN; }
"{"                     { return OPEN_BRACE; }
"}"                     { return CLOSE_BRACE; }
"["                     { return OPEN_BRACKET; }
"]"                     { return CLOSE_BRACKET; }
":"                     { return COLON; }
";"                     { return SEMI_COLON; }
"!"                     { return NOT; }
"!="                    { return DIFFERENT; }
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MULTIPLY; }
"/"                     { return DIV; }
","                     { return COMMA; }
"&&"                    { return AND; }
"||"                    { return OR; }
"<"                     { return LESS; }
">"                     { return GREATER; }
"<="                    { return LESS_OR_EQUAL; }
">="                    { return GREATER_OR_EQUAL; }
"="                     { return ASSIGN; } 
"=="                    { return EQUAL; }
[ \t]*                  { /* ignore whitespaces */ }
"//".*	                { /* ignore comment */ }
\n                      { line_num++; }
[a-zA-Z][a-zA-Z0-9]*    { yylval.symbol = yytext; return IDENTIFIER; }
[0-9]+                  { yylval.symbol = yytext; return INTEGER; }
<<EOF>>                 { return END_OF_FILE; }
.                       { lexerror = 1; return LEXICAL_ERROR; }

%%

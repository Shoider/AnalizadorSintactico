%option noyywrap

%{
#include <stdio.h>
%}


DIGITOS			[0-9]+
LETRAS          [a-zA-Z]+
PARENTESIS      "("")"
CORCHETES       "[""]"
BLOQUES         "{""}"
OPERADORLOG     "!"|"||"|"&&"
PUNTEROS        "->"|"*"

%%


"int"               { return INT; }
"float"             { return FLOAT; }
"short"             { return SHORT; }
"long"              { return LONG; }
"char"              { return CHAR; }
"void"              { return VOID; }
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"do"                { return DO; }
"for"               { return FOR; }
"switch"            { return SWITCH; }
"case"              { return CASE; }
"default"           { return DEFAULT; }
"return"            { return RETURN; }
"break"             { return BREAK; }
"static"            { return STATIC; }
"const"             { return CONST; }



{DIGITOS}               { return NUMERO; }
{DIGITOS}"."{DIGITOS}   { return NUMEROFLOAT; }

{LETRAS}                { return IDENTIFICADOR; }


"="                     { return ASIGNACION; }
"=="                    { return IGUALDAD; }
"<"                     { return MENOR; }
">"                     { return MAYOR; }
"<="                    { return MENORIGUAL; }
">="                    { return MAYORIGUAL; }
"!="                    { return DIFERENTE; }

"+"                     { return SUMA; }
"-"                     { return RESTA; }
"*"                     { return MULTIPLICACION; }
"/"                     { return DIVISION; }
"%"                     { return MODULO; }

"+="                    { return SUMAASIG; }
"-="                    { return RESTAASIG; }
"*="                    { return MULTIPLICACIONASIG; }
"/="                    { return DIVISIONASIG; }
"%="                    { return MODULOASIG; }

"++"                    { return INCREMENTO; }
"--"                    { return DECREMENTO; }



";"                   { printf("FL \n"); return FL; }
":"                   { printf("ETIQUETA "); return ETIQUETA; }
","                   { printf("SEPARACION "); return SEPARACION; }

"("                   { return PARENTESIS_ABIERTO; }
")"                   { return PARENTESIS_CERRADO; }
"["                   { return CORCHETE_ABIERTO; }
"]"                   { return CORCHETE_CERRADO; }
"{"                   { return BLOQUE_ABIERTO; }
"}"                   { return BLOQUE_CERRADO; }


[ \t\n]             // Ignorar espacios en blanco y saltos de línea
.                   { printf("Error: Caracter desconocido (%s) ", yytext); }

%%

int main() {
    yylex();
    printf("FIN\n"); // Agregar una marca al final de la salida
    return 0;
}
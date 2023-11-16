%{
    #include <stdio.h>
    int yylex();
    int yyerror(char *s);
%}

%token INT FLOAT SHORT LONG CHAR VOID IF ELSE WHILE DO FOR SWITCH CASE DEFAULT RETURN BREAK STATIC CONST
%token NUMERO NUMEROFLOAT IDENTIFICADOR ASIGNACION IGUALDAD MENOR MAYOR MENORIGUAL MAYORIGUAL DIFERENTE
%token SUMA RESTA MULTIPLICACION DIVISION MODULO SUMAASIG RESTAASIG MULTIPLICACIONASIG DIVISIONASIG MODULOASIG
%token INCREMENTO DECREMENTO FL ETIQUETA SEPARACION OTHER CHART
%token PARENTESIS_ABIERTO PARENTESIS_CERRADO CORCHETE_ABIERTO CORCHETE_CERRADO BLOQUE_ABIERTO BLOQUE_CERRADO

%left '+' '-' // Define la asociatividad y precedencia de los operadores aritméticos

%%

// Aquí van las reglas gramaticales, producciones y acciones

prog : declaracionInt prog | declaracionFloat prog | declaracionShort prog | declaracionLong prog | declaracionChart |
    declaracionInt | declaracionFloat | declaracionShort | declaracionLong | declaracionChart prog | OTHER prog 
    | error { printf("Error: Entrada no válida\n"); }
    ;

declaracionInt : INT IDENTIFICADOR ASIGNACION NUMERO FL { printf("\nAceptacion: Declaración de variable entera\n"); }
            ;

declaracionFloat : FLOAT IDENTIFICADOR ASIGNACION NUMEROFLOAT FL { printf("\nAceptacion: Declaración de variable float\n"); }
            ;

declaracionShort : SHORT IDENTIFICADOR ASIGNACION NUMERO FL { printf("\nAceptacion: Declaración de variable short\n"); }
            ;

declaracionLong : LONG IDENTIFICADOR ASIGNACION NUMERO FL { printf("\nAceptacion: Declaración de variable long\n"); }
            ;

declaracionChart : CHAR IDENTIFICADOR ASIGNACION CHART FL { printf("\nAceptacion: Declaración de variable char\n"); }
            ;


%%

int yyerror(char *s){
    printf("\nt-> Error Sintactico %s\n",s);
}

int main(int argc, char **argv){
    yyparse();
    return 0;
}
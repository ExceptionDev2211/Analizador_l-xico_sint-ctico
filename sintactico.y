%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex(void);
void yyerror(char *s);
extern FILE *yyin;

#define MAX_SYMBOLS 500

typedef struct {
    char *name;
    float floatValue;
    char *stringValue;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

void addSymbol(char *name) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Error: El símbolo '%s' ya está definido.\n", name);
            return;
        }
    }
    if (symbolCount >= MAX_SYMBOLS) {
        printf("Error: Se ha alcanzado el límite máximo de símbolos.\n");
        return;
    }

    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].floatValue = 0.0;
    symbolTable[symbolCount].stringValue = NULL;
    symbolCount++;
}

float getSymbolValue(char *name) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return symbolTable[i].floatValue;
        }
    }
    printf("Error: El símbolo '%s' no está definido.\n", name);
    return 0.0;
}

void setFloatValue(char *name, float value) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].floatValue = value;
            return;
        }
    }
    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].floatValue = value;
    symbolCount++;
}
void setFunctionValue(char *name, float param1, float param2) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].floatValue = param1 + param2;
            return;
        }
    }
    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].floatValue = param1 + param2;
    symbolCount++;
}

void setStringValue(char *name, char *valueS) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            free(symbolTable[i].stringValue); 
            symbolTable[i].stringValue = strdup(valueS);
            return;
        }
    }
    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].stringValue = strdup(valueS);
    symbolCount++;
}

%}

%union {
    int int_val;
    float float_val;
    char *str_val;
}

%token <int_val>  ENT
%token <str_val>  STR VARID
%token <float_val>  FLOT
%token VAR FN SI SINO MIE DEV TRY CAP MOST PAR ASIG IGU DIF MEN MENI MAY MAYI MAS REST MUL DIV MOD LPAREN RPAREN FL FINS FINF LCORCH RCORCH COMM FINP FINW FINT PARAM
%type <float_val> value condition operation return


%%
program:
        |instruction
        |functionStatement
        |program instruction
        |program functionStatement
        ;

instruction:
          varDeclaration
        | varAsignation
        | varInitialization        
        | operation FL
        | ifStatement
        | forStatement
        | whileStatement
        | errorStatement
        | bringFunction
        | printStatement
        ;

varDeclaration:
          VAR VARID FL { addSymbol($2); }
        ;

varInitialization:
          VAR VARID ASIG ENT FL { setFloatValue($2, (float) $4); }
        | VAR VARID ASIG FLOT FL { setFloatValue($2, $4); }
        | VAR VARID ASIG STR FL { setStringValue($2, $4); }
        | VAR VARID ASIG value FL { setFloatValue($2, $4); }
        | VAR VARID ASIG operation FL { setFloatValue($2, $4); }
        ;

varAsignation:
          VARID ASIG value FL { setFloatValue($1, $3); }
        | VARID ASIG operation FL { setFloatValue($1, $3); }
        ;

value:
          ENT { $$ = (float)$1; }
        | FLOT { $$ = $1; }
        | VARID { $$ = getSymbolValue($1); }
        ;

operation:
          value MAS value { $$ = $1 + $3; }
        | value REST value { $$ = $1 - $3; }
        | value MUL value { $$ = $1 * $3; }
        | value DIV value {
            if ($3 == 0) {
                yyerror("División por cero");
                $$ = 0;
            } else {
                $$ = $1 / $3;
            }
          }
        | value MOD value { $$ = (int)$1 % (int)$3; }
        ;



condition:
          value IGU value { if($1 == $3) $$ = 1; else $$ = 0; }
        | value DIF value { if($1 != $3) $$ = 1; else $$ = 0;}
        | value MEN value { if($1 < $3) $$ = 1; else $$ = 0; }
        | value MENI value { if($1 <= $3) $$ = 1; else $$ = 0; }
        | value MAY value { if($1 > $3) $$ = 1; else $$ = 0; }
        | value MAYI value { if($1 >= $3) $$ = 1; else $$ = 0; }
        ;
        
ifStatement: 
            SI LPAREN condition RPAREN LCORCH operation FL RCORCH FINS { if ($3 == 1) { printf("%f\n", $6); } }
          | SI LPAREN condition RPAREN LCORCH VARID ASIG value FL RCORCH FINS {if ($3 == 1) { setFloatValue($6,$8);}}
          | SI LPAREN condition RPAREN LCORCH VARID ASIG operation FL RCORCH FINS {if ($3 == 1) { setFloatValue($6,$8);} }
          | SI LPAREN condition RPAREN LCORCH VARID ASIG value FL RCORCH SINO LCORCH VARID ASIG value FL RCORCH FINS {if ($3 == 1) { setFloatValue($6,$8);} else {setFloatValue($13,$15);} }
          | SI LPAREN condition RPAREN LCORCH VARID ASIG operation FL RCORCH SINO LCORCH VARID ASIG operation FL RCORCH FINS {if ($3 == 1) { setFloatValue($6,$8);} else {setFloatValue($13,$15);} }
        ;
forStatement: PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i <= $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) + $16);}}
            | PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i <= $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) * $16);}}
            | PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i <= $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) - $16);}}
            | PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i <= $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) / $16);}}
            | PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i < $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) + $16);}}
            | PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i < $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) * $16);}}
            | PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i < $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) - $16);}}
            | PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINP {int i ; setFloatValue($3,$5); for(i = $5; i < $9; i++){ printf("%f\n", (float)getSymbolValue($12));  setFloatValue($12, getSymbolValue($12) / $16);}}

whileStatement: MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINW {while($3 < $5){$3 +=1;setFloatValue($8, getSymbolValue($8) + $12);}}
              | MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINW {while($3 < $5){$3 +=1;setFloatValue($8, getSymbolValue($8) - $12);}}
              | MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINW {while($3 < $5){$3 +=1;setFloatValue($8, getSymbolValue($8) / $12);}}
              | MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINW {while($3 < $5){$3 +=1;setFloatValue($8, getSymbolValue($8) * $12);}}
              | MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINW {while($3 <= $5){$3 +=1;setFloatValue($8, getSymbolValue($8) + $12);}}
              | MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINW {while($3 <= $5){$3 +=1;setFloatValue($8, getSymbolValue($8) - $12);}}
              | MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINW {while($3 <= $5){$3 +=1;setFloatValue($8, getSymbolValue($8) / $12);}}
              | MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINW {while($3 <= $5){$3 +=1;setFloatValue($8, getSymbolValue($8) * $12);}}

functionStatement:  
                FN VARID PARAM LCORCH varDeclaration return RCORCH FINF { addSymbol($2); setFloatValue($2,$6) ;}  
                | FN VARID PARAM LCORCH varAsignation return RCORCH FINF { addSymbol($2); setFloatValue($2,$6);}
                | FN VARID PARAM LCORCH varInitialization return RCORCH FINF { addSymbol($2); setFloatValue($2,$6);}  
                | FN VARID PARAM LCORCH operation return RCORCH FINF { addSymbol($2); setFloatValue($2,$6);}  
                | FN VARID PARAM LCORCH varInitialization operation return RCORCH FINF { addSymbol($2); setFloatValue($2,$7);}  
                | FN VARID PARAM LCORCH ifStatement return RCORCH FINF { addSymbol($2); setFloatValue($2,$6);}
                | FN VARID PARAM LCORCH varInitialization ifStatement return RCORCH FINF { addSymbol($2); setFloatValue($2,$7);}
                | FN VARID PARAM LCORCH whileStatement return RCORCH FINF { addSymbol($2); setFloatValue($2,$6);}
                | FN VARID PARAM LCORCH forStatement return RCORCH FINF { addSymbol($2); setFloatValue($2,$6);}
                | FN VARID PARAM LCORCH varInitialization forStatement return RCORCH FINF { addSymbol($2); setFloatValue($2,$7);}
                | FN VARID PARAM LCORCH varInitialization whileStatement return RCORCH FINF { addSymbol($2); setFloatValue($2,$7);}    

bringFunction:  VARID LPAREN RPAREN FL {addSymbol($1);}
                |VARID LPAREN FLOT FLOT RPAREN FL {setFunctionValue($1,$3,$4);}               

return:  
         DEV VARID FL { $$ = getSymbolValue($2);}
        | DEV operation FL { $$ = $2;}

errorStatement: TRY LCORCH program RCORCH CAP LCORCH program RCORCH FINT
              | TRY LCORCH program RCORCH CAP LCORCH printStatement RCORCH FINT              


printStatement:
          MOST LPAREN STR RPAREN FL { printf("%s\n", $3); }
        | MOST LPAREN value RPAREN FL { printf("%f\n", $3); }
        | MOST LPAREN operation RPAREN FL { printf("%f\n", $3); }
        | MOST LPAREN condition RPAREN FL { printf("%f\n", $3); }
        ;

%%

void yyerror(char *s) {
    printf("Error Sintáctico: %s\n", s);
}

int main(int argc, char **argv) {
    printf("Inicio del programa: \n");
    if (argc > 1) {
        yyin = fopen(argv[1], "rt");
    } else {
        yyin = stdin;
    }
    yyparse();
    return 0;
}

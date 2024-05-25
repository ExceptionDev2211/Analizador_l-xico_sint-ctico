%{
#include "sintactico.tab.h"
%}
entero          -?[0-9]+                         
cadena          \"[^\"]*\" 
flotante        -?[0-9]+\.[0-9]+ 
variableId      [a-zA-Z][a-zA-Z0-9]*
parametro           \(("p"[0-9]+","?)*\)


%%

[ \t\n]+                        { /* Ignorar saltos de línea y espacios en blanco */ }
"variable"                        {return VAR;}
"funcion"                         {return FN;}
"si"                              {return SI;}
"sino"                            {return SINO;}
"mientras"                        {return MIE;}
"fins"                            {return FINS;}
"finf"                            {return FINF;}
"finw"                            {return FINW;}
"fint"                            {return FINT;}
"devolver"                        {return DEV;}
"intentar"                        {return TRY;}
"capturar"                        {return CAP;}
"mostrar"                         {return MOST;}
"para"                            {return PAR;}
"finp"                            {return FINP;}
{parametro}                         {return PARAM;}
{entero}                        { yylval.int_val = atoi(yytext); return ENT; }
{flotante}                      { yylval.float_val = atof(yytext); return FLOT; }
{cadena}                        { yylval.str_val = strdup(yytext); return STR; }
{variableId}                    { yylval.str_val = strdup(yytext); return VARID; }
=                               {return ASIG;}  
==                              { return IGU; }
"!="                            { return DIF; }
"<"                             { return MEN; }
"<="                            { return MENI; }
">"                             { return MAY; }
">="                            { return MAYI; }
\+                             { return MAS; }
"--"                             { return REST; }
\*                             { return MUL; }
\/                             { return DIV; }
%                              { return MOD; }
"("                             { return LPAREN; }
")"                             { return RPAREN; }
"{"                             { return LCORCH; }
"}"                             { return RCORCH; }
\;                              {return FL;}
\,                              {return COMM;}
.                               { printf("Error léxico: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

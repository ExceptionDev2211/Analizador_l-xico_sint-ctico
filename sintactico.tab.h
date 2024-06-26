/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ENT = 258,                     /* ENT  */
    STR = 259,                     /* STR  */
    VARID = 260,                   /* VARID  */
    FLOT = 261,                    /* FLOT  */
    VAR = 262,                     /* VAR  */
    FN = 263,                      /* FN  */
    SI = 264,                      /* SI  */
    SINO = 265,                    /* SINO  */
    MIE = 266,                     /* MIE  */
    DEV = 267,                     /* DEV  */
    TRY = 268,                     /* TRY  */
    CAP = 269,                     /* CAP  */
    MOST = 270,                    /* MOST  */
    PAR = 271,                     /* PAR  */
    ASIG = 272,                    /* ASIG  */
    IGU = 273,                     /* IGU  */
    DIF = 274,                     /* DIF  */
    MEN = 275,                     /* MEN  */
    MENI = 276,                    /* MENI  */
    MAY = 277,                     /* MAY  */
    MAYI = 278,                    /* MAYI  */
    MAS = 279,                     /* MAS  */
    REST = 280,                    /* REST  */
    MUL = 281,                     /* MUL  */
    DIV = 282,                     /* DIV  */
    MOD = 283,                     /* MOD  */
    LPAREN = 284,                  /* LPAREN  */
    RPAREN = 285,                  /* RPAREN  */
    FL = 286,                      /* FL  */
    FINS = 287,                    /* FINS  */
    FINF = 288,                    /* FINF  */
    LCORCH = 289,                  /* LCORCH  */
    RCORCH = 290,                  /* RCORCH  */
    COMM = 291,                    /* COMM  */
    FINP = 292,                    /* FINP  */
    FINW = 293,                    /* FINW  */
    FINT = 294,                    /* FINT  */
    PARAM = 295                    /* PARAM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "sintactico.y"

    int int_val;
    float float_val;
    char *str_val;

#line 110 "sintactico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */

/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintactico.y"

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


#line 156 "sintactico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintactico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ENT = 3,                        /* ENT  */
  YYSYMBOL_STR = 4,                        /* STR  */
  YYSYMBOL_VARID = 5,                      /* VARID  */
  YYSYMBOL_FLOT = 6,                       /* FLOT  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_FN = 8,                         /* FN  */
  YYSYMBOL_SI = 9,                         /* SI  */
  YYSYMBOL_SINO = 10,                      /* SINO  */
  YYSYMBOL_MIE = 11,                       /* MIE  */
  YYSYMBOL_DEV = 12,                       /* DEV  */
  YYSYMBOL_TRY = 13,                       /* TRY  */
  YYSYMBOL_CAP = 14,                       /* CAP  */
  YYSYMBOL_MOST = 15,                      /* MOST  */
  YYSYMBOL_PAR = 16,                       /* PAR  */
  YYSYMBOL_ASIG = 17,                      /* ASIG  */
  YYSYMBOL_IGU = 18,                       /* IGU  */
  YYSYMBOL_DIF = 19,                       /* DIF  */
  YYSYMBOL_MEN = 20,                       /* MEN  */
  YYSYMBOL_MENI = 21,                      /* MENI  */
  YYSYMBOL_MAY = 22,                       /* MAY  */
  YYSYMBOL_MAYI = 23,                      /* MAYI  */
  YYSYMBOL_MAS = 24,                       /* MAS  */
  YYSYMBOL_REST = 25,                      /* REST  */
  YYSYMBOL_MUL = 26,                       /* MUL  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_MOD = 28,                       /* MOD  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_FL = 31,                        /* FL  */
  YYSYMBOL_FINS = 32,                      /* FINS  */
  YYSYMBOL_FINF = 33,                      /* FINF  */
  YYSYMBOL_LCORCH = 34,                    /* LCORCH  */
  YYSYMBOL_RCORCH = 35,                    /* RCORCH  */
  YYSYMBOL_COMM = 36,                      /* COMM  */
  YYSYMBOL_FINP = 37,                      /* FINP  */
  YYSYMBOL_FINW = 38,                      /* FINW  */
  YYSYMBOL_FINT = 39,                      /* FINT  */
  YYSYMBOL_PARAM = 40,                     /* PARAM  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_instruction = 43,               /* instruction  */
  YYSYMBOL_varDeclaration = 44,            /* varDeclaration  */
  YYSYMBOL_varInitialization = 45,         /* varInitialization  */
  YYSYMBOL_varAsignation = 46,             /* varAsignation  */
  YYSYMBOL_value = 47,                     /* value  */
  YYSYMBOL_operation = 48,                 /* operation  */
  YYSYMBOL_condition = 49,                 /* condition  */
  YYSYMBOL_ifStatement = 50,               /* ifStatement  */
  YYSYMBOL_forStatement = 51,              /* forStatement  */
  YYSYMBOL_whileStatement = 52,            /* whileStatement  */
  YYSYMBOL_functionStatement = 53,         /* functionStatement  */
  YYSYMBOL_bringFunction = 54,             /* bringFunction  */
  YYSYMBOL_return = 55,                    /* return  */
  YYSYMBOL_errorStatement = 56,            /* errorStatement  */
  YYSYMBOL_printStatement = 57             /* printStatement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  305

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   100,   100,   101,   102,   103,   104,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   121,   125,   126,
     127,   128,   129,   133,   134,   138,   139,   140,   144,   145,
     146,   147,   155,   161,   162,   163,   164,   165,   166,   170,
     171,   172,   173,   174,   176,   177,   178,   179,   180,   181,
     182,   183,   185,   186,   187,   188,   189,   190,   191,   192,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   207,   208,   211,   212,   214,   215,   219,   220,   221,
     222
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ENT", "STR", "VARID",
  "FLOT", "VAR", "FN", "SI", "SINO", "MIE", "DEV", "TRY", "CAP", "MOST",
  "PAR", "ASIG", "IGU", "DIF", "MEN", "MENI", "MAY", "MAYI", "MAS", "REST",
  "MUL", "DIV", "MOD", "LPAREN", "RPAREN", "FL", "FINS", "FINF", "LCORCH",
  "RCORCH", "COMM", "FINP", "FINW", "FINT", "PARAM", "$accept", "program",
  "instruction", "varDeclaration", "varInitialization", "varAsignation",
  "value", "operation", "condition", "ifStatement", "forStatement",
  "whileStatement", "functionStatement", "bringFunction", "return",
  "errorStatement", "printStatement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     152,   -57,    32,   -57,     3,    16,    19,    38,    37,    40,
      51,   114,   -57,   -57,   -57,   -57,   189,    62,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,    91,     5,   -11,    63,    91,
      91,   152,    35,    97,   -57,   -57,   -57,    91,    91,    91,
      91,    91,   -57,   -57,    60,    78,   104,    80,   137,   -57,
      84,   129,    94,    61,    21,    98,   224,   102,   108,   139,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   132,   -57,   133,
     135,   143,   145,   144,   128,    91,    91,    91,    91,    91,
      91,   153,    91,    91,   163,   159,   160,   162,   165,   195,
     166,   -57,   -57,   -57,   -57,   -57,   188,   210,   183,   210,
     210,   210,   210,   210,   -57,   -57,   -57,   -57,   -57,   -57,
     101,   202,   203,   172,   -57,   -57,   -57,   -57,   222,   -57,
     110,   220,   210,   210,   210,   210,   221,   223,   225,   226,
     227,   228,   240,   233,   231,   232,   152,    91,   236,   237,
     238,   234,   235,   239,   241,   242,   244,   245,   246,   247,
     248,    91,   249,   254,   267,    57,   250,    69,   -57,   -57,
     -57,   253,   255,   256,   257,   -57,   -57,   -57,   -57,   -57,
     -57,   176,   251,   259,   266,   270,   258,   260,    91,    91,
     -57,   -57,   -57,   -57,   261,   263,   -57,   268,   287,   -57,
     -57,   264,   265,    -1,    15,   184,   194,   269,   271,   272,
     -57,   273,   -57,    91,    91,    91,    91,    91,    91,    91,
      91,   288,   295,   296,   297,   277,   278,   279,   280,   281,
     282,   283,   284,   299,   300,   301,   302,   285,   286,   289,
     290,   291,   292,   293,   294,   317,   318,    91,    91,   298,
     303,   304,   305,   306,   307,   308,   309,   200,   204,   319,
     320,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,    91,
      91,    91,    91,    91,    91,    91,    91,   313,   314,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   -57,   -57,   339,
     340,   341,   342,   343,   344,   345,   346,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    25,    27,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     7,     9,     8,     0,     0,    11,    12,
      13,     4,    15,    14,    16,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     1,     5,     6,     0,     0,     0,
       0,     0,    10,    27,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,    31,    32,    23,    24,     0,    71,    25,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    20,    19,    21,    22,    27,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,    77,    78,    79,    80,     0,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     2,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,    73,    74,
      60,     0,     0,     0,     0,    62,    61,    63,    65,    68,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    66,    69,    70,     0,     0,    39,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    55,    54,    56,    57,    59,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    50,    49,
      51,    44,    46,    45,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -28,   -10,   230,   310,   311,   -25,   -15,   354,   -56,
     -55,   -52,    -9,   -57,   -24,   -57,   196
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    17,    52,    18,
      19,    20,    21,    22,   121,    23,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    35,    36,    54,    51,    53,    48,    56,    27,   199,
      45,    46,    60,    61,    62,    63,    64,    57,   101,   102,
      49,    28,   103,    72,     1,   201,     2,     3,     4,     5,
       6,   200,     7,    73,     8,    47,     9,    10,     1,    55,
      43,     3,   123,   124,    35,    36,   125,   202,    29,    25,
     104,   105,   106,   107,   108,   109,    84,   111,   112,   100,
       1,    26,     2,     3,     4,     5,     6,    30,     7,    32,
       8,    31,     9,    10,   126,   127,   128,   129,   130,   131,
      33,    82,    83,   122,    37,    38,    39,    40,    41,   178,
     179,    65,   176,    42,     1,   133,    43,     3,   141,   142,
     143,   144,    59,    50,     1,   139,   132,     3,   155,    66,
      67,    68,   157,     1,    34,   138,     3,     1,    74,     2,
       3,     4,     5,     6,    81,     7,   171,     8,    85,     9,
      10,     1,    87,    96,     3,     4,   172,     6,    88,     7,
      69,    70,    43,    71,    10,    35,    36,    75,    76,    77,
      78,    79,    80,   191,   192,     1,    89,     2,     3,     4,
       5,     6,    90,     7,    91,     8,    92,     9,    10,    37,
      38,    39,    40,    41,    93,    95,    94,   113,   215,   216,
     217,   218,   219,   220,   221,   222,     1,   110,    43,     3,
     114,   115,     6,   116,     7,   120,   117,   119,   118,    10,
      37,    38,    39,    40,    41,    25,   136,   184,   203,   204,
     205,   206,   249,    37,    38,    39,    40,    41,   207,   208,
     209,   210,   120,   250,   259,   260,   261,   262,   263,   264,
     265,   266,   134,   135,   269,   270,   271,   272,   273,   274,
     275,   276,    75,    76,    77,    78,    79,    80,    37,    38,
      39,    40,    41,   137,    86,   140,   145,   151,   146,   174,
     147,   148,   149,   150,   152,   153,   154,   158,   159,   161,
     162,   160,   175,   195,   163,   165,   164,   166,   167,   168,
     169,   170,   185,   187,   173,   177,   180,   188,   181,   182,
     183,   186,   196,   223,   197,   198,   193,   189,   194,   190,
     224,   225,   226,   211,    97,   212,   213,   214,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   247,   248,   241,   242,   243,   244,   245,   246,
       0,     0,   156,     0,     0,     0,   251,     0,     0,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   277,   278,
     267,   268,   279,   280,   281,   282,   283,   284,   285,   286,
       0,   287,   288,     0,     0,     0,   289,   290,   291,   292,
     293,   294,   295,   296,     0,     0,   297,   298,   299,   300,
     301,   302,   303,   304,    98,    99,    58
};

static const yytype_int16 yycheck[] =
{
      25,    11,    11,    31,    29,    30,    17,    32,     5,    10,
      25,     6,    37,    38,    39,    40,    41,    32,    74,    74,
      31,     5,    74,    48,     3,    10,     5,     6,     7,     8,
       9,    32,    11,    48,    13,    30,    15,    16,     3,     4,
       5,     6,    98,    98,    54,    54,    98,    32,    29,    17,
      75,    76,    77,    78,    79,    80,    35,    82,    83,    74,
       3,    29,     5,     6,     7,     8,     9,    29,    11,    29,
      13,    34,    15,    16,    98,    99,   100,   101,   102,   103,
      29,    20,    21,    98,    24,    25,    26,    27,    28,    20,
      21,    31,    35,    31,     3,   110,     5,     6,   122,   123,
     124,   125,     5,    40,     3,   120,     5,     6,   136,    31,
       6,    31,   137,     3,     0,     5,     6,     3,    34,     5,
       6,     7,     8,     9,    30,    11,   151,    13,    30,    15,
      16,     3,    30,     5,     6,     7,   151,     9,    30,    11,
       3,     4,     5,     6,    16,   155,   155,    18,    19,    20,
      21,    22,    23,   178,   179,     3,    17,     5,     6,     7,
       8,     9,    30,    11,    31,    13,    31,    15,    16,    24,
      25,    26,    27,    28,    31,    31,    31,    14,   203,   204,
     205,   206,   207,   208,   209,   210,     3,    34,     5,     6,
      31,    31,     9,    31,    11,    12,    31,    31,     3,    16,
      24,    25,    26,    27,    28,    17,    34,    31,    24,    25,
      26,    27,   237,    24,    25,    26,    27,    28,    24,    25,
      26,    27,    12,   238,    24,    25,    26,    27,    24,    25,
      26,    27,    30,    30,   259,   260,   261,   262,   263,   264,
     265,   266,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    31,    30,    35,    35,    17,    35,     5,
      35,    35,    35,    35,    31,    34,    34,    31,    31,    35,
      35,    33,     5,     5,    35,    33,    35,    33,    33,    33,
      33,    33,    31,    17,    35,    35,    33,    17,    33,    33,
      33,    32,     5,     5,    30,    30,    35,    39,    35,    39,
       5,     5,     5,    34,    74,    34,    34,    34,    31,    31,
      31,    31,    31,    31,    31,    31,    17,    17,    17,    17,
      35,    35,     5,     5,    35,    35,    35,    35,    35,    35,
      -1,    -1,   136,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    38,    38,    38,    38,    38,    38,    38,    35,    35,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      -1,    32,    32,    -1,    -1,    -1,    35,    35,    35,    35,
      35,    35,    35,    35,    -1,    -1,    37,    37,    37,    37,
      37,    37,    37,    37,    74,    74,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    11,    13,    15,
      16,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    56,    57,    17,    29,     5,     5,    29,
      29,    34,    29,    29,     0,    43,    53,    24,    25,    26,
      27,    28,    31,     5,    47,    48,     6,    30,    17,    31,
      40,    47,    49,    47,    42,     4,    47,    48,    49,     5,
      47,    47,    47,    47,    47,    31,    31,     6,    31,     3,
       4,     6,    47,    48,    34,    18,    19,    20,    21,    22,
      23,    30,    20,    21,    35,    30,    30,    30,    30,    17,
      30,    31,    31,    31,    31,    31,     5,    44,    45,    46,
      48,    50,    51,    52,    47,    47,    47,    47,    47,    47,
      34,    47,    47,    14,    31,    31,    31,    31,     3,    31,
      12,    55,    48,    50,    51,    52,    55,    55,    55,    55,
      55,    55,     5,    48,    30,    30,    34,    31,     5,    48,
      35,    55,    55,    55,    55,    35,    35,    35,    35,    35,
      35,    17,    31,    34,    34,    42,    57,    47,    31,    31,
      33,    35,    35,    35,    35,    33,    33,    33,    33,    33,
      33,    47,    48,    35,     5,     5,    35,    35,    20,    21,
      33,    33,    33,    33,    31,    31,    32,    17,    17,    39,
      39,    47,    47,    35,    35,     5,     5,    30,    30,    10,
      32,    10,    32,    24,    25,    26,    27,    24,    25,    26,
      27,    34,    34,    34,    34,    47,    47,    47,    47,    47,
      47,    47,    47,     5,     5,     5,     5,    31,    31,    31,
      31,    31,    31,    31,    31,    17,    17,    17,    17,    35,
      35,    35,    35,    35,    35,    35,    35,     5,     5,    47,
      48,    38,    38,    38,    38,    38,    38,    38,    38,    24,
      25,    26,    27,    24,    25,    26,    27,    31,    31,    47,
      47,    47,    47,    47,    47,    47,    47,    35,    35,    31,
      31,    31,    31,    31,    31,    31,    31,    32,    32,    35,
      35,    35,    35,    35,    35,    35,    35,    37,    37,    37,
      37,    37,    37,    37,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    44,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    47,    48,    48,
      48,    48,    48,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     5,     5,
       5,     5,     5,     4,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     9,
      11,    11,    18,    18,    19,    19,    19,    19,    19,    19,
      19,    19,    15,    15,    15,    15,    15,    15,    15,    15,
       8,     8,     8,     8,     9,     8,     9,     8,     8,     9,
       9,     4,     6,     3,     3,     9,     9,     5,     5,     5,
       5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 17: /* varDeclaration: VAR VARID FL  */
#line 121 "sintactico.y"
                       { addSymbol((yyvsp[-1].str_val)); }
#line 1389 "sintactico.tab.c"
    break;

  case 18: /* varInitialization: VAR VARID ASIG ENT FL  */
#line 125 "sintactico.y"
                                { setFloatValue((yyvsp[-3].str_val), (float) (yyvsp[-1].int_val)); }
#line 1395 "sintactico.tab.c"
    break;

  case 19: /* varInitialization: VAR VARID ASIG FLOT FL  */
#line 126 "sintactico.y"
                                 { setFloatValue((yyvsp[-3].str_val), (yyvsp[-1].float_val)); }
#line 1401 "sintactico.tab.c"
    break;

  case 20: /* varInitialization: VAR VARID ASIG STR FL  */
#line 127 "sintactico.y"
                                { setStringValue((yyvsp[-3].str_val), (yyvsp[-1].str_val)); }
#line 1407 "sintactico.tab.c"
    break;

  case 21: /* varInitialization: VAR VARID ASIG value FL  */
#line 128 "sintactico.y"
                                  { setFloatValue((yyvsp[-3].str_val), (yyvsp[-1].float_val)); }
#line 1413 "sintactico.tab.c"
    break;

  case 22: /* varInitialization: VAR VARID ASIG operation FL  */
#line 129 "sintactico.y"
                                      { setFloatValue((yyvsp[-3].str_val), (yyvsp[-1].float_val)); }
#line 1419 "sintactico.tab.c"
    break;

  case 23: /* varAsignation: VARID ASIG value FL  */
#line 133 "sintactico.y"
                              { setFloatValue((yyvsp[-3].str_val), (yyvsp[-1].float_val)); }
#line 1425 "sintactico.tab.c"
    break;

  case 24: /* varAsignation: VARID ASIG operation FL  */
#line 134 "sintactico.y"
                                  { setFloatValue((yyvsp[-3].str_val), (yyvsp[-1].float_val)); }
#line 1431 "sintactico.tab.c"
    break;

  case 25: /* value: ENT  */
#line 138 "sintactico.y"
              { (yyval.float_val) = (float)(yyvsp[0].int_val); }
#line 1437 "sintactico.tab.c"
    break;

  case 26: /* value: FLOT  */
#line 139 "sintactico.y"
               { (yyval.float_val) = (yyvsp[0].float_val); }
#line 1443 "sintactico.tab.c"
    break;

  case 27: /* value: VARID  */
#line 140 "sintactico.y"
                { (yyval.float_val) = getSymbolValue((yyvsp[0].str_val)); }
#line 1449 "sintactico.tab.c"
    break;

  case 28: /* operation: value MAS value  */
#line 144 "sintactico.y"
                          { (yyval.float_val) = (yyvsp[-2].float_val) + (yyvsp[0].float_val); }
#line 1455 "sintactico.tab.c"
    break;

  case 29: /* operation: value REST value  */
#line 145 "sintactico.y"
                           { (yyval.float_val) = (yyvsp[-2].float_val) - (yyvsp[0].float_val); }
#line 1461 "sintactico.tab.c"
    break;

  case 30: /* operation: value MUL value  */
#line 146 "sintactico.y"
                          { (yyval.float_val) = (yyvsp[-2].float_val) * (yyvsp[0].float_val); }
#line 1467 "sintactico.tab.c"
    break;

  case 31: /* operation: value DIV value  */
#line 147 "sintactico.y"
                          {
            if ((yyvsp[0].float_val) == 0) {
                yyerror("División por cero");
                (yyval.float_val) = 0;
            } else {
                (yyval.float_val) = (yyvsp[-2].float_val) / (yyvsp[0].float_val);
            }
          }
#line 1480 "sintactico.tab.c"
    break;

  case 32: /* operation: value MOD value  */
#line 155 "sintactico.y"
                          { (yyval.float_val) = (int)(yyvsp[-2].float_val) % (int)(yyvsp[0].float_val); }
#line 1486 "sintactico.tab.c"
    break;

  case 33: /* condition: value IGU value  */
#line 161 "sintactico.y"
                          { if((yyvsp[-2].float_val) == (yyvsp[0].float_val)) (yyval.float_val) = 1; else (yyval.float_val) = 0; }
#line 1492 "sintactico.tab.c"
    break;

  case 34: /* condition: value DIF value  */
#line 162 "sintactico.y"
                          { if((yyvsp[-2].float_val) != (yyvsp[0].float_val)) (yyval.float_val) = 1; else (yyval.float_val) = 0;}
#line 1498 "sintactico.tab.c"
    break;

  case 35: /* condition: value MEN value  */
#line 163 "sintactico.y"
                          { if((yyvsp[-2].float_val) < (yyvsp[0].float_val)) (yyval.float_val) = 1; else (yyval.float_val) = 0; }
#line 1504 "sintactico.tab.c"
    break;

  case 36: /* condition: value MENI value  */
#line 164 "sintactico.y"
                           { if((yyvsp[-2].float_val) <= (yyvsp[0].float_val)) (yyval.float_val) = 1; else (yyval.float_val) = 0; }
#line 1510 "sintactico.tab.c"
    break;

  case 37: /* condition: value MAY value  */
#line 165 "sintactico.y"
                          { if((yyvsp[-2].float_val) > (yyvsp[0].float_val)) (yyval.float_val) = 1; else (yyval.float_val) = 0; }
#line 1516 "sintactico.tab.c"
    break;

  case 38: /* condition: value MAYI value  */
#line 166 "sintactico.y"
                           { if((yyvsp[-2].float_val) >= (yyvsp[0].float_val)) (yyval.float_val) = 1; else (yyval.float_val) = 0; }
#line 1522 "sintactico.tab.c"
    break;

  case 39: /* ifStatement: SI LPAREN condition RPAREN LCORCH operation FL RCORCH FINS  */
#line 170 "sintactico.y"
                                                                       { if ((yyvsp[-6].float_val) == 1) { printf("%f\n", (yyvsp[-3].float_val)); } }
#line 1528 "sintactico.tab.c"
    break;

  case 40: /* ifStatement: SI LPAREN condition RPAREN LCORCH VARID ASIG value FL RCORCH FINS  */
#line 171 "sintactico.y"
                                                                              {if ((yyvsp[-8].float_val) == 1) { setFloatValue((yyvsp[-5].str_val),(yyvsp[-3].float_val));}}
#line 1534 "sintactico.tab.c"
    break;

  case 41: /* ifStatement: SI LPAREN condition RPAREN LCORCH VARID ASIG operation FL RCORCH FINS  */
#line 172 "sintactico.y"
                                                                                  {if ((yyvsp[-8].float_val) == 1) { setFloatValue((yyvsp[-5].str_val),(yyvsp[-3].float_val));} }
#line 1540 "sintactico.tab.c"
    break;

  case 42: /* ifStatement: SI LPAREN condition RPAREN LCORCH VARID ASIG value FL RCORCH SINO LCORCH VARID ASIG value FL RCORCH FINS  */
#line 173 "sintactico.y"
                                                                                                                     {if ((yyvsp[-15].float_val) == 1) { setFloatValue((yyvsp[-12].str_val),(yyvsp[-10].float_val));} else {setFloatValue((yyvsp[-5].str_val),(yyvsp[-3].float_val));} }
#line 1546 "sintactico.tab.c"
    break;

  case 43: /* ifStatement: SI LPAREN condition RPAREN LCORCH VARID ASIG operation FL RCORCH SINO LCORCH VARID ASIG operation FL RCORCH FINS  */
#line 174 "sintactico.y"
                                                                                                                             {if ((yyvsp[-15].float_val) == 1) { setFloatValue((yyvsp[-12].str_val),(yyvsp[-10].float_val));} else {setFloatValue((yyvsp[-5].str_val),(yyvsp[-3].float_val));} }
#line 1552 "sintactico.tab.c"
    break;

  case 44: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINP  */
#line 176 "sintactico.y"
                                                                                                                    {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i <= (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) + (yyvsp[-3].float_val));}}
#line 1558 "sintactico.tab.c"
    break;

  case 45: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINP  */
#line 177 "sintactico.y"
                                                                                                                    {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i <= (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) * (yyvsp[-3].float_val));}}
#line 1564 "sintactico.tab.c"
    break;

  case 46: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINP  */
#line 178 "sintactico.y"
                                                                                                                     {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i <= (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) - (yyvsp[-3].float_val));}}
#line 1570 "sintactico.tab.c"
    break;

  case 47: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MENI value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINP  */
#line 179 "sintactico.y"
                                                                                                                    {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i <= (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) / (yyvsp[-3].float_val));}}
#line 1576 "sintactico.tab.c"
    break;

  case 48: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINP  */
#line 180 "sintactico.y"
                                                                                                                   {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i < (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) + (yyvsp[-3].float_val));}}
#line 1582 "sintactico.tab.c"
    break;

  case 49: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINP  */
#line 181 "sintactico.y"
                                                                                                                   {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i < (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) * (yyvsp[-3].float_val));}}
#line 1588 "sintactico.tab.c"
    break;

  case 50: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINP  */
#line 182 "sintactico.y"
                                                                                                                    {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i < (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) - (yyvsp[-3].float_val));}}
#line 1594 "sintactico.tab.c"
    break;

  case 51: /* forStatement: PAR LPAREN VARID ASIG ENT FL value MEN value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINP  */
#line 183 "sintactico.y"
                                                                                                                   {int i ; setFloatValue((yyvsp[-16].str_val),(yyvsp[-14].int_val)); for(i = (yyvsp[-14].int_val); i < (yyvsp[-10].float_val); i++){ printf("%f\n", (float)getSymbolValue((yyvsp[-7].str_val)));  setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) / (yyvsp[-3].float_val));}}
#line 1600 "sintactico.tab.c"
    break;

  case 52: /* whileStatement: MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINW  */
#line 185 "sintactico.y"
                                                                                                   {while((yyvsp[-12].float_val) < (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) + (yyvsp[-3].float_val));}}
#line 1606 "sintactico.tab.c"
    break;

  case 53: /* whileStatement: MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINW  */
#line 186 "sintactico.y"
                                                                                                    {while((yyvsp[-12].float_val) < (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) - (yyvsp[-3].float_val));}}
#line 1612 "sintactico.tab.c"
    break;

  case 54: /* whileStatement: MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINW  */
#line 187 "sintactico.y"
                                                                                                   {while((yyvsp[-12].float_val) < (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) / (yyvsp[-3].float_val));}}
#line 1618 "sintactico.tab.c"
    break;

  case 55: /* whileStatement: MIE LPAREN value MEN value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINW  */
#line 188 "sintactico.y"
                                                                                                   {while((yyvsp[-12].float_val) < (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) * (yyvsp[-3].float_val));}}
#line 1624 "sintactico.tab.c"
    break;

  case 56: /* whileStatement: MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID MAS value FL RCORCH FINW  */
#line 189 "sintactico.y"
                                                                                                    {while((yyvsp[-12].float_val) <= (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) + (yyvsp[-3].float_val));}}
#line 1630 "sintactico.tab.c"
    break;

  case 57: /* whileStatement: MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID REST value FL RCORCH FINW  */
#line 190 "sintactico.y"
                                                                                                     {while((yyvsp[-12].float_val) <= (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) - (yyvsp[-3].float_val));}}
#line 1636 "sintactico.tab.c"
    break;

  case 58: /* whileStatement: MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID DIV value FL RCORCH FINW  */
#line 191 "sintactico.y"
                                                                                                    {while((yyvsp[-12].float_val) <= (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) / (yyvsp[-3].float_val));}}
#line 1642 "sintactico.tab.c"
    break;

  case 59: /* whileStatement: MIE LPAREN value MENI value RPAREN LCORCH VARID ASIG VARID MUL value FL RCORCH FINW  */
#line 192 "sintactico.y"
                                                                                                    {while((yyvsp[-12].float_val) <= (yyvsp[-10].float_val)){(yyvsp[-12].float_val) +=1;setFloatValue((yyvsp[-7].str_val), getSymbolValue((yyvsp[-7].str_val)) * (yyvsp[-3].float_val));}}
#line 1648 "sintactico.tab.c"
    break;

  case 60: /* functionStatement: FN VARID PARAM LCORCH varDeclaration return RCORCH FINF  */
#line 195 "sintactico.y"
                                                                        { addSymbol((yyvsp[-6].str_val)); setFloatValue((yyvsp[-6].str_val),(yyvsp[-2].float_val)) ;}
#line 1654 "sintactico.tab.c"
    break;

  case 61: /* functionStatement: FN VARID PARAM LCORCH varAsignation return RCORCH FINF  */
#line 196 "sintactico.y"
                                                                         { addSymbol((yyvsp[-6].str_val)); setFloatValue((yyvsp[-6].str_val),(yyvsp[-2].float_val));}
#line 1660 "sintactico.tab.c"
    break;

  case 62: /* functionStatement: FN VARID PARAM LCORCH varInitialization return RCORCH FINF  */
#line 197 "sintactico.y"
                                                                             { addSymbol((yyvsp[-6].str_val)); setFloatValue((yyvsp[-6].str_val),(yyvsp[-2].float_val));}
#line 1666 "sintactico.tab.c"
    break;

  case 63: /* functionStatement: FN VARID PARAM LCORCH operation return RCORCH FINF  */
#line 198 "sintactico.y"
                                                                     { addSymbol((yyvsp[-6].str_val)); setFloatValue((yyvsp[-6].str_val),(yyvsp[-2].float_val));}
#line 1672 "sintactico.tab.c"
    break;

  case 64: /* functionStatement: FN VARID PARAM LCORCH varInitialization operation return RCORCH FINF  */
#line 199 "sintactico.y"
                                                                                       { addSymbol((yyvsp[-7].str_val)); setFloatValue((yyvsp[-7].str_val),(yyvsp[-2].float_val));}
#line 1678 "sintactico.tab.c"
    break;

  case 65: /* functionStatement: FN VARID PARAM LCORCH ifStatement return RCORCH FINF  */
#line 200 "sintactico.y"
                                                                       { addSymbol((yyvsp[-6].str_val)); setFloatValue((yyvsp[-6].str_val),(yyvsp[-2].float_val));}
#line 1684 "sintactico.tab.c"
    break;

  case 66: /* functionStatement: FN VARID PARAM LCORCH varInitialization ifStatement return RCORCH FINF  */
#line 201 "sintactico.y"
                                                                                         { addSymbol((yyvsp[-7].str_val)); setFloatValue((yyvsp[-7].str_val),(yyvsp[-2].float_val));}
#line 1690 "sintactico.tab.c"
    break;

  case 67: /* functionStatement: FN VARID PARAM LCORCH whileStatement return RCORCH FINF  */
#line 202 "sintactico.y"
                                                                          { addSymbol((yyvsp[-6].str_val)); setFloatValue((yyvsp[-6].str_val),(yyvsp[-2].float_val));}
#line 1696 "sintactico.tab.c"
    break;

  case 68: /* functionStatement: FN VARID PARAM LCORCH forStatement return RCORCH FINF  */
#line 203 "sintactico.y"
                                                                        { addSymbol((yyvsp[-6].str_val)); setFloatValue((yyvsp[-6].str_val),(yyvsp[-2].float_val));}
#line 1702 "sintactico.tab.c"
    break;

  case 69: /* functionStatement: FN VARID PARAM LCORCH varInitialization forStatement return RCORCH FINF  */
#line 204 "sintactico.y"
                                                                                          { addSymbol((yyvsp[-7].str_val)); setFloatValue((yyvsp[-7].str_val),(yyvsp[-2].float_val));}
#line 1708 "sintactico.tab.c"
    break;

  case 70: /* functionStatement: FN VARID PARAM LCORCH varInitialization whileStatement return RCORCH FINF  */
#line 205 "sintactico.y"
                                                                                            { addSymbol((yyvsp[-7].str_val)); setFloatValue((yyvsp[-7].str_val),(yyvsp[-2].float_val));}
#line 1714 "sintactico.tab.c"
    break;

  case 71: /* bringFunction: VARID LPAREN RPAREN FL  */
#line 207 "sintactico.y"
                                       {addSymbol((yyvsp[-3].str_val));}
#line 1720 "sintactico.tab.c"
    break;

  case 72: /* bringFunction: VARID LPAREN FLOT FLOT RPAREN FL  */
#line 208 "sintactico.y"
                                                  {setFunctionValue((yyvsp[-5].str_val),(yyvsp[-3].float_val),(yyvsp[-2].float_val));}
#line 1726 "sintactico.tab.c"
    break;

  case 73: /* return: DEV VARID FL  */
#line 211 "sintactico.y"
                      { (yyval.float_val) = getSymbolValue((yyvsp[-1].str_val));}
#line 1732 "sintactico.tab.c"
    break;

  case 74: /* return: DEV operation FL  */
#line 212 "sintactico.y"
                           { (yyval.float_val) = (yyvsp[-1].float_val);}
#line 1738 "sintactico.tab.c"
    break;

  case 77: /* printStatement: MOST LPAREN STR RPAREN FL  */
#line 219 "sintactico.y"
                                    { printf("%s\n", (yyvsp[-2].str_val)); }
#line 1744 "sintactico.tab.c"
    break;

  case 78: /* printStatement: MOST LPAREN value RPAREN FL  */
#line 220 "sintactico.y"
                                      { printf("%f\n", (yyvsp[-2].float_val)); }
#line 1750 "sintactico.tab.c"
    break;

  case 79: /* printStatement: MOST LPAREN operation RPAREN FL  */
#line 221 "sintactico.y"
                                          { printf("%f\n", (yyvsp[-2].float_val)); }
#line 1756 "sintactico.tab.c"
    break;

  case 80: /* printStatement: MOST LPAREN condition RPAREN FL  */
#line 222 "sintactico.y"
                                          { printf("%f\n", (yyvsp[-2].float_val)); }
#line 1762 "sintactico.tab.c"
    break;


#line 1766 "sintactico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 225 "sintactico.y"


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

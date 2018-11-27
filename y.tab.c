/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFICADOR = 258,
     STRING = 259,
     ENTERO = 260,
     DECIMAL = 261,
     NUMERO = 262,
     TEXTO = 263,
     NADA = 264,
     SI = 265,
     SINOSI = 266,
     SINO = 267,
     MIENTRAS = 268,
     HASTA = 269,
     HACER = 270,
     DESDE = 271,
     PORCADA = 272,
     RETORNA = 273,
     SEPARADOR = 274,
     ES = 275,
     POR = 276,
     DIVIDIDO = 277,
     DECREMENTAR = 278,
     INCREMENTAR = 279,
     NEGAR = 280,
     Y = 281,
     O = 282,
     DESIGUAL = 283,
     IGUAL = 284,
     MENOR = 285,
     MENOR_IGUAL = 286,
     MAYOR = 287,
     MAYOR_IGUAL = 288,
     IMPRIMIR = 289,
     LEER = 290,
     CONCATENAR = 291,
     A = 292,
     PONER = 293,
     EN = 294,
     MAYUSCULA = 295,
     MINUSCULA = 296,
     FIN = 297,
     SALIR = 298
   };
#endif
/* Tokens.  */
#define IDENTIFICADOR 258
#define STRING 259
#define ENTERO 260
#define DECIMAL 261
#define NUMERO 262
#define TEXTO 263
#define NADA 264
#define SI 265
#define SINOSI 266
#define SINO 267
#define MIENTRAS 268
#define HASTA 269
#define HACER 270
#define DESDE 271
#define PORCADA 272
#define RETORNA 273
#define SEPARADOR 274
#define ES 275
#define POR 276
#define DIVIDIDO 277
#define DECREMENTAR 278
#define INCREMENTAR 279
#define NEGAR 280
#define Y 281
#define O 282
#define DESIGUAL 283
#define IGUAL 284
#define MENOR 285
#define MENOR_IGUAL 286
#define MAYOR 287
#define MAYOR_IGUAL 288
#define IMPRIMIR 289
#define LEER 290
#define CONCATENAR 291
#define A 292
#define PONER 293
#define EN 294
#define MAYUSCULA 295
#define MINUSCULA 296
#define FIN 297
#define SALIR 298




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

#define MAX_IDS 10000

int yylex();
void yyerror (char const *s);

int var_count = 0;

char *identifiers[MAX_IDS] = {0};
int list_length(ExpressionList *list);
int getId(char *strId);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "parser.y"
{
    int intval;
    char *strval;
    float floatval;

    AssignmentNode *assignment;
    ArrayAssignment *arr_assign;

    WhileNode *whilenode;
    IfNode *ifnode;
    BoolNode *boolnode;
    FunctionNode*fnnode;
    ForNode *fornode;
    ForeachNode *foreachnode;

    ExpressionNode *exprnode;

    ExpressionList *explist;

    Block *block;

    StatementList *statements;

    bool_operation boolop;
}
/* Line 193 of yacc.c.  */
#line 227 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 240 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,    46,    44,    52,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    34,    38,    40,    42,
      44,    46,    48,    50,    54,    58,    62,    66,    70,    74,
      77,    81,    86,    91,    96,    99,   102,   107,   112,   116,
     119,   124,   129,   131,   135,   138,   146,   154,   162,   172,
     181,   189,   198,   205,   213,   217,   221,   225,   229,   232,
     234,   236,   238,   240,   242
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    56,    -1,    56,    55,    -1,
      58,    -1,    59,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    61,    -1,    57,    -1,    43,    -1,
       3,    20,    60,    -1,    63,    20,    60,    -1,     4,    -1,
       5,    -1,     6,    -1,    62,    -1,     3,    -1,    63,    -1,
      60,    44,    60,    -1,    60,    45,    60,    -1,    60,    46,
      60,    -1,    60,    21,    60,    -1,    60,    47,    60,    -1,
      60,    22,    60,    -1,    45,    60,    -1,    48,    60,    49,
      -1,    36,    60,    37,     3,    -1,    38,     3,    39,    40,
      -1,    38,     3,    39,    41,    -1,    24,     3,    -1,    23,
       3,    -1,    35,     7,    37,     3,    -1,    35,     8,    37,
       3,    -1,    50,    64,    51,    -1,    50,    51,    -1,     3,
      50,    60,    51,    -1,    63,    50,    60,    51,    -1,    60,
      -1,    60,    52,    64,    -1,    34,    60,    -1,    13,    19,
      71,    19,    15,    55,    42,    -1,    14,    19,    71,    19,
      15,    55,    42,    -1,    17,     3,    39,     3,    15,    55,
      42,    -1,    16,    58,    14,    19,    71,    19,    15,    55,
      42,    -1,    16,    14,    19,    71,    19,    15,    55,    42,
      -1,    10,    19,    71,    19,    15,    55,    42,    -1,    10,
      19,    71,    19,    15,    55,    42,    70,    -1,    11,    19,
      71,    19,    55,    42,    -1,    11,    19,    71,    19,    55,
      42,    70,    -1,    12,    55,    42,    -1,    60,    72,    60,
      -1,    71,    27,    71,    -1,    71,    26,    71,    -1,    25,
      71,    -1,    31,    -1,    30,    -1,    33,    -1,    32,    -1,
      29,    -1,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   104,   112,   124,   129,   134,   139,   144,
     149,   154,   159,   164,   171,   175,   184,   192,   198,   204,
     210,   217,   224,   227,   233,   239,   245,   251,   257,   263,
     268,   274,   281,   287,   293,   299,   305,   313,   324,   327,
     333,   343,   352,   357,   365,   371,   376,   386,   395,   401,
     410,   417,   426,   432,   438,   448,   455,   462,   470,   480,
     481,   482,   483,   484,   485
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "STRING", "ENTERO",
  "DECIMAL", "NUMERO", "TEXTO", "NADA", "SI", "SINOSI", "SINO", "MIENTRAS",
  "HASTA", "HACER", "DESDE", "PORCADA", "RETORNA", "SEPARADOR", "ES",
  "POR", "DIVIDIDO", "DECREMENTAR", "INCREMENTAR", "NEGAR", "Y", "O",
  "DESIGUAL", "IGUAL", "MENOR", "MENOR_IGUAL", "MAYOR", "MAYOR_IGUAL",
  "IMPRIMIR", "LEER", "CONCATENAR", "A", "PONER", "EN", "MAYUSCULA",
  "MINUSCULA", "FIN", "SALIR", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'['", "']'", "','", "$accept", "entry", "program", "block", "exit",
  "asig", "arr_asig", "expression", "func_call", "array", "arr_indexing",
  "explist", "print", "while", "foreach", "for", "if", "elseif",
  "condition", "bool_comp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    43,    45,    42,    47,    40,    41,
      91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    58,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     4,     4,     4,     2,     2,     4,     4,     3,     2,
       4,     4,     1,     3,     2,     7,     7,     7,     9,     8,
       7,     8,     6,     7,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     2,     3,    13,     5,     6,
      12,     0,     7,     8,     9,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    34,    21,    17,
      18,    19,     0,     0,     0,    44,    20,    22,     0,     0,
       0,     0,     1,     4,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    39,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,    40,    58,    64,    63,    60,    59,    62,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,    38,    26,    28,    23,    24,    25,    27,    36,
      37,    31,    32,    33,    41,    55,     0,    57,    56,     0,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,    50,    45,    46,     0,     0,    47,     0,     0,    51,
      49,     0,     0,     0,    48,     0,    54,     0,     0,    52,
      53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    59,    20,    46,
      47,    70,    22,    23,    24,    25,    26,   139,    60,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int16 yypact[] =
{
     126,   -15,    -4,    24,    28,    -2,    46,    47,    49,    20,
      25,    20,    52,   -28,    58,   -28,   126,   -28,   -28,   -28,
     -28,   -10,   -28,   -28,   -28,   -28,   -28,    20,    20,    14,
      14,    14,    43,    50,    67,    55,   -28,   -28,    42,   -28,
     -28,   -28,    20,    20,     3,   149,   -28,    45,    59,    60,
     161,    65,   -28,   -28,    20,    20,   149,    66,    14,   157,
      -5,    15,    53,    14,    80,    95,    79,   109,   -28,    39,
      56,    20,    20,    20,    20,    20,    20,   105,   115,   119,
     -13,   149,   130,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,    20,   112,    14,    14,   117,   131,    63,    14,   133,
     -28,    20,   -28,   -28,   -28,    79,    79,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   149,   126,   -28,   -28,   126,
     126,   142,   118,   126,   -28,    92,    99,   121,   126,   150,
     138,    26,   -28,   -28,   155,   126,   -28,   153,   126,   -28,
     -28,   158,    14,   167,   -28,   140,   -28,   126,   168,    26,
     -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -28,   -28,   -14,   -28,   -28,   163,   -28,     2,   -28,   -28,
       0,    72,   -28,   -28,   -28,   -28,   -28,    35,   -27,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      21,    32,    53,    61,    62,    27,    38,    39,    40,    41,
      54,    45,    33,    50,    92,    29,    21,    38,    39,    40,
      41,    93,    94,    38,    39,    40,    41,   112,   113,    56,
      57,    84,    48,    49,    95,    28,    97,   137,   138,    58,
      55,    93,    94,    30,    66,    67,    69,    31,    42,    35,
      36,    43,    37,    44,    68,    51,    81,    82,    52,    42,
      71,    72,    43,    27,    44,    42,   117,   118,    43,    63,
      44,   122,    96,   103,   104,   105,   106,   107,   108,    93,
      94,    64,   121,    73,    74,    75,    76,    71,    72,    93,
      94,   101,    28,   115,    65,    55,    77,    78,    99,    98,
      71,    72,   125,    69,    80,   126,   127,   102,   109,   130,
      73,    74,    75,    76,   134,   145,    21,    83,   110,    21,
      21,   141,   111,    21,   143,    75,    76,   116,    21,     1,
      71,    72,   119,   148,   131,    21,     2,   129,    21,     3,
       4,   132,     5,     6,    93,    94,   120,    21,   123,     7,
       8,    71,    72,    73,    74,    75,    76,   128,   100,   147,
       9,    10,    11,   133,    12,   135,    93,    94,    34,    13,
      71,    72,   142,   124,    73,    74,    75,    76,    71,    72,
     136,   114,    71,    72,   150,    85,    86,    87,    88,    89,
      90,     0,     0,    73,    74,    75,    76,   140,    79,     0,
     144,    73,    74,    75,    76,    73,    74,    75,    76,   146,
     149
};

static const yytype_int16 yycheck[] =
{
       0,     3,    16,    30,    31,    20,     3,     4,     5,     6,
      20,     9,    14,    11,    19,    19,    16,     3,     4,     5,
       6,    26,    27,     3,     4,     5,     6,    40,    41,    27,
      28,    58,     7,     8,    19,    50,    63,    11,    12,    25,
      50,    26,    27,    19,    42,    43,    44,    19,    45,     3,
       3,    48,     3,    50,    51,     3,    54,    55,     0,    45,
      21,    22,    48,    20,    50,    45,    93,    94,    48,    19,
      50,    98,    19,    71,    72,    73,    74,    75,    76,    26,
      27,    14,    19,    44,    45,    46,    47,    21,    22,    26,
      27,    52,    50,    91,    39,    50,    37,    37,     3,    19,
      21,    22,   116,   101,    39,   119,   120,    51,     3,   123,
      44,    45,    46,    47,   128,   142,   116,    51,     3,   119,
     120,   135,     3,   123,   138,    46,    47,    15,   128,     3,
      21,    22,    15,   147,    42,   135,    10,    19,   138,    13,
      14,    42,    16,    17,    26,    27,    15,   147,    15,    23,
      24,    21,    22,    44,    45,    46,    47,    15,    49,    19,
      34,    35,    36,    42,    38,    15,    26,    27,     5,    43,
      21,    22,    19,   101,    44,    45,    46,    47,    21,    22,
      42,    51,    21,    22,   149,    28,    29,    30,    31,    32,
      33,    -1,    -1,    44,    45,    46,    47,    42,    37,    -1,
      42,    44,    45,    46,    47,    44,    45,    46,    47,    42,
      42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    13,    14,    16,    17,    23,    24,    34,
      35,    36,    38,    43,    54,    55,    56,    57,    58,    59,
      61,    63,    65,    66,    67,    68,    69,    20,    50,    19,
      19,    19,     3,    14,    58,     3,     3,     3,     3,     4,
       5,     6,    45,    48,    50,    60,    62,    63,     7,     8,
      60,     3,     0,    55,    20,    50,    60,    60,    25,    60,
      71,    71,    71,    19,    14,    39,    60,    60,    51,    60,
      64,    21,    22,    44,    45,    46,    47,    37,    37,    37,
      39,    60,    60,    51,    71,    28,    29,    30,    31,    32,
      33,    72,    19,    26,    27,    19,    19,    71,    19,     3,
      49,    52,    51,    60,    60,    60,    60,    60,    60,     3,
       3,     3,    40,    41,    51,    60,    15,    71,    71,    15,
      15,    19,    71,    15,    64,    55,    55,    55,    15,    19,
      55,    42,    42,    42,    55,    15,    42,    11,    12,    70,
      42,    55,    19,    55,    42,    71,    42,    19,    55,    42,
      70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 100 "parser.y"
    {produce((yyvsp[(1) - (1)].statements));}
    break;

  case 3:
#line 104 "parser.y"
    {
        (yyval.statements) = malloc(sizeof(*(yyval.statements)));
        (yyval.statements)->type = (yyvsp[(1) - (1)].block)->type;;
        (yyval.statements)->body = (yyvsp[(1) - (1)].block)->node;
        (yyval.statements)->next = NULL;

        free((yyvsp[(1) - (1)].block));
    }
    break;

  case 4:
#line 112 "parser.y"
    {
        (yyval.statements) = malloc(sizeof(*(yyval.statements)));

        (yyval.statements)->type = (yyvsp[(1) - (2)].block)->type;
        (yyval.statements)->body = (yyvsp[(1) - (2)].block)->node;
        (yyval.statements)->next = (yyvsp[(2) - (2)].statements);

        free((yyvsp[(1) - (2)].block));
    }
    break;

  case 5:
#line 124 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = ASSIGNMENT;
        (yyval.block)->node = (yyvsp[(1) - (1)].assignment);
    }
    break;

  case 6:
#line 129 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = ARRAY_ASSIGNMENT;
        (yyval.block)->node = (yyvsp[(1) - (1)].arr_assign);
    }
    break;

  case 7:
#line 134 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = PRINT_CALL;
        (yyval.block)->node = (yyvsp[(1) - (1)].exprnode);
    }
    break;

  case 8:
#line 139 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = WHILE_LOOP;
        (yyval.block)->node = (yyvsp[(1) - (1)].whilenode);
    }
    break;

  case 9:
#line 144 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = FOREACH_LOOP;
        (yyval.block)->node = (yyvsp[(1) - (1)].foreachnode);
    }
    break;

  case 10:
#line 149 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = FOR_LOOP;
        (yyval.block)->node = (yyvsp[(1) - (1)].fornode);
    }
    break;

  case 11:
#line 154 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = IF_THEN_ELSE;
        (yyval.block)->node = (yyvsp[(1) - (1)].ifnode);
    }
    break;

  case 12:
#line 159 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = FUNCTION_CALL;
        (yyval.block)->node = (yyvsp[(1) - (1)].fnnode);
    }
    break;

  case 13:
#line 164 "parser.y"
    {
        (yyval.block) = malloc(sizeof(*(yyval.block)));
        (yyval.block)->type = EXIT_CALL;
    }
    break;

  case 15:
#line 175 "parser.y"
    {
        (yyval.assignment) = malloc(sizeof(*(yyval.assignment)));
        (yyval.assignment)->var_id = getId((yyvsp[(1) - (3)].strval));

        (yyval.assignment)->value = (yyvsp[(3) - (3)].exprnode);
    }
    break;

  case 16:
#line 184 "parser.y"
    {
		(yyval.arr_assign) = malloc(sizeof(*(yyval.arr_assign)));
		(yyval.arr_assign)->array = (yyvsp[(1) - (3)].exprnode);
		(yyval.arr_assign)->value = (yyvsp[(3) - (3)].exprnode);
	}
    break;

  case 17:
#line 192 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = STR_LITERAL;
        (yyval.exprnode)->left = malloc(strlen((yyvsp[(1) - (1)].strval)) + 1);
        strcpy((yyval.exprnode)->left, (yyvsp[(1) - (1)].strval));
    }
    break;

  case 18:
#line 198 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = INT_LITERAL;
        (yyval.exprnode)->left = malloc(sizeof(int));
        memcpy((yyval.exprnode)->left, &(yyvsp[(1) - (1)].intval), sizeof(int));
    }
    break;

  case 19:
#line 204 "parser.y"
    {
	 		(yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
			(yyval.exprnode)->type = FLOAT_LITERAL;
			(yyval.exprnode)->left = malloc(sizeof(float));
			memcpy((yyval.exprnode)->left, &(yyvsp[(1) - (1)].floatval), sizeof(float));
    }
    break;

  case 20:
#line 210 "parser.y"
    {
	 	(yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
	 	(yyval.exprnode)->type = ARRAY_LITERAL;
	 	(yyval.exprnode)->left = (yyvsp[(1) - (1)].explist);
	 	(yyval.exprnode)->right = malloc(sizeof(int));
	 	*((int*)(yyval.exprnode)->right) = list_length((yyvsp[(1) - (1)].explist));
	}
    break;

  case 21:
#line 217 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = VARIABLE;
        (yyval.exprnode)->left = malloc(sizeof(int));
        int id = getId((yyvsp[(1) - (1)].strval));
        memcpy((yyval.exprnode)->left, &id, sizeof(int));
    }
    break;

  case 22:
#line 224 "parser.y"
    {
        (yyval.exprnode) = (yyvsp[(1) - (1)].exprnode);
    }
    break;

  case 23:
#line 227 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = ARIT_SUM;
        (yyval.exprnode)->left = (yyvsp[(1) - (3)].exprnode);
        (yyval.exprnode)->right = (yyvsp[(3) - (3)].exprnode);
    }
    break;

  case 24:
#line 233 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = ARIT_SUB;
        (yyval.exprnode)->left = (yyvsp[(1) - (3)].exprnode);
        (yyval.exprnode)->right = (yyvsp[(3) - (3)].exprnode);
	}
    break;

  case 25:
#line 239 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = ARIT_PROD;
        (yyval.exprnode)->left = (yyvsp[(1) - (3)].exprnode);
        (yyval.exprnode)->right = (yyvsp[(3) - (3)].exprnode);
    }
    break;

  case 26:
#line 245 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = ARIT_PROD;
        (yyval.exprnode)->left = (yyvsp[(1) - (3)].exprnode);
        (yyval.exprnode)->right = (yyvsp[(3) - (3)].exprnode);
    }
    break;

  case 27:
#line 251 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = ARIT_DIV;
        (yyval.exprnode)->left = (yyvsp[(1) - (3)].exprnode);
        (yyval.exprnode)->right = (yyvsp[(3) - (3)].exprnode);
	}
    break;

  case 28:
#line 257 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = ARIT_DIV;
        (yyval.exprnode)->left = (yyvsp[(1) - (3)].exprnode);
        (yyval.exprnode)->right = (yyvsp[(3) - (3)].exprnode);
    }
    break;

  case 29:
#line 263 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = ARIT_UNARY_MINUS;
        (yyval.exprnode)->left = (yyvsp[(2) - (2)].exprnode);
    }
    break;

  case 30:
#line 268 "parser.y"
    {
        (yyval.exprnode) = (yyvsp[(2) - (3)].exprnode);
    }
    break;

  case 31:
#line 274 "parser.y"
    {
        (yyval.fnnode) = malloc(sizeof(*(yyval.fnnode)));
        (yyval.fnnode)->function = ARR_APPEND;
        (yyval.fnnode)->first = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->first) = getId((yyvsp[(4) - (4)].strval));
        (yyval.fnnode)->second = (yyvsp[(2) - (4)].exprnode);
    }
    break;

  case 32:
#line 281 "parser.y"
    {
        (yyval.fnnode) = malloc(sizeof(*(yyval.fnnode)));
        (yyval.fnnode)->function = TO_UPPER;
        (yyval.fnnode)->first = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->first) = getId((yyvsp[(2) - (4)].strval));
    }
    break;

  case 33:
#line 287 "parser.y"
    {
        (yyval.fnnode) = malloc(sizeof(*(yyval.fnnode)));
        (yyval.fnnode)->function = TO_LOWER;
        (yyval.fnnode)->first = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->first) = getId((yyvsp[(2) - (4)].strval));
    }
    break;

  case 34:
#line 293 "parser.y"
    {
        (yyval.fnnode) = malloc(sizeof(*(yyval.fnnode)));
        (yyval.fnnode)->function = INCREMENT;
        (yyval.fnnode)->first = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->first) = getId((yyvsp[(2) - (2)].strval));
    }
    break;

  case 35:
#line 299 "parser.y"
    {
        (yyval.fnnode) = malloc(sizeof(*(yyval.fnnode)));
        (yyval.fnnode)->function = DECREMENT;
        (yyval.fnnode)->first = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->first) = getId((yyvsp[(2) - (2)].strval));
    }
    break;

  case 36:
#line 305 "parser.y"
    {
        (yyval.fnnode) = malloc(sizeof(*(yyval.fnnode)));
        (yyval.fnnode)->function = SCAN_READ;
        (yyval.fnnode)->first = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->first) = 0;  // 0 = NUMERO
        (yyval.fnnode)->second = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->second) = getId((yyvsp[(4) - (4)].strval));
    }
    break;

  case 37:
#line 313 "parser.y"
    {
        (yyval.fnnode) = malloc(sizeof(*(yyval.fnnode)));
        (yyval.fnnode)->function = SCAN_READ;
        (yyval.fnnode)->first = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->first) = 1;  // 1 = TEXTO
        (yyval.fnnode)->second = malloc(sizeof(int));
        *((int*)(yyval.fnnode)->second) = getId((yyvsp[(4) - (4)].strval));
    }
    break;

  case 38:
#line 324 "parser.y"
    {
	    (yyval.explist) = (yyvsp[(2) - (3)].explist);
	}
    break;

  case 39:
#line 327 "parser.y"
    {
	  	(yyval.explist) = NULL;
	}
    break;

  case 40:
#line 333 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = INDEXED_ARRAY;

        (yyval.exprnode)->left = malloc(sizeof(int));
        int id = getId((yyvsp[(1) - (4)].strval));
        memcpy((yyval.exprnode)->left, &id, sizeof(int));

        (yyval.exprnode)->right = (yyvsp[(3) - (4)].exprnode);
    }
    break;

  case 41:
#line 343 "parser.y"
    {
        (yyval.exprnode) = malloc(sizeof(*(yyval.exprnode)));
        (yyval.exprnode)->type = NESTED_INDEXING;
        (yyval.exprnode)->left = (yyvsp[(1) - (4)].exprnode);
        (yyval.exprnode)->right = (yyvsp[(3) - (4)].exprnode);
    }
    break;

  case 42:
#line 352 "parser.y"
    {
        (yyval.explist) = malloc(sizeof(*(yyval.explist)));
        (yyval.explist)->expression = (yyvsp[(1) - (1)].exprnode);
        (yyval.explist)->next = NULL;
    }
    break;

  case 43:
#line 357 "parser.y"
    {
        (yyval.explist) = malloc(sizeof(*(yyval.explist)));
        (yyval.explist)->expression = (yyvsp[(1) - (3)].exprnode);
        (yyval.explist)->next = (yyvsp[(3) - (3)].explist);
    }
    break;

  case 44:
#line 365 "parser.y"
    {
		(yyval.exprnode) = (yyvsp[(2) - (2)].exprnode);
	}
    break;

  case 45:
#line 371 "parser.y"
    {
        (yyval.whilenode) = malloc(sizeof(*(yyval.whilenode)));
        (yyval.whilenode)->condition = (yyvsp[(3) - (7)].boolnode);
        (yyval.whilenode)->body = (yyvsp[(6) - (7)].statements);
    }
    break;

  case 46:
#line 376 "parser.y"
    {
        (yyval.whilenode) = malloc(sizeof(*(yyval.whilenode)));
        (yyval.whilenode)->condition = malloc(sizeof(*(yyval.whilenode)->condition));
        (yyval.whilenode)->condition->type = BOOL_NOT;
        (yyval.whilenode)->condition->left = (yyvsp[(3) - (7)].boolnode);
        (yyval.whilenode)->body = (yyvsp[(6) - (7)].statements);
    }
    break;

  case 47:
#line 386 "parser.y"
    {
        (yyval.foreachnode) = malloc(sizeof(*(yyval.foreachnode)));
        (yyval.foreachnode)->current = getId((yyvsp[(2) - (7)].strval));
        (yyval.foreachnode)->list = getId((yyvsp[(4) - (7)].strval));
        (yyval.foreachnode)->body = (yyvsp[(6) - (7)].statements);
    }
    break;

  case 48:
#line 395 "parser.y"
    {
        (yyval.fornode) = malloc(sizeof(*(yyval.fornode)));
        (yyval.fornode)->asig = (yyvsp[(2) - (9)].assignment);
        (yyval.fornode)->condition = (yyvsp[(5) - (9)].boolnode);
        (yyval.fornode)->body = (yyvsp[(8) - (9)].statements);
    }
    break;

  case 49:
#line 401 "parser.y"
    {
        (yyval.fornode) = malloc(sizeof(*(yyval.fornode)));
        (yyval.fornode)->asig = NULL;
        (yyval.fornode)->condition = (yyvsp[(4) - (8)].boolnode);
        (yyval.fornode)->body = (yyvsp[(7) - (8)].statements);
    }
    break;

  case 50:
#line 410 "parser.y"
    {
        (yyval.ifnode) = malloc(sizeof(*(yyval.ifnode)));
        (yyval.ifnode)->condition = (yyvsp[(3) - (7)].boolnode);
        (yyval.ifnode)->body = (yyvsp[(6) - (7)].statements);
        (yyval.ifnode)->elseif = NULL;

    }
    break;

  case 51:
#line 417 "parser.y"
    {
        (yyval.ifnode) = malloc(sizeof(*(yyval.ifnode)));
        (yyval.ifnode)->condition = (yyvsp[(3) - (8)].boolnode);
        (yyval.ifnode)->body = (yyvsp[(6) - (8)].statements);
        (yyval.ifnode)->elseif = (yyvsp[(8) - (8)].ifnode);
    }
    break;

  case 52:
#line 426 "parser.y"
    {
        (yyval.ifnode) = malloc(sizeof(*(yyval.ifnode)));
        (yyval.ifnode)->condition = (yyvsp[(3) - (6)].boolnode);
        (yyval.ifnode)->body = (yyvsp[(5) - (6)].statements);
        (yyval.ifnode)->elseif = NULL;
    }
    break;

  case 53:
#line 432 "parser.y"
    {
        (yyval.ifnode) = malloc(sizeof(*(yyval.ifnode)));
        (yyval.ifnode)->condition = (yyvsp[(3) - (7)].boolnode);
        (yyval.ifnode)->body = (yyvsp[(5) - (7)].statements);
        (yyval.ifnode)->elseif = (yyvsp[(7) - (7)].ifnode);
    }
    break;

  case 54:
#line 438 "parser.y"
    {
        (yyval.ifnode) = malloc(sizeof(*(yyval.ifnode)));
        (yyval.ifnode)->body = (yyvsp[(2) - (3)].statements);
        (yyval.ifnode)->elseif = NULL;
        (yyval.ifnode)->condition = malloc(sizeof(*(yyval.ifnode)->condition));
        (yyval.ifnode)->condition->type = TRUE_LITERAL;
    }
    break;

  case 55:
#line 448 "parser.y"
    {
        (yyval.boolnode) = malloc(sizeof(*(yyval.boolnode)));
        (yyval.boolnode)->type = (yyvsp[(2) - (3)].boolop);

        (yyval.boolnode)->left = (yyvsp[(1) - (3)].exprnode);
        (yyval.boolnode)->right = (yyvsp[(3) - (3)].exprnode);
    }
    break;

  case 56:
#line 455 "parser.y"
    {
        (yyval.boolnode) = malloc(sizeof(*(yyval.boolnode)));
        (yyval.boolnode)->type = BOOL_OR;

        (yyval.boolnode)->left = (yyvsp[(1) - (3)].boolnode);
        (yyval.boolnode)->right = (yyvsp[(3) - (3)].boolnode);
    }
    break;

  case 57:
#line 462 "parser.y"
    {
        (yyval.boolnode) = malloc(sizeof(*(yyval.boolnode)));
        (yyval.boolnode)->type = BOOL_AND;

        (yyval.boolnode)->left = (yyvsp[(1) - (3)].boolnode);
        (yyval.boolnode)->right = (yyvsp[(3) - (3)].boolnode);

    }
    break;

  case 58:
#line 470 "parser.y"
    {
        (yyval.boolnode) = malloc(sizeof(*(yyval.boolnode)));
        (yyval.boolnode)->type = BOOL_NOT;

        (yyval.boolnode)->left = (yyvsp[(2) - (2)].boolnode);
        (yyval.boolnode)->right = NULL;
    }
    break;

  case 59:
#line 480 "parser.y"
    { (yyval.boolop) = COMP_LE;  }
    break;

  case 60:
#line 481 "parser.y"
    { (yyval.boolop) = COMP_LT;  }
    break;

  case 61:
#line 482 "parser.y"
    { (yyval.boolop) = COMP_GE;  }
    break;

  case 62:
#line 483 "parser.y"
    { (yyval.boolop) = COMP_GT;  }
    break;

  case 63:
#line 484 "parser.y"
    { (yyval.boolop) = COMP_EQ;  }
    break;

  case 64:
#line 485 "parser.y"
    { (yyval.boolop) = COMP_NEQ; }
    break;


/* Line 1267 of yacc.c.  */
#line 2153 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 488 "parser.y"


int main() {
	printf("#include <stdlib.h>\n");

	printf("#include \"variables.h\"\n");

	printf("#include \"arrays.h\"\n");

	printf("#include \"utils.h\"\n");

    printf("int main(void) { \n\n");

    // Start the Parsing (yacc)
    yyparse();

    printf("}\n");

    return 0;
}

int getId(char *strId) {
	int i;

	for(i = 0 ; i < MAX_IDS && identifiers[i] != NULL ; i++) {
		if(strcmp(identifiers[i], strId) == 0) {
			return i;
		}
	}

	if(i == MAX_IDS) {
		return -1;
	}

	identifiers[i] = malloc(strlen(strId) + 1);
	strcpy(identifiers[i], strId);
	printf("map_name(%d, \"%s\");\n", i, strId);

	return i;
}

int list_length(ExpressionList *list) {
	int len = 0;
	while(list != NULL) {
		len++;
		list = list->next;
	}
	return len;
}

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
	fflush(stdout);
	fprintf(stderr, "***%s\n", s);
}

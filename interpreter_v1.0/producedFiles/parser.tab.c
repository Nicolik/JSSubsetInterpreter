/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 14 "parser.y" /* yacc.c:339  */


void yyerror(char *s, ...);

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../ast.h"
#include "../funcs.h"

struct symbol *symbTEMP; /* Questo puntatore a symbol table viene utilizzato per memorizzare temporaneamente i vettori */
/* the default evaluator will, by default, assign the most recently evaluated expression to the 
   special variable _ (underscore). */

#line 81 "producedFiles/parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PRODUCEDFILES_PARSER_TAB_H_INCLUDED
# define YY_YY_PRODUCEDFILES_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    NAME = 259,
    BIFUNC = 260,
    STREXP = 261,
    STRERR = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    DO = 266,
    FOR = 267,
    FUNCTION = 268,
    RETURN = 269,
    LENGTH = 270,
    TYPEOF = 271,
    PUSH = 272,
    POP = 273,
    READ = 274,
    ERRNAME = 275,
    INCREMENT = 276,
    DECREMENT = 277,
    ASGNSUM = 278,
    ASGNDIF = 279,
    ASGNPROD = 280,
    ASGNDIV = 281,
    ASGNMOD = 282,
    OR = 283,
    AND = 284,
    CMP = 285,
    LEFTSHIFT = 286,
    RIGHTSHIFT = 287,
    UMINUS = 288,
    UPLUS = 289,
    NOT = 290,
    POW = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:355  */

  struct ast *a;
  double d;
  char *str;
  struct symbol *sym;		/* which symbol */
  struct symlist *sl;
  struct arrayElemList *al;
  int fn;			/* which function */

#line 168 "producedFiles/parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PRODUCEDFILES_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "producedFiles/parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   818

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,    33,     2,
      49,    50,    39,    37,    55,    38,    56,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    31,    52,    45,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    24,    25,
      26,    27,    28,    29,    30,    34,    35,    36,    42,    43,
      44,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    93,    94,    95,    98,    99,   102,   103,
     104,   107,   108,   112,   113,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   132,   133,   134,   137,   138,   139,
     140,   141,   142,   145,   146,   147,   148,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   179,   180,   181,
     182,   183,   184,   187,   188,   191,   194,   199,   207,   208,
     211,   212,   213,   216,   217,   220,   221,   224,   232,   233,
     236,   242,   248,   249,   252,   253,   259,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "NAME", "BIFUNC", "STREXP",
  "STRERR", "IF", "ELSE", "WHILE", "DO", "FOR", "FUNCTION", "RETURN",
  "LENGTH", "TYPEOF", "PUSH", "POP", "READ", "ERRNAME", "INCREMENT",
  "DECREMENT", "'='", "ASGNSUM", "ASGNDIF", "ASGNPROD", "ASGNDIV",
  "ASGNMOD", "OR", "AND", "'|'", "'^'", "'&'", "CMP", "LEFTSHIFT",
  "RIGHTSHIFT", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "UPLUS",
  "NOT", "'~'", "POW", "\"then\"", "';'", "'('", "')'", "'{'", "'}'",
  "'['", "']'", "','", "'.'", "$accept", "stmt", "branchstmt", "loopstmt",
  "bodylist", "list", "arithmexp", "logicexp", "bitwisexp", "incrmentexp",
  "exp", "assignexp", "arraydeclright", "arraydecl", "arraydecls",
  "arrayelemsast", "arrpushpop", "explist", "symlist", "functionbody",
  "returnstmt", "funcdecl", "funcnoparamdecl", "funcdecls", "interprlist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    61,   278,   279,   280,   281,   282,   283,
     284,   124,    94,    38,   285,   286,   287,    43,    45,    42,
      47,    37,   288,   289,   290,   126,   291,   292,    59,    40,
      41,   123,   125,    91,    93,    44,    46
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -131,   152,  -131,  -131,  -131,    -9,   -39,  -131,  -131,   -38,
     -28,   172,   -25,    33,   -11,   -10,  -131,    37,    39,   391,
     391,   391,   391,   391,    66,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,   642,  -131,  -131,  -131,    -3,  -131,  -131,  -131,
    -131,  -131,  -131,   279,   391,   391,   391,   391,   391,   335,
     391,     5,   391,   391,   391,  -131,  -131,    38,    45,     1,
     299,     2,  -131,  -131,    53,     8,     8,     8,     8,   466,
    -131,   386,    29,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,  -131,  -131,   105,
    -131,   105,   105,   105,   105,   105,  -131,   413,    34,   440,
    -131,    40,    41,   488,   510,   532,   223,    48,   284,    51,
       3,   554,    57,  -131,   391,  -131,   391,  -131,   701,   717,
     732,   746,   759,   772,    54,    54,    82,    82,     8,     8,
       8,     8,   391,  -131,    28,   391,    58,  -131,   172,   172,
    -131,  -131,   391,   391,    46,    61,    63,  -131,  -131,  -131,
    -131,   391,   576,  -131,   107,  -131,   598,   662,   114,  -131,
      68,   105,  -131,   172,  -131,   391,  -131,   243,    74,  -131,
    -131,   620,   355,  -131,  -131,    75,   172,  -131,   682,  -131,
    -131,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      84,     0,     1,    87,    41,    45,     0,    54,    55,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     2,     3,    38,    39,
      40,    53,     0,    47,    67,     5,     0,    52,    82,    83,
      86,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    12,     0,     0,     0,
       0,     0,    35,    36,    45,    23,    22,    26,    30,     0,
      64,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    65,    57,
      66,    58,    59,    60,    61,    62,    49,    73,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,    21,     0,    63,    25,    24,
      27,    28,    29,    37,    31,    32,    15,    16,    17,    18,
      19,    20,     0,    48,    50,     0,     0,    42,     0,     0,
      11,    14,     0,     0,    75,     0,     0,    43,    44,    69,
      74,     0,     0,    72,     6,     8,     0,     0,     0,    13,
       0,    51,    71,     0,     9,     0,    76,     0,     0,    13,
       7,     0,     0,    77,    81,     0,     0,    78,     0,    80,
      10,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,    -1,  -131,  -131,  -130,    76,  -131,  -131,  -131,  -131,
     -18,    71,    87,  -131,    72,    32,  -131,    17,    -8,    -2,
    -131,  -131,  -131,  -131,  -131
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    56,    26,    27,    57,   167,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    72,    37,    98,   146,   168,
     173,    38,    39,    40,     1
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    65,    66,    67,    68,    69,    71,   144,   154,   155,
      52,    53,    41,    42,    43,    44,    45,    46,    47,    48,
     100,    54,   101,   102,    58,    89,    91,    92,    93,    94,
      95,    97,    99,   170,   103,   104,   105,    59,    60,    61,
      49,    62,   111,    63,    50,    88,   180,    51,   107,   108,
     110,   151,   113,   145,    86,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     4,
      64,     6,     7,     8,    41,    42,   114,    44,    45,    46,
      47,    48,    14,   117,   133,    15,    16,    17,    18,   135,
     136,    81,    82,    83,    84,    85,    89,   142,    71,   143,
      86,   158,    49,    19,    20,   141,    50,   148,   153,    51,
      21,    22,   159,   160,    97,    23,   163,   152,   144,   169,
      70,    83,    84,    85,   156,   157,   174,   179,    86,   109,
      90,   106,   112,   161,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   171,   149,   150,
     166,    86,     2,     3,   178,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,    13,   141,   175,    14,     0,
       0,    15,    16,    17,    18,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,     0,     0,    14,    19,
      20,    15,    16,    17,    18,     0,    21,    22,     0,     0,
       0,    23,     0,     0,     0,    24,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    21,    22,     0,     0,
       0,    23,     0,    55,     0,    24,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,     0,     0,    14,
       0,     0,    15,    16,    17,    18,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,   172,     0,    14,
      19,    20,    15,    16,    17,    18,     0,    21,    22,     0,
       0,     0,    23,     0,     0,   140,    24,     0,     0,     0,
      19,    20,     4,    64,     6,     7,     8,    21,    22,     0,
       0,     0,    23,     0,     0,    14,    24,     0,    15,    16,
      17,    18,     4,     5,     6,     7,     8,   114,    44,    45,
      46,    47,    48,     0,     0,    14,    19,    20,    15,    16,
      17,    18,     0,    21,    22,     0,     0,     0,    23,     0,
       0,     0,    24,     0,     0,     0,    19,    20,     4,    64,
       6,     7,     8,    21,    22,     0,     0,     0,    23,     0,
       0,    14,    24,     0,    15,    16,    17,    18,     4,    64,
       6,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    19,    20,    15,    16,    17,    18,     0,    21,
      22,     0,     0,     0,    23,    96,     0,     0,     0,     0,
       0,     0,    19,    20,     4,    64,     6,     7,     8,    21,
      22,     0,     0,   177,    23,     0,     0,    14,     0,     0,
      15,    16,    17,    18,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    19,    20,
       0,     0,    86,     0,     0,    21,    22,     0,     0,     0,
      23,   116,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,   132,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,     0,     0,   134,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,    86,     0,     0,     0,   115,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,    86,     0,     0,     0,   137,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,    86,     0,     0,     0,
     138,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86,     0,
       0,     0,   139,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
      86,     0,     0,     0,   147,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,    86,     0,     0,     0,   162,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,    86,     0,     0,     0,   164,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,    86,     0,     0,     0,
     176,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86,     0,
      87,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86,     0,
     165,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86,     0,
     181,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,    86,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,    86,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,    86,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,    86,    -1,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
       1,    19,    20,    21,    22,    23,    24,     4,   138,   139,
      49,    49,    21,    22,    23,    24,    25,    26,    27,    28,
      15,    49,    17,    18,    49,    43,    44,    45,    46,    47,
      48,    49,    50,   163,    52,    53,    54,     4,    49,    49,
      49,     4,    60,     4,    53,    48,   176,    56,    10,     4,
      49,    23,    50,    50,    46,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     3,
       4,     5,     6,     7,    21,    22,    23,    24,    25,    26,
      27,    28,    16,    54,    50,    19,    20,    21,    22,    49,
      49,    37,    38,    39,    40,    41,   114,    49,   116,    48,
      46,    55,    49,    37,    38,   106,    53,    50,    50,    56,
      44,    45,    51,    50,   132,    49,     9,   135,     4,    51,
      54,    39,    40,    41,   142,   143,    52,    52,    46,    58,
      43,    55,    60,   151,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   165,   116,   132,
     158,    46,     0,     1,   172,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,   167,   169,    16,    -1,
      -1,    19,    20,    21,    22,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    -1,    -1,    -1,    16,    37,
      38,    19,    20,    21,    22,    -1,    44,    45,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    49,    -1,    51,    -1,    53,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    19,    20,    21,    22,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    12,    -1,    14,    -1,    16,
      37,    38,    19,    20,    21,    22,    -1,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,    -1,
      37,    38,     3,     4,     5,     6,     7,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    16,    53,    -1,    19,    20,
      21,    22,     3,     4,     5,     6,     7,    23,    24,    25,
      26,    27,    28,    -1,    -1,    16,    37,    38,    19,    20,
      21,    22,    -1,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    37,    38,     3,     4,
       5,     6,     7,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    16,    53,    -1,    19,    20,    21,    22,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    37,    38,    19,    20,    21,    22,    -1,    44,
      45,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,     3,     4,     5,     6,     7,    44,
      45,    -1,    -1,    48,    49,    -1,    -1,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    37,    38,
      -1,    -1,    46,    -1,    -1,    44,    45,    -1,    -1,    -1,
      49,    55,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    50,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    50,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,
      48,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,
      48,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,
      48,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    81,     0,     1,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    13,    16,    19,    20,    21,    22,    37,
      38,    44,    45,    49,    53,    58,    59,    60,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    73,    78,    79,
      80,    21,    22,    23,    24,    25,    26,    27,    28,    49,
      53,    56,    49,    49,    49,    51,    58,    61,    49,     4,
      49,    49,     4,     4,     4,    67,    67,    67,    67,    67,
      54,    67,    72,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    46,    48,    48,    67,
      69,    67,    67,    67,    67,    67,    50,    67,    74,    67,
      15,    17,    18,    67,    67,    67,    62,    10,     4,    68,
      49,    67,    71,    50,    23,    50,    55,    54,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    55,    50,    54,    49,    49,    50,    50,    50,
      52,    58,    49,    48,     4,    50,    75,    50,    50,    72,
      74,    23,    67,    50,    61,    61,    67,    67,    55,    51,
      50,    67,    50,     9,    50,    48,    75,    62,    76,    51,
      61,    67,    14,    77,    52,    76,    50,    48,    67,    52,
      61,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    71,    71,    72,    72,
      73,    73,    73,    74,    74,    75,    75,    76,    77,    77,
      78,    79,    80,    80,    81,    81,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     5,     7,     5,     6,
       9,     3,     1,     0,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     2,     3,     3,     3,
       2,     3,     3,     2,     2,     2,     2,     3,     1,     1,
       1,     1,     4,     4,     4,     1,     1,     1,     4,     3,
       4,     6,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     1,     3,
       3,     6,     5,     1,     3,     1,     3,     2,     2,     3,
       8,     7,     1,     1,     0,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 92 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1855 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 93 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1861 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 94 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[-1].a); }
#line 1867 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 95 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1873 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 98 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newflow('I', (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1879 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 99 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newflow('I', (yyvsp[-4].a), (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1885 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 102 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newflow('W', (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1891 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 103 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newflow(NT_dowhle, (yyvsp[-1].a), (yyvsp[-4].a), NULL); }
#line 1897 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 104 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newflowFor((yyvsp[-4].a), (yyvsp[0].a), (yyvsp[-6].a), (yyvsp[-2].a)); }
#line 1903 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 107 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[-1].a); }
#line 1909 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 108 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1915 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 112 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = NULL; }
#line 1921 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 113 "parser.y" /* yacc.c:1661  */
    {    
                                      if ((yyvsp[-1].a) == NULL)
                                        (yyval.a) = (yyvsp[0].a);
                                      else
                                        (yyval.a) = newast('L', (yyvsp[-1].a), (yyvsp[0].a));
                                    }
#line 1932 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 121 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('+', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1938 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 122 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('-', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1944 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 123 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('*', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1950 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 124 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('/', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1956 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 125 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('%', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1962 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 126 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast(NT_pow, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1968 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 127 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[-1].a); }
#line 1974 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 128 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('M', (yyvsp[0].a), NULL); }
#line 1980 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 129 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1986 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 132 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('&', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1992 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 133 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('O', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1998 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 134 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('!', (yyvsp[0].a), NULL); }
#line 2004 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 137 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('|', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2010 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 138 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('^', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2016 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 139 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('B', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2022 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 140 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('~', (yyvsp[0].a), NULL); }
#line 2028 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 141 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast(NT_lshift, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2034 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 142 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast(NT_rshift, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2040 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 145 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newIncrement((yyvsp[-1].sym), 0); }
#line 2046 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 146 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newDecrement((yyvsp[-1].sym), 0); }
#line 2052 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 147 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newIncrement((yyvsp[0].sym), 1); }
#line 2058 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 148 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newDecrement((yyvsp[0].sym), 1); }
#line 2064 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 151 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newcmp((yyvsp[-1].fn), (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2070 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 152 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 2076 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 153 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 2082 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 154 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 2088 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 155 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newnum((yyvsp[0].d));  }
#line 2094 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 156 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a)); }
#line 2100 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 157 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newTypeOfExp((yyvsp[-1].a)); }
#line 2106 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 158 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newTypeOfExp((yyvsp[-1].a)); }
#line 2112 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 159 "parser.y" /* yacc.c:1661  */
    { 
                                  if((yyvsp[0].sym)->type == STT_NOTYPE && (yyvsp[0].sym)->scope != ST_function) {
                                    yyerror("Semantic error. The variable '%s' is not defined yet.", (yyvsp[0].sym)->name); YYERROR; 
                                  }
                                  debug_print("new name '%s' used in exp with scope: '%d' (0 = global, 1 = function) \n", (yyvsp[0].sym)->name, (yyvsp[0].sym)->scope);
                                  (yyval.a) = newref((yyvsp[0].sym)); 
                              }
#line 2124 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 166 "parser.y" /* yacc.c:1661  */
    { YYERROR; }
#line 2130 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 167 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 2136 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 168 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newcall((yyvsp[-3].sym), (yyvsp[-1].a)); }
#line 2142 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 169 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newcall((yyvsp[-2].sym), NULL); }
#line 2148 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 170 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newarrayelast((yyvsp[-3].sym), (yyvsp[-1].a)); }
#line 2154 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 171 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newasgnArray((yyvsp[-5].sym), (yyvsp[-3].a), (yyvsp[0].a)); }
#line 2160 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 172 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 2166 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 173 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[0].a); }
#line 2172 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 174 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newstring((yyvsp[0].str));  debug_print("Defined string exp\n");  }
#line 2178 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 175 "parser.y" /* yacc.c:1661  */
    { YYERROR; }
#line 2184 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 176 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newinput(); }
#line 2190 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 179 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newasgn((yyvsp[-2].sym), (yyvsp[0].a)); }
#line 2196 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 180 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newasgnsumdif((yyvsp[-2].sym), (yyvsp[0].a), 0); }
#line 2202 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 181 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newasgnsumdif((yyvsp[-2].sym), (yyvsp[0].a), 1); }
#line 2208 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 182 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newasgnsumdif((yyvsp[-2].sym), (yyvsp[0].a), 2); }
#line 2214 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 183 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newasgnsumdif((yyvsp[-2].sym), (yyvsp[0].a), 3); }
#line 2220 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 184 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newasgnsumdif((yyvsp[-2].sym), (yyvsp[0].a), 4); }
#line 2226 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 187 "parser.y" /* yacc.c:1661  */
    { (yyval.al) = (yyvsp[-1].al); }
#line 2232 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 188 "parser.y" /* yacc.c:1661  */
    { (yyval.al) = NULL; }
#line 2238 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 194 "parser.y" /* yacc.c:1661  */
    { 
                                              (yyval.a) = dodefArrayAST((yyvsp[-2].sym), (yyvsp[0].al)); 
                                              printf(KMAG "Defined array %s\n" KNRM, (yyvsp[-2].sym)->name); 
                                              debug_print("array declaration \n"); 
                                              }
#line 2248 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 199 "parser.y" /* yacc.c:1661  */
    {   
                                              symbTEMP = lookup("_");
                                              (yyval.a) = dodefArrayAST(symbTEMP, (yyvsp[0].al)); 
                                              printf(KMAG "Defined array\n" KNRM); 
                                              debug_print("array declaration \n"); 
                                              }
#line 2259 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 207 "parser.y" /* yacc.c:1661  */
    { (yyval.al) = newElemListAST ((yyvsp[0].a), NULL); debug_print("AST elem list allocation LAST \n"); }
#line 2265 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 208 "parser.y" /* yacc.c:1661  */
    { (yyval.al) = newElemListAST ((yyvsp[-2].a), (yyvsp[0].al)); debug_print("AST elem list allocation \n"); }
#line 2271 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 211 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = getSizeOfArrayNameAST((yyvsp[-2].sym)); }
#line 2277 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 212 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = makePushOnArrayAST((yyvsp[-5].sym), (yyvsp[-1].a)); }
#line 2283 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 213 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = makePopFromArrayAST((yyvsp[-4].sym)); }
#line 2289 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 217 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newast('L', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2295 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 220 "parser.y" /* yacc.c:1661  */
    { (yyvsp[0].sym)->scope = ST_function; (yyval.sl) = newsymlist((yyvsp[0].sym), NULL); debug_print("sym list allocation LAST \n");}
#line 2301 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 221 "parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].sym)->scope = ST_function; (yyval.sl) = newsymlist((yyvsp[-2].sym), (yyvsp[0].sl));   debug_print("sym list allocation \n");}
#line 2307 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 224 "parser.y" /* yacc.c:1661  */
    { 
                                        if ((yyvsp[-1].a) == NULL)
                                          (yyval.a) = (yyvsp[0].a);
                                        else
                                          (yyval.a) = newast('L', (yyvsp[-1].a), (yyvsp[0].a)); 
                                      }
#line 2318 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 232 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = newnum(0); }
#line 2324 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 233 "parser.y" /* yacc.c:1661  */
    { (yyval.a) = (yyvsp[-1].a); }
#line 2330 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 236 "parser.y" /* yacc.c:1661  */
    {
                                                                  dodef((yyvsp[-6].sym), (yyvsp[-4].sl), (yyvsp[-1].a)); 
                                                                  printf(KMAG "Defined function %s\n", (yyvsp[-6].sym)->name);                                                              
                                                                }
#line 2339 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 242 "parser.y" /* yacc.c:1661  */
    {
                                                                  dodef((yyvsp[-5].sym), NULL, (yyvsp[-1].a));
                                                                  printf(KMAG "Defined function %s\n", (yyvsp[-5].sym)->name);                                                              
                                                                }
#line 2348 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 253 "parser.y" /* yacc.c:1661  */
    {
                                if(debug) dumpast((yyvsp[0].a), 0);                      
                                handleOutputSwitchStruct((yyvsp[0].a));
                                if(interactiveOrFile) printf(KNRM "> ");
                                treefree((yyvsp[0].a));
                              }
#line 2359 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 259 "parser.y" /* yacc.c:1661  */
    {
                              if(interactiveOrFile) printf(KNRM "> ");
                            }
#line 2367 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 263 "parser.y" /* yacc.c:1661  */
    {  if(interactiveOrFile) printf("> "); /*yyerrok; */ }
#line 2373 "producedFiles/parser.tab.c" /* yacc.c:1661  */
    break;


#line 2377 "producedFiles/parser.tab.c" /* yacc.c:1661  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 266 "parser.y" /* yacc.c:1906  */


void yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  if (numberOfErrors < TOOMANYERRORS) {
    // fprintf(stderr, KRED "Line %d: error: ", yylineno);
    fprintf(stderr, KRED "Line %d:[%d-%d]: error: ", yylineno, yylloc.first_column, yylloc.last_column);
    vfprintf(stderr, s, ap);
    fprintf(stderr, KNRM "\n");
  } else {
    fprintf(stderr, KRED "Too many errors in your program (more than %d). Exit.\n" KNRM, TOOMANYERRORS);
    exit(0);
  }
  
  numberOfErrors++;
}

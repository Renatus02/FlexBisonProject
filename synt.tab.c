
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "synt.y"

    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    extern char currentScope[10];
    extern char typeidf[10];
    void erreur_dd(char* idf);
    void erreur_nondec(char* idf);
    char *determiner_type(char* type1, char* type2);
    char *getidfType(char entite[], char scope[]);
    int nb_ligne = 1;
    int nb_colonne = 1;



/* Line 189 of yacc.c  */
#line 89 "synt.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     aff = 258,
     point = 259,
     po = 260,
     pf = 261,
     vg = 262,
     idf = 263,
     pvg = 264,
     mc_then = 265,
     mc_if = 266,
     mc_else = 267,
     mc_program = 268,
     mc_endif = 269,
     mc_character = 270,
     mc_real = 271,
     mc_enddo = 272,
     mc_read = 273,
     mc_write = 274,
     mc_integer = 275,
     mc_endr = 276,
     mc_routine = 277,
     mc_equivalence = 278,
     mc_dowhile = 279,
     mc_end = 280,
     mc_call = 281,
     mc_dimension = 282,
     mc_logical = 283,
     cst_char = 284,
     opar_plus = 285,
     opar_moins = 286,
     opar_div = 287,
     opar_mult = 288,
     cst_bool = 289,
     cst_int = 290,
     cst_real = 291,
     op_gt = 292,
     op_lt = 293,
     op_eq = 294,
     op_ge = 295,
     op_le = 296,
     op_and = 297,
     op_or = 298,
     op_ne = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "synt.y"
 
   int entier; 
   float reel;
   char* str;
   struct 
   {
       char *type;
   }exp;



/* Line 214 of yacc.c  */
#line 181 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "synt.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   280

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,     9,    14,    18,    19,    28,
      29,    40,    41,    50,    55,    59,    61,    63,    65,    67,
      69,    71,    73,    77,    79,    83,    90,    99,   100,   105,
     110,   111,   113,   117,   123,   131,   135,   139,   146,   155,
     157,   159,   161,   163,   167,   171,   175,   179,   183,   187,
     189,   193,   197,   202,   209,   215,   221,   227,   232,   237,
     239,   241,   245,   249,   259,   269,   275,   281,   283,   287,
     290,   293,   296,   298,   300,   303,   306,   307,   314,   323,
     328,   330,   332,   334,   336,   338,   340,   342,   344,   346
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    50,    46,    -1,    47,    -1,    -1,    13,
       8,    48,    49,    -1,    59,    71,    25,    -1,    -1,    57,
      22,     8,    51,     5,    58,     6,    54,    -1,    -1,    15,
      22,     8,    52,    33,    74,     5,    58,     6,    54,    -1,
      -1,    15,    22,     8,    53,     5,    58,     6,    54,    -1,
      59,    71,    55,    21,    -1,     8,     3,    62,    -1,    30,
      -1,    31,    -1,    33,    -1,    20,    -1,    16,    -1,    28,
      -1,     8,    -1,    58,     7,     8,    -1,    74,    -1,    58,
       7,    74,    -1,    58,     7,     8,     5,    74,     6,    -1,
      58,     7,     8,     5,    74,     7,    74,     6,    -1,    -1,
      59,    57,    60,     9,    -1,    59,    15,    60,     9,    -1,
      -1,     8,    -1,    60,     7,     8,    -1,    60,    27,     5,
      74,     6,    -1,    60,    27,     5,    74,     7,    74,     6,
      -1,    60,    33,    74,    -1,     8,     3,    62,    -1,     8,
       5,    74,     6,     3,    62,    -1,     8,     5,    74,     7,
      74,     6,     3,    62,    -1,    74,    -1,     8,    -1,    29,
      -1,    34,    -1,    62,    56,     8,    -1,    62,    32,     8,
      -1,    62,    56,    74,    -1,    62,    32,    36,    -1,    62,
      32,    35,    -1,     5,    62,     6,    -1,    63,    -1,    62,
      56,    29,    -1,    62,    32,    29,    -1,    62,     5,    74,
       6,    -1,    62,     5,    74,     7,    74,     6,    -1,    62,
      56,     5,    62,     6,    -1,    62,    32,     5,    62,     6,
      -1,    26,     8,     5,    58,     6,    -1,    18,     5,     8,
       6,    -1,    19,     5,    66,     6,    -1,    29,    -1,     8,
      -1,    66,     7,    29,    -1,    66,     7,     8,    -1,    11,
       5,    68,     6,    10,    71,    12,    71,    14,    -1,    11,
       5,    34,     6,    10,    71,    12,    71,    14,    -1,    62,
       4,    76,     4,    62,    -1,    68,     4,    75,     4,    69,
      -1,    69,    -1,     5,    68,     6,    -1,    61,     9,    -1,
      65,     9,    -1,    64,     9,    -1,    67,    -1,    72,    -1,
      73,     9,    -1,    71,    70,    -1,    -1,    24,     5,    68,
       6,    71,    17,    -1,    23,     5,    58,     6,     7,     5,
      58,     6,    -1,    23,     5,    58,     6,    -1,    35,    -1,
      36,    -1,    42,    -1,    43,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    37,    43,    43,    51,    55,    55,    68,
      68,    79,    79,    92,    96,   100,   102,   104,   108,   110,
     112,   116,   118,   120,   122,   124,   126,   128,   132,   134,
     136,   140,   145,   152,   154,   156,   160,   166,   172,   181,
     183,   188,   190,   192,   196,   200,   204,   208,   213,   215,
     218,   221,   224,   227,   230,   232,   237,   244,   248,   252,
     254,   256,   258,   262,   264,   268,   270,   272,   276,   280,
     282,   284,   286,   288,   290,   294,   296,   300,   304,   306,
     310,   312,   316,   318,   322,   324,   326,   328,   330,   332
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "aff", "point", "po", "pf", "vg", "idf",
  "pvg", "mc_then", "mc_if", "mc_else", "mc_program", "mc_endif",
  "mc_character", "mc_real", "mc_enddo", "mc_read", "mc_write",
  "mc_integer", "mc_endr", "mc_routine", "mc_equivalence", "mc_dowhile",
  "mc_end", "mc_call", "mc_dimension", "mc_logical", "cst_char",
  "opar_plus", "opar_moins", "opar_div", "opar_mult", "cst_bool",
  "cst_int", "cst_real", "op_gt", "op_lt", "op_eq", "op_ge", "op_le",
  "op_and", "op_or", "op_ne", "$accept", "PROG", "PP", "$@1",
  "CORP_PROGRAM", "ROUTINE", "$@2", "$@3", "$@4", "CORP_FONCTION",
  "RETURN", "OPAR", "TYPE", "LIST_PARAMETRE", "LIST_DECLARATION",
  "DECLARATION", "AFFECT", "EXPRESSION", "CALL", "READ", "WRITE",
  "WRITE_ARGS", "CONDITION", "exp_cnd", "LALR", "INSTRUCTION",
  "LIST_INSTRUCTION", "BOUCLE", "EQ", "CST", "OPLOG", "OPCOMP", 0
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    48,    47,    49,    51,    50,    52,
      50,    53,    50,    54,    55,    56,    56,    56,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    65,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    69,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     4,     3,     0,     8,     0,
      10,     0,     8,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     6,     8,     0,     4,     4,
       0,     1,     3,     5,     7,     3,     3,     6,     8,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     4,     6,     5,     5,     5,     4,     4,     1,
       1,     3,     3,     9,     9,     5,     5,     1,     3,     2,
       2,     2,     1,     1,     2,     2,     0,     6,     8,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    19,    18,    20,     0,     3,     0,     0,
       4,     0,     1,     2,     0,    30,     9,     7,     5,    76,
       0,     0,     0,     0,     0,     0,     0,    27,    27,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,    72,    75,    73,     0,    80,    81,     0,    21,
       0,    23,     0,     0,    29,     0,     0,    28,     0,     0,
       0,     0,     0,    27,     0,    69,    71,    70,    74,    27,
      30,     0,    30,    32,     0,    35,     0,    40,     0,    41,
      42,    36,    49,    39,     0,     0,    42,     0,     0,    67,
       0,    60,    59,     0,     0,     0,     0,    12,    76,    22,
      24,     8,     0,     0,     0,     0,    15,    16,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,     0,    79,    76,    30,     0,     0,    33,     0,    48,
      27,     0,     0,    44,    51,    47,    46,     0,    43,    50,
      45,     0,     0,    68,    76,    84,    85,    86,    87,    88,
      89,     0,    82,    83,     0,    76,    62,    61,     0,     0,
      10,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      37,     0,     0,     0,     0,     0,    27,    77,     0,    13,
      25,     0,    34,    56,     0,    55,    54,     0,    76,    65,
       0,    66,    76,     0,    14,     0,    53,    38,     0,     0,
      78,    26,    64,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    15,    18,     8,    22,    20,    21,    97,
     162,   110,     9,    50,    98,    30,    39,    87,    82,    40,
      41,    93,    42,   114,    89,    43,    25,    44,    45,    83,
     154,   151
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
      -4,    18,     1,   -92,   -92,   -92,    52,   -92,    -4,    40,
     -92,    63,   -92,   -92,    73,   -92,    85,   -92,   -92,    -1,
      62,    94,    98,   106,   106,   173,    31,     0,     0,   -92,
     121,   160,    15,   113,   135,   144,   148,   157,   -92,   117,
     159,   161,   -92,   -92,   -92,   181,   -92,   -92,   195,   -92,
      70,   -92,   100,   205,   -92,   198,    31,   -92,    20,    31,
      34,   211,    21,     0,    86,   -92,   -92,   -92,   -92,     0,
     -92,    57,   -92,   -92,    31,   -92,    20,   -92,   224,   -92,
     -92,   147,   -92,   -92,   154,    86,   221,   112,    92,   -92,
     232,   -92,   -92,   169,   176,   107,   179,   -92,    -1,   236,
     -92,   -92,   182,   126,   241,    31,   -92,   -92,     5,   -92,
      53,   248,    31,   104,   119,   254,   219,   152,   256,   -92,
     -92,    51,   258,   -92,   -92,   231,    31,   -92,    31,   -92,
       0,   200,    20,   -92,   -92,   -92,   -92,    20,   -92,   -92,
     -92,    20,   261,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   264,   -92,   -92,   265,   -92,   -92,   -92,   266,   191,
     -92,   124,   249,   218,   267,   238,   -92,    31,   133,   141,
     147,   269,   193,    20,   270,   210,     0,   -92,    20,   -92,
     -92,    31,   -92,   -92,   268,   -92,   -92,    20,   -92,   147,
      86,   -92,   -92,   255,    42,   271,   -92,   147,   212,   229,
     -92,   -92,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   272,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -67,
     -92,   -92,   -13,   -25,   263,   252,   -92,   -54,   -92,   -92,
     -92,   -92,   -92,   -43,   105,   -92,   -91,   -92,   -92,   -26,
     -92,   -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int16 yytable[] =
{
      48,    51,    51,    52,    81,   101,    24,   125,    49,     1,
     132,     2,     3,   133,    23,     3,     4,    88,    58,     4,
      59,    95,   103,    11,     5,    76,    10,     5,    77,    91,
      75,   113,   159,    84,   134,    46,    47,    51,    94,    85,
     135,   136,    77,    51,    96,   100,    78,   105,   102,    79,
      92,   -36,    12,   172,    80,    46,    47,   160,   137,   156,
      78,   138,    14,    79,   175,    99,    46,    47,    86,    46,
      47,    16,   106,   107,   108,   109,    70,    71,   168,   131,
     157,    17,   139,   169,   140,    24,   142,   170,    46,    47,
     -11,    85,    46,    47,    77,    26,   117,   198,   118,    27,
     163,   199,   164,    28,    51,   165,    72,    71,   116,   105,
     129,   117,    78,   123,    29,    79,   116,   105,    60,   189,
      80,    46,    47,   117,   194,   143,    65,   178,    53,    59,
      54,   105,   129,   197,   106,   107,   108,   109,   105,   185,
      61,   184,   106,   107,   108,   109,   105,   186,    55,    62,
      51,   193,   105,    63,    56,   195,   106,   107,   108,   109,
     111,   112,    64,   106,   107,   108,   109,    53,    66,    57,
      67,   106,   107,   108,   109,   120,   121,   106,   107,   108,
     109,    32,   122,    71,    33,   124,    71,    55,   127,   128,
      68,    34,    35,    56,   152,   153,    36,    37,    38,    32,
      69,    32,    33,    74,    33,   188,   166,   167,   177,    34,
      35,    34,    35,    73,    36,    37,    36,    37,    32,    90,
      32,    33,   192,    33,   180,   181,   202,   115,    34,    35,
      34,    35,   104,    36,    37,    36,    37,    32,   119,   161,
      33,   126,    33,   203,   183,    71,   130,    34,    35,    34,
      35,   141,    36,    37,    36,    37,   145,   146,   147,   148,
     149,   200,    71,   150,   144,   158,   155,   171,   173,   174,
     179,   176,   187,   182,   196,   190,    31,   201,    19,   191,
      13
};

static const yytype_uint8 yycheck[] =
{
      26,    27,    28,    28,    58,    72,    19,    98,     8,    13,
       5,    15,    16,     8,    15,    16,    20,    60,     3,    20,
       5,    64,    76,    22,    28,     5,     8,    28,     8,     8,
      56,    85,   123,    59,    29,    35,    36,    63,    63,     5,
      35,    36,     8,    69,    69,    71,    26,     5,    74,    29,
      29,     9,     0,   144,    34,    35,    36,   124,     5,     8,
      26,     8,    22,    29,   155,     8,    35,    36,    34,    35,
      36,     8,    30,    31,    32,    33,     6,     7,   132,   105,
      29,     8,    29,   137,   110,    98,   112,   141,    35,    36,
       5,     5,    35,    36,     8,    33,     4,   188,     6,     5,
     126,   192,   128,     5,   130,   130,     6,     7,     4,     5,
       6,     4,    26,     6,     8,    29,     4,     5,     5,   173,
      34,    35,    36,     4,   178,     6,     9,     3,     7,     5,
       9,     5,     6,   187,    30,    31,    32,    33,     5,     6,
       5,   167,    30,    31,    32,    33,     5,     6,    27,     5,
     176,   176,     5,     5,    33,   181,    30,    31,    32,    33,
       6,     7,     5,    30,    31,    32,    33,     7,     9,     9,
       9,    30,    31,    32,    33,     6,     7,    30,    31,    32,
      33,     8,     6,     7,    11,     6,     7,    27,     6,     7,
       9,    18,    19,    33,    42,    43,    23,    24,    25,     8,
       5,     8,    11,     5,    11,    12,     6,     7,    17,    18,
      19,    18,    19,     8,    23,    24,    23,    24,     8,     8,
       8,    11,    12,    11,     6,     7,    14,     6,    18,    19,
      18,    19,     8,    23,    24,    23,    24,     8,     6,     8,
      11,     5,    11,    14,     6,     7,     5,    18,    19,    18,
      19,     3,    23,    24,    23,    24,    37,    38,    39,    40,
      41,     6,     7,    44,    10,     7,    10,     6,     4,     4,
      21,     5,     3,     6,     6,     5,    24,     6,    15,   174,
       8
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    15,    16,    20,    28,    46,    47,    50,    57,
       8,    22,     0,    46,    22,    48,     8,     8,    49,    59,
      52,    53,    51,    15,    57,    71,    33,     5,     5,     8,
      60,    60,     8,    11,    18,    19,    23,    24,    25,    61,
      64,    65,    67,    70,    72,    73,    35,    36,    74,     8,
      58,    74,    58,     7,     9,    27,    33,     9,     3,     5,
       5,     5,     5,     5,     5,     9,     9,     9,     9,     5,
       6,     7,     6,     8,     5,    74,     5,     8,    26,    29,
      34,    62,    63,    74,    74,     5,    34,    62,    68,    69,
       8,     8,    29,    66,    58,    68,    58,    54,    59,     8,
      74,    54,    74,    62,     8,     5,    30,    31,    32,    33,
      56,     6,     7,    62,    68,     6,     4,     4,     6,     6,
       6,     7,     6,     6,     6,    71,     5,     6,     7,     6,
       5,    74,     5,     8,    29,    35,    36,     5,     8,    29,
      74,     3,    74,     6,    10,    37,    38,    39,    40,    41,
      44,    76,    42,    43,    75,    10,     8,    29,     7,    71,
      54,     8,    55,    74,    74,    58,     6,     7,    62,    62,
      62,     6,    71,     4,     4,    71,     5,    17,     3,    21,
       6,     7,     6,     6,    74,     6,     6,     3,    12,    62,
       5,    69,    12,    58,    62,    74,     6,    62,    71,    71,
       6,     6,    14,    14
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 37 "synt.y"
    {printf("syntaxe correcte\n"); YYACCEPT;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 43 "synt.y"
    {
    strcpy(currentScope, "main");

;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 55 "synt.y"
    {
    strcpy(currentScope, (yyvsp[(3) - (3)].str));

if (doubleDeclaration((yyvsp[(3) - (3)].str), currentScope)) {
        
        printf("double declaration de la variable %s\n", (yyvsp[(3) - (3)].str));
        
    }
    else 
    insererTYPE((yyvsp[(3) - (3)].str), typeidf, currentScope);

;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 68 "synt.y"
    {
        strcpy(currentScope, (yyvsp[(3) - (3)].str));
        if (doubleDeclaration((yyvsp[(3) - (3)].str), currentScope)) {
        
        printf("double declaration de la variable %s\n", (yyvsp[(3) - (3)].str));
        
    }
    else 
    insererTYPE((yyvsp[(3) - (3)].str), typeidf, currentScope);
        ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 79 "synt.y"
    {
        strcpy(currentScope, (yyvsp[(3) - (3)].str));
        if (doubleDeclaration((yyvsp[(3) - (3)].str), currentScope)) {
        
        printf("double declaration de la variable %s\n", (yyvsp[(3) - (3)].str));
        
    }
    else 
    insererTYPE((yyvsp[(3) - (3)].str), typeidf, currentScope);
        ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 92 "synt.y"
    {strcpy(currentScope, "");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 108 "synt.y"
    {strcpy(typeidf, "INTEGER");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 110 "synt.y"
    {strcpy(typeidf, "REAL");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 112 "synt.y"
    {strcpy(typeidf, "LOGICAL");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 140 "synt.y"
    {
    if (doubleDeclaration((yyvsp[(1) - (1)].str), currentScope)) erreur_dd((yyvsp[(1) - (1)].str));
    else insererTYPE((yyvsp[(1) - (1)].str), typeidf, currentScope);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 145 "synt.y"
    {
    
    if (doubleDeclaration((yyvsp[(3) - (3)].str), currentScope)) erreur_dd((yyvsp[(3) - (3)].str)); 
    else insererTYPE((yyvsp[(3) - (3)].str), typeidf, currentScope);
    
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 160 "synt.y"
    {
    determiner_type(getidfType((yyvsp[(1) - (3)].str), currentScope), (yyvsp[(3) - (3)].exp).type);

    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 166 "synt.y"
    {
        determiner_type(getidfType((yyvsp[(1) - (6)].str), currentScope), (yyvsp[(6) - (6)].exp).type);

;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 172 "synt.y"
    {
        determiner_type(getidfType((yyvsp[(1) - (8)].str), currentScope), (yyvsp[(8) - (8)].exp).type);

;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 181 "synt.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 183 "synt.y"
    { 
            if(!doubleDeclaration((yyvsp[(1) - (1)].str), currentScope)) erreur_nondec((yyvsp[(1) - (1)].str));
            (yyval.exp).type = getidfType((yyvsp[(1) - (1)].str), currentScope);
          ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 188 "synt.y"
    {(yyval.exp).type = "CHARACTER";;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 190 "synt.y"
    {(yyval.exp).type = "LOGICAL";;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 192 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (3)].exp).type, getidfType((yyvsp[(3) - (3)].str), currentScope));
          ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 196 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (3)].exp).type, getidfType((yyvsp[(3) - (3)].str), currentScope));
          ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 200 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type);
          ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 204 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (3)].exp).type, "REAL");
          ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 208 "synt.y"
    { if ((yyvsp[(3) - (3)].entier)==0) 
          printf ("Erreur semantique division par 0 a la ligne %d et a la colonne %d \n",nb_ligne,nb_colonne); 
          (yyval.exp).type = determiner_type((yyvsp[(1) - (3)].exp).type, "INTEGER");
          ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 213 "synt.y"
    { (yyval.exp) = (yyvsp[(2) - (3)].exp); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 215 "synt.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 218 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (3)].exp).type, "CHARACTER");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 221 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (3)].exp).type, "CHARACTER");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 224 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (4)].exp).type, (yyvsp[(3) - (4)].exp).type);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 227 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (6)].exp).type, (yyvsp[(3) - (6)].exp).type);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 232 "synt.y"
    { 
            (yyval.exp).type = determiner_type((yyvsp[(1) - (5)].exp).type, (yyvsp[(4) - (5)].exp).type);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 237 "synt.y"
    { 
    if(!doubleDeclaration((yyvsp[(2) - (5)].str), currentScope)) erreur_nondec((yyvsp[(2) - (5)].str));
    (yyval.exp).type = getidfType((yyvsp[(2) - (5)].str), currentScope);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 254 "synt.y"
    { if(!doubleDeclaration((yyvsp[(1) - (1)].str), currentScope)) erreur_nondec((yyvsp[(1) - (1)].str));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 258 "synt.y"
    { if(!doubleDeclaration((yyvsp[(3) - (3)].str), currentScope)) erreur_nondec((yyvsp[(3) - (3)].str));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 310 "synt.y"
    {(yyval.exp).type = "INTEGER"; ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 312 "synt.y"
    {(yyval.exp).type = "REAL"; ;}
    break;



/* Line 1455 of yacc.c  */
#line 1893 "synt.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 337 "synt.y"


void erreur_dd(char *idf){
    printf("Erreur semantique: double declaration de la variable %s a la ligne %d et la colonne %d\n", idf, nb_ligne, nb_colonne);
}

void erreur_nondec(char *idf){
    printf("Erreur semantique: variable %s non declarer dans %s a la ligne %d et la colonne %d\n", idf, currentScope, nb_ligne, nb_colonne);
}

char *determiner_type(char* type1, char* type2) {
    // Handle cases where either type is unspecified
    if (type1[0] == ' ' || type2[0] == ' ') {
        return type1[0] == ' ' ? type2 : type1;
    }

    // Handle cases where types are compatible or both are the same
    if (strcmp(type1, type2) == 0) {
        return type1;
    }

    // Handle cases where types are incompatible
    printf("Erreur semantique: incompatibilite de types a la ligne %d et a la colonne %d\n", nb_ligne, nb_colonne);
    return " ";
}
#include <stdio.h>
int yyerror(char *msg) {
    printf(" ------------------------------- Erreur Syntaxique at ligne: %d et colonne: %d -------------------------------", nb_ligne, nb_colonne);
    return 1;
}

int yywrap() {
    return 1;
}

int main() {
    initialisation();
    yyparse();
    afficher();
    return 0;
}

/* A Bison parser, made by GNU Bison 3.7.3.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <stdlib.h>
#include <string.h>
#include "slc.h" // mandatory for submission
#include "tree.h"

void insertTopList();
void genNode3(Categ categ, int numComps, char *ident);
void genNode(Categ categ, int numComps);
void genIdent(char *token_val);
void genInt(char *token_val);
void genBool(char *token_val);
void genEmpty();
void genOp(Categ categ);

#line 87 "src/parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BOOLEAN = 3,                    /* BOOLEAN  */
  YYSYMBOL_EQUAL = 4,                      /* EQUAL  */
  YYSYMBOL_DIFFERENT = 5,                  /* DIFFERENT  */
  YYSYMBOL_LESS = 6,                       /* LESS  */
  YYSYMBOL_LESS_OR_EQUAL = 7,              /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER = 8,                    /* GREATER  */
  YYSYMBOL_GREATER_OR_EQUAL = 9,           /* GREATER_OR_EQUAL  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_MULTIPLY = 13,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_CLOSE_BRACE = 16,               /* CLOSE_BRACE  */
  YYSYMBOL_CLOSE_BRACKET = 17,             /* CLOSE_BRACKET  */
  YYSYMBOL_CLOSE_PAREN = 18,               /* CLOSE_PAREN  */
  YYSYMBOL_COLON = 19,                     /* COLON  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_END_OF_FILE = 22,               /* END_OF_FILE  */
  YYSYMBOL_FUNCTIONS = 23,                 /* FUNCTIONS  */
  YYSYMBOL_GOTO = 24,                      /* GOTO  */
  YYSYMBOL_IDENTIFIER = 25,                /* IDENTIFIER  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_INTEGER = 28,                   /* INTEGER  */
  YYSYMBOL_LABELS = 29,                    /* LABELS  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_OPEN_BRACE = 31,                /* OPEN_BRACE  */
  YYSYMBOL_OPEN_BRACKET = 32,              /* OPEN_BRACKET  */
  YYSYMBOL_OPEN_PAREN = 33,                /* OPEN_PAREN  */
  YYSYMBOL_RETURN = 34,                    /* RETURN  */
  YYSYMBOL_SEMI_COLON = 35,                /* SEMI_COLON  */
  YYSYMBOL_TYPES = 36,                     /* TYPES  */
  YYSYMBOL_VAR = 37,                       /* VAR  */
  YYSYMBOL_VARS = 38,                      /* VARS  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_LEXICAL_ERROR = 41,             /* LEXICAL_ERROR  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_function = 44,                  /* function  */
  YYSYMBOL_function_header = 45,           /* function_header  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_labels = 48,                    /* labels  */
  YYSYMBOL_variables = 49,                 /* variables  */
  YYSYMBOL_declaration_vars = 50,          /* declaration_vars  */
  YYSYMBOL_functions = 51,                 /* functions  */
  YYSYMBOL_declaration_funcs = 52,         /* declaration_funcs  */
  YYSYMBOL_body = 53,                      /* body  */
  YYSYMBOL_statements = 54,                /* statements  */
  YYSYMBOL_formal_parameters = 55,         /* formal_parameters  */
  YYSYMBOL_formal_parameter_list = 56,     /* formal_parameter_list  */
  YYSYMBOL_formal_parameter = 57,          /* formal_parameter  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_unlabeled_statement = 59,       /* unlabeled_statement  */
  YYSYMBOL_assignment = 60,                /* assignment  */
  YYSYMBOL_function_call_statement = 61,   /* function_call_statement  */
  YYSYMBOL_goto = 62,                      /* goto  */
  YYSYMBOL_return = 63,                    /* return  */
  YYSYMBOL_conditional = 64,               /* conditional  */
  YYSYMBOL_repetitive = 65,                /* repetitive  */
  YYSYMBOL_compound = 66,                  /* compound  */
  YYSYMBOL_unlabeled_statements = 67,      /* unlabeled_statements  */
  YYSYMBOL_empty_statement = 68,           /* empty_statement  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_binop_expression = 70,          /* binop_expression  */
  YYSYMBOL_simple_expression = 71,         /* simple_expression  */
  YYSYMBOL_unop_expression = 72,           /* unop_expression  */
  YYSYMBOL_relational_operator = 73,       /* relational_operator  */
  YYSYMBOL_additive_operator = 74,         /* additive_operator  */
  YYSYMBOL_unary_operator = 75,            /* unary_operator  */
  YYSYMBOL_terms = 76,                     /* terms  */
  YYSYMBOL_multiplicative_operator = 77,   /* multiplicative_operator  */
  YYSYMBOL_factor = 78,                    /* factor  */
  YYSYMBOL_function_call = 79,             /* function_call  */
  YYSYMBOL_identifier_list = 80,           /* identifier_list  */
  YYSYMBOL_expression_list = 81,           /* expression_list  */
  YYSYMBOL_variable = 82,                  /* variable  */
  YYSYMBOL_type = 83,                      /* type  */
  YYSYMBOL_identifier = 84,                /* identifier  */
  YYSYMBOL_integer = 85,                   /* integer  */
  YYSYMBOL_boolean = 86,                   /* boolean  */
  YYSYMBOL_empty = 87                      /* empty  */
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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    63,    65,    66,    66,    68,    69,    70,
      71,    72,    73,    74,    75,    77,    79,    81,    82,    84,
      86,    87,    89,    90,    92,    93,    95,    96,    98,    99,
     101,   102,   104,   105,   107,   108,   109,   110,   111,   112,
     113,   114,   116,   118,   120,   122,   124,   125,   127,   129,
     130,   132,   133,   135,   137,   138,   139,   140,   142,   143,
     145,   146,   148,   150,   151,   152,   153,   154,   155,   157,
     158,   159,   161,   162,   163,   165,   166,   168,   169,   170,
     172,   173,   174,   175,   176,   178,   180,   181,   183,   184,
     186,   188,   190,   192,   194,   196
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
  "\"end of file\"", "error", "\"invalid token\"", "BOOLEAN", "EQUAL",
  "DIFFERENT", "LESS", "LESS_OR_EQUAL", "GREATER", "GREATER_OR_EQUAL",
  "PLUS", "MINUS", "OR", "MULTIPLY", "DIV", "AND", "CLOSE_BRACE",
  "CLOSE_BRACKET", "CLOSE_PAREN", "COLON", "COMMA", "ELSE", "END_OF_FILE",
  "FUNCTIONS", "GOTO", "IDENTIFIER", "ASSIGN", "IF", "INTEGER", "LABELS",
  "NOT", "OPEN_BRACE", "OPEN_BRACKET", "OPEN_PAREN", "RETURN",
  "SEMI_COLON", "TYPES", "VAR", "VARS", "VOID", "WHILE", "LEXICAL_ERROR",
  "$accept", "program", "function", "function_header", "$@1", "block",
  "labels", "variables", "declaration_vars", "functions",
  "declaration_funcs", "body", "statements", "formal_parameters",
  "formal_parameter_list", "formal_parameter", "statement",
  "unlabeled_statement", "assignment", "function_call_statement", "goto",
  "return", "conditional", "repetitive", "compound",
  "unlabeled_statements", "empty_statement", "expression",
  "binop_expression", "simple_expression", "unop_expression",
  "relational_operator", "additive_operator", "unary_operator", "terms",
  "multiplicative_operator", "factor", "function_call", "identifier_list",
  "expression_list", "variable", "type", "identifier", "integer",
  "boolean", "empty", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,   -86,   -86,     4,    -8,    53,    20,    20,   -86,   -86,
      22,    20,   107,    20,   -86,    17,    42,    21,   -86,    34,
      34,   -86,    22,   -11,   -86,    20,    39,   107,    76,   -86,
      59,    83,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,    65,    68,    37,    86,    20,    10,    42,    21,
     -86,    21,   -86,   -86,    12,   -86,   -86,   -86,    20,   -86,
      89,    76,   -86,    95,    72,    87,   -86,   -86,   -86,   -86,
     -86,    76,    90,   -86,   151,   144,    41,   130,   -86,   -86,
     -86,   -86,   -86,   -86,    76,   -86,   -86,   -86,    76,   107,
      76,   -86,    70,    20,    21,   -86,   -86,   -86,    20,    60,
     -86,    93,   103,   -86,   -86,   109,   -86,   -86,   -86,   110,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
      41,    41,    41,   154,   -86,   -86,   -86,    41,   118,   102,
     -86,   -86,    63,    20,   111,   -86,   -86,    96,   -86,    12,
      20,   -86,   136,   -86,   154,   130,   154,   -86,   136,   -86,
     -86,    76,   133,   -86,    20,   -86,   -86,   148,   -86,   -86,
     -86,   -86,   136,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    92,     5,     0,     0,     0,     0,     0,     1,     2,
       0,     0,    95,     0,     3,     0,     0,     0,     7,     0,
       0,    20,    19,     0,    86,     0,     0,    95,    95,    53,
       0,     0,    24,    32,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,    90,     0,    16,     0,     0,     0,
       8,     0,     9,    10,    95,     4,     6,    21,     0,    15,
       0,    95,    51,     0,    90,     0,    94,    72,    73,    93,
      74,    95,     0,    55,    54,    56,     0,    60,    75,    83,
      80,    81,    82,    57,    95,    22,    25,    43,    95,     0,
      95,    23,     0,     0,     0,    11,    12,    13,     0,     0,
      28,     0,     0,    87,    44,     0,    49,    52,    50,     0,
      45,    65,    66,    64,    63,    68,    67,    69,    70,    71,
       0,     0,     0,    62,    77,    78,    79,     0,     0,     0,
      33,    88,     0,     0,     0,    91,    14,     0,    26,     0,
       0,    27,     0,    84,    59,    61,    58,    76,     0,    42,
      85,    95,     0,    17,     0,    29,    31,    46,    48,    89,
      18,    30,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,    11,   -86,   -86,   -86,   -86,   155,   -86,    27,
     -86,     2,   -86,   152,   -86,    32,   142,   -25,   -86,   -86,
     -86,   -86,   -86,   -86,   -85,   -86,   -86,   -56,   -86,   -60,
     -86,    99,   -86,   -86,    54,   -86,    49,    -4,   -10,   -86,
       8,    44,     0,   -86,   -86,    14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     7,    14,    15,    16,    46,    17,
      22,    18,    31,    55,    99,   100,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    63,    41,    72,    73,    74,
      75,   120,   121,    76,    77,   127,    78,    79,   101,   132,
      80,   134,    64,    81,    82,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    23,    62,    47,     8,   105,    19,    20,    42,    58,
       6,    24,    44,    24,     9,   109,   123,    50,    52,    53,
      43,    21,     6,    42,    59,    60,    45,    42,   128,    93,
      58,    44,   129,    57,   131,    43,    92,     1,   107,    43,
      10,    65,    49,    51,    66,     1,    24,     1,    12,    98,
      95,    96,    12,    97,    24,    13,    89,   157,   103,    42,
     144,     2,   146,   158,   130,    10,     1,    54,   102,    69,
      90,    43,    61,    12,    71,    94,    10,   163,   138,    66,
     139,   150,    11,   151,    12,    42,    67,    68,   137,   133,
      58,    13,    84,   135,    88,   159,   136,    43,    24,    85,
      87,     1,    91,   108,    69,    90,    70,    25,     1,    71,
      26,   106,   140,    58,    27,   154,    58,    28,    29,    25,
       1,   141,    26,    30,   104,   110,    27,   142,   143,    28,
      29,    25,     1,   135,    26,    30,   148,   149,    27,    24,
     156,    28,    29,   124,   125,   126,   153,    30,   111,   112,
     113,   114,   115,   116,   161,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   117,   118,   119,    27,   160,   162,
      48,   155,    56,    86,   122,   145,   147,   152
};

static const yytype_uint8 yycheck[] =
{
       0,    11,    27,    13,     0,    61,     6,     7,    12,    20,
      10,    11,    12,    13,    22,    71,    76,    15,    16,    17,
      12,    10,    22,    27,    35,    25,    12,    31,    84,    19,
      20,    31,    88,    22,    90,    27,    46,    25,    63,    31,
      23,    27,    15,    16,     3,    25,    46,    25,    31,    37,
      48,    49,    31,    51,    54,    38,    19,   142,    58,    63,
     120,    39,   122,   148,    89,    23,    25,    33,    54,    28,
      33,    63,    33,    31,    33,    48,    23,   162,    18,     3,
      20,    18,    29,    20,    31,    89,    10,    11,    98,    19,
      20,    38,    33,    93,    26,   151,    94,    89,    98,    16,
      35,    25,    16,    16,    28,    33,    30,    24,    25,    33,
      27,    16,    19,    20,    31,    19,    20,    34,    35,    24,
      25,    18,    27,    40,    35,    35,    31,    18,    18,    34,
      35,    24,    25,   133,    27,    40,    18,    35,    31,   139,
     140,    34,    35,    13,    14,    15,    35,    40,     4,     5,
       6,     7,     8,     9,   154,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    10,    11,    12,    31,    35,    21,
      15,   139,    20,    31,    75,   121,   127,   133
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    39,    43,    44,    45,    84,    46,     0,    22,
      23,    29,    31,    38,    47,    48,    49,    51,    53,    84,
      84,    44,    52,    80,    84,    24,    27,    31,    34,    35,
      40,    54,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    68,    79,    82,    84,    87,    50,    80,    49,    51,
      53,    51,    53,    53,    33,    55,    55,    44,    20,    35,
      84,    33,    59,    67,    84,    87,     3,    10,    11,    28,
      30,    33,    69,    70,    71,    72,    75,    76,    78,    79,
      82,    85,    86,    87,    33,    16,    58,    35,    26,    19,
      33,    16,    80,    19,    51,    53,    53,    53,    37,    56,
      57,    80,    87,    84,    35,    69,    16,    59,    16,    69,
      35,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      73,    74,    73,    71,    13,    14,    15,    77,    69,    69,
      59,    69,    81,    19,    83,    84,    53,    80,    18,    20,
      19,    18,    18,    18,    71,    76,    71,    78,    18,    35,
      18,    20,    83,    35,    19,    57,    84,    66,    66,    69,
      35,    84,    21,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    45,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    75,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    79,    80,    80,    81,    81,
      82,    83,    84,    85,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     0,     4,     1,     2,     2,
       2,     3,     3,     3,     4,     3,     2,     4,     5,     2,
       1,     2,     3,     3,     1,     2,     3,     3,     1,     3,
       4,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     2,     3,     3,     5,     7,     5,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: function END_OF_FILE  */
#line 61 "src/parser.y"
                                                                                                                                        { genNode(C_PROGRAM, 1); return 0; }
#line 1284 "src/parser.c"
    break;

  case 3: /* function: function_header block  */
#line 63 "src/parser.y"
                                                                                    { genNode(C_FUNCTION, 2); }
#line 1290 "src/parser.c"
    break;

  case 4: /* function_header: identifier identifier formal_parameters  */
#line 65 "src/parser.y"
                                                                                    { genNode(C_FUNCTION_HEADER, 3); }
#line 1296 "src/parser.c"
    break;

  case 5: /* $@1: %empty  */
#line 66 "src/parser.y"
       { genEmpty(); }
#line 1302 "src/parser.c"
    break;

  case 6: /* function_header: VOID $@1 identifier formal_parameters  */
#line 66 "src/parser.y"
                                                                                    { genNode(C_FUNCTION_HEADER, 2); }
#line 1308 "src/parser.c"
    break;

  case 7: /* block: body  */
#line 68 "src/parser.y"
                                                                                                                                                                { genNode(C_BLOCK, 1); }
#line 1314 "src/parser.c"
    break;

  case 8: /* block: labels body  */
#line 69 "src/parser.y"
                                                                                                                                                        { genNode(C_BLOCK, 2); }
#line 1320 "src/parser.c"
    break;

  case 9: /* block: variables body  */
#line 70 "src/parser.y"
                                                                                                                                                        { genNode(C_BLOCK, 2); }
#line 1326 "src/parser.c"
    break;

  case 10: /* block: functions body  */
#line 71 "src/parser.y"
                                                                                                                                                { genNode(C_BLOCK, 2); }
#line 1332 "src/parser.c"
    break;

  case 11: /* block: labels variables body  */
#line 72 "src/parser.y"
                                                                                                                                        { genNode(C_BLOCK, 3); }
#line 1338 "src/parser.c"
    break;

  case 12: /* block: labels functions body  */
#line 73 "src/parser.y"
                                                                                                                                        { genNode(C_BLOCK, 3); }
#line 1344 "src/parser.c"
    break;

  case 13: /* block: variables functions body  */
#line 74 "src/parser.y"
                                                                                                                                                { genNode(C_BLOCK, 3); }
#line 1350 "src/parser.c"
    break;

  case 14: /* block: labels variables functions body  */
#line 75 "src/parser.y"
                                                                                    { genNode(C_BLOCK, 4); }
#line 1356 "src/parser.c"
    break;

  case 15: /* labels: LABELS identifier_list SEMI_COLON  */
#line 77 "src/parser.y"
                                                                                                                                { genNode(C_LABELS, 1); }
#line 1362 "src/parser.c"
    break;

  case 16: /* variables: VARS declaration_vars  */
#line 79 "src/parser.y"
                                                                                                                                        { genNode(C_VARIABLES, 1); }
#line 1368 "src/parser.c"
    break;

  case 17: /* declaration_vars: identifier_list COLON type SEMI_COLON  */
#line 81 "src/parser.y"
                                                                                                                { genNode(C_DECLARATION_VARS, 2); }
#line 1374 "src/parser.c"
    break;

  case 18: /* declaration_vars: declaration_vars identifier_list COLON type SEMI_COLON  */
#line 82 "src/parser.y"
                                                                                                                { genNode(C_DECLARATION_VARS, 2); insertTopList(); }
#line 1380 "src/parser.c"
    break;

  case 19: /* functions: FUNCTIONS declaration_funcs  */
#line 84 "src/parser.y"
                                                                                                                                { genNode(C_FUNCTIONS, 1); }
#line 1386 "src/parser.c"
    break;

  case 20: /* declaration_funcs: function  */
#line 86 "src/parser.y"
                                                                                                                                                { genNode(C_DECLARATION_FUNCS, 1); }
#line 1392 "src/parser.c"
    break;

  case 21: /* declaration_funcs: declaration_funcs function  */
#line 87 "src/parser.y"
                                                                                                                                        { genNode(C_DECLARATION_FUNCS, 1); insertTopList(); }
#line 1398 "src/parser.c"
    break;

  case 22: /* body: OPEN_BRACE statements CLOSE_BRACE  */
#line 89 "src/parser.y"
                                                                                                                                { genNode(C_BODY, 1); }
#line 1404 "src/parser.c"
    break;

  case 23: /* body: OPEN_BRACE empty CLOSE_BRACE  */
#line 90 "src/parser.y"
                                                                                                                                        { genNode(C_BODY, 1); }
#line 1410 "src/parser.c"
    break;

  case 24: /* statements: statement  */
#line 92 "src/parser.y"
                                                                                                                                                { genNode(C_STATEMENTS, 1); }
#line 1416 "src/parser.c"
    break;

  case 25: /* statements: statements statement  */
#line 93 "src/parser.y"
                                                                                                                                                { genNode(C_STATEMENTS, 1); insertTopList(); }
#line 1422 "src/parser.c"
    break;

  case 26: /* formal_parameters: OPEN_PAREN formal_parameter_list CLOSE_PAREN  */
#line 95 "src/parser.y"
                                                                                                        { genNode(C_PARAMS, 1); }
#line 1428 "src/parser.c"
    break;

  case 27: /* formal_parameters: OPEN_PAREN empty CLOSE_PAREN  */
#line 96 "src/parser.y"
                                                                                                                                        { genNode(C_PARAMS, 1); }
#line 1434 "src/parser.c"
    break;

  case 28: /* formal_parameter_list: formal_parameter  */
#line 98 "src/parser.y"
                                                                                                                                { genNode(C_PARAM_LIST, 1); }
#line 1440 "src/parser.c"
    break;

  case 29: /* formal_parameter_list: formal_parameter_list COMMA formal_parameter  */
#line 99 "src/parser.y"
                                                                                                                        { genNode(C_PARAM_LIST, 1); insertTopList(); }
#line 1446 "src/parser.c"
    break;

  case 30: /* formal_parameter: VAR identifier_list COLON identifier  */
#line 101 "src/parser.y"
                                                                                                                { genNode(C_REF_PARAM, 2); }
#line 1452 "src/parser.c"
    break;

  case 31: /* formal_parameter: identifier_list COLON identifier  */
#line 102 "src/parser.y"
                                                                                                                                        { genNode(C_VAL_PARAM, 2); }
#line 1458 "src/parser.c"
    break;

  case 32: /* statement: unlabeled_statement  */
#line 104 "src/parser.y"
                                                                                                                                        { genNode(C_STATEMENT, 1); }
#line 1464 "src/parser.c"
    break;

  case 33: /* statement: identifier COLON unlabeled_statement  */
#line 105 "src/parser.y"
                                                                                                                                { genNode(C_STATEMENT, 2); }
#line 1470 "src/parser.c"
    break;

  case 34: /* unlabeled_statement: assignment  */
#line 107 "src/parser.y"
                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1476 "src/parser.c"
    break;

  case 35: /* unlabeled_statement: function_call_statement  */
#line 108 "src/parser.y"
                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1482 "src/parser.c"
    break;

  case 36: /* unlabeled_statement: goto  */
#line 109 "src/parser.y"
                                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1488 "src/parser.c"
    break;

  case 37: /* unlabeled_statement: return  */
#line 110 "src/parser.y"
                                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1494 "src/parser.c"
    break;

  case 38: /* unlabeled_statement: conditional  */
#line 111 "src/parser.y"
                                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1500 "src/parser.c"
    break;

  case 39: /* unlabeled_statement: repetitive  */
#line 112 "src/parser.y"
                                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1506 "src/parser.c"
    break;

  case 40: /* unlabeled_statement: compound  */
#line 113 "src/parser.y"
                                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1512 "src/parser.c"
    break;

  case 41: /* unlabeled_statement: empty_statement  */
#line 114 "src/parser.y"
                                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1518 "src/parser.c"
    break;

  case 42: /* assignment: variable ASSIGN expression SEMI_COLON  */
#line 116 "src/parser.y"
                                                                                                                        { genNode(C_ASSIGNMENT, 2); }
#line 1524 "src/parser.c"
    break;

  case 43: /* function_call_statement: function_call SEMI_COLON  */
#line 118 "src/parser.y"
                                                                                                                        { genNode(C_FUNCTION_CALL_STATEMENT, 1); }
#line 1530 "src/parser.c"
    break;

  case 44: /* goto: GOTO identifier SEMI_COLON  */
#line 120 "src/parser.y"
                                                                                                                                        { genNode(C_GOTO, 1); }
#line 1536 "src/parser.c"
    break;

  case 45: /* return: RETURN expression SEMI_COLON  */
#line 122 "src/parser.y"
                                                                                                                                { genNode(C_RETURN, 1); }
#line 1542 "src/parser.c"
    break;

  case 46: /* conditional: IF OPEN_PAREN expression CLOSE_PAREN compound  */
#line 124 "src/parser.y"
                                                                                                                { genNode(C_CONDITIONAL, 2); }
#line 1548 "src/parser.c"
    break;

  case 47: /* conditional: IF OPEN_PAREN expression CLOSE_PAREN compound ELSE compound  */
#line 125 "src/parser.y"
                                                                                                        { genNode(C_CONDITIONAL, 3); }
#line 1554 "src/parser.c"
    break;

  case 48: /* repetitive: WHILE OPEN_PAREN expression CLOSE_PAREN compound  */
#line 127 "src/parser.y"
                                                                                                        { genNode(C_REPETITIVE, 2); }
#line 1560 "src/parser.c"
    break;

  case 49: /* compound: OPEN_BRACE unlabeled_statements CLOSE_BRACE  */
#line 129 "src/parser.y"
                                                                                                                { genNode(C_COMPOUND, 1); }
#line 1566 "src/parser.c"
    break;

  case 50: /* compound: OPEN_BRACE empty CLOSE_BRACE  */
#line 130 "src/parser.y"
                                                                                                                                        { genNode(C_COMPOUND, 1); }
#line 1572 "src/parser.c"
    break;

  case 51: /* unlabeled_statements: unlabeled_statement  */
#line 132 "src/parser.y"
                                                                                                                                { genNode(C_UNLABELED_STATEMENTS, 1); }
#line 1578 "src/parser.c"
    break;

  case 52: /* unlabeled_statements: unlabeled_statements unlabeled_statement  */
#line 133 "src/parser.y"
                                                                                                                                { genNode(C_UNLABELED_STATEMENTS, 1); insertTopList(); }
#line 1584 "src/parser.c"
    break;

  case 53: /* empty_statement: SEMI_COLON  */
#line 135 "src/parser.y"
                                                                                                                                                { /*?*/ genEmpty(); }
#line 1590 "src/parser.c"
    break;

  case 54: /* expression: simple_expression  */
#line 137 "src/parser.y"
                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1596 "src/parser.c"
    break;

  case 55: /* expression: binop_expression  */
#line 138 "src/parser.y"
                                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1602 "src/parser.c"
    break;

  case 56: /* expression: unop_expression  */
#line 139 "src/parser.y"
                                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1608 "src/parser.c"
    break;

  case 58: /* binop_expression: unop_expression relational_operator simple_expression  */
#line 142 "src/parser.y"
                                                                                                { genNode(C_BINOP_EXPRESSION, 3); }
#line 1614 "src/parser.c"
    break;

  case 59: /* binop_expression: simple_expression relational_operator simple_expression  */
#line 143 "src/parser.y"
                                                                                                                { genNode(C_BINOP_EXPRESSION, 3); }
#line 1620 "src/parser.c"
    break;

  case 60: /* simple_expression: terms  */
#line 145 "src/parser.y"
                                                                                                                                        { genNode(C_SIMPLE_EXPRESSION, 1); }
#line 1626 "src/parser.c"
    break;

  case 61: /* simple_expression: simple_expression additive_operator terms  */
#line 146 "src/parser.y"
                                                                                                                                { genNode(C_SIMPLE_EXPRESSION, 2); insertTopList(); }
#line 1632 "src/parser.c"
    break;

  case 62: /* unop_expression: unary_operator simple_expression  */
#line 148 "src/parser.y"
                                                                                                                        { genNode(C_UNOP_EXPRESSION, 2); }
#line 1638 "src/parser.c"
    break;

  case 63: /* relational_operator: LESS_OR_EQUAL  */
#line 150 "src/parser.y"
                                                                                                                                        { genNode(C_RELOP, 1); genOp(C_LESS_EQUAL); }
#line 1644 "src/parser.c"
    break;

  case 64: /* relational_operator: LESS  */
#line 151 "src/parser.y"
                                                                                                                                                                { genNode(C_RELOP, 1); genOp(C_LESS); }
#line 1650 "src/parser.c"
    break;

  case 65: /* relational_operator: EQUAL  */
#line 152 "src/parser.y"
                                                                                                                                                                { genNode(C_RELOP, 1); genOp(C_EQUAL); }
#line 1656 "src/parser.c"
    break;

  case 66: /* relational_operator: DIFFERENT  */
#line 153 "src/parser.y"
                                                                                                                                                        { genNode(C_RELOP, 1); genOp(C_DIFFERENT); }
#line 1662 "src/parser.c"
    break;

  case 67: /* relational_operator: GREATER_OR_EQUAL  */
#line 154 "src/parser.y"
                                                                                                                                                        { genNode(C_RELOP, 1); genOp(C_GREATER_EQUAL); }
#line 1668 "src/parser.c"
    break;

  case 68: /* relational_operator: GREATER  */
#line 155 "src/parser.y"
                                                                                                                                                                { genNode(C_RELOP, 1); genOp(C_GREATER); }
#line 1674 "src/parser.c"
    break;

  case 69: /* additive_operator: PLUS  */
#line 157 "src/parser.y"
                                                                                                                                                { genNode(C_ADDOP, 1); genOp(C_PLUS); }
#line 1680 "src/parser.c"
    break;

  case 70: /* additive_operator: MINUS  */
#line 158 "src/parser.y"
                                                                                                                                                                { genNode(C_ADDOP, 1); genOp(C_MINUS); }
#line 1686 "src/parser.c"
    break;

  case 71: /* additive_operator: OR  */
#line 159 "src/parser.y"
                                                                                                                                                                { genNode(C_ADDOP, 1); genOp(C_OR); }
#line 1692 "src/parser.c"
    break;

  case 72: /* unary_operator: PLUS  */
#line 161 "src/parser.y"
                                                                                                                                                { genNode(C_UNOP, 1); genOp(C_PLUS); }
#line 1698 "src/parser.c"
    break;

  case 73: /* unary_operator: MINUS  */
#line 162 "src/parser.y"
                                                                                                                                                                { genNode(C_UNOP, 1); genOp(C_MINUS); }
#line 1704 "src/parser.c"
    break;

  case 74: /* unary_operator: NOT  */
#line 163 "src/parser.y"
                                                                                                                                                                { genNode(C_UNOP, 1); genOp(C_NOT); }
#line 1710 "src/parser.c"
    break;

  case 75: /* terms: factor  */
#line 165 "src/parser.y"
                                                                                                                                                        { genNode(C_TERM, 1); }
#line 1716 "src/parser.c"
    break;

  case 76: /* terms: terms multiplicative_operator factor  */
#line 166 "src/parser.y"
                                                                                                                                { genNode(C_TERM, 2); insertTopList(); }
#line 1722 "src/parser.c"
    break;

  case 77: /* multiplicative_operator: MULTIPLY  */
#line 168 "src/parser.y"
                                                                                                                                        { genNode(C_MULOP, 1); genOp(C_MULTIPLY); }
#line 1728 "src/parser.c"
    break;

  case 78: /* multiplicative_operator: DIV  */
#line 169 "src/parser.y"
                                                                                                                                                                { genNode(C_MULOP, 1); genOp(C_DIV); }
#line 1734 "src/parser.c"
    break;

  case 79: /* multiplicative_operator: AND  */
#line 170 "src/parser.y"
                                                                                                                                                                { genNode(C_MULOP, 1); genOp(C_AND); }
#line 1740 "src/parser.c"
    break;

  case 80: /* factor: variable  */
#line 172 "src/parser.y"
                                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1746 "src/parser.c"
    break;

  case 81: /* factor: integer  */
#line 173 "src/parser.y"
                                                                                                                                                                { genNode(C_FACTOR, 1); }
#line 1752 "src/parser.c"
    break;

  case 82: /* factor: boolean  */
#line 174 "src/parser.y"
                                                                                                                                                                { genNode(C_FACTOR, 1); }
#line 1758 "src/parser.c"
    break;

  case 83: /* factor: function_call  */
#line 175 "src/parser.y"
                                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1764 "src/parser.c"
    break;

  case 84: /* factor: OPEN_PAREN expression CLOSE_PAREN  */
#line 176 "src/parser.y"
                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1770 "src/parser.c"
    break;

  case 85: /* function_call: identifier OPEN_PAREN expression_list CLOSE_PAREN  */
#line 178 "src/parser.y"
                                                                                                        { genNode(C_FUNCTION_CALL, 2); }
#line 1776 "src/parser.c"
    break;

  case 86: /* identifier_list: identifier  */
#line 180 "src/parser.y"
                                                                                                                        { genNode(C_IDENTIFIER_LIST, 1); }
#line 1782 "src/parser.c"
    break;

  case 87: /* identifier_list: identifier_list COMMA identifier  */
#line 181 "src/parser.y"
                                                                                                                                        { genNode(C_IDENTIFIER_LIST, 1); insertTopList(); }
#line 1788 "src/parser.c"
    break;

  case 88: /* expression_list: expression  */
#line 183 "src/parser.y"
                                                                                                                        { genNode(C_EXPRESSION_LIST, 1); }
#line 1794 "src/parser.c"
    break;

  case 89: /* expression_list: expression_list COMMA expression  */
#line 184 "src/parser.y"
                                                                                                                                        { genNode(C_EXPRESSION_LIST, 1); insertTopList(); }
#line 1800 "src/parser.c"
    break;

  case 90: /* variable: identifier  */
#line 186 "src/parser.y"
                                                                                                                                                { genNode(C_VARIABLE, 1); }
#line 1806 "src/parser.c"
    break;

  case 91: /* type: identifier  */
#line 188 "src/parser.y"
                                                                                                                                                        { genNode(C_TYPE, 1); }
#line 1812 "src/parser.c"
    break;

  case 92: /* identifier: IDENTIFIER  */
#line 190 "src/parser.y"
                                                                                                                                                { genIdent((yyvsp[0].symbol)); }
#line 1818 "src/parser.c"
    break;

  case 93: /* integer: INTEGER  */
#line 192 "src/parser.y"
                                                                                                                                                        { genInt((yyvsp[0].symbol)); }
#line 1824 "src/parser.c"
    break;

  case 94: /* boolean: BOOLEAN  */
#line 194 "src/parser.y"
                                                                                                                                                        { genBool((yyvsp[0].symbol)); }
#line 1830 "src/parser.c"
    break;

  case 95: /* empty: %empty  */
#line 196 "src/parser.y"
                                                                                                                                                        { genEmpty(); }
#line 1836 "src/parser.c"
    break;


#line 1840 "src/parser.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 199 "src/parser.y"


void insertTopList()
{
	TreeNode *top = pop();
	TreeNode *prev = pop();
	top->next = prev;
	push(top);
}

void genNode3(Categ categ, int numComps, char *symbol)
{
	TreeNode *treeNode = malloc(sizeof(TreeNode));
	treeNode->categ = categ;
	treeNode->next = NULL;
	treeNode->symbol = malloc(strlen(symbol) + 1);
        strcpy(treeNode->symbol, symbol);
	if (numComps > 0)
            for(int i = numComps - 1; i >= 0; i--)
                treeNode->components[i] = pop();
	push(treeNode);
}

void genNode(Categ categ, int numComps)
{
	genNode3(categ, numComps, "");
}

void genIdent(char *token_val)
{
    genNode3(C_IDENTIFIER, 0, token_val);
}

void genInt(char *token_val)
{	
	genNode3(C_INTEGER, 0, token_val);
}

void genBool(char *token_val)
{
	genNode3(C_BOOLEAN, 0, token_val);
}

void genEmpty() 
{
	push(NULL);
}

void genOp (Categ categ)
{
	genNode(categ, 0);
}

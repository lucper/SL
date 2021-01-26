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
void genEmpty();
void genOpSymbol(Categ categ);

#line 86 "src/parser.c"

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
  YYSYMBOL_EQUAL = 3,                      /* EQUAL  */
  YYSYMBOL_DIFFERENT = 4,                  /* DIFFERENT  */
  YYSYMBOL_LESS = 5,                       /* LESS  */
  YYSYMBOL_LESS_OR_EQUAL = 6,              /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER = 7,                    /* GREATER  */
  YYSYMBOL_GREATER_OR_EQUAL = 8,           /* GREATER_OR_EQUAL  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_MULTIPLY = 12,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_CLOSE_BRACE = 15,               /* CLOSE_BRACE  */
  YYSYMBOL_CLOSE_BRACKET = 16,             /* CLOSE_BRACKET  */
  YYSYMBOL_CLOSE_PAREN = 17,               /* CLOSE_PAREN  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_END_OF_FILE = 21,               /* END_OF_FILE  */
  YYSYMBOL_FUNCTIONS = 22,                 /* FUNCTIONS  */
  YYSYMBOL_GOTO = 23,                      /* GOTO  */
  YYSYMBOL_IDENTIFIER = 24,                /* IDENTIFIER  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_LABELS = 28,                    /* LABELS  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_OPEN_BRACE = 30,                /* OPEN_BRACE  */
  YYSYMBOL_OPEN_BRACKET = 31,              /* OPEN_BRACKET  */
  YYSYMBOL_OPEN_PAREN = 32,                /* OPEN_PAREN  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_SEMI_COLON = 34,                /* SEMI_COLON  */
  YYSYMBOL_TYPES = 35,                     /* TYPES  */
  YYSYMBOL_VAR = 36,                       /* VAR  */
  YYSYMBOL_VARS = 37,                      /* VARS  */
  YYSYMBOL_VOID = 38,                      /* VOID  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_LEXICAL_ERROR = 40,             /* LEXICAL_ERROR  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_function = 43,                  /* function  */
  YYSYMBOL_function_header = 44,           /* function_header  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_block = 46,                     /* block  */
  YYSYMBOL_labels = 47,                    /* labels  */
  YYSYMBOL_variables = 48,                 /* variables  */
  YYSYMBOL_declaration_vars = 49,          /* declaration_vars  */
  YYSYMBOL_functions = 50,                 /* functions  */
  YYSYMBOL_declaration_funcs = 51,         /* declaration_funcs  */
  YYSYMBOL_body = 52,                      /* body  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_formal_parameters = 54,         /* formal_parameters  */
  YYSYMBOL_formal_parameter_rest = 55,     /* formal_parameter_rest  */
  YYSYMBOL_formal_parameter = 56,          /* formal_parameter  */
  YYSYMBOL_expression_parameter = 57,      /* expression_parameter  */
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
  YYSYMBOL_additive_term = 73,             /* additive_term  */
  YYSYMBOL_relational_operator = 74,       /* relational_operator  */
  YYSYMBOL_additive_operator = 75,         /* additive_operator  */
  YYSYMBOL_unary_operator = 76,            /* unary_operator  */
  YYSYMBOL_term = 77,                      /* term  */
  YYSYMBOL_multiplicative_factor = 78,     /* multiplicative_factor  */
  YYSYMBOL_multiplicative_operator = 79,   /* multiplicative_operator  */
  YYSYMBOL_factor = 80,                    /* factor  */
  YYSYMBOL_function_call = 81,             /* function_call  */
  YYSYMBOL_identifier_list = 82,           /* identifier_list  */
  YYSYMBOL_expression_list = 83,           /* expression_list  */
  YYSYMBOL_variable = 84,                  /* variable  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_identifier = 86,                /* identifier  */
  YYSYMBOL_integer = 87,                   /* integer  */
  YYSYMBOL_empty = 88                      /* empty  */
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
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

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
       0,    59,    59,    61,    63,    64,    64,    66,    67,    68,
      69,    70,    71,    72,    73,    75,    77,    79,    80,    82,
      84,    85,    87,    88,    90,    91,    93,    94,    95,    97,
      98,   100,   102,   103,   105,   106,   108,   109,   110,   111,
     112,   113,   114,   115,   117,   119,   121,   123,   125,   126,
     128,   130,   131,   133,   134,   136,   138,   139,   140,   141,
     143,   144,   146,   147,   149,   150,   152,   153,   155,   156,
     157,   158,   159,   160,   162,   163,   164,   166,   167,   168,
     170,   171,   173,   174,   176,   177,   178,   180,   181,   182,
     183,   185,   187,   188,   190,   191,   193,   195,   197,   199,
     201
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
  "\"end of file\"", "error", "\"invalid token\"", "EQUAL", "DIFFERENT",
  "LESS", "LESS_OR_EQUAL", "GREATER", "GREATER_OR_EQUAL", "PLUS", "MINUS",
  "OR", "MULTIPLY", "DIV", "AND", "CLOSE_BRACE", "CLOSE_BRACKET",
  "CLOSE_PAREN", "COLON", "COMMA", "ELSE", "END_OF_FILE", "FUNCTIONS",
  "GOTO", "IDENTIFIER", "ASSIGN", "IF", "INTEGER", "LABELS", "NOT",
  "OPEN_BRACE", "OPEN_BRACKET", "OPEN_PAREN", "RETURN", "SEMI_COLON",
  "TYPES", "VAR", "VARS", "VOID", "WHILE", "LEXICAL_ERROR", "$accept",
  "program", "function", "function_header", "$@1", "block", "labels",
  "variables", "declaration_vars", "functions", "declaration_funcs",
  "body", "statements", "formal_parameters", "formal_parameter_rest",
  "formal_parameter", "expression_parameter", "statement",
  "unlabeled_statement", "assignment", "function_call_statement", "goto",
  "return", "conditional", "repetitive", "compound",
  "unlabeled_statements", "empty_statement", "expression",
  "binop_expression", "simple_expression", "unop_expression",
  "additive_term", "relational_operator", "additive_operator",
  "unary_operator", "term", "multiplicative_factor",
  "multiplicative_operator", "factor", "function_call", "identifier_list",
  "expression_list", "variable", "type", "identifier", "integer", "empty", YY_NULLPTR
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
     295
};
#endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,  -115,  -115,     2,    16,    48,    21,    21,  -115,  -115,
      10,    21,    86,    21,  -115,    81,    99,    47,  -115,    70,
      70,  -115,    10,    32,  -115,    21,   108,    86,    63,  -115,
     120,    41,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,   103,   128,    83,   140,    21,    87,    99,    47,
    -115,    47,  -115,  -115,    11,  -115,  -115,  -115,    21,  -115,
     122,    63,  -115,    74,   125,   144,  -115,  -115,  -115,  -115,
      63,   126,  -115,   139,   139,    90,   117,   118,  -115,  -115,
    -115,  -115,    63,  -115,  -115,  -115,    63,    86,    63,  -115,
     105,    21,    47,  -115,  -115,  -115,    21,    24,  -115,   116,
     137,  -115,  -115,   145,  -115,  -115,  -115,   146,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,    90,    90,   117,  -115,  -115,
    -115,   117,    90,  -115,  -115,  -115,   118,    90,   147,   131,
    -115,  -115,    64,    21,   132,  -115,  -115,   130,  -115,    11,
     119,    21,  -115,   138,  -115,  -115,  -115,   117,    90,  -115,
      90,  -115,   138,  -115,  -115,    63,   133,  -115,    21,  -115,
    -115,    11,  -115,   149,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,   138,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    98,     5,     0,     0,     0,     0,     0,     1,     2,
       0,     0,   100,     0,     3,     0,     0,     0,     7,     0,
       0,    20,    19,     0,    92,     0,     0,   100,   100,    55,
       0,     0,    24,    34,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,    96,     0,    16,     0,     0,     0,
       8,     0,     9,    10,   100,     4,     6,    21,     0,    15,
       0,   100,    53,     0,    96,     0,    77,    78,    99,    79,
     100,     0,    57,    56,    58,     0,    63,    81,    89,    87,
      88,    59,   100,    22,    25,    45,   100,     0,   100,    23,
       0,     0,     0,    11,    12,    13,     0,     0,    31,     0,
       0,    93,    46,     0,    51,    54,    52,     0,    47,    70,
      71,    69,    68,    73,    72,     0,     0,    65,    74,    75,
      76,    62,     0,    84,    85,    86,    80,     0,     0,     0,
      35,    94,     0,     0,     0,    97,    14,     0,    27,     0,
       0,     0,    28,     0,    90,    61,    60,    64,     0,    66,
       0,    82,     0,    44,    91,   100,     0,    17,     0,    29,
      26,     0,    33,    48,    67,    83,    50,    95,    18,    32,
      30,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,    72,  -115,  -115,  -115,  -115,   155,  -115,     5,
    -115,     1,  -115,   151,  -115,  -100,  -115,   141,   -19,  -115,
    -115,  -115,  -115,  -115,  -115,  -114,  -115,  -115,   -56,  -115,
      35,  -115,    56,   100,   -88,  -115,   -60,  -115,    49,   -87,
      -8,   -10,  -115,    -3,    43,     0,  -115,    15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     7,    14,    15,    16,    46,    17,
      22,    18,    31,    55,   140,    97,    98,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    63,    41,    71,    72,
      73,    74,   121,   115,   122,    75,    76,   126,   127,    77,
      78,    99,   132,    79,   134,    64,    80,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    23,     8,    47,    42,   103,    19,    20,    62,    43,
       6,    24,    44,    24,   107,   117,    50,    52,    53,    42,
      49,    51,     6,    42,    43,    60,   128,    45,    43,   163,
     129,    44,   131,   148,     1,     1,    90,     9,   166,   159,
     151,   138,    65,   139,   105,     1,    24,    96,     2,    93,
      94,    58,    95,    92,    24,    42,    83,   172,   101,   148,
      43,   170,   149,   165,    25,     1,    59,    26,   130,   100,
      10,    27,    66,    67,    28,    29,    11,    12,    12,    42,
      30,   154,    21,   155,    43,    13,   137,     1,   164,   104,
      68,   135,    69,   136,    57,    70,    24,    25,     1,   167,
      26,    87,    54,    10,    27,    91,    58,    28,    29,    25,
       1,    12,    26,    30,     1,    88,    27,    68,    13,    28,
      29,    10,    70,   133,    58,    30,   118,   119,   120,    12,
     123,   124,   125,   135,   141,    58,   160,    85,   161,    24,
      61,   162,   109,   110,   111,   112,   113,   114,   158,    58,
     145,   146,    82,    86,   142,    89,   102,    88,   169,   106,
     108,    24,   143,   144,   152,   153,   157,   168,    27,   171,
      48,    56,    84,   147,   116,   150,   156
};

static const yytype_uint8 yycheck[] =
{
       0,    11,     0,    13,    12,    61,     6,     7,    27,    12,
      10,    11,    12,    13,    70,    75,    15,    16,    17,    27,
      15,    16,    22,    31,    27,    25,    82,    12,    31,   143,
      86,    31,    88,   121,    24,    24,    46,    21,   152,   139,
     127,    17,    27,    19,    63,    24,    46,    36,    38,    48,
      49,    19,    51,    48,    54,    63,    15,   171,    58,   147,
      63,   161,   122,   150,    23,    24,    34,    26,    87,    54,
      22,    30,     9,    10,    33,    34,    28,    30,    30,    87,
      39,    17,    10,    19,    87,    37,    96,    24,   148,    15,
      27,    91,    29,    92,    22,    32,    96,    23,    24,   155,
      26,    18,    32,    22,    30,    18,    19,    33,    34,    23,
      24,    30,    26,    39,    24,    32,    30,    27,    37,    33,
      34,    22,    32,    18,    19,    39,     9,    10,    11,    30,
      12,    13,    14,   133,    18,    19,    17,    34,    19,   139,
      32,   141,     3,     4,     5,     6,     7,     8,    18,    19,
     115,   116,    32,    25,    17,    15,    34,    32,   158,    15,
      34,   161,    17,    17,    17,    34,    34,    34,    30,    20,
      15,    20,    31,   117,    74,   126,   133
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    38,    42,    43,    44,    86,    45,     0,    21,
      22,    28,    30,    37,    46,    47,    48,    50,    52,    86,
      86,    43,    51,    82,    86,    23,    26,    30,    33,    34,
      39,    53,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    68,    81,    84,    86,    88,    49,    82,    48,    50,
      52,    50,    52,    52,    32,    54,    54,    43,    19,    34,
      86,    32,    59,    67,    86,    88,     9,    10,    27,    29,
      32,    69,    70,    71,    72,    76,    77,    80,    81,    84,
      87,    88,    32,    15,    58,    34,    25,    18,    32,    15,
      82,    18,    50,    52,    52,    52,    36,    56,    57,    82,
      88,    86,    34,    69,    15,    59,    15,    69,    34,     3,
       4,     5,     6,     7,     8,    74,    74,    77,     9,    10,
      11,    73,    75,    12,    13,    14,    78,    79,    69,    69,
      59,    69,    83,    18,    85,    86,    52,    82,    17,    19,
      55,    18,    17,    17,    17,    71,    71,    73,    75,    77,
      79,    80,    17,    34,    17,    19,    85,    34,    18,    56,
      17,    19,    86,    66,    77,    80,    66,    69,    34,    86,
      56,    20,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    44,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    48,    49,    49,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    61,    62,    63,    64,    64,
      65,    66,    66,    67,    67,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    76,
      77,    77,    78,    78,    79,    79,    79,    80,    80,    80,
      80,    81,    82,    82,    83,    83,    84,    85,    86,    87,
      88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     0,     4,     1,     2,     2,
       2,     3,     3,     3,     4,     3,     2,     4,     5,     2,
       1,     2,     3,     3,     1,     2,     4,     3,     3,     2,
       3,     1,     4,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     2,     3,     3,     5,     7,
       5,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       3,     3,     2,     1,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     1,     3,     1,     1,     1,     1,
       0
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
#line 59 "src/parser.y"
                                                                                                                                        { genNode(C_PROGRAM, 1); return 0; }
#line 1290 "src/parser.c"
    break;

  case 3: /* function: function_header block  */
#line 61 "src/parser.y"
                                                                                    { genNode(C_FUNCTION, 2); }
#line 1296 "src/parser.c"
    break;

  case 4: /* function_header: identifier identifier formal_parameters  */
#line 63 "src/parser.y"
                                                                                    { genNode(C_FUNCTION_HEADER, 3); }
#line 1302 "src/parser.c"
    break;

  case 5: /* $@1: %empty  */
#line 64 "src/parser.y"
       { genEmpty(); }
#line 1308 "src/parser.c"
    break;

  case 6: /* function_header: VOID $@1 identifier formal_parameters  */
#line 64 "src/parser.y"
                                                                                    { genNode(C_FUNCTION_HEADER, 2); }
#line 1314 "src/parser.c"
    break;

  case 7: /* block: body  */
#line 66 "src/parser.y"
                                                                                                                                                                { genNode(C_BLOCK, 1); }
#line 1320 "src/parser.c"
    break;

  case 8: /* block: labels body  */
#line 67 "src/parser.y"
                                                                                                                                                        { genNode(C_BLOCK, 2); }
#line 1326 "src/parser.c"
    break;

  case 9: /* block: variables body  */
#line 68 "src/parser.y"
                                                                                                                                                        { genNode(C_BLOCK, 2); }
#line 1332 "src/parser.c"
    break;

  case 10: /* block: functions body  */
#line 69 "src/parser.y"
                                                                                                                                                { genNode(C_BLOCK, 2); }
#line 1338 "src/parser.c"
    break;

  case 11: /* block: labels variables body  */
#line 70 "src/parser.y"
                                                                                                                                        { genNode(C_BLOCK, 3); }
#line 1344 "src/parser.c"
    break;

  case 12: /* block: labels functions body  */
#line 71 "src/parser.y"
                                                                                                                                        { genNode(C_BLOCK, 3); }
#line 1350 "src/parser.c"
    break;

  case 13: /* block: variables functions body  */
#line 72 "src/parser.y"
                                                                                                                                                { genNode(C_BLOCK, 3); }
#line 1356 "src/parser.c"
    break;

  case 14: /* block: labels variables functions body  */
#line 73 "src/parser.y"
                                                                                    { genNode(C_BLOCK, 4); }
#line 1362 "src/parser.c"
    break;

  case 15: /* labels: LABELS identifier_list SEMI_COLON  */
#line 75 "src/parser.y"
                                                                                                                                { genNode(C_LABELS, 1); }
#line 1368 "src/parser.c"
    break;

  case 16: /* variables: VARS declaration_vars  */
#line 77 "src/parser.y"
                                                                                                                                        { genNode(C_VARIABLES, 1); }
#line 1374 "src/parser.c"
    break;

  case 17: /* declaration_vars: identifier_list COLON type SEMI_COLON  */
#line 79 "src/parser.y"
                                                                                                                { genNode(C_DECLARATION_VARS, 2); }
#line 1380 "src/parser.c"
    break;

  case 18: /* declaration_vars: declaration_vars identifier_list COLON type SEMI_COLON  */
#line 80 "src/parser.y"
                                                                                                                { genNode(C_DECLARATION_VARS, 2); insertTopList(); }
#line 1386 "src/parser.c"
    break;

  case 19: /* functions: FUNCTIONS declaration_funcs  */
#line 82 "src/parser.y"
                                                                                                                                { genNode(C_FUNCTIONS, 1); }
#line 1392 "src/parser.c"
    break;

  case 20: /* declaration_funcs: function  */
#line 84 "src/parser.y"
                                                                                                                                                { genNode(C_DECLARATION_FUNCS, 1); }
#line 1398 "src/parser.c"
    break;

  case 21: /* declaration_funcs: declaration_funcs function  */
#line 85 "src/parser.y"
                                                                                                                                        { genNode(C_DECLARATION_FUNCS, 1); insertTopList(); }
#line 1404 "src/parser.c"
    break;

  case 22: /* body: OPEN_BRACE statements CLOSE_BRACE  */
#line 87 "src/parser.y"
                                                                                                                                { genNode(C_BODY, 1); }
#line 1410 "src/parser.c"
    break;

  case 23: /* body: OPEN_BRACE empty CLOSE_BRACE  */
#line 88 "src/parser.y"
                                                                                                                                        { genNode(C_BODY, 1); }
#line 1416 "src/parser.c"
    break;

  case 24: /* statements: statement  */
#line 90 "src/parser.y"
                                                                                                                                                { genNode(C_STATEMENTS, 1); }
#line 1422 "src/parser.c"
    break;

  case 25: /* statements: statements statement  */
#line 91 "src/parser.y"
                                                                                                                                                { genNode(C_STATEMENTS, 1); insertTopList(); }
#line 1428 "src/parser.c"
    break;

  case 26: /* formal_parameters: OPEN_PAREN formal_parameter formal_parameter_rest CLOSE_PAREN  */
#line 93 "src/parser.y"
                                                                                        { genNode(C_FORMAL_PARAMS, 2); }
#line 1434 "src/parser.c"
    break;

  case 27: /* formal_parameters: OPEN_PAREN formal_parameter CLOSE_PAREN  */
#line 94 "src/parser.y"
                                                                                                                                { genNode(C_FORMAL_PARAMS, 1); }
#line 1440 "src/parser.c"
    break;

  case 28: /* formal_parameters: OPEN_PAREN empty CLOSE_PAREN  */
#line 95 "src/parser.y"
                                                                                                                                        { genNode(C_FORMAL_PARAMS, 1); }
#line 1446 "src/parser.c"
    break;

  case 29: /* formal_parameter_rest: COMMA formal_parameter  */
#line 97 "src/parser.y"
                                                                                                                        { genNode(C_FORMAL_PARAMS_REST, 1); }
#line 1452 "src/parser.c"
    break;

  case 30: /* formal_parameter_rest: formal_parameter_rest COMMA formal_parameter  */
#line 98 "src/parser.y"
                                                                                                                        { genNode(C_FORMAL_PARAMS_REST, 1); insertTopList(); }
#line 1458 "src/parser.c"
    break;

  case 31: /* formal_parameter: expression_parameter  */
#line 100 "src/parser.y"
                                                                                                                                { genNode(C_FORMAL_PARAM, 1); }
#line 1464 "src/parser.c"
    break;

  case 32: /* expression_parameter: VAR identifier_list COLON identifier  */
#line 102 "src/parser.y"
                                                                                                                { genNode(C_EXPRESSION_PARAM, 2); }
#line 1470 "src/parser.c"
    break;

  case 33: /* expression_parameter: identifier_list COLON identifier  */
#line 103 "src/parser.y"
                                                                                                                                        { genNode(C_EXPRESSION_PARAM, 2); }
#line 1476 "src/parser.c"
    break;

  case 34: /* statement: unlabeled_statement  */
#line 105 "src/parser.y"
                                                                                                                                        { genNode(C_STATEMENT, 1); }
#line 1482 "src/parser.c"
    break;

  case 35: /* statement: identifier COLON unlabeled_statement  */
#line 106 "src/parser.y"
                                                                                                                                { genNode(C_STATEMENT, 2); }
#line 1488 "src/parser.c"
    break;

  case 36: /* unlabeled_statement: assignment  */
#line 108 "src/parser.y"
                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1494 "src/parser.c"
    break;

  case 37: /* unlabeled_statement: function_call_statement  */
#line 109 "src/parser.y"
                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1500 "src/parser.c"
    break;

  case 38: /* unlabeled_statement: goto  */
#line 110 "src/parser.y"
                                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1506 "src/parser.c"
    break;

  case 39: /* unlabeled_statement: return  */
#line 111 "src/parser.y"
                                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1512 "src/parser.c"
    break;

  case 40: /* unlabeled_statement: conditional  */
#line 112 "src/parser.y"
                                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1518 "src/parser.c"
    break;

  case 41: /* unlabeled_statement: repetitive  */
#line 113 "src/parser.y"
                                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1524 "src/parser.c"
    break;

  case 42: /* unlabeled_statement: compound  */
#line 114 "src/parser.y"
                                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1530 "src/parser.c"
    break;

  case 43: /* unlabeled_statement: empty_statement  */
#line 115 "src/parser.y"
                                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1536 "src/parser.c"
    break;

  case 44: /* assignment: variable ASSIGN expression SEMI_COLON  */
#line 117 "src/parser.y"
                                                                                                                        { genNode(C_ASSIGNMENT, 2); }
#line 1542 "src/parser.c"
    break;

  case 45: /* function_call_statement: function_call SEMI_COLON  */
#line 119 "src/parser.y"
                                                                                                                        { genNode(C_FUNCTION_CALL_STATEMENT, 1); }
#line 1548 "src/parser.c"
    break;

  case 46: /* goto: GOTO identifier SEMI_COLON  */
#line 121 "src/parser.y"
                                                                                                                                        { genNode(C_GOTO, 1); }
#line 1554 "src/parser.c"
    break;

  case 47: /* return: RETURN expression SEMI_COLON  */
#line 123 "src/parser.y"
                                                                                                                                { genNode(C_RETURN, 1); }
#line 1560 "src/parser.c"
    break;

  case 48: /* conditional: IF OPEN_PAREN expression CLOSE_PAREN compound  */
#line 125 "src/parser.y"
                                                                                                                { genNode(C_CONDITIONAL, 2); }
#line 1566 "src/parser.c"
    break;

  case 49: /* conditional: IF OPEN_PAREN expression CLOSE_PAREN compound ELSE compound  */
#line 126 "src/parser.y"
                                                                                                        { genNode(C_CONDITIONAL, 3); }
#line 1572 "src/parser.c"
    break;

  case 50: /* repetitive: WHILE OPEN_PAREN expression CLOSE_PAREN compound  */
#line 128 "src/parser.y"
                                                                                                        { genNode(C_REPETITIVE, 2); }
#line 1578 "src/parser.c"
    break;

  case 51: /* compound: OPEN_BRACE unlabeled_statements CLOSE_BRACE  */
#line 130 "src/parser.y"
                                                                                                                { genNode(C_COMPOUND, 1); }
#line 1584 "src/parser.c"
    break;

  case 52: /* compound: OPEN_BRACE empty CLOSE_BRACE  */
#line 131 "src/parser.y"
                                                                                                                                        { genNode(C_COMPOUND, 1); }
#line 1590 "src/parser.c"
    break;

  case 53: /* unlabeled_statements: unlabeled_statement  */
#line 133 "src/parser.y"
                                                                                                                                { genNode(C_UNLABELED_STATEMENTS, 1); }
#line 1596 "src/parser.c"
    break;

  case 54: /* unlabeled_statements: unlabeled_statements unlabeled_statement  */
#line 134 "src/parser.y"
                                                                                                                                { genNode(C_UNLABELED_STATEMENTS, 1); insertTopList(); }
#line 1602 "src/parser.c"
    break;

  case 55: /* empty_statement: SEMI_COLON  */
#line 136 "src/parser.y"
                                                                                                                                                { /*?*/ genEmpty(); }
#line 1608 "src/parser.c"
    break;

  case 56: /* expression: simple_expression  */
#line 138 "src/parser.y"
                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1614 "src/parser.c"
    break;

  case 57: /* expression: binop_expression  */
#line 139 "src/parser.y"
                                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1620 "src/parser.c"
    break;

  case 58: /* expression: unop_expression  */
#line 140 "src/parser.y"
                                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1626 "src/parser.c"
    break;

  case 60: /* binop_expression: unop_expression relational_operator simple_expression  */
#line 143 "src/parser.y"
                                                                                                { /*!*/ genNode(C_BINOP_EXPRESSION, 3); }
#line 1632 "src/parser.c"
    break;

  case 61: /* binop_expression: simple_expression relational_operator simple_expression  */
#line 144 "src/parser.y"
                                                                                                                { /*!*/ genNode(C_BINOP_EXPRESSION, 3); }
#line 1638 "src/parser.c"
    break;

  case 62: /* simple_expression: term additive_term  */
#line 146 "src/parser.y"
                                                                                                                        { genNode(C_SIMPLE_EXPRESSION, 2); }
#line 1644 "src/parser.c"
    break;

  case 63: /* simple_expression: term  */
#line 147 "src/parser.y"
                                                                                                                                                                { genNode(C_SIMPLE_EXPRESSION, 1); }
#line 1650 "src/parser.c"
    break;

  case 64: /* unop_expression: unary_operator term additive_term  */
#line 149 "src/parser.y"
                                                                                                                        { /*!*/ genNode(C_UNOP_EXPRESSION, 3); }
#line 1656 "src/parser.c"
    break;

  case 65: /* unop_expression: unary_operator term  */
#line 150 "src/parser.y"
                                                                                                                                                { /*!*/ genNode(C_UNOP_EXPRESSION, 2); }
#line 1662 "src/parser.c"
    break;

  case 66: /* additive_term: additive_operator term  */
#line 152 "src/parser.y"
                                                                                                                                { /*!*/ genNode(C_ADDITIVE_TERM, 2); }
#line 1668 "src/parser.c"
    break;

  case 67: /* additive_term: additive_term additive_operator term  */
#line 153 "src/parser.y"
                                                                                                                                { /*!*/ genNode(C_ADDITIVE_TERM, 2); insertTopList(); }
#line 1674 "src/parser.c"
    break;

  case 69: /* relational_operator: LESS  */
#line 156 "src/parser.y"
                                                                                                                                                                { genOpSymbol(C_LESS); }
#line 1680 "src/parser.c"
    break;

  case 73: /* relational_operator: GREATER  */
#line 160 "src/parser.y"
                                                                                                                                                                { genOpSymbol(C_GREATER); }
#line 1686 "src/parser.c"
    break;

  case 74: /* additive_operator: PLUS  */
#line 162 "src/parser.y"
                                                                                                                                                { genOpSymbol(C_PLUS); }
#line 1692 "src/parser.c"
    break;

  case 75: /* additive_operator: MINUS  */
#line 163 "src/parser.y"
                                                                                                                                                                { genOpSymbol(C_MINUS); }
#line 1698 "src/parser.c"
    break;

  case 77: /* unary_operator: PLUS  */
#line 166 "src/parser.y"
                                                                                                                                                { genOpSymbol(C_PLUS); }
#line 1704 "src/parser.c"
    break;

  case 78: /* unary_operator: MINUS  */
#line 167 "src/parser.y"
                                                                                                                                                                { genOpSymbol(C_MINUS); }
#line 1710 "src/parser.c"
    break;

  case 80: /* term: factor multiplicative_factor  */
#line 170 "src/parser.y"
                                                                                                                                        { genNode(C_TERM, 2); }
#line 1716 "src/parser.c"
    break;

  case 81: /* term: factor  */
#line 171 "src/parser.y"
                                                                                                                                                                { genNode(C_TERM, 1); }
#line 1722 "src/parser.c"
    break;

  case 82: /* multiplicative_factor: multiplicative_operator factor  */
#line 173 "src/parser.y"
                                                                                                                { /*!*/ genNode(C_MULTIPLICATIVE_FACTOR, 2); }
#line 1728 "src/parser.c"
    break;

  case 83: /* multiplicative_factor: multiplicative_factor multiplicative_operator factor  */
#line 174 "src/parser.y"
                                                                                                                { /*!*/ genNode(C_MULTIPLICATIVE_FACTOR, 2); insertTopList(); }
#line 1734 "src/parser.c"
    break;

  case 84: /* multiplicative_operator: MULTIPLY  */
#line 176 "src/parser.y"
                                                                                                                                        { genOpSymbol(C_MULTIPLY); }
#line 1740 "src/parser.c"
    break;

  case 87: /* factor: variable  */
#line 180 "src/parser.y"
                                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1746 "src/parser.c"
    break;

  case 88: /* factor: integer  */
#line 181 "src/parser.y"
                                                                                                                                                                { genNode(C_FACTOR, 1); }
#line 1752 "src/parser.c"
    break;

  case 89: /* factor: function_call  */
#line 182 "src/parser.y"
                                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1758 "src/parser.c"
    break;

  case 90: /* factor: OPEN_PAREN expression CLOSE_PAREN  */
#line 183 "src/parser.y"
                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1764 "src/parser.c"
    break;

  case 91: /* function_call: identifier OPEN_PAREN expression_list CLOSE_PAREN  */
#line 185 "src/parser.y"
                                                                                                        { genNode(C_FUNCTION_CALL, 2); }
#line 1770 "src/parser.c"
    break;

  case 92: /* identifier_list: identifier  */
#line 187 "src/parser.y"
                                                                                                                        { genNode(C_IDENTIFIER_LIST, 1); }
#line 1776 "src/parser.c"
    break;

  case 93: /* identifier_list: identifier_list COMMA identifier  */
#line 188 "src/parser.y"
                                                                                                                                        { genNode(C_IDENTIFIER_LIST, 1); insertTopList(); }
#line 1782 "src/parser.c"
    break;

  case 94: /* expression_list: expression  */
#line 190 "src/parser.y"
                                                                                                                        { genNode(C_EXPRESSION_LIST, 1); }
#line 1788 "src/parser.c"
    break;

  case 95: /* expression_list: expression_list COMMA expression  */
#line 191 "src/parser.y"
                                                                                                                                        { genNode(C_EXPRESSION_LIST, 1); insertTopList(); }
#line 1794 "src/parser.c"
    break;

  case 96: /* variable: identifier  */
#line 193 "src/parser.y"
                                                                                                                                                { genNode(C_VARIABLE, 1); }
#line 1800 "src/parser.c"
    break;

  case 97: /* type: identifier  */
#line 195 "src/parser.y"
                                                                                                                                                        { genNode(C_TYPE, 1); }
#line 1806 "src/parser.c"
    break;

  case 98: /* identifier: IDENTIFIER  */
#line 197 "src/parser.y"
                                                                                                                                                { genIdent((yyvsp[0].symbol)); }
#line 1812 "src/parser.c"
    break;

  case 99: /* integer: INTEGER  */
#line 199 "src/parser.y"
                                                                                                                                                        { genInt((yyvsp[0].symbol)); }
#line 1818 "src/parser.c"
    break;

  case 100: /* empty: %empty  */
#line 201 "src/parser.y"
                                                                                                                                                        { genEmpty(); }
#line 1824 "src/parser.c"
    break;


#line 1828 "src/parser.c"

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

#line 204 "src/parser.y"


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

void genEmpty() 
{
	push(NULL);
}

void genOpSymbol(Categ categ)
{
	genNode(categ, 0);
}

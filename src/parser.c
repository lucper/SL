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
#line 1 "parser.y"

#include <stdlib.h>
#include "test_tree.h"
#include "tree.h"

void insertTopList();
void genNode3(Categ categ, int numComps, char *ident);
void genNode(Categ categ, int numComps);
void genIdent(char *token_val);
void genInt(char *token_val);
void genEmpty();
void genOpSymbol(Categ categ);

ParseStackNode *top = NULL; // global to be accessed by getTree()

#line 87 "parser.c"

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
  YYSYMBOL_types = 47,                     /* types  */
  YYSYMBOL_types_list = 48,                /* types_list  */
  YYSYMBOL_labels = 49,                    /* labels  */
  YYSYMBOL_variables = 50,                 /* variables  */
  YYSYMBOL_declaration_vars = 51,          /* declaration_vars  */
  YYSYMBOL_functions = 52,                 /* functions  */
  YYSYMBOL_declaration_funcs = 53,         /* declaration_funcs  */
  YYSYMBOL_body = 54,                      /* body  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_array_size = 57,                /* array_size  */
  YYSYMBOL_formal_parameters = 58,         /* formal_parameters  */
  YYSYMBOL_formal_parameter_rest = 59,     /* formal_parameter_rest  */
  YYSYMBOL_formal_parameter = 60,          /* formal_parameter  */
  YYSYMBOL_function_parameter = 61,        /* function_parameter  */
  YYSYMBOL_expression_parameter = 62,      /* expression_parameter  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_variable = 64,                  /* variable  */
  YYSYMBOL_array = 65,                     /* array  */
  YYSYMBOL_unlabeled_statement = 66,       /* unlabeled_statement  */
  YYSYMBOL_assignment = 67,                /* assignment  */
  YYSYMBOL_function_call_statement = 68,   /* function_call_statement  */
  YYSYMBOL_goto = 69,                      /* goto  */
  YYSYMBOL_return = 70,                    /* return  */
  YYSYMBOL_conditional = 71,               /* conditional  */
  YYSYMBOL_repetitive = 72,                /* repetitive  */
  YYSYMBOL_compound = 73,                  /* compound  */
  YYSYMBOL_unlabeled_statements = 74,      /* unlabeled_statements  */
  YYSYMBOL_empty_statement = 75,           /* empty_statement  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_binop_expression = 77,          /* binop_expression  */
  YYSYMBOL_simple_expression = 78,         /* simple_expression  */
  YYSYMBOL_unop_expression = 79,           /* unop_expression  */
  YYSYMBOL_additive_term = 80,             /* additive_term  */
  YYSYMBOL_relational_operator = 81,       /* relational_operator  */
  YYSYMBOL_additive_operator = 82,         /* additive_operator  */
  YYSYMBOL_unary_operator = 83,            /* unary_operator  */
  YYSYMBOL_term = 84,                      /* term  */
  YYSYMBOL_multiplicative_factor = 85,     /* multiplicative_factor  */
  YYSYMBOL_multiplicative_operator = 86,   /* multiplicative_operator  */
  YYSYMBOL_factor = 87,                    /* factor  */
  YYSYMBOL_function_call = 88,             /* function_call  */
  YYSYMBOL_identifier_list = 89,           /* identifier_list  */
  YYSYMBOL_identifier_list_rest = 90,      /* identifier_list_rest  */
  YYSYMBOL_expression_list = 91,           /* expression_list  */
  YYSYMBOL_expression_list_rest = 92,      /* expression_list_rest  */
  YYSYMBOL_identifier = 93,                /* identifier  */
  YYSYMBOL_integer = 94,                   /* integer  */
  YYSYMBOL_empty = 95                      /* empty  */
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
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

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
       0,    60,    60,    62,    64,    65,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    84,    86,    87,    89,    91,    93,    94,
      96,    98,    99,   101,   102,   104,   105,   107,   108,   110,
     111,   113,   114,   115,   117,   118,   120,   121,   123,   125,
     126,   128,   129,   131,   132,   134,   135,   137,   138,   139,
     140,   141,   142,   143,   144,   146,   148,   150,   152,   154,
     155,   157,   159,   160,   162,   163,   165,   167,   168,   169,
     170,   172,   173,   175,   176,   178,   179,   181,   182,   184,
     185,   186,   187,   188,   189,   191,   192,   193,   195,   196,
     197,   199,   200,   202,   203,   205,   206,   207,   209,   210,
     211,   212,   214,   216,   217,   219,   220,   222,   223,   225,
     226,   228,   230,   232
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
  "program", "function", "function_header", "$@1", "block", "types",
  "types_list", "labels", "variables", "declaration_vars", "functions",
  "declaration_funcs", "body", "statements", "type", "array_size",
  "formal_parameters", "formal_parameter_rest", "formal_parameter",
  "function_parameter", "expression_parameter", "statement", "variable",
  "array", "unlabeled_statement", "assignment", "function_call_statement",
  "goto", "return", "conditional", "repetitive", "compound",
  "unlabeled_statements", "empty_statement", "expression",
  "binop_expression", "simple_expression", "unop_expression",
  "additive_term", "relational_operator", "additive_operator",
  "unary_operator", "term", "multiplicative_factor",
  "multiplicative_operator", "factor", "function_call", "identifier_list",
  "identifier_list_rest", "expression_list", "expression_list_rest",
  "identifier", "integer", "empty", YY_NULLPTR
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

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      50,  -146,  -146,    31,    48,   100,    61,    61,  -146,  -146,
      50,    61,   150,    61,    61,  -146,    21,   120,    24,    57,
    -146,    82,    82,  -146,    50,    84,   121,    61,   127,   150,
      74,  -146,   136,    93,  -146,   137,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,   141,    68,   166,    61,   146,
      61,   164,    24,    57,  -146,    21,    24,    57,  -146,    57,
    -146,  -146,   105,  -146,  -146,  -146,  -146,    61,   167,   151,
      74,  -146,   130,   116,   172,  -146,  -146,  -146,  -146,    74,
    -146,   154,  -146,   187,   187,    65,   156,   165,  -146,  -146,
    -146,    74,  -146,  -146,    74,  -146,   150,    74,    74,   168,
    -146,   171,    61,   179,    61,    57,  -146,  -146,    24,    57,
    -146,    57,  -146,  -146,  -146,    61,  -146,    62,  -146,  -146,
     182,   115,   185,  -146,    61,  -146,   186,  -146,  -146,  -146,
     188,  -146,  -146,  -146,  -146,  -146,  -146,  -146,    65,    65,
     156,  -146,  -146,  -146,   156,    65,  -146,  -146,  -146,   165,
      65,   189,   170,  -146,   191,   190,   193,    74,    61,   174,
     180,    61,   178,  -146,    57,  -146,  -146,  -146,   195,  -146,
     105,   119,    61,  -146,  -146,   184,  -146,  -146,  -146,   156,
      65,  -146,    65,  -146,   184,  -146,  -146,    74,   196,  -146,
     200,   183,  -146,   192,   194,   197,  -146,  -146,    61,  -146,
    -146,   105,  -146,   198,  -146,  -146,  -146,  -146,    74,  -146,
    -146,   204,   192,  -146,  -146,  -146,   184,  -146,  -146,   205,
    -146,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   121,     5,     0,     0,     0,     0,     0,     1,     2,
       0,     0,   123,     0,     0,     3,     0,     0,     0,     0,
      22,     0,     0,    31,    30,     0,   114,     0,     0,   123,
     123,    76,     0,     0,    35,     0,    51,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    54,     0,    23,     0,
      27,     0,     0,     0,     8,     0,     0,     0,     7,     0,
       9,    10,   123,     4,     6,    32,    26,     0,   113,     0,
     123,    74,     0,    54,     0,    98,    99,   122,   100,   123,
     108,     0,    78,    77,    79,     0,    84,   102,   110,   109,
      80,   123,    33,    36,   123,    66,     0,   123,   123,    53,
      34,     0,     0,     0,     0,     0,    14,    15,     0,     0,
      11,     0,    12,    13,    16,     0,    48,     0,    47,    46,
       0,   114,     0,   115,     0,    67,     0,    72,    75,    73,
       0,    68,    91,    92,    90,    89,    94,    93,     0,     0,
      86,    95,    96,    97,    83,     0,   105,   106,   107,   101,
       0,     0,     0,    52,     0,   118,     0,   123,     0,     0,
      38,     0,     0,    20,     0,    17,    18,    19,     0,    42,
       0,     0,     0,    43,   116,     0,   111,    82,    81,    85,
       0,    87,     0,   103,     0,    65,    55,   123,   117,   112,
       0,     0,    24,     0,    37,     0,    28,    21,     0,    44,
      41,     0,    50,    69,    88,   104,    71,   119,   123,    56,
      25,     0,     0,    29,    49,    45,     0,   120,    39,     0,
      70,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,    81,   -57,  -146,  -146,   206,  -146,  -146,    56,
    -146,     4,  -146,   -15,  -146,   -81,  -146,   202,  -146,  -136,
    -146,  -146,   199,    35,  -146,   -20,  -146,  -146,  -146,  -146,
    -146,  -146,  -145,  -146,  -146,   -62,  -146,    13,  -146,    86,
     138,  -118,  -146,   -70,  -146,    78,  -125,    37,     5,  -146,
    -146,  -146,     0,  -130,    16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     7,    15,    16,    48,    17,    18,
      50,    19,    24,    20,    33,   159,   194,    63,   171,   117,
     118,   119,    34,    80,    99,    36,    37,    38,    39,    40,
      41,    42,    43,    72,    44,    81,    82,    83,    84,   144,
     138,   145,    85,    86,   149,   150,    87,    88,   120,    68,
     156,   188,    73,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    54,    58,    60,    61,   116,    21,    22,   126,    71,
       6,    26,    46,    26,    26,   140,    25,   130,    49,    51,
      53,    57,    59,   162,     6,   183,   180,    69,    47,   151,
     203,     8,   152,    46,   199,   154,   155,   106,   107,   206,
     110,   112,   113,    10,   114,    74,    10,    35,    26,    45,
      26,    12,   128,   101,    12,   103,   105,   205,    14,   109,
     111,   180,   121,   211,    35,   215,    45,   123,    35,     9,
      45,   220,    52,    56,     1,   181,   153,   191,   122,   169,
     195,   170,   219,    75,    76,     1,    96,    12,     2,     1,
     163,    23,    77,   165,   166,   190,   167,    79,     1,    97,
      98,    77,   160,    78,   160,    65,    79,    35,    92,    45,
     204,   108,   164,   116,    62,    26,    27,     1,    66,    28,
     168,    21,    10,    29,   174,   207,    30,    31,    11,     1,
      12,    35,    32,    45,    67,    13,   200,    14,   201,     1,
      67,   115,    10,     2,   116,   127,   217,    97,    98,   197,
      12,   177,   178,    27,     1,    13,    28,    14,   160,    70,
      29,   160,    94,    30,    31,   141,   142,   143,    91,    32,
     121,   102,   202,    27,     1,    95,    28,   146,   147,   148,
      29,   100,   104,    30,    31,   125,   124,   129,   131,    32,
     132,   133,   134,   135,   136,   137,   158,   161,   214,   157,
     172,   121,   173,   175,   185,   176,   184,   186,   192,   187,
     189,   193,   196,   198,    29,   208,   209,   210,   216,    77,
     218,   221,   139,    55,    64,   212,   179,   182,     0,     0,
       0,   213,    93
};

static const yytype_int16 yycheck[] =
{
       0,    16,    17,    18,    19,    62,     6,     7,    70,    29,
      10,    11,    12,    13,    14,    85,    11,    79,    13,    14,
      16,    17,    18,   104,    24,   150,   144,    27,    12,    91,
     175,     0,    94,    33,   170,    97,    98,    52,    53,   184,
      55,    56,    57,    22,    59,    29,    22,    12,    48,    12,
      50,    30,    72,    48,    30,    50,    52,   182,    37,    55,
      56,   179,    62,   193,    29,   201,    29,    67,    33,    21,
      33,   216,    16,    17,    24,   145,    96,   158,    62,    17,
     161,    19,   212,     9,    10,    24,    18,    30,    38,    24,
     105,    10,    27,   108,   109,   157,   111,    32,    24,    31,
      32,    27,   102,    29,   104,    24,    32,    72,    15,    72,
     180,    55,   108,   170,    32,   115,    23,    24,    34,    26,
     115,   121,    22,    30,   124,   187,    33,    34,    28,    24,
      30,    96,    39,    96,    19,    35,    17,    37,    19,    24,
      19,    36,    22,    38,   201,    15,   208,    31,    32,   164,
      30,   138,   139,    23,    24,    35,    26,    37,   158,    32,
      30,   161,    25,    33,    34,     9,    10,    11,    32,    39,
     170,    25,   172,    23,    24,    34,    26,    12,    13,    14,
      30,    15,    18,    33,    34,    34,    19,    15,    34,    39,
       3,     4,     5,     6,     7,     8,    25,    18,   198,    31,
      18,   201,    17,    17,    34,    17,    17,    16,    34,    19,
      17,    31,    34,    18,    30,    19,    16,    34,    20,    27,
      16,    16,    84,    17,    22,    31,   140,   149,    -1,    -1,
      -1,    34,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    38,    42,    43,    44,    93,    45,     0,    21,
      22,    28,    30,    35,    37,    46,    47,    49,    50,    52,
      54,    93,    93,    43,    53,    89,    93,    23,    26,    30,
      33,    34,    39,    55,    63,    64,    66,    67,    68,    69,
      70,    71,    72,    73,    75,    88,    93,    95,    48,    89,
      51,    89,    50,    52,    54,    47,    50,    52,    54,    52,
      54,    54,    32,    58,    58,    43,    34,    19,    90,    93,
      32,    66,    74,    93,    95,     9,    10,    27,    29,    32,
      64,    76,    77,    78,    79,    83,    84,    87,    88,    94,
      95,    32,    15,    63,    25,    34,    18,    31,    32,    65,
      15,    89,    25,    89,    18,    52,    54,    54,    50,    52,
      54,    52,    54,    54,    54,    36,    44,    60,    61,    62,
      89,    93,    95,    93,    19,    34,    76,    15,    66,    15,
      76,    34,     3,     4,     5,     6,     7,     8,    81,    81,
      84,     9,    10,    11,    80,    82,    12,    13,    14,    85,
      86,    76,    76,    66,    76,    76,    91,    31,    25,    56,
      93,    18,    56,    54,    52,    54,    54,    54,    89,    17,
      19,    59,    18,    17,    93,    17,    17,    78,    78,    80,
      82,    84,    86,    87,    17,    34,    16,    19,    92,    17,
      76,    56,    34,    31,    57,    56,    34,    54,    18,    60,
      17,    19,    93,    73,    84,    87,    73,    76,    19,    16,
      34,    94,    31,    34,    93,    60,    20,    76,    16,    94,
      73,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    44,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    48,    48,    49,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    59,    60,    60,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    68,    69,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    76,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    86,    87,    87,
      87,    87,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     3,     0,     4,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     5,     1,     2,     4,     5,     3,     2,     4,     5,
       2,     1,     2,     3,     3,     1,     2,     2,     1,     3,
       4,     4,     3,     3,     2,     3,     1,     1,     1,     4,
       3,     1,     3,     2,     1,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     3,     3,     5,
       7,     5,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     3,     3,     2,     1,     3,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     2,     1,     2,     3,     2,     1,     2,
       3,     1,     1,     0
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
#line 60 "parser.y"
                                                                                                                        { genNode(C_PROGRAM, 1); return 0; }
#line 1335 "parser.c"
    break;

  case 3: /* function: function_header block  */
#line 62 "parser.y"
                                                                                                                        { genNode(C_FUNCTION, 2); }
#line 1341 "parser.c"
    break;

  case 4: /* function_header: identifier identifier formal_parameters  */
#line 64 "parser.y"
                                                                                                { genNode(C_FUNCTION_HEADER, 3); }
#line 1347 "parser.c"
    break;

  case 5: /* $@1: %empty  */
#line 65 "parser.y"
               { genEmpty(); }
#line 1353 "parser.c"
    break;

  case 6: /* function_header: VOID $@1 identifier formal_parameters  */
#line 65 "parser.y"
                                                                                                        { genNode(C_FUNCTION_HEADER, 2); }
#line 1359 "parser.c"
    break;

  case 7: /* block: labels body  */
#line 67 "parser.y"
                                                                                                                { genNode(C_BLOCK, 2); }
#line 1365 "parser.c"
    break;

  case 9: /* block: variables body  */
#line 69 "parser.y"
                                                                                                                                        { genNode(C_BLOCK, 2); }
#line 1371 "parser.c"
    break;

  case 16: /* block: variables functions body  */
#line 76 "parser.y"
                                                                                                                                { genNode(C_BLOCK, 3); }
#line 1377 "parser.c"
    break;

  case 20: /* block: types variables functions body  */
#line 80 "parser.y"
                                                                                                                { genNode(C_BLOCK, 4); }
#line 1383 "parser.c"
    break;

  case 22: /* block: body  */
#line 82 "parser.y"
                                                                                                                                                { genNode(C_BLOCK, 1); }
#line 1389 "parser.c"
    break;

  case 23: /* types: TYPES types_list  */
#line 84 "parser.y"
                                                                                                                { genNode(C_TYPES, 1); }
#line 1395 "parser.c"
    break;

  case 24: /* types_list: identifier_list ASSIGN type SEMI_COLON  */
#line 86 "parser.y"
                                                                                        { genNode(C_TYPES_LIST, 2); }
#line 1401 "parser.c"
    break;

  case 25: /* types_list: types_list identifier_list ASSIGN type SEMI_COLON  */
#line 87 "parser.y"
                                                                                                { genNode(C_TYPES_LIST, 2); insertTopList(); }
#line 1407 "parser.c"
    break;

  case 26: /* labels: LABELS identifier_list SEMI_COLON  */
#line 89 "parser.y"
                                                                                                                { genNode(C_LABELS, 1); }
#line 1413 "parser.c"
    break;

  case 27: /* variables: VARS declaration_vars  */
#line 91 "parser.y"
                                                                                                                        { genNode(C_VARIABLES, 1); }
#line 1419 "parser.c"
    break;

  case 28: /* declaration_vars: identifier_list COLON type SEMI_COLON  */
#line 93 "parser.y"
                                                                                                { genNode(C_DECLARATION_VARS, 2); }
#line 1425 "parser.c"
    break;

  case 29: /* declaration_vars: declaration_vars identifier_list COLON type SEMI_COLON  */
#line 94 "parser.y"
                                                                                                { genNode(C_DECLARATION_VARS, 2); insertTopList(); }
#line 1431 "parser.c"
    break;

  case 30: /* functions: FUNCTIONS declaration_funcs  */
#line 96 "parser.y"
                                                                                                                { genNode(C_FUNCTIONS, 1); }
#line 1437 "parser.c"
    break;

  case 31: /* declaration_funcs: function  */
#line 98 "parser.y"
                                                                                                                                { genNode(C_DECLARATION_FUNCS, 1); }
#line 1443 "parser.c"
    break;

  case 32: /* declaration_funcs: declaration_funcs function  */
#line 99 "parser.y"
                                                                                                                        { genNode(C_DECLARATION_FUNCS, 1); insertTopList(); }
#line 1449 "parser.c"
    break;

  case 33: /* body: OPEN_BRACE statements CLOSE_BRACE  */
#line 101 "parser.y"
                                                                                                                { genNode(C_BODY, 1); }
#line 1455 "parser.c"
    break;

  case 34: /* body: OPEN_BRACE empty CLOSE_BRACE  */
#line 102 "parser.y"
                                                                                                                        { genNode(C_BODY, 1); }
#line 1461 "parser.c"
    break;

  case 35: /* statements: statement  */
#line 104 "parser.y"
                                                                                                                                { genNode(C_STATEMENTS, 1); }
#line 1467 "parser.c"
    break;

  case 36: /* statements: statements statement  */
#line 105 "parser.y"
                                                                                                                                { genNode(C_STATEMENTS, 1); insertTopList(); }
#line 1473 "parser.c"
    break;

  case 37: /* type: identifier array_size  */
#line 107 "parser.y"
                                                                                                { genNode(C_TYPE, 2); }
#line 1479 "parser.c"
    break;

  case 38: /* type: identifier  */
#line 108 "parser.y"
                                                                                                                                        { genNode(C_TYPE, 1); }
#line 1485 "parser.c"
    break;

  case 39: /* array_size: OPEN_BRACKET integer CLOSE_BRACKET  */
#line 110 "parser.y"
                                                                                        { genNode(C_ARRAY_SIZE, 1); }
#line 1491 "parser.c"
    break;

  case 40: /* array_size: array_size OPEN_BRACKET integer CLOSE_BRACKET  */
#line 111 "parser.y"
                                                                                                        { genNode(C_ARRAY_SIZE, 1); insertTopList(); }
#line 1497 "parser.c"
    break;

  case 41: /* formal_parameters: OPEN_PAREN formal_parameter formal_parameter_rest CLOSE_PAREN  */
#line 113 "parser.y"
                                                                                        { genNode(C_FORMAL_PARAMS, 2); }
#line 1503 "parser.c"
    break;

  case 42: /* formal_parameters: OPEN_PAREN formal_parameter CLOSE_PAREN  */
#line 114 "parser.y"
                                                                                                                { genNode(C_FORMAL_PARAMS, 1); }
#line 1509 "parser.c"
    break;

  case 43: /* formal_parameters: OPEN_PAREN empty CLOSE_PAREN  */
#line 115 "parser.y"
                                                                                                                        { genNode(C_FORMAL_PARAMS, 1); }
#line 1515 "parser.c"
    break;

  case 44: /* formal_parameter_rest: COMMA formal_parameter  */
#line 117 "parser.y"
                                                                                                        { genNode(C_FORMAL_PARAMS_REST, 1); }
#line 1521 "parser.c"
    break;

  case 45: /* formal_parameter_rest: formal_parameter_rest COMMA formal_parameter  */
#line 118 "parser.y"
                                                                                                        { genNode(C_FORMAL_PARAMS_REST, 1); insertTopList(); }
#line 1527 "parser.c"
    break;

  case 46: /* formal_parameter: expression_parameter  */
#line 120 "parser.y"
                                                                                { genNode(C_FORMAL_PARAM, 1); }
#line 1533 "parser.c"
    break;

  case 47: /* formal_parameter: function_parameter  */
#line 121 "parser.y"
                                                                                                                                { genNode(C_FORMAL_PARAM, 1); }
#line 1539 "parser.c"
    break;

  case 48: /* function_parameter: function_header  */
#line 123 "parser.y"
                                                                                                        { genNode(C_FUNCTION_PARAM, 1); }
#line 1545 "parser.c"
    break;

  case 49: /* expression_parameter: VAR identifier_list COLON identifier  */
#line 125 "parser.y"
                                                                                                { genNode(C_EXPRESSION_PARAM, 2); }
#line 1551 "parser.c"
    break;

  case 50: /* expression_parameter: identifier_list COLON identifier  */
#line 126 "parser.y"
                                                                                                                        { genNode(C_EXPRESSION_PARAM, 2); }
#line 1557 "parser.c"
    break;

  case 51: /* statement: unlabeled_statement  */
#line 128 "parser.y"
                                                                                                                        { genNode(C_STATEMENT, 1); }
#line 1563 "parser.c"
    break;

  case 52: /* statement: identifier COLON unlabeled_statement  */
#line 129 "parser.y"
                                                                                                                { genNode(C_STATEMENT, 2); }
#line 1569 "parser.c"
    break;

  case 53: /* variable: identifier array  */
#line 131 "parser.y"
                                                                                                        { genNode(C_VARIABLE, 2); }
#line 1575 "parser.c"
    break;

  case 54: /* variable: identifier  */
#line 132 "parser.y"
                                                                                                                                        { genNode(C_VARIABLE, 1); }
#line 1581 "parser.c"
    break;

  case 55: /* array: OPEN_BRACKET expression CLOSE_BRACKET  */
#line 134 "parser.y"
                                                                                                { genNode(C_ARRAY, 1); }
#line 1587 "parser.c"
    break;

  case 56: /* array: array OPEN_BRACKET expression CLOSE_BRACKET  */
#line 135 "parser.y"
                                                                                                        { genNode(C_ARRAY, 1); insertTopList(); }
#line 1593 "parser.c"
    break;

  case 57: /* unlabeled_statement: assignment  */
#line 137 "parser.y"
                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1599 "parser.c"
    break;

  case 58: /* unlabeled_statement: function_call_statement  */
#line 138 "parser.y"
                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1605 "parser.c"
    break;

  case 59: /* unlabeled_statement: goto  */
#line 139 "parser.y"
                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1611 "parser.c"
    break;

  case 60: /* unlabeled_statement: return  */
#line 140 "parser.y"
                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1617 "parser.c"
    break;

  case 61: /* unlabeled_statement: conditional  */
#line 141 "parser.y"
                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1623 "parser.c"
    break;

  case 62: /* unlabeled_statement: repetitive  */
#line 142 "parser.y"
                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1629 "parser.c"
    break;

  case 63: /* unlabeled_statement: compound  */
#line 143 "parser.y"
                                                                                                                                                { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1635 "parser.c"
    break;

  case 64: /* unlabeled_statement: empty_statement  */
#line 144 "parser.y"
                                                                                                                                        { genNode(C_UNLABELED_STATEMENT, 1); }
#line 1641 "parser.c"
    break;

  case 65: /* assignment: variable ASSIGN expression SEMI_COLON  */
#line 146 "parser.y"
                                                                                                        { genNode(C_ASSIGNMENT, 2); }
#line 1647 "parser.c"
    break;

  case 66: /* function_call_statement: function_call SEMI_COLON  */
#line 148 "parser.y"
                                                                                                        { genNode(C_FUNCTION_CALL_STATEMENT, 1); }
#line 1653 "parser.c"
    break;

  case 67: /* goto: GOTO identifier SEMI_COLON  */
#line 150 "parser.y"
                                                                                                                        { genNode(C_GOTO, 1); }
#line 1659 "parser.c"
    break;

  case 68: /* return: RETURN expression SEMI_COLON  */
#line 152 "parser.y"
                                                                                                                { genNode(C_RETURN, 1); }
#line 1665 "parser.c"
    break;

  case 69: /* conditional: IF OPEN_PAREN expression CLOSE_PAREN compound  */
#line 154 "parser.y"
                                                                                                { genNode(C_CONDITIONAL, 2); }
#line 1671 "parser.c"
    break;

  case 70: /* conditional: IF OPEN_PAREN expression CLOSE_PAREN compound ELSE compound  */
#line 155 "parser.y"
                                                                                        { genNode(C_CONDITIONAL, 3); }
#line 1677 "parser.c"
    break;

  case 71: /* repetitive: WHILE OPEN_PAREN expression CLOSE_PAREN compound  */
#line 157 "parser.y"
                                                                                        { genNode(C_REPETITIVE, 2); }
#line 1683 "parser.c"
    break;

  case 72: /* compound: OPEN_BRACE unlabeled_statements CLOSE_BRACE  */
#line 159 "parser.y"
                                                                                                { genNode(C_COMPOUND, 1); }
#line 1689 "parser.c"
    break;

  case 73: /* compound: OPEN_BRACE empty CLOSE_BRACE  */
#line 160 "parser.y"
                                                                                                                        { genNode(C_COMPOUND, 1); }
#line 1695 "parser.c"
    break;

  case 74: /* unlabeled_statements: unlabeled_statement  */
#line 162 "parser.y"
                                                                                                                { genNode(C_UNLABELED_STATEMENTS, 1); }
#line 1701 "parser.c"
    break;

  case 75: /* unlabeled_statements: unlabeled_statements unlabeled_statement  */
#line 163 "parser.y"
                                                                                                                { genNode(C_UNLABELED_STATEMENTS, 1); insertTopList(); }
#line 1707 "parser.c"
    break;

  case 76: /* empty_statement: SEMI_COLON  */
#line 165 "parser.y"
                                                                                                                                { /*?*/ genEmpty(); }
#line 1713 "parser.c"
    break;

  case 77: /* expression: simple_expression  */
#line 167 "parser.y"
                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1719 "parser.c"
    break;

  case 78: /* expression: binop_expression  */
#line 168 "parser.y"
                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1725 "parser.c"
    break;

  case 79: /* expression: unop_expression  */
#line 169 "parser.y"
                                                                                                                                        { genNode(C_EXPRESSION, 1); }
#line 1731 "parser.c"
    break;

  case 81: /* binop_expression: unop_expression relational_operator simple_expression  */
#line 172 "parser.y"
                                                                                { /*!*/ genNode(C_BINOP_EXPRESSION, 3); }
#line 1737 "parser.c"
    break;

  case 82: /* binop_expression: simple_expression relational_operator simple_expression  */
#line 173 "parser.y"
                                                                                                { /*!*/ genNode(C_BINOP_EXPRESSION, 3); }
#line 1743 "parser.c"
    break;

  case 83: /* simple_expression: term additive_term  */
#line 175 "parser.y"
                                                                                                                { genNode(C_SIMPLE_EXPRESSION, 2); }
#line 1749 "parser.c"
    break;

  case 84: /* simple_expression: term  */
#line 176 "parser.y"
                                                                                                                                                { genNode(C_SIMPLE_EXPRESSION, 1); }
#line 1755 "parser.c"
    break;

  case 85: /* unop_expression: unary_operator term additive_term  */
#line 178 "parser.y"
                                                                                                        { /*!*/ genNode(C_UNOP_EXPRESSION, 3); }
#line 1761 "parser.c"
    break;

  case 86: /* unop_expression: unary_operator term  */
#line 179 "parser.y"
                                                                                                                                { /*!*/ genNode(C_UNOP_EXPRESSION, 2); }
#line 1767 "parser.c"
    break;

  case 87: /* additive_term: additive_operator term  */
#line 181 "parser.y"
                                                                                                                { /*!*/ genNode(C_ADDITIVE_TERM, 2); }
#line 1773 "parser.c"
    break;

  case 88: /* additive_term: additive_term additive_operator term  */
#line 182 "parser.y"
                                                                                                                { /*!*/ genNode(C_ADDITIVE_TERM, 2); insertTopList(); }
#line 1779 "parser.c"
    break;

  case 90: /* relational_operator: LESS  */
#line 185 "parser.y"
                                                                                                                                                { genOpSymbol(C_LESS); }
#line 1785 "parser.c"
    break;

  case 94: /* relational_operator: GREATER  */
#line 189 "parser.y"
                                                                                                                                                { genOpSymbol(C_GREATER); }
#line 1791 "parser.c"
    break;

  case 95: /* additive_operator: PLUS  */
#line 191 "parser.y"
                                                                                                                                { genOpSymbol(C_PLUS); }
#line 1797 "parser.c"
    break;

  case 96: /* additive_operator: MINUS  */
#line 192 "parser.y"
                                                                                                                                                { genOpSymbol(C_MINUS); }
#line 1803 "parser.c"
    break;

  case 98: /* unary_operator: PLUS  */
#line 195 "parser.y"
                                                                                                                                { genOpSymbol(C_PLUS); }
#line 1809 "parser.c"
    break;

  case 99: /* unary_operator: MINUS  */
#line 196 "parser.y"
                                                                                                                                                { genOpSymbol(C_MINUS); }
#line 1815 "parser.c"
    break;

  case 101: /* term: factor multiplicative_factor  */
#line 199 "parser.y"
                                                                                                                        { genNode(C_TERM, 2); }
#line 1821 "parser.c"
    break;

  case 102: /* term: factor  */
#line 200 "parser.y"
                                                                                                                                                { genNode(C_TERM, 1); }
#line 1827 "parser.c"
    break;

  case 103: /* multiplicative_factor: multiplicative_operator factor  */
#line 202 "parser.y"
                                                                                                { /*!*/ genNode(C_MULTIPLICATIVE_FACTOR, 2); }
#line 1833 "parser.c"
    break;

  case 104: /* multiplicative_factor: multiplicative_factor multiplicative_operator factor  */
#line 203 "parser.y"
                                                                                                { /*!*/ genNode(C_MULTIPLICATIVE_FACTOR, 2); insertTopList(); }
#line 1839 "parser.c"
    break;

  case 105: /* multiplicative_operator: MULTIPLY  */
#line 205 "parser.y"
                                                                                                                        { genOpSymbol(C_MULTIPLY); }
#line 1845 "parser.c"
    break;

  case 108: /* factor: variable  */
#line 209 "parser.y"
                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1851 "parser.c"
    break;

  case 109: /* factor: integer  */
#line 210 "parser.y"
                                                                                                                                                { genNode(C_FACTOR, 1); }
#line 1857 "parser.c"
    break;

  case 110: /* factor: function_call  */
#line 211 "parser.y"
                                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1863 "parser.c"
    break;

  case 111: /* factor: OPEN_PAREN expression CLOSE_PAREN  */
#line 212 "parser.y"
                                                                                                                        { genNode(C_FACTOR, 1); }
#line 1869 "parser.c"
    break;

  case 112: /* function_call: identifier OPEN_PAREN expression_list CLOSE_PAREN  */
#line 214 "parser.y"
                                                                                        { genNode(C_FUNCTION_CALL, 2); }
#line 1875 "parser.c"
    break;

  case 113: /* identifier_list: identifier identifier_list_rest  */
#line 216 "parser.y"
                                                                                                        { genNode(C_IDENTIFIER_LIST, 2); }
#line 1881 "parser.c"
    break;

  case 114: /* identifier_list: identifier  */
#line 217 "parser.y"
                                                                                                                                        { genNode(C_IDENTIFIER_LIST, 1); }
#line 1887 "parser.c"
    break;

  case 115: /* identifier_list_rest: COMMA identifier  */
#line 219 "parser.y"
                                                                                                                { genNode(C_IDENTIFIER_LIST_REST, 1); }
#line 1893 "parser.c"
    break;

  case 116: /* identifier_list_rest: identifier_list_rest COMMA identifier  */
#line 220 "parser.y"
                                                                                                                { genNode(C_IDENTIFIER_LIST_REST, 1); insertTopList(); }
#line 1899 "parser.c"
    break;

  case 117: /* expression_list: expression expression_list_rest  */
#line 222 "parser.y"
                                                                                                        { genNode(C_EXPRESSION_LIST, 2); }
#line 1905 "parser.c"
    break;

  case 118: /* expression_list: expression  */
#line 223 "parser.y"
                                                                                                                                        { genNode(C_EXPRESSION_LIST, 1); }
#line 1911 "parser.c"
    break;

  case 119: /* expression_list_rest: COMMA expression  */
#line 225 "parser.y"
                                                                                                                { genNode(C_EXPRESSION_LIST_REST, 1); }
#line 1917 "parser.c"
    break;

  case 120: /* expression_list_rest: expression_list_rest COMMA expression  */
#line 226 "parser.y"
                                                                                                                { genNode(C_EXPRESSION_LIST_REST, 1); insertTopList(); }
#line 1923 "parser.c"
    break;

  case 121: /* identifier: IDENTIFIER  */
#line 228 "parser.y"
                                                                                                                                { genIdent((yyvsp[0].symbol)); }
#line 1929 "parser.c"
    break;

  case 122: /* integer: INTEGER  */
#line 230 "parser.y"
                                                                                                                                        { genInt((yyvsp[0].symbol)); }
#line 1935 "parser.c"
    break;

  case 123: /* empty: %empty  */
#line 232 "parser.y"
                                                                                                                                        { genEmpty(); }
#line 1941 "parser.c"
    break;


#line 1945 "parser.c"

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

#line 235 "parser.y"


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
	treeNode->symbol = symbol;
	if (numComps > 0)
		for(int i = numComps - 1; i >= 0; i--)
			treeNode->components[i] = pop();
	push(treeNode);
}

void genNode(Categ categ, int numComps)
{
	genNode3(categ, numComps, NULL);
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
	// Is this the correct way to do it?
	// Probably, will be different when generating code.
	genNode(categ, 0);
}
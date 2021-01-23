/* A Bison parser, made by GNU Bison 3.7.3.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
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
    EQUAL = 258,                   /* EQUAL  */
    DIFFERENT = 259,               /* DIFFERENT  */
    LESS = 260,                    /* LESS  */
    LESS_OR_EQUAL = 261,           /* LESS_OR_EQUAL  */
    GREATER = 262,                 /* GREATER  */
    GREATER_OR_EQUAL = 263,        /* GREATER_OR_EQUAL  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    OR = 266,                      /* OR  */
    MULTIPLY = 267,                /* MULTIPLY  */
    DIV = 268,                     /* DIV  */
    AND = 269,                     /* AND  */
    CLOSE_BRACE = 270,             /* CLOSE_BRACE  */
    CLOSE_BRACKET = 271,           /* CLOSE_BRACKET  */
    CLOSE_PAREN = 272,             /* CLOSE_PAREN  */
    COLON = 273,                   /* COLON  */
    COMMA = 274,                   /* COMMA  */
    ELSE = 275,                    /* ELSE  */
    END_OF_FILE = 276,             /* END_OF_FILE  */
    FUNCTIONS = 277,               /* FUNCTIONS  */
    GOTO = 278,                    /* GOTO  */
    IDENTIFIER = 279,              /* IDENTIFIER  */
    ASSIGN = 280,                  /* ASSIGN  */
    IF = 281,                      /* IF  */
    INTEGER = 282,                 /* INTEGER  */
    LABELS = 283,                  /* LABELS  */
    NOT = 284,                     /* NOT  */
    OPEN_BRACE = 285,              /* OPEN_BRACE  */
    OPEN_BRACKET = 286,            /* OPEN_BRACKET  */
    OPEN_PAREN = 287,              /* OPEN_PAREN  */
    RETURN = 288,                  /* RETURN  */
    SEMI_COLON = 289,              /* SEMI_COLON  */
    TYPES = 290,                   /* TYPES  */
    VAR = 291,                     /* VAR  */
    VARS = 292,                    /* VARS  */
    VOID = 293,                    /* VOID  */
    WHILE = 294,                   /* WHILE  */
    LEXICAL_ERROR = 295            /* LEXICAL_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "src/parser.y"

	char *symbol;

#line 108 "src/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

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
    BOOLEAN = 258,                 /* BOOLEAN  */
    EQUAL = 259,                   /* EQUAL  */
    DIFFERENT = 260,               /* DIFFERENT  */
    LESS = 261,                    /* LESS  */
    LESS_OR_EQUAL = 262,           /* LESS_OR_EQUAL  */
    GREATER = 263,                 /* GREATER  */
    GREATER_OR_EQUAL = 264,        /* GREATER_OR_EQUAL  */
    PLUS = 265,                    /* PLUS  */
    MINUS = 266,                   /* MINUS  */
    OR = 267,                      /* OR  */
    MULTIPLY = 268,                /* MULTIPLY  */
    DIV = 269,                     /* DIV  */
    AND = 270,                     /* AND  */
    CLOSE_BRACE = 271,             /* CLOSE_BRACE  */
    CLOSE_BRACKET = 272,           /* CLOSE_BRACKET  */
    CLOSE_PAREN = 273,             /* CLOSE_PAREN  */
    COLON = 274,                   /* COLON  */
    COMMA = 275,                   /* COMMA  */
    ELSE = 276,                    /* ELSE  */
    END_OF_FILE = 277,             /* END_OF_FILE  */
    FUNCTIONS = 278,               /* FUNCTIONS  */
    GOTO = 279,                    /* GOTO  */
    IDENTIFIER = 280,              /* IDENTIFIER  */
    ASSIGN = 281,                  /* ASSIGN  */
    IF = 282,                      /* IF  */
    INTEGER = 283,                 /* INTEGER  */
    LABELS = 284,                  /* LABELS  */
    NOT = 285,                     /* NOT  */
    OPEN_BRACE = 286,              /* OPEN_BRACE  */
    OPEN_BRACKET = 287,            /* OPEN_BRACKET  */
    OPEN_PAREN = 288,              /* OPEN_PAREN  */
    RETURN = 289,                  /* RETURN  */
    SEMI_COLON = 290,              /* SEMI_COLON  */
    TYPES = 291,                   /* TYPES  */
    VAR = 292,                     /* VAR  */
    VARS = 293,                    /* VARS  */
    VOID = 294,                    /* VOID  */
    WHILE = 295,                   /* WHILE  */
    LEXICAL_ERROR = 296            /* LEXICAL_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "src/parser.y"

	char *symbol;

#line 109 "src/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

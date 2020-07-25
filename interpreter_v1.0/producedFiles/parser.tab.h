/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 31 "parser.y" /* yacc.c:1915  */

  struct ast *a;
  double d;
  char *str;
  struct symbol *sym;		/* which symbol */
  struct symlist *sl;
  struct arrayElemList *al;
  int fn;			/* which function */

#line 101 "producedFiles/parser.tab.h" /* yacc.c:1915  */
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

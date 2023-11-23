
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     saut_ligne = 258,
     aff = 259,
     point = 260,
     po = 261,
     pf = 262,
     vg = 263,
     cst = 264,
     idf = 265,
     pvg = 266,
     mc_then = 267,
     mc_if = 268,
     mc_else = 269,
     mc_program = 270,
     mc_endif = 271,
     mc_character = 272,
     mc_real = 273,
     mc_enddo = 274,
     mc_read = 275,
     mc_write = 276,
     mc_integer = 277,
     mc_endr = 278,
     mc_routine = 279,
     mc_return = 280,
     mc_equivalence = 281,
     opcomp = 282,
     oplog = 283,
     mc_dowhile = 284,
     mc_end = 285,
     mc_call = 286,
     mc_dimension = 287,
     mc_logical = 288,
     cst_char = 289,
     opar_plus = 290,
     opar_moins = 291,
     opar_div = 292,
     opar_mult = 293,
     cst_bool = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



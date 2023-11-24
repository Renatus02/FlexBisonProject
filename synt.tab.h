
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
     cst_float = 291,
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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



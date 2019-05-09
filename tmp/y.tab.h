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

#ifndef YY_YY_TMP_Y_TAB_H_INCLUDED
# define YY_YY_TMP_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UNSIGNED = 258,
    SIGNED = 259,
    AUTO = 260,
    CHAR = 261,
    LONG = 262,
    INT = 263,
    DOUBLE = 264,
    FLOAT = 265,
    VOID = 266,
    SHORT = 267,
    LONG_LONG = 268,
    STRUCT = 269,
    UNION = 270,
    ENUM = 271,
    TYPEDEF = 272,
    EXTERN = 273,
    INLINE = 274,
    REGISTER = 275,
    RESTRICT = 276,
    STATIC = 277,
    CONST = 278,
    VOLATILE = 279,
    PTR = 280,
    SHIFT_RIGHT_ASSIGN = 281,
    SHIFT_LEFT_ASSIGN = 282,
    SUB_ASSIGN = 283,
    OR_ASSIGN = 284,
    DIV_ASSIGN = 285,
    ADD_ASSIGN = 286,
    MUL_ASSIGN = 287,
    MOD_ASSIGN = 288,
    AND_ASSIGN = 289,
    XOR_ASSIGN = 290,
    BREAK = 291,
    CONTINUE = 292,
    DEFAULT = 293,
    RETURN = 294,
    GOTO = 295,
    SIZEOF = 296,
    DO = 297,
    ELSE = 298,
    FOR = 299,
    IF = 300,
    WHILE = 301,
    SWITCH = 302,
    CASE = 303,
    ELSE_IF = 304,
    INTEGER = 305,
    FLOATING = 306,
    STRING = 307,
    NAME = 308,
    SHIFT_RIGHT = 309,
    SHIFT_LEFT = 310,
    INC = 311,
    DEC = 312,
    AND = 313,
    OR = 314,
    LE = 315,
    GE = 316,
    EQ = 317,
    NE = 318
  };
#endif
/* Tokens.  */
#define UNSIGNED 258
#define SIGNED 259
#define AUTO 260
#define CHAR 261
#define LONG 262
#define INT 263
#define DOUBLE 264
#define FLOAT 265
#define VOID 266
#define SHORT 267
#define LONG_LONG 268
#define STRUCT 269
#define UNION 270
#define ENUM 271
#define TYPEDEF 272
#define EXTERN 273
#define INLINE 274
#define REGISTER 275
#define RESTRICT 276
#define STATIC 277
#define CONST 278
#define VOLATILE 279
#define PTR 280
#define SHIFT_RIGHT_ASSIGN 281
#define SHIFT_LEFT_ASSIGN 282
#define SUB_ASSIGN 283
#define OR_ASSIGN 284
#define DIV_ASSIGN 285
#define ADD_ASSIGN 286
#define MUL_ASSIGN 287
#define MOD_ASSIGN 288
#define AND_ASSIGN 289
#define XOR_ASSIGN 290
#define BREAK 291
#define CONTINUE 292
#define DEFAULT 293
#define RETURN 294
#define GOTO 295
#define SIZEOF 296
#define DO 297
#define ELSE 298
#define FOR 299
#define IF 300
#define WHILE 301
#define SWITCH 302
#define CASE 303
#define ELSE_IF 304
#define INTEGER 305
#define FLOATING 306
#define STRING 307
#define NAME 308
#define SHIFT_RIGHT 309
#define SHIFT_LEFT 310
#define INC 311
#define DEC 312
#define AND 313
#define OR 314
#define LE 315
#define GE 316
#define EQ 317
#define NE 318

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TMP_Y_TAB_H_INCLUDED  */

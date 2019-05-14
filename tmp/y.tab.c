/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/test.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	FILE *yyin;
	extern int yylineno;
	int yylex(void);
	void yyerror(const char *str);
	int typedef volatile pluh;
	struct typedef_list
	{
		char *type_id;
		struct typedef_list *next;
	} *g_typedefs = NULL;

	struct typedef_list *addtype(char const *newtype)
	{
		struct typedef_list *tmp = (struct typedef_list*)malloc(sizeof(struct typedef_list));
		
		tmp->type_id = (char*)malloc(strlen(newtype)+1);
		strcpy(tmp->type_id, newtype);
		tmp->next = NULL;
		
		if (!g_typedefs)
		{
		  g_typedefs = tmp;
		}
		else
		{
		  tmp->next = g_typedefs;
		  g_typedefs = tmp;
		}
	}
	
	typedef enum _SpecificationType
	{
		SpecificationTypeStorageDenied,
		SpecificationTypeGlobal,
		SpecificationTypeArgument,
		SpecificationTypeNone,
		SpecificationTypePrev
	}SpecificationType;
	
	typedef enum _TypeBasic
	{
		TypeBasicInt,
		TypeBasicVoid,
		TypeBasicDouble,
		TypeBasicFloat,
		TypeBasicChar,
		TypeBasicCompound,
		TypeBasicNone
	}TypeBasic;
	
	typedef enum _TypeAdditional
	{
		TypeAdditionalLongLong,
		TypeAdditionalLong,
		TypeAdditionalShort,
		TypeAdditionalNone
	}TypeAdditional;
		
	typedef enum _TypeSign
	{
		TypeSignSigned,
		TypeSignUnsigned,
		TypeSignNone
	}TypeSign;
	
	typedef enum _TypeStorage
	{
		TypeStorageAuto,
		TypeStorageExtern,
		TypeStorageRegister,
		TypeStorageStatic,
		TypeStorageNone,
	}TypeStorage;
	
	struct _technical_variables
	{
		TypeBasic type_basic;
		TypeAdditional type_additional;
		TypeSign type_sign;
		TypeStorage type_storage;
		SpecificationType specification_type;
		SpecificationType prev_storage;
		unsigned int auto_cntr, extern_cntr, register_cntr, static_cntr;
	} technical_variables;
	
	void set_specification(SpecificationType specification_type)
	{
		//printf("	%d specification: %d %d %d\n", yylineno, technical_variables.prev_storage, technical_variables.specification_type, specification_type);
		if(specification_type == SpecificationTypePrev)
		{
			//SpecificationType tmp=technical_variables.prev_storage;
			//technical_variables.prev_storage = technical_variables.specification_type;
			technical_variables.specification_type = technical_variables.prev_storage;
			return;
		}
		technical_variables.prev_storage = technical_variables.specification_type;
		technical_variables.specification_type = specification_type;
	}
	
	void technical_variables_clean_all()
	{
		technical_variables.type_basic = TypeBasicNone;
		technical_variables.type_additional = TypeAdditionalNone;
		technical_variables.type_sign = TypeSignNone;
		technical_variables.type_storage = TypeStorageNone;
	}
	
	//#define DGB_PRINT printf("%s %d\n", __FUNCTION__, __LINE__);
	#define DGB_PRINT
	// сначала может быть объявлен доп тип, потом базовый. чекнуть
	void set_type_basic(TypeBasic new_type_basic)
	{
		if(technical_variables.type_basic != TypeBasicNone )
		{
			
			yyerror("More than one type specified");
			//YYACCEPT;
			return;
		}
		
		if(technical_variables.type_sign != TypeSignNone &&
			(new_type_basic != TypeBasicInt && new_type_basic != TypeBasicChar && new_type_basic != TypeBasicNone)
			)
		{
			
			yyerror("More than one type specified");
			//YYACCEPT;
			return;
		}
		
		switch(technical_variables.type_additional)
		{
			case TypeAdditionalNone:
				technical_variables.type_basic = new_type_basic;
				return;
			break;
			
			case TypeAdditionalShort:
				if(technical_variables.type_basic != TypeBasicInt && 
					technical_variables.type_basic != TypeBasicFloat &&
					technical_variables.type_basic != TypeBasicDouble &&
					technical_variables.type_basic != TypeBasicNone
				)
				{
					
					yyerror("More than one type specified");
					//YYACCEPT;
					return;
				}
				
				technical_variables.type_basic = new_type_basic;
				return;
			break;
			
			case TypeAdditionalLongLong:
				if(technical_variables.type_basic != TypeBasicInt && 
					technical_variables.type_basic != TypeBasicDouble &&
					technical_variables.type_basic != TypeBasicNone 
				)
				{
					
					yyerror("More than one type specified");
					//YYACCEPT;
					return;
				}
				
				technical_variables.type_basic = new_type_basic;
				return;
			break;
			
			case TypeAdditionalLong:
				if(technical_variables.type_basic != TypeBasicInt && 
					technical_variables.type_basic != TypeBasicFloat &&
					technical_variables.type_basic != TypeBasicDouble &&
					technical_variables.type_basic != TypeBasicNone
				)
				{
					
					yyerror("More than one type specified");
					//YYACCEPT;
					return;
				}
				
				technical_variables.type_basic = new_type_basic;
				return;
			break;
		}
			
	}
	
	void set_type_additional(TypeAdditional new_type_additional)
	{
		if(technical_variables.type_additional != TypeAdditionalNone)
		{
			
			yyerror("Incorrect combination of specificators");
			//YYACCEPT;
			return;
		}
		else if(technical_variables.type_basic != TypeBasicInt && 
				technical_variables.type_basic != TypeBasicFloat &&
				technical_variables.type_basic != TypeBasicDouble &&
				technical_variables.type_basic != TypeBasicNone)
		{
			
			printf("%d\n", TypeBasicNone);
			yyerror("Incorrect combination of specificators");
			//YYACCEPT;
			return;
		}
		
		switch(technical_variables.type_basic)
		{
			case TypeBasicInt:
				technical_variables.type_additional = new_type_additional;
				return;
			break;
			
			case TypeBasicFloat:
				if(new_type_additional != TypeAdditionalLong)
				{
					
					yyerror("Incorrect combination of specificators");
					//YYACCEPT;
					return;
				}
				technical_variables.type_additional = new_type_additional;
				return;
			break;
			
			case TypeBasicDouble:
				if(new_type_additional != TypeAdditionalLong &&
					new_type_additional != TypeAdditionalLongLong
					)
				{
					
					yyerror("Incorrect combination of specificators");
					//YYACCEPT;
					return;
				}
				technical_variables.type_additional = new_type_additional;
				return;
			break;
			
			case TypeBasicNone:
				technical_variables.type_additional = new_type_additional;
				return;
			break;
		}
		
	}
	
	void set_type_sign(TypeSign new_type_sign)
	{
		if(technical_variables.type_sign == new_type_sign)
		{
			return;
		}
		else if(technical_variables.type_sign != TypeSignNone)
		{
			
			yyerror("Incorrect combination of specificators");
			//YYACCEPT;
			return;
		}
		
		if (technical_variables.type_basic != TypeBasicInt && 
			technical_variables.type_basic != TypeBasicChar &&
			technical_variables.type_basic != TypeBasicNone)
		{
		
			yyerror("Incorrect combination of specificators");
			//YYACCEPT;
			return;
		}
		else
		{
			technical_variables.type_sign = new_type_sign;
			return;
		}
	}
	
	void set_type_storage(TypeStorage new_type_storage)
	{
		SpecificationType specification_type = technical_variables.specification_type;
		
		if(technical_variables.type_storage != TypeStorageNone)
		{
			
			yyerror("More than one storage class specified");
			//YYACCEPT;
			return;
		}
		switch(specification_type)
		{
			case SpecificationTypeArgument:
				if(new_type_storage != TypeStorageRegister)
				{
					
					yyerror("Incorrect storage class specified");
					//YYACCEPT;
					return;
				}
				technical_variables.type_storage = new_type_storage;
				return;
			break;
			
			case SpecificationTypeGlobal:
				if(new_type_storage != TypeStorageStatic &&
					new_type_storage != TypeStorageExtern)
				{
					
					yyerror("Incorrect storage class specified");
					//YYACCEPT;
					return;
				}
				technical_variables.type_storage = new_type_storage;
				return;
			break;
			
			case SpecificationTypeStorageDenied:
				
				yyerror("Storage class denied in this construction");
				//YYACCEPT;
				return;
			break;
			
			case SpecificationTypeNone:
				technical_variables.type_storage = new_type_storage;
				return;
			break;
		}
	}
	

#line 407 "tmp/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    STATIC = 276,
    CONST = 277,
    VOLATILE = 278,
    PTR = 279,
    STARS = 280,
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
    INTEGER = 304,
    FLOATING = 305,
    STRING = 306,
    NAME = 307,
    SHIFT_RIGHT = 308,
    SHIFT_LEFT = 309,
    INC = 310,
    DEC = 311,
    AND = 312,
    OR = 313,
    LE = 314,
    GE = 315,
    EQ = 316,
    NE = 317,
    CUSTOM_TYPE = 318
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
#define STATIC 276
#define CONST 277
#define VOLATILE 278
#define PTR 279
#define STARS 280
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
#define INTEGER 304
#define FLOATING 305
#define STRING 306
#define NAME 307
#define SHIFT_RIGHT 308
#define SHIFT_LEFT 309
#define INC 310
#define DEC 311
#define AND 312
#define OR 313
#define LE 314
#define GE 315
#define EQ 316
#define NE 317
#define CUSTOM_TYPE 318

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 364 "src/test.y" /* yacc.c:355  */

	char *str;
	int val;

#line 578 "tmp/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TMP_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 595 "tmp/y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   957

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  232
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  362

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,     2,     2,     2,    87,    67,     2,
      81,    82,    72,    70,    64,    71,    84,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    74,
      69,    75,    68,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,    65,    79,    85,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   375,   375,   376,   377,   378,   379,   380,   386,   387,
     392,   392,   396,   407,   408,   409,   414,   415,   416,   417,
     421,   422,   423,   424,   425,   426,   430,   431,   435,   436,
     437,   441,   442,   443,   448,   449,   453,   454,   459,   464,
     465,   466,   470,   471,   476,   477,   478,   479,   483,   487,
     488,   489,   490,   495,   496,   497,   498,   503,   504,   505,
     510,   511,   515,   516,   520,   521,   522,   523,   524,   528,
     529,   530,   534,   535,   540,   541,   547,   548,   549,   555,
     556,   556,   556,   557,   557,   557,   561,   562,   562,   567,
     567,   571,   574,   576,   577,   578,   579,   585,   586,   586,
     586,   587,   587,   587,   591,   596,   597,   602,   603,   607,
     608,   609,   615,   616,   617,   618,   619,   620,   625,   626,
     627,   627,   628,   628,   633,   634,   635,   640,   641,   646,
     647,   648,   653,   654,   655,   656,   657,   662,   663,   664,
     665,   670,   671,   677,   677,   677,   678,   678,   678,   682,
     687,   688,   694,   695,   700,   701,   706,   707,   712,   713,
     718,   719,   724,   725,   726,   731,   732,   737,   738,   738,
     738,   738,   738,   743,   744,   748,   749,   755,   756,   757,
     758,   759,   760,   760,   760,   765,   766,   767,   768,   769,
     770,   771,   772,   778,   778,   779,   779,   779,   782,   783,
     789,   790,   791,   792,   793,   794,   795,   796,   797,   798,
     799,   803,   804,   805,   806,   807,   808,   812,   813,   814,
     815,   816,   820,   821,   822,   823,   824,   825,   829,   830,
     831,   832,   833
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNSIGNED", "SIGNED", "AUTO", "CHAR",
  "LONG", "INT", "DOUBLE", "FLOAT", "VOID", "SHORT", "LONG_LONG", "STRUCT",
  "UNION", "ENUM", "TYPEDEF", "EXTERN", "INLINE", "REGISTER", "STATIC",
  "CONST", "VOLATILE", "PTR", "STARS", "SHIFT_RIGHT_ASSIGN",
  "SHIFT_LEFT_ASSIGN", "SUB_ASSIGN", "OR_ASSIGN", "DIV_ASSIGN",
  "ADD_ASSIGN", "MUL_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "BREAK", "CONTINUE", "DEFAULT", "RETURN", "GOTO", "SIZEOF", "DO", "ELSE",
  "FOR", "IF", "WHILE", "SWITCH", "CASE", "INTEGER", "FLOATING", "STRING",
  "NAME", "SHIFT_RIGHT", "SHIFT_LEFT", "INC", "DEC", "AND", "OR", "LE",
  "GE", "EQ", "NE", "CUSTOM_TYPE", "','", "'|'", "'^'", "'&'", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "';'", "'='", "'['", "']'", "'{'",
  "'}'", "':'", "'('", "')'", "'?'", "'.'", "'~'", "'!'", "'%'", "$accept",
  "program", "definition", "typedef", "$@1", "typedef_oldtype",
  "typedef_newtypes", "typedef_newtype", "predefinitor", "definitors",
  "definitor", "definitor_identificator", "pointer_id", "array_or_id",
  "array_id", "dimension", "int_dimension", "basic_unit",
  "initializer_list", "initializers", "storage_class_specifier",
  "type_specifier", "simple_type_specifier", "arithmetic_type",
  "basic_type", "additional_type_specifier", "signification",
  "type_qualifier", "compound_type_specifier", "structure", "$@2", "$@3",
  "$@4", "$@5", "structure_fields", "$@6", "field", "$@7", "field_type",
  "field_ids", "union", "$@8", "$@9", "$@10", "$@11", "union_fields",
  "enumeration", "enum_fields", "enum_identifier", "statement",
  "statement_list", "$@12", "$@13", "label", "expression_statement",
  "conditional_statement", "jump_statement", "loop_statement",
  "expression_for_loop", "function", "$@14", "$@15", "$@16", "$@17",
  "prefuction", "func_id", "expression", "assignment_expression",
  "conditional_expression", "logical_expression", "compare_expression",
  "shift_expression", "simple_expression", "cast", "$@18", "$@19", "$@20",
  "$@21", "caster", "primary_expression", "prefix_expression", "$@22",
  "$@23", "postfix_expression", "arguments", "$@24", "$@25", "$@26",
  "arguments_without_type", "assignment_operator", "unary_operator",
  "calc_operator", "compare_operator", "logical_operator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    44,   124,    94,    38,    62,    60,
      43,    45,    42,    47,    59,    61,    91,    93,   123,   125,
      58,    40,    41,    63,    46,   126,    33,    37
};
# endif

#define YYPACT_NINF -243

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-243)))

#define YYTABLE_NINF -152

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     714,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,   -12,    12,    66,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,   693,  -243,  -243,   505,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,   -10,
      24,    84,   111,   113,   137,   737,  -243,  -243,  -243,  -243,
    -243,     4,  -243,  -243,    60,  -243,   141,     5,  -243,  -243,
    -243,  -243,  -243,  -243,   138,   147,  -243,   149,  -243,   165,
      14,   737,   -24,  -243,     6,    43,  -243,   606,    88,  -243,
     167,   737,   150,  -243,   737,  -243,   737,   148,   -41,   170,
      82,    71,  -243,     7,   158,   153,   188,   162,  -243,    20,
     823,  -243,  -243,  -243,  -243,   847,   847,  -243,  -243,  -243,
    -243,   133,   871,  -243,  -243,  -243,  -243,   177,  -243,  -243,
     135,   205,   152,   125,  -243,  -243,   146,    22,   871,  -243,
     737,   -49,  -243,   737,   737,   164,  -243,  -243,   737,   171,
     173,   204,  -243,   170,  -243,  -243,     7,  -243,  -243,   202,
    -243,   206,     6,   182,   871,  -243,   871,  -243,  -243,  -243,
    -243,    11,   -38,  -243,   871,  -243,  -243,  -243,  -243,  -243,
     871,   871,  -243,  -243,  -243,  -243,  -243,  -243,   871,   871,
     871,  -243,  -243,  -243,  -243,  -243,   871,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,   871,   208,
    -243,  -243,   871,   772,   209,  -243,  -243,    43,  -243,  -243,
     190,   191,  -243,   737,    64,   192,  -243,  -243,  -243,    14,
    -243,  -243,   737,   133,  -243,  -243,   737,  -243,   -44,   205,
     152,   125,   125,  -243,  -243,  -243,    -3,  -243,  -243,   -13,
    -243,  -243,   737,   194,   314,  -243,  -243,   110,   220,  -243,
      73,  -243,  -243,   623,  -243,  -243,  -243,  -243,   871,  -243,
     871,  -243,   737,   314,   201,   210,   196,   796,   226,   734,
     199,   207,   211,   213,   871,   203,  -243,   314,  -243,   528,
    -243,   145,  -243,  -243,  -243,  -243,  -243,   130,   233,  -243,
      64,  -243,  -243,   214,   215,  -243,  -243,    43,   422,  -243,
    -243,   734,  -243,   139,   212,   239,   398,   871,   871,   871,
     218,   734,   484,  -243,   734,   737,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,   219,   600,   216,   177,
      19,    45,    50,   734,  -243,  -243,  -243,  -243,   871,   871,
    -243,   398,   734,   734,   734,  -243,  -243,    61,    57,   244,
    -243,  -243,   217,   871,   734,   734,  -243,   106,  -243,  -243,
     734,  -243
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    73,    72,    56,    67,    70,    64,    66,    65,    60,
      71,    69,    80,    98,     0,    10,    53,    55,    54,    74,
      75,    59,     0,     2,     6,     0,    20,    22,    57,    61,
      62,    63,    68,    21,    58,    76,    77,    78,     4,     0,
      79,     0,    97,     0,   105,     0,     1,     3,     7,     5,
      35,    37,    34,     8,     0,    26,    28,     0,    31,    36,
      24,    23,    25,   149,   143,     0,    81,     0,    99,     0,
       0,    12,     0,    38,    41,     0,     9,     0,    37,    33,
       0,     0,     0,    84,     0,   102,     0,   109,     0,   107,
      16,     0,    13,     0,     0,    39,     0,    37,    27,     0,
       0,    45,    46,    47,    44,     0,     0,   211,   213,   214,
     212,     0,   168,   215,   216,   175,    30,    29,   152,   154,
     156,   158,   160,   162,   165,   185,   167,   177,     0,    32,
     193,     0,   147,     0,    91,    87,    86,    89,     0,    87,
       0,     0,   106,   108,   111,    18,     0,    11,    19,     0,
      42,     0,    40,     0,   182,   181,     0,   178,   179,    49,
      52,     0,     0,   169,     0,   231,   232,   229,   230,   228,
       0,     0,   224,   225,   226,   227,   223,   222,     0,     0,
       0,   217,   218,   219,   220,   221,     0,   207,   206,   205,
     210,   202,   204,   201,   203,   208,   209,   200,     0,     0,
     191,   192,     0,     0,     0,   180,   167,     0,   195,   144,
       0,    87,    82,     0,    92,     0,   100,   110,    14,     0,
      17,    43,     0,     0,    48,   176,     0,   153,     0,   159,
     161,   164,   163,   166,   155,   190,     0,   187,   198,     0,
     189,   194,     0,     0,     0,    85,    88,    37,     0,    93,
       0,   103,    15,   173,   183,    50,    51,   170,     0,   186,
       0,   188,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,   127,     0,   119,     0,
     118,   120,   112,   113,   114,   116,   115,     0,     0,    95,
      92,    90,   174,     0,     0,   157,   199,     0,   120,   134,
     133,     0,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,   148,     0,     0,   128,    94,    96,   184,
     171,   197,   145,   126,   136,   132,     0,     0,     0,   142,
       0,     0,     0,     0,   124,   117,   121,   123,     0,     0,
     141,     0,     0,     0,     0,   125,   172,     0,     0,   129,
     137,   131,     0,     0,     0,     0,   138,     0,   139,   130,
       0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,     1,   267,  -243,  -243,  -243,   -86,     0,  -243,
     -69,  -202,   -20,   -43,  -243,  -243,   200,  -102,  -101,  -243,
     -22,   -17,  -243,  -243,  -243,  -243,  -243,   -23,  -243,  -243,
    -243,  -243,  -243,  -243,   -68,  -243,    86,  -243,  -243,    13,
    -243,  -243,  -243,  -243,  -243,   163,  -243,  -243,   221,  -214,
    -242,  -243,  -243,  -243,  -243,  -243,  -243,  -243,   -39,   285,
    -243,  -243,  -243,  -243,  -243,  -243,   -60,  -140,  -227,  -243,
     140,   134,    30,  -124,  -243,  -243,  -243,  -243,    87,  -243,
     -87,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,   278,    24,    45,    70,    91,    92,   134,    54,
      55,    56,    99,    58,    59,    73,    74,   115,   116,   161,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      41,    84,    65,   133,   139,   213,   136,   214,   137,   250,
      36,    43,    86,    67,   138,   140,    37,    88,    89,   280,
     281,   314,   315,   282,   283,   284,   285,   286,   328,    38,
      81,   243,    82,   210,    39,    63,   287,   118,   119,   120,
     121,   122,   123,   124,   163,   226,   294,   338,   254,   125,
     126,   222,   293,   127,   131,   207,   242,   297,   239,   198,
     128,   186,   178,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    23,    62,    60,   205,    57,    98,   148,    61,   159,
     160,    87,   249,   155,    79,   208,   135,   117,   157,   158,
     164,   298,    25,    47,   227,    94,   164,    19,    20,    19,
      20,   295,    50,   209,    80,   312,   258,   129,   142,    50,
      40,   206,    19,    20,   225,    71,   199,   310,    62,    60,
      93,   260,   162,    95,    61,   305,    79,    78,   234,    90,
     218,   164,   233,   238,    42,   211,    90,   145,    50,   261,
     149,    64,    97,    93,   259,   223,    80,   200,   201,    52,
      72,   130,    96,   164,   206,  -150,    52,   323,   249,    50,
     224,   206,   206,   206,   162,    97,   162,   334,   202,   206,
     336,   342,   -83,   203,    19,    20,   204,    62,    60,   164,
     228,    62,    60,    61,   164,    52,   247,    61,    44,   345,
     296,   255,   256,   219,    75,   164,    93,   343,   349,   350,
     351,   353,   344,   252,    76,   146,    52,   290,   241,   354,
     358,   359,   236,   352,   248,   147,   361,   291,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,    66,  -122,    72,  -122,  -122,  -122,  -122,  -151,
     164,   206,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   101,   102,   103,   104,    72,   206,   360,  -101,
     288,    68,   165,   166,   164,   181,   182,   183,   184,    93,
     167,   168,   169,   164,   316,   179,   180,   303,  -122,   231,
     232,   111,   185,   324,   346,    69,    77,    87,   170,    97,
    -146,   197,   253,   141,   313,    83,   253,    85,   321,   151,
      62,    60,   132,   292,   144,   150,    61,   153,    72,    62,
      60,   164,   262,   212,   279,    61,   329,   330,   331,   332,
    -104,   206,   216,   217,   220,    94,    62,    60,   340,   221,
     235,   240,    61,   279,   172,   173,   174,   175,   244,   289,
     245,   251,   263,   176,   177,   299,   301,   279,   304,   347,
     306,   329,   317,   311,   300,   326,   325,   355,   307,    48,
     341,   356,   308,   357,   309,   152,   319,   320,   333,   246,
     339,   215,   348,   318,    62,    60,   327,    49,     0,   143,
      61,   229,   230,   257,     0,   279,   337,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,    16,     0,    17,    18,    19,    20,     0,     0,
       0,   327,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,   267,   268,   100,   269,     0,   270,   271,
     272,   273,   274,   101,   102,   103,   275,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,   107,     0,     0,   108,   109,   110,     0,   276,     0,
       0,     0,   277,     0,     0,   112,     0,     0,     0,   113,
     114,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,    16,     0,    17,    18,
      19,    20,     0,     0,     0,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   100,
    -122,     0,  -122,  -122,  -122,  -122,     0,   101,   102,   103,
     104,     0,     0,   105,   106,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,   107,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,   113,   114,  -122,     0,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,   322,  -122,     0,  -122,  -122,  -122,  -122,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    16,     0,    17,    18,    19,    20,     0,
      50,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,    16,  -122,    17,    18,
      19,    20,     0,    50,     0,     0,     0,    51,     0,     0,
       0,     0,     0,   335,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,    53,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,    53,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,    16,     0,
      17,    18,    19,    20,     0,    50,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,    16,     0,    17,    18,    19,    20,   100,    50,     0,
       0,     0,    97,     0,     0,   101,   102,   103,   104,     0,
       0,   105,   106,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    52,   107,     0,     0,   108,   109,   110,     0,
       0,     0,     0,     0,   111,     0,    21,   112,     0,     0,
       0,   113,   114,    46,     0,    52,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,    17,    18,    19,    20,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    18,    19,    20,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,    16,    21,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,   267,   268,   100,   269,    21,   270,   271,
     272,   273,   274,   101,   102,   103,   275,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,   107,     0,     0,   108,   109,   110,     0,   276,     0,
       0,     0,   277,   100,     0,   112,     0,     0,     0,   113,
     114,   101,   102,   103,   104,     0,     0,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,   100,     0,   107,
       0,     0,   108,   109,   110,   101,   102,   103,   104,     0,
       0,   105,   106,   112,   237,     0,     0,   113,   114,     0,
       0,     0,     0,   107,   100,     0,   108,   109,   110,     0,
     302,     0,   101,   102,   103,   104,     0,   112,   105,   106,
       0,   113,   114,     0,     0,     0,     0,     0,   100,     0,
     107,     0,     0,   108,   109,   110,   101,   102,   103,   104,
       0,     0,   105,   106,   154,     0,     0,     0,   113,   114,
       0,     0,   100,     0,   107,     0,     0,   108,   109,   110,
     101,   102,   103,   104,     0,     0,   105,   106,   156,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   107,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,   113,   114
};

static const yytype_int16 yycheck[] =
{
       0,     0,    25,    25,   128,    25,    75,    93,    25,   111,
     111,    52,   214,   100,    57,    64,    84,    77,   105,   106,
      64,   263,    22,    22,   164,    49,    64,    22,    23,    22,
      23,   258,    25,    82,    57,   277,    80,    80,    79,    25,
      52,   128,    22,    23,    82,    45,    24,   274,    71,    71,
      70,    64,   112,    77,    71,   269,    99,    52,   198,    52,
     146,    64,   186,   203,    52,   133,    52,    90,    25,    82,
      93,    81,    52,    93,    77,    64,    99,    55,    56,    72,
      76,    81,    76,    64,   171,    81,    72,   301,   290,    25,
      79,   178,   179,   180,   154,    52,   156,   311,    76,   186,
     314,    82,    78,    81,    22,    23,    84,   130,   130,    64,
     170,   134,   134,   130,    64,    72,    52,   134,    52,   333,
     260,   223,   223,   146,    64,    64,   146,    82,   342,   343,
     344,    74,    82,   219,    74,    64,    72,    64,   207,    82,
     354,   355,   202,    82,    80,    74,   360,    74,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    78,    18,    76,    20,    21,    22,    23,    81,
      64,   258,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    49,    50,    51,    52,    76,   274,    82,    78,
      80,    78,    57,    58,    64,    70,    71,    72,    73,   219,
      65,    66,    67,    64,    74,    53,    54,   267,    63,   179,
     180,    78,    87,    74,   338,    78,    75,    52,    83,    52,
      82,    75,   222,    75,    79,    78,   226,    78,   297,    76,
     253,   253,    82,   253,    64,    77,   253,    49,    76,   262,
     262,    64,   242,    79,   244,   262,   306,   307,   308,   309,
      79,   338,    79,    49,    52,    49,   279,   279,   327,    77,
      52,    52,   279,   263,    59,    60,    61,    62,    78,    49,
      79,    79,    78,    68,    69,    74,    80,   277,    52,   339,
      81,   341,    49,    80,    74,    46,    74,    43,    81,    22,
      74,    74,    81,   353,    81,    95,    82,    82,    80,   213,
      81,   138,   341,   290,   327,   327,   306,    22,    -1,    88,
     327,   171,   178,   226,    -1,   315,   315,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    67,    -1,    -1,    70,    71,    72,    -1,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    41,
      18,    -1,    20,    21,    22,    23,    -1,    49,    50,    51,
      52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    67,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    86,    63,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    79,    18,    -1,    20,    21,    22,    23,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    -1,    20,    21,    22,    23,    -1,
      25,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    63,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      20,    21,    22,    23,    -1,    25,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    22,    23,    41,    25,    -1,
      -1,    -1,    52,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    55,    56,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    67,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    63,    81,    -1,    -1,
      -1,    85,    86,     0,    -1,    72,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    63,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    63,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    67,    -1,    -1,    70,    71,    72,    -1,    74,    -1,
      -1,    -1,    78,    41,    -1,    81,    -1,    -1,    -1,    85,
      86,    49,    50,    51,    52,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    67,
      -1,    -1,    70,    71,    72,    49,    50,    51,    52,    -1,
      -1,    55,    56,    81,    82,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    67,    41,    -1,    70,    71,    72,    -1,
      74,    -1,    49,    50,    51,    52,    -1,    81,    55,    56,
      -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      67,    -1,    -1,    70,    71,    72,    49,    50,    51,    52,
      -1,    -1,    55,    56,    81,    -1,    -1,    -1,    85,    86,
      -1,    -1,    41,    -1,    67,    -1,    -1,    70,    71,    72,
      49,    50,    51,    52,    -1,    -1,    55,    56,    81,    -1,
      -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    20,    21,    22,
      23,    63,    89,    90,    91,    96,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   128,   134,   147,   152,
      52,   118,    52,   129,    52,    92,     0,    90,    91,   147,
      25,    52,    72,    74,    97,    98,    99,   100,   101,   102,
     108,   109,   115,   153,    81,   120,    78,   131,    78,    78,
      93,    96,    76,   103,   104,    64,    74,    75,    52,   101,
     115,   148,   150,    78,   119,    78,   130,    52,   135,   136,
      52,    94,    95,   100,    49,    77,    76,    52,    98,   100,
      41,    49,    50,    51,    52,    55,    56,    67,    70,    71,
      72,    78,    81,    85,    86,   105,   106,   154,   155,   156,
     157,   158,   159,   160,   161,   167,   168,   171,   178,   101,
      96,   172,    82,   121,    96,   122,   124,   126,   132,   122,
     133,    75,    79,   136,    64,   115,    64,    74,    95,   115,
      77,    76,   104,    49,    81,   168,    81,   168,   168,   105,
     106,   107,   154,   162,    64,    57,    58,    65,    66,    67,
      83,   181,    59,    60,    61,    62,    68,    69,   180,    53,
      54,    70,    71,    72,    73,    87,   179,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    75,   177,    24,
      55,    56,    76,    81,    84,   161,   168,   173,    64,    82,
     151,   122,    79,   123,   125,   133,    79,    49,    95,   115,
      52,    77,   169,    64,    79,    82,   163,   155,   154,   158,
     159,   160,   160,   161,   155,    52,   154,    82,   155,   176,
      52,    98,   174,   149,    78,    79,   124,    52,    80,    99,
     127,    79,    95,    96,   166,   105,   106,   166,    80,    77,
      64,    82,    96,    78,    36,    37,    38,    39,    40,    42,
      44,    45,    46,    47,    48,    52,    74,    78,    90,    96,
     137,   138,   141,   142,   143,   144,   145,   154,    80,    49,
      64,    74,   100,   170,   164,   156,   155,   175,   138,    74,
      74,    80,    74,   154,    52,   137,    81,    81,    81,    81,
     156,    80,   138,    79,   139,   140,    74,    49,   127,    82,
      82,    98,    79,   137,    74,    74,    46,    96,   146,   154,
     154,   154,   154,    80,   137,    79,   137,    90,   165,    81,
      98,    74,    82,    82,    82,   137,   161,   154,   146,   137,
     137,   137,    82,    74,    82,    43,    74,   154,   137,   137,
      82,   137
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    89,    89,    90,    90,
      92,    91,    93,    94,    94,    94,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   101,   101,   102,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   107,
     107,   107,   107,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   117,
     118,   119,   117,   120,   121,   117,   122,   123,   122,   125,
     124,   126,   127,   127,   127,   127,   127,   128,   129,   130,
     128,   131,   132,   128,   133,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   138,   138,
     139,   138,   140,   138,   141,   141,   141,   142,   142,   143,
     143,   143,   144,   144,   144,   144,   144,   145,   145,   145,
     145,   146,   146,   148,   149,   147,   150,   151,   147,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     158,   158,   159,   159,   159,   160,   160,   161,   162,   163,
     164,   165,   161,   166,   166,   167,   167,   168,   168,   168,
     168,   168,   169,   170,   168,   171,   171,   171,   171,   171,
     171,   171,   171,   173,   172,   174,   175,   172,   176,   176,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   178,   178,   178,   178,   178,   178,   179,   179,   179,
     179,   179,   180,   180,   180,   180,   180,   180,   181,   181,
     181,   181,   181
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     2,     3,
       0,     5,     1,     1,     3,     4,     1,     3,     2,     2,
       1,     1,     1,     2,     2,     2,     1,     3,     1,     3,
       3,     1,     3,     2,     1,     1,     1,     1,     2,     2,
       3,     1,     3,     4,     1,     1,     1,     1,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     0,     6,     0,     0,     7,     1,     0,     3,     0,
       4,     1,     0,     1,     3,     2,     3,     2,     0,     0,
       6,     0,     0,     7,     1,     2,     5,     1,     2,     1,
       3,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       0,     3,     0,     3,     3,     4,     3,     1,     2,     5,
       7,     5,     3,     2,     2,     2,     3,     5,     7,     7,
       9,     2,     1,     0,     0,     9,     0,     0,     8,     2,
       1,     2,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     1,     0,     0,
       0,     0,     8,     1,     2,     1,     3,     1,     2,     2,
       2,     2,     0,     0,     6,     1,     4,     3,     4,     3,
       3,     2,     2,     0,     3,     0,     0,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 375 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2090 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 376 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2096 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 379 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2102 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 380 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2108 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 392 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeStorageDenied);}
#line 2114 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 392 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2120 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 407 "src/test.y" /* yacc.c:1646  */
    {addtype((yyvsp[0].str)); /*printf("%s\n",$1);*/}
#line 2126 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 408 "src/test.y" /* yacc.c:1646  */
    {addtype((yyvsp[0].str)); /*printf("%s\n",$3);*/}
#line 2132 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 409 "src/test.y" /* yacc.c:1646  */
    {addtype((yyvsp[0].str)); /*printf("%s\n",$4);*/}
#line 2138 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 414 "src/test.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2144 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 415 "src/test.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2150 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 416 "src/test.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[-1].str);}
#line 2156 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 417 "src/test.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2162 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 495 "src/test.y" /* yacc.c:1646  */
    {set_type_storage(TypeStorageExtern);}
#line 2168 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 496 "src/test.y" /* yacc.c:1646  */
    {set_type_storage(TypeStorageStatic);}
#line 2174 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 497 "src/test.y" /* yacc.c:1646  */
    {set_type_storage(TypeStorageRegister);}
#line 2180 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 498 "src/test.y" /* yacc.c:1646  */
    {set_type_storage(TypeStorageAuto);}
#line 2186 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 505 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicCompound); }
#line 2192 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 510 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicVoid);}
#line 2198 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 520 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicInt);}
#line 2204 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 521 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicFloat);}
#line 2210 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 522 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicDouble);}
#line 2216 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 523 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicChar);}
#line 2222 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 528 "src/test.y" /* yacc.c:1646  */
    {set_type_additional(TypeAdditionalLongLong);}
#line 2228 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 529 "src/test.y" /* yacc.c:1646  */
    {set_type_additional(TypeAdditionalLong);}
#line 2234 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 530 "src/test.y" /* yacc.c:1646  */
    {set_type_additional(TypeAdditionalShort);}
#line 2240 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 534 "src/test.y" /* yacc.c:1646  */
    {set_type_sign(TypeSignSigned);}
#line 2246 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 535 "src/test.y" /* yacc.c:1646  */
    {set_type_sign(TypeSignSigned);}
#line 2252 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 547 "src/test.y" /* yacc.c:1646  */
    { set_type_basic(TypeBasicCompound);}
#line 2258 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 548 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicCompound);}
#line 2264 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 549 "src/test.y" /* yacc.c:1646  */
    {set_type_basic(TypeBasicCompound);}
#line 2270 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 556 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2276 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 556 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeStorageDenied);}
#line 2282 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 556 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2288 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 557 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2294 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 557 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeStorageDenied);}
#line 2300 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 557 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2306 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 561 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2312 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 562 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2318 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 562 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2324 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 567 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2330 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 586 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2336 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 586 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeStorageDenied);}
#line 2342 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 586 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2348 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 587 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2354 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 587 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeStorageDenied);}
#line 2360 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 587 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2366 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 625 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all(); set_specification(SpecificationTypeNone);}
#line 2372 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 626 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
#line 2378 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 627 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all(); set_specification(SpecificationTypeNone);}
#line 2384 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 627 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
#line 2390 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 628 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
#line 2396 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 628 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
#line 2402 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 677 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeArgument);}
#line 2408 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 677 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeNone);}
#line 2414 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 677 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2420 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 678 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeArgument);}
#line 2426 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 678 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeNone);}
#line 2432 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 678 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2438 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 682 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2444 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 738 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeStorageDenied);}
#line 2450 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 738 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2456 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 738 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2462 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 738 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2468 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 760 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeStorageDenied);}
#line 2474 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 760 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2480 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 760 "src/test.y" /* yacc.c:1646  */
    {set_specification(SpecificationTypeGlobal);}
#line 2486 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 778 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2492 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 779 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2498 "tmp/y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 779 "src/test.y" /* yacc.c:1646  */
    {technical_variables_clean_all();}
#line 2504 "tmp/y.tab.c" /* yacc.c:1646  */
    break;


#line 2508 "tmp/y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 835 "src/test.y" /* yacc.c:1906  */


void yyerror(const char *str)
{
	fprintf(stderr, "Error: %s at line %d\n", str, yylineno);
}
  
int main(int argc, char *argv[])
{
	technical_variables_clean_all();
	technical_variables.prev_storage = SpecificationTypeGlobal;
	set_specification(SpecificationTypeGlobal);
	if(argc < 2)
	{
		printf("Not enough arguments. Please specify filename. \n");
		return -1;
	}
	if((yyin = fopen(argv[1], "r")) == NULL)
	{
		printf("Cannot open file %s.\n", argv[1]);
		return -1;
	}
	yyparse();
	fclose(yyin);
	return 0;
}



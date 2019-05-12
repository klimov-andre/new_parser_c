%{
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

%}

%token UNSIGNED SIGNED AUTO CHAR LONG INT DOUBLE FLOAT VOID SHORT LONG_LONG
%token STRUCT UNION ENUM TYPEDEF
%token EXTERN INLINE REGISTER STATIC CONST VOLATILE
%token PTR STARS
%token SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN SUB_ASSIGN OR_ASSIGN DIV_ASSIGN ADD_ASSIGN MUL_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN
%token BREAK CONTINUE DEFAULT RETURN GOTO SIZEOF
%token DO ELSE FOR IF WHILE SWITCH CASE ELSE_IF
%token INTEGER FLOATING STRING NAME
%token SHIFT_RIGHT SHIFT_LEFT INC DEC AND OR LE GE EQ NE 
%token CUSTOM_TYPE

%left ','
%right  SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN SUB_ASSIGN OR_ASSIGN DIV_ASSIGN ADD_ASSIGN MUL_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN
%left OR AND '|' '^' '&' EQ NE GE LE '>' '<' SHIFT_RIGHT SHIFT_LEFT '+' '-'
%left '*' '/' INC DEC PTR

%type<str> NAME typedef_newtype

%start program
%define parse.error verbose

%union 
{
	char *str;
	int val;
};

%%

program:
	definition
	| program definition
/*	| function*/
/*	| program function*/
	| typedef
  | program typedef
	;

definition:
	predefinitor ';'
	| predefinitor definitors ';'
	;

// Должно работать еще и как 	typedef_oldtype TYPEDEF typedef_newtypes ';', но 32 конфликта - оч много, поэтому только так
typedef:
	TYPEDEF typedef_oldtype typedef_newtypes ';' 
	;

typedef_oldtype:
	specifier
	;
	
specifier:
	type_specifier
	| type_qualifier
	| specifier type_qualifier
	| specifier type_specifier
	;
	
typedef_newtypes:
	typedef_newtype {addtype($1); printf("%s\n",$1);}
	| typedef_newtypes ',' typedef_newtype {addtype($3); printf("%s\n",$3);}
	| typedef_newtypes ',' type_qualifier typedef_newtype {addtype($4); printf("%s\n",$4);}
	;
	

typedef_newtype:
	NAME {$$ = $1;}
	| pointer_id type_qualifier NAME {$$ = $3;}
	| NAME  type_qualifier {$$ = $1;}
	| pointer_id typedef_newtype {$$ = $2;}
	;

predefinitor:
	 global_storage_class_specifier
	| type_qualifier
	| type_specifier
	| predefinitor type_specifier
	| predefinitor global_storage_class_specifier
	| predefinitor type_qualifier
	;

definitors:
	definitor
	| definitors ',' definitor
	;

definitor:
	definitor_identificator
	| definitor_identificator '=' STRING
	| definitor_identificator '=' expression
	| definitor_identificator '=' initializer_list
	;

definitor_identificator:
	array_or_id
	| pointer_id type_qualifier array_or_id
	| pointer_id array_or_id
	| pointer_id global_storage_class_specifier
	;

/* Одна и более звездочек */
pointer_id:
	'*'
	| STARS
	;

array_or_id:
	array_id
	| NAME
	;

/* массив */
array_id:
	NAME dimension
	;

/* размерность*/
dimension:
	'[' ']'
	| '[' ']' int_dimension
	| int_dimension
	;

int_dimension:
	'[' INTEGER ']'
	| int_dimension '[' INTEGER ']'
	;


/*  не хватает строкового литерала */
basic_unit:
	NAME
	| INTEGER
	| FLOATING
	| STRING
	;

initializer_list:
	'{' initializers '}'
	;

initializers:
	basic_unit
	| initializers ',' basic_unit
	| initializers ',' initializer_list
	| initializer_list
	;

/* пока что так, в дальнейшем дополнить по полной */
expression:
	INTEGER
	| FLOATING
	;

/* с этим вопросы: глобально доступны только - 2, локально - 4, для функций толлько - 2 */
global_storage_class_specifier:
	EXTERN | STATIC
	; 

/* спецификатор типа (стр 35) */
type_specifier:
	simple_type_specifier
	| compound_type_specifier
	| CUSTOM_TYPE
	;
	
/* стр 40 */
simple_type_specifier:
	VOID 
	| arithmetic_type
	;

arithmetic_type:
	basic_type
	| additional_type_specifier
	;

basic_type:
	INT | FLOAT | DOUBLE | CHAR | signification
	;

additional_type_specifier:
	LONG_LONG | LONG | SHORT
	;

signification:
	SIGNED
	| UNSIGNED
	;

/* стр 61*/
type_qualifier:
	CONST
	| VOLATILE
	;
	

/* составные типы */
compound_type_specifier:
	structure
	| union
	| enumeration
	;
	

/* стр 45*/
structure:
	STRUCT NAME
	| STRUCT '{' structure_fields '}' 
	| STRUCT NAME '{' structure_fields '}'
	;

structure_fields:
	field
	| structure_fields field
	;

/* класс хранения указывать нельзя, но можно остальные спецификаторы*/
field:
	field_type field_ids ';'
	;
	
field_type:
	type_qualifier
	| type_specifier
	| field_type type_specifier
	| field_type type_qualifier
	;
	
field_ids:
	/* empty */
	| definitor_identificator
	| NAME ':' INTEGER /* <-- битовые поля */
	| ':' INTEGER /* <-- битовые поля */
	| field_ids ',' field_ids
	;
	

/* стр 52*/
union:
	UNION NAME
	| UNION '{' union_fields '}' 
	| UNION NAME '{' union_fields '}'
	;

union_fields:
	structure_fields
	;


/* стр 57*/
enumeration:
	ENUM NAME
	| ENUM NAME '{' enum_fields '}'
	;

/* нужны махинации с enum_identifier чтобы не было shift/reduce */
enum_fields:
	enum_identifier
	| enum_fields enum_identifier
	;
	
enum_identifier:
	NAME
	| NAME '=' INTEGER
	| enum_identifier ','
	;



%%

void yyerror(const char *str)
{
	fprintf(stderr, "Error: %s at line %d\n", str, yylineno);
}
  
int main(int argc, char *argv[])
{
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


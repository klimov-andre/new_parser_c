%{
	#include <stdio.h>
	#include <string.h>

	FILE *yyin;
	extern int yylineno;
	int yylex(void);
	void yyerror(const char *str);
%}

%token UNSIGNED SIGNED AUTO CHAR LONG INT DOUBLE FLOAT VOID SHORT LONG_LONG
%token STRUCT UNION ENUM TYPEDEF
%token EXTERN INLINE REGISTER RESTRICT STATIC CONST VOLATILE
%token PTR
%token SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN SUB_ASSIGN OR_ASSIGN DIV_ASSIGN ADD_ASSIGN MUL_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN
%token BREAK CONTINUE DEFAULT RETURN GOTO SIZEOF
%token DO ELSE FOR IF WHILE SWITCH CASE ELSE_IF
%token INTEGER FLOATING STRING NAME
%token SHIFT_RIGHT SHIFT_LEFT INC DEC AND OR LE GE EQ NE 

%left ','
%right  SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN SUB_ASSIGN OR_ASSIGN DIV_ASSIGN ADD_ASSIGN MUL_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN
%left OR AND '|' '^' '&' EQ NE GE LE '>' '<' SHIFT_RIGHT SHIFT_LEFT '+' '-'
%left '*' '/' INC DEC PTR

%start program
%define parse.error verbose

%%

program:
	definition
	| program definition
/*	| function*/
/*	| program function*/
/*	| typedef */
/*  | program typedef */
	;

definition:
	predefinitor ';'
	| predefinitor definitors ';'
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
	array_or_id
	| array_or_id '=' STRING
	| array_or_id '=' expression
	| array_or_id '=' initializer_list
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
	| type_specifier '*'
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
	| RESTRICT /* только для указателей и может нужно убрать*/
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
	| array_or_id
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


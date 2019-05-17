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
	
%}

%token UNSIGNED SIGNED AUTO CHAR LONG INT DOUBLE FLOAT VOID SHORT LONG_LONG
%token STRUCT UNION ENUM TYPEDEF
%token EXTERN INLINE REGISTER STATIC CONST VOLATILE
%token PTR STARS
%token SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN SUB_ASSIGN OR_ASSIGN DIV_ASSIGN ADD_ASSIGN MUL_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN
%token BREAK CONTINUE DEFAULT RETURN GOTO SIZEOF
%token DO ELSE FOR IF WHILE SWITCH CASE 
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


/* ----- Грамматика всей программы ----- */

program:
	definition {technical_variables_clean_all();}
	| program definition {technical_variables_clean_all();}
	| function
	| program function
	| typedef {technical_variables_clean_all();}
	| program typedef {technical_variables_clean_all();}
	;

/* ----- Грамматика объявлений ----- */
	
definition:
	predefinitor ';'
	| predefinitor definitors ';'
	;

// Должно работать еще и как 	typedef_oldtype TYPEDEF typedef_newtypes ';', но 32 конфликта - оч много, поэтому только так
typedef:
	TYPEDEF {set_specification(SpecificationTypeStorageDenied);}  typedef_oldtype typedef_newtypes ';' {set_specification(SpecificationTypeGlobal);}
	;

typedef_oldtype:
	predefinitor
	;
	
//specifier:
	//type_specifier
	//| type_qualifier
	//| specifier type_qualifier
//	| specifier type_specifier
	//;
	
typedef_newtypes:
	typedef_newtype {addtype($1); /*printf("%s\n",$1);*/}
	| typedef_newtypes ',' typedef_newtype {addtype($3); /*printf("%s\n",$3);*/}
	| typedef_newtypes ',' type_qualifier typedef_newtype {addtype($4); /*printf("%s\n",$4);*/}
	;
	

typedef_newtype:
	NAME {$$ = $1;}
	| pointer_id type_qualifier NAME {$$ = $3;}
	| NAME  type_qualifier {$$ = $1;}
	| pointer_id typedef_newtype {$$ = $2;}
	;

predefinitor:
	 storage_class_specifier
	| type_qualifier
	| type_specifier
	| predefinitor type_specifier
	| predefinitor storage_class_specifier
	| predefinitor type_qualifier
	;

definitors:
	definitor
	| definitors ',' definitor
	;

definitor:
	definitor_identificator
	| definitor_identificator '=' expression
	| definitor_identificator '=' initializer_list
	;

definitor_identificator:
	array_or_id
	| pointer_id type_qualifier array_or_id
	| pointer_id array_or_id
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
	
/* с этим вопросы: глобально доступны только - 2, локально - 4, для функций толлько - 2 */
storage_class_specifier:
	EXTERN {set_type_storage(TypeStorageExtern);}
	| STATIC {set_type_storage(TypeStorageStatic);}
	| REGISTER {set_type_storage(TypeStorageRegister);}
	| AUTO {set_type_storage(TypeStorageAuto);}
	;

/* спецификатор типа (стр 35) */
type_specifier:
	simple_type_specifier
	| compound_type_specifier
	| CUSTOM_TYPE {set_type_basic(TypeBasicCompound); }
	;
	
/* стр 40 */
simple_type_specifier:
	VOID {set_type_basic(TypeBasicVoid);}
	| arithmetic_type
	;

arithmetic_type:
	basic_type
	| additional_type_specifier
	;

basic_type:
	INT   {set_type_basic(TypeBasicInt);}
	| FLOAT {set_type_basic(TypeBasicFloat);}
	| DOUBLE {set_type_basic(TypeBasicDouble);}
	| CHAR {set_type_basic(TypeBasicChar);}
	| signification
	;

additional_type_specifier:
	LONG_LONG {set_type_additional(TypeAdditionalLongLong);}
	| LONG {set_type_additional(TypeAdditionalLong);}
	| SHORT {set_type_additional(TypeAdditionalShort);}
	;

signification:
	SIGNED {set_type_sign(TypeSignSigned);}
	| UNSIGNED {set_type_sign(TypeSignSigned);}
	;

/* стр 61*/
type_qualifier:
	CONST
	| VOLATILE
	;
	

/* составные типы */
compound_type_specifier:
	structure { set_type_basic(TypeBasicCompound);}
	| union {set_type_basic(TypeBasicCompound);}
	| enumeration {set_type_basic(TypeBasicCompound);}
	;
	

/* стр 45*/
structure:
	STRUCT NAME
	| STRUCT {technical_variables_clean_all();} '{' {set_specification(SpecificationTypeStorageDenied);} structure_fields '}' {set_specification(SpecificationTypeGlobal);}
	| STRUCT NAME {technical_variables_clean_all();} '{' {set_specification(SpecificationTypeStorageDenied);} structure_fields '}' {set_specification(SpecificationTypeGlobal);}
	;

structure_fields:
	field {technical_variables_clean_all();}
	| structure_fields {technical_variables_clean_all();} field {technical_variables_clean_all();}
	;

/* класс хранения указывать нельзя, но можно остальные спецификаторы*/
field:
	field_type {technical_variables_clean_all();} field_ids ';'
	;
	
field_type:
	predefinitor
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
	| UNION {technical_variables_clean_all();} '{' {set_specification(SpecificationTypeStorageDenied);} union_fields '}' {set_specification(SpecificationTypeGlobal);}
	| UNION NAME {technical_variables_clean_all();} '{' {set_specification(SpecificationTypeStorageDenied);} union_fields '}' {set_specification(SpecificationTypeGlobal);}
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
	
/* ----- Операторы ----- */
	
statement:
	definition {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	| label
	| expression_statement
	| conditional_statement
	| loop_statement
	| jump_statement
	| '{' statement_list '}'
	;
	
// Набор операторов
statement_list:
	statement {technical_variables_clean_all(); set_specification(SpecificationTypeNone);}
	| statement_list {technical_variables_clean_all(); set_specification(SpecificationTypeNone);} statement  {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	;

// Метки
label:
	NAME ':' statement
	;
	
label_for_switch:
	NAME ':' statement_for_switch
	| CASE conditional_expression ':' statement_for_switch
	| DEFAULT ':' statement_for_switch
	;
	
statement_for_switch:
	definition {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	| label_for_switch
	| expression_statement
	| conditional_statement
	| loop_statement
	| jump_for_switch_statement
	| '{' statement_for_switch_list '}'
	;

statement_for_switch_list:
	statement_for_switch {technical_variables_clean_all(); set_specification(SpecificationTypeNone);}
	| statement_for_switch_list {technical_variables_clean_all(); set_specification(SpecificationTypeNone);} statement_for_switch {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	;
	
statement_for_loop:
	definition {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	| label
	| expression_statement
	| conditional_for_loop_statement
	| loop_statement
	| jump_for_loop_statement
	| '{' statement_for_loop_list '}'
	;
	
statement_for_loop_list:
	statement_for_loop {technical_variables_clean_all(); set_specification(SpecificationTypeNone);}
	| statement_for_loop_list {technical_variables_clean_all(); set_specification(SpecificationTypeNone);} statement_for_loop {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	;
	
conditional_for_loop_statement:
	IF '(' expression ')' statement_for_loop
	| IF '(' expression ')' statement_for_loop ELSE statement_for_loop
	| SWITCH '(' expression ')' statement_for_switch_loop
	;

statement_for_switch_loop:
	definition {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	| label_for_switch
	| expression_statement
	| conditional_for_loop_statement
	| loop_statement
	| jump_for_switch_loop_statement
	| '{' statement_for_switch_loop_list '}'
	;
	
jump_for_switch_loop_statement:
	GOTO NAME ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;
	
statement_for_switch_loop_list:
	statement_for_switch_loop {technical_variables_clean_all(); set_specification(SpecificationTypeNone);}
	| statement_for_switch_loop_list {technical_variables_clean_all(); set_specification(SpecificationTypeNone);} statement_for_switch_loop {technical_variables_clean_all();; set_specification(SpecificationTypeNone);}
	;

// Выражения
expression_statement:
	';'
	| expression ';'
	;
	
// Условные операторы
conditional_statement:
	IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement_for_switch
	;
	
// Переходы
jump_statement:
	GOTO NAME ';'
	| RETURN ';'
	| RETURN expression ';'
	;
	
jump_for_switch_statement:
	jump_statement
	| BREAK ';'
	;

jump_for_loop_statement:
	jump_statement
	| CONTINUE ';'
	| BREAK ';'
	;
	
// Циклы
loop_statement:
	WHILE '(' expression ')' statement_for_loop
	| DO statement_for_loop WHILE '(' expression ')' ';'
	| FOR '(' expression_for_loop ';' expression_for_loop ')' statement_for_loop
	| FOR '(' expression_for_loop ';' expression_for_loop ';' expression ')' statement_for_loop
	;
	
// Выражения для циклов
expression_for_loop:
	predefinitor definitor /* объявление переменной может быть прямо в скобочках */
	| expression /* либо сразу выражение */
	;

/* ----- Грамматика функций ----- */	

function:
	prefuction  '(' {set_specification(SpecificationTypeArgument);} arguments ')' {set_specification(SpecificationTypeNone);} '{' statement_list '}' {set_specification(SpecificationTypeGlobal);}
	| prefuction '('{set_specification(SpecificationTypeArgument);} ')'{set_specification(SpecificationTypeNone);} '{' statement_list '}'{set_specification(SpecificationTypeGlobal);}
	;
	
prefuction:
	predefinitor func_id {technical_variables_clean_all();}
	;
	
// Грамматика имен функций
func_id:
	NAME
	| pointer_id NAME;
	
/* ----- Грамматика выражений ----- */

// Выражения могут быть перечислены в строчку через запятую
expression:
	assignment_expression
	| expression ',' assignment_expression
	;

// Присваивания в выражении
assignment_expression:
	conditional_expression /* Если нет знака присваивания, то это может быть условие */
	| prefix_expression assignment_operator assignment_expression
	;

// Сложные условные выражения (да да, те самые (**) конструкции типа Условие ? Выражение1 : Выражение2; )
conditional_expression:
	logical_expression
	| logical_expression '?' expression ':' conditional_expression
	;

// Логические выражения (выражения с логическими операторами)
logical_expression:
	compare_expression
	| logical_expression logical_operator compare_expression
	;

// Простые условные выражения (только со знаками сравнения)
compare_expression:
	shift_expression
	| compare_expression compare_operator shift_expression
	;
	
// Выражения со сдвигами
shift_expression:
	simple_expression
	| shift_expression SHIFT_LEFT simple_expression
	| shift_expression SHIFT_RIGHT simple_expression
	;
	
// Самые простые выражения (там где обычные арифметические операции)
simple_expression:
	cast
	| simple_expression calc_operator cast
	;
	
// Приведение типов (тоже может быть внутри выражений)
cast:
	prefix_expression
	| '(' {set_specification(SpecificationTypeStorageDenied);} {technical_variables_clean_all();} caster {technical_variables_clean_all();} ')' {set_specification(SpecificationTypeGlobal);} cast /*
	| '(' {set_specification(SpecificationTypeStorageDenied);} predefinitor pointer_id')' {set_specification(SpecificationTypeGlobal);} cast*/
	;
	
caster:
	predefinitor
	| predefinitor pointer_id;

// Конечные члены выражения	
primary_expression: 
	basic_unit
	| '(' expression ')'
	;
	
// Унарные выражения (чтоб можно было перед выражениями всякие штуки писать
// типа ++, --, а еще приведение типов) Здесь же и sizeof
prefix_expression:
	postfix_expression
	| INC prefix_expression
	| DEC prefix_expression
	| unary_operator cast
	| SIZEOF prefix_expression
	| SIZEOF '(' {set_specification(SpecificationTypeStorageDenied);} caster {technical_variables_clean_all();} ')' {set_specification(SpecificationTypeGlobal);}
	;

// Те же унарные выражения, только уже после основных выражений
postfix_expression:
	primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' arguments_without_type ')'
	| postfix_expression '.' NAME
	| postfix_expression PTR NAME
	| postfix_expression INC
	| postfix_expression DEC
	;
	
/* ----- Описание аргументов ----- */

arguments:
	predefinitor {technical_variables_clean_all();} definitor
	| arguments ',' {technical_variables_clean_all();}  predefinitor {technical_variables_clean_all();} definitor;
	
arguments_without_type:
	assignment_expression
	| arguments_without_type ',' assignment_expression
	;
	
/* ----- Всякие разные операторы ----- */

assignment_operator:
	'='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| SHIFT_LEFT_ASSIGN
	| SHIFT_RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;
	
unary_operator:
	'&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

calc_operator:
	'+'
	| '-'
	| '*'
	| '/'
	| '%'
	;
	
compare_operator:
	'<'
	| '>'
	| LE
	| GE
	| EQ
	| NE
	;
	
logical_operator:
	'&'
	| '|'
	| '^' 
	| AND
	| OR
	;
%%

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



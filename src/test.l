%{
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	#include <stdlib.h>
	
	extern FILE *yyin;
	extern struct typedef_list
	{
		char *type_id;
		struct typedef_list *next;
	} *g_typedefs;
	
	
	int existstype(char const *xtype)
	{
		struct typedef_list *tmp;

		tmp = g_typedefs;
		while (tmp)
		{
		  if (0 == strcmp(xtype, tmp->type_id))
		  {
		    return 1;
		  }
		  tmp = tmp->next;
		}
		return 0;
	}
	
	int get_type(const char* token)
	{
		if(existstype(token))
		{
			return CUSTOM_TYPE;
		}
		return NAME;
	}
	
	void literal()
	{
		char c;
		while((c = getc(yyin)) != '\'' && c != '\n' && c != 0)
			printf("%c\n", c);
	}
	
	void string()
	{
		char c;
		while((c = getc(yyin)) != '\"' && c != 0)
			printf("%c\n", c);
	}
	
%}

/*  не хватает строковогго литерала*/
dquotes_one (\"([^\\\"\n]*(\\\"|\\\n|\\)?)*(\"|[^\\]\n))
dquotes_two (\"([^\\\"\n]*(\\\"|\\\n|\\)?)*([^\\]\"|[^\\]\n))

string ({dquotes_one}|{dquotes_two})+([\t\n ]*)({dquotes_one}|{dquotes_two})*

comment (\/{2,}(.*\\(\n))+.*)|(\/{2,}(.*)(\n))|(\/\*([^*]|\*+[^*/])*\*+\/)

squotes_one (\'(\\.|.{0,5})\')

ch_or_digit [_a-zA-Z0-9]

Sign [+-] 
 
Num [0-9] 
 
Expo [eE]{Sign}?{Num}+ 

%option noyywrap
%option yylineno
%%
#[ \t]*(define|include|if|else|ifdef|ifndef|endif|pragma)([^\n\\]*(\\\n|\\\r\n|\\)?)*([^\\]\n) ;
#[ \t]*(define|include|if|else|ifdef|ifndef|endif|pragma) ;
{comment} ;
{squotes_one} return STRING;
{string} return STRING;

"auto"			{return(AUTO);}
"break"			{return(BREAK);}
"case"			{return(CASE);}
"char"			{return(CHAR);}
"const"			{return(CONST);}
"continue"		{return(CONTINUE);}
"default"		{return(DEFAULT);}
"do"			{return(DO);}
"double"		{return(DOUBLE);}
"else"			{return(ELSE);}
"enum"			{return(ENUM);}
"extern"		{return(EXTERN);}
"float"			{return(FLOAT);}
"for"			{return(FOR);}
"goto"			{return(GOTO);}
"if"			{return(IF);}
"int"			{return(INT);}
"long long"     {return(LONG_LONG);}
"long"			{return(LONG);}
"register"		{return(REGISTER);}
"return"		{return(RETURN);}
"short"			{return(SHORT);}
"signed"		{return(SIGNED);}
"sizeof"		{return(SIZEOF);}
"static"		{return(STATIC);}
"struct"		{return(STRUCT);}
"switch"		{return(SWITCH);}
"typedef"		{return(TYPEDEF);}
"union"			{return(UNION);}
"unsigned"		{return(UNSIGNED);}
"void"			{return(VOID);}
"volatile"		{return(VOLATILE);}
"while"			{return(WHILE);}

">>="			{return(SHIFT_RIGHT_ASSIGN);}
"<<="			{return(SHIFT_LEFT_ASSIGN);}
"+="			{return(ADD_ASSIGN);}
"-="			{return(SUB_ASSIGN);}
"*="			{return(MUL_ASSIGN);}
"/="			{return(DIV_ASSIGN);}
"%="			{return(MOD_ASSIGN);}
"&="			{return(AND_ASSIGN);}
"^="			{return(XOR_ASSIGN);}
"|="			{return(OR_ASSIGN);}
">>"			{return(SHIFT_RIGHT);}
"<<"			{return(SHIFT_LEFT);}
"++"			{return(INC);}
"--"			{return(DEC);}
"->"			{return(PTR);}
"&&"			{return(AND);}
"||"			{return(OR);}
"<="			{return(LE);}
">="			{return(GE);}
"=="			{return(EQ);}
"!="			{return(NE);}
";"				{return(';');}
"{"				{return('{');}
"}"				{return('}');}
","				{return(',');}
":"				{return(':');}
"="				{return('=');}
"("				{return('(');}
")"				{return(')');}
"["				{return('[');}
"]"				{return(']');}
"."				{return('.');}
"&"				{return('&');}
"!"				{return('!');}
"~"				{return('~');}
"-"				{return('-');}
"+"				{return('+');}
\*(([\t\n ])*\*)+   {return(STARS);}
"*"				{return('*');}
"/"				{return('/');}
"%"				{return('%');}
"<"				{return('<');}
">"				{return('>');}
"^"				{return('^');}
"|"				{return('|');}
"?"				{return('?');}

[_a-zA-Z][_a-zA-Z0-9]*		{yylval.str = strdup(yytext); return (get_type(strdup(yytext)));}
[0-9]+						{return (INTEGER);}
[0-9]+([.][0-9]*)?|[.][0-9]+				{return (FLOATING);}// очень плохая регулярка
[0-9]*[eE][+-]?[0-9]+	{return (FLOATING);}

 
({Num}*\.{Num}+)({Expo})? {return (FLOATING);}
({Num}+\.{Num}*)({Expo})? {return (FLOATING);}

0[bB][01]+		{return(INTEGER);}
0[xX][0-9a-fA-F]+	{return(INTEGER);}

[\n\r]			;
[ \t]+			;
. ;
%%


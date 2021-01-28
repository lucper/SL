%{
#include <stdlib.h>
#include <string.h>
#include "slc.h" // mandatory for submission
#include "tree.h"

void insertTopList();
void genNode3(Categ categ, int numComps, char *ident);
void genNode(Categ categ, int numComps);
void genIdent(char *token_val);
void genInt(char *token_val);
void genBool(char *token_val);
void genEmpty();
void genOp(Categ categ);
%}

%union {
	char *symbol;
}
%token <symbol> BOOLEAN
%token EQUAL
%token DIFFERENT
%token LESS
%token LESS_OR_EQUAL
%token GREATER
%token GREATER_OR_EQUAL
%token PLUS
%token MINUS
%token OR
%token MULTIPLY
%token DIV
%token AND
%token CLOSE_BRACE
%token CLOSE_BRACKET
%token CLOSE_PAREN
%token COLON
%token COMMA
%token ELSE
%token END_OF_FILE
%token FUNCTIONS
%token GOTO
%token <symbol> IDENTIFIER
%token ASSIGN
%token IF
%token <symbol> INTEGER
%token LABELS
%token NOT
%token OPEN_BRACE
%token OPEN_BRACKET
%token OPEN_PAREN
%token RETURN
%token SEMI_COLON
%token TYPES
%token VAR
%token VARS
%token VOID
%token WHILE
%token LEXICAL_ERROR

%%
program: function END_OF_FILE														{ genNode(C_PROGRAM, 1); return 0; }
    ;
function: function_header block	                                                    { genNode(C_FUNCTION, 2); }
	;
function_header: identifier identifier formal_parameters                            { genNode(C_FUNCTION_HEADER, 3); }
| VOID { genEmpty(); } identifier formal_parameters                                 { genNode(C_FUNCTION_HEADER, 2); }
	;
block: body																			{ genNode(C_BLOCK, 1); }
	| labels body																	{ genNode(C_BLOCK, 2); }
	| variables body																{ genNode(C_BLOCK, 2); }
	| functions body    															{ genNode(C_BLOCK, 2); }
    | labels variables body 														{ genNode(C_BLOCK, 3); }
    | labels functions body 														{ genNode(C_BLOCK, 3); }
	| variables functions body														{ genNode(C_BLOCK, 3); }
    | labels variables functions body                                               { genNode(C_BLOCK, 4); }
	;
labels: LABELS identifier_list SEMI_COLON											{ genNode(C_LABELS, 1); }
	;
variables: VARS declaration_vars 													{ genNode(C_VARIABLES, 1); }
	;
declaration_vars: identifier_list COLON type SEMI_COLON								{ genNode(C_DECLARATION_VARS, 2); }
	| declaration_vars identifier_list COLON type SEMI_COLON						{ genNode(C_DECLARATION_VARS, 2); insertTopList(); }
	;
functions: FUNCTIONS declaration_funcs												{ genNode(C_FUNCTIONS, 1); }
	;
declaration_funcs: function															{ genNode(C_DECLARATION_FUNCS, 1); }
	| declaration_funcs function													{ genNode(C_DECLARATION_FUNCS, 1); insertTopList(); }
	;
body: OPEN_BRACE statements CLOSE_BRACE												{ genNode(C_BODY, 1); }
	| OPEN_BRACE empty CLOSE_BRACE													{ genNode(C_BODY, 1); }
	;
statements: statement																{ genNode(C_STATEMENTS, 1); }
	| statements statement															{ genNode(C_STATEMENTS, 1); insertTopList(); }
	;
formal_parameters: OPEN_PAREN formal_parameter_list CLOSE_PAREN						{ genNode(C_PARAMS, 1); }
	| OPEN_PAREN empty CLOSE_PAREN													{ genNode(C_PARAMS, 1); }
	;
formal_parameter_list: formal_parameter												{ genNode(C_PARAM_LIST, 1); }
	| formal_parameter_list COMMA formal_parameter									{ genNode(C_PARAM_LIST, 1); insertTopList(); }
	;
formal_parameter: VAR identifier_list COLON identifier								{ genNode(C_REF_PARAM, 2); }
	| identifier_list COLON identifier												{ genNode(C_VAL_PARAM, 2); }
	;
statement: unlabeled_statement														{ genNode(C_STATEMENT, 1); }
	| identifier COLON unlabeled_statement											{ genNode(C_STATEMENT, 2); }
	;
unlabeled_statement: assignment														{ genNode(C_UNLABELED_STATEMENT, 1); }
	| function_call_statement														{ genNode(C_UNLABELED_STATEMENT, 1); }
	| goto																			{ genNode(C_UNLABELED_STATEMENT, 1); }
	| return																		{ genNode(C_UNLABELED_STATEMENT, 1); }
	| conditional																	{ genNode(C_UNLABELED_STATEMENT, 1); }
	| repetitive																	{ genNode(C_UNLABELED_STATEMENT, 1); }
	| compound																		{ genNode(C_UNLABELED_STATEMENT, 1); }
	| empty_statement																{ genNode(C_UNLABELED_STATEMENT, 1); }
	;
assignment: variable ASSIGN expression SEMI_COLON									{ genNode(C_ASSIGNMENT, 2); }
	;
function_call_statement: function_call SEMI_COLON									{ genNode(C_FUNCTION_CALL_STATEMENT, 1); }
	;
goto: GOTO identifier SEMI_COLON													{ genNode(C_GOTO, 1); }
	;
return: RETURN expression SEMI_COLON												{ genNode(C_RETURN, 1); }
	;
conditional: IF OPEN_PAREN expression CLOSE_PAREN compound							{ genNode(C_CONDITIONAL, 2); }
	| IF OPEN_PAREN expression CLOSE_PAREN compound ELSE compound					{ genNode(C_CONDITIONAL, 3); }
	;
repetitive: WHILE OPEN_PAREN expression CLOSE_PAREN compound						{ genNode(C_REPETITIVE, 2); }
	;
compound: OPEN_BRACE unlabeled_statements CLOSE_BRACE								{ genNode(C_COMPOUND, 1); }
	| OPEN_BRACE empty CLOSE_BRACE													{ genNode(C_COMPOUND, 1); }
	;
unlabeled_statements: unlabeled_statement											{ genNode(C_UNLABELED_STATEMENTS, 1); }
	| unlabeled_statements unlabeled_statement										{ genNode(C_UNLABELED_STATEMENTS, 1); insertTopList(); }
	;
empty_statement: SEMI_COLON															{ /*?*/ genEmpty(); }
	;
expression: simple_expression														{ genNode(C_EXPRESSION, 1); }
	| binop_expression																{ genNode(C_EXPRESSION, 1); }		
	| unop_expression																{ genNode(C_EXPRESSION, 1); }			
	| empty
	;
binop_expression: unop_expression relational_operator simple_expression				{ genNode(C_BINOP_EXPRESSION, 3); }
	| simple_expression relational_operator simple_expression						{ genNode(C_BINOP_EXPRESSION, 3); }
	;
simple_expression: terms			    											{ genNode(C_SIMPLE_EXPRESSION, 1); }
	| simple_expression additive_operator terms										{ genNode(C_SIMPLE_EXPRESSION, 2); insertTopList(); }
	;
unop_expression: unary_operator simple_expression									{ genNode(C_UNOP_EXPRESSION, 2); }
	;
relational_operator: op_less_eq 													{ genNode(C_RELOP, 1); }
	| op_less																		{ genNode(C_RELOP, 1); }									
	| op_eq 																		{ genNode(C_RELOP, 1); }
	| op_diff 																		{ genNode(C_RELOP, 1); }
	| op_greater_eq 																{ genNode(C_RELOP, 1); }
	| op_greater																	{ genNode(C_RELOP, 1); }
	;
op_less_eq: LESS_OR_EQUAL 															{ genOp(C_LESS_EQUAL); }
	;
op_less: LESS 																		{ genOp(C_LESS); }
	;
op_eq: EQUAL 																		{ genOp(C_EQUAL); }
	;
op_diff: DIFFERENT 																	{ genOp(C_DIFFERENT); }
	;
op_greater_eq: GREATER_OR_EQUAL 													{ genOp(C_GREATER_EQUAL); }
	;
op_greater: GREATER 																{ genOp(C_GREATER); }
	;
additive_operator: op_plus															{ genNode(C_ADDOP, 1); }
	| op_minus																		{ genNode(C_ADDOP, 1); }
	| op_or																			{ genNode(C_ADDOP, 1); }
	;
unary_operator: op_plus																{ genNode(C_UNOP, 1); }
	| op_minus																		{ genNode(C_UNOP, 1); }
	| op_not 																		{ genNode(C_UNOP, 1); }
	;
op_plus: PLUS 																		{ genOp(C_PLUS); }
	;
op_minus: MINUS 																	{ genOp(C_MINUS); }
	;
op_not: NOT 																		{ genOp(C_NOT); }
	;
op_or: OR 																			{ genOp(C_OR); }
	;
terms: factor																		{ genNode(C_TERMS, 1); }
	| terms multiplicative_operator factor											{ genNode(C_TERMS, 2); insertTopList(); }
	;
multiplicative_operator: op_mult 													{ genNode(C_MULOP, 1); }
	| op_div																		{ genNode(C_MULOP, 1); }
	| op_and																		{ genNode(C_MULOP, 1); }
	;
op_mult: MULTIPLY 																	{ genOp(C_MULTIPLY); }
	;
op_div: DIV 																		{ genOp(C_DIV); }
	;
op_and: AND 																		{ genOp(C_AND); }
	;
factor: variable																	{ genNode(C_FACTOR, 1); }
	| integer																		{ genNode(C_FACTOR, 1); }
	| boolean 																		{ genNode(C_FACTOR, 1); }
	| function_call																	{ genNode(C_FACTOR, 1); }
	| OPEN_PAREN expression CLOSE_PAREN												{ genNode(C_FACTOR, 1); }
	;
function_call: identifier OPEN_PAREN expression_list CLOSE_PAREN					{ genNode(C_FUNCTION_CALL, 2); }
	;
identifier_list: identifier									                        { genNode(C_IDENTIFIER_LIST, 1); }
	| identifier_list COMMA identifier												{ genNode(C_IDENTIFIER_LIST, 1); insertTopList(); }
	;
expression_list: expression									                        { genNode(C_EXPRESSION_LIST, 1); }
	| expression_list COMMA expression												{ genNode(C_EXPRESSION_LIST, 1); insertTopList(); }
	;
variable: identifier																{ genNode(C_VARIABLE, 1); }
	;
type: identifier																	{ genNode(C_TYPE, 1); }
	;
identifier: IDENTIFIER																{ genIdent($1); }
	;
integer: INTEGER																	{ genInt($1); }
	;
boolean: BOOLEAN 																	{ genBool($1); }
	;
empty: /*empty*/																	{ genEmpty(); }
	;

%%

void insertTopList()
{
	TreeNode *top = pop();
	TreeNode *prev = pop();
	top->next = prev;
	push(top);
}

void genNode3(Categ categ, int numComps, char *symbol)
{
	TreeNode *treeNode = malloc(sizeof(TreeNode));
	treeNode->categ = categ;
	treeNode->next = NULL;
	treeNode->symbol = malloc(strlen(symbol) + 1);
        strcpy(treeNode->symbol, symbol);
	if (numComps > 0)
            for(int i = numComps - 1; i >= 0; i--)
                treeNode->components[i] = pop();
	push(treeNode);
}

void genNode(Categ categ, int numComps)
{
	genNode3(categ, numComps, "");
}

void genIdent(char *token_val)
{
    genNode3(C_IDENTIFIER, 0, token_val);
}

void genInt(char *token_val)
{	
	genNode3(C_INTEGER, 0, token_val);
}

void genBool(char *token_val)
{
	genNode3(C_BOOLEAN, 0, token_val);
}

void genEmpty() 
{
	push(NULL);
}

void genOp (Categ categ)
{
	genNode(categ, 0);
}

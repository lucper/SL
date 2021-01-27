#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "symtable.h"

#define MAX_COMPS 5

typedef enum {
    C_PROGRAM = 1,
    C_FUNCTION,
    C_FUNCTION_HEADER,
    C_BLOCK,
    C_PARAMS,
    C_BODY,
    C_IDENTIFIER,
    C_FUNCTION_CALL,
    C_STATEMENTS,
    C_STATEMENT,
    C_UNLABELED_STATEMENT,
    C_FUNCTION_CALL_STATEMENT,
    C_EXPRESSION,
    C_SIMPLE_EXPRESSION,
    C_TERM,
    C_FACTOR,
    C_EXPRESSION_LIST,
    C_INTEGER,
	C_BOOLEAN,
    C_VARIABLE,
    C_GOTO,
    C_ASSIGNMENT,
    C_COMPOUND,
    C_CONDITIONAL,
    C_VARIABLES,
    C_DECLARATION_VARS,
    C_TYPE,
    C_IDENTIFIER_LIST,
    C_UNLABELED_STATEMENTS,
    C_BINOP_EXPRESSION,
    C_REPETITIVE,
    C_FUNCTIONS,
    C_DECLARATION_FUNCS,
    C_UNOP_EXPRESSION,
    C_RETURN,
    C_PARAM_LIST,
    C_REF_PARAM,
	C_VAL_PARAM,
    C_FUNCTION_PARAM,
    C_LABELS,
	C_ADDOP,
	C_MULOP,
	C_RELOP,
	C_UNOP,
	/* Operators */
	C_LESS_EQUAL,
    C_LESS,
	C_EQUAL,
	C_DIFFERENT,
	C_GREATER_EQUAL,
    C_GREATER,
    C_PLUS,
    C_MINUS,
	C_OR,
	C_NOT,
    C_MULTIPLY,
	C_DIV,
	C_AND
} Categ;

typedef struct _treeNode {
    Categ categ;
    struct _treeNode *next;
    struct _treeNode *components[MAX_COMPS];
    char *symbol;
} TreeNode;

typedef struct _parseStackNode {
    TreeNode *treeNode;
    struct _parseStackNode *next;
} ParseStackNode;

void *getTree();
void counts(void *p, int *functions, int *funcalls, int *whiles, int *ifs, int *bin);
void dumpTree(TreeNode *p, int indent);
void freeStack();
void *push(TreeNode *treeNode);
TreeNode *pop();
TreeNode *reverse(TreeNode *p);

extern ParseStackNode *top;

#endif /* TREE_H */

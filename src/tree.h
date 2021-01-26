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
    C_FORMAL_PARAMS,
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
    C_GOTO,
    C_ASSIGNMENT,
    C_ADDITIVE_TERM,
    C_PLUS,                     /* TODO: verify if this is correct */
    C_MINUS,                    /* TODO: verify if this is correct */
    C_MULTIPLICATIVE_FACTOR,
    C_MULTIPLY,                 /* TODO: verify if this is correct */
    C_COMPOUND,
    C_CONDITIONAL,
    C_LESS,                     /* TODO: verify if this is correct */
    C_VARIABLES,
    C_VARIABLE,
    C_DECLARATION_VARS,
    C_TYPE,
    C_IDENTIFIER_LIST,
    C_UNLABELED_STATEMENTS,
    C_BINOP_EXPRESSION,
    C_REPETITIVE,
    C_GREATER,                  /* TODO: verify if this is correct */
    C_FUNCTIONS,
    C_DECLARATION_FUNCS,
    C_UNOP_EXPRESSION,
    C_RETURN,
    C_FORMAL_PARAMS_REST,
    C_FORMAL_PARAM,
    C_EXPRESSION_PARAM,
    C_FUNCTION_PARAM,
    C_LABELS,
	C_BOOLEAN	
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

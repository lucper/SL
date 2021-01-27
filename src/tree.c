#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

ParseStackNode *top = NULL;

static void freeTreeNode(TreeNode *p)
{
    if (p) {
        if (p->next)
            freeTreeNode(p->next);
        for (int i = 0; i < MAX_COMPS; i++)
            if (p->components[i])
                freeTreeNode(p->components[i]);
        free(p->symbol);
        free(p);
    }
}

TreeNode *reverse(TreeNode *p)
{
    TreeNode *prev = NULL, *next;
    while(p) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    return prev;
}

void *push(TreeNode *treeNode)
{
    if (!top) {
        top = malloc(sizeof(ParseStackNode));
        top->treeNode = treeNode;
        top->next = NULL;
    } else {
        ParseStackNode *newNode = malloc(sizeof(ParseStackNode));
        newNode->treeNode = treeNode;
        newNode->next = top;
        top = newNode;
    }
}

TreeNode *pop()
{
    if (!top) {
        printf("nothing to pop: empty stack");
        exit(1); // TODO: return error message
    } else {
        ParseStackNode *temp = top;
        TreeNode *poppedTreeNode = temp->treeNode;
        top = top->next;
        free(temp);
        return poppedTreeNode;
    }
}

void freeStack()
{
    if (top) {
        ParseStackNode *temp;
        while (top) {
            temp = top;
            top = top->next;
            freeTreeNode(temp->treeNode);
            free(temp);
        }
    }
}

/* Return pointer to final program tree.
 * If the tree was built correctly, it will
 * be the only pointer on the stack. The client
 * doesn't need to know its type.  */
void *getTree()
{
    return pop();
}

/* Recursively count nodes in tree of a given category.  */
static int count(TreeNode *p, Categ cat)
{
    if (!p)
        return 0;
    else {
        int countCateg = 0;
        if (p->categ == cat)
            countCateg++;
        
        if (p->next)
            countCateg += count(p->next, cat);
        
        for (int i = 0; i < MAX_COMPS; i++)
            if (p->components[i])
                countCateg += count(p->components[i], cat);
        return countCateg;
    }
}

/* Return the number of occurrences of program constructs in the tree:
 * p                pointer to the tree
 * functions        function declarations
 * funcalls         function calls
 * whiles           while statements
 * ifs              if statements
 * bin              binary operations 
 * Traverse the tree and increment corresponding constructs. */
void counts(void *p, int *functions, int *funcalls, int *whiles, int *ifs, int *bin)
{
    *functions = count(p, C_FUNCTION);
    *funcalls = count(p, C_FUNCTION_CALL);
    *whiles = count(p, C_REPETITIVE);
    *ifs = count(p, C_CONDITIONAL);
    *bin = count(p, C_RELOP) + count(p, C_ADDOP) + count(p, C_MULOP);
}

/* (!) For debugging purposes
 * Dump contents of nodes recursively, where
 * p                pointer to root
 * indent           amount of identation for node p (increase in recursive calls) */
void dumpTree(TreeNode *p, int indent)
{
    // TODO: implement indentation
    if (!p)
        return;
    else {
        if (p->next)
            dumpTree(p->next, indent);
        for (int i = 0; i < MAX_COMPS; i++)
            if (p->components[i])
                dumpTree(p->components[i], indent);
        printf("Categ = %d\tSymbol = %s\n", p->categ, p->symbol);
    }
}

#include "symtable.h"
#include "tree.h"

void processFuncDecl(TreeNode *p, bool isMain);
TypeDescr *processBinExpr(TreeNode *p);
TypeDescr *processUniExpr(TreeNode *p);
TypeDescr *processExpr(TreeNode *p);
void processVarDecl(TreeNode *p);
void processVariables(TreeNode *p);
void processAssign(TreeNode *p);
void processStatement(TreeNode *p);
void processIteration(TreeNode *p);
void processProgram(void *p); /* mandatory for submission */

extern int currentLevel;
extern int currentDispl;

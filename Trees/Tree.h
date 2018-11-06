#ifndef ALBERI_H
#define ALBERI_H
#include "UnivEl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef int element;
typedef struct treeElement {  //this is a node
  element value; //the node's value'
  struct treeElement *left, *right; //the node's sons'
} node;
typedef node* tree;

typedef unsigned char boolean;
#define True 1
#define False 0
#define Error -1

//extern tree emptyTree(void);
#define emptyTree() NULL //creates an empty tree, which is just a null pointer
extern element root(tree t);
extern tree left(tree t);
extern tree right(tree t);
extern tree consTree(element e, tree l, tree r);
extern tree CONSTREE(void* toel, int tipo, tree l, tree r);
extern boolean isEmpty(tree t);

extern void preOrder(tree t);
extern void inOrder(tree t);
extern void postOrder(tree t);

extern tree insordTree(element e, tree t);
extern tree INSORDTREE(void* toel, int tipo, tree t);
extern boolean memberTree(element e, tree t);
extern boolean memberOrdTree(element e, tree t);
extern tree copyTree(tree t);
extern void DominantsCounter(tree t, int* n);

extern boolean isLessT(element a, element b);
extern boolean isEqualT(element a, element b);
extern boolean isBiggerT(element a, element b);
extern void BstMaxToMin(tree t);
extern void BstMinToMax(tree t);
extern int height(tree t);
extern int LeavesNumber(tree t);

extern void delete_tree(tree t);
extern void free_node(tree n);
extern tree deleteBST(element e, tree t);
extern tree DELETEBST(void*toel, int tipo, tree t);
#endif /*ALBERI_H*/

#ifndef ALBERI_H
#define ALBERI_H
#include "UnivEl.h"
/* Ci devi infilare:
  -showEl(element e);
  -cmpTreeEl(node* a, node* b);
  -typedef dell'elemento
*/

/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef int element;
typedef struct treeElement {
  element value;
  struct treeElement *left, *right;
} node;
typedef node* tree;

typedef unsigned char boolean;
#define True 1
#define False 0
#define Error -1

//extern tree emptyTree(void);
#define emptyTree() NULL
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
extern void ContaDominanti(tree t, int* n);

extern boolean isLess(element a, element b);
extern boolean isEqual(element a, element b);
extern boolean isBigger(element a, element b);
//non miei
//extern tree ConstInputAnticipato(void);
//extern tree ConstVettAnticipato(int*, int*);
extern void BstMaxToMin(tree t);
extern void BstMinToMax(tree t);
extern tree deleteBST(element e, tree t);
extern tree DELETEBST(void*toel, int tipo, tree t);
extern int height(tree t);
extern int numerofoglie(tree t);
extern void delete_tree(tree t);
#endif /*ALBERI_H*/

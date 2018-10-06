#include "UnivEl.h"
#include "Alberi.h"
element root(tree t) //returns the root element
{
  if(t == NULL){
	element tmp; 	//Returns a null element. May give errors if unchecked
	tmp.value = NULL;
	tmp.type = NULL;
	return tmp;
  }
  return t->value; 
}

boolean isEmpty(tree t) //tells if the tree is empty
{
 return t == NULL ? True : False;
}

tree left(tree t) //returns the left tree
{
  return t == NULL ? NULL : t->left;
}

tree right(tree t) // returns the right tree
{
  return t== NULL ? NULL : t->right;
}

tree consTree(element e, tree l, tree r) 
/* Builds a new tree out of the given element and trees.
 * In someway, the function creates a new root which uses
 * the given trees as sons */
{
  tree t = malloc(sizeof(node));
  t->value = copy_element(e);
  t->left = l;
  t->right = r;
  return t;
}


void preOrder(tree t) //Prints the tree in pre order
{
  if(t!=NULL){
		printf("\t");
		printEl(root(t));
		preOrder(left(t));
		preOrder(right(t));
	}
}

void inOrder(tree t) //Prints the tree in order
{
	if (isEmpty(t)==False){
		inOrder(left(t));
		printf("\t");
		printEl(root(t));
		inOrder(right(t));
	}
}

void postOrder(tree t) //Prints the tree in post order
{
	if (isEmpty(t)==False){
		postOrder(left(t));
		postOrder(right(t));
		printf("\t");
		printEl(root(t));
	}
}

boolean elementIsEqual(element e1, element e2) //checks if 2 elements are equal
{
  return cmp(&e1, &e2) == 0 ? True : False;
}

boolean memberTree(element e, tree t) //checks if a give element is part of the tree
{
  return t == NULL ? False : (cmp(&e, &(t->value)) == 0 ? True : (memberTree(e, t->left) || memberTree(e, t->right)));
}

boolean memberOrdTree(element e, tree t) //checks if a given element is part of the BST
{
  int conf;
  while(t != NULL){
    conf = cmp(&e, &(t->value));
    if(conf == 0)
      return True; //element found
    else if(conf < 0)
      t = t->left;
    else
      t = t->right;
  }
  return False;
}

tree copyTree(tree t) //Cretes a new tree which is the exact copy of the given one
{
  if(isEmpty(t)==True)
    return NULL;
  return consTree(root(t), copyTree(left(t)), copyTree(right(t)));
}

void DominantsCounter(tree t, int* n)
/* 
 * This functions is probably useless.
 * It tells you how many nodes are at the same time:
 * - Not leaves
 * - Bigger than the additions of their sons' value
 */
{
	int c = element_value(&(t->value)); //gets the absolute value of the node's element
	if (left(t) == NULL && right(t) == NULL)
		return;
	if(left(t) != NULL){
		DominantsCounter(left(t), n);
		c = c - element_value(&(left(t)->value)); //checking if the absolute value of the left son is bigger than the node's one'
	}
	if (right(t) != NULL) {
		DominantsCounter(right(t), n);
		if (!(c < 0)) { //if the left son was bigger, no need to do this
			c = c - element_value(&right(t)->value); //same as before
		}
	}
	if(c > 0) //if the parent was bigger than the addition of the sons'absolute values we found a dominant node
		(*n)++;
}

int LeavesNumber(tree t) //counts how many leaves are available in the given tree
{
	if (isEmpty(t) == True)
		return 0;
		
	boolean empty_left = isEmpty(left(t));
	boolean empty_right = isEmpty(right(t));
	
	if (empty_left == True && empty_right == True)
		return 1;
	else if (empty_left == False && empty_right == False)
		return  LeavesNumber(left(t)) + LeavesNumber(right(t));
	else if (empty_left == True && empty_right == False)
		return  LeavesNumber(right(t));
	else if (empty_left == False && empty_right == True)
		return  LeavesNumber(left(t));
}

boolean isBigger(element a, element b) //Tells which element is bigger
//Does not support different elements
{
	if(cmp(&a,&b)>0)
		return True;
	else
		return False;
}

boolean isEqual(element a, element b) // Tells IF THE GIVEN ELEMENTS ARE EQUAL
//does not support different elements
{
	if(cmp(&a,&b) == 0)
		return True;
	else
		return False;
}

boolean isLess(element a, element b) //Tells if a is smaller than b
//does not support different elements
{
	if(cmp(&a,&b) < 0)
		return True;
	else
		return False;
}


tree insordTree(element e, tree t) // Adds an element to the tree without breaking the BST order
{
	if (isEmpty(t) == True)
		return consTree(e, emptyTree(), emptyTree());
	else
		if (isLess(e, root(t)) == True || isEqual(e, root(t)) == True)
			return consTree(root(t), insordTree(e, left(t)), right(t));
		else
			return consTree(root(t), left(t), insordTree(e, right(t)));
}

void BstMaxToMin(tree t) //Prints the tree from the biggest element to the smallest
//uses the bst properties
{
	if (t != NULL){
		BstMaxToMin(right(t));
		printf("\n");
		printEl(root(t));
		BstMaxToMin(left(t));
	}
}

void BstMinToMax(tree t) //prints the whole tree from the smallest element to the biggest
//uses the bst properties
{
	if (t != NULL){
		BstMinToMax(left(t));
		printf("\n");
		printEl(root(t));
		BstMinToMax(right(t));
	}
}

tree deleteBST(element e, tree t) { //Deletes an element equal to the one given
//uses bst properties
	tree l = t, next;
	tree pl = NULL, pr = NULL;
	while (isEmpty(t)==False && isEqual(root(t),e) == False) {
		if (isLess(e,root(t)) == True) {
			pl = t;
			pr = emptyTree();
			t = left(t);
		}
		else {
			pl = emptyTree();
			pr = t;
			t = right(t);
		}
	}
	//printf("\ntrovato %d", root(t));

	if (isEmpty(t)==False) {
		// The node is a leaf
		if (isEmpty(left(t))==True && isEmpty(right(t))==True) {
                        
			if (t == l){
                            free_node(t);
				return emptyTree();
                        }
                        free_node(t);
			next = emptyTree();
		}
		else {
			// it only has 1 son
			if (isEmpty(left(t))==True) {
                            free_node(t);
				if (t == l){
                                    free_node(t);
                                    return right(t);
                                }
                            free_node(t);
				next = right(t);
			}
			else {
				if (isEmpty(right(t))==True) {
					if (t == l){
                                            free_node(t);                                      
						return left(t);
                                            }
                                        free_node(t);
					next = left(t);
				}
				else {
					// 2 sons
					pr = t;
					pl = emptyTree();
					next = right(t);
					if (isEmpty(next)==False)
						while (isEmpty(left(next))==False) {
							pr = emptyTree();
							pl = next;
							next = left(next);
						}
					t->value = copy_element(root(next));
					if (right(next) != NULL) {
						next = right(next);
					}
					else
						next = emptyTree();
				}
			}
		}
		if (isEmpty(pl) == False)
			pl->left = next;
		if (isEmpty(pr)==False)
			pr->right = next;
	}
	return l;
}

int height(tree t) { // Finds the tree height
	if (isEmpty(t))
		return 0;
	else {
		int h1 = height(left(t));
		int h2 = height(right(t));
		if (h1 > h2)
		/*
		 * find the highest tree height, afterwars ads
		 * 1 for the root
		 * */
			return 1 + h1; 
		else
			return 1 + h2;
	}
}

tree CONSTREE(void* toel, int tipo, tree l, tree r) //Same as cons, but without a general element
{
    element el = build_element(toel, tipo); //Creates a general element
    tree tmp = consTree(el, l, r); //uses the actual constree function
    element_del(&el); //deletes the tmp element
    return tmp; //returns the new tree
}

boolean MEMBERTREE(void* toel, int tipo, tree t) //same as member tree, but without a general element
{
	boolean tmp;
	element el = build_element(toel, tipo);
    tmp = memberTree(el, t);
    element_del(&el);
    return tmp;
}

tree INSORDTREE(void* toel, int tipo, tree t) //like insord but withouta general element
{
    element el = build_element(toel, tipo);
    t = insordTree(el,t);
    element_del(&el);
    return t;
}

tree DELETEBST(void*toel, int tipo, tree t) //same as delete bst but without a general element
{
    element el = build_element(toel, tipo);
    t = deleteBST(el,t);
    element_del(&el);
    return t;
}

void free_node(tree n) //deletes a tree node forever
{
    element_del(&(n->value));
    free(n);
}
void delete_tree(tree t) //deletes the whole tree forever
{
    if(isEmpty(t)==True)
        return;
    delete_tree(left(t));
    delete_tree(right(t));
    free_node(t);
}

#include "UnivEl.h"
#include "Alberi.h"
element root(tree t)
{
  if(t == NULL)
    abort();
  return t->value;
}

boolean isEmpty(tree t)
{
 return t == NULL ? True : False;
}

tree left(tree t)
{
  return t == NULL ? NULL : t->left;
}

tree right(tree t)
{
  return t== NULL ? NULL : t->right;
}

tree consTree(element e, tree l, tree r)
{
  tree t = malloc(sizeof(node));
  t->value = copy_element(e);
  t->left = l;
  t->right = r;
  return t;
}


void preOrder(tree t)
{
  if(t!=NULL){
		printf("\t");
		printEl(root(t));
		preOrder(left(t));
		preOrder(right(t));
	}
	else
		printf("\t-"); //Niente figlio
}

void inOrder(tree t) //In ordine
{
	if (isEmpty(t)==False){
		inOrder(left(t));
		printf("\t");
		printEl(root(t));
		inOrder(right(t));
	}
	else
		printf("\t-"); //Niente figlio
}

void postOrder(tree t) //Posticipato
{
	if (isEmpty(t)==False){
		postOrder(left(t));
		postOrder(right(t));
		printf("\t");
		printEl(root(t));
	}
	else
		printf("\t-"); //Niente figlio
}

boolean elementIsEqual(element e1, element e2)
{
  return cmp(&e1, &e2) == 0 ? True : False;
}

boolean memberTree(element e, tree t)
{
  return t == NULL ? False : (cmp(&e, &(t->value)) == 0 ? True : (memberTree(e, t->left) || memberTree(e, t->right)));
}

boolean memberOrdTree(element e, tree t)
{
  int confronto;
  while(t != NULL){
    confronto = cmp(&e, &(t->value));
    if(confronto == 0)
      return True;
    else if(confronto < 0)
      t = t->left;
    else
      t = t->right;
  }
  return False;
}

tree copyTree(tree t)
{
  if(isEmpty(t)==True)
    return NULL;
  return consTree(root(t), copyTree(left(t)), copyTree(right(t)));
}

void ContaDominanti(tree t, int* n)
{
	int c;
	if (left(t) == NULL && right(t) == NULL)
		return;
	if(left(t) != NULL){
		ContaDominanti(left(t), n);
		c = element_value(&(t->value)) - element_value(&(t->value));
	}
	if (right(t) != NULL) {
		ContaDominanti(right(t), n);
		if (!(c < 0)) {
			c = c - element_value(&t->value);
		}
	}
	if(c > 0)
		(*n)++;
}

int numerofoglie(tree t)
{
	if (isEmpty(t) == True)
		return 0;
		
	boolean empty_left = isEmpty(left(t));
	boolean empty_right = isEmpty(right(t));
	
	if (empty_left == True && empty_right == True)
		return 1;
	else if (empty_left == False && empty_right == False)
		return  numerofoglie(left(t)) + numerofoglie(right(t));
	else if (empty_left == True && empty_right == False)
		return  numerofoglie(right(t));
	else if (empty_left == False && empty_right == True)
		return  numerofoglie(left(t));
}

boolean isBigger(element a, element b)
{
	if(cmp(&a,&b)>0)
		return True;
	else
		return False;
}

boolean isEqual(element a, element b)
{
	if(cmp(&a,&b) == 0)
		return True;
	else
		return False;
}

boolean isLess(element a, element b)
{
	if(cmp(&a,&b) < 0)
		return True;
	else
		return False;
}


tree insordTree(element e, tree t) //Aggiunge l'elemento, rispettando l'ordine dell'albero bin di ric
{
	if (isEmpty(t) == True)
		return consTree(e, emptyTree(), emptyTree());
	else
		if (isLess(e, root(t)) == True || isEqual(e, root(t)) == True)
			return consTree(root(t), insordTree(e, left(t)), right(t));
		else
			return consTree(root(t), left(t), insordTree(e, right(t)));
}

void BstMaxToMin(tree t)
{
	if (t != NULL){
		BstMaxToMin(right(t));
		printf("\n");
		printEl(root(t));
		BstMaxToMin(left(t));
	}
}

void BstMinToMax(tree t)
{
	if (t != NULL){
		BstMinToMax(left(t));
		printf("\n");
		printEl(root(t));
		BstMinToMax(right(t));
	}
}

tree deleteBST(element e, tree t) {
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
		// Il nodo da eliminare � una foglia
		if (isEmpty(left(t))==True && isEmpty(right(t))==True) {
                        
			if (t == l){
                            free_node(t);
				return emptyTree();
                        }
                        free_node(t);
			next = emptyTree();
		}
		else {
			// Il nodo da eliminare ha un solo figlio
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
					// Il nodo da eliminare ha due figli
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

int height(tree t) {
	if (isEmpty(t))
		return 0;
	else {
		int h1 = height(left(t));
		int h2 = height(right(t));
		if (h1 > h2)
			return 1 + h1;
		else
			return 1 + h2;
	}
}

tree CONSTREE(void* toel, int tipo, tree l, tree r)
{
    element el = build_element(toel, tipo);
    tree tmp = consTree(el, l, r);
    element_del(&el);
    return tmp;
}

tree INSORDTREE(void* toel, int tipo, tree t)
{
    element el = build_element(toel, tipo);
    t = insordTree(el,t);
    element_del(&el);
    return t;
}

tree DELETEBST(void*toel, int tipo, tree t)
{
    element el = build_element(toel, tipo);
    t = deleteBST(el,t);
    element_del(&el);
    return t;
}

void free_node(tree n)
{
    element_del(&(n->value));
    free(n);
}
void delete_tree(tree t)
{
    if(isEmpty(t)==True)
        return;
    delete_tree(left(t));
    delete_tree(right(t));
    free_node(t);
}

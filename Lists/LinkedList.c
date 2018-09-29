#include "UnivLL.h"


list cons(element e, list l)
{
	list t = malloc(sizeof(item));
	//t->value = e;
	t->value = copy_element(e);
	t->next = l;
	return t;
}
/*list tail(list l)
{
	return l->next;
}

element head(list l)
{
	return l->value;
}

BOOL empty(list l)
{
	return (l) == NULL ? True : False;
}

list emptylist()
{
	return NULL;
}*/

list append(list l1,list l2)
{
	list root = l1;
	if(l1 == NULL)
		return l2;
	else{
		while(l1->next != NULL)
			l1 = l1->next;
		l1->next = l2;
		return root;
	}
}

list append_element(element e, list l)
{
	if (l == NULL)
		return cons(e, l);
	list tmp = cons(e, NULL);
	return append(l, tmp);
}

void pop(list l, size_t element_n)
{
	//non serve lo 0, poichè è un semplice tail + cancellazione!!!
	if(element_n > length(l)){
		fprintf(stderr, "Tryng to delete an element outside the list!");
		abort();
	}
  for(size_t i = 0; i < element_n; i++)
    l = l->next;
  list cancellable = l->next;
  l->next = cancellable->next;
  item_del(cancellable);
}

void showlist(list l)
{
    if(l == NULL)
        printf("Empty list!\n");
    printf("[ ");
    while(l != NULL){
        printEl((l->value));
	printf(" ");
        l = l->next;
    }
    printf("]\n");
}

size_t length(list l)
{
	size_t i = 0;
	while(l != NULL){
		i++;
    l = tail(l);
  }
	return i;
}

element getElement(list l, size_t element_n)
{
	for(size_t i = 0; i < element_n; i++){
		if(l->next == NULL){
      fprintf(stderr, "%s\n","Cercato di leggere oltre il limite della lista!" );
			abort();
    }
		l = l->next;
	}
	return head(l);
}

element last(list l)
{
	while(tail(l) != NULL)
		l = l->next;
	return head(l);
}

BOOL isBigger(element a, element b)
{
	if(cmp(&a,&b)>0)
		return True;
	else
		return False;
}

BOOL isEqual(element a, element b)
{
	if(cmp(&a,&b) == 0)
		return True;
	else
		return False;
}

BOOL isLess(element a, element b)
{
	if(cmp(&a,&b) < 0)
		return True;
	else
		return False;
}


list insord(element e, list l)
{
	if (empty(l) == True)
		return cons(e, l);
	list prev=emptylist();
	list root = l;
	while (l != NULL) {
		if (isBigger(head(l), e) == True || isEqual(head(l),e)==True) {
			l = cons(e, l);
			if (prev == NULL)
				return l;
			prev->next = l;
			return root;
		}
		prev = l;
		l = l->next;
	}
	return append_element(e, root);
}
//Laboratorio 7
list intersect(list l1, list l2)
{
	list root = l2;
	list l3 = emptylist();
	if (l2 == NULL)
		return l3;
	while(l1 != NULL){
		if (ricerca(head(l1), l2) != -1 && ricerca(head(l1), l3) == -1)
			l3 = append_element(head(l1), l3);
		l1 = tail(l1);
	}
	return l3;
}

void list_del(list l)
{
	list fin;
	while(l != NULL){
		fin = l;
		l = tail(l);
		item_del(fin);
	}
}

size_t ricerca(element e, list l)
{
	if (l == NULL)
		return error;
	size_t  i = 0;
	do {
		if (isEqual(e, l->value))
			return i;
		i++;
		l = l->next;
	} while (l != NULL);
	return error;
}

list difference(list l1, list l2)
{
	list root = l2;
	list l3 = NULL;
	if (l2 == NULL)
		return l3;
	while (l1 != NULL) {
		if (ricerca(l1->value, l2) == -1 && ricerca(l1->value, l3) == -1)
			l3 = append_element(l1->value, l3);
		l1 = l1->next;
	}
	return l3;
}

element maxelement(list l)
{
	element x;
    BOOL flag = False;
	while (l != NULL) {
		if (flag == False){
			x = copy_element(head(l));
            flag = True;
        }
		else if (isLess(x, l->value))
            element_del(&x);
			x = copy_element(head(l));
		l = tail(l);
	}
	return x;
}

void item_del(item* it)
{
	element_del(&(it->value));
	free(it);
}

void bubble_sort(list l)
{
	int swapped;
	list ptr1;
	list lptr = NULL;
	if (l == NULL)
		return;
	do
	{
		swapped = 0;
		ptr1 = l;

		while (ptr1->next != lptr)
		{
			if (isBigger(ptr1->value, ptr1->next->value) == True)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(list a, list b) // va miglioratore
{
	element tmp;
	memcpy(&tmp, &(a->value), sizeof(element));
	memcpy(&(a->value), &(b->value), sizeof(element));
	memcpy(&(b->value), &tmp, sizeof(element));
}

list CONS(void* toel, int tipo, list l)
{
    element el = build_element(toel, tipo);
    l = cons(el, l);
    //element_del(&el);
    return l;
}

list APPEND_ELEMENT(void* toel, int tipo, list l)
{
    element el = build_element(toel, tipo);
    l = append_element(el, l);
    element_del(&el);
    return l;
}

list INSORD(void* toel, int tipo, list l)
{
    element el = build_element(toel, tipo);
    l = insord(el, l);
    
    element_del(&el);
    return l;
}

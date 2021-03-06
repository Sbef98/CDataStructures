#include "LinkedList.h"


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

list behead(list l)
{
	if(l == NULL)
		return NULL;
	list tmp;
	tmp = l;
	l = tail(l);
	item_del(tmp);
	return l;
}

void pop(list l, size_t element_n)
{
	if(element_n == 0){
		fprintf(stderr, "Cannot delete element 0. Use behead instead of pop");
	}
	if(element_n > length(l)){
		fprintf(stderr, "Tryng to delete an element outside the list!");
		abort();
	}
  for(size_t i = 0; i < element_n - 1; i++)
    l = l->next;
  list cancellable = l->next;
  l->next = cancellable->next;
  item_del(cancellable);
}

void showlist(list l)
{
    if(l == NULL){
        printf("Empty list!\n");
	return;
    }
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
      fprintf(stderr, "%s\n","The list ended already!" );
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

int ricerca(element e, list l)
{
	if (l == NULL)
		return error;
	int  i = 0;
	do {
		if (isEqual(e, l->value))
			return i;
		i++;
		l = l->next;
	} while (l != NULL);
	return error;
}

list copy_list(list l)
{
	list l2 = emptylist();
	while (l != NULL) {
		l2 = append_element(head(l), l2);
		l = tail(l);
	}
	return l2;
}

list difference(list l1, list l2)
{
	if (l2 == NULL)
		return copy_list(l1);
	if (l1 == NULL)
		return copy_list(l2);
	list root = l2;
	list l3 = NULL;
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
	if(l == NULL)
	    fprintf(stderr,"Looking for max element in an empty list");
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

list deleteRepetition(list l)
//This function is not mine. i fixed it giving a brief look, but nothing more
{
	if(empty(l) == True)
		return emptylist();
	list root = l;
	while(empty(tail(l)) == false){
		int duplicate = ricerca(head(l), tail(l));
		if(duplicate == error)
			l = tail(l);
			//Controllare se si stia rimuovendo quello giusto
		else{
			if(duplicate == 0)
				l = behead(l);
			else
				pop(l, duplicate);
		}
	}
	return root;
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
	/*
	memcpy(&tmp, &(a->value), sizeof(element));
	memcpy(&(a->value), &(b->value), sizeof(element));
	memcpy(&(b->value), &tmp, sizeof(element));*/
	tmp.value = a->value.value;
	tmp.type = a->value.type;
	a->value.value = b->value.value;
	a->value.type = b->value.type;
	b->value.value = tmp.value;
	b->value.type = tmp.type;
}

list CONS(void* toel, int tipo, list l)
{
        list t = malloc(sizeof(item));
	t->value = build_element(toel, tipo);;
	t->next = l;
    	return t;
}

list APPEND_ELEMENT(void* toel, int tipo, list l)
{
    	if (l == NULL)
		return CONS(toel, tipo, l);
	list tmp = CONS(toel, tipo,  NULL);
	return append(l, tmp);
    	return l;
}

list INSORD(void* toel, int tipo, list l)
{
    element el = build_element(toel, tipo);
    l = insord(el, l);
    
    element_del(&el);
    return l;
}

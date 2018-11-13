#include "LinkedList.h"


list cons(element e, list l)
{
	list t = malloc(sizeof(item));
	t->value = copy_element(e);
	t->next = l;
	return t;
}
list tail(list l)
{
	return l->next;
}

element head(list l)
{
	return l->value;
}

bool empty(list l)
{
	if (l == NULL)
		return true;
	return false;
}

list emptylist()
{
	return NULL;
}

list append(list l1,list l2)
{
	list root = l1;
	if(empty(l1) == true)
		return l2;
	else{
		while(tail(l1) != NULL)
			l1 = tail(l1);
		l1->next = l2;
		return root;
	}
}

list append_element(element e, list l)
{
	if (empty(l) == true)
		return cons(e, l);
	list tmp = cons(e, NULL);
	return append(l, tmp);
}

list behead(list l)
{
	if(empty(l) == true)
		return NULL;
	list tmp;
	tmp = l;
	l = tail(l);
	item_del(tmp);
	return l;
}

void pop(list l, size_t element_n)
{
	if (element_n == 0)
	{
		fprintf(stderr, "To delete the first element use behead function!");
		abort();
	}

	if(element_n > llenght(l)){
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
    if(empty(l) == true)
        printf("\nEmpty list!\n");
	else {
		printf("[ ");
		while (l != NULL) {
			printEl(head(l));
			printf(" ");
			l = l->next;
		}
		printf("]\n");
	}
}

size_t llenght(list l)
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
		if(tail(l) == NULL){
			fprintf(stderr, "%s\n","The list already ended!" );
			abort();
		}
		l = l->next;
	}
	return head(l);
}

element last(list l)
{
	while(tail(l) != NULL)
		l = tail(l);
	return head(l);
}

bool isBigger(element a, element b)
{
	if(cmp(&a,&b) > 0)
		return true;
	else
		return false;
}

bool isEqual(element a, element b)
{
	if(cmp(&a,&b) == 0)
		return true;
	else
		return false;
}

bool isLess(element a, element b)
{
	if(cmp(&a,&b) < 0)
		return true;
	else
		return false;
}


list insord(element e, list l)
{
	if (empty(l) == true)
		return cons(e, l);
	list prev=emptylist();
	list root = l;
	while (l != NULL) {
		if (isBigger(head(l), e) == true || isEqual(head(l),e)==true) {
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

list intersect(list l1, list l2)
{
	list root = l2;
	list l3 = emptylist();
	if (empty(l2) == true)
		return l3;
	while(empty(l1) == false){
		if (search(head(l1), l2) != -1 && search(head(l1), l3) == -1)
			l3 = append_element(head(l1), l3);
		l1 = tail(l1);
	}
	return l3;
}

void list_del(list l)
{
	list fin;
	while(empty(l)){
		fin = l;
		l = tail(l);
		item_del(fin);
	}
}

int search(element e, list l)
{
	if (empty(l) == true)
		return error;
	size_t  i = 0;
	do {
		if (isEqual(e, l->value))
			return i;
		i++;
		l = tail(l);
	} while (l != NULL);
	
	//fprintf(stderr, "Element not present!");
	return error;
}

list copy_list(list l)
{
	list l2 = emptylist();
	while (empty(l) == true) {
		l2 = append_element(head(l), l2);
		l = tail(l);
	}
	return l2;
}

list difference(list l1, list l2)
{
	if (empty(l2) == true)
		return copy_list(l1);
	if (empty(l1) == true)
		return copy_list(l2);
	list root = l2;
	list l3 = NULL;
	while (empty(l1) == false) {
		if (search(head(l1), l2) == -1 && search(head(l1), l3) == -1)
			l3 = append_element(head(l1), l3);
		l1 = tail(l1);
	}
	return l3;
}

element maxelement(list l)
{
	element x;
    bool flag = false;
	while (l != NULL) {
		if (flag == false){
			x = copy_element(head(l));
            flag = true;
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

		while (tail(ptr1) != lptr)
		{
			if (isBigger(head(ptr1), head(tail(ptr1))) == true)
			{
				swap(ptr1, tail(ptr1));
				swapped = 1;
			}
			ptr1 = tail(ptr1);
		}
		lptr = ptr1;
	} while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(list a, list b) // va miglioratore
{
	element tmp;
	tmp.value = a->value.value;
	tmp.type = a->value.type;
	a->value.value = b->value.value;
	a->value.type = b->value.type;
	b->value.value = tmp.value;
	b->value.type = tmp.type;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


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

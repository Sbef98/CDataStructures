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
	if (element_n == 0)														//This function cannot delete the first element because it doesn't have return, so we would lost all the list;
	{
		fprintf(stderr, "To delete the first element use behead function!");
		abort();
	}

	if(element_n > llenght(l)){
		fprintf(stderr, "Tryng to delete an element outside the list!");
		abort();
	}
  for(size_t i = 0; i < element_n - 1; i++)
    l = tail(l);															//The l pointer is incremented untill it points to the item before the item to delete;		
  list cancellable = tail(l);												//the pointer to the next item of list l, the item to delete, is saved in "cancellable" variable;
  l->next = tail(cancellable);												//The pointer to the next element of list l, is set to the next item of cancellable; the list l is now not linked to the item to delete;
  item_del(cancellable);													//The element to delete is deleted;
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
		l = tail(l);
	}
	return head(l);
}

element last(list l)
{
	while(empty(tail(l)) == false)
		l = tail(l);
	return head(l);
}

list insord(element e, list l)
{
	if (empty(l) == true)													//If the list is empty, the function add the element at the head of the lists;
		return cons(e, l);
	list prev = emptylist();												//prev is a pointer to the previous item, it points to the item before the item pointed by l;
	list root = l;
	while (empty(l) == false) {												//While list l is not empty:
		if (isBigger(head(l), e) == true || isEqual(head(l),e) == true) {		//If the element to add is bigger or equal at the element in the item pointed by l;
			l = cons(e, l);															//The function insert the element e at the head of list l;
			if (prev == NULL)														//If l points to the firts item of the list, no more operations needed:
				return l;																//So l pointer is returned;
			prev->next = l;															//Else, if l was not pointing the first item of the list, the item before l, pointed by prev, is linked to the new item created now pointed by l;
			return root;																//The first item of the list is returned;
		}
		prev = l;																//We need to explore the next element, so prev is set pointing l;											
		l = l->next;															//Then l is incremented pointing to next item;
	}
	return append_element(e, root);											//If any element present in the items of the list l are bigger than the element e, the element to add is copied into an item linked at the end of the list; 
}

list intersect(list l1, list l2)
{
	list l3 = emptylist();													//Is created a new list l3, this is the list that will be returned;
	if (empty(l2) == true)													//If l2 is an empty list, is impossible to have element in common with it, so a empty list is returned;
		return l3;
	while(empty(l1) == false){												//While l1 is not an empy list:				
		if (search(head(l1), l2) != -1 && search(head(l1), l3) == -1)			//If is found the element in the item pointed by l1 in l2, and it is not already present in the new list l3: 
			l3 = append_element(head(l1), l3);										//The element in the item pointed by l1 is added to l3;
		l1 = tail(l1);															//l1 is incremented, now it points to the next item of the list;
	}
	return l3;																//l3 is returned;
}

void list_del(list l)
{
	list toDelete;
	while(empty(l)){
		toDelete = l;
		l = tail(l);
		item_del(toDelete);
	}
}

int search(element e, list l)
{
	if (empty(l) == true)
		return error;
	size_t  i = 0;
	while (empty(l) == false)
	{
		if (isEqual(e, head(l)))
			return i;
		i++;
		l = tail(l);
	}	
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
	if (empty(l2) == true)													//If one of the lists is empty, there are not item to delete in the other, so the difference is a copy of the other list;							
		return copy_list(l1);
	if (empty(l1) == true)
		return copy_list(l2);
	list root = l2;
	list l3 = emptylist();
	while (empty(l1) == false) {											//For each item of l1:
		if (search(head(l1), l2) == -1 && search(head(l1), l3) == -1)			//If the element in the item pointed by l1 is not present in l2 and is not already added in l3:
			l3 = append_element(head(l1), l3);										//Than insert at the end of l3 a copy of the item pointed by l1;
		l1 = tail(l1);
	}
	return l3;
}

element maxelement(list l)
{
	if (empty(l) == true)
	{
		fprintf(stderr, "\nEmpty list, impossible to find the max element;\n");
		abort();
	}
	element max = copy_element(head(l));									//Variable max is set with the first element of the list;
	while (empty(l) == false) {												//Untill are checked all the elements list:
		if (isLess(max, head(l)))												//If the element in the item pointed by l is bigger than element in my max variable:
		{
			element_del(max);														//Max is updated with the element in the item pointed by l;
			max = copy_element(head(l));
		}
		l = tail(l);
	}
	return max;
}

void item_del(item* it)
{
	element_del(head(it));
	free(it);
}

list NoRepetition(list l)
{
	if (empty(l) == true)
		return emptylist();
	
	list root = l;
	while (empty(tail(l)) == false)											//Untill it has checked all the elements before the last of the list:
	{
		int duplicate = search(head(l), tail(l));							
		if (duplicate != -1)													//If there is a duplicate:																										//If it is in the first position:							
			pop(l, duplicate + 1);													//Deletes it with pop function;
		else																	//If there are no more duplicates of that element:
			l = tail(l);															//Check for duplicates of the next element;
	}
	return root;															//Return root;
}

void bubble_sort(list l)
{
	bool inorder;
	list ptr1;
	list lptr = emptylist();
	if (empty(l) == true)
		return;
	do
	{
		inorder = true;														//I choose to consider the list alredy in order;
		ptr1 = l;

		while (tail(ptr1) != lptr)											//While it has not checked all the element of the list untill lptr:
		{
			if (isBigger(head(ptr1), head(tail(ptr1))) == true)					//If one single pair of element are not in orde:
			{
				swap(ptr1, tail(ptr1));												//It swap these elements;
				inorder = false;													//And set the inorder flag to false, it cannot still say the list is in order;
			}
			ptr1 = tail(ptr1);													//ptr1 is incremented to check the next pair of element;
		}
		lptr = ptr1;														//lptr is set to ptr1, to exclude the last element of the list, that surely is the maximum value of the whole list;
	} while (inorder == false);											//Do these operations untill the list is not in order;
}

void swap(list a, list b)
{
	element tmp;
	tmp.value = head(a).value;
	tmp.type = head(a).type;
	a->value.value = head(b).value;
	a->value.type = head(b).type;
	b->value.value = tmp.value;
	b->value.type = tmp.type;
}

/*-----------------------------Fuzioni speciali-----------------------------------------------------------------------------------------------------------------------------------------------------*/


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
    element_del(el);
    return l;
}

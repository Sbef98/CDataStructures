#define _CRT_SECURE_NO_WARNINGS
#ifndef UNIVLL_H
#define UNIVLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UnivEl.h"

struct list_element {
  element value;
  struct list_element *next;
};
typedef struct list_element item;
typedef struct list_element *list;

extern list cons(element e, list l);						//Creates an item and puts it at the head of the list
extern list tail(list l);									//Return a pointer to the next item of the list;
extern element head(list l);								//Returns the element restrained in the item pointed by l;
extern bool empty(list l);									//Returns true if l is an empty list, otherwise false ;
extern list emptylist();									//Creates an empty list;

extern list append (list l1, list l2);						//concatenates 2 lists
extern list append_element(element e, list l);				//adds an element at the end of the list 
extern list behead(list l);									//removes the first item of the list, deleting the element and returning the new list;
extern void pop(list l, size_t element_n);					//removes the element at element_n position from the list, first element of the list is element_n = 0, this function doesn't work with the first element of the list;
extern void showlist(list l);								//prints the whole list;
extern size_t llenght(list l);								//Tells how long is the list, how many items are linked;
extern element getElement(list l, size_t element_n);		//retuns the element in element_n posistion, first element of the list is element_n = 0;
extern element last(list l);								//returns the last element;

extern list insord(element e, list l);						//Insert an element keeping the list in increasing order 
extern list intersect(list l1, list l2);					//returns a list made of elements available in both lists;
extern void list_del(list l);								//Deletes a list;
extern int search(element e, list l);						//"research", finds an element inside a list telling its position, if the element is not present in the list it returns -1;
extern list difference(list l1, list l2);					//Returns a list of elements that are not in common;
extern list copy_list(list l);
extern element maxelement(list l);							//returns the biggest element;
extern void item_del(item* it);								//Deletes a list item;
extern list NoRepetition(list l);							//Returns the list without duplicates, keeps the element at the first found position;
extern void bubble_sort(list a);							//Orders the list in increasing order;
extern void swap(list a, list b);

extern list CONS(void* toel, int type, list l);				//same as cons, no need to have already an existing element;
extern list APPEND_ELEMENT(void* toel, int type, list l);	//same as the one before, no need for a preexisting element;
extern list INSORD(void* toel, int tipo, list l);			//Creates an element, and inserts it an item linked in the list without breack the increasing order;

#endif /*UNIVLL_H*/

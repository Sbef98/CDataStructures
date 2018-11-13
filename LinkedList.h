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

extern list cons(element e, list l);  //Creates a item and puts it at the head of the list
extern list CONS(void* toel, int type, list l); //same as cons, no need to have a already existing element
extern list tail(list l);
extern element head(list l);
extern bool empty(list l);
extern list emptylist();

extern list append (list l1, list l2);  //concatenate 2 lists
extern list append_element(element e, list l);//adds an element at the end of the list 
extern list APPEND_ELEMENT(void* toel, int type, list l); //same as the one before, no need for a preexisting element
extern list behead(list l); //let's kill the hydra'
extern void pop(list l, size_t element_n);  //removes the element at element_n position from the list, first element of the list is element_n = 0, this function doesn't work with the first element of the list;
extern void showlist(list l); //prints the whole list
extern size_t llenght(list l); //Tells how long is the list, how many items are linked
extern element getElement(list l, size_t element_n);  //retuns the element in element_n posistion, first element of the list is element_n = 0;
extern element last(list l); //returns the last element
extern bool isBigger(element a, element b);  //
extern bool isEqual(element a, element b);  
extern bool isLess(element a, element b);  //
extern list insord(element e, list l);  //Insert an element keeping the list in order 
extern list INSORD(void* toel, int tipo, list l); 
extern list intersect(list l1, list l2); //RETURNS A LIST MADE OF elements available in both lists
extern void list_del(list l); //Deletes a list
extern int search(element e, list l); //"research", finds an element inside a list telling its position
extern list difference(list l1, list l2); //Returns a list of elements that are not in common
extern list copy_list(list l);
extern element maxelement(list l); //returns the biggest element
extern void item_del(item* it); //Deletes a list item
extern void bubble_sort(list a); //why not merge sort or quick sort? i like bubbles. who doesn't.'
extern void swap(list a, list b);
#endif /*UNIVLL_H*/

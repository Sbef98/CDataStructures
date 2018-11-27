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


typedef char BOOL;
#define error -1
#define True 1
#define False 0

extern list cons(element e, list l);  //Puts the element as the first list's item'
extern list CONS(void* toel, int type, list l); //same as cons, no need to have a already existing element
//extern list tail(list l);  //ok
#define tail(/*list*/ l) 	(*(l)).next// Returns the remaining part of the list
//extern element head(list l);  //ok
#define head(/*list*/ l) (*(l)).value// Returns the first element of the list
//extern BOOL empty(list l);  //ok
#define empty(/*list*/ l) (l) == NULL ? True : False//Tells if a list is empty
//extern list emptylist();  //ok
#define emptylist() NULL //an empty list
extern list append (list l1, list l2);  //concatenate 2 lists
extern list append_element(element e, list l);//adds an element at the end of the list 
extern list APPEND_ELEMENT(void* toel, int type, list l); //same as the one before, no need for a preexisting element
extern list behead(list l); //let's kill the hydra'
extern void pop(list l, size_t element_n);  //removes an element from the list
extern void showlist(list l); //prints the whole list
extern void printEl(element e);//defined in univel.h
/*void print_list(list l)
{
    if(l == NULL)
        printf("Empty list!\n");
    printf("[ ");
    while(l != NULL){
        printf("%i ", head(l));
        l = l->next;
    }
    printf("]\n");
}*/
  
extern size_t length(list l); //Tells how long is the list
extern element getElement(list l, size_t element_n);  //retuns the element in element_n posistion 
extern element last(list l); //returns the list ending
extern BOOL isBigger(element a, element b);  //
extern BOOL isEqual(element a, element b);  
extern BOOL isLess(element a, element b);  //
extern list insord(element e, list l);  //Insert an element keeping the list in order 
extern list INSORD(void* toel, int tipo, list l); 
extern list intersect(list l1, list l2); //RETURNS A LIST MADE OF elements available in both lists
extern void list_del(list l); //Deletes a list
extern int ricerca(element e, list l); //"research", finds an element inside a list telling its position
extern list difference(list l1, list l2); //Returns a list of elements that are not in common
extern list copy_list(list l);
extern element maxelement(list l); //returns the biggest element
extern void item_del(item* it); //Deletes a list item
extern void bubble_sort(list a); //why not merge sort or quick sort? i like bubbles. who doesn't.'
extern void swap(list a, list b);
extern list deleteRepetition(list l);
#endif /*UNIVLL_H*/

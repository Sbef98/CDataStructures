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

extern list cons(element e, list l); //ok
extern list CONS(void* toel, int type, list l);
//extern list tail(list l);  //ok
#define tail(/*list*/ l) 	(*(l)).next//CONTROLLA
//extern element head(list l);  //ok
#define head(/*list*/ l) (*(l)).value//CONTROLLA
//extern BOOL empty(list l);  //ok
#define empty(/*list*/ l) (l) == NULL ? True : False//CONTROLLA
//extern list emptylist();  //ok
#define emptylist() NULL //CONTROLLA
extern list append (list l1, list l2);  //ok
extern list append_element(element e, list l);//ok
extern list APPEND_ELEMENT(void* toel, int type, list l);
extern list behead(list l);
extern void pop(list l, size_t element_n);  //ok
extern void showlist(list l); //ok
extern void printEl(element e);//da definire esternamente
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
  
extern size_t length(list l); //ok 
extern element getElement(list l, size_t element_n);  //ok
extern element last(list l); //ok
extern BOOL isBigger(element a, element b);  //ok
extern BOOL isEqual(element a, element b);  //ok
extern BOOL isLess(element a, element b);  //ok
extern list mergord(list l);  //ok
extern list merge(list left, list right);  //ok
extern list insord(element e, list l);  //ok
extern list INSORD(void* toel, int tipo, list l);
extern list intersect(list l1, list l2); //ok
extern void list_del(list l); //ok
extern size_t ricerca(element e, list l); //ok
extern list difference(list l1, list l2); //ok
extern element maxelement(list l); //ok
extern void item_del(item* it); //ok
extern int cmp(element* a, element* b); //da definire nel h
extern void element_del(element *e); //da definire esternamente
extern void bubble_sort(list a);
extern void swap(list a, list b); // va migliorato
//Poi di definiti  esternamente (ed ovviamente) c'è copy element!
#endif /*UNIVLL_H*/

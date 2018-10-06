#if !defined HEAP_H
#define HEAP_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//#include "element.h"

extern int left(int); //finds the left son
extern int right(int); //finds the right son
extern void scambia(int*, int*); //"SWAP"
extern void heapify(int*, int, int); //makes everything happy (idk)
extern void build_heap(int*, int); //builds a heap
extern void heapsort(int*, int); //sorts the heap
//extern int riempivettore(int*); 
//extern void stampavettore(int*);
extern int Parent(int); //Finds the parent
extern void MoveUp(int*, int, int); //brings the node up until it finds its right place

#endif

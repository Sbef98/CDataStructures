#if !defined HEAP_H
#define HEAP_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//#include "element.h"

extern int left(int);
extern int right(int);
extern void scambia(int*, int*);
extern void heapify(int*, int, int);
extern void build_heap(int*, int);
extern void heapsort(int*, int);
extern int riempivettore(int*);
extern void stampavettore(int*);
extern int Parent(int);
extern void MoveUp(int*, int, int);

#endif
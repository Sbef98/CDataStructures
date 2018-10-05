#include "heap.h"
#define MAX 50

//Heap_size � il numero di elementi escluso lo 0 iniziale (0, 2, 5, 3, 6, 9): 5

int left(int i)
{
	return 2 * i;
}

int right(int i)
{
	return 2 * i + 1;
}

void scambia(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void heapify(int *A, int i, int heap_size) //Node move down 
{

	int l, r, largest;
	l = left(i); //I's left son index'
	r = right(i);//I's right son index'

	largest = i; //Setting position I as default value

	if ((l <= heap_size) && (A[l] > A[i])) //If i has left son and the right one is > father i
		largest = l; //Setting largest at l

	if ((r <= heap_size) && (A[r] > A[largest]) && A[r] > A[largest])//If i has right son adn right son is > father i
		largest = r; //setting r as largest


	if (largest != i) { //if largest changed
		scambia(&A[i], &A[largest]); //swap father with son's value'
		heapify(A, largest, heap_size); //executing the function again until largest = i
	}
	return;
}

void build_heap(int *A, int heap_size) //Builds a heap from a tree
{
	int i;
	for (i = heap_size / 2; i >= 1; i--) //Setting i at half tree, keep on until i = 1
		heapify(A, i, heap_size);
	return;
}

void heapsort(int *A, int dim) //sorting the heap from the lowest to the biggest
{
	int i, heap_size;

	heap_size = dim;

	for (i = dim; i >= 2; i--) {
		scambia(&A[1], &A[i]);
		heapify(A, 1, --heap_size);
                //heapify(A,i,1);
                //MoveUp(A,A[i],dim);
	}
	return;
}

int riempivettore(int *A)
{
	int i;
	for (i = 1; i < MAX; i++)
		A[i] = MAX - i;

	return MAX - 1;
}

void stampavettore(int *A)
{
	int i;
	printf("\n");
        printf("Lunghezza vettore: %d\n", A[0]);
	for (i = 1; i <= A[0]; i++)
		printf(" %d", A[i]);

	return;
}

int Parent(int i) 
{
	return i / 2;
}

void MoveUp(int *A, int i, int heap_size) {

	while (i != 1 && A[i] > A[Parent(i)]) {
		scambia(&A[i], &A[Parent(i)]);
		i = Parent(i);
	}
}

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

void heapify(int *A, int i, int heap_size) //Move down di un nodo
{

	int l, r, largest;
	l = left(i); //Indice del figlio sx di i
	r = right(i);//Indice del figlio dx di i

	largest = i; //Setto come valore di default i (posizione)

	if ((l <= heap_size) && (A[l] > A[i])) //Se i ha figlio sx e se figlio sx > padre i
		largest = l; //Setto largest ad l

	if ((r <= heap_size) && (A[r] > A[largest]) && A[r] > A[largest])//Se i ha figlio dx e se figlio dx > padre i
		largest = r; //Setto largest ad r


	if (largest != i) { //Se largest � cambiato
		scambia(&A[i], &A[largest]); //Scambio i valori del padre con il figlio
		heapify(A, largest, heap_size); //Rieseguo la funzione in modo ricorsivo, fino a quanto largest == i
	}
	return;
}

void build_heap(int *A, int heap_size) //Costruisce una code heap da albero
{
	int i;
	for (i = heap_size / 2; i >= 1; i--) //Setto i a met� dell'albero, e continuo fino ad i = 1
		heapify(A, i, heap_size);
	return;
}

void heapsort(int *A, int dim) //Ordina la heap in ordine crescente
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
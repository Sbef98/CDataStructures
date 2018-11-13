#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
#include "LinkedList.h"

int main(void)
{
	// Testing library with numeric data type
	int x = 5, b = 6, c = 7;
	list int_list = CONS(&x, int_element, emptylist());
	APPEND_ELEMENT(&b, int_element, int_list);
	INSORD(&c, int_element, int_list);

	int_list = behead(int_list);
	showlist(int_list);
	pop(int_list, 1);
	showlist(int_list);
	list vector = emptylist();

	for (size_t i = 0; i < 10; ++i)
	{
		element tmp = build_element(&i, int_element);
		vector = cons(tmp, vector);
		element_del(&tmp);
	}
	showlist(vector);
	bubble_sort(vector);
	showlist(vector);
	showlist(intersect(int_list, vector));
	if (llenght(intersect(int_list, vector)) == 1)
		printf("\nintersect ok\n");
	showlist(difference(vector, int_list));
	list none = difference(vector, copy_list(vector));
	showlist(none);
	if (empty(none) == true)
		printf("\ndifference and copy_list ok\n");
	showlist(intersect(emptylist(), emptylist()));

	int number = 4;
	element tosearch = build_element(&number, int_element);
	int n = search(tosearch, vector);
	element found = getElement(vector, n);
	if (isEqual(tosearch, found) == true)
		printf("\nsearch and getElement ok\n");
	int ultimo = get_int(last(vector));
	int max = get_int(maxelement(vector));
	if (ultimo == 9 && max == ultimo)
		printf("\nlast and maxelement ok\n");
	item_del(int_list);
	//end of numeric data test
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
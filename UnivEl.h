#define _CRT_SECURE_NO_WARNINGS
#ifndef UNIVEL_H
#define UNIVEL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ushort unsigned short
#define uchar unsigned char
#define uint unsigned int
#define error -1

enum types{ 	//add your types to this list
  char_element,
  uchar_element,
  ushort_element,
  short_element,
  uint_element,
  int_element,
  float_element,
  double_element,
  string_element,
  persona_element,
};

typedef struct{
	void* value;	//where the actual variable will be stored
	int type; 		//Type of element, like char_element
} element;

typedef struct{
	char* s;
	size_t len;
} string;

typedef struct { //an example of addable new data type
    char Nome [20];
    char CF [17];
    char Referto [100];
    int CodiceAccesso;
} Persona;


extern element build_element(void* el, int tipo);	//Allocates memory for an element;
extern void element_del(element e);					//Deallocates element;
extern void printEl(element e);						//Prints the element using printf function;
extern int cmp(element* a, element* b);				//Dynamic compare function
extern bool isBigger(element a, element b);			//Returns true if a > b false otherwise;
extern bool isEqual(element a, element b);			//Returns true if a = b false otherwise;
extern bool isLess(element a, element b);			//Returns true if a < b false otherwise;

#define copy_element(/*element*/ el)	build_element((el).value, (el).type)
extern int element_value(element* e);				//the absolute value of an element. This way, it's possible to confront diferent data types;

#define get_int(e) *((int*)((e).value))				//Returns the value of the data of an element;
#define get_float(e) *((float*)((e).value))			
#define get_double(e) *((double*)((e).value))
#define get_uint(e) *((uint*)((e).value))
#define get_short(e) *((short*)((e).value))
#define get_ushort(e) *((ushort*)((e).value))
#define get_char(e) *((char*)((e).value))
#define get_uchar(e) *((uchar*)((e).value))
#define get_string(e) *((string*)((e).value))

/*		Special Elements
	(link here your functions)		*/

extern void str_del(string str);
extern string string_append(char* add_str, string str);
extern string build_string(char* str_in, size_t len);
extern string* string_copy(void* str_in);

extern Persona build_persona(char* nome, char* cf, char* referto, int codiceAccesso);

#endif /*EL_H*/

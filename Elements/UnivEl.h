#define _CRT_SECURE_NO_WARNINGS
#ifndef UNIVEL_H
#define UNIVEL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ushort unsigned short
#define uchar unsigned char
#define uint unsigned int

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
  persona_element;
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

extern element build_element(void* el, int tipo); 
/*Do you wat to convert your variable to a element?
 * are u lazy to do it by yourself?
 * Pick this function!
 * for example: 
 * int c = 3;
 * element new_el = build_element(&c, int_element);
 */
extern void element_del(element *e); //deallocates and element
extern int cmp(element* a, element* b); //it's like 'a-b'
extern void printEl(element e);
#define copy_element(/*element*/ el)	build_element((el).value, (el).type)
extern int element_value(element* e); //the absolute value of an element. This way, it's possible to confront diferent data types

				/*
		Special Elements 
	(link here your functions)
				*/
extern void str_del(string str);
extern string string_append(char* add_str, string str);
extern string build_string(char* str_in, size_t len);
extern string* string_copy(void* str_in);
extern Persona build_persona(char* nome, char* cf, char* referto, int codiceAccesso);
#endif /*EL_H*/

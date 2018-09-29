#define _CRT_SECURE_NO_WARNINGS
#ifndef UNIVEL_H
#define UNIVEL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ushort unsigned short
#define uchar unsigned char
#define uint unsigned int

enum types{
  char_element,
  uchar_element,
  ushort_element,
  short_element,
  uint_element,
  int_element,
  float_element,
  double_element,
  string_element,
};

typedef struct{
	void* value;
	int type;
} element;

typedef struct{
	char* s;
	size_t len;
} string;
typedef struct {
    char Nome [20];
    char CF [17];
    char Referto [100];
    int CodiceAccesso;
} Persona;
extern element build_element(void* el, int tipo);
extern void element_del(element *e);
extern int cmp(element* a, element* b);
extern void printEl(element e);
#define copy_element(/*element*/ el)	build_element((el).value, (el).type)
extern int element_value(element* e);

				/*
		ELEMENTI SPECIALI
				*/
extern void str_del(string str);
extern string string_append(char* add_str, string str);
extern string build_string(char* str_in, size_t len);
extern string* string_copy(void* str_in);
extern Persona build_persona(char* nome, char* cf, char* referto, int codiceAccesso);
#endif /*EL_H*/

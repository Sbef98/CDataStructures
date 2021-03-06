#include "UnivEl.h"
/*
For any of these function, in case you need to add a new elements,
just define the needed functions at the end of this file.
Afterwars, add the needed case to each switch!!!
*/
element build_element(void* el, int tipo)
{
	element out;
	out.type = tipo;
	switch(tipo){
		case char_element:
		case uchar_element:
			out.value = malloc(sizeof(char));
			memcpy(out.value, el, sizeof(char));
			break;
		case short_element:
		case ushort_element:
			out.value = malloc(sizeof(short));
			memcpy(out.value, el, sizeof(short));
			break;
		case float_element:
			out.value = malloc(sizeof(float));
			memcpy(out.value, el, sizeof(float));
			break;
		case double_element:
			out.value = malloc(sizeof(double));
			memcpy(out.value, el, sizeof(double));
			break;
		case int_element:
		case uint_element:
			out.value =  malloc(sizeof(int));
			memcpy(out.value, el, sizeof(int));
			break;
		case string_element:
			out.value = string_copy(el);
			break;
		default:
			fprintf(stderr,"What do you want to make me build?\n Do you think you are jedi waving  your mouse?\nWrong types are not accepted, only right ones \n(or money)\n");
			break;
	}
	return out;
}
void element_del(element *e)
{
	switch(e->type){
		case string_element:
			str_del(*((string*)e->value));
			break;
		default:
			free(e->value);
			break;
	}
}

void printEl(element e)
{
	switch(e.type){
		case ushort_element:
			printf("%u", (*(unsigned short*)e.value));
			break;
		case uchar_element:
			printf("%u", (*(unsigned char*)e.value));
			break;
		case uint_element:
			printf("%u", (*(unsigned int*)e.value));
			break;
		case int_element:
			printf("%d", (*(int*)e.value));
			break;
		case char_element:
			printf("%d", (*(char*)e.value));
			break;
		case short_element:
			printf("%d", (*(short*)e.value));
			break;
		case float_element:
			printf("%f", (*(float*)e.value));
			break;
		case double_element:
			printf("%lf", (*(double*)e.value));
			break;
		case string_element:
			printf("%s", ((string*)e.value)->s);
			break;
		default:
			printf("IDK WHAT THE HELL IS THIS $*!t");
            break;
 	}
}

int cmp(element* a, element* b)
{
    if(a->type != b->type){
        fprintf(stderr, "Tentativo di confronto tra elementi di tipo differente! Errore!\n");
        abort();
    }
    int out;
    switch(a->type){
		case ushort_element:
            out = (int)(*((ushort*) (a->value)) - *((ushort*) (b->value)));
			break;
		case uchar_element:
            out = (int)(*((uchar*) (a->value)) - *((uchar*) (b->value)));
			break;
		case uint_element:
            out = (int)(*((uint*) (a->value)) - *((uint*) (b->value)));
			break;
		case int_element:
            out = (int)(*((int*)(a->value)) - *((int*)(b->value)));
			break;
		case char_element:
            out = (int)(*((char*)(a->value)) - *((char*)(b->value)));
			break;
		case short_element:
            out = (int)(*((short*)(a->value)) - *((short*) (b->value)));
			break;
		case float_element:
						if( get_float((*a)) - get_float((*b)) < 0)
							out = -1;
						else
							out = get_float(*a) -get_float(*b) == 0 ? 0 : 1;
			break;
		case double_element:
            if(get_double(*a) - get_double(*b) < 0)
							out = -1;
						else
							out = get_double(*a) - get_double(*b) == 0 ? 0 : 1;
			break;
		case string_element:
			out = (int)strcmp(((string*)a->value)->s, ((string*)b->value)->s);
			break;
		default:
			printf("Unknow type inserted!");
            abort();
            break;
	}
	return out;
}

int element_value(element* e)
{   //fa cagare sta funzione e non ho idea del perchè io l'abbia creata
	int out;
    switch(e->type){
		case ushort_element:
            out = (int)(*((ushort*) (e->value)));
			break;
		case uchar_element:
            out = (int)(*((uchar*) (e->value)));
			break;
		case uint_element:
            out = (int)(*((uint*) (e->value)));
			break;
		case int_element:
            out = (int)(*((int*)(e->value)));
			break;
		case char_element:
            out = (int)(*((char*)(e->value)));
			break;
		case short_element:
            out = (int)(*((short*)(e->value)));
			break;
		case float_element:
            out = (int)(*((float*)(e->value)));
			break;
		case double_element:
            out = (int)(*((double*)(e->value)));
			break;
		case string_element:
			out = (int)strcmp(((string*)e->value)->s, "");
			break;
		default:
			printf("Unknow type inserted!");
            abort();
            break;
	}
	return out;
}

////////// FUNCTIONS FOR ELEMENTS MANAGEMENT ///////////

string* string_copy(void* str_in)
{
	string* str_out = malloc(sizeof(string*));
	*str_out=build_string(((string*)str_in)->s, ((string*)str_in)->len);
	return str_out;
}
string build_string(char* str_in, size_t len)
{
	char* str_out = calloc(len + 1, sizeof(char));
	str_out = strcpy(str_out, str_in);
	string s = { str_out, len };
	return s;
}
string string_append(char* add_str, string str)
{
	size_t len = strlen(add_str);
	str.len += len;
	strcat(str.s, add_str);
	return str;
}
void str_del(string str)
{
	free(str.s);
}

Persona build_persona(char* nome, char* cf, char* referto, int codiceAccesso)
{
    Persona p;
    strcpy(p.CF, cf);
    strcpy(p.Nome, cf);
    strcpy(p.Referto, cf);
    p.CodiceAccesso = codiceAccesso;
    return p;
}

Persona* persona_copy(void* p)
{
    Persona* pout = malloc(sizeof(Persona));
    *pout = build_persona(((Persona*)p)->Nome, ((Persona*)p)->CF, ((Persona*)p)->Referto, ((Persona*)p)->CodiceAccesso);
    return pout;
}

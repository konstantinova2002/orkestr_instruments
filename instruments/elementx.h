#pragma once
#include "Base.h"

class elementx
{
public:
	elementx();
	elementx(int choiceInstrument);
	elementx(char type_instrument);
	elementx(const elementx& other); 
	~elementx();

	elementx* get_next();
	void set_next(elementx* next);
	elementx* get_prev();
	void set_prev(elementx* prev);
	Base* get_instrument();
	void set_instrument(Base* instrument);
	int get_number_element();
	void set_number_element(int number_element);
	char get_type_instrument();
	void set_type_instrument(char type_instrument);
private:
	elementx* next;
	elementx* prev;
	Base* instrument;
	int number_element;
	char type_instrument;
};
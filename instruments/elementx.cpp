#include "elementx.h"
#include "perc_instr.h"
#include "string_instr.h"
#include "wind_instr.h"

elementx::elementx()
{
	cout << "\n>>>>>>Вызван конструктор класса element (без параметров)<<<<<<\n";
	system("pause");

	next = nullptr;
	prev = nullptr;
	instrument = nullptr;
	number_element = 0;
	type_instrument = ' ';
}

elementx::elementx(int choiceInstrument) 
{
	cout << "\n>>>>>>Вызван конструктор класса element (с параметром choiceInstrument)<<<<<<\n";
	system("pause");

	switch (choiceInstrument) {
	case 1: 
		instrument = new perc_instr;
		type_instrument = 'P';
		break;
	case 2:
		instrument = new string_instr;
		type_instrument = 'S';
		break;
	case 3: 
		instrument = new wind_instr;
		type_instrument = 'W';
		break;
	default:
		break;
	}
}

elementx::elementx(char TypeInstrument) 
{
	cout << "\n>>>>>>Вызван конструктор класса element (с параметром TypeInstrument)<<<<<<\n";
	system("pause");

	switch (TypeInstrument)
	{
	case 'P':
		instrument = new perc_instr('f');
		TypeInstrument = 'P';
		break;
	case 'S':
		instrument = new string_instr('f');
		TypeInstrument = 'S';
		break;
	case 'W':
		instrument = new wind_instr('f');
		TypeInstrument = 'W';
		break;
	default:
		break;
	}
}

elementx::elementx(const elementx& other)
{
	std::cout << "\n>>>>>>Вызван конструктор класса element (копирования)<<<<<<\n";
	system("pause");

	this->number_element = other.number_element;
	this->next = new elementx;
	this->next = other.next;
	this->prev = new elementx;
	this->prev = other.prev;
	this->instrument = other.instrument;
}

elementx::~elementx() 
{
	cout << "\n>>>>>>Вызван деструктор класса element<<<<<<\n";
	system("pause");

	next = nullptr;
	prev = nullptr;
	delete instrument;
	instrument = nullptr;
}

elementx* elementx::get_next()
{
	return next;
}

void elementx::set_next(elementx* next)
{
	this->next = next;
}

elementx* elementx::get_prev() {

	return prev;
}

void elementx::set_prev(elementx* prev)
{
	this->prev = prev;
}

Base* elementx::get_instrument() 
{
	return instrument;
}

void elementx::set_instrument(Base* instrument) 
{
	this->instrument = instrument;
}

int elementx::get_number_element() 
{
	return number_element;
}

void elementx::set_number_element(int number_element)
{
	this->number_element = number_element;
}

char elementx::get_type_instrument()
{
	return type_instrument;
}

void elementx::set_type_instrument(char type_instrument)
{
	this->type_instrument = type_instrument;
}
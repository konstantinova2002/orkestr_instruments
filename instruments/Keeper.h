#pragma once
#include "Base.h"
#include "elementx.h" 
#include <fstream>

class Keeper {
private:
	elementx* head;	
	elementx* tail;	
	elementx* index;	
public:
	Keeper();
	Keeper(elementx* head, elementx* tail, elementx* index); 
	Keeper(const Keeper& other);
	~Keeper();

	elementx* get_head();
	void set_head(elementx* root);
	elementx* get_tail();
	void set_tail(elementx* rear);
	elementx* get_index();
	void set_index(elementx* index);

	void insert_instrument();
	void show_orchestra();
	void delete_instrument();
	void change_instrument();
	Keeper& operator ! ();
	void load();
};
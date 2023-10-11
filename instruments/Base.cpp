#include "Base.h"

char* Base::get_name_instr()
{
    return this->name_instr;
}

void Base::set_name_instr(char* name_instr)
{
    this->name_instr = name_instr;
}

char* Base::get_FIO()
{
    return this->FIO;
}

void Base::set_FIO(char* FIO)
{
    this->FIO = FIO;
}

int Base::get_quantity()
{
    return this->quantity;
}

void Base::set_quantity(int quantity)
{
    this->quantity = quantity;
}

int Base::get_cost()
{
    return this->cost;
}

void Base::set_cost(int cost)
{
    this->cost = cost;
}
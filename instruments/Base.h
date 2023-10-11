#pragma once

class Base 
{
public:
    char* get_name_instr();
    void set_name_instr(char* name);
    char* get_FIO();
    void set_FIO(char* FIO);
    int get_quantity();
    void set_quantity(int quantity);
    int get_cost();
    void set_cost(int cost);
private:
    char* name_instr;
    char* FIO;
    int quantity;
    int cost;
};
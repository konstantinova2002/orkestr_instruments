#pragma once
#include <iostream>
#include <fstream>
#include "to_get_string.h"
#include "read_line_file.h"
#include "convert_to_float.h" 
#include "my_exception.h"

class Base 
{
public:
    Base();
    Base(const char* initStr);
    Base(const Base& other);
    virtual ~Base();

    char* get_name_instr();
    void set_name_instr(char* name);
    char* get_FIO();
    void set_FIO(char* FIO);
    int get_num_in_orchestra();
    void set_num_in_orchestra(int quantity);
    int get_cost();
    void set_cost(int cost);
    int get_number_in_keeper();
    void set_number_in_keeper(int number_in_keeper);

    virtual void show_instrument() = 0;
    virtual void change() = 0;
    virtual void save_to_file(std::ofstream& outputFile) = 0;
    virtual void save_service(std::ofstream& fout) = 0; 
    virtual void load_file(std::ifstream& fin) = 0;
private:
    char* name_instr;
    char* FIO;
    int num_in_orchestra;
    int cost;
    int number_in_keeper;
};
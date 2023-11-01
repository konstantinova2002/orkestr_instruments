#define _CRT_SECURE_NO_WARNINGS 
#include "Base.h"
using namespace std;

char* Base::get_name_instr()
{
    return name_instr;
}

void Base::set_name_instr(char* name_instr)
{
    this->name_instr = name_instr;
}

char* Base::get_FIO()
{
    return FIO;
}

void Base::set_FIO(char* FIO)
{
    this->FIO = FIO;
}

int Base::get_num_in_orchestra()
{
    return num_in_orchestra;
}

void Base::set_num_in_orchestra(int num_in_Orchestra)
{
    this->num_in_orchestra = num_in_Orchestra;
}

int Base::get_cost()
{
    return cost;
}

void Base::set_cost(int cost)
{
    this->cost = cost;
}

int Base::get_number_in_keeper() 
{
    return number_in_keeper;
}

void Base::set_number_in_keeper(int number_in_keeper)
{
    this->number_in_keeper = number_in_keeper;
}


Base::Base()
{
	std::cout << "\n>>>>>>Вызван конструктор класса Base (без параметров)<<<<<<\n";
	system("pause");

	const char* initStr = "\t-";

	name_instr = new char[sizeof(initStr)];
	strcpy(name_instr, initStr);

	FIO = new char[sizeof(initStr)];
	strcpy(FIO, initStr);

	num_in_orchestra = 0;
	cost = 0;
	number_in_keeper = 1;
}

Base::Base(const char* initStr)
{
	std::cout << "\n>>>>>>Вызван конструктор класса Base (с параметром)<<<<<<\n";
	system("pause");

	name_instr = new char[sizeof(initStr)];
	strcpy(name_instr, initStr);

	FIO = new char[sizeof(initStr)];
	strcpy(FIO, initStr);

	num_in_orchestra = 0;
	cost = 0;
	number_in_keeper = 1;
}

Base::Base(const Base& other) 
{
	std::cout << "\n>>>>>>Вызван конструктор класса Base (копирования)<<<<<<\n";
	system("pause");

	strcpy(this->name_instr, other.name_instr);
	strcpy(this->FIO, other.FIO);
	this->num_in_orchestra = other.num_in_orchestra;
	this->cost = other.cost;
	this->number_in_keeper = other.number_in_keeper;
}

Base::~Base() 
{
	std::cout << "\n>>>>>>Вызван виртуальный деструктор класса Base<<<<<<\n";
	system("pause");

	cost = 0;
	num_in_orchestra = 0;
	number_in_keeper = 0;
	delete[] FIO;
	FIO = nullptr;
	delete[] name_instr;
	name_instr = nullptr;
};
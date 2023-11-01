#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class my_exception : public exception {
public:
	my_exception(const char* msg) :exception(msg) {}
};
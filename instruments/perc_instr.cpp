#define _CRT_SECURE_NO_WARNINGS  
#include "perc_instr.h"
using namespace std;

perc_instr::perc_instr() 
{
	std::cout << "\n>>>>>>Вызван конструктор класса perc_instr (без параметров)<<<<<<\n";
	system("pause");

	const char* initStr = "\t-";

	type_perc = new char[sizeof(initStr)];
	strcpy(type_perc, initStr);

	int choicePercussionInst;
	int NumUnitsPercussion;
	float CostPercussion;
	int lenString;
	do {
		system("cls");
		cout << "Введите данные об ударном инструменте" << endl
			<< "[1] - Название" << endl
			<< "[2] - ФИО владельца" << endl
			<< "[3] - Количество единиц в оркестре" << endl
			<< "[4] - Стоимость" << endl
			<< "[5] - Тип" << endl
			<< "[6] - Выход" << endl
			<< "Выбранный пункт: ";
		cin >> choicePercussionInst;


		switch (choicePercussionInst) {
		case 1:
			system("cls");
			cout << "Ударный интрумент\n";
			cout << "Введите название:\n" << endl;
			set_name_instr(to_get_string(&lenString));
			break;
		case 2:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите ФИО владельца:\n" << endl;
			set_FIO(to_get_string(&lenString));
			break;
		case 3:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите количество единиц в оркестре: ";
			cin >> NumUnitsPercussion;
			set_num_in_orchestra(NumUnitsPercussion);
			break;
		case 4:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите стоимость: ";
			cin >> CostPercussion;
			set_cost(CostPercussion);
			break;
		case 5:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите тип: \n" << endl;
			type_perc = to_get_string(&lenString);
			break;
		case 6:
			break;
		default:
			cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 6.\n\n";
			system("pause");
			break;
		}
	} while (choicePercussionInst != 6);
}

perc_instr::perc_instr(char file) {
	std::cout << "\n>>>>>>Вызван конструктор класса perc_instr (с параметром)<<<<<<\n";
	system("pause");

	type_perc = nullptr;
}

perc_instr::perc_instr(const perc_instr& other)
{
	std::cout << "\n>>>>>>Вызван конструктор класса perc_instr (копирования)|<<<<<<\n";
	system("pause");

	strcpy(this->type_perc, other.type_perc);
}

perc_instr::~perc_instr()
{
	std::cout << "\n>>>>>>Вызван деструктор класса perc_instr<<<<<<\n";
	system("pause");

	delete[] type_perc;
	type_perc = nullptr;
}

char* perc_instr::get_type_perc() 
{
	return type_perc;
}

void perc_instr::set_type_perc(char* type_perc)
{
	this->type_perc = type_perc;
}

void perc_instr::show_instrument()
{
	cout << "\nУдарный инструмент\n\n"
		<< "Название: " << get_name_instr() << endl
		<< "ФИО владельца: " << get_FIO() << endl
		<< "Количество единиц в оркестре: " << get_num_in_orchestra() << endl
		<< "Стоимость: " << get_cost() << endl
		<< "Тип: " << get_type_perc() << endl;
}

void perc_instr::change()
{
	int lenString;
	int choiceChangePerc;
	int NumUnitsPercussion;
	float CostPercussion;
	cout << "\n\nВыберете пункт, который хотите изменить..." << endl
		<< "[1] - Название" << endl
		<< "[2] - ФИО владельца" << endl
		<< "[3] - Количество единиц в оркестре" << endl
		<< "[4] - Стоимость" << endl
		<< "[5] - Тип" << endl
		<< "Выбранный пункт: ";
	cin >> choiceChangePerc;
	switch (choiceChangePerc) {
	case 1:
		cout << "\nВведите название: ";
		set_name_instr(to_get_string(&lenString));
		break;
	case 2:
		cout << "\nВведите ФИО владельца: ";
		set_FIO(to_get_string(&lenString));
		break;
	case 3:
		cout << "Введите количество единиц в оркестре: ";
		cin >> NumUnitsPercussion;
		set_num_in_orchestra(NumUnitsPercussion);
		break;
	case 4:
		cout << "Введите стоимость: ";
		cin >> CostPercussion;
		set_cost(CostPercussion);
		break;
	case 5:
		cout << "Введите тип: ";
		type_perc = to_get_string(&lenString);
		break;
	default:
		cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
		system("pause");
		break;
	}
}

void perc_instr::save_to_file(std::ofstream& outputFile) 
{
	outputFile << "Номер: " << get_number_in_keeper() << "\n"
		<< "Ударный инструмент\n\n"
		<< "Название: " << get_name_instr() << "\n"
		<< "ФИО владельца: " << get_FIO() << "\n"
		<< "Количество единиц в оркестре: " << get_num_in_orchestra() << "\n"
		<< "Стоимость: " << get_cost() << "\n"
		<< "Тип: " << type_perc << "\n\n\n";
}

void perc_instr::save_service(std::ofstream& fout)
{
	fout << "P" << endl
		<< get_name_instr() << endl
		<< get_FIO() << endl 
		<< get_num_in_orchestra() << endl
		<< get_cost() << endl
		<< type_perc << endl; 
}

void perc_instr::load_file(std::ifstream& fin)
{
	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			set_name_instr(read_line_file(fin));
			break;
		case 1:
			set_FIO(read_line_file(fin));
			break;
		case 2:
			set_num_in_orchestra(atoi(read_line_file(fin)));
			break;
		case 3:
			set_cost(convert_to_float(read_line_file(fin)));
			break;
		case 4:
			type_perc = read_line_file(fin);
			break;
		}
	}
}
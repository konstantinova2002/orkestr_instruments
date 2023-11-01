#define _CRT_SECURE_NO_WARNINGS  
#include "string_instr.h"
using namespace std;

string_instr::string_instr() 
{
	std::cout << "\n>>>>>>������ ����������� ������ string_instr (��� ����������)<<<<<<\n";
	system("pause");

	const char* initStr = "\t-";

	name_manufacture = new char[sizeof(initStr)];
	strcpy(name_manufacture, initStr);

	text_description = new char[sizeof(initStr)];
	strcpy(text_description, initStr);

	int choiceStringInst;
	int NumUnitsStringInst;
	float CostStringInst;
	int lenString;
	do 
	{
		system("cls");
		cout << "������� ������ � �������� �����������" << endl
			<< "[1] - ��������" << endl
			<< "[2] - ��� ���������" << endl
			<< "[3] - ���������� ������ � ��������" << endl
			<< "[4] - ���������" << endl
			<< "[5] - ������������ �������������" << endl
			<< "[6] - ������� ��������� ��������" << endl
			<< "[7] - �����" << endl
			<< "��������� �����: ";
		cin >> choiceStringInst;


		switch (choiceStringInst) 
		{
		case 1:
			system("cls");
			cout << "�������� ���������\n";
			cout << "������� ��������:\n" << endl;
			set_name_instr(to_get_string(&lenString));
			break;
		case 2:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ��� ���������:\n" << endl;
			set_FIO(to_get_string(&lenString));
			break;
		case 3:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ���������� ������ � ��������: ";
			cin >> NumUnitsStringInst;
			set_num_in_orchestra(NumUnitsStringInst);
			break;
		case 4:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ���������: ";
			cin >> CostStringInst;
			set_cost(CostStringInst);
			break;
		case 5:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ������������ �������������: \n" << endl;
			name_manufacture = to_get_string(&lenString);
			break;
		case 6:
			system("cls");
			cout << "�������� ����������\n";
			cout << "�������� ������� ��������� ��������:\n" << endl;
			text_description = to_get_string(&lenString);
			break;
		case 7:
			break;
		default:
			cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 7.\n\n";
			system("pause");
			break;
		}
	} while (choiceStringInst != 7);
}

string_instr::string_instr(char file)
{
	std::cout << "\n>>>>>>������ ����������� ������ string_instr (� ����������)<<<<<<\n";
	system("pause");

	name_manufacture = nullptr;
	text_description = nullptr;
}

string_instr::string_instr(const string_instr& other)
{
	std::cout << "\n>>>>>>������ ����������� ������ string_instr (�����������)<<<<<<\n";
	system("pause");

	strcpy(this->name_manufacture, other.name_manufacture);
	strcpy(this->text_description, other.text_description);
}

string_instr::~string_instr()
{
	std::cout << "\n>>>>>>������ ���������� ������ string_instr<<<<<<\n";
	system("pause");

	delete[] name_manufacture;
	name_manufacture = nullptr;
	delete[] text_description;
	text_description = nullptr;
}

char* string_instr::get_name_manufacture()
{
	return name_manufacture;
}

void string_instr::set_name_manufacture(char* name_manufacture) 
{
	this->name_manufacture = name_manufacture;
}

char* string_instr::get_text_description()
{
	return text_description;
}

void string_instr::set_text_description(char* text_description) 
{
	this->text_description = text_description;  
}

void string_instr::show_instrument()
{
	cout << "\n�������� ����������\n\n"
		<< "��������: " << get_name_instr() << endl
		<< "��� ���������: " << get_FIO() << endl
		<< "���������� ������ � ��������: " << get_num_in_orchestra() << endl
		<< "���������: " << get_cost() << endl
		<< "�������������: " << get_name_manufacture() << endl
		<< "��������: " << get_text_description() << endl;
}

void string_instr::change() 
{
	int lenString;
	int choiceChangePerc;
	int NumUnitsPercussion;
	float CostPercussion;
	cout << "\n\n�������� �����, ������� ������ ��������..." << endl
		<< "[1] - ��������" << endl
		<< "[2] - ��� ���������" << endl
		<< "[3] - ���������� ������ � ��������" << endl
		<< "[4] - ���������" << endl
		<< "[5] - �������������" << endl
		<< "[6] - ��������" << endl
		<< "��������� �����: ";
	cin >> choiceChangePerc;
	switch (choiceChangePerc) 
	{
	case 1:
		cout << "\n������� ��������: ";
		set_name_instr(to_get_string(&lenString));
		break;
	case 2:
		cout << "\n������� ��� ���������: ";
		set_FIO(to_get_string(&lenString));
		break;
	case 3:
		cout << "������� ���������� ������ � ��������: ";
		cin >> NumUnitsPercussion;
		set_num_in_orchestra(NumUnitsPercussion);
		break;
	case 4:
		cout << "������� ���������: ";
		cin >> CostPercussion;
		set_cost(CostPercussion);
		break;
	case 5:
		cout << "������� ������������ �������������: ";
		name_manufacture = to_get_string(&lenString);
		break;
	case 6:
		cout << "�������� ������� ��������� ��������: ";
		text_description = to_get_string(&lenString);
		break;
	default:
		cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 6.\n\n";
		system("pause");
		break;
	}
}

void string_instr::save_to_file(std::ofstream& outputFile) 
{
	outputFile << "�����: " << get_number_in_keeper() << "\n"
		<< "�������� ����������\n\n"
		<< "��������: " << get_name_instr() << "\n"
		<< "��� ���������: " << get_FIO() << "\n"
		<< "���������� ������ � ��������: " << get_num_in_orchestra() << "\n"
		<< "���������: " << get_cost() << "\n"
		<< "�������������: " << name_manufacture << "\n"
		<< "��������: " << text_description << "\n\n\n";
}

void string_instr::save_service(std::ofstream& fout)
{
	fout << "S" << endl
		<< get_name_instr() << endl
		<< get_FIO() << endl
		<< get_num_in_orchestra() << endl
		<< get_cost() << endl
		<< name_manufacture << endl
		<< text_description << endl;
}

void string_instr::load_file(std::ifstream& fin) 
{
	for (int i = 0; i < 6; i++) 
	{
		switch (i) 
		{
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
			name_manufacture = read_line_file(fin);
			break;
		case 5:
			text_description = read_line_file(fin);
			break;
		}
	}
}

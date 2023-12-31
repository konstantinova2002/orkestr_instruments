#define _CRT_SECURE_NO_WARNINGS
#include "wind_instr.h"
using namespace std;

wind_instr::wind_instr()
{
	cout << "\n>>>>>>������ ����������� ������ wind_instr (��� ����������)<<<<<<\n";
	system("pause");

	const char* initStr = "\t-";

	name_manufacture = new char[sizeof(initStr)];
	strcpy(name_manufacture, initStr);

	defects = new char[sizeof(initStr)];
	strcpy(defects, initStr);

	int choiceWind;
	int NumUnitsWind;
	float CostWind;
	int lenString;
	do 
	{
		system("cls");
		cout << "������� ������ � ������� �����������" << endl
			<< "[1] - ��������" << endl
			<< "[2] - ��� ���������" << endl
			<< "[3] - ���������� ������ � ��������" << endl
			<< "[4] - ���������" << endl
			<< "[5] - ������������ �������������" << endl
			<< "[6] - ����� ������� ������������" << endl
			<< "[7] - �����" << endl
			<< "��������� �����: ";
		cin >> choiceWind;


		switch (choiceWind) 
		{
		case 1:
			system("cls");
			cout << "������� ���������\n";
			cout << "������� ��������:\n" << endl;
			set_name_instr(to_get_string(&lenString));
			break;
		case 2:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ��� ���������:\n" << endl;
			set_FIO(to_get_string(&lenString));
			break;
		case 3:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���������� ������ � ��������: ";
			cin >> NumUnitsWind;
			set_num_in_orchestra(NumUnitsWind);
			break;
		case 4:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���������: ";
			cin >> CostWind;
			set_cost(CostWind);
			break;
		case 5:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ������������ �������������: \n" << endl;
			name_manufacture = to_get_string(&lenString);
			break;
		case 6:
			system("cls");
			cout << "������� ����������\n";
			cout << "�������� ����� ������� ����������� � ���� �����������:\n" << endl;
			defects = to_get_string(&lenString);
			break;
		case 7:
			break;
		default:
			cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 7.\n\n";
			system("pause");
			break;
		}
	} while (choiceWind != 7);
}

wind_instr::wind_instr(char file)
{
	std::cout << "\n>>>>>>������ ����������� ������ wind_instr (� ����������)<<<<<<\n";
	system("pause");

	name_manufacture = nullptr;
	defects = nullptr;
}

wind_instr::wind_instr(const wind_instr& other)
{
	cout << "\n>>>>>>������ ����������� ������ wind_instr (�����������)<<<<<<\n";
	system("pause");
	strcpy(this->name_manufacture, other.name_manufacture);
	strcpy(this->defects, other.defects);
}

wind_instr::~wind_instr()
{
	cout << "\n>>>>>>������ ���������� ������ wind_instr<<<<<<\n";
	system("pause");
	delete[] name_manufacture;
	name_manufacture = nullptr;
	delete[] defects;
	defects = nullptr;
}

char* wind_instr::get_name_manufacture() 
{
	return name_manufacture;
}

void wind_instr::set_name_manufacture(char* name_manufacture) 
{
	this->name_manufacture = name_manufacture;
}

char* wind_instr::get_defects() 
{
	return defects; 
}

void wind_instr::set_defects(char* defects) 
{
	this->defects = defects;
}

void wind_instr::show_instrument()
{
	cout << "\n������� ����������\n\n"
		<< "��������: " << get_name_instr() << endl
		<< "��� ���������: " << get_FIO() << endl
		<< "���������� ������ � ��������: " << get_num_in_orchestra() << endl
		<< "���������: " << get_cost() << endl
		<< "������������ �������������: " << get_name_manufacture() << endl
		<< "�������: " << get_defects() << endl;
}

void wind_instr::change()
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
		cout << "�������� ����� ������� ����������� � ���� �����������: ";
		defects = to_get_string(&lenString);
		break;
	default:
		cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 6.\n\n";
		system("pause");
		break;
	}
}

void wind_instr::save_to_file(std::ofstream& outputFile)
{
	outputFile << "�����: " << get_number_in_keeper() << "\n"
		<< "������� ����������\n\n"
		<< "��������: " << get_name_instr() << "\n"
		<< "��� ���������: " << get_FIO() << "\n"
		<< "���������� ������ � ��������: " << get_num_in_orchestra() << "\n"
		<< "���������: " << get_cost() << "\n"
		<< "�������������: " << name_manufacture << "\n"
		<< "�������: " << defects << "\n\n\n";
}

void wind_instr::save_service(std::ofstream& fout)
{
	fout << "W" << endl
		<< get_name_instr() << endl
		<< get_FIO() << endl
		<< get_num_in_orchestra() << endl
		<< get_cost() << endl
		<< name_manufacture << endl
		<< defects << endl;
}

void wind_instr::load_file(std::ifstream& fin)
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
			defects = read_line_file(fin);
			break;
		}
	}
}
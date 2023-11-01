#define _CRT_SECURE_NO_WARNINGS  
#include "perc_instr.h"
using namespace std;

perc_instr::perc_instr() 
{
	std::cout << "\n>>>>>>������ ����������� ������ perc_instr (��� ����������)<<<<<<\n";
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
		cout << "������� ������ �� ������� �����������" << endl
			<< "[1] - ��������" << endl
			<< "[2] - ��� ���������" << endl
			<< "[3] - ���������� ������ � ��������" << endl
			<< "[4] - ���������" << endl
			<< "[5] - ���" << endl
			<< "[6] - �����" << endl
			<< "��������� �����: ";
		cin >> choicePercussionInst;


		switch (choicePercussionInst) {
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
			cin >> NumUnitsPercussion;
			set_num_in_orchestra(NumUnitsPercussion);
			break;
		case 4:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���������: ";
			cin >> CostPercussion;
			set_cost(CostPercussion);
			break;
		case 5:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���: \n" << endl;
			type_perc = to_get_string(&lenString);
			break;
		case 6:
			break;
		default:
			cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 6.\n\n";
			system("pause");
			break;
		}
	} while (choicePercussionInst != 6);
}

perc_instr::perc_instr(char file) {
	std::cout << "\n>>>>>>������ ����������� ������ perc_instr (� ����������)<<<<<<\n";
	system("pause");

	type_perc = nullptr;
}

perc_instr::perc_instr(const perc_instr& other)
{
	std::cout << "\n>>>>>>������ ����������� ������ perc_instr (�����������)|<<<<<<\n";
	system("pause");

	strcpy(this->type_perc, other.type_perc);
}

perc_instr::~perc_instr()
{
	std::cout << "\n>>>>>>������ ���������� ������ perc_instr<<<<<<\n";
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
	cout << "\n������� ����������\n\n"
		<< "��������: " << get_name_instr() << endl
		<< "��� ���������: " << get_FIO() << endl
		<< "���������� ������ � ��������: " << get_num_in_orchestra() << endl
		<< "���������: " << get_cost() << endl
		<< "���: " << get_type_perc() << endl;
}

void perc_instr::change()
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
		<< "[5] - ���" << endl
		<< "��������� �����: ";
	cin >> choiceChangePerc;
	switch (choiceChangePerc) {
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
		cout << "������� ���: ";
		type_perc = to_get_string(&lenString);
		break;
	default:
		cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 5.\n\n";
		system("pause");
		break;
	}
}

void perc_instr::save_to_file(std::ofstream& outputFile) 
{
	outputFile << "�����: " << get_number_in_keeper() << "\n"
		<< "������� ����������\n\n"
		<< "��������: " << get_name_instr() << "\n"
		<< "��� ���������: " << get_FIO() << "\n"
		<< "���������� ������ � ��������: " << get_num_in_orchestra() << "\n"
		<< "���������: " << get_cost() << "\n"
		<< "���: " << type_perc << "\n\n\n";
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
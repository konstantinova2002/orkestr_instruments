#define _CRT_SECURE_NO_WARNINGS  
#include "Keeper.h"
#include <iostream>
using namespace std;

int main() {
	cin.exceptions(std::istream::failbit);
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	Keeper mainKeeper;

	int choice1;

	do {
		system("cls");
		cout << "�������" << endl
			<< "[1] - �������� ����������" << endl
			<< "[2] - ������� ����������" << endl
			<< "[3] - ������� �� ����� ��� ��������� �����������" << endl
			<< "[4] - �������� ������ �� �����������" << endl
			<< "[5] - ��������� � ����" << endl
			<< "[6] - ��������� �� �����" << endl
			<< "[7] - ����� �� ���������" << endl
			<< "��������� �����: ";
		try {

			cin >> choice1;


			switch (choice1) {
			case 1:
				mainKeeper.insert_instrument();
				break;
			case 2:
				mainKeeper.delete_instrument();
				break;
			case 3:
				mainKeeper.show_orchestra();
				break;
			case 4:
				mainKeeper.change_instrument();
				break;
			case 5:
				!mainKeeper;
				break;
			case 6:
				mainKeeper.load();
				break;
			case 7:
				break;
			default:
				throw my_exception("\n\n������������ �����!!!\n����������, �������� ����� ���� �� 1 �� 7.\n\n");
				break;
			}
		}
		catch (my_exception& ex) {
			cout << ex.what();
			system("pause");
		}
		catch (const std::istream::failure& ex) {
			system("cls");
			cout << "\n\n������� ������������ �������� !!!" << endl
				<< ex.what() << endl
				<< "��������� ����...\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
		}

	} while (choice1 != 7);



	return 0;
}
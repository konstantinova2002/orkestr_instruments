#include "Keeper.h"
using namespace std;

Keeper::Keeper() 
{
	system("cls");
	cout << "\n>>>>>>Вызван конструктор класса Keeper (без параметров)<<<<<<\n";
	system("pause");

	head = nullptr;
	tail = nullptr;
	index = nullptr;
}

Keeper::Keeper(elementx* head, elementx* tail, elementx* index)
{
	cout << "\n>>>>>>Вызван конструктор класса Keeper (с параметрами)<<<<<<<\n";
	system("pause");

	this->head = head;
	this->tail = tail;
	this->index = index;
}

Keeper::Keeper(const Keeper& other)
{
	cout << "\n>>>>>>Вызван конструктор класса Keeper (копирования)|<<<<<\n";
	system("pause");

	this->head = nullptr;
	this->tail = nullptr;
	this->index = nullptr;

	if (other.tail == nullptr)
		return;

	elementx* firstElement = new elementx(other.tail->get_type_instrument());
	this->head = firstElement;
	elementx* newTail_tmp = firstElement;

	elementx* tail_tmp = other.tail->get_next();
	while (tail_tmp != nullptr) {
		elementx* element = new elementx(tail_tmp->get_type_instrument());
		this->tail = element;
		element->set_prev(newTail_tmp);
		newTail_tmp->set_next(element);
		newTail_tmp = newTail_tmp->get_next();

		tail_tmp = tail_tmp->get_next();
	}

	this->index = this->head;
}

Keeper::~Keeper() 
{
	cout << "\n>>>>>>Вызван деструктор класса Keeper<<<<<<\n";
	system("pause");

	while (index != nullptr) {
		if (index == nullptr) {
			return;
		}

		if (index == tail) {
			delete tail;
			index = nullptr;
			tail = nullptr;
			head = nullptr;
			return;
		}

		elementx* tmp_element = index;
		index = tmp_element->get_next();
		delete tmp_element;
	}
}

elementx* Keeper::get_head()
{
	return head;
}

void Keeper::set_head(elementx* head) 
{
	this->head = head;
}

elementx* Keeper::get_tail() 
{
	return tail;
}

void Keeper::set_tail(elementx* tail)
{
	this->tail = tail;
}

elementx* Keeper::get_index() 
{
	return index;
}

void Keeper::set_index(elementx* index) 
{
	this->index = index;
}

void Keeper::insert_instrument()  
{
	int choiceInstrument;
	system("cls");
	cout << "Какой инструмент добавить в оркестр ?" << endl
		<< "[1] - Ударный" << endl
		<< "[2] - Струнный" << endl
		<< "[3] - Духовой" << endl
		<< "Выбранный пункт: ";
	cin >> choiceInstrument;

	if ((choiceInstrument != 1) && (choiceInstrument != 2) && (choiceInstrument != 3))
		throw my_exception("\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт меню от 1 до 3.\n\n");

	elementx* element = new elementx(choiceInstrument);

	element->set_prev(tail);
	if (head == nullptr) 
	{
		head = element;
		index = element;
	}
	if (tail != nullptr)
		tail->set_next(element);
	tail = element;

	if (element->get_prev() != nullptr)
	{
		element->set_number_element((element->get_prev())->get_number_element() + 1);
		(element->get_instrument())->set_number_in_keeper((element->get_prev())->get_number_element() + 1);
	}
	else 
	{
		element->set_number_element(1);
		(element->get_instrument())->set_number_in_keeper(1); 
	}
	
}

void Keeper::show_orchestra()
{
	if (tail == nullptr)
		throw my_exception("Список иснтрументов пуст!!!");

	system("cls");
	while (index != nullptr) 
	{
		cout << "\n\nНомер: " << index->get_number_element();
		(index->get_instrument())->show_instrument();
		index = index->get_next(); 
	}
	index = head;
	cout << "\n\n";
	system("pause");
}

void Keeper::delete_instrument()  
{
	if (tail == nullptr)
		throw my_exception("Список инструментов пуст !!!");

	int cnt = 1;
	int choiceDelete;
	show_orchestra();
	cout << "\n\n\nВведите номер инструмента, который хотите удалить: ";
	cin >> choiceDelete;

	if ((choiceDelete <= 0) || (choiceDelete > tail->get_number_element()))
		throw my_exception("\n\nНеккоректный выбор!!!\nИнструмента с таким номером нет в оркестре.\n\n");

	while (index->get_number_element() != choiceDelete)
	{
		index = index->get_next();
	}

	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
		delete index;
		index = nullptr;
		return;
	}
	else 
	{
		if (index == tail)
		{
			tail = index->get_prev();
			tail->set_next(nullptr);
			delete index;
			index = head;
		}
		else 
		{
			if (index == head) 
			{
				head = index->get_next();
				head->set_prev(nullptr);
				delete index;
				index = head;
			}
			else 
			{
				(index->get_prev())->set_next(index->get_next());
				(index->get_next())->set_prev(index->get_prev());
				delete index;
				index = head;

			}
		}

	}

	while (index != nullptr)
	{
		index->set_number_element(cnt);
		index = index->get_next(); 
		cnt++;
	}
	index = head;
}

void Keeper::change_instrument()
{
	if (tail == nullptr)
		throw "Список инструментов пуст !!!";

	int choiceChange;
	show_orchestra();
	cout << "\n\nВведите номер инструмента, данные которого вы хотите изменить: ";
	cin >> choiceChange;

	if ((choiceChange <= 0) || (choiceChange > tail->get_number_element()))
		throw "\n\nНеккоректный выбор!!!\nИнструмента с таким номером нет в оркестре.\n\n";

	system("cls");

	while (index->get_number_element() != choiceChange) {
		index = index->get_next();
	}
	(index->get_instrument())->show_instrument();
	(index->get_instrument())->change();
	index = head;
}

Keeper& Keeper::operator!()
{
	if (head == nullptr) {
		throw my_exception("Список инструментов пуст !!!");
	}
	
	std::ofstream outputFile;
	outputFile.open("orchestra.txt");
	if (outputFile.is_open()) {
		while (index != nullptr) 
		{
			(index->get_instrument())->save_to_file(outputFile);
			index = index->get_next();
		}
		index = head;
		cout << "\n\nОркестр успешно сохранён в файл !!!\n\n";
		system("pause");
	}
	else
		throw "\n\nОшибка!!!\nФайл открыть не удалось.\n\n";
	outputFile.close();


	std::ofstream fout;
	fout.open("special.txt");
	if (fout.is_open()) {
		while (index != nullptr) {
			(index->get_instrument())->save_service(fout);
			index = index->get_next();
		}
		index = head;
	}
	else
		throw my_exception("\n\nОшибка!!!\nФайл открыть не удалось.\n\n");

	fout.close();

	return *this;
}

void Keeper::load() 
{
	std::ifstream fin;
	fin.open("service.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			elementx* element = nullptr;
			char* line = read_line_file(fin);

			if (!strcmp(line, "P")) 
			{
				element = new elementx('P');
				(element->get_instrument())->load_file(fin);
			}
			if (!strcmp(line, "S")) 
			{
				element = new elementx('S');
				(element->get_instrument())->load_file(fin);
			}
			if (!strcmp(line, "W")) 
			{
				element = new elementx('W');
				(element->get_instrument())->load_file(fin);
			}
			if (*line == '\0')
				return;

			delete[] line;

			element->set_prev(tail);
			if (head == nullptr) { 
				head = element;
				index = element;
			}
			if (tail != nullptr)
				tail->set_next(element);
			head = element;


			if (element->get_prev() != nullptr) {
				element->set_number_element((element->get_prev())->get_number_element() + 1);
				(element->get_instrument())->set_number_in_keeper((element->get_prev())->get_number_element() + 1);
			}
			else {
				element->set_number_element(1);
				(element->get_instrument())->set_number_in_keeper(1); 
			}
		}
	}
	else {
		system("cls");
		cout << "\n\nОшибка!!!\nФайл открыть не удалось.\n\n";
		system("pause");
	}

	fin.close();
}
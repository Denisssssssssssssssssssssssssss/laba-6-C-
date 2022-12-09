#include "equipment.h"
#include "checkfileextension.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//конструктор класса  без параметров
equipment::equipment() {
	cost = 0;
	eqtitle = "-";
}

//конструктор класса  с одним параметром
equipment::equipment(int allfields) {
	if (allfields >= 0) {
		cost = allfields;
		eqtitle = to_string(allfields);
	}
	else {
		cout << "Было введено недопустимое значение allfields (allfields < 0)." << endl;
		equipment equ;
		*this = equ;
	}
}

//конструктор класса  со всеми параметрами
equipment::equipment(string eqtitle, int cost) {
	this->eqtitle = eqtitle;
	if(cost >= 0)
		this->cost = cost;
	else {
		cout << "Было введено недопустимое значение cost (cost < 0)." << endl;
		this->cost = 0;
	}
}

//метод ввода класса 
void equipment::input() {
	cout << "Введите тип оборудования: ";
	getline(cin, eqtitle);
	cout << "Введите цену оборудования: ";
	cin >> cost;
}

//метод вывода
void equipment::output() {
	cout << "Оборудование: " << eqtitle << endl;
	cout << "Цена оборудования: " << cost << endl;
}

//перегрузка оператора +
equipment equipment::operator + (equipment e1) {
	cost = cost + e1.cost;
	return *this;
}

//перегрузка оператора ++ префиксный
equipment& equipment::operator++() {
	cost++;
	return *this;
}

//перегрузка оператора ++ постфиксный
equipment equipment::operator++(int) {
	equipment temp = *this;
	++* this;
	return temp;
}

//метод, возвращающий значение через указатель
equipment* equipment::get() {
	return this;
}

//метод, возвращающий значение через ссылку
equipment& equipment::getadress() {
	return *this;
}

void equipment::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << eqtitle << "\t";
	file << cost << "\t";
}

void equipment::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	int flag = 0;
	string buff;
	try {
		file >> eqtitle;
		while (!flag) {
			file >> buff;
			if (buff[0] >= '0' && buff[0] <= '9') {
				cost = stoi(buff);
				flag = 1;
			}
			else {
				eqtitle += " ";
				eqtitle += buff;
			}
		}
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи или неверно указано имя файла.\n");
	}

}
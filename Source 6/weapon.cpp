#include "weapon.h"
#include "checkfileextension.h"
#include <iostream>
#include <string>
#include <sstream>

//конструктор класса  без параметров
weapon::weapon() {
	wepcost = 0;
	weptitle = "-";
}

//конструктор класса  с одним параметром
weapon::weapon(int allfields) {
	if (allfields >= 0) {
		wepcost = allfields;
		weptitle = to_string(allfields);
	}
	else {
		cout << "Было введено недопустимое значение allfields (allfields < 0)." << endl;
		weapon weap;
		*this = weap;
	}
}

//конструктор класса  со всеми параметрами
weapon::weapon(string weptitle, int wepcost) {
	this->weptitle = weptitle;
	if (wepcost >= 0)
		this->wepcost = wepcost;
	else {
		cout << "Было введено недопустимое значение wepcost (wepcost < 0)." << endl;
		this->wepcost = 0;
	}
}

//метод ввода
void weapon::input() {
	cout << "Введите тип вооружения: ";
	getline(cin, weptitle);
	cout << "Введите затраты на вооружение : ";
	cin >> wepcost;
}

//метод вывода
void weapon::output() {
	cout << "Вооружение: " << weptitle << endl;
	cout << "Стоимость вооружения: " << wepcost << endl;
}

void weapon::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << weptitle << "\t";
	file << wepcost << "\t";
}

void weapon::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	int flag = 0;
	string buff;
	try {
		file >> weptitle;
		while (!flag) {
			file >> buff;
			if (buff[0] >= '0' && buff[0] <= '9') {
				wepcost = stoi(buff);
				flag = 1;
			}
			else {
				weptitle += " ";
				weptitle += buff;
			}
		}
	}
	catch (exception& e) {
			throw exception("В файле недостаточно данных для записи или неверно указано имя файла.\n");
	}

}
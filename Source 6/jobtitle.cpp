#include "jobtitle.h"
#include "checkfileextension.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//конструктор класса jobtitle без параметров
jobtitle::jobtitle() {
	jtitle = "-";
	monthcost = 0;
}

//конструктор класса jobtitle с одним параметром
jobtitle::jobtitle(int allfields) {
	if (allfields >= 0) {
		jtitle = to_string(allfields);
		monthcost = allfields;
	}
	else {
		cout << "Было введено недопустимое значение allfields (allfields < 0)." << endl;
		jobtitle jtitle;
		*this = jtitle;
	}
}

//конструктор класса jobtitle со всеми параметрами
jobtitle::jobtitle(string jtitle, int monthcost) {
	this->jtitle = jtitle;
	if(monthcost >= 0)
		this->monthcost = monthcost;
	else {
		cout << "Было введено недопустимое значение monthcost (monthcost < 0)." << endl;
		this->monthcost = 0;
	}
}

//метод ввода класса jobtitle
void jobtitle::input() {
	cout << "Введите должность: ";
	getline(cin, jtitle);
	cout << "Введите зарплату: ";
	cin >> monthcost;

}

//метод вывода
void jobtitle::output() {
	cout << "Должность: " << jtitle << endl;
	cout << "Зарплата: " << monthcost << endl;

}

//перегрузка оператора +
jobtitle jobtitle::operator + (jobtitle j1) {
	monthcost = monthcost + j1.monthcost;
	return *this;
}

//перегрузка оператора ++ префиксный
jobtitle& jobtitle::operator++() {
	monthcost++;
	return *this;
}

//перегрузка оператора ++ постфиксный
jobtitle jobtitle::operator++(int) {
	jobtitle temp = *this;
	++* this;
	return temp;
}

//метод, возвращающий значение через указатель
jobtitle* jobtitle::get() {
	return this;
}

//метод, возвращающий значение через ссылку
jobtitle& jobtitle::getadress() {
	return *this;
}

//метод для редактирования должности
void jobtitle::editjtitle(string jtitle, string add) {
	int i;
	//строковый поток
	stringstream ss(this->jtitle);
	//подсчет количества слов в строке
	int n = count(this->jtitle.begin(), this->jtitle.end(), ' ') + 1;
	string* words = new string[n];
	this->jtitle = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for (i = 0; i < n; i++) {
		//если строки одинаковые
		if (!(*(words + i)).compare(jtitle)) {
			this->jtitle += add + " ";
		}
		this->jtitle += *(words + i) + " ";
	}
}

void jobtitle::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << jtitle << "\t";
	file << monthcost << "\t";
}

void jobtitle::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	int flag = 0;
	string buff;
	try {
		file >> jtitle;
		while (!flag) {
			file >> buff;
			if (buff[0] >= '0' && buff[0] <= '9') {
				monthcost = stoi(buff);
				flag = 1;
			}
			else {
				jtitle += " ";
				jtitle += buff;
			}
		}
		
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи или неверно указано имя файла.\n");
	}

}
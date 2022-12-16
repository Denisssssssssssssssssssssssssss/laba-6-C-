#include "employee.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include "checkfileextension.h"

//исходное значение пол€ counter
int employee::counter = 0;

//конструктор класса employee без параметров
employee::employee() {
	counter++;
	id = counter;
	equipment equip;
	jobtitle jtitle;
	transport tran;
	weapon *weap;
	this->jtitle = jtitle;
	this->equip = equip;
	this->tran = tran;
	this->fire = fire;
	this->melee = melee;
}

//конструктор класса employee с одним параметром
employee::employee(int allfields) {
	counter++;
	id = counter;
	if (allfields >= 0) {
		equipment equip(allfields);
		this->equip = equip;
		jobtitle j(allfields);
		this->jtitle = jtitle;
		transport tran(allfields);
		this->tran = tran;
		meleeweapon melee(allfields);
		this->melee = melee;
		firearms<int> fire(allfields);
		this->fire = fire;
	}
	else {
		cout << "Ѕыло введено недопустимое значение allfields (allfields < 0)." << endl;
		equipment equip;
		jobtitle jtitle;
		transport tran;
		meleeweapon melee;
		firearms<int> fire;
		this->jtitle = jtitle;
		this->equip = equip;
		this->tran = tran;
		this->melee = melee;
		this->fire = fire;
	}
}

//конструктор класса employee со всеми параметрами
employee::employee(jobtitle jitle, equipment equip, transport tran, meleeweapon melee, firearms<int> fire) {
	counter++;
	id = counter;
	this->equip = equip;
	this->jtitle = jtitle;
	this->tran = tran;
	this->melee = melee;
	this->fire = fire;
}

//метод полного вывода employee
void employee::output() {
	cout << "ID: " << this->id << endl;
	jtitle.output();
	equip.output();
	tran.output();
	melee.output();
	fire.output();
}

//метод ввода employee
void employee::input() {
	cout << "¬ведите ID: ";
	cin >> this->id;
	while (getchar() != '\n');
	jtitle.input();
	while (getchar() != '\n');
	equip.input();
	while (getchar() != '\n');
	tran.input();
	while (getchar() != '\n');
	melee.input();
	while (getchar() != '\n');
	fire.input();
}

//метод подсчета затрат
int employee::empcost() {
	int salary = 0; //затарты
	salary += jtitle.monthcost + equip.cost + tran.trcost + melee.wepcost + fire.wepcost;
	return salary;
}

//метод вывода пол€ counter
void employee::printcounter() {
	cout << " оличество работников: " << counter << endl;
}

//метод уменьшиющий значение пол€ counter на 1
void employee::minuscounter() {
	counter--;
	cout << " оличество работников уменьшено на 1." << endl;
}

//метод уменьшающий значение пол€ counter на заданное значение
void employee::minuscounter(int number) {
	int x = counter;
	counter = counter - number;
	cout << " оличество работников изменено с " << x << " на " << counter << endl;
}

//перегрузка оператора +
employee employee::operator + (employee e1) {
	id = id + e1.id;
	return *this;
}

//перегрузка оператора ++ префиксный
employee& employee::operator++() {
	id++;
	return *this;
}

//перегрузка оператора ++ постфиксный
employee employee::operator++(int) {
	employee temp = *this;
	++* this;
	return temp;
}

//метод, возвращающий значение через указатель
employee* employee::get() {
	return this;
}

//метод, возвращающий значение через ссылку
employee& employee::getadress() {
	return *this;
}

void employee::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("»спользовано недопустимое расширение файла. ƒопустимое расширение: \".txt\".\n");
	file << id << "\t";
	jtitle.tofile(file,filename);
	equip.tofile(file, filename);
	melee.tofile(file, filename);
	fire.tofile(file, filename);
	tran.tofile(file,filename);

}


void employee::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("»спользовано недопустимое расширение файла. ƒопустимое расширение: \".txt\".\n");
	try {
		file >> id;
		jtitle.getfromfile(file,filename);
		equip.getfromfile(file, filename);
		melee.getfromfile(file, filename);
		fire.getfromfile(file, filename);
		tran.getfromfile(file,filename);
	}
	catch (exception& e) {
		throw exception("¬ файле недостаточно данных дл€ записи или неверно указано им€ файла.\n");
	}
}
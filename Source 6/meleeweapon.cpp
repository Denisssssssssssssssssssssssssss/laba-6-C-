#include "meleeweapon.h"
#include "weapon.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//конструктор класса meleeweapon без параметров
meleeweapon::meleeweapon() : weapon() {
	damage = "";
}

//конструктор класса meleeweapon со всеми параметрами
meleeweapon::meleeweapon(string weptitle, int wepcost, string damage) : weapon(weptitle,wepcost) {
	this->damage = damage;
}

//конструктор класса employee с одним параметром
meleeweapon::meleeweapon(int allfields) : weapon(allfields){
	if (allfields >= 0) {
		damage = allfields;
	}
	else {
		damage = "";
	}
}

//метод вывода meleeweapon
void meleeweapon::output() {
	this->weapon::output();
	cout << "Характер урона: " << damage << endl;
}

//метод ввода
void meleeweapon::input(){
	this->weapon::input();
	cout << "Характер урона: ";
	cin >> damage;
}


//метод записи в файл
void meleeweapon::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << weptitle << "\t";
	file << wepcost << "\t";
	file << damage << "\n";
}

//метод записи из файла
void meleeweapon::getfromfile(ifstream& file, string filename) {
	try {
		this->weapon::getfromfile(file, filename);
		file >> damage;
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи.\n");
	}
}

//перегрузка оператора присваивания
meleeweapon meleeweapon::operator= (meleeweapon mel) {
	this->weptitle = mel.weptitle;
	this->wepcost = mel.wepcost;
	this->damage = mel.damage;
	return *this;
}

//перегрузка оператора <<
ostream& operator<< (ostream& out, meleeweapon& melee) {
	out << melee.wepcost << endl;
	out << melee.weptitle << endl;
	out << "damage: " << melee.damage;
	return out;
}

//перегрузка оператора >>
istream& operator>> (istream& os, meleeweapon& subemployee) {
	subemployee.weapon::input();
	cout << "Введите характер урона: ";
	os >> subemployee.damage;
	return os;
}
#pragma once
#include "weapon.h"
#include <fstream>
#include <iostream>

template <typename T>
class firearms : public weapon
{
	using  weapon::operator =;
private: 
	T range;
public:
	firearms(string weptitle, int wepcost, T range) : weapon(weptitle,wepcost) {
		this->range = range;
		
	}
	firearms(int allfields) : weapon(allfields) {
			range = allfields;	
	}
	firearms() : weapon() {
		range = 0;
		
	}
	void output() override {
		this->weapon::output();
		cout << "Дальность:\n";
			cout << range << endl;
	}
	void input() override {
		this->weapon::input();
			cout << "Введите дальность: ";
			cin >> range;
	}
	firearms operator=(weapon fire) {
		weapon::operator=(fire);
		return *this;
	}
	void tofile(ofstream& file, string filename) override {
	}
	//перегрузка оператора <<
	ostream& operator<< (ostream& out) {
		weapon s = *this;
		out << s;
		out << "Дальность:\n";
			out << this->range << endl;
		return out;
	}
};
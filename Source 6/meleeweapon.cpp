#include "meleeweapon.h"
#include "weapon.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//����������� ������ meleeweapon ��� ����������
meleeweapon::meleeweapon() : weapon() {
	damage = "";
}

//����������� ������ meleeweapon �� ����� �����������
meleeweapon::meleeweapon(string weptitle, int wepcost, string damage) : weapon(weptitle,wepcost) {
	this->damage = damage;
}

//����������� ������ employee � ����� ����������
meleeweapon::meleeweapon(int allfields) : weapon(allfields){
	if (allfields >= 0) {
		damage = allfields;
	}
	else {
		damage = "";
	}
}

//����� ������ meleeweapon
void meleeweapon::output() {
	this->weapon::output();
	cout << "�������� �����: " << damage << endl;
}

//����� �����
void meleeweapon::input(){
	this->weapon::input();
	cout << "�������� �����: ";
	cin >> damage;
}


//����� ������ � ����
void meleeweapon::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << weptitle << "\t";
	file << wepcost << "\t";
	file << damage << "\n";
}

//����� ������ �� �����
void meleeweapon::getfromfile(ifstream& file, string filename) {
	try {
		this->weapon::getfromfile(file, filename);
		file >> damage;
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������.\n");
	}
}

//���������� ��������� ������������
meleeweapon meleeweapon::operator= (meleeweapon mel) {
	this->weptitle = mel.weptitle;
	this->wepcost = mel.wepcost;
	this->damage = mel.damage;
	return *this;
}

//���������� ��������� <<
ostream& operator<< (ostream& out, meleeweapon& melee) {
	out << melee.wepcost << endl;
	out << melee.weptitle << endl;
	out << "damage: " << melee.damage;
	return out;
}

//���������� ��������� >>
istream& operator>> (istream& os, meleeweapon& subemployee) {
	subemployee.weapon::input();
	cout << "������� �������� �����: ";
	os >> subemployee.damage;
	return os;
}
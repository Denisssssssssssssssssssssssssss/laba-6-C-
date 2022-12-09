#include "weapon.h"
#include "checkfileextension.h"
#include <iostream>
#include <string>
#include <sstream>

//����������� ������  ��� ����������
weapon::weapon() {
	wepcost = 0;
	weptitle = "-";
}

//����������� ������  � ����� ����������
weapon::weapon(int allfields) {
	if (allfields >= 0) {
		wepcost = allfields;
		weptitle = to_string(allfields);
	}
	else {
		cout << "���� ������� ������������ �������� allfields (allfields < 0)." << endl;
		weapon weap;
		*this = weap;
	}
}

//����������� ������  �� ����� �����������
weapon::weapon(string weptitle, int wepcost) {
	this->weptitle = weptitle;
	if (wepcost >= 0)
		this->wepcost = wepcost;
	else {
		cout << "���� ������� ������������ �������� wepcost (wepcost < 0)." << endl;
		this->wepcost = 0;
	}
}

//����� �����
void weapon::input() {
	cout << "������� ��� ����������: ";
	getline(cin, weptitle);
	cout << "������� ������� �� ���������� : ";
	cin >> wepcost;
}

//����� ������
void weapon::output() {
	cout << "����������: " << weptitle << endl;
	cout << "��������� ����������: " << wepcost << endl;
}

void weapon::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << weptitle << "\t";
	file << wepcost << "\t";
}

void weapon::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
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
			throw exception("� ����� ������������ ������ ��� ������ ��� ������� ������� ��� �����.\n");
	}

}
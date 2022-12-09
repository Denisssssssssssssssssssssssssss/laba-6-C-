#include "equipment.h"
#include "checkfileextension.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//����������� ������  ��� ����������
equipment::equipment() {
	cost = 0;
	eqtitle = "-";
}

//����������� ������  � ����� ����������
equipment::equipment(int allfields) {
	if (allfields >= 0) {
		cost = allfields;
		eqtitle = to_string(allfields);
	}
	else {
		cout << "���� ������� ������������ �������� allfields (allfields < 0)." << endl;
		equipment equ;
		*this = equ;
	}
}

//����������� ������  �� ����� �����������
equipment::equipment(string eqtitle, int cost) {
	this->eqtitle = eqtitle;
	if(cost >= 0)
		this->cost = cost;
	else {
		cout << "���� ������� ������������ �������� cost (cost < 0)." << endl;
		this->cost = 0;
	}
}

//����� ����� ������ 
void equipment::input() {
	cout << "������� ��� ������������: ";
	getline(cin, eqtitle);
	cout << "������� ���� ������������: ";
	cin >> cost;
}

//����� ������
void equipment::output() {
	cout << "������������: " << eqtitle << endl;
	cout << "���� ������������: " << cost << endl;
}

//���������� ��������� +
equipment equipment::operator + (equipment e1) {
	cost = cost + e1.cost;
	return *this;
}

//���������� ��������� ++ ����������
equipment& equipment::operator++() {
	cost++;
	return *this;
}

//���������� ��������� ++ �����������
equipment equipment::operator++(int) {
	equipment temp = *this;
	++* this;
	return temp;
}

//�����, ������������ �������� ����� ���������
equipment* equipment::get() {
	return this;
}

//�����, ������������ �������� ����� ������
equipment& equipment::getadress() {
	return *this;
}

void equipment::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << eqtitle << "\t";
	file << cost << "\t";
}

void equipment::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
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
		throw exception("� ����� ������������ ������ ��� ������ ��� ������� ������� ��� �����.\n");
	}

}
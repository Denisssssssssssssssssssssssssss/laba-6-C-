#include "jobtitle.h"
#include "checkfileextension.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//����������� ������ jobtitle ��� ����������
jobtitle::jobtitle() {
	jtitle = "-";
	monthcost = 0;
}

//����������� ������ jobtitle � ����� ����������
jobtitle::jobtitle(int allfields) {
	if (allfields >= 0) {
		jtitle = to_string(allfields);
		monthcost = allfields;
	}
	else {
		cout << "���� ������� ������������ �������� allfields (allfields < 0)." << endl;
		jobtitle jtitle;
		*this = jtitle;
	}
}

//����������� ������ jobtitle �� ����� �����������
jobtitle::jobtitle(string jtitle, int monthcost) {
	this->jtitle = jtitle;
	if(monthcost >= 0)
		this->monthcost = monthcost;
	else {
		cout << "���� ������� ������������ �������� monthcost (monthcost < 0)." << endl;
		this->monthcost = 0;
	}
}

//����� ����� ������ jobtitle
void jobtitle::input() {
	cout << "������� ���������: ";
	getline(cin, jtitle);
	cout << "������� ��������: ";
	cin >> monthcost;

}

//����� ������
void jobtitle::output() {
	cout << "���������: " << jtitle << endl;
	cout << "��������: " << monthcost << endl;

}

//���������� ��������� +
jobtitle jobtitle::operator + (jobtitle j1) {
	monthcost = monthcost + j1.monthcost;
	return *this;
}

//���������� ��������� ++ ����������
jobtitle& jobtitle::operator++() {
	monthcost++;
	return *this;
}

//���������� ��������� ++ �����������
jobtitle jobtitle::operator++(int) {
	jobtitle temp = *this;
	++* this;
	return temp;
}

//�����, ������������ �������� ����� ���������
jobtitle* jobtitle::get() {
	return this;
}

//�����, ������������ �������� ����� ������
jobtitle& jobtitle::getadress() {
	return *this;
}

//����� ��� �������������� ���������
void jobtitle::editjtitle(string jtitle, string add) {
	int i;
	//��������� �����
	stringstream ss(this->jtitle);
	//������� ���������� ���� � ������
	int n = count(this->jtitle.begin(), this->jtitle.end(), ' ') + 1;
	string* words = new string[n];
	this->jtitle = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for (i = 0; i < n; i++) {
		//���� ������ ����������
		if (!(*(words + i)).compare(jtitle)) {
			this->jtitle += add + " ";
		}
		this->jtitle += *(words + i) + " ";
	}
}

void jobtitle::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << jtitle << "\t";
	file << monthcost << "\t";
}

void jobtitle::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
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
		throw exception("� ����� ������������ ������ ��� ������ ��� ������� ������� ��� �����.\n");
	}

}
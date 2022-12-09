#include "transport.h"
#include "checkfileextension.h"
#include <iostream>
#include <string>
#include <sstream>

//����������� ������  ��� ����������
transport::transport() {
	trcost = 0;
	trtitle = "-";
}

//����������� ������  � ����� ����������
transport::transport(int allfields) {
	if (allfields >= 0) {
		trcost = allfields;
		trtitle = to_string(allfields);
	}
	else {
		cout << "���� ������� ������������ �������� allfields (allfields < 0)." << endl;
		transport tran;
		*this = tran;
	}
}

//����������� ������  �� ����� �����������
transport::transport(string trtitle, int trcost) {
	this->trtitle = trtitle;
	if (trcost >= 0)
		this->trcost = trcost;
	else {
		cout << "���� ������� ������������ �������� trcost (trcost < 0)." << endl;
		this->trcost = 0;
	}
}

//����� �����
void transport::input() {
	cout << "������� ��� ����������: ";
	getline(cin, trtitle);
	cout << "������� ������� �� ��������: ";
	cin >> trcost;
}

//����� ������
void transport::output() {
	cout << "���������: " << trtitle << endl;
	cout << "��������� ���������������: " << trcost << endl;
}

void transport::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << trtitle << "\t";
	file << trcost << "\t";
}

void transport::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	int flag = 0;
	string buff;
	try {
		file >> trtitle;
		while (!flag) {
			file >> buff;
			if (buff[0] >= '0' && buff[0] <= '9') {
				trcost = stoi(buff);
				flag = 1;
			}
			else {
				trtitle += " ";
				trtitle += buff;
			}
		}
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������ ��� ������� ������� ��� �����.\n");
	}

}
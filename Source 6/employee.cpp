#include "employee.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include "checkfileextension.h"

//�������� �������� ���� counter
int employee::counter = 0;

//����������� ������ employee ��� ����������
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

//����������� ������ employee � ����� ����������
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
		cout << "���� ������� ������������ �������� allfields (allfields < 0)." << endl;
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

//����������� ������ employee �� ����� �����������
employee::employee(jobtitle jitle, equipment equip, transport tran, meleeweapon melee, firearms<int> fire) {
	counter++;
	id = counter;
	this->equip = equip;
	this->jtitle = jtitle;
	this->tran = tran;
	this->melee = melee;
	this->fire = fire;
}

//����� ������� ������ employee
void employee::output() {
	cout << "ID: " << this->id << endl;
	jtitle.output();
	equip.output();
	tran.output();
	melee.output();
	fire.output();
}

//����� ����� employee
void employee::input() {
	cout << "������� ID: ";
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

//����� �������� ������
int employee::empcost() {
	int salary = 0; //�������
	salary += jtitle.monthcost + equip.cost + tran.trcost + melee.wepcost + fire.wepcost;
	return salary;
}

//����� ������ ���� counter
void employee::printcounter() {
	cout << "���������� ����������: " << counter << endl;
}

//����� ����������� �������� ���� counter �� 1
void employee::minuscounter() {
	counter--;
	cout << "���������� ���������� ��������� �� 1." << endl;
}

//����� ����������� �������� ���� counter �� �������� ��������
void employee::minuscounter(int number) {
	int x = counter;
	counter = counter - number;
	cout << "���������� ���������� �������� � " << x << " �� " << counter << endl;
}

//���������� ��������� +
employee employee::operator + (employee e1) {
	id = id + e1.id;
	return *this;
}

//���������� ��������� ++ ����������
employee& employee::operator++() {
	id++;
	return *this;
}

//���������� ��������� ++ �����������
employee employee::operator++(int) {
	employee temp = *this;
	++* this;
	return temp;
}

//�����, ������������ �������� ����� ���������
employee* employee::get() {
	return this;
}

//�����, ������������ �������� ����� ������
employee& employee::getadress() {
	return *this;
}

void employee::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << id << "\t";
	jtitle.tofile(file,filename);
	equip.tofile(file, filename);
	melee.tofile(file, filename);
	fire.tofile(file, filename);
	tran.tofile(file,filename);

}


void employee::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	try {
		file >> id;
		jtitle.getfromfile(file,filename);
		equip.getfromfile(file, filename);
		melee.getfromfile(file, filename);
		fire.getfromfile(file, filename);
		tran.getfromfile(file,filename);
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������ ��� ������� ������� ��� �����.\n");
	}
}
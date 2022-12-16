#pragma once
#include "jobtitle.h"
#include "equipment.h"
#include "transport.h"
#include "meleeweapon.h"
#include "firearms.h"
#include "checkfileextension.h"
#include <fstream>
#include <string>

using namespace std;

class employee {
public:
	employee(jobtitle jtitle, equipment equip, transport tran, meleeweapon melee, firearms<int> fire);
	employee(int allfields);
	employee();
	void output();
	void input();
	int empcost();
	void printcounter();
	void minuscounter();
	void minuscounter(int number);
	employee operator + (employee e1);
	employee& operator++(); //префиксный
	employee operator++(int); //постфиксный
	employee* get(); //метод, возвращающий значение через указатель
	employee& getadress(); //метод, возвращающий значение через ссылку
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	static int counter;
	int id; //индивидуальный номер
	jobtitle jtitle; //должность
	equipment equip; //снаряжение
	transport tran; //транспорт
	firearms<int> fire; //огнестрельное оружие
	meleeweapon melee; //оружие ближнего боя
};

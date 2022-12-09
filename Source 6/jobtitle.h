#pragma once
#include "checkfileextension.h"
#include <string>
#include <fstream>
using namespace std;

class equipment;

class jobtitle
{
	friend class employee;
	friend float costcomparison(jobtitle jtitle, equipment equip);
public:
	jobtitle(string jtitle, int monthcost);
	jobtitle(int allfields);
	jobtitle();
	void input();
	void output();
	jobtitle operator + (jobtitle j1);
	jobtitle& operator++(); //префиксный
	jobtitle operator++(int); //постфиксный
	jobtitle* get(); //метод, возвращающий значение через указатель
	jobtitle& getadress(); //метод, возвращающий значение через ссылку
	void editjtitle(string jtitle, string add);
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	string jtitle; //наименование должности
	int monthcost; //зарплата
};


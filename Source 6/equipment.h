#pragma once
#include "checkfileextension.h"
#include <string>
#include <fstream>

using namespace std;

class jobtitle;

class equipment
{
	friend class employee;
	friend float costcomparison(jobtitle jtitle, equipment equip);
public:
	equipment(string eqtitle, int cost);
	equipment(int allfields);
	equipment();
	void input();
	void output();
	equipment operator + (equipment e1);
	equipment& operator++(); //префиксный
	equipment operator++(int); //постфиксный
	equipment* get(); //метод, возвращающий значение через указатель
	equipment& getadress(); //метод, возвращающий значение через ссылку
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	string eqtitle; //наименование экипировки
	int cost; //стоимость экипировки
};


#pragma once
#include "checkfileextension.h"
#include <string>
#include <fstream>
using namespace std;

class weapon
{
	friend class employee;

protected:
	string weptitle;
	int wepcost;

public:
	friend ostream& operator<< (ostream& os,weapon& weapon1);
	friend istream& operator>> (istream& os,weapon& weapon1);
	weapon();
	weapon(int allfields);
	weapon(string weptitle, int wepcost);
	virtual void input();
	virtual void output();
	virtual void tofile(ofstream& file, string filename) = 0;
	virtual void getfromfile(ifstream& file, string filename);
};


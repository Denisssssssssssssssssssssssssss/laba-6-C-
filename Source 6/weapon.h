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
	weapon();
	weapon(int allfields);
	weapon(string weptitle, int wepcost);
	virtual void input();
	virtual void output();
	virtual void tofile(ofstream& file, string filename);
	virtual void getfromfile(ifstream& file, string filename);
};


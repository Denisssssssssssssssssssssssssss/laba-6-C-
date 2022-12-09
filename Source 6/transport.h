#pragma once
#include "checkfileextension.h"
#include <string>
#include <fstream>
using namespace std;

class transport
{
	friend class employee;
private:
	string trtitle;
	int trcost;
public:
	transport();
	transport(int allfields);
	transport(string trtitle, int trcost);
	void input();
	void output();
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
};


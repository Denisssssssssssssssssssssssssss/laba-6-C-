#pragma once
#include <string>
#include "weapon.h"

class meleeweapon : public weapon
{
	friend ostream& operator<< (ostream& os, meleeweapon& subemployee);
	friend istream& operator>> (istream& os, meleeweapon& subemployee);
private:
	string damage;
public:
	meleeweapon();
	meleeweapon(int allfields);
	meleeweapon(string weptitle, int wepcost,string damage);
	virtual void output() override;
	virtual void input() override;
	void tofile(ofstream& file, string filename) override;
	void getfromfile(ifstream& file, string filename) override;
	meleeweapon operator= (meleeweapon mel);
};


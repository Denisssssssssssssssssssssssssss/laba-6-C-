#include <iostream>
#include <Windows.h>
#include "firearms.h"
#include "meleeweapon.h"



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    meleeweapon meleeweapon (50), meleeweapon1(1);
    int wepcost = 19;
    string weptitle = "Вепрь";
    int range = 19;
    string damage = "нелетальное";
    firearms<int>firearms(weptitle, wepcost, range);
    firearms.output();
    cout << firearms << endl;
    weapon* weapon1;
    weapon1 = &meleeweapon;
    weapon1->output();;
    cout << endl;
    weapon* wep;
    wep = &meleeweapon;
    wep = &meleeweapon;
    cout << endl;
    cout << meleeweapon;
    cout << endl << endl;
    cout << endl;
    firearms.output();
    return 0;
}
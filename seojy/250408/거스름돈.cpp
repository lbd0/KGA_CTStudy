#include <iostream>

#pragma once


using namespace std;

int GetChange(int money)
{
	int Five_H = money / 500;
	money -= Five_H * 500;

	int One_H = money / 100;
	money -= One_H * 100;

	int fifty = money / 50;
	money -= fifty * 50;

	int ten = money / 10;
	money -= ten * 50;

	return Five_H + One_H + fifty + ten;
}

int main()
{
	int money = 1890;

	int change = GetChange(money);
	cout << change << endl;
}

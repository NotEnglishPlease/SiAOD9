#pragma once
#include <iostream>
#include <string>

using namespace std;

struct fullName
{
	string name;
	string surname;
	string patronymic;
};

struct address
{
	string street;
	int houseNum;
	int flatNum;
};

struct bankAcc
{
	int accNum;
	fullName accName;
	address accAddres;
};
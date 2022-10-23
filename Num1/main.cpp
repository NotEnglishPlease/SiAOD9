#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cmath>
#include <chrono>
#include "Bank.h"

using namespace std;

bankAcc fillEl(int num);
void fillTable(vector <bankAcc>& accs, int n);
int linearFind(vector <bankAcc> accs, int num);
int barrierFind(vector <bankAcc> accs, int num);
void fillHashTable(vector <bankAcc>& accs, int n);
int hashFind(vector <bankAcc> accs, int num);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	string stop = "\n----------------------------------------------------------------------------\n", option;
	short problem;
	bool flag = true;
	int n, num, k;
	vector <bankAcc> accs;
	auto begin = chrono::steady_clock::time_point();
	auto end = chrono::steady_clock::time_point();
	while (flag)
	{
		system("cls");
		cout << "������������ ������ �9 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"����\n"
			"1) �������� �����.\n"
			"2) ����� � ��������.\n"
			"3) ����� � ����������� ������� �����������.\n"
			"4) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
		{
			cout << "������� ���������� ��������, ������� ���������� �������:";
			cin >> n;
			accs.resize(n);
			fillTable(accs, n);
			num = accs[rand() % n].accNum;
			begin = chrono::steady_clock::now();
			cout << "���������� ���������: " << linearFind(accs, num) << '\n';
			end = chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			cout << "����������� �����: " << elapsed_ms.count() << " ��.\n";
			accs.clear();
			system("pause");
			break;
		}
		case 2:
		{
			cout << "������� ���������� ��������, ������� ���������� �������:";
			cin >> n;
			accs.resize(n);
			fillTable(accs, n);
			num = accs[rand() % n].accNum;
			begin = chrono::steady_clock::now();
			cout << "���������� ���������: " << barrierFind(accs, num) << '\n';
			end = chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			cout << "����������� �����: " << elapsed_ms.count() << " ��.\n";
			accs.clear();
			system("pause");
			break;
		}
		case 3:
		{
			cout << "������� ���������� ��������, ������� ���������� �������:";
			cin >> n;
			accs.resize(n);
			fillHashTable(accs, n);
			num = accs[rand() % n].accNum;
			begin = chrono::steady_clock::now();
			cout << "���������� ���������: " << hashFind(accs, num) << '\n';
			end = chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			cout << "����������� �����: " << elapsed_ms.count() << " ��.\n";
			accs.clear();
			system("pause");
			break;
		}
		case 5:
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

bankAcc fillEl(int num)
{
	vector <string> names = { "�����", "�������", "������", "����", "���������", "�����", "������", "������", "����", "�����" };
	vector <string> surnames = { "������", "�������", "��������", "�������", "�����", "�������", "������", "�������", "�������", "������" };
	vector <string> patronymics = { "�������������", "����������", "����������", "���������", "���������", "����������", "���������", "�����", "����������", "����������" };
	vector <string> streets = { "�����������", "����������", "��������", "���������", "�������", "������", "�����", "����", "����������", "������" };
	bankAcc tempAcc;
	int randNum;
	if (num == 0)
	{
		randNum = rand() % 10;
		tempAcc.accName.name = names[randNum];
		randNum = rand() % 10;
		tempAcc.accName.surname = surnames[randNum];
		randNum = rand() % 10;
		tempAcc.accName.patronymic = patronymics[randNum];
		randNum = rand() % 10;
		tempAcc.accAddres.street = streets[randNum];
		tempAcc.accNum = rand() % 9999999 + 1000000;
		tempAcc.accAddres.houseNum = rand() % 100 + 1;
		tempAcc.accAddres.flatNum = rand() % 100 + 1;
	}
	else
	{
		tempAcc.accNum = num;
		randNum = rand() % 10;
		tempAcc.accName.name = names[randNum];
		randNum = rand() % 10;
		tempAcc.accName.surname = surnames[randNum];
		randNum = rand() % 10;
		tempAcc.accName.patronymic = patronymics[randNum];
		randNum = rand() % 10;
		tempAcc.accAddres.street = streets[randNum];
		tempAcc.accAddres.houseNum = rand() % 100 + 1;
		tempAcc.accAddres.flatNum = rand() % 100 + 1;
	}
	return tempAcc;
}

void fillTable(vector <bankAcc>& accs, int n)
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		accs[i] = fillEl(0);
		if (i > 0) 
			while (flag == true) 
				for (int j = 0; j < i; j++)
				{
					if (accs[i].accNum == accs[j].accNum)
					{
						accs[i] = fillEl(0);
						flag = true;
						break;
					}
					else
					{
						flag = false;
					}
				}
		flag = true;
	}
}

int linearFind(vector <bankAcc> accs, int num)
{
	int comparisons = 0;
	for (int i = 0; i < accs.size(); i++)
	{
		comparisons++;
		if (accs[i].accNum == num)
		{
			return comparisons;
		}
		comparisons++;
	}
}

int barrierFind(vector <bankAcc> accs, int num)
{
	int comparisons = 0;
	bankAcc barrier;
	barrier.accNum = num;
	accs.push_back(barrier);
	for (int i = 0; accs[i].accNum != num; i++) {
		comparisons++;
	}
	return comparisons;
}

void fillHashTable(vector <bankAcc>& accs, int n)
{
	int randNum, keyNum;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		while (flag == true) {
			randNum = rand() % 9999999 + 1000000;
			for (int j = 0; j < n; j++)
			{
				if (accs[j].accNum == randNum)
				{
					randNum = rand() % 9999999 + 1000000;
					flag = true;
					break;
				}
				else
				{
					flag = false;
				}
			}
		}
		flag = true;
		keyNum = randNum % n;
		if (accs[keyNum].accNum == NULL)
		{
			accs[keyNum] = fillEl(randNum);
		}
		else
		{
			while (accs[keyNum].accNum != NULL)
			{
				if (keyNum == n - 1) 
				{
					keyNum = 0;
				}
				else 
				{
					keyNum++;
				}
			}
			accs[keyNum] = fillEl(randNum);
		}
	}
}

int hashFind(vector <bankAcc> accs, int num)
{
	int comparisons = 0;
	int index = num % accs.size();
	while ((accs[index].accNum != num) && (accs[index].accNum != NULL))
	{
		if (index == accs.size()) 
		{
			index = 0;
			comparisons++;
		}
		else {
			comparisons++;
			index++;
		}
		comparisons++;
	}
	accs[index].accNum = 0;
	return comparisons;
}
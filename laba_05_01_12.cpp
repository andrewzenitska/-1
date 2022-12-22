#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "List.h"
#include "Keeper.h"
#include "Tree.h"
#include "Member.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Keeper kipper;
	int c;

	while (true)
	{
		cout << "\n����"
			<< "\n1.�������������� �� �����"
			<< "\n2.�������� ��������"
			<< "\n3.����� ������ �� �����"
			<< "\n4.������� ��������"
			<< "\n5.���������� � ����"
			<< "\n0.����� ��� ����������\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			std::string F;
			cout << "\t������� �������� �����: ";
			getline(cin, F);
			getline(cin, F);
			if (kipper.loadFromFile(F))
				cout << "\t������ ������� ���������\n";
			else
				cout << "\t���� �� ������ ��� ��������\n";
			break; }
		case 2: {

			std::string FIO, parents, lover, children, birth, death;
			int age;
			cout << "\t������� ���: ";
			getline(cin, FIO);
			getline(cin, FIO);
			cout << "\t������� ������ � ���������: ";
			getline(cin, parents);
			cout << "\t������� ������ � �������: ";
			getline(cin, lover);
			cout << "\t������� ������ � �����: ";
			getline(cin, children);
			cout << "\t������� ���� ��������: ";
			getline(cin, birth);
			cout << "\t������� ���� ������: ";
			getline(cin, death);
			cout << "\t������� �������: ";
			cin >> age;
			kipper.addElem(new Member(FIO, parents, lover, children, birth, death, age));
			cout << "\t������� �" << kipper.size() << " ������� ��������\n";

			break; }
		case 3: {
			if (kipper.size() == 0)
				cout << "\t���� �����������.\n";
			else
				kipper.printAll();
			break; }
		case 4: {
			if (kipper.size() == 0)
				cout << "\t���� �����������.\n";
			else
			{
				size_t num;
				cout << "\t�������� ��������. ��������: �"
					<< (kipper.size() == 1 ? "" : "1 - �")
					<< (kipper.size() == 1 ? 1 : kipper.size())
					<< "\n\t->";
				cin >> num;
				try
				{
					kipper.deleteElem(num - 1);
					cout << "\t������ ������� �������\n";
				}
				catch (int)
				{
					cout << "\t������� ������������ ��������!\n";
				}
			}
			break; }
		case 5: {
			if (kipper.saveToFile("save.txt"))
				cout << "\t������ ������� ���������\n";
			else
				cout << "\t��� ���������� ��������� ������\n";
			break; }
		case 0: {
			cout << "\t\t  ��� ������������� ������ ����� �������!"
				<< "\n\t\t  ����������?(1-�� / 0-���)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
}

/*
����������� ����� Keeper, ������� ��������� ��������� ��� �������� �
��������� ��������. ����� Keeper ������ ������������ ��������� �������:
	? ���������� � �������� ����������� �������� ������������ ������ Base;
	? ������ ���������� ���� � �����;
	? ������ �������������� ���� �� �����.


����� ��������� ������ ������ ������ � �����.
������ ���� ����� �����:
	���, ������ � ���������, ������ � �������, ������ � ����� �����,
	���� ��������, ���� ������ (���� ����), �������.
*/
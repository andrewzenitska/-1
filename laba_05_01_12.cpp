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
		cout << "\nМеню"
			<< "\n1.Восстановление из файла"
			<< "\n2.Добавить человека"
			<< "\n3.Вывод данных на экран"
			<< "\n4.Удалить человека"
			<< "\n5.Сохранение в файл"
			<< "\n0.Выход без сохранения\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			std::string F;
			cout << "\tВведите название файла: ";
			getline(cin, F);
			getline(cin, F);
			if (kipper.loadFromFile(F))
				cout << "\tДанные успешно загружены\n";
			else
				cout << "\tФайл не найден или повреждён\n";
			break; }
		case 2: {

			std::string FIO, parents, lover, children, birth, death;
			int age;
			cout << "\tВведите ФИО: ";
			getline(cin, FIO);
			getline(cin, FIO);
			cout << "\tВведите данные о родителях: ";
			getline(cin, parents);
			cout << "\tВведите данные о супруге: ";
			getline(cin, lover);
			cout << "\tВведите данные о детях: ";
			getline(cin, children);
			cout << "\tВведите дату рождения: ";
			getline(cin, birth);
			cout << "\tВведите дату смерти: ";
			getline(cin, death);
			cout << "\tВведите возраст: ";
			cin >> age;
			kipper.addElem(new Member(FIO, parents, lover, children, birth, death, age));
			cout << "\tчеловек №" << kipper.size() << " успешно добавлен\n";

			break; }
		case 3: {
			if (kipper.size() == 0)
				cout << "\tЛюди отсутствуют.\n";
			else
				kipper.printAll();
			break; }
		case 4: {
			if (kipper.size() == 0)
				cout << "\tЛюди отсутствуют.\n";
			else
			{
				size_t num;
				cout << "\tВыбирите человека. Доступны: №"
					<< (kipper.size() == 1 ? "" : "1 - №")
					<< (kipper.size() == 1 ? 1 : kipper.size())
					<< "\n\t->";
				cin >> num;
				try
				{
					kipper.deleteElem(num - 1);
					cout << "\tДанные успешно удалены\n";
				}
				catch (int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 5: {
			if (kipper.saveToFile("save.txt"))
				cout << "\tДанные успешно сохранены\n";
			else
				cout << "\tПри сохранении произошла ошибка\n";
			break; }
		case 0: {
			cout << "\t\t  Все несохраненные данные будут утеряны!"
				<< "\n\t\t  Продолжить?(1-Да / 0-Нет)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
}

/*
Разработать класс Keeper, который реализует контейнер для хранения и
обработки объектов. Класс Keeper должен обеспечивать следующие функции:
	? добавление и удаление производных объектов абстрактного класса Base;
	? полное сохранение себя в файле;
	? полное восстановление себя из файла.


Класс Фамильное дерево хранит данные о семье.
Каждый член семьи имеет:
	ФИО, знания о родителях, знания о супруге, знания о своих детях,
	дату рождения, дату смерти (если есть), возраст.
*/
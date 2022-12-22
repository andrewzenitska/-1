#include "Keeper.h"

Keeper::Keeper()
{
	std::cout << "Keeper\n";
}

Keeper::~Keeper()
{
	std::cout << "~Keeper\n";
	while(!trees.empty())
		delete trees.pop(0);
}

void Keeper::deleteElem(size_t position)
{
	delete trees.pop(position);
}

void Keeper::addElem(Tree* elem)
{
	trees.push_back(elem);
}

int Keeper::saveToFile(std::string file)
{
	std::ofstream fout(file);
	if (!fout) return 0;
	fout << to_string(trees.size()) << std::endl;
	for (size_t i = 0; i < trees.size(); ++i)
		fout << trees[i]->data();

	fout.close();
	return 1;
}

int Keeper::loadFromFile(std::string file)
{
	try
	{

		List<Tree*> temp;
		std::ifstream fin(file);
		if (!fin) return 0;
		std::string FIO, parents, lover, children, birth, death;
		int age;
		size_t trees_am;
		fin >> trees_am;
		for (size_t i = 0; i < trees_am; i++)
		{
			if (fin.eof()) return 0;
			getline(fin, FIO); if (fin.eof()) return 0;
			getline(fin, FIO); if (fin.eof()) return 0;
			getline(fin, parents); if (fin.eof()) return 0;
			getline(fin, lover); if (fin.eof()) return 0;
			getline(fin, children); if (fin.eof()) return 0;
			getline(fin, birth); if (fin.eof()) return 0;
			getline(fin, death); if (fin.eof()) return 0;
			fin >> age;
			temp.push_back(new Member(FIO, parents, lover, children, birth, death, age));
		}
		fin >> age;
		if (!fin.eof()) return 0;
		for (size_t i = 0; i < trees_am; i++)
			trees.push_back(temp[i]);
		return 1;
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

void Keeper::printAll()
{
	for (size_t i = 0; i < trees.size(); i++)
		std::cout << "человек №" << i + 1 << ":\n" << trees[i]->data_print();
}

size_t Keeper::size()
{
	return trees.size();
}

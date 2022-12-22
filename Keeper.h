#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Tree.h"
#include "Member.h"
class Keeper
{
private:
	List<Tree*> trees;

public:
	Keeper();
	~Keeper();
	void deleteElem(size_t position);
	void addElem(Tree* elem);
	int saveToFile(std::string file);
	int loadFromFile(std::string file);
	void printAll();
	size_t size();
};

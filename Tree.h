#pragma once
#include <iostream>
#include <string>
class Tree
{
public:
	Tree();
	virtual ~Tree();
	virtual std::string data() = 0;
	virtual std::string data_print() = 0;
};


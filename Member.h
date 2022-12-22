#pragma once
#include <string>
#include "Tree.h"
class Member :
    public Tree
{
private:
	std::string FIO, parents, lover, children, birth, death;
	int age;
public:
    Member(std::string FIO, std::string parents, std::string lover, std::string children, std::string birth, std::string death, int age);
    ~Member();
    std::string data() override;
    std::string data_print() override;
};


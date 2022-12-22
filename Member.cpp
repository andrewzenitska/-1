#include "Member.h"

Member::Member(std::string FIO, std::string parents, std::string lover, std::string children, std::string birth, std::string death, int age) :
	FIO(FIO), parents(parents), lover(lover), children(children), birth(birth), death(death), age(age)
{
	std::cout << "Member\n";
}

Member::~Member()
{
	std::cout << "~Member\n";
}

std::string Member::data()
{
	return FIO + "\n" + parents + "\n" + lover + "\n" + children + "\n" + birth + "\n" + death + "\n" + std::to_string(age) + "\n";
}

std::string Member::data_print()
{
	return "\n\tФИО: " + FIO +
		"\n\tродители: " + parents +
		"\n\tсупруг(а): " + lover +
		"\n\tдети: " + children +
		"\n\tдата рождения: " + birth +
		"\n\tдата смерти: " + death +
		"\n\tвозраст: " + std::to_string(age) + "\n";
}

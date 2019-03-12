#pragma once
#include <string>
#include <vector>
#include <map>

class Lab1
{
private:
	const std::string EXIT_CMD = "/exit";
	const std::string ADD_CMD = "/e";
	const std::string PRINT_CMD = "/p";
	const std::string MAX_CMD = "/x";
	const std::string MIN_CMD = "/n";
	const std::vector<unsigned int>::value_type MAX_MARSK = 5;


	struct Semestr
	{
		unsigned int _marksCount;
		unsigned int _semester;
	};

	struct Student
	{
		std::string _surName;
		std::string _group;
		std::vector<unsigned int> _examMarks;
		std::vector<unsigned int> _marks;
	};

	std::vector<Student> _students;
	std::map<unsigned int, Semestr> _semestrs;

	void AddStudent();
	void PrintStudent();
	void MaxAverageMark();
	void MinAverageMark();

public:
	Lab1();

	void BeginInput();

	~Lab1();
};


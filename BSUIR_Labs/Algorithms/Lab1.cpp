#include "Lab1.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include "..\Generic\ParseInput.h"
#include "..\Generic\\SaveInput.h"

Lab1::Lab1()
{
	Semestr sem_1 = { 4, 1 };
	_semestrs.insert(std::pair<unsigned int, Semestr>(sem_1._semester, sem_1));

	Semestr sem_2 = { 3, 2 };
	_semestrs.insert(std::pair<unsigned int, Semestr>(sem_2._semester, sem_2));

	Semestr sem_3 = { 5, 3 };
	_semestrs.insert(std::pair<unsigned int, Semestr>(sem_3._semester, sem_3));

	Semestr sem_4 = { 4, 4 };
	_semestrs.insert(std::pair<unsigned int, Semestr>(sem_4._semester, sem_4));
	
	Student stud_2 = { "Aly", "881063", std::vector<unsigned int>{ 1, 1, 1}, std::vector<unsigned int>{ 21, 1, 1} };
	_students.push_back(stud_2);

	Student stud_1 = { "Alexey", "881063", std::vector<unsigned int>{ 1, 1, 1}, std::vector<unsigned int>{ 1, 1, 1} };
	_students.push_back(stud_1);
}

void Lab1::BeginInput()
{
	ParseInput parse;
	std::string command;
	std::string input;

	std::string::const_iterator iter;
	do
	{
		std::cout << ">";
		input = parse.GetInput();
		iter = input.begin();
		command = parse.GetCmd(input.begin(), input.end());

		if (command == "")
			std::cout << "Invalid command!\n";
		else
		{
			try
			{
				if (command == ADD_CMD)
				{
					AddStudent(); SaveInput::CleatInput(); continue;
				}
				if (command == PRINT_CMD)
				{
					PrintStudent(); SaveInput::CleatInput(); continue;
				}
				if (command == MAX_CMD)
				{
					MaxAverageMark(); continue;
				}
				if (command == MIN_CMD)
				{
					MinAverageMark(); continue;
				}
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << "\n";
			}
		}
	} while (command != EXIT_CMD);
}

void Lab1::AddStudent()
{
	Student newStudent;

	std::cout << "SurName: ";
	std::string surName;
	SaveInput::Input(surName);

	std::cout << "Group: ";
	std::string group;
	SaveInput::Input(group);

	std::cout << "Semestr: ";
	unsigned int semestr;
	SaveInput::Input(semestr);

	newStudent._surName = surName;
	newStudent._group = group;
	
	std::map<unsigned int, Semestr>::const_iterator iter = _semestrs.find(semestr);
	
	std::cout << "Input " << iter->second._marksCount << " exam marks: ";
	unsigned int mark;
	for (unsigned int i = 0; i != iter->second._marksCount; i++)
	{
		SaveInput::Input(mark);
		newStudent._examMarks.push_back(mark);
	}

	std::cout << "Input " << iter->second._marksCount << " marks: ";
	for (unsigned int i = 0; i != MAX_MARSK; i++)
	{
		SaveInput::Input(mark);
		newStudent._marks.push_back(mark);
	}

	_students.push_back(newStudent);
}

void Lab1::PrintStudent()
{
	std::cout << "Student surName: ";
	std::string surName;
	SaveInput::Input(surName);

	std::vector<Student>::const_iterator iter = std::find_if(_students.begin(), _students.end(), 
		[&](Student &item) { return item._surName == surName; });

	if (iter != _students.end())
	{
		std::cout << " | Student: \nSurName: " << iter->_surName << 
			"\nGroup: " << iter->_group << 
			"\nSem: " << iter->_examMarks.size();

		std::cout << "\nMarsk: ";

		for (std::vector<unsigned int>::const_iterator mark_iter = iter->_marks.begin(); 
			mark_iter != iter->_marks.end(); mark_iter++)
				std::cout << *mark_iter << " ";

		std::cout << "\nExam marsk: ";

		for (std::vector<unsigned int>::const_iterator mark_iter = iter->_examMarks.begin();
			mark_iter != iter->_examMarks.end(); mark_iter++)
			std::cout << *mark_iter << " ";
	}
	else
	{
		std::cout << "\nCannot find student by surname!";
	}
	std::cout << "\n";
}

void Lab1::MaxAverageMark()
{
	unsigned int max = 0;
	unsigned int average = 0;
	std::vector<Student>::const_iterator student = _students.begin();

	for (std::vector<Student>::const_iterator iter = _students.begin(); iter != _students.end(); iter++)
	{	
		average = std::accumulate(iter->_marks.begin(), iter->_marks.end(), average);
		if (average > max)
		{
			max = average;
			student = iter;
		}
		average = 0;
	}

	if (student != _students.end())
	{
		std::cout << "Max average: " << max << " by " << student->_surName << " student";
	}
	else
	{
		std::cout << "\nStudent vectro is empty!";
	}
	std::cout << "\n";
}

void Lab1::MinAverageMark()
{
	unsigned int min = UINT32_MAX;
	unsigned int average = 0;
	std::vector<Student>::const_iterator student = _students.begin();

	for (std::vector<Student>::const_iterator iter = _students.begin(); iter != _students.end(); iter++)
	{
		average = std::accumulate(iter->_marks.begin(), iter->_marks.end(), average);
		if (average < min)
		{
			min = average;
			student = iter;
		}
		average = 0;
	}

	if (student != _students.end())
	{
		std::cout << "Max average: " << min << " by " << student->_surName << " student";
	}
	else
	{
		std::cout << "\nStudent vectro is empty!";
	}
	std::cout << "\n";
}

Lab1::~Lab1()
{
	_semestrs.clear();
	_students.clear();
}

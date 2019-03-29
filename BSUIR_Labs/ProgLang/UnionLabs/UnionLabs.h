#pragma once
#include <string>
#include <iostream>
#include <vector>

class UnionLabs
{
public:
	struct Enrollee
	{
		std::string _surName;
		std::string _country;
		std::string _city;
		float _avgCertifMark;
	};


private:

	template<class T>
	static void SaveInput(T& value)
	{
		std::cin >> value;
		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\tError: Invalid value!\n";
			std::cin >> value;
		}
	}

	static std::string ResutlOfLab1(const int &value_1, const int &value_2);

	static void Lab2_DoJob(int** matrix, const int &size);
	static void ShowMatrix(int** matrinx, const int &size);

	static bool Lab3_DoJob(const std::string &str, const std::string &pattern);

	static void Lab4_DoJob(const std::vector<Enrollee> &vec);
	static void Lab4_Display(const std::vector<Enrollee>::const_iterator begin, 
		std::vector<Enrollee>::const_iterator end);

	static void Lab5_DoJob(std::string firstFile, std::string secondFile);

public:
	static void InputLab1();
	static void InputLab2();
	static void InputLab3();
	static void InputLab4();
	static void InputLab5();
};
#pragma once
#include <string>
#include <iostream>

class UnionLabs
{
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

public:
	static void InputLab1();
	static void InputLab2();
	static void InputLab3();
};
#include "UnionLabs.h"

std::string UnionLabs::ResutlOfLab1(const int &value_1, const int &value_2)
{
	return std::to_string(value_1) + (value_1 > value_2 ? "" : " " + std::to_string(value_2));
}

void UnionLabs::ShowMatrix(int** matrix, const int &size)
{
	for (int i = 0; i != size; i++)
	{
		for (int j = 0; j != size; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void UnionLabs::Lab2_DoJob(int** matrix, const int &size)
{
	int* maxOnDigs = &matrix[0][0];

	for (int i = 0; i != size; i++)
	{
		if (matrix[i][i] > *maxOnDigs)
			maxOnDigs = &matrix[i][i];

		if (matrix[i][size - 1 - i] > *maxOnDigs)
			maxOnDigs = &matrix[i][size - 1 - i];
	}
	std::swap(*maxOnDigs, matrix[size / 2][size / 2]);
}

bool UnionLabs::Lab3_DoJob(const std::string &str, const std::string &pattern)
{
	bool contains = false;
	for (std::string::const_iterator iter = pattern.begin(); iter != pattern.end(); iter++)
	{
		contains = str.find(*iter) != std::string::npos;
	}
	return contains;
}

void UnionLabs::InputLab1()
{
	int firstValue;
	std::cout << "\tLab 1\nInput: ";
	SaveInput(firstValue);
	int secondValue;
	SaveInput(secondValue);
	
	std::cout << "\nResult: " << ResutlOfLab1(firstValue, secondValue);
}

void UnionLabs::InputLab2()
{
	int n;
	std::cout << "\n\n\tLab 2\nMatrix size: ";
	SaveInput(n);

	int** matrix = new int*[n];

	int value;
	for (int i = 0; i != n; i++)
	{
		matrix[i] = new int[n];
		std::cout << "[" << i << "]: ";
		for (int j = 0; j != n; j++)
		{
			SaveInput(value);
			matrix[i][j] = value;
		}
	}
	std::cout << "\nMatrix before...\n";
	ShowMatrix(matrix, n);

	Lab2_DoJob(matrix, n);

	std::cout << "\nMatrix after...\n";
	ShowMatrix(matrix, n);


}

void UnionLabs::InputLab3()
{
	std::string inputStr;
	std::string pattern;

	std::cout << "\n\tLab 3\nInput pattern: ";
	std::getline(std::cin, pattern);
	std::cout << "Input str: ";
	std::getline(std::cin, inputStr);

	std::cout << "\nResult: " << (Lab3_DoJob(inputStr, pattern) ? "True" : "False");
}
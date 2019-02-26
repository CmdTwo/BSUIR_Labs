#include "UnionLabs.h"

std::string UnionLabs::ResutlOfLab1(const int &value_1, const int &value_2)
{
	return std::to_string(value_1) + (value_1 > value_2 ? "" : " " + std::to_string(value_2));
}

void UnionLabs::InputLab1()
{
	int firstValue;
	std::cout << "\nLab 1\nInput: ";
	SaveInput(firstValue);
	int secondValue;
	SaveInput(secondValue);

	std::cout << "\nResult: " << ResutlOfLab1(firstValue, secondValue);
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

		if (matrix[size - 1 - i][size - 1 - i] > *maxOnDigs)
			maxOnDigs = &matrix[size - 1 - i][size - 1 - i];
	}
	std::swap(*maxOnDigs, matrix[size / 2][size / 2]);
}

void UnionLabs::InputLab2()
{
	int n;
	SaveInput(n);

	int** matrix = new int*[n];

	for (int i = 0; i != n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j != n; j++)
		{
			matrix[i][j] = rand() % 9 + 1;
		}
	}
	std::cout << "\nLab2\nMatrix before...\n";
	ShowMatrix(matrix, n);

	Lab2_DoJob(matrix, n);

	std::cout << "\nMatrix after...\n";
	ShowMatrix(matrix, n);

}

bool UnionLabs::Lab3_DoJob(const std::string &str, const std::string &pattern)
{
	for (std::string::const_iterator iter = pattern.begin(); iter != pattern.end(); iter++)
	{
		if(str.find(*iter) != std::string::npos)
			return true;
	}
	return false;
}

void UnionLabs::InputLab3()
{
	std::string pattern = "DOS";
	std::string inputStr;
	std::getline(std::cin, inputStr);
	
	std::cout << "Has str \n- " << inputStr.c_str() << "\ncontains any latter like in '" << pattern << "' ?\nResult: " << (Lab3_DoJob(inputStr,pattern) ? "True" : "False");
}
#include "UnionLabs.h"
#include <numeric>
#include <algorithm>
#include <fstream>
#include <cctype>

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

void UnionLabs::Lab4_DoJob(const std::vector<Enrollee> &vec)
{
	float avg = std::accumulate(vec.begin(), vec.end(), 0.0, 
		[](float currentSum, Enrollee const& v)	{ return currentSum + v._avgCertifMark; });

	avg /= vec.size();

	std::vector<Enrollee> selectVect;
	
	std::copy_if(vec.begin(), vec.end(), std::back_inserter(selectVect),
		[&](const Enrollee &v) { return v._avgCertifMark >= avg; });

	std::sort(selectVect.begin(), selectVect.end(), 
		[](const Enrollee &x, const Enrollee &y) { return x._surName < y._surName; });
	
	std::cout << "\nAll unselected vector:\n\n";
	Lab4_Display(vec.begin(), vec.end());

	std::cout << "\nAverage mark: " << avg << "\n\nSelected and sorted vector:\n\n";
	Lab4_Display(selectVect.begin(), selectVect.end());

	std::ofstream file("Lab4File.txt");

	if (file.is_open())
	{
		file << "\nAverage mark: " << avg << "\n\nSelected and sorted vector:\n\n";
		for (std::vector<Enrollee>::const_iterator iter = selectVect.begin(); iter != selectVect.end(); iter++)
		{
			file << " " << iter->_surName << " (" << iter->_country << ", " << iter->_city
				<< ") " << iter->_avgCertifMark << "\n";
		}
	}

	file.close();
}

void UnionLabs::Lab4_Display(const std::vector<Enrollee>::const_iterator begin,
	std::vector<Enrollee>::const_iterator end)
{
	for (std::vector<Enrollee>::const_iterator iter = begin; iter != end; iter++)
	{
		std::cout << " " << iter->_surName << " (" << iter->_country << ", " << iter->_city
			<< ") " << iter->_avgCertifMark << "\n";
	}
}

void UnionLabs::Lab5_DoJob(std::string first, std::string second)
{
	std::ifstream readFile(first);
	std::ofstream writeFile(second);

	if (readFile.is_open() && writeFile.is_open())
	{
		std::string buffer;
		while (std::getline(readFile, buffer))
		{	
			std::string::const_iterator iter = std::find_if(buffer.begin(), buffer.end(),
				[](const char &c) { return std::isdigit(c); });

			if (iter == buffer.end())
			{
				writeFile << buffer << std::endl;
			}
		}

		readFile.close();
		writeFile.close();
	}
	else if(!readFile.is_open())
	{
		throw std::exception("Invalid read file name/path!");
	}
	else
	{
		throw std::exception("Invalid write file name/path!");
	}

	std::cout << "Complete!";
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

void UnionLabs::InputLab4()
{
	 std::vector<Enrollee> enrolleeVec;

	 //enrolleeVec.push_back(Enrollee{ "Bernikovich", "Belarus", "Minsk", 10 });
	 //enrolleeVec.push_back(Enrollee{ "Poshar", "Belarus", "Minsk", 3 });
	 //enrolleeVec.push_back(Enrollee{ "Marg", "Belarus", "Minsk", 5 });
	 //enrolleeVec.push_back(Enrollee{ "Alyn", "Belarus", "Minsk", 9 });

	 std::cout << "\n\tLab 4\nInput count: ";
	 size_t count;
	 SaveInput(count);

	 std::cout << "\n(Surname Country City Mark)\n\n";

	 for (size_t i = 0; i != count; i++)
	 {
		 Enrollee newItem;
		 float avg;

		 std::cout << "[" << (i + 1) << "]: ";
		 std::cin >> newItem._surName >> newItem._country >> newItem._city;
		 SaveInput(avg);

		 newItem._avgCertifMark = avg;

		 enrolleeVec.push_back(newItem);
	 }

	 Lab4_DoJob(enrolleeVec);


}

void UnionLabs::InputLab5()
{
	//std::string openFile;
	//std::cout << "Input first file name: ";
	//std::cin >> openFile;

	//std::string outFile;
	//std::cout << "Input second file name: ";
	//std::cin >> outFile;

	//Lab5_DoJob(openFile, outFile);
	Lab5_DoJob("Lab5_1.txt", "Lab5_2.txt");
}
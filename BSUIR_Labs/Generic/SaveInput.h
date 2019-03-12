#pragma once
#include <iostream>

class SaveInput
{
public:
	template<class T>
	static void Input(T& value)
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

	static void CleatInput()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};


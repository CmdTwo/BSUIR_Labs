#include <iostream>
#include <string>
#include "..\Generic\SaveInput.h"


#pragma region Labs

//#include "..\DataStructLabs\HashTable\HashTable.h"
//#include "..\DataStructLabs\PriorityQueue\PriorityQueue.h"
#include "..\ProgLang\UnionLabs\UnionLabs.h"
#pragma endregion


int main()
{
	try
	{
		//UnionLabs::InputLab4();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	SaveInput::CleatInput();
	std::cin.get();
}
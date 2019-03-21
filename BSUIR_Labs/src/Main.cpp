#include <iostream>
#include <string>
#include "..\Generic\SaveInput.h"


#pragma region Labs

//#include "..\DataStructLabs\HashTable\HashTable.h"
#include "..\DataStructLabs\PriorityQueue\PriorityQueue.h"

#pragma endregion


int main()
{
	try
	{
		PriorityQueue<int> queue = PriorityQueue<int>();

		queue.PushBack(1, 20);
		queue.PushBack(3, 90);
		queue.PushBack(4, 1);
		queue.PushBack(1512, 2);
		queue.PushBack(2, 30);
		queue.PushBack(2, 100);

		std::cout << "Debug print:\n\n";
		queue.DebugPrint();

		std::cout << "\n\nTry to find...\n";
		PriorityQueue<int>::const_iterator iter = queue.Find((float)90);
		std::cout << "Result: " << iter->_value << "(" << iter->_priority << ")\n";

		std::cout << "\nTry to remove...\n";
		queue.Remove(2);
		std::cout << "Result: complete";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	SaveInput::CleatInput();
	std::cin.get();
}
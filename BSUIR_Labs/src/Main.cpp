#include <iostream>
#include <string>
#include "..\Generic\SaveInput.h"


#pragma region Labs

#include "..\DataStructLabs\HashTable\HashTable.h"

#pragma endregion


int main()
{
	try
	{
		HashTable<std::string> hashTable = HashTable<std::string>();

		std::cout << "Inout any Key: ";
		std::string key;
		std::cin >> key;		

		std::cout << "Input any Value: ";
		std::string value;
		std::cin >> value;

		hashTable.Insert(key, value);
		std::cout << "\nValue has been inserted;\n";

		std::cout << "\nTry to get Value by Key...\n";
		std::cout << "Result: " << hashTable.Get(key) << "\n";

		std::cout << "\nTry to remove by Key...\n";
		hashTable.Remove(key);
		std::cout << "Value has been removed;\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	SaveInput::CleatInput();
	std::cin.get();
}
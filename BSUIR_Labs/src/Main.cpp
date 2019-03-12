#include <iostream>
#include <numeric>

#pragma region Examples

//#include "..\DataStructLabs\Polyno\Polyno.h"
//#include "..\DataStructLabs\Counting\Counting.h"
//#include "..\DataStructLabs\SingleList\SingleList.h"

//#include "..\ProgLang\UnionLabs\UnionLabs.h"

#include "..\Algorithms\Lab1.h"
#include "..\Algorithms\Lab2.h"

#pragma endregion

int main()
{
	try
	{		
		//Lab1 lab;
		//lab.BeginInput();

		Lab2 lab;
		lab.BeginInput();
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	//std::cin.get();
}
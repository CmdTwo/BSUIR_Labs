#include <iostream>
#include <time.h>

#pragma region Examples

//#include "..\DataStructLabs\Polyno\Polyno.h"
//#include "..\DataStructLabs\Counting\Counting.h"
//#include "..\DataStructLabs\SingleList\SingleList.h"

#include "..\ProgLang\UnionLabs\UnionLabs.h"

#pragma endregion


int main()
{
	std::srand(time(0));

	try
	{		
		//UnionLabs::InputLab1();
		//UnionLabs::InputLab2();
		//UnionLabs::InputLab3();
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}
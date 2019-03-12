#include <iostream>
#include <numeric>

#pragma region Examples

//#include "..\DataStructLabs\Polyno\Polyno.h"
//#include "..\DataStructLabs\Counting\Counting.h"
//#include "..\DataStructLabs\SingleList\SingleList.h"

//#include "..\ProgLang\UnionLabs\UnionLabs.h"

#include "..\Algorithms\Lab1.h"
#include "..\Generic\ParseInput.h"

#pragma endregion

int main()
{
	try
	{		
		Lab1 lab;
		lab.BeginInput();
		//ParseInput tmp;

		//std::string::size_type outSize;
		//std::string input = tmp.GetInput();

		//ParseInput::Cmd result;
		//tmp.ParseToCmd(result, input.begin(), input.end());

		//result._args.Clear();
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	//std::cin.get();
}
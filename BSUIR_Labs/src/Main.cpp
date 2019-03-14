#include <iostream>
#include <numeric>

#pragma region Examples

//#include "..\DataStructLabs\Polyno\Polyno.h"
//#include "..\DataStructLabs\Counting\Counting.h"
#include "..\DataStructLabs\SingleList\SingleList.h"
#include "..\DataStructLabs\DoubleList\DoubleList.h"

//#include "..\ProgLang\UnionLabs\UnionLabs.h"

#pragma endregion

struct Sub
{
	std::string _name;
	std::string _surName;
	std::string _phone;

	static bool CheckBySurname(const Sub &value, const std::string &surName)
	{
		return value._surName == surName;
	}

	static bool CheckByName(const Sub &value, const std::string &name)
	{
		return value._name == name;
	}

	static bool STakeByPhone(const Sub &value, const std::string &phone)
	{
		return value._phone == phone;
	}

	static bool CompareBySurname(const Sub &first, const Sub &second)
	{
		return first._surName[0] > second._surName[0];
	}

	static bool CompareByPhone(const Sub &first, const Sub &second)
	{
		int firstNumber = std::atoi(first._phone.substr(6, first._phone.length()).c_str());
		int secondNumber = std::atoi(second._phone.substr(6, second._phone.length()).c_str());
		return firstNumber > secondNumber;
	}
};

struct Phone
{
	std::string _phone;

	static bool CompareByMaxPhoneLenght(const Phone &value, const std::string::size_type &lenght)
	{
		return value._phone.size() > lenght;
	}

	static bool CompareByPhone(const Phone &first, const Phone &second)
	{
		int firstNumber = std::atoi(first._phone.c_str());
		int secondNumber = std::atoi(second._phone.c_str());

		return firstNumber > secondNumber;
	}
};

#pragma endregion

int main()
{
	try
	{		

		DoubleList<Phone> doubleList = DoubleList<Phone>();
		doubleList.PushBack(Phone{ "3463724" });
		doubleList.PushBack(Phone{ "102" });
		doubleList.PushBack(Phone{ "3467637" });
		doubleList.PushBack(Phone{ "103" });
		doubleList.PushBack(Phone{ "104" });
		doubleList.PushBack(Phone{ "5412566" });
		doubleList.PushBack(Phone{ "6136376" });
		doubleList.PushBack(Phone{ "101" });

		//for (DoubleList<Phone>::const_iterator iter = doubleList.rBegin(); iter != doubleList.rEnd(); iter = iter->_prev)
		//		std::cout << iter->_value._phone.c_str() << "\n";

		//std::cout << "\n";

		for (DoubleList<Phone>::const_iterator iter = doubleList.Begin(); iter != doubleList.End(); iter = iter->_next)
			std::cout << iter->_value._phone.c_str() << "\n";
		
		SingleList<Phone> singeList = SingleList<Phone>();

		std::cout << "\n";

		doubleList.rSelectTo<std::string::size_type>(singeList, 3, Phone::CompareByMaxPhoneLenght);

		for (SingleList<Phone>::const_iterator iter = singeList.Begin(); iter != singeList.End(); iter = iter->_next)
			std::cout << iter->_value._phone.c_str() << "\n";

		std::cout << "\n";

		singeList.SortBy(Phone::CompareByPhone);

			for (SingleList<Phone>::const_iterator iter = singeList.Begin(); iter != singeList.End(); iter = iter->_next)
				std::cout << iter->_value._phone.c_str() << "\n";

//		SingleList<Sub> single = SingleList<Sub>();
//		single.PushBack(Sub{ "Alexey", "Bern", "+375296385341" });
//		single.PushBack(Sub{ "Egor", "Kirich", "+375175351513" });
//		single.PushBack(Sub{ "Lera", "Bubble", "+375295321251" });
//		single.PushBack(Sub{ "Adolf", "Hitler", "+375179358185" });
//		single.PushBack(Sub{ "Zack", "Fallout", "+375179358185" });
//
//		for (SingleList<Sub>::const_iterator iter = single.Begin(); iter != single.End(); iter = iter->_next)
//			std::cout << iter->_value._name.c_str() << "\t" << iter->_value._phone.c_str() << "\n";
//
//#pragma region Sort
//
//		single.SortBy(Sub::CompareBySurname);
//		std::cout << "\nAfter sort:\n\n";
//
//		for (SingleList<Sub>::const_iterator iter = single.Begin(); iter != single.End(); iter = iter->_next)
//			std::cout << iter->_value._name.c_str() << "\t" << iter->_value._phone.c_str() << "\n";
//
//#pragma endregion
//
//		std::cout << "\n";
//
//#pragma region TakeBy
//
//		SingleList<Sub>* result = new SingleList<Sub>();
//		single.TakeBy<std::string>(result, "+375179358185", Sub::STakeByPhone);
//
//		std::cout << "Take result:\n\n";
//
//		for (SingleList<Sub>::const_iterator iter = result->Begin(); iter != result->End(); iter = iter->_next)
//			std::cout << iter->_value._name.c_str() << "\t" << iter->_value._phone.c_str() << "\n";
//
//#pragma endregion
//
//		std::cout << "\n";
//
//#pragma region Remove
//
//		single.PushBack(Sub{ "Mel", "Gachi", "+375179358185" });
//
//		std::cout << "Before remove:\n";
//
//		std::cout << "Count:" << single.Count() << "\n\n";
//
//		std::cout << "After remove:\n";
//
//		single.Remove(single.Find<std::string>("Mel", Sub::CheckByName));
//
//		std::cout << "Count:" << single.Count() << "\n";
//
//#pragma endregion

	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	std::cin.get();
}
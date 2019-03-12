#pragma once
#include <conio.h>

class KeyInput
{
public:
	enum Keys
	{
		NaN,
		F1,
		F2,
		Plus,
		Minus,
		Exclamation
	};

	static Keys GetKeyInput();
};
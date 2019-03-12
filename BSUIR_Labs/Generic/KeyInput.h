#pragma once
#include <conio.h>

class KeyInput
{
public:
	enum Keys
	{
		NaN,
		RightSlash,
		E,
		P,
		X,
		N,
		Esc
	};

	static Keys GetKeyInput();
};
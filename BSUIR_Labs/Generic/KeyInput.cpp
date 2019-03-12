#include "KeyInput.h"

 KeyInput::Keys KeyInput::GetKeyInput() 
{
	unsigned int first = _getch();
	unsigned int result;

	if (first == 0)
	{
		unsigned int second = _getch();
		result = second;
	}
	else
		result = first;

	
	switch (result)
	{
	case(33):
		return KeyInput::Exclamation; break;
	case(43):
		return KeyInput::Plus; break;
	case(95):
		return KeyInput::Minus; break;
	case(59):
		return KeyInput::F1; break;
	case(60):
		return KeyInput::F2; break;
	default:
		return KeyInput::NaN;
	}
}
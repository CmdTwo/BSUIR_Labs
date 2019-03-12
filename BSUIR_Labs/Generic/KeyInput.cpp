#include "KeyInput.h"

 KeyInput::Keys KeyInput::GetKeyInput() 
{
	unsigned int first = _getche();
	unsigned int second = _getche();

	unsigned int result = first + second;

	switch (result)
	{
	case(27):
		return KeyInput::Esc;
	case(47):
		return KeyInput::RightSlash;
	default:
		return KeyInput::NaN;
	}
}
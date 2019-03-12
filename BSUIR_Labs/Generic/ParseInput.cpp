#include "ParseInput.h"
#include <iostream>
#include <algorithm>

bool ParseInput::IsSeparator(const char &c)
{
	return c == SEPARATOR;
}

ParseInput::ParseInput()
{
}

std::string ParseInput::GetInput() const
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

std::string ParseInput::GetCmd(std::string::const_iterator begin, std::string::const_iterator end) const
{
	std::string::const_iterator cmdBegin = std::find(begin, end, CMD_CHAR);
	std::string::const_iterator cmdEnd = std::find(cmdBegin, end, SEPARATOR);
	return std::string(cmdBegin, cmdEnd);
}

ParseInput::~ParseInput()
{
}

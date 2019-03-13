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

void ParseInput::Split(std::string::const_iterator inBegin, std::string::const_iterator inEnd,
	std::vector<std::string> &container, const char &separator)
{
	std::string::const_iterator bFind = inBegin;
	std::string::const_iterator eFind = bFind;
	do
	{
		bFind = std::find_if_not(bFind, inEnd, [&](const char &c) { return c == ' '; });
		eFind = std::find_if(bFind, inEnd, [&](const char &c) { return c == ' '; });

		if (bFind != eFind)
		{
			container.push_back(std::string(bFind, eFind));
			bFind = eFind;
		}		

	}while(eFind != inEnd);
}

ParseInput::~ParseInput()
{
}

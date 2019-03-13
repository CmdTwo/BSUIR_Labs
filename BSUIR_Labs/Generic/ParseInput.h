#pragma once
#include <string>
#include <vector>

class ParseInput
{
private:
	static bool IsSeparator(const char &c);

public:

	struct Cmd
	{
	public:
		std::string _cmd;
		std::vector<std::string> _args;
	};

	static const char CMD_CHAR = '/';
	static const char SEPARATOR = ' ';

	ParseInput();

	std::string GetInput() const;

	std::string GetCmd(std::string::const_iterator begin, std::string::const_iterator end) const;
	void Split(std::string::const_iterator inBegin, std::string::const_iterator inEnd,
		std::vector<std::string> &container, const char &separator);

	~ParseInput();
};


#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Lab4
{
	const std::string OPEN_CMD = "/open";
	const std::string PRINT_CMD = "/print";
	const std::string ADD_CMD = "/add";
	const std::string REMOVE_CMD = "/remove";
	const std::string CLOSE_CMD = "/close";
	const std::string SORT_CMD = "/sort";
	const std::string EXIT_CMD = "/exit";

	struct FileItem
	{
		std::string _fullName;
		unsigned int _space;
		unsigned int _population;
	};
	std::string _fileName;
	std::ifstream _file;
	std::vector<FileItem> _fileItems;

public:
	Lab4();

	void BeginInput();

	void OpenFile();
	void PrintItems();
	void AddItem();
	void RemoveItem();
	void CloseFile();
	void SortBySpaceOnMan();

	
	~Lab4();
};


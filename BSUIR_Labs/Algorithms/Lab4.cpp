#include "Lab4.h"
#include "..\Generic\SaveInput.h"
#include "..\Generic\ParseInput.h"
#include <algorithm>

Lab4::Lab4()
{
}

void Lab4::BeginInput()
{
	ParseInput parse;
	std::string command;
	std::string input;

	std::string::const_iterator iter;
	do
	{
		std::cout << ">";
		input = parse.GetInput();
		iter = input.begin();
		command = parse.GetCmd(input.begin(), input.end());

		if (command == "")
			std::cout << "Invalid command!\n";
		else
		{
			try
			{
				if (command == OPEN_CMD)
				{
					OpenFile(); continue;
				}
				else if (command != EXIT_CMD)
				{
					if (_file.is_open())
					{
						if (command == PRINT_CMD)
						{
							PrintItems(); continue;
						}
						if (command == ADD_CMD)
						{
							AddItem(); continue;
						}
						if (command == REMOVE_CMD)
						{
							RemoveItem(); continue;
						}
						if (command == CLOSE_CMD)
						{
							CloseFile(); continue;
						}
						if (command == SORT_CMD)
						{
							SortBySpaceOnMan(); continue;
						}
					}
					else
					{
						std::cout << "Error: Open file first!\n\n";
					}
				}
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << "\n";
			}
		}
	} while (command != EXIT_CMD);
}

void Lab4::OpenFile()
{
	std::cout << "File name: ";
	SaveInput::Input(_fileName);

	_file = std::ifstream(_fileName);
	std::string buffer;

	if (_file.is_open())
	{
		std::vector<std::string> fileData;
		ParseInput parse;
		while (std::getline(_file, buffer))
		{
			parse.Split(buffer.begin(), buffer.end(), fileData, ' ');

			FileItem item = { fileData[0], std::atoi(fileData[1].c_str()), std::atoi(fileData[2].c_str()) };
			_fileItems.push_back(item);
			fileData.clear();
		}
		std::cout << "File has been opened...\n\n";
	}
	else
	{
		std::cout << "Failed open file operation. Try again...\n\n";
	}
	SaveInput::CleatInput();
}

void Lab4::PrintItems()
{
	for (std::vector<FileItem>::const_iterator iter = _fileItems.begin(); iter != _fileItems.end(); iter++)
	{
		std::cout << "N: " << iter->_fullName << " | S: " << iter->_space << " | P: " << iter->_population << "\n";
	}
}

void Lab4::AddItem()
{
	std::string fullName;
	std::cout << "New Item\nFull name: ";
	SaveInput::Input(fullName);

	unsigned int space;
	std::cout << "Space: ";
	SaveInput::Input(space);

	unsigned int popu;
	std::cout << "Population: ";
	SaveInput::Input(popu);
	   
	FileItem item = { fullName, space, popu };

	_fileItems.push_back(item);

	std::cout << "Item has added...\n\n";
	SaveInput::CleatInput();
}

void Lab4::RemoveItem()
{
	std::string fullName;
	std::cout << "Remove user\nFull name: ";
	SaveInput::Input(fullName);

	std::vector<FileItem>::const_iterator iter = std::find_if(_fileItems.begin(), _fileItems.end(),
		[&](const FileItem &item) { return item._fullName == fullName; });

	_fileItems.erase(iter);
	
	std::cout << "Item has removed...\n\n";

	SaveInput::CleatInput();
}

void Lab4::CloseFile()
{
	_file.close();

	std::ofstream writeFile(_fileName);

	for (std::vector<FileItem>::const_iterator iter = _fileItems.begin(); iter != _fileItems.end(); iter++)
	{
		writeFile << iter->_fullName << " " << iter->_space << " " << iter->_population << std::endl;
	}

	writeFile.close();
	_fileItems.clear();

	std::cout << "File has been closed...\n\n";
}

void Lab4::SortBySpaceOnMan()
{
	std::sort(_fileItems.begin(), _fileItems.end(), 
		[&](const FileItem &x, const FileItem &y) {return x._space / x._population > y._space / y._population; });

	std::cout << "File has been sorted by space on per man...\n\n";
}

Lab4::~Lab4()
{
}

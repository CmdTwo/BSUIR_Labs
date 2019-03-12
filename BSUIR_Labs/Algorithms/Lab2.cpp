#include "Lab2.h"
#include <iostream>
#include "..\Generic\KeyInput.h"
#include <string>

Lab2::Lab2()
{
}

void Lab2::BeginInput()
{
	KeyInput::Keys key;
	do
	{
		key = KeyInput::GetKeyInput();;

		switch (key)
		{
		case KeyInput::NaN:
			break;
		case KeyInput::F1:
			Print(); break;
		case KeyInput::Plus:
			AddStudent(); break;
		case KeyInput::Minus:
			RemoveStudent(); break;
		case KeyInput::Exclamation:
			PushToStack(); break;
		default:
			break;
		}
	} while (key != KeyInput::Keys::F2);
}

void Lab2::Print()
{
	if (_stack.size() != 0)
	{
		std::queue<std::string>* current = _stack.top();
		std::cout << "Curren count: " << current->size() << "\n";
	}
	else
		std::cout << "Stack not init!\n";
}

void Lab2::AddStudent()
{
	if (_stack.size() != 0)
	{
		std::queue<std::string>* iter = _stack.top();
		std::string name = "User_" + (std::to_string(iter->size()));
		iter->push(name);
		std::cout << "Added user: " << name << "\n";
	}
	else
		std::cout << "Stack not init!\n";
}

void Lab2::PushToStack()
{
	_stack.push(new std::queue<std::string>);
	std::cout << "Push new queue to stack\n";
}

void Lab2::RemoveStudent()
{
	if (_stack.size() != 0)
	{
		std::queue<std::string>* iter = _stack.top();
		if (iter->size() != 0)
		{
			std::string name = iter->front();
			iter->pop();
			std::cout << "Remove users: " << name << "\n";
		}
		else
			std::cout << "Queue is empty!\n";
	}
	else
		std::cout << "Stack not init!\n";
}

Lab2::~Lab2()
{
	while (_stack.size() != 0)
		_stack.pop();
}

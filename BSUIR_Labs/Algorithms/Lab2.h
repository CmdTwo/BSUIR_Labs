#pragma once
#include <stack>
#include <queue>

class Lab2
{
private:

	std::stack<std::queue<std::string>*> _stack;


	void AddStudent();
	void PushToStack();
	void RemoveStudent();
	void Print();

public:
	Lab2();
	void BeginInput();
	~Lab2();
};


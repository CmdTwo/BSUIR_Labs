#include "Lab3.h"
#include <iostream>
#include "..\Generic\SaveInput.h"



Lab3::Lab3()
{
	//unsigned int inputKey;
	//unsigned int n;
	//std::cout << "Max items: ";
	//SaveInput::Input(n);

	//for (unsigned int i = 0; i != n; i++)
	//{
	//	SaveInput::Input(inputKey);
	//	Push(inputKey);
	//}	
}

void Lab3::Push(const unsigned int &item)
{
	if (_root == nullptr)
	{
		_root = new Node;
		_root->_left = nullptr;
		_root->_right = nullptr;
		_root->_key = item;
		_root->_lvl = 0;
	}
	else
	{
		Push(_root, item, 1);
	}
}

void Lab3::Push(Node* node, const unsigned int &item, const unsigned int lvl)
{
	if (item >= node->_key)
	{
		if (node->_right == nullptr)
		{
			node->_right = new Node;
			node->_right->_left = nullptr;
			node->_right->_right = nullptr;
			node->_right->_key = item;
			node->_right->_lvl = lvl;
		}
		else
		{
			Push(node->_right, item, lvl + 1);
		}
	}
	else
	{
		if (node->_left == nullptr)
		{
			node->_left = new Node;
			node->_left->_left = nullptr;
			node->_left->_right = nullptr;
			node->_left->_key = item;
			node->_left->_lvl = lvl;
		}
		else
		{
			Push(node->_left, item, lvl + 1);
		}
	}
}

void Lab3::NLR(Node* node) const
{
	std::cout << node->_key << "(" << node->_lvl << ") ";

	if (node->_left != nullptr)
	{
		NLR(node->_left);
	}
	if (node->_right != nullptr)
	{
		NLR(node->_right);
	}

}

unsigned int Lab3::GetNodeOnLvl(Node* node, const unsigned int &lvl, unsigned int currentLvl) const
{
	int count = 0;
	if (currentLvl != lvl)
	{
		if (node->_left != nullptr)
		{
			count += GetNodeOnLvl(node->_left, lvl, currentLvl + 1);
		}
		if (node->_right != nullptr)
		{
			count += GetNodeOnLvl(node->_right, lvl, currentLvl + 1);
		}
	}
	else
	{
		return 1;
	}
	return count;
}

void Lab3::NodesOnLvl(const unsigned int &lvl) const
{
	std::cout << "Nodes on " << lvl << ": " << GetNodeOnLvl(_root, lvl, 0);
}

void Lab3::Print() const
{
	NLR(_root);
}

Lab3::~Lab3()
{
}

#include "Counting.h"
#include <iostream>
#include <math.h>

std::ostream& operator<< (std::ostream &out, const Counting::Item &item)
{
	out << "Permanent index: " << item._permanentIndex << " | Name: " << item._name;
	return out;
}

std::ostream& operator<< (std::ostream &out, const Counting &counting)
{
	if (counting._count != 0)
	{
		Counting::ConstIter iter = counting._first;
		int count = 1;
		do
		{
			out << "Index: " << count++ << " | " << (*iter) << "\n";
			iter = iter->_next;
		} while (iter != counting._first);
		out << std::endl;
	}
	return out;
}

Counting::Counting()
{
	_count = 0;
}

void Counting::PushBack(Counting::Iter pushItem)
{
	if (_count == 0)
	{
		_first = pushItem;
		_last = _first;
		_first->_next = _last;
	}
	else if(_count == 1)
	{
		_last = pushItem;
		_first->_next = _last;
		_last->_next = _first;
	}
	else
	{
		_last->_next = pushItem;
		_last = _last->_next;
		_last->_next = _first;
	}
	pushItem->_permanentIndex = ++_count;
}

void Counting::PushBack(const std::string &name)
{
	Item* newItem = new Item;
	newItem->_name = name;

	PushBack(newItem);
}

void Counting::Remove(Iter prevItem, Iter removeItem)
{
	prevItem->_next = removeItem->_next;
	
	if(_first == removeItem)
		_first = prevItem->_next;
	else if(_last == removeItem)
		_last = prevItem;

	delete removeItem;
	_count--;
}

void Counting::Remove(Iter removeItem)
{
	if (_count != 0)
	{
		Iter item = _first;
		do
		{
			if (item->_next == removeItem)
			{
				Remove(item, removeItem);
				break;
			}
		}while(item != _first);
	}
}

void Counting::RemoveAll()
{
	Iter iter = _first;
	Iter deleteIter;
	for(int i = 0; i != _count; i++)
	{
		deleteIter = iter;
		iter = iter->_next;
		delete deleteIter;
	}
	_count = 0;
}

void Counting::RemoveEvery(const int &n)
{
	if (n > 1)
	{
		Iter item = _first;
		Iter prevItem = item;

		int iterations = 1;
		while (_count != 1)
		{
			if (n == iterations++)
			{
				Remove(prevItem, item);
				item = prevItem->_next;
				iterations = 1;
			}
			else
			{
				prevItem = item;
				item = item->_next;
			}
		}
	}
	else
		RemoveAll();
}

Counting::ConstIter Counting::GetFirst() const
{
	return _first;
}

Counting::~Counting()
{
	RemoveAll();
}
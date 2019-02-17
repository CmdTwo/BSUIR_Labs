#include "Polyno.h"
#include <iostream>

std::ostream& operator<< (std::ostream &out, const Polyno::Item &item)
{
	out << (item._value >= 0 ? "+" : "") << item._value << (item._powValue != 0 ? "x" : "");
	if (item._powValue >= 2)
		out << "^" << item._powValue;
	return out;
}

std::ostream& operator<< (std::ostream &out, const Polyno &polyno)
{
	Polyno::ConstIter iter = polyno._begin;
	while (iter != polyno._end)
	{
		out << (*iter) << " ";
		iter = iter->_next;
	}
	out << std::endl;
	return out;
}

Polyno::Polyno()
{
	_end = new Item;
	_begin = _end;
}

void Polyno::PushBack(const double value, const int pow)
{
	Item* newItem = new Item;
	newItem->_value = value;
	newItem->_powValue = pow;

	PushBack(newItem);
}

void Polyno::PushBack(Item* pushItem)
{
	if (_begin == _end)
	{
		_begin = pushItem;
		_begin->_next = _end;
	}
	else
	{
		*_end = *pushItem;
		_end->_next = new Item;
		_end = _end->_next;
	}
}

void Polyno::PushUnique(ConstIter pushItem)
{
	Iter findIter = Find(pushItem->_powValue);
	if (findIter == _end)
	{
		PushBack(new Item(*pushItem));
	}
	else
	{
		findIter->_value += pushItem->_value;
	}
}

double Polyno::Meaning(const double x) const
{
	Item* iter = _begin;
	double sum = 0;
	while (iter != _end)
	{
		sum += iter->_value * pow(x, iter->_powValue);
		iter = iter->_next;
	}
	return sum;
}

bool Polyno::IsEqual(const Polyno& other) const
{
	return Meaning(MEANING_VALUE) == other.Meaning(MEANING_VALUE);
}

int Polyno::Count() const
{
	Item* iter = _begin;
	int count = 0;
	while (iter != _end)
	{
		count++;
		iter = iter->_next;
	}
	return count;
}

void Polyno::Add(const Polyno& other, Polyno* out) const
{
	if (Count() != other.Count())
		throw std::exception("Obj1 elements count not equal obj2 elements count!");

	ConstIter firstIter = _begin;
	ConstIter secondIter = other.Begin();

	while (firstIter != _end && secondIter != other.End())
	{
		out->PushUnique(firstIter);
		out->PushUnique(secondIter);

		firstIter = firstIter->_next;
		secondIter = secondIter->_next;
	}
}

void Polyno::Inverse()
{
	Iter iter = _begin;
	while (iter != _end)
	{
		iter->_value = -iter->_value;
		iter = iter->_next;
	}
}

Polyno::Iter Polyno::Find(const int& pow) const
{
	Iter iter = _begin;
	while (iter != _end)
	{
		if (iter->_powValue == pow)
			return iter;
		else
			iter = iter->_next;
	}
	return _end;
}

Polyno::ConstIter Polyno::Begin() const
{
	return _begin;
}

Polyno::ConstIter Polyno::End() const
{
	return _end;
}

Polyno::~Polyno()
{
	Iter iter = _begin;
	Iter deleteIter;
	while (iter != _end)
	{
		deleteIter = iter;
		iter = iter->_next;
		delete deleteIter;
	}
}
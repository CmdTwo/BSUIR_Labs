#pragma once
#include <algorithm>

///<summary>Singly linked list</summary>
template<class T>
class SingleList
{
public:
	struct Item
	{
		T _value;
		Item* _next;
	};

	typedef Item* iterator;
	typedef const Item* const_iterator;
	typedef T value_type;

private:
	iterator _begin;
	iterator _end;
	unsigned int _count;

public:
	///<summary>Default constructor</summary>
	SingleList()
	{
		_end = new Item;
		_begin = _end;
	}

	///<summary>Pushing copy of item</summary>	
	void PushBack(const value_type &value)
	{
		Item* pushItem = new Item;
		pushItem->_value = value;
		
		if (_begin == _end)
		{
			_begin = pushItem;
			_begin->_next = _end;
		}
		else
		{
			(*_end) = (*pushItem);
			_end->_next = new Item;
			_end = _end->_next;
		}
		_count++;
	}

	///<summary>Sorting by compare </summary>
	void SortBy(bool compare(const value_type &v1, const value_type &v2))
	{
		for (iterator first = _begin; first != _end; first = first->_next)
			for (iterator second = first->_next; second != _end; second = second->_next)
				if (compare(first->_value, second->_value))
					std::swap(first->_value, second->_value);
	}

	///<summary>Taking by compare and returns list</summary>
	template<class C>
	void TakeBy(SingleList* outBegin, C takeBy, bool compare(const value_type &v, const C &c)) const
	{
		for (iterator first = _begin; first != _end; first = first->_next)
		{
			if (compare(first->_value, takeBy))
				outBegin->PushBack(first->_value);
		}
	}

	///<summary>Removing item</summary>
	void Remove(iterator removeIter)
	{
		if (removeIter == _begin)
		{
			_begin = _begin->_next;
			_count--;
			delete removeIter;
		}
		else
		{
			iterator iter = _begin;
			iterator prev = iter;
			while (iter != _end)
			{
				if (iter == removeIter)
				{
					prev->_next = iter->_next;
					delete iter;
					_count--;
					break;
				}
				else
				{
					prev = iter;
					iter = iter->_next;
				}
			}
		}
	}

	///<summary>Returns first equal item</summary>
	template<class C>
	iterator Find(C checkBy, bool compare(const value_type &v, const C &c)) const
	{
		for (iterator first = _begin; first != _end; first = first->_next)
		{
			if (compare(first->_value, checkBy))
				return first;
		}
		return _end;
	}

	///<summary>Returns begin iterator</summary>
	iterator Begin()
	{
		return _begin;
	}

	///<summary>Returns const begin iterator</summary>
	const_iterator Begin() const
	{
		return _begin;
	}

	///<summary>Returns end iterator</summary>
	iterator End()
	{
		return _end;
	}

	///<summary>Returns const end iterator</summary>
	const_iterator End() const
	{
		return _end;
	}

	///<summary>Returns count of items</summary>
	int Count() const
	{
		return _count;
	}

	///<summary>Default destructor</summary>
	~SingleList()
	{
		iterator iter = _begin;
		iterator deleteIter;
		while (iter != _end)
		{
			deleteIter = iter;
			iter = iter->_next;
			delete deleteIter;
		}
	}
};


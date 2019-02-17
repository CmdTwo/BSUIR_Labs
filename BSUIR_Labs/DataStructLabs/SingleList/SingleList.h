#pragma once
#include <algorithm>

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

public:
	SingleList()
	{
		_end = new Item;
		_begin = _end;
	}

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
	}

	void SortBy(bool compare(const value_type &v1, const value_type &v2))
	{
		for (iterator first = _begin; first != _end; first = first->_next)
			for (iterator second = first->_next; second != _end; second = second->_next)
				if (compare(first->_value, second->_value))
					std::swap(first->_value, second->_value);
	}

	template<class C>
	void TakeBy(SingleList* outBegin, C takeBy, bool compare(const value_type &v, const C &c))
	{
		for (iterator first = _begin; first != _end; first = first->_next)
		{
			if (compare(first->_value, takeBy))
				outBegin->PushBack(first->_value);
		}
	}

	iterator Begin()
	{
		return _begin;
	}

	const_iterator Begin() const
	{
		return _begin;
	}

	iterator End()
	{
		return _end;
	}

	const_iterator End() const
	{
		return _end;
	}

	~SingleList()
	{
	}
};


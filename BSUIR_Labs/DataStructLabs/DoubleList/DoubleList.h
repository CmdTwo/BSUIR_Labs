#pragma once
#include "..\SingleList\SingleList.h"

///<summary>Double linked list</summary>
template<class T>
class DoubleList
{
public:
	struct Item
	{
		T _value;
		Item* _next;
		Item* _prev;
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
	DoubleList()
	{
		_count = 0;
		_end = new Item;
		_begin = _end;
		_begin->_prev = _end;
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
			_end->_prev = _begin;
		}
		else
		{
			_end->_prev->_next = pushItem;
			pushItem->_prev = _end->_prev;
			pushItem->_next = _end;
			_end->_prev = pushItem;
			//(*_end) = (*pushItem);
			//_end->_next = new Item;
			//_end->_prev = _end;
			//_end = _end->_next;
		}
		_count++;
	}

	///<summary>Selection by predicate and push in Out single list</summary>
	template<class C>
	void SelectTo(SingleList<value_type>& out, C arg, bool predicate(const value_type &v, const C &c))
	{
		for (const_iterator iter = _begin; iter != _end; iter = iter->_next)
			if (predicate(iter->_value, arg))
				out.PushBack(iter->_value);
	}

	///<summary>Reverse selection by predicate and push in Out single list</summary>
	template<class C>
	void rSelectTo(SingleList<value_type>& out, C arg, bool predicate(const value_type &v, const C &c))
	{
		for (const_iterator iter = rBegin(); iter != rEnd(); iter = iter->_prev)
			if (predicate(iter->_value, arg))
				out.PushBack(iter->_value);
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

	///<summary>Returns reverse begin iterator</summary>
	iterator rBegin()
	{
		return _end->_prev;
	}

	///<summary>Returns reverse const begin iterator</summary>
	const_iterator rBegin() const
	{
		return _end->_prev;
	}

	///<summary>Returns reverse  end iterator</summary>
	iterator rEnd()
	{
		return _begin->_prev;
	}

	///<summary>Returns reverse  const end iterator</summary>
	const_iterator rEnd() const
	{
		return _begin->_prev;
	}

	~DoubleList()
	{

	}
};


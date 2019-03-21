#pragma once
#include <string>

///<summary>Simple queue with priority</summary>
template<class T>
class PriorityQueue
{
public:
	struct Item
	{
		float _priority;
		T _value;
		Item* _next;
	};

	typedef Item* iterator;
	typedef const Item* const_iterator;
	typedef T value_type;

private:
	iterator _begin;
	iterator _end;
	int _count;

	///<summary>Inserting new item by priority</summary>
	void Insert(Item* newItem)
	{
		iterator iter = _begin;
		iterator prev = iter;
		do
		{
			if (iter == _end)
			{
				prev->_next = newItem;
				newItem->_next = _end;
				return;
			}

			if (newItem->_priority > iter->_priority)
			{
				if (iter == _begin)
				{
					_begin = newItem;
					_begin->_next = prev;
				}
				else
				{
					prev->_next = newItem;
					newItem->_next = iter;
				}
				return;
			}
			prev = iter;
			iter = iter->_next;
		} while (iter != _end);

		prev->_next = newItem;
		newItem->_next = iter;
	}
	
public:

	///<summary>Default constructor</summary>
	PriorityQueue()
	{
		_count = 0;
		_end = new Item;
		_begin = _end;
	}

	///<summary>TEMP: Debug print</summary>
	void DebugPrint() const
	{
		const_iterator iter = _begin;
		while (iter != _end)
		{
			std::cout << iter->_value << "(" << iter->_priority << "%) ";
			iter = iter->_next;
		}
	}

	///<summary>Pushing copy of item</summary>	
	void PushBack(const value_type &value, const float &priority)
	{
		Item* pushItem = new Item;
		pushItem->_value = value;
		pushItem->_priority = priority;

		if (_begin == _end)
		{
			_begin = pushItem;
			_begin->_next = _end;
		}
		else
		{
			Insert(pushItem);
		}
		_count++;
	}

	///<summary>Removing item by value</summary>
	void Remove(const value_type &value)
	{
		iterator iter = _begin;
		iterator prev = iter;
		do
		{
			if (iter->_value == value)
			{
				if (iter == _begin)
				{
					_begin = _begin->_next;
				}
				else
				{
					prev->_next = iter->_next;
				}
				delete iter;
				_count--;
				return;
			}
			prev = iter;
			iter = iter->_next;
		} while (iter != _end);
		throw std::exception("Cannot find and remove item by value");
	}

	///<summary>Removing item by priority</summary>
	void Remove(const float &priority)
	{
		iterator iter = _begin;
		iterator prev = iter;
		do
		{
			if (iter->_priority == priority)
			{
				if (iter == _begin)
				{
					_begin = _begin->_next;
				}
				else
				{
					prev->_next = iter->_next;
				}
				delete iter;
				_count--;
				return;
			}
			prev = iter;
			iter = iter->_next;
		} while (iter != _end);
		throw std::exception("Cannot find and remove item by priority");
	}

	///<summary>Returns first equal item by value</summary>
	const_iterator Find(const value_type &value) const
	{
		const_iterator iter = _begin;
		do
		{
			if (iter->_value == value)
				return iter;

			iter = iter->_next;
		} while (iter != _end);
		throw std::exception("Cannot find item by value");
	}

	///<summary>Returns first equal item by priority</summary>
	const_iterator Find(const float &priority) const
	{
		const_iterator iter = _begin;
		do
		{
			if (iter->_priority == priority)
				return iter;

			iter = iter->_next;
		} while (iter != _end);
		throw std::exception("Cannot find item by priority");
	}

	///<summary>Returns first item</summary>
	const_iterator Top() const
	{
		return _begin;
	}

	///<summary>Removing all items in queue</summary>
	void Clear()
	{
		iterator iter = _begin;
		iterator deleteIter;
		while (iter != _end)
		{
			deleteIter = iter;
			iter = iter->_next;
			delete deleteIter;
		}
		_count = 0;
	}

	///<summary>Default destructor</summary>
	~PriorityQueue()
	{
		Clear();
	}
};
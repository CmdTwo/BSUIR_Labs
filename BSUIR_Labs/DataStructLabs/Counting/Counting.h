#pragma once
#include <string>

///<summary>Singly linked ring for counting</summary>
class Counting
{
public:

	struct Item
	{
		Item* _next;
		int _permanentIndex;
		std::string _name;

		Item()
		{
			_permanentIndex = 0;
			_name = "NaN";
		}

		friend std::ostream& operator<< (std::ostream &out, const Counting::Item &item);
	};


private:

	using Iter = Item* ;
	using ConstIter = const Item*;

	Iter _first;
	Iter _last;

	int _count;

	///<summary>Pushing new item</summary>
	void PushBack(Iter pushItem);

	///<summary>Removing and updating ring</summary>
	void Remove(Iter prevItem, Iter removeItem);

public:

	///<summary>Default constructor</summary>
	Counting();

	///<summary>Creating and pushing new item</summary>
	void PushBack(const std::string &name);

	///<summary>Removing every N argument item</summary>
	void RemoveEvery(const int &n);

	///<summary>Removing item</summary>
	void Remove(Iter removeItem);

	///<summary>Removing all items</summary>
	void RemoveAll();

	///<summary>Returns first item</summary>
	ConstIter GetFirst() const;

	friend std::ostream& operator<< (std::ostream &out, const Counting &counting);

	///<summary>Default destructor</summary>
	~Counting();
};
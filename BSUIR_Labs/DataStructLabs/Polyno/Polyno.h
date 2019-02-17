#pragma once
#include <iostream>

///<summary>Singly linked list for polynomials</summary>
class Polyno
{
public:
	struct Item
	{
		Item* _next;
		double _value;
		int _powValue;

		Item()
		{
			_value = 0;
			_powValue = 0;
		}

		Item(const Item &obj)
		{
			_value = obj._value;
			_powValue = obj._powValue;
		}

		friend std::ostream& operator<< (std::ostream &out, const Polyno::Item &item);
	};

	using Iter = Item * ;
	using ConstIter = const Item*;

private:
	Iter _begin;
	Iter _end;

	///<summary>Const value for Meaning method</summary>
	const double MEANING_VALUE = 2;

	///<summary>Pushing unique copy of item</summary>
	void PushUnique(ConstIter item);

public:
	///<summary>Default constructor</summary>
	Polyno();

	///<summary>Pushing new item</summary>	
	void PushBack(Item* pushItem);

	///<summary>Creating and pushing new item</summary>
	void PushBack(const double value, const int pow);

	///<summary>Returns meaning value by X argument</summary>
	double Meaning(const double x) const;

	///<summary>Checking equality with Other argument</summary>
	bool IsEqual(const Polyno &other) const;

	///<summary>Addind this Polyno with Other argument and pushing result in Out argument</summary>
	void Add(const Polyno& other, Polyno* out) const;

	///<summary>Returns elements count</summary>
	int Count() const;

	///<summary>Inversing this Polyno</summary>
	void Inverse();

	///<summary>Finding by power and returns iterator</summary>
	Iter Find(const int &pow) const;

	///<summary>Const begin</summary>
	ConstIter Begin() const;

	///<summary>Const end</summary>
	ConstIter End() const;

	friend std::ostream& operator<< (std::ostream &out, const Polyno &polyno);

	///<summary>Default destructor</summary>
	~Polyno();
};
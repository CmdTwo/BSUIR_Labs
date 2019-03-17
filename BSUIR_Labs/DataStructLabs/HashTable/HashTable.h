#pragma once
#include <string>
#include <vector>
#include <algorithm>

///<summary>Simple Hash Table</summary>
template<class T>
class HashTable
{
private:

	struct HashItem
	{
		T _value;
		std::string _key;
	};

	const unsigned int HASH_PRIME_NUMBER = 2069;
	const size_t MAX_VALUES = 100;

	std::vector<HashItem>* _values;

	///<summary>Generate hash code from key</summary>
	size_t GetHash(const std::string &key)
	{
		size_t sum = 0;
		for (size_t i = 0; i != key.size(); i++)
			sum += (int)key[i] * (i + 1);
		return sum % HASH_PRIME_NUMBER;
	}
	///<summary>Returns index from hash</summary>
	size_t GetIndex(size_t hashCode)
	{
		return hashCode % MAX_VALUES;
	}

public:
	///<summary>Default constructor</summary>
	HashTable()
	{
		_values = new std::vector<HashItem>[MAX_VALUES];
	}

	///<summary>Inserting new value by key</summary>
	void Insert(const std::string &key, const T &value)
	{
		if (!Contains(key, value))
		{
			size_t hashIndex = GetIndex(GetHash(key));

			HashItem item;
			item._value = value;
			item._key = key;

			_values[hashIndex].push_back(item);
		}
		else
			throw std::exception(("That key (" + key + ") already used!").c_str());
	}

	///<summary>Removing value by key</summary>
	void Remove(const std::string &key)
	{
		size_t hashIndex = GetIndex(GetHash(key));
		if (_values[hashIndex].size() == 0)
		{
			throw std::exception(("No any key like: " + key).c_str());
		}
		else
		{
			auto value = std::find_if(_values[hashIndex].begin(), _values[hashIndex].end(),
				[&](const HashItem &v) { return v._key == key; });
			if (value != _values[hashIndex].end())
			{
				_values[hashIndex].erase(value);
			}
			else
			{
				throw std::exception(("No any value by key: " + key).c_str());
			}
		}
	}

	///<summary>Returns copy of value by key</summary>
	T Get(const std::string &key)
	{
		size_t hashIndex = GetIndex(GetHash(key));
		if (_values[hashIndex].size() == 0)
		{
			throw std::exception(("No any key like: " + key).c_str());
		}
		else
		{
			auto value = std::find_if(_values[hashIndex].begin(), _values[hashIndex].end(),
				[&](const HashItem &v) { return v._key == key; });
			if (value != _values[hashIndex].end())
				return value->_value;
			else
				throw std::exception(("No any value by key: " + key).c_str());
		}
	}

	///<summary>Checking contains any value by key</summary>
	bool Contains(const std::string &key, const T &value)
	{
		size_t hashIndex = GetIndex(GetHash(key));
		if (_values[hashIndex].size() == 0)
			return false;
		else
		{
			return std::find_if(_values[hashIndex].begin(), _values[hashIndex].end(), 
				[&](const HashItem &v) { return v._key == key; }) != _values[hashIndex].end();
		}
	}

	///<summary>Removing all values and keys</summary>
	void Clear()
	{
		for (size_t i = 0; i != MAX_VALUES; i++)
			_values[i].clear();
	}

	///<summary>Default destructor</summary>
	~HashTable()
	{
		Clear();
	}
};


#pragma once

template <typename TKey, typename TValue>
class Dictionary
{
private:
	KeyValuePair<TKey, TValue>* _pairs = nullptr;
	size_t _count = 0;
	size_t _capacity = 5;

public:
	Dictionary()
	{
		_pairs = new KeyValuePair<TKey, TValue>[_capacity];
	}
	
	Dictionary(const Dictionary& other)
	{
		_count = other._count;
		_capacity = other._capacity;

		_pairs = new KeyValuePair<TKey, TValue>[_capacity];

		for (size_t i = 0; i < _count; i++)
		{
			_pairs[i] = other._pairs[i];
		}
	}
	Dictionary& operator=(const Dictionary& other)
	{
		if (this != &other)
		{
			delete[] _pairs;

			_count = other._count;
			_capacity = other._capacity;

			_pairs = new KeyValuePair<TKey, TValue>[_capacity];

			for (size_t i = 0; i < _count; i++)
			{
				_pairs[i] = other._pairs[i];
			}
		}
		return *this;
	}

	TValue& item(const TKey key)
	{
		for (size_t i = 0; i < _count; i++)
			if (_pairs[i].key == key)
				return _pairs[i].value;
		assert(!"Not founded!");
	}
	TValue& operator[](const TKey key)
	{
		for (size_t i = 0; i < _count; i++)
		{
			if (_pairs[i].key == key)
				return _pairs[i].value;
		}

		this->add(key, TValue());
		return _pairs[_count - 1][key];
	}
	
	void add(const KeyValuePair<TKey, TValue> pair)
	{
		if (containsKey(pair.key))
			assert(!"This key is full!");

		if (_count < _capacity)
		{
			_pairs[_count++] = pair;
			return;
		}

		_capacity *= 2;
		KeyValuePair<TKey, TValue>* newArray = new KeyValuePair<TKey, TValue>[_capacity];

		for (size_t i = 0; i < _count; i++)
		{
			newArray[i] = _pairs[i];
		}

		newArray[_count++] = pair;
		delete[] _pairs; _pairs = nullptr;
		_pairs = newArray;
	}
	void add(const TKey key, const TValue value)
	{
		this->add(KeyValuePair<TKey, TValue> {key, value});
	}
	
	size_t count() const { return _count; }
	size_t capacity() const { return _capacity; }
	const TKey* keys()
	{
		TKey* newArray = new TKey[_count];

		for (size_t i = 0; i < _count; i++)
		{
			newArray[i] = _pairs[i].key;
		}

		return newArray;
	}
	const TValue* values()
	{
		TValue* newArray = new TValue[_count];

		for (size_t i = 0; i < _count; i++)
			newArray[i] = _pairs[i].value;

		return newArray;
	}
	KeyValuePair<TKey, TValue>* items() { return _pairs; }
	
	void clear(){ _count = 0; }
	bool containsKey(const TKey key) const
	{
		for (size_t i = 0; i < _count; i++)
			if (_pairs[i].key == key)
				return true;
		
		return false;
	}
	bool containsValue(const TValue value) const
	{
		for (size_t i = 0; i < _count; i++)
			if (_pairs[i].value == value)
				return true;

		return false;
	}
	bool remove(const TKey key)
	{
		for (size_t i = 0; i < _count; i++)
		{
			if (_pairs[i].key == key)
			{
				for (size_t j = i; j < _count - 1; j++)
					_pairs[j] = _pairs[j + 1];

				_count--;
				return true;
			}
		}
		return false;
	}

	~Dictionary()
	{
		delete[] _pairs;
		_pairs = nullptr;
	}
};
#pragma once

class myString {
private:
	size_t _length = 0;
	size_t _capacity = 16;
	char* _text = nullptr;
	void setText(const char* text)
	{
		delete[] _text;
		_text = nullptr;

		if (text == nullptr)
		{
			_length = 0;
			_capacity = 16;
			_text = new char[_capacity];
			_text[0] = '\0';
			return;
		}

		_length = 0;
		while (text[_length] != '\0')
			_length++;

		_capacity = _length + 1;

		_text = new char[_capacity];

		for (size_t i = 0; i < _length; i++)
			_text[i] = text[i];

		_text[_length] = '\0';
	}
public:
	myString()
	{
		_capacity = 16;
		_length = 0;
		_text = new char[_capacity];
		_text[0] = '\0';
	}
	myString(const char* text)
	{
		_text = nullptr;
		setText(text);
	}
	myString(const myString& other)
	{
		setText(other._text);
	}

	myString(const size_t count, const char text)
	{
		_length = count;
		_capacity = count + 1;

		_text = new char[_capacity];

		for (size_t i = 0; i < count; i++)
		{
			_text[i] = text;
		}

		_text[_capacity] = '\0';
	}

	myString& operator=(const myString& other)
	{
		if (this != &other)
			setText(other._text);
		return *this;
	}
	myString(myString&& other) noexcept
	{
		_text = other._text;
		_length = other._length;
		_capacity = other._capacity;

		other._text = nullptr;
		other._length = 0;
		other._capacity = 0;
	}
	myString& operator=(myString&& other) noexcept
	{
		if (this != &other)
		{
			delete[] _text;

			_text = other._text;
			_length = other._length;
			_capacity = other._capacity;

			other._text = nullptr;
			other._length = 0;
			other._capacity = 0;
		}
		return *this;
	}
	char& front()
	{
		if (_length == 0)
			assert(!"length == 0");

		return _text[0];
	}
	char& back()
	{
		if (_length == 0)
			assert(!"length == 0");

		return _text[_length - 1];
	}
	char& at(size_t index)
	{
		if (index >= _length)
			assert(!"index >= length");

		return _text[index];
	}
	size_t capacity() const { return _capacity; }
	size_t size() const { return _length; }
	size_t length() const { return _length; }
	size_t find(char chr) const
	{
		for (size_t i = 0; i < _length; i++)
		{
			if (_text[i] == chr)
				return i;
		}

		return (size_t) - 1;
	}
	size_t rfind(char chr) const
	{
		for (size_t i = _length; i > 0; i--)
		{
			if (_text[i - 1] == chr)
				return i - 1;
		}

		return (size_t)-1;
	}
	void clear()
	{
		_length = 0;
		_text[0] = '\0';
	}
	void resize(size_t newSize)
	{
		if (newSize < _length)
		{
			_length = newSize;
			_text[_length] = '\0';
			return;
		}

		if (newSize > _capacity)
			reserve(newSize + 1);

		for (size_t i = _length; i < newSize; i++)
			_text[i] = '\0';

		_length = newSize;
		_text[_length] = '\0';
	}
	void reserve(size_t newCapacity)
	{
		if (newCapacity <= _capacity)
			return;

		char* newText = new char[newCapacity];

		for (size_t i = 0; i < _length; i++)
			newText[i] = _text[i];

		newText[_length] = '\0';

		delete[] _text;
		_text = newText;

		_capacity = newCapacity;
	}
	void shrink_to_fit()
	{
		if (_capacity == _length + 1)
			return;

		char* newText = new char[_length + 1];

		for (size_t i = 0; i < _length; i++)
			newText[i] = _text[i];

		newText[_length] = '\0';

		delete[] _text;
		_text = newText;

		_capacity = _length + 1;
	}
	bool empty() const { return _length == 0; }
	myString& append(const char* text)
	{
		if (text == nullptr)
			return *this;

		size_t addLen = 0;
		while (text[addLen] != '\0')
			addLen++;

		size_t newLength = _length + addLen;

		if (newLength + 1 > _capacity)
			reserve(newLength + 1);
		for (size_t i = 0; i < addLen; i++)
			_text[_length + i] = text[i];

		_length = newLength;
		_text[_length] = '\0';

		return *this;
	}
	int compare(const myString& right) const
	{
		size_t i = 0;

		while (i < _length && i < right._length)
		{
			if (_text[i] < right._text[i])
				return -1;
			if (_text[i] > right._text[i])
				return 1;
			i++;
		}

		if (_length == right._length)
			return 0;
		if (_length < right._length)
			return -1;
		return 1;
	}
	void push_back(char c)
	{
		if (_length + 1 >= _capacity)
			reserve(_capacity * 2);

		_text[_length] = c;
		_length++;
		_text[_length] = '\0';
	}
	void pop_back()
	{
		if (_length == 0)
			assert(!"length == 0");

		_length--;
		_text[_length] = '\0';
	}

	const char* print() const { return _text; }

	~myString()
	{
		delete[] _text;
	}
};

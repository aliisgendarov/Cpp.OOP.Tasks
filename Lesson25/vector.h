#pragma once
class Vector {
private:
	int* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = 15;
public:
	Vector() = default;
	Vector(size_t capacity)
	{
		this->_capacity = capacity;
		_array = new int[_capacity];
	}
	const int* getData() const { return _array; }
	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }
	void print() const
	{
		cout << "Size: " << _size << endl;
		cout << "Capacity: " << _capacity << endl;
		cout << "Array: ";
		for (size_t i = 0; i < _size; i++)
			cout << _array[i] << " ";
		cout << endl;
	}

	Vector(const Vector& other)
	{
		_size = other._size;
		_capacity = other._capacity;
		_array = new int[_capacity];

		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	Vector& operator=(const Vector& other)
	{
		if (this == &other)
			return *this;

		delete[] _array;

		_size = other._size;
		_capacity = other._capacity;
		_array = new int[_capacity];

		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];

		return *this;
	}

	Vector operator+(const Vector& other)
	{
		Vector result(_size + other._size);

		for (size_t i = 0; i < _size; i++)
			result._array[i] = _array[i];

		for (size_t i = 0; i < other._size; i++)
			result._array[_size + i] = other._array[i];

		result._size = _size + other._size;

		return result;
	}

	bool operator==(const Vector& other) const
	{
		if (_size != other._size)
			return false;

		for (size_t i = 0; i < _size; i++)
			if (_array[i] != other._array[i])
				return false;

		return true;
	}


	bool operator!=(const Vector& other) const
	{
		return !(*this == other);
	}

	int& operator[](size_t index)
	{
		if (index >= _size)
			assert(!"index >= size");

		return _array[index];
	}

	Vector& operator++()
	{
		for (size_t i = 0; i < _size; i++)
			_array[i]++;

		return *this;
	}
	Vector& operator--()
	{
		for (size_t i = 0; i < _size; i++)
			_array[i]--;

		return *this;
	}
	Vector operator++(int)
	{
		Vector temp = *this;

		for (size_t i = 0; i < _size; i++)
			_array[i]++;

		return temp;
	}
	Vector operator--(int)
	{
		Vector temp = *this;

		for (size_t i = 0; i < _size; i++)
			_array[i]--;

		return temp;
	}

	void operator()() const { this->print(); }
	Vector& push_back(const int value)
	{
		if (_size < _capacity)
		{
			_array[_size++] = value;
			return *this;
		}

		_capacity *= 2;
		int* newArray = new int[_capacity];
		
		for (size_t i = 0; i < _size; i++)
			newArray[i] = _array[i];

		newArray[_size++] = value;

		delete[] _array; _array = nullptr;
		_array = newArray;

		return *this;
	}
	Vector& push_front(const int value)
	{
		if (_size + 1 > _capacity)
			_capacity *= 2;

		int* newArray = new int[_capacity];

		newArray[0] = value;

		for (size_t i = 0; i < _size; i++)
			newArray[i + 1] = _array[i];

		delete[] _array; _array = nullptr;
		_array = newArray; _size++;

		return *this;
	}
	Vector& pop_back()
	{
		if (_size == 0)
			assert(!"size == 0");

		_size--;

		return *this;
	}
	Vector& pop_front()
	{
		if (_size == 0)
			assert(!"size == 0");

		int* newArray = new int[_capacity];

		for (size_t i = 1; i < _size; i++)
			newArray[i - 1] = _array[i];

		delete[] _array; _array = nullptr;
		_array = newArray;
		_size--;

		return *this;
	}
	void deleteByIndex(size_t index)
	{
		if (index >= _size)
			assert(!"index >= size");

		for (size_t i = index; i < _size - 1; i++)
			_array[i] = _array[i + 1];

		_size--;
	}
	void insertByIndex(const size_t index, const int element)
	{
		if (index > _size)
			assert(!"index > _size");

		if (_size + 1 > _capacity)
			_capacity *= 2;

		int* newArray = new int[_capacity];

		for (size_t i = 0; i < index; i++)
			newArray[i] = _array[i];

		newArray[index] = element;

		for (size_t i = index; i < _size; i++)
			newArray[i + 1] = _array[i];

		delete[] _array; _array = nullptr;
		_array = newArray;
		_size++;
	}
	// tapsa index-ni qaytarsin,
	// tapmasa -1 (unsigned int-in max qiymeti qayidacaq)
	size_t find(const int element)
	{
		for (size_t i = 0; i < _size; i++)
			if (element == _array[i])
				return i;
		
		return (size_t)-1;
	}
	size_t rfind(const int element)
	{
		if (_size == 0)
			return (size_t)-1;

		for (int i = _size - 1; i >= 0; i--)
			if (element == _array[i])
				return i;
		
		return (size_t)-1;
	}
	// reverse true gonderilse, tersine sort olunsun.
	void sort(bool reverse = false)
	{
		if (!reverse)
		{
			for (size_t i = 0; i < _size; i++)
			{
				for (size_t j = 0; j < _size - 1; j++)
				{
					if (_array[j] > _array[j + 1])
					{
						int temp = _array[j];
						_array[j] = _array[j + 1];
						_array[j + 1] = temp;
					}
				}
			}
		}
		else
		{
			for (size_t i = 0; i < _size; i++)
			{
				for (size_t j = 0; j < _size - 1; j++)
				{
					if (_array[j] < _array[j + 1])
					{
						int temp = _array[j];
						_array[j] = _array[j + 1];
						_array[j + 1] = temp;
					}
				}
			}
		}
	}

	~Vector()
	{
		delete[] _array;
		_array = nullptr;
	}
};
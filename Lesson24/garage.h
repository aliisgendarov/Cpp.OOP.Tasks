#pragma once

class Garage {
private:
	Airplane** airplanes = nullptr;
	size_t _count = 0;
	char* _name;
	char* _address;

public:
	explicit Garage()
	{
		_name = _address = nullptr;
	}
	explicit Garage(const char* name, const char* address, size_t count) : Garage()
	{
		setName(name);
		setAddress(address);
		setCount(count);
	
		airplanes = new Airplane *[_count];
		for (size_t i = 0; i < _count; i++)
		{
			airplanes[i] = nullptr;
		}
	}
	Garage(const Garage& other)
	{
		setName(other._name);
		setAddress(other._address);
		setCount(other._count);

		airplanes = new Airplane * [_count];

		for (size_t i = 0; i < _count; i++)
		{
			if (other.airplanes[i] != nullptr)
				airplanes[i] = new Airplane(*other.airplanes[i]);
			else
				airplanes[i] = nullptr;
		}
	}
	Garage& operator=(const Garage& other)
	{
		if (this != &other)
		{
			for (size_t i = 0; i < _count; i++)
				delete airplanes[i];
			delete[] airplanes;

			setName(other._name);
			setAddress(other._address);
			setCount(other._count);

			airplanes = new Airplane * [_count];

			for (size_t i = 0; i < _count; i++)
			{
				if (other.airplanes[i] != nullptr)
					airplanes[i] = new Airplane(*other.airplanes[i]);
				else
					airplanes[i] = nullptr;
			}
		}
		return *this;
	}
	Garage(Garage&& other)
	{
		_name = other._name;
		_address = other._address;
		_count = other._count;
		airplanes = other.airplanes;

		other._name = nullptr;
		other._address = nullptr;
		other.airplanes = nullptr;
		other._count = 0;
	}
	Garage& operator=(Garage&& other)
	{
		if (this != &other)
		{
			for (size_t i = 0; i < _count; i++)
				delete airplanes[i];
			delete[] airplanes;

			delete[] _name;
			delete[] _address;

			_name = other._name;
			_address = other._address;
			_count = other._count;
			airplanes = other.airplanes;

			other._name = nullptr;
			other._address = nullptr;
			other.airplanes = nullptr;
			other._count = 0;
		}
		return *this;
	}

	Airplane* getAirplaneById(int id)
	{
		for (size_t i = 0; i < _count; i++)
		{
			if (airplanes[i] != nullptr && airplanes[i]->getId() == id)
				return airplanes[i];
		}

		return nullptr;
	}
	Airplane** getAirplanesCapacityGreaterThan(int capacity)
	{
		size_t count = 0;
		for (size_t i = 0; i < _count; i++)
		{
			if (airplanes[i] != nullptr && airplanes[i]->getCapacity() > capacity)
			{
				count++;
			}
		}

		Airplane** result = new Airplane * [count + 1];

		size_t index = 0;
		for (size_t i = 0; i < _count; i++)
		{
			if (airplanes[i] != nullptr && airplanes[i]->getCapacity() > capacity)
			{
				result[index++] = airplanes[i];
			}
		}
		result[index] = nullptr;

		return result;
	}
	Airplane** getAirplanesByColor(const char* color)
	{
		if (color == nullptr)
			assert(!"color == nullptr");

		size_t count = 0;
		for (size_t i = 0; i < _count; i++)
		{
			if (airplanes[i] != nullptr && airplanes[i]->getColor() != nullptr && strcmp(color, airplanes[i]->getColor()) == 0)
			{
				count++;
			}
		}

		Airplane** result = new Airplane * [count + 1];

		size_t index = 0;
		for (size_t i = 0; i < _count; i++)
		{
			if (airplanes[i] != nullptr && airplanes[i]->getColor() != nullptr && strcmp(color, airplanes[i]->getColor()) == 0)
			{
				result[index++] = airplanes[i];
			}
		}
		result[index] = nullptr;

		return result;
	}

	const char* getName() const { return _name; }
	const char* getAddress() const { return _address; }
	size_t getCount() const { return _count; }

	void setName(const char* name)
	{
		if (name == nullptr)
			assert(!"name == nullptr");

		if (_name != nullptr)
		{
			delete[] _name;
			_name = nullptr;
		}

		size_t len = strlen(name) + 1;
		_name = new char [len];
		strcpy_s(_name, len, name);
	}
	void setAddress(const char* address)
	{
		if (address == nullptr)
			assert(!"address == nullptr");

		if (_address != nullptr)
		{
			delete[] _address;
			_address = nullptr;
		}

		size_t len = strlen(address) + 1;
		_address = new char [len];
		strcpy_s(_address, len, address);
	}
	void setCount(size_t count)
	{
		if (count <= 0)
			assert(!"count <= 0");
		this->_count = count;
	}

	void addAirplane(Airplane* plane, size_t index)
	{
		if (plane == nullptr)
			assert(!"plane == nullptr");

		if (index >= _count)
			assert(!"index out of range");

		if (airplanes[index] != nullptr)
		{
			delete airplanes[index];
			airplanes[index] = nullptr;
		}

		airplanes[index] = plane;
	}

	void print()
	{
		cout << "Name: " << _name << endl;
		cout << "Airplanes: " << endl;
		for (size_t i = 0; i < _count; i++)
		{
			if (airplanes[i] != nullptr)
				airplanes[i]->print();
			cout << endl;
		}
		cout << "Address: " << _address << endl;
		cout << "Count: " << _count;

	}
	~Garage()
	{
		delete[] _name;
		delete[] _address;
		for (size_t i = 0; i < _count; i++)
		{
			delete airplanes[i];
		}
		delete[] airplanes;

		_name = _address = nullptr;
		airplanes = nullptr;
	}
};
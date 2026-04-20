#pragma once

class Airplane {
	int _id;
	char* _model;
	char* _color;
	double _engine;
	int _capacity;
	static int staticId;

	void setId(int id)
	{
		this->_id = id;
	}

public:
	static int MAXCOUNT;

	explicit Airplane()
	{
		if (staticId >= MAXCOUNT)
			assert(!"staticId >= MAXCOUNT");
		_id = ++staticId;
		_model = _color = nullptr;
		_engine = 0;
		_capacity = 0;
	}
	explicit Airplane(const char* model, const char* color, double engine, int capacity) : Airplane()
	{
		setModel(model);
		setColor(color);
		setEngine(engine);
		setCapacity(capacity);
	}

	Airplane(const Airplane& other)
	{
		if (staticId >= MAXCOUNT)
			assert(!"staticId >= MAXCOUNT");
		_id = ++staticId;
		setModel(other._model);
		setColor(other._color);
		setEngine(other._engine);
		setCapacity(other._capacity);
	}
	Airplane& operator=(const Airplane& other)
	{
		if (this != &other)
		{
			setModel(other._model);
			setColor(other._color);
			setEngine(other._engine);
			setCapacity(other._capacity);
		}
		return *this;
	}

	Airplane(Airplane&& other)
	{
		if (staticId >= MAXCOUNT)
			assert(!"staticId >= MAXCOUNT");
		_id = ++staticId;
		_model = other._model;
		_color = other._color;
		_engine = other._engine;
		_capacity = other._capacity;

		other._model = nullptr;
		other._color = nullptr;
		other._engine = 0;
		other._capacity = 0;
	}

	Airplane& operator=(Airplane&& other)
	{
		if (this != &other)
		{
			if (_model != nullptr)
			{
				delete[] _model;
				_model = nullptr;
			}
			if (_color != nullptr)
			{
				delete[] _color;
				_color = nullptr;
			}

			_model = other._model;
			_color = other._color;
			_engine = other._engine;
			_capacity = other._capacity;

			other._model = nullptr;
			other._color = nullptr;
			other._engine = 0;
			other._capacity = 0;
		}
		return *this;
	}

	int getId() const noexcept { return _id; }
	const char* getModel() const noexcept { return _model; }
	const char* getColor() const noexcept { return _color; }
	double getEngine() const noexcept { return _engine; }
	int getCapacity() const noexcept { return _capacity; }
	static int getStaticId() noexcept { return staticId; }
	static int getMaxCount() noexcept { return MAXCOUNT; }


	void setModel(const char* model)
	{
		if (model == nullptr)
			assert(!"model == nullptr");
		if (_model != nullptr)
		{
			delete[] _model;
			_model = nullptr;
		}

		size_t len = strlen(model) + 1;
		_model = new char[len];
		strcpy_s(_model, len, model);
	}
	void setColor(const char* color)
	{
		if (color == nullptr)
			assert(!"color == nullptr");
		if (_color != nullptr)
		{
			delete[] _color;
			_color = nullptr;
		}

		size_t len = strlen(color) + 1;
		_color = new char[len];
		strcpy_s(_color, len, color);
	}
	void setEngine(double engine)
	{
		if (engine < 0)
			assert(!"engine < 0");
		this->_engine = engine;
	}
	void setCapacity(int capacity)
	{
		if (capacity < 0)
			assert(!"capacity < 0");
		this->_capacity = capacity;
	}

	void print() const
	{
		cout << "ID: " << _id << endl;
		cout << "Model: " << _model << endl;
		cout << "Color: " << _color << endl;
		cout << "Engine: " << _engine << endl;
		cout << "Capacity: " << _capacity << endl;
	}
	~Airplane()
	{
		delete[] _model;
		delete[] _color;

		_model = _color = nullptr;
	}
};

int Airplane::staticId = 0;
int Airplane::MAXCOUNT = 100;
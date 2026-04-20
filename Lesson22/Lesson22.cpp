#include <iostream>
using namespace std;

class Product
{
private:
	int _id = 0;
	char* _name = nullptr;
	char* _description = nullptr;
	double _price = 0;
	short _discount = 0; // 0-100%

public:
	Product()
	{
		int _id = 0;
		char* _name = nullptr;
		char* _description = nullptr;
		double _price = 0;
		short _discount = 0;
	}
	Product(int id, const char* name, const char* description, double price, short discount)
	{
		this->_id = id;
		strcpy_s(_name, strlen(name), name);
		strcpy_s(_description, strlen(description), description);
		this->_price = price;
		this->_discount = discount;
	}
	double getDiscountPrice();
	void print()
	{
		cout << "ID: " << _id;
		cout << "Name: " << _name;
		cout << "Description: " << _description;
		cout << "Price: " << _price;
		cout << "Discount: " << _discount;
	}
};

class Stock
{
private:
	char* _name = nullptr;
	Product** _products = nullptr; // dynamic array
	size_t _count = 0;

public:
	void print() // show all products in Stock
	{
		cout << "Name: " << _name;
		cout << "Count: " << _name;
	}
	Product* getProductById(int id)
	{
		for (size_t i = 0; i < _count; i++)
		{
			if (_products[i]->_id == id)
				return _products[i];
		}
	}

};

// Note: Hər iki class-a aid qeydlər:
// Constructors: Default, Parameterized
// Accessors: Getter, Setter
// Destructor
// Delegation of constructors
// Constructor Overlaoding
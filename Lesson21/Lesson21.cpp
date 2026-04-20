#include <iostream>

using namespace std;

class Fraction
{
private:
    int _numerator; // suret
    int _denominator; // mexrec
public:
    Fraction(int num, int don) // Constructor
    {
        this->_numerator = num;
        this->_denominator = don;
    }
    Fraction Multiply(const Fraction& other) // Kəsri kəsrə vurub yeni kəsr qaytarır
    {
        int numer = other._numerator * _numerator;
        int denum = other._denominator * _denominator;
        Fraction f(numer, denum);
        return f;
    }
    Fraction Add(const Fraction& other) // Kəsri kəsrlə toplayib yeni kəsr qaytarır
    {
        int numer = other._numerator * _denominator + other._denominator * _numerator;
        int denum = other._denominator * _denominator;
        Fraction f(numer, denum);
        return f;
    }
    Fraction Minus(const Fraction& other) // Kəsri kəsrden çixib yeni kəsr qaytarır
    {
        int numer = _numerator * other._denominator - other._numerator * _denominator;
        int denum = other._denominator * _denominator;
        Fraction f(numer, denum);
        return f;
    }
    Fraction Divide(const Fraction& other) // Kəsri kəsrə bölüb yeni kəsr qaytarır
    {
        int numer = other._denominator * _numerator;
        int denum = other._numerator * _denominator;
        Fraction f(numer, denum);
        return f;
    }
    void Simplify() // Kəsri ixtisar edir
    {
        int sign = 1;
        if (_numerator < 0)
        {
            sign *= -1;
            _numerator = _numerator * sign;
        }
        if (_denominator < 0)
        {
            sign *= -1;
            _denominator = _denominator * sign;
        }
        int i = 2;
        while (i <= _numerator && i <= _denominator)
        {
            if (_numerator % i == 0 && _denominator % i == 0)
            {
                _numerator /= i;
                _denominator /= i;
            }
            else
            {
                i++;
            }
        }
        _numerator *= sign;
    }
    void Show()
    {
        cout << "Numerator: " << this->_numerator << endl;
        cout << "Denumerator: " << this->_denominator << endl;
    }

};

class Point
{
private:
    int x;
    int y;
public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()
    {
        cout << "X: " << this->x << " ";
        cout << "Y: " << this->y << endl;
    }
    void SetterX(int x)
    {
        this->x = x;
    }
    void SetterY(int y)
    {
        this->y = y;
    }
    int GetterX()
    {
        return this->x;
    }
    int GetterY()
    {
        return this->y;
    }
};

class Counter
{
private:
    int _min;
    int _max;
    int _currentValue = 0;
public:
    Counter(int min, int max)
    {
        this->_min = min;
        this->_max = max;
    }
    void increment()
    {
        if (_currentValue > _max)
            _currentValue = _min;
        else
            _currentValue++;
    }
    void decrement()
    {
        if (_currentValue < _min)
            _currentValue = _min;
        else
            _currentValue--;
    }
    int getCurrent()
    {
        return this->_currentValue;
    }
};

int main()
{
    // Task 1
    Fraction f1(4, 7);
    Fraction f2(4, 7);
    Fraction result = f1.Multiply(f2);
    result.Show();
    system("pause"); cout << endl;

    Fraction f3(4, 16);
    f3.Simplify();
    f3.Show();

    // Task 2
    Point p1(2, 7);
    p1.Print();
    cout << p1.GetterX() << endl;
    p1.SetterY(6);
    p1.Print();
    system("pause"); cout << endl;

    // Task 3
    Counter c(0, 100);
    c.increment();
    cout << c.getCurrent(); // 1
    c.increment(); cout << endl;
    cout << c.getCurrent(); // 2
    c.decrement(); cout << endl;
    cout << c.getCurrent(); // 1


    return 0;
}

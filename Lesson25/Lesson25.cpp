#include <iostream>
#include <cassert>

using namespace std;

#include "vector.h"

int main()
{
    Vector v1(10);

    v1.push_back(1); 
    v1.push_back(2); 
    v1.push_back(3);
    v1.print();
    cout << endl << endl;

    v1.push_front(100);
    v1.print();
    cout << endl << endl;

    v1.pop_back();
    v1.print();
    cout << endl << endl;

    v1.pop_front();
    v1.print();
    cout << endl << endl;

    v1.insertByIndex(1, 999);
    v1.print();
    cout << endl << endl;

    v1.deleteByIndex(1);
    v1.print();
    cout << endl << endl;

    cout << "v1[0] = " << v1[0] << endl;

    v1();
    cout << endl << endl;

    v1.push_back(5).push_back(2).push_back(5);
    v1.print();
    cout << endl << endl;

    cout << "find 5: " << v1.find(5) << endl;
    cout << "rfind 5: " << v1.rfind(5) << endl;

    v1.sort();
    v1.print();
    cout << endl << endl;

    v1.sort(true);
    v1.print();
    cout << endl << endl;

    ++v1;
    v1.print();
    cout << endl << endl;
    v1--;
    v1.print();
    cout << endl << endl;

    Vector v2(7);
    v2.push_back(10); 
    v2.push_back(20);

    Vector v3 = v1 + v2;
    v3.print();
    cout << endl << endl;

    Vector v4 = v3;

    cout << "v3 == v4: " << (v3 == v4) << endl;
    cout << "v3 != v1: " << (v3 != v1) << endl;
    cout << endl << endl;

    Vector v5;
    v5 = v1;
    v5.print();
    cout << endl << endl;

    Vector v6 = v1;
    v6.print();
    cout << endl << endl;

    return 0;
}
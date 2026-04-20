#include <iostream>
#include <cassert>

using namespace std;

#include "mystring.h"

int main()
{
    myString s1("Salam");
    myString s2("Dunya");
    myString s3(s1);
    myString s4(5, 'A');

    cout << "s1: " << s1.print() << endl;
    cout << "s2: " << s2.print() << endl;
    cout << "s3 (copy): " << s3.print() << endl;
    cout << "s4 (AAAAA): " << s4.print() << endl;

    s1.append(" World");
    cout << "append: " << s1.print() << endl;

    s1.push_back('!');
    cout << "push_back: " << s1.print() << endl;

    s1.pop_back();
    cout << "pop_back: " << s1.print() << endl;

    cout << "front: " << s1.front() << endl;
    cout << "back: " << s1.back() << endl;
    cout << "at(1): " << s1.at(1) << endl;

    cout << "find 'a': " << s1.find('a') << endl;
    cout << "rfind 'a': " << s1.rfind('a') << endl;

    cout << "size: " << s1.size() << endl;
    cout << "capacity: " << s1.capacity() << endl;

    s1.resize(3);
    cout << "resize(3): " << s1.print() << endl;

    s1.reserve(50);
    cout << "capacity after reserve: " << s1.capacity() << endl;

    s2.clear();
    cout << "s2 empty after clear: " << s2.empty() << endl;

    myString a("abc");
    myString b("abd");

    cout << "compare a vs b: " << a.compare(b) << endl;

    s2 = s1;
    cout << "assignment s2 = s1: " << s2.print() << endl;

    return 0;
}

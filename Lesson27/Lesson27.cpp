#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

#include "keyValue.h"
#include "dictionary.h"

int main()
{
    cout << boolalpha;

    Dictionary<int, string> dict;

    dict.add(1, "Apple");
    dict.add(2, "Banana");
    dict.add(3, "Cherry");

    cout << "Key 1: " << dict[1] << endl;
    dict[1] = "Green Apple";
    cout << "Updated Key 1: " << dict[1] << endl;

    cout << "Item(2): " << dict.item(2) << endl;

    cout << "Count: " << dict.count() << endl;
    cout << "Capacity: " << dict.capacity() << endl;

    cout << "Contains key 2: " << dict.containsKey(2) << endl;
    cout << "Contains key 10: " << dict.containsKey(10) << endl;

    cout << "Contains value 'Cherry': " << dict.containsValue("Cherry") << endl;
    cout << "Contains value 'Apple': " << dict.containsValue("Apple") << endl;

    const int* keys = dict.keys();
    cout << "Keys: ";
    for (size_t i = 0; i < dict.count(); i++)
        cout << keys[i] << " ";
    cout << endl;

    const string* values = dict.values();
    cout << "Values: ";
    for (size_t i = 0; i < dict.count(); i++)
        cout << values[i] << " ";
    cout << endl;

    KeyValuePair<int, string>* items = dict.items();
    cout << "Items:" << endl;
    for (size_t i = 0; i < dict.count(); i++)
        cout << items[i].key << " -> " << items[i].value << endl;

    cout << "Remove key 2: " << dict.remove(2) << endl;
    cout << "After remove, count: " << dict.count() << endl;

    dict.clear();
    cout << "After clear, count: " << dict.count() << endl;

    delete[] keys;
    delete[] values;

    return 0;
}
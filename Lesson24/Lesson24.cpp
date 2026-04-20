#include <iostream>
#include <cassert>

using namespace std;

#include "airPlane.h"
#include "garage.h"

int main()
{
    Airplane::MAXCOUNT = 10;

    cout << "===== Airplane test =====" << endl;

    Airplane a1("Boeing 737", "White", 2.5, 180);
    Airplane a2("Airbus A320", "Blue", 2.7, 160);

    a1.print(); cout << endl;
    a2.print(); cout << endl;

    cout << endl << "-- Copy constructor --" << endl;
    Airplane a3 = a1;
    a3.print(); cout << endl;

    cout << endl << "-- Move assignment --" << endl;
    Airplane a4;
    a4 = move(a2);
    a4.print(); cout << endl;

    cout << endl << "===== Garage test =====" << endl;

    Garage g1("Main Garage", "Baku", 3);

    g1.addAirplane(new Airplane("F16", "Gray", 3.0, 1), 0);
    g1.addAirplane(new Airplane("Boeing 747", "White", 4.0, 400), 1);
    g1.addAirplane(new Airplane("Airbus A380", "White", 4.5, 500), 2);

    cout << endl << "-- All airplanes --" << endl;
    g1.print();

    cout << endl << "-- getAirplaneById --" << endl;
    Airplane* found = g1.getAirplaneById(6);
    if (found)
        found->print();
    else
        cout << "Not found" << endl;

    cout << endl << "-- Capacity > 100 --" << endl;
    Airplane** cap = g1.getAirplanesCapacityGreaterThan(100);
    for (size_t i = 0; cap[i] != nullptr; i++)
    {
        cap[i]->print();
        cout << endl;
    }
    delete[] cap;

    cout << endl << "-- Color = White --" << endl;
    Airplane** col = g1.getAirplanesByColor("White");
    for (size_t i = 0; col[i] != nullptr; i++)
    {
        col[i]->print();
        cout << endl;
    }
    delete[] col;

    return 0;
}

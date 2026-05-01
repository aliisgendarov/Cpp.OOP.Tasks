#include <iostream>

using namespace std;

#include "SimpleQueue.h"
#include "Worker.h"
#include "Printer.h"

int main()
{
    Printer printer;

    printer.Request(Worker("Veli", "Semedov", 35, 3));
    printer.Request(Worker("Veli", "Memmedov", 30, 2));
    printer.Request(Worker("Xelil", "Hesenov", 22, 4));

    printer.start();

    return 0;
}
#pragma once

class Printer {
private:
    SimpleQueue<Worker> workerQueue;

public:
    void Request(Worker w)
    {
        workerQueue.enQueue(w);
    }

    void start() {
        while (!workerQueue.isEmpty())
        {
            Worker w = workerQueue.peek();

            cout << w.getName() << " " << w.getSurname() << endl;
            cout << "Sehifeler: " << w.getPageCount() << endl;

            for (int i = 0; i < w.getPageCount(); i++)
            {
                cout << "Sehife " << i + 1 << " cap olunur" << endl;
            }

            cout << "Print bitdi: " << w.getName() << endl << endl;

            workerQueue.deQueue();
        }

        cout << "Queue bosdur!" << endl;
    }
};
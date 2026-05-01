#pragma once

class Worker
{
private:
    size_t _id;
    string _name;
    string _surname;
    size_t _age;
    size_t _pageCount;
    static size_t staticId;

public:
    Worker()
    {
        _id = ++staticId;
        _name = "";
        _surname = "";
        _age = 0;
        _pageCount = 0;
    }
    Worker(string name, string surname, size_t age, size_t pageCount) {
        this->_id = ++staticId;
        this->_name = name;
        this->_surname = surname;
        this->_age = age;
        this->_pageCount = pageCount;
    }

    size_t getId() { return _id; }
    string getName() { return _name; }
    string getSurname() { return _surname; }
    size_t getAge() { return _age; }
    size_t getPageCount() { return _pageCount; }
};

size_t Worker::staticId = 0;
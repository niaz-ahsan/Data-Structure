#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(std::string &&n) : _name(&n), _address(nullptr) {}
    ~Person() {
        delete _name;
        delete _address;
    }

    void set_name(std::string *name); 
    void set_address(std::string *address);

    std::string get_name();
    std::string get_address();
private:
    std::string *_name;
    std::string *_address;    
};

#endif
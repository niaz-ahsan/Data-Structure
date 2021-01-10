#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(){}
    Person(std::string &&n) : _name(&n), _address(nullptr) {}
    ~Person() {}

    void set_name(std::string *name); 
    void set_address(std::string *address);

    std::string get_name();
    std::string get_address();
    bool operator==(Person p) {
        return get_name() == p.get_name();
    }
private:
    std::string *_name;
    std::string *_address;    
};

#endif
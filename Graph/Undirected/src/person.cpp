#include "person.h"

void Person::set_name(std::string *name) {
    _name = name;
} 
void Person::set_address(std::string *address) {
    _address = address;
}

std::string Person::get_name() {
    return *_name;
}
std::string Person::get_address() {
    return *_address;
}
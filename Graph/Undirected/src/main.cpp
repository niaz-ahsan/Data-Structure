#include <iostream>

#include "person.h"

int main() {
    Person *niaz = new Person("Niaz Ahsan");

    std::cout << niaz->get_name() << std::endl;

    return 0;
}
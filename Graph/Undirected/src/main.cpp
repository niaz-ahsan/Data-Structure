#include <iostream>

#include "person.h"
#include "graph.h"
#include "graph.cpp"

int main() {
    Person *niaz = new Person("Niaz Ahsan");
    Person *babu = new Person("Noor Babu");
    Person *sakib = new Person("A S M Muntaheen");

    Graph<Person> *graph = new Graph<Person>(5);
    graph->add_node(niaz);
    graph->add_node(babu);
    graph->add_node(sakib);


    return 0;
}
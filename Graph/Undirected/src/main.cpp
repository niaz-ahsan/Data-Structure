#include <iostream>

#include "person.h"
#include "graph.h"
#include "graph.cpp"

int main() {
    Person *john = new Person("John Doe");
    Person *steve = new Person("Steve Smith");
    Person *marco = new Person("Marco Polo");
    Person *ethan = new Person("Ethan Sarina");

    Graph<Person> *graph = new Graph<Person>(5);
    graph->add_node(john);
    graph->add_node(steve);
    graph->add_node(marco);
    graph->add_node(ethan);

    graph->load_matrix();

    graph->add_edge(john, marco);
    graph->add_edge(steve, ethan);
    graph->add_edge(marco, ethan);
    graph->add_edge(john, steve);
    graph->add_edge(john, john);

    //graph->remove_edge(babu, sakib);

    graph->print_graph();

    return 0;
}
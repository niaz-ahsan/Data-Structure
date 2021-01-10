#include <iostream>

#include "person.h"
#include "graph.h"
#include "graph.cpp"

int main() {
    Person *niaz = new Person("Niaz Ahsan");
    Person *babu = new Person("Noor Babu");
    Person *sakib = new Person("A S M Muntaheen");
    Person *khadija = new Person("Khadija Siddiqua");

    Graph<Person> *graph = new Graph<Person>(5);
    graph->add_node(niaz);
    graph->add_node(babu);
    graph->add_node(sakib);
    graph->add_node(khadija);

    graph->load_matrix();

    graph->add_edge(niaz, babu);
    graph->add_edge(babu, sakib);
    graph->add_edge(niaz, sakib);
    graph->add_edge(niaz, khadija);

    //graph->remove_edge(babu, sakib);

    graph->print_graph();

    return 0;
}
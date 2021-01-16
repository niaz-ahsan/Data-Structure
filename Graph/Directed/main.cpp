#include <iostream>
#include <string>
#include "graph.h"
#include "graph.cpp"

#include "linked_list.h"

int main() {
    Graph<std::string> g(4);
    g.add_edge("John Doe","Steve Smith");
    g.add_edge("John Doe","Marco Polo");
    g.add_edge("Steve Smith", "Ethan Sarina");
    g.add_edge("Steve Smith", "Marco Polo");
    g.add_edge("Ethan Sarina", "John Doe");
    g.print();
}
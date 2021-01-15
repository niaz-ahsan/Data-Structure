#include <iostream>
#include "graph.h"
#include "graph.cpp"

#include "linked_list.h"

int main() {
    /*Graph<int> g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);*/

    Node<int> node0(0);
    Node<int> node1(1);
    Node<int> node2(2);

    Linked_List<int> list;
    list.push(&node0);
    list.push(&node2);
    list.push(&node1);
}
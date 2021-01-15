#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "linked_list.h"
#include "linked_list.cpp"

template<typename T>
class Graph {
public:
    Graph(int l) : _limit(l) {}
    ~Graph() {
        //delete _lists;
    }

    void add_edge(T, T);
    void remove_edge(T, T);
    void print();
private:
    int _limit;
    std::vector<Linked_List<T>*> _lists;
    int look_for_head(T);
};


#endif
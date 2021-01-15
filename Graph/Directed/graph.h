#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template<typename T>
class Graph {
public:
    Graph(int l) : _limit(l) {}
    ~Graph() {}

    void add_edge(T*, T*);
    void remove_edge(T*, T*);
    void print();
private:
    int _limit;
    std::vector<T> _vertices;
};


#endif
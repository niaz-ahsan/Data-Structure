#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

template<typename T>
class Graph {
public:    
    //Graph(){};
    Graph(int l) : _limit(l) {}
    ~Graph() {}
    void add_node(T*);
    void add_edge(T*, T*);
    void remove_edge(T*, T*);
    void print_graph();
private:
    int _limit;
    std::vector<T> _nodes;
    std::vector<std::vector<int>> _inner_matrix;    
    void load_matrix();
    int find_index(T*);
};

#endif
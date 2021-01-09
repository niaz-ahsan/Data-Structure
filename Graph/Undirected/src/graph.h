#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template<typename T>
class Graph {
public:    
    Graph(int l) : _limit(l) {}
    void add_node(T *node) {
        if(_nodes.size() <= _limit) {
            _nodes.push_back(node);
        }
    };
    
private:
    int _limit;
    std::vector<T> _nodes;    
};

#endif
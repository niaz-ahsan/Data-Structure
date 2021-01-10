#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

template<typename T>
class Graph {
public:    
    //Graph(){};
    Graph(int l) : _limit(l), longest_name_index(-1), longest_name_length(0) {}
    ~Graph() {}
    void add_node(T*);
    void add_edge(T*, T*);
    void remove_edge(T*, T*);
    void print_graph();
    void load_matrix();
private:
    int _limit;
    std::vector<T> _nodes;
    std::vector<std::vector<int>> _inner_matrix;    
    int longest_name_index;
    size_t longest_name_length;
    void set_whitespace(size_t);
    int find_index(T*);
    void set_longest_name_data();
};

#endif
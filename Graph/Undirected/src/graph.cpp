#include "graph.h"
#include "person.h"
#include <iostream>

template<typename T>
void Graph<T>::load_matrix() {
    std::vector<int> inner;
    for(int i=0; i<_nodes.size(); i++) {
        inner.clear();
        for(int j=0; j<_nodes.size(); j++) {
            inner.push_back(0);
        }
        _inner_matrix.push_back(inner);
    }
}

template<typename T>
void Graph<T>::add_node(T *node) {
    if(_nodes.size() <= _limit) {
        _nodes.push_back(*node);
    }
    load_matrix();
}

template<typename T>
void Graph<T>::add_edge(T *src_node, T *des_node) {
    int row = find_index(src_node);
    int col = find_index(des_node);
    //std::cout << row << " " << col << std::endl;
    _inner_matrix[row][col] = 1;
}

template<typename T>
void Graph<T>::remove_edge(T *src_node, T *des_node) {
    int row = find_index(src_node);
    int col = find_index(des_node);
    _inner_matrix[row][col] = 0;
}

template<typename T>
int Graph<T>::find_index(T *node) {
    auto ptr = find(_nodes.begin(), _nodes.end(), *node);

    if(ptr != _nodes.end()) {
        int index = ptr - _nodes.begin();
        return index;
    } else {
        // not found
        return -1;
    }
}

template<typename T> 
void Graph<T>::print_graph() {
    for(int i=0; i<_nodes.size(); i++) {
        for(int j=0; j<_nodes.size(); j++) {
            std::cout << _inner_matrix[i][j];
        }
        std::cout << std::endl;
    }
}



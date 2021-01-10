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
}

template<typename T>
void Graph<T>::add_edge(T *src_node, T *des_node) {
    int row = find_index(src_node);
    int col = find_index(des_node);
    if(row == col) {
        _inner_matrix[row][col] = 1;
        return;
    }
    _inner_matrix[row][col] = 1;
    _inner_matrix[col][row] = 1; // both of the cell connected as this is undirected
}

template<typename T>
void Graph<T>::remove_edge(T *src_node, T *des_node) {
    int row = find_index(src_node);
    int col = find_index(des_node);
    if(row == col) {
        _inner_matrix[row][col] = 0;
        return;
    }
    _inner_matrix[row][col] = 0;
    _inner_matrix[col][row] = 0; // both of the cell connected as this is undirected
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
void Graph<T>::set_whitespace(size_t range) {
    for(size_t x=0; x<range; x++) {
        std::cout << " ";
    }
}

template<typename T> 
void Graph<T>::print_graph() {
    // Printing whitespaces equal to len of 1st elem of node
    set_longest_name_data();
    std::string blank_for = _nodes[longest_name_index].get_name();
    set_whitespace(blank_for.length()+3);

    // Printing 1st row with the names and counting their word count to maintain same whitespace distance while printing them in next rows.
    for(int i=0; i<_nodes.size(); i++) {
        std::string name = _nodes[i].get_name();
        std::cout << name << " | ";
    }

    std::cout << std::endl;

    for(int i=0; i<_nodes.size(); i++) {
        for(int j=0; j<=_nodes.size(); j++) {
            if(j==0) {
                std::string name = _nodes[i].get_name();
                std::cout << name;
                if(i == longest_name_index) {
                    // this is longest word
                    std::cout << " | ";
                } else {
                    // not the longest
                    size_t delta = longest_name_length - name.length();
                    set_whitespace(delta);
                    std::cout << " | ";
                }
            } else {
                //std::cout << _inner_matrix[i][j-1];
                if(_inner_matrix[i][j-1] == 1) {
                    std::cout << "#";
                } else {
                    std::cout << " ";
                }
                std::string name = _nodes[j-1].get_name();
                set_whitespace(name.length());    
                std::cout << "| ";
            }
            
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Graph<T>::set_longest_name_data() {
    for(int i=0; i<_nodes.size(); i++) {
        std::string name = _nodes[i].get_name();
        if(name.length() > longest_name_length) {
            longest_name_length = name.length();
            longest_name_index = i;
        }
    }  
}





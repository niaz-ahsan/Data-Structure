#include "graph.h"
#include "person.h"

template<typename T>
void Graph<T>::load_matrix() {
    for(int i=0; i<_nodes.size(); i++) {
        for(int j=0; j<_nodes.size(); j++) {
            _inner_matrix[i][j] = 0;
        }
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
    auto ptr = find(_nodes.begin(), _nodes.end(), node);

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

}

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.

/*Graph<Person>* get_graph_instance() {
    Graph<Person> *graph = new Graph<Person>(5);
    return graph;
}*/


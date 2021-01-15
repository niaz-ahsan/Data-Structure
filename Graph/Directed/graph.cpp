#include "graph.h"
#include <iostream>

template<typename T>
void Graph<T>::add_edge(T src, T des) {
    int index = look_for_head(src);
    if(index >= 0) {
        // already exists as a head
        Node<T> *des_node = new Node<T>(des);
        _lists[index]->push(des_node);
    } else {
        // new element
        if(_lists.size() <= _limit) {
            Linked_List<T> *list = new Linked_List<T>();
            Node<T> *src_node = new Node<T>(src);
            Node<T> *des_node = new Node<T>(des);
            list->push(src_node);
            list->push(des_node);
            _lists.emplace_back(list); 
        } else {
            std::cout << "Limit reached!" << std::endl;
        }    
    }
}

template<typename T>
int Graph<T>::look_for_head(T data) {
    for(int i=0; i<_lists.size(); i++) {
        if(_lists[i]->get_head_data() == data) {
            return i;
        }
    }

    return -1;
}
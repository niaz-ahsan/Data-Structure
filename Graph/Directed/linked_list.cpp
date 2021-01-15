#include "linked_list.h"
#include <iostream>

template<typename T>
void Linked_List<T>::push(Node<T> *node) {
    if(is_empty()) {
        _head = node;
        _tail = node;
    } else {
        _tail->set_next(node);
        _tail = node;
    }
}

template<typename T>
void Linked_List<T>::remove(T to_delete) {
    if(is_empty()) {
        std::cout << "Delete: No element to delete" << std::endl;
        return;
    }    

    if(_head->get_data() == to_delete) {
        _head = _head->get_next();
    } else {
        Node<T> *current_node = _head;
        Node<T> *next_node = _head->get_next();

        while(next_node != nullptr) {
            if(next_node->get_data() == to_delete) {
                current_node->set_next(next_node->get_next());
                break;
            } else {
                current_node = next_node;
                next_node = next_node->get_next();
            }
        }
    }
}

template<typename T>
T Linked_List<T>::get_head_data() {
    return _head->get_data();
}
#include <iostream>

template<typename T>
class Node {
public:
    Node(T data) : _data(data), _next(nullptr) {}
    void set_next(Node *next) {
        _next = next;
    }
    Node* get_next() { return _next; }
    T get_data() { return _data; } 
    void print() {
        std::cout << _data << " -> ";
    }
private:    
    T _data;
    Node *_next;
};

template<typename T>
class Linked_list {
public:
    Linked_list() : _head(nullptr), _tail(nullptr) {}
    
    // pushes Node<T> at the end
    void push(Node<T> *node) {
        // if head is nullptr set node as head and tail
        // else connect tail's next ptr to this node
        if(_head == nullptr) {
            _head = node;
            _tail = node;
        } else {
            _tail->set_next(node);
            _tail = node;
        }
    }

    // pops the first element
    void pop() {
        if(_head != nullptr) {
            _head = _head->get_next();
        } else {
            std::cout << "No more element in your linked list!";
        }
    }

    void print() {
        if(_head != nullptr) {
            Node<T> *present_node = _head;
            while(present_node->get_next() != nullptr) {
                present_node->print();
                present_node = present_node->get_next();
            }
            std::cout << present_node->get_data() << " -> ";
            std::cout << std::endl;
        } else {
            std::cout << "No item in Linked List" << std::endl;
        }
    }
private:
    Node<T> *_head, *_tail;
};

int main() {
    Node<int> *n1 = new Node<int>(4);
    Node<int> *n2 = new Node<int>(67);
    Node<int> *n3 = new Node<int>(25);

    Linked_list<int> *linked_list = new Linked_list<int>();
    linked_list->push(n1);
    linked_list->push(n2);
    linked_list->push(n3);
    linked_list->print();

    linked_list->pop();
    linked_list->print();


    delete linked_list;
    delete n1;
    delete n2;
    delete n3;     
}
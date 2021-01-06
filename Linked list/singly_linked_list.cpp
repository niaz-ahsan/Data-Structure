// Authored by: Niaz
// On 3 Jan 21
// Implementation of a Singly Linked List using dynamic memory

#include <iostream>

template<typename T>
class Node {
public:
    Node(T data) : _data(data), _next(nullptr) {}
    ~Node() {
        delete _next;
    }
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
    ~Linked_list() {
        delete _head;
        delete _tail;
    }
    
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

    bool search(T search_for) {
        if(_head == nullptr) {
            return false;
        }
        bool found = false;
        Node<T> *present_node = _head;
        while(present_node->get_next() != nullptr) {
            Node<T> *next_node = present_node->get_next();
            if(present_node == _head) {
                if(present_node->get_data() == search_for || next_node->get_data() == search_for) {
                    found = true;
                    break;
                }
            } else {
                if (next_node->get_data() == search_for) {
                    found = true;
                    break;
                }
            }
            present_node = next_node;
        }
        return found;
    }

    void print() {
        if(_head != nullptr) {
            Node<T> *present_node = _head;
            while(present_node->get_next() != nullptr) {
                present_node->print();
                present_node = present_node->get_next();
            }
            present_node->print();
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
    Node<int> *n4 = new Node<int>(100); 

    Linked_list<int> *linked_list = new Linked_list<int>();
    // Pushing 
    linked_list->push(n1);
    linked_list->push(n2);
    linked_list->push(n3);
    linked_list->push(n4);
    std::cout << "After pushing: ";
    linked_list->print();

    // Searching
    std::cout << "Searching 4: " << linked_list->search(4) << std::endl;

    //Popping
    linked_list->pop();
    std::cout << "After one pop op: ";
    linked_list->print();

    // Searching again
    std::cout << "Searching 4: " << linked_list->search(4) << std::endl;    
}
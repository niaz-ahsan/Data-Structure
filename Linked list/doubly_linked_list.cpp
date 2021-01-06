// Authored by: Niaz
// On 5 Jan 21
// Implementation of a Doubly Linked List using dynamic memory

#include <iostream>

template<typename T>
class Node {
public:
    Node(T data) : _data(data), _next(nullptr), _prev(nullptr) {}
    ~Node() {
        delete _next;
        delete _prev;
    }
    void set_next(Node *next) {
        _next = next;
    }
    void set_prev(Node *prev) {
        _prev = prev;
    }
    Node* get_next() { return _next; }
    Node* get_prev() { return _prev; }
    T get_data() { return _data; } 
    void print() {
        std::cout << " <- " << _data << " -> ";
    }
private:    
    T _data;
    Node *_next;
    Node *_prev;
};

template<typename T>
class Doubly_Linked_List {
public:
    Doubly_Linked_List() : _head(nullptr), _tail(nullptr) {}
    ~Doubly_Linked_List() {
        delete _head;
        delete _tail;
    }

    void insert_front(Node<T> *node) {
        if(_head == nullptr) {
            // if list is empty
            _head = node;
            _tail = node;
        } else {
            // list not empty
            _head->set_prev(node);
            node->set_next(_head);
            _head = node;
        }   
    }

    void insert_back(Node<T> *node) {
        if(_tail == nullptr) {
            // if list is empty
            _head = node;
            _tail = node;
        } else {
            // list not empty
            _tail->set_next(node);
            node->set_prev(_tail);
            _tail = node;
        }
    }

    void delete_front() {
        if(_head == nullptr) {
            // list is empty
            std::cout << "No more item in the list!" << std::endl;
        } else {
            // list not empty
            _head = _head->get_next();
            _head->set_prev(nullptr);
        }
    }

    void delete_back() {
        if(_tail == nullptr) {
            // list is empty
            std::cout << "No more item in the list!" << std::endl;
        } else {
            // list not empty
            _tail = _tail->get_prev();
            _tail->set_next(nullptr);
        }
    }

    void display_forward() {
        if(_head == nullptr) {
            std::cout << "No item in the list" << std::endl;
        } else {
            Node<T> *current_node = _head;
            while(current_node->get_next() != nullptr) {
                current_node->print();
                current_node = current_node->get_next();
            }
            current_node->print();
            std::cout << std::endl;
        }
    }

    void display_backward() {
        if(_tail == nullptr) {
            std::cout << "No item in the list" << std::endl;
        } else {
            Node<T> *current_node = _tail;
            while(current_node->get_prev() != nullptr) {
                current_node->print();
                current_node = current_node->get_prev();
            }
            current_node->print();
            std::cout << std::endl;
        }
    }
private:
    Node<T> *_head, *_tail;
};

int main() {
    Node<char> *c1 = new Node<char>('c');
    Node<char> *c2 = new Node<char>('a');
    Node<char> *c3 = new Node<char>('r');
    Node<char> *c4 = new Node<char>('t');
    Node<char> *c5 = new Node<char>('f');

    Doubly_Linked_List<char> *the_list = new Doubly_Linked_List<char>();
    the_list->insert_back(c1);
    the_list->insert_back(c2);
    the_list->insert_back(c3);
    the_list->insert_back(c4);

    std::cout << "Initial push back: ";
    the_list->display_forward();

    the_list->delete_front();
    the_list->insert_front(c5);
    std::cout << "Replacing 1st elem by deleting and inserting front: ";
    the_list->display_forward();
    std::cout << "Displaying backward: ";
    the_list->display_backward();
}
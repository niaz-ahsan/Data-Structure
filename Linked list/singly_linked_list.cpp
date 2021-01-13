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
    
    void insert_at_tail(Node<T> *node) {
        if(is_empty()) {
            _head = node;
            _tail = node;
        } else {
            _tail->set_next(node);
            _tail = node;
        }
    }

    void insert_at_head(Node<T> *node) {
        if(is_empty()) {
            _head = node;
            _tail = node;
        } else {
            node->set_next(_head);
            _head = node;
        }
    }

    void delete_at_head() {
        if(!is_empty()) {
            _head = _head->get_next();
        } else {
            std::cout << "del_at_head: No more element in your linked list!" << std::endl;
        }
    }

    bool search(T search_for) {
        if(is_empty()) {
            return false;
        }
        bool found = false;
        Node<T> *current_node = _head;
        while(current_node->get_next() != nullptr) {
            Node<T> *next_node = current_node->get_next();
            if(current_node == _head) {
                if(current_node->get_data() == search_for || next_node->get_data() == search_for) {
                    found = true;
                    break;
                }
            } else {
                if (next_node->get_data() == search_for) {
                    found = true;
                    break;
                }
            }
            current_node = next_node;
        }
        return found;
    }

    void delete_node(T to_delete) {
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

    int get_length() {
        if(is_empty()) {
            return 0;
        } 

        int counter = 0;
        Node<T> *current_node = _head;
        while(current_node->get_next() != nullptr) {
            counter++;
            current_node = current_node->get_next();
        }
        counter++;
        return counter;
    }

    bool is_empty() {
        return (_head == nullptr);
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
            std::cout << "print: No item in Linked List" << std::endl; 
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
    linked_list->insert_at_head(n1);
    linked_list->insert_at_head(n2);
    linked_list->insert_at_head(n3);
    linked_list->insert_at_head(n4);
    std::cout << "After pushing: ";
    linked_list->print();

    // Searching
    std::cout << "Searching 4: " << linked_list->search(4) << std::endl;

    //Popping
    linked_list->delete_at_head();
    linked_list->delete_at_head();
    linked_list->delete_at_head();
    linked_list->delete_at_head();
    linked_list->delete_at_head();
    std::cout << "After delete op: ";
    linked_list->print();

    // Searching again
    std::cout << "Searching 4: " << linked_list->search(4) << std::endl;    
}
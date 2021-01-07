// Authored by: Niaz
// On 7 Jan 21
// Implementation of a Stack using Doubly Linked List

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
        std::cout <<  _data << " | ";
    }
private:    
    T _data;
    Node *_next;
    Node *_prev;
};

template <typename T>
class Stack {
public:
    Stack(int l) : _node(nullptr), _ptr(nullptr), _limit(l), _count(0) {}
    ~Stack() { 
        delete _node;  
        if(_ptr != nullptr) {
            delete _ptr;
        }
    }

    // pushes on top
    void push(T data) {
        if(_count == _limit) {
            std::cout << "Stack Overflow! Can't push anymore" << std::endl;
            return;
        }

        generate_node(data);
        if(_ptr == nullptr) {
            // stack empty, push new item
            _ptr = _node;
        } else {
            // stack not empty
            _ptr->set_prev(_node);
            _node->set_next(_ptr);
            _ptr = _node;
        }
        ++_count;
    }

    // pops from top
    T pop() {
        if(_ptr == nullptr) {
            std::cout << "Pop: No item in the stack" << std::endl;
            return 0;
        } 

        Node<T> *temp = _ptr;
        if(_ptr->get_next() != nullptr) {
            _ptr = _ptr->get_next();
            _ptr->set_prev(nullptr);
        } else {
            _ptr = nullptr;
        }
        return temp->get_data();
    }

    void display() {
        if(_ptr == nullptr) {
            std::cout << "Display: No item in the stack" << std::endl;
            return;
        } 

        std::cout << "Data separated by '|'" << std::endl;
        Node<T> *temp = _ptr;
        while(temp->get_next() != nullptr) {
            temp->print();
            temp = temp->get_next();
        }
        temp->print();
        std::cout << std::endl;       
    }
private:
    Node<T> *_node;
    Node<T> *_ptr;  // to point at head 
    int _limit; 
    int _count;
    void generate_node(T data) {
        _node = new Node<T>(data);
    }
};

int main() {
    Stack<int> *my_stack = new Stack<int>(5);
    my_stack->push(3);
    my_stack->push(6);
    my_stack->push(9);
    my_stack->push(11);
    my_stack->push(15);
    my_stack->push(19); // Operation shouldn't be successful

    my_stack->display();

    my_stack->pop();
    my_stack->pop();
    my_stack->pop();
    my_stack->pop();
    my_stack->pop();
    my_stack->pop();

    my_stack->display();
}
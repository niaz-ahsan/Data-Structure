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
        std::cout << _data << " | ";
    }
private:    
    T _data;
    Node *_next;
};

template<typename T>
class Queue {
public:
    Queue(int l) : _head(nullptr), _tail(nullptr), _node(nullptr), _limit(l), _count(0) {}
    ~Queue() {
        delete _head;
        delete _tail;
        delete _node;
    }

    // push data
    void enqueue(T data) {
        if(_count == _limit) {
            std::cout << "Queue overfolw! Can't push anymore!" << std::endl;
            return;
        }

        generate_node(data);
        if(_tail == nullptr) {
            // queue is empty
            _head = _node;
            _tail = _node;
        } else {
            // queue not empty
            _tail->set_next(_node);
            _tail = _node;
        }
        ++_count;
    }

    // pops data
    T deque() {
        if(_head == nullptr) {
            std::cout << "Dequeue: No item in the list!" << std::endl;
            return 0;
        }

        Node<T> *temp = _head;
        _head = _head->get_next();
        return temp->get_data();
    }

    void display() {
        if(_head == nullptr) {
            std::cout << "Display: No item in the list!" << std::endl;
            return;
        }

        Node<T> *temp = _head;
        while(temp->get_next() != nullptr) {
            temp->print();
            temp = temp->get_next();
        }
        temp->print();
        std::cout << std::endl;
    }
private:
    Node<T> *_head;
    Node<T> *_tail;
    Node<T> *_node;
    int _limit;
    int _count;
    void generate_node(T data) {
        _node = new Node<T>(data);
    }
};

int main() {
    Queue<int> *my_q = new Queue<int>(5);
    my_q->enqueue(5);
    my_q->enqueue(10);
    my_q->enqueue(15);
    my_q->enqueue(10);
    my_q->enqueue(15);
    my_q->enqueue(10); // operation shouldn't be successful
    my_q->enqueue(15); // operation shouldn't be successful

    my_q->display();

    my_q->deque();
    my_q->deque();
    my_q->deque();
    my_q->deque();
    my_q->deque();
    my_q->deque(); // print error message
    my_q->deque(); // print error message

    my_q->display();
}
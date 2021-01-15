#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
private:    
    T _data;
    Node *_next;
};

template<typename T>
class Linked_List {
public:
    Linked_List() : _head(nullptr) {}
    ~Linked_List() {
        delete _head;
        delete _tail;
    }

    void push(T*);
    void remove(T);
    bool is_empty() {
        return (_head == nullptr);
    }
private:
    T *_head, *_tail;    
};

#endif
#include<iostream>
using namespace std;


template<typename T>
class Queue{
    
    template<typename V>
        class Node{
            public:
            V data;
            Node<V>* next;
            Node(V data) : data(data), next(NULL) {}
        };
    int size; // How many elements are inserted in queue
    Node<T>* _front;
    Node<T>* _rear;
    
    public:

    // Default constructor
    Queue() : size(0), _front(NULL), _rear(NULL) {}
    
    // Copy constructor
    Queue(Queue<T> const &q){
        size = q.size;
        _front = NULL;
        _rear = NULL;
        Node<T>* tmp{q._front};
        while(tmp != NULL){
            Node<T>* node{new Node<T>(tmp->data)};
            if(_front == NULL){
                _front = node;
                _rear = node;
            }else{
                _rear->next = node;
                _rear = node;
            }
            tmp = tmp->next;
        }
    }

    // Copy assignment operator
    void operator=(Queue<T> const &q){
        size = q.size;
        _front = NULL;
        _rear = NULL;
        Node<T>* tmp{q._front};
        while(tmp != NULL){
            Node<T>* node{new Node<T>(tmp->data)};
            if(_front == NULL){
                _front = node;
                _rear = node;
            }else{
                _rear->next = node;
                _rear = node;
            }
            tmp = tmp->next;
        }
    }


    int getSize(){
        return size;
    }

    bool empty(){
        return size == 0;
    }

    T front(){
        if(_front == NULL) return -1;
        return _front->data;
    }

    T rear(){
        if(_rear == NULL) return -1;
        return _rear->data;
    }

    void push(T data){
        Node<T>* node{new Node<T>(data)};
        if(_front == NULL){
            _front = node;
            _rear = node;
        }else{
            _rear->next = node;
            _rear = node;
        }
        size += 1;
    }

    void pop(){
        if(_front == NULL){
            cout << "Queue is empty !!!" << endl;
            return;
        }
        if(_front == _rear){
            Node<T>* tmp{_front};
            _front = NULL;
            _rear = NULL;
            delete tmp;
            size -= 1;
            return;
        }
        Node<T>* tmp{_front};
        _front = _front->next;
        tmp->next = NULL;
        delete tmp;
        size -= 1;
    }
};

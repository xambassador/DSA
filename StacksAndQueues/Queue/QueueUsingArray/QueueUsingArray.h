#include<iostream>
using namespace std;

/* Implement Queue using array */
/* Circular array based method */



template<typename T>
class Queue{
    T data; // Data that store in queue
    int size; // how many elements are inserted
    int capacity; // Indicate how many element that queue can store
    int frontIndex; // Represent front
    int rearIndex; // Represent rear
    int nextIndex; // Represent next element is inserted at this index
    T* arr; // Container for store data

    public:
    
    // Default constructor
    Queue() : size(0), capacity(10), frontIndex(-1), rearIndex(-1), nextIndex(0), arr(new T[capacity]) {}
    
    // Parameterized constructor
    Queue(int size) : size(0), capacity(size), frontIndex(-1), rearIndex(-1), nextIndex(0), arr(new T[capacity]) {}
    
    ~Queue(){
        delete arr;
    }

    int getSize(){
        return size;
    }

    int max_size(){
        return capacity;
    }

    bool empty(){
        return size == 0;
    }

    T front(){
        if(frontIndex == -1) return -1;
        return arr[frontIndex];
    }

    T rear(){
        if(rearIndex == -1) return -1;
        return arr[rearIndex];
    }


    void push(T data){
        if(size == capacity){
            cout << "Queue is full !!" << endl;
            return;
        }
        arr[nextIndex] = data;
        nextIndex = (nextIndex + 1) % capacity;
        rearIndex = (rearIndex + 1) % capacity;
        if(frontIndex == -1){
            frontIndex = 0;
            rearIndex = 0;
        }
        size += 1;
    }

    void pop(){
        if(size == 0){
            cout << "Queue is empty !!" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        size -= 1;
        if(size == 0){
            nextIndex = 0;
            frontIndex = -1;
            rearIndex = -1;
        }
    }
};

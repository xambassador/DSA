#include<iostream>
using namespace std;

template<typename T>
class Stack{
    T data; // Data that is store in stack
    int maxSize; // Size of array that are use as internally for store data
    int size;
    int nextIndex; // Indicate new element is store at this index
    T* arr; // Array

    public:
    
    // Default constructor
    Stack() : size(0), maxSize(10), nextIndex(0),arr(new T[maxSize]){}

    // Parameterized constructor
    Stack(int size) : size(0), maxSize(size), nextIndex(0), arr(new T[maxSize]){}

    // Copy constructor
    Stack(Stack<T> const &s) : size(0), maxSize(s.maxSize), nextIndex(0), arr(new T[maxSize]){
        for(int i{}; i<maxSize; i++){
            arr[i] = 0;
        }
        for(int i{}; i<s.nextIndex; i++){
            arr[i] = s.arr[i];
        }
        nextIndex = s.nextIndex;
        size = s.size;
    }

    // Copy assignment operator
    void operator=(Stack<T> const &s){
        size = 0;
        nextIndex = 0;
        maxSize = s.maxSize;
        arr = new T[maxSize];
        for(int i{}; i<maxSize;i++){
            arr[i] = 0;
        }
        for(int i{}; i<s.nextIndex;i++){
            arr[i] = s.arr[i];
        }
        nextIndex = s.nextIndex;
        size = s.size;
    }

    int getSize() const{
        return size;
    }

    int max_size() const{
        return maxSize;
    }

    bool empty() const{
        return nextIndex == 0;
    }

    T top() const{
        if(nextIndex == 0) return -1;
        return arr[nextIndex-1];
    }

    void push(T data){
        if(nextIndex == maxSize){
            T* narr{new T[maxSize*2]};
            for(int i{}; i<maxSize*2; i++){
                narr[i] = 0;
            }
            for(int i{}; i<maxSize*2; i++){
                narr[i] = arr[i];
            }
            T* tmp{arr};
            arr = narr;
            delete tmp;
            maxSize *= 2;
        }
        arr[nextIndex] = data;
        nextIndex++;
        size += 1;
    }

    void pop(){
        if(nextIndex == 0) return;
        nextIndex--;
        size -= 1;
    }

    ~Stack(){
        delete arr;
    }
};

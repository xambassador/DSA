#include<iostream>
using namespace std;

template<typename T>
class Queue{
    T data;
    int size;
    int capacity;
    int frontIndex;
    int rearIndex;
    int nextIndex;
    T* arr;
    public:

    Queue() : size(0), capacity(10), frontIndex(-1), rearIndex(-1), nextIndex(0), arr(new T[capacity]) {}
    
    Queue(int size) : size(0), capacity(size), frontIndex(-1), rearIndex(-1), nextIndex(0), arr(new T[capacity]) {}

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
            T* narr{new T[capacity * 2]};
            for(int i{}; i<capacity*2; i++){
                narr[i] = 0;
            }
            for(int i{frontIndex}, j=0; i<nextIndex; i++, j++){
                if(j == 0){
                    frontIndex = 0;
                    rearIndex = 0;
                    narr[j] = arr[i];
                }else{
                    narr[j] = arr[i];
                    rearIndex = j;
                }
            }
            T* tmp{arr};
            arr = narr;
            delete tmp;
            nextIndex = rearIndex + 1;
            capacity *= 2;
        }
        if(frontIndex == -1){
            frontIndex = 0;
        }
        arr[nextIndex] = data;
        rearIndex = nextIndex;
        nextIndex += 1;
        size += 1;
    }

    void pop(){
        if(size == 0){
            cout << "Queue is empty !!! " << endl;
            return;
        }
        frontIndex += 1;
        size -= 1;
        if(frontIndex > rearIndex){
            frontIndex = -1;
            rearIndex = -1;
        }
    }
};

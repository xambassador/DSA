#include<iostream>
using namespace std;

template<typename T>
class Stack {
    T data; // Data that we want to store.
    int const size; // This indicate, till now how many elements are inserted in stacks.
    int nextIndex; // This indicate, which index the next element is inserted.
    T* arr; // Here we use array internaly to store our data.
    
    public:
    //Default constructor
    Stack() : size(10){
        arr = new T[10]; // Here we create 10 size array.
        nextIndex = 0;
    }
    
    // Parameterized constructor that create stack with specifie size
    Stack(int size) : size(size){
        arr = new T[size];
        nextIndex = 0;
    }
    
    // Copy Constructor
    Stack(Stack<T>const &s) : size(s.size){
        nextIndex = 0;
        arr = new T[s.size];
        for(int i{};i<s.nextIndex;i++){
            arr[i] = s.arr[i];
        }
        this->nextIndex = s.nextIndex;
    }

    // Parameterized constructor, create stack using initializer list
    Stack(initializer_list<T> const l) : size(l.size()*2){
        nextIndex = 0;
        arr = new T[size];
        for(auto it{l.begin()}; it != l.end(); it++){
            arr[nextIndex++] = *it;
        }
    }

    // This function return how many elements are inserted
    int getSize() const{
        return nextIndex;
    }
    
    // Return a size that indicate how much element current stack can hold
    int max_size() const{
        return size;
    }

    // This function check whether stack is empty or not
    bool empty() const{
        return size == 0;
    }
    
    // Return top element of stack
    T top() const{
        if(nextIndex == 0) return -1;
        return arr[nextIndex-1];
    }
    
    // Push new element on stack
    void push(T data){
        if(nextIndex == size){
            cout << "Sorry stack is full, you cant insert new element" << endl;
            return;
        }
        arr[nextIndex] = data;
        nextIndex++;
    }
    
    // Delete top element
    void pop(){
        if(nextIndex == 0){
            cout << "Stack is empty !!" << endl;
            return;
        }
        nextIndex--;
    }
    
    // delete every element and clear whole stack
    void clean(){
        nextIndex = 0;
    }

    ~Stack(){
        delete arr;
    }
};

#include<initializer_list>
template<typename T>
class Deque{
    T* arr; // Use array as queue container. Use circular array.
    int size; // Define how many elements are inserted
    int capacity; // Define size of array that we use as container.
    int frontIndex; // For front element.
    int rearIndex; // For rear element.
    
    public:

    // Default constructor
    Deque(){
        arr = new T[10];
        size = 0;
        capacity = 10;
        frontIndex = -1;
        rearIndex = -1;
    }

    // Parameterized constructor
    Deque(std::initializer_list<T> l){
        size = l.size();
        capacity = l.size()*2;
        frontIndex = -1;
        rearIndex = -1;
        arr = new T[capacity];
        int i{0};
        auto it{l.begin()};
        while(it != l.end()){
            arr[i++] = *it;
            it++;
        }
        frontIndex = 0;
        rearIndex = l.size() - 1;
    }

    // Copy constructor
    Deque(Deque<T> const &dq) {
        // Deep copy
        size = 0;
        capacity = dq.capacity;
        frontIndex = -1;
        rearIndex = -1;
        arr = new T[capacity];
        
        // Copy elements from dq
        for(int i{}; i<capacity; i++){
            arr[i] = dq.arr[i];
        }

        frontIndex = dq.frontIndex;
        rearIndex = dq.rearIndex;
        size = dq.size;
    }

    // Copy assignment operator
    void operator=(Deque<T> const &dq){
        size = dq.size();
        capacity = dq.capacity;
        // Deep copy
        arr = new T[capacity];
        for(int i{};i<capacity;i++){
            arr[i] = dq.arr[i];
        }
        frontIndex = dq.frontIndex;
        rearIndex = dq.rearIndex;
    }

    int getSize() const {
        return size;
    }

    int maxSize() const {
        return capacity;
    }

    bool empty() const {
        return size == 0;
    }

    T front() const {
        if(size == 0) return -1;
        return arr[frontIndex];
    }

    T rear() const {
        if(size == 0) return -1;
        return arr[rearIndex];
    }

    void push_front(T data){
        // If queue is full
        if(size == capacity){
            cout << "Queue is full" << endl;
            return;
        }

        // If queue is initially empty
        if(frontIndex == -1){
            frontIndex = 0;
            rearIndex = 0;
        }

        else if(frontIndex == 0) frontIndex = capacity - 1;

        else frontIndex -= 1;

        arr[frontIndex] = data;
        size += 1;
    }

    void push_back(T data){
        // If queue is full
        if(size == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        
        // If queue is initially empty
        if(frontIndex == -1) {
            frontIndex = 0;
            rearIndex = 0;
        }

        // If rearIndex is at last position or at last index of array then we move it circular.
        else if(rearIndex == capacity - 1) rearIndex = 0;

        else rearIndex += 1;

        arr[rearIndex] = data;
        size += 1;
    }

    void pop_front(){
        // If queue is empty
        if(size == 0){
            cout << "Queue is empty" <<  endl;
            return;
        }

        // If queue has only one element
        if(frontIndex == rearIndex){
            // We reset everything
            frontIndex = -1;
            rearIndex = -1;
        }

        else{
            // If frontIndex is at last index of array
            if(frontIndex == capacity - 1) frontIndex = 0;

            else frontIndex += 1;
        }

        size -= 1;
    }

    void pop_back(){
        // If queue is empty
        if(size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        // If there is only one element
        if(frontIndex == rearIndex) {
            // reset everything
            frontIndex = -1;
            rearIndex = -1;
        }

        // If rear is at 0th index
        else if(rearIndex == 0) rearIndex = capacity - 1;

        else rearIndex -= 1;

        size -= 1;
    }

    ~Deque(){
        delete arr;
    }
};

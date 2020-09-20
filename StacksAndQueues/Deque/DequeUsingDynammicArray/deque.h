#include<initializer_list> 
template<typename T>
class Deque{
    T* arr; // Container for store data.
    int size; // Indicate number of element inserted in queue
    int capacity; // Initial capacity before expand.
    int frontIndex; // Indicate front element.
    int rearIndex; // Indicate rear element.
    
    public:

    // Default constructor
    Deque(){
        size = 0;
        capacity = 10;
        arr = new T[capacity];
        frontIndex = -1;
        rearIndex = -1;
        for(int i{}; i<capacity; i++){
            arr[i] = 0;
        }
    }

    // Parameterized constructor
    Deque(std::initializer_list<T> l){
        size = l.size();
        capacity = l.size() * 2;
        arr = new T[capacity];
        int i{};
        for(auto it{l.begin()}; it != l.end(); it++){
            arr[i++] = *it;
        }
        frontIndex = 0;
        rearIndex = size-1;
    }

    // Copy constructor
    Deque(Deque<T> const &dq){
        // Deep copy
        size = dq.size;
        capacity = dq.capacity;
        frontIndex = dq.frontIndex;
        rearIndex = dq.rearIndex;
        arr = new T[capacity];
        for(int i{}; i<capacity; i++){
            arr[i] = dq.arr[i];
        }
    }

    // Copy assignment operator
    void operator=(Deque<T> const &dq){
        // Deep copy
        size = dq.size;
        capacity = dq.capacity;
        frontIndex = dq.frontIndex;
        rearIndex = dq.rearIndex;
        for(int i{}; i<capacity; i++){
            arr[i] = dq.arr[i];
        }
    }

    // Assign : replace content
    
    // count times insert data
    void assign(int const count, T data){
        delete arr; // Clear all old content
        capacity = count * 2;
        size = count;
        arr = new T[capacity]; // Create new array
        for(int i{}; i<count; i++){
            arr[i] = data;
        }
        frontIndex = 0;
        rearIndex = size - 1;
    }

    // from initializer list
    void assign(std::initializer_list<T> l){
        delete arr; // Clear all old content
        capacity = l.size()*2;
        size = l.size();
        arr = new T[capacity];
        int i{};
        for(auto it{l.begin()}; it != l.end(); it++){
            arr[i++] = *it;
        }
        frontIndex = 0;
        rearIndex = size - 1;
    }

    int getSize() const{
        return size;
    }

    int max_size() const{
        return capacity;
    }

    bool empty() const{
        return size == 0;
    }

    T front() const{
        if(size == 0) return -1;
        return arr[frontIndex];
    }

    T rear() const{
        if(size == 0) return -1;
        return arr[rearIndex];
    }

    void push_front(T data){
        // If array is full
        if(size == capacity) {
            // reallocation of array
            int newCapacity{capacity*2};
            T* narr {new T[newCapacity]};
            for(int i{}; i<newCapacity; i++) {
                narr[i] = 0;
            }

            // 1. If frontIndex < rearIndex
            if(frontIndex < rearIndex) {
                for(int i{frontIndex},j{}; i<=rearIndex; i++,j++){
                    narr[j] = arr[i];
                }
                frontIndex = 0;
                rearIndex = capacity - 1;
            }

            // 2. If frontIndex > rearIndex
            else if(frontIndex > rearIndex){
                int i{frontIndex}, j{};
                for(; i<capacity; i++){
                    narr[j++] = arr[i];
                }
                i = 0;
                for(; i <= rearIndex; i++){
                    narr[j++] = arr[i];
                }
                frontIndex = 0;
                rearIndex = capacity - 1;
            }
            
            // point old arr to narr
            // Before doing that, make a tmp for store old array

            T* tmp{arr};
            arr = narr;
            delete tmp;
            capacity *= 2;
        }


        // If queue is initialy empty
        if(frontIndex == -1) {
            frontIndex = 0;
            rearIndex = 0;
        }

        else if(frontIndex == 0) frontIndex = capacity - 1;

        else frontIndex -= 1;

        arr[frontIndex] = data;
        size += 1;
    }

    void push_back(T data){
        // If array is full
        if(size == capacity){
            //reallocation of array
            
            int newCapacity{capacity*2};
            T* narr {new T[newCapacity]};
            for(int i{}; i<newCapacity; i++) {
                narr[i] = 0;
            }

            // 1. If frontIndex < rearIndex
            if(frontIndex < rearIndex) {
                for(int i{frontIndex},j{}; i<=rearIndex; i++,j++){
                    narr[j] = arr[i];
                }
                frontIndex = 0;
                rearIndex = capacity - 1;
            }

            // 2. If frontIndex > rearIndex
            else if(frontIndex > rearIndex){
                int i{frontIndex}, j{};
                for(; i<capacity; i++){
                    narr[j++] = arr[i];
                }
                i = 0;
                for(; i <= rearIndex; i++){
                    narr[j++] = arr[i];
                }
                frontIndex = 0;
                rearIndex = capacity - 1;
            }

            // point old arr to narr
            // Before doing that, make a tmp for store old array

            T* tmp{arr};
            arr = narr;
            delete tmp;
            capacity *= 2;
        }

        // If queue is initialy empty
        if(frontIndex == -1){
            frontIndex = 0;
            rearIndex = 0;
        }

        else if(rearIndex == capacity - 1) rearIndex = 0;

        else rearIndex += 1;

        arr[rearIndex] = data;
        size += 1;
    }

    void pop_front() {
        // If array is empty
        if(size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        
        // If there is only one element
        if(frontIndex == rearIndex) {
            // reset front and rear
            frontIndex = -1;
            rearIndex = -1;
            size -= 1;
            return;
        }

        // If frontIndex is at lastIndex of array
        if(frontIndex == capacity - 1) frontIndex = 0;

        else frontIndex += 1;

        size -= 1;
    }

    void pop_back(){
        // If array is empty
        if(size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        // If there is only one element
        if(frontIndex == rearIndex) {
            // reset front and rear
            frontIndex = -1;
            rearIndex = -1;
            size -= 1;
            return;
        }
        
        // If rearIndex is at 0
        if(rearIndex == 0) rearIndex = capacity - 1;

        else rearIndex -= 1;

        size -= 1;
    }

    ~Deque(){
        delete arr;
    }
};

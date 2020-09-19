template<typename T>
class Queue{
    T data; // Data that store in queue
    int size; // Number of element that are inserted in queue
    int capacity; // maximum element that queue can hold
    int frontIndex; // front
    int rearIndex; // rear
    int nextIndex; // where new element is inserted
    T* arr; // array as container
    public:

    // Default constructor
    Queue() : size(0), capacity(10), frontIndex(-1), rearIndex(-1), nextIndex(0), arr(new T[capacity]) {}
    
    // Parameterized constructor
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
        // Size reach to capacity means array is now full, so we need to create new array first,
        // then remove all garbage values from it and then copy and paste from old array to new array
        if(size == capacity){
            T* narr{new T[capacity * 2]}; // create new array
            for(int i{}; i<capacity*2; i++){ // remove garbage values
                narr[i] = 0;
            }
            for(int i{frontIndex}, j=0; i<nextIndex; i++, j++){ // copy
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

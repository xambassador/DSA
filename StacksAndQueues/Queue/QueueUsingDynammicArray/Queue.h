// -----------------------------------------------------------------------------
template<typename T>
class Queue {
    // ---------
    T data; // Data that store in queue
    int size; // Number of element that are inserted in queue
    int capacity; // maximum element that queue can hold
    int frontIndex; // front
    int rearIndex; // rear
    T* arr; // array as container

    public:

    // ---------
    // Default constructor
    Queue() : size(0), capacity(10), frontIndex(-1), rearIndex(-1), arr(new T[capacity]) {}

    // ---------
    // Parameterized constructor
    Queue(int size) : size(0), capacity(size), frontIndex(-1), rearIndex(-1), arr(new T[capacity]) {}

    // ---------
    int getSize() {
        return size;
    }

    // ---------
    int max_size() {
        return capacity;
    }

    // ---------
    bool empty() {
        return size == 0;
    }

    // ---------
    T front() {
        if (frontIndex == -1) return -1;
        return arr[frontIndex];
    }

    // ---------
    T rear() {
        if (rearIndex == -1) return -1;
        return arr[rearIndex];
    }

    // ---------
    void push(T data) {
        // Queue is full
        if (size == capacity) {
            // reallocating
            T* narr{new T[capacity * 2]};
            for (int i{}; i < capacity * 2; i++) narr[i] = 0;
            int j{};
            // If frontIndex < rearIndex
            if (frontIndex < rearIndex) {
                for (int i{frontIndex}; i <= rearIndex; i++) narr[j++] = arr[i];
                frontIndex = 0;
                rearIndex = capacity - 1;
            }

            // if frontIndex > rearIndex
            else if (frontIndex > rearIndex) {
                int j{};
                for (int i{frontIndex}; i < capacity; i++) narr[j++] = arr[i];
                for (int i{}; i <= rearIndex; i++) narr[j++] = arr[i];
                frontIndex = 0;
                rearIndex = capacity - 1;
            }
            T* tmp{arr};
            arr = narr;
            delete tmp;
            capacity *= 2;
        }

        // If queue is initially empty
        if (frontIndex == -1) {
            frontIndex = 0;
            rearIndex = 0;
        }

        else if (rearIndex == capacity - 1) rearIndex = 0;
        else rearIndex += 1;

        arr[rearIndex] = data;
        size += 1;
    }

    // ---------
    void pop() {
        if (size == 0) {
            cout << "Queue is empty !!! " << endl;
            return;
        }

        arr[frontIndex] = -1;

        // If queue has only one element
        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
            size -= 1;
        }

        else if (frontIndex == capacity - 1) frontIndex = 0;
        else frontIndex += 1;

        size -= 1;
    }

    // ---------
    ~Queue() {
        delete arr;
    }
};

// -----------------------------------------------------------------------------
template<typename T>
class Queue {
    // ---------
    int size; // How many elements are inserted in queue

    // ---------
    template<typename V>
        class Node {
            public:
            V data;
            Node<V>* next;
            Node(V data) : data(data), next(NULL) {}
        };

    // ---------
    Node<T>* _front; // Actual head of linked list
    Node<T>* _rear; // tail of linked list

    public:

    // ---------
    // Default constructor
    Queue() : size(0), _front(NULL), _rear(NULL) {}

    // ---------
    // Copy constructor
    Queue(Queue<T> const &q) {
        size = q.size;
        _front = NULL;
        _rear = NULL;
        Node<T>* tmp{q._front};
        while (tmp != NULL) {
            Node<T>* node{new Node<T>(tmp->data)};
            if (_front == NULL) {
                _front = node;
                _rear = node;
            } else {
                _rear->next = node;
                _rear = node;
            }
            tmp = tmp->next;
        }
    }

    // ---------
    // Copy assignment operator
    void operator=(Queue<T> const &q) {
        // Deep copy
        // Clean old content
        while (_front != NULL) {
            Node<T>* tmp{_front};
            _front = _front->next;
            delete tmp;
        }

        // Reset both pointers
        _front = NULL;
        _rear = NULL;

        Node<T>* tmp{q._front};
        while (tmp != NULL) {
            Node<T>* node{new Node<T>(tmp->data)};
            if (_front == NULL) {
                _front = node;
                _rear = node;
            } else {
                _rear->next = node;
                _rear = node;
            }
            tmp = tmp->next;
        }

        this->size = q.size;
    }

    // ---------
    int getSize() const {
        return size;
    }

    // ---------
    bool empty() const {
        return size == 0;
    }

    // ---------
    T front() const {
        if (_front == NULL) return -1;
        return _front->data;
    }

    // ---------
    T rear() const {
        if (_rear == NULL) return -1;
        return _rear->data;
    }

    // ---------
    void push(T data) {
        // Data inserted from rear end.
        Node<T>* node{new Node<T>(data)};
        if (_front == NULL) {
            _front = node;
            _rear = node;
        } else {
            _rear->next = node;
            _rear = node;
        }
        size += 1;
    }

    // ---------
    void pop() {
        // Data deleted from front end.
        if (_front == NULL) {
            cout << "Queue is empty !!!" << endl;
            return;
        }
        if (_front == _rear) {
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

    // ---------
    ~Queue() {
        while (_front != NULL) {
            Node<T>* tmp{_front};
            _front = _front->next;
            tmp->next = NULL;
            delete tmp;
        }
    }
};

#include<initializer_list>

template<typename T>
class Deque{
    // Singly linked list node
    template<typename V>
        class Node{
            public:
            V data;
            Node<V>* next;
            // Default constructor
            Node(V data) : data(data), next(NULL) {}
        };
    
    int size;
    Node<T>* _front;
    Node<T>* _rear;

    public:
    
    // Default constructor
    Deque(){
        size = 0;
        _front = NULL;
        _rear = NULL;
    }
    
    // Parameterized constructor
    Deque(std::initializer_list<T> l){
        size = l.size();
        _front = NULL;
        _rear = NULL;
        auto it{l.begin()};
        while(it != l.end()){
            Node<T>* node{new Node<T>(*it)};
            if(_front == NULL){
                _front = node;
                _rear = node;
            }else{
                _rear->next = node;
                _rear = node;
            }
            it++;
        }
    }

    // Copy constructor

    Deque(Deque<T> const &dq){
        size = dq.size;
        _front = NULL;
        _rear  = NULL;
        Node<T>* tmp{dq._front};
        while(tmp != NULL){
            Node<T>* node{new Node<T>(tmp->data)};
            if(_front == NULL){
                _front = _rear = node;
            }else{
                _rear->next = node;
                _rear = node;
            }
            tmp = tmp->next;
        }
    }
    
    // Copy assignment operator

    void operator=(Deque<T> const &dq){
        // Clean old content
        while(_front != NULL){
            Node<T>* tmp{_front};
            _front = _front -> next;
            delete tmp;
        }

        // Reset both pointer
        _front = NULL;
        _rear = NULL;

        Node<T>* tmp{dq._front};
        while(tmp != NULL){
            Node<T>* node{new Node<T>(tmp->data)};
            if(_front == NULL){
                _front = _rear = node;
            }else{
                _rear->next = node;
                _rear = node;
            }
            tmp = tmp->next;
        }

        size = dq.size;
    }

    // Assign : replace everything
    void assign(int count, T data){
        // Clean old content
        while(_front != NULL){
            Node<T>* tmp{_front};
            _front = _front -> next;
            delete tmp;
        }

        // Reset both pointer
        _front = NULL;
        _rear = NULL;

        int i{};
        while(i < count){
            Node<T>* node{new Node<T>(data)};
            if(_front == NULL){
                _front = _rear = node;
            }else{
                _rear->next = node;
                _rear = node;
            }
            i++;
        }
        size = count;
    }

    void assign(std::initializer_list<T> l){
        // Clean old content
        while(_front != NULL){
            Node<T>* tmp{_front};
            _front = _front -> next;
            delete tmp;
        }

        // Reset both pointer
        _front = NULL;
        _rear = NULL;

        auto it{l.begin()};
        while(it != l.end()){
            Node<T>* node{new Node<T>(*it)};
            if(_front == NULL){
                _front = _rear = node;
            }else{
                _rear->next = node;
                _rear = node;
            }
            it++;
        }

        size = l.size();
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    T front() const {
        if(_front == NULL) return -1;
        return _front->data;
    }

    T rear() const {
        if(_rear == NULL) return -1;
        return _rear->data;
    }

    void push_front(T data){
        Node<T>* node{new Node<T>(data)};

        // If queue is initially empty
        if(_front == NULL){
            _front = _rear = node;
        }

        else{
            node->next = _front;
            _front = node;
        }

        size += 1;
    }

    void push_back(T data){
        Node<T>* node{new Node<T>(data)};
        
        // If queue is initially empty
        if(_front == NULL) _front = _rear = node;

        else{
            _rear->next = node;
            _rear = node;
        }

        size += 1;
    }

    void pop_front(){
        // If queue is empty
        
        if(_front == NULL) return;

        // If there is only one element
        if(_front == _rear) {
            delete _front;
            _front = NULL;
            _rear = NULL;
            size -= 1;
        }

        else{
            Node<T>* tmp{_front};
            _front = _front->next;
            tmp->next = NULL;
            delete tmp;
            size -= 1;
        }
    }

    // This function take O(n) time becuase here it need to traverse for figure out last node. Because here we use singly linked list.
    void pop_back(){
        // If queue is empty

        if(_front == NULL) return;

        // If there is only one element
        if(_front == _rear) {
            delete _front;
            _front = NULL;
            _rear = NULL;
            size -= 1;
        }

        else{
            Node<T>* tmp{_front};
            while(tmp->next != NULL){
                if(tmp->next->next == NULL){
                    // That means we reach second last node
                    _rear = tmp;
                }
                tmp = tmp->next;
            }
            delete tmp;
            _rear->next = NULL;
            size -= 1;
        }
    }

    void clean(){
        while(_front != NULL){
            Node<T>* tmp{_front};
            _front = _front->next;
            tmp->next = NULL;
            delete tmp;
        }
        _front = NULL;
        _rear = NULL;
    }

    ~Deque(){
        while(_front != NULL){
            Node<T>* tmp{_front};
            _front = _front->next;
            delete tmp;
        }
    }
};

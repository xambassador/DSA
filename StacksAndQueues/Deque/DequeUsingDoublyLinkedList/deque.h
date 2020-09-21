#include<initializer_list>

template<typename T>
class Deque{
    /* Doubly linked list node class */
    /****************************************************/
    template<typename V>
        class Node{
            public:
            V data;
            Node<V>* next;
            Node<V>* prev;

            Node(V data){
                this->data = data;
                next = NULL;
                prev = NULL;
            }
        };
    /*****************************************************/

    
    /* Data members */
    /*****************************************************/
    int size; // For number of elements inserted
    Node<T>* frontNode; // Front of deque
    Node<T>* rearNode; // rear of deque
    /*****************************************************/

    public:
    
    /* Constructors or Member functions */
    /*****************************************************/
    

    // Default constructor
    Deque(){
        size = 0;
        frontNode = NULL;
        rearNode = NULL;
    }

    // Destructor
    ~Deque(){
        while(frontNode != NULL){
            Node<T>* tmp{frontNode};
            frontNode = frontNode->next;
            tmp->next = tmp->prev = NULL;
            delete tmp;
        }
    }

    // Parameterize constructor
    Deque(std::initializer_list<T> l){
        size = l.size();
        frontNode = NULL;
        rearNode = NULL;
        auto it{l.begin()};
        while(it != l.end()){
            Node<T>* node{new Node<T>(*it)};

            // Initially list is empty
            if(frontNode == NULL) frontNode = rearNode = node;

            else {
                rearNode->next = node;
                node->prev = rearNode;
                rearNode = node;
            }

            it++;
        }
    }

    // Copy constructor
    Deque(Deque<T> const &dq){
        frontNode = NULL;
        rearNode = NULL;
        size = dq.size;

        Node<T>* tmp{dq.frontNode};
        while(tmp != NULL){
            Node<T>* node{new Node<T>(tmp->data)};

            if(frontNode == NULL) frontNode = rearNode = node;

            else{
                rearNode->next = node;
                node->prev = rearNode;
                rearNode = node;
            }

            tmp = tmp->next;
        }
    }

    // Copy assignment operator
    void operator=(Deque<T> const &dq){
        // Clearing old content
        while(frontNode != NULL){
            Node<T>* tmp{frontNode};
            frontNode = frontNode->next;
            tmp->next = NULL;
            tmp->prev = NULL;
            delete tmp;
        }

        // Reset both pointers
        frontNode = rearNode = NULL;

        Node<T>* tmp{dq.frontNode};
        while(tmp != NULL){
            Node<T>* node{new Node<T>(tmp->data)};

            if(frontNode == NULL) frontNode = rearNode = node;

            else{
                rearNode->next = node;
                node->prev = node;
                rearNode = node;
            }

            tmp = tmp->next;
        }

        size = dq.size;
    }

    // assign

    void assign(int count, T data){
        // Clearing old content
        while(frontNode != NULL){
            Node<T>* tmp{frontNode};
            frontNode = frontNode->next;
            tmp->next = tmp->prev = NULL;
            delete tmp;
        }

        // Reset
        frontNode = NULL;
        rearNode = NULL;
        
        for(int i{}; i<count; i++){
            Node<T>* node{new Node<T>(data)};

            if(frontNode == NULL) frontNode = rearNode = node;

            else{
                rearNode->next = node;
                node->prev = rearNode;
                rearNode = node;
            }
        }

        size = count;
    }


    void assign(std::initializer_list<T> l){
        // Clear old content
        while(frontNode != NULL){
            Node<T>* tmp{frontNode};
            frontNode = frontNode->next;
            tmp->next = tmp->prev = NULL;
            delete tmp;
        }

        // Reset
        frontNode = rearNode = NULL;
        
        for(auto it{l.begin()}; it != l.end(); it++){
            Node<T>* node{new Node<T>(*it)};

            if(frontNode == NULL) frontNode = rearNode = node;

            else{
                rearNode->next = node;
                node->prev = rearNode;
                rearNode = node;
            }
        }

        size = l.size();
    }

    /*****************************************************/

    // Size
    /*****************************************************/

    int getSize() const {
        return size;
    }


    bool empty() const {
        return size == 0;
    }

    /*****************************************************/


    // Access
    /*****************************************************/
    
    T front(){
        if(frontNode == NULL) return -1;
        return frontNode->data;
    }


    T rear(){
        if(frontNode == NULL) return -1;
        return rearNode->data;
    }


    /*****************************************************/


    // Modifiers
    /*****************************************************/
    
    void push_front(T data){
        // Create node
        Node<T>* node{new Node<T>(data)};

        // If list is empty
        if(frontNode == NULL) frontNode = rearNode = node;

        else{
            node->next = frontNode;
            frontNode->prev = node;
            frontNode = node;
        }

        size += 1;
    }


    void push_back(T data){
        // Create node
        Node<T>* node{new Node<T>(data)};

        // If list is empty

        if(frontNode == NULL) frontNode = rearNode = node;

        else{
            rearNode->next = node;
            node->prev = rearNode;
            rearNode = node;
        }

        size += 1;
    }


    void pop_front(){
        // If list is empty
        if(frontNode == NULL){
            cout << "Queue is empty !!!" << endl;
            return;
        }
        

        // If there is only one element
        if(frontNode == rearNode) {
            delete frontNode;
            frontNode = NULL;
            rearNode = NULL;
            return;
        }


        Node<T>* tmp{frontNode};
        frontNode = frontNode->next;
        tmp->next = NULL;
        tmp->prev = NULL;
        delete tmp;
        size -= 1;
    }


    void pop_back(){
        // If list is empty
        if(frontNode == NULL){
            cout << "Queue is empty !!!" << endl;
            return;
        }

        // If there is only one element
        if(frontNode == rearNode) {
            delete frontNode;
            frontNode = NULL;
            rearNode = NULL;
            return;
        }

        Node<T>* tmp{rearNode};
        rearNode = rearNode->prev; // move rear pointer to right to left direction
        tmp->next = NULL;
        tmp->prev = NULL;
        delete tmp;
        size -= 1;
    }

    void clean(){
        while(frontNode != NULL){
            Node<T>* tmp{frontNode};
            frontNode = frontNode->next;
            tmp->next = NULL;
            tmp->prev = NULL;
            delete tmp;
        }
        frontNode = NULL;
        rearNode = NULL;
    }

    /*****************************************************/
};

// -----------------------------------------------------------------------------
template<typename T>
class Stack {
    // ---------
    template<typename V>
        class Node {
            public:
            V data;
            Node<V>* next;
            Node(V data) : data(data), next(NULL) {}
        };

    // ---------
    Node<T>* head;
    int size;

    public:

    // ---------
    // Default constructor
    Stack() : size(0), head(NULL) {}

    // ---------
    // Copy constructor
    Stack(Stack<T> const &s) : size(s.size), head(NULL) {
        Node<T>* tmp{s.head}, tail{head};
        while (tmp != NULL) {
            Node<T>* node{new Node<T>(tmp->data)};
            if (head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            tmp = tmp->next;
        }
    }

    // ---------
    // Copy assignment operator
    void operator=(Stack<T> const &s) {
        size = s.size;
        head = NULL;
        Node<T>* tmp{s.head}, tail{head};
        while (tmp != NULL) {
            Node<T>* node{new Node<T>(tmp->data)};
            if (head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            tmp = tmp->next;
        }
    }

    // ---------
    int getSize() const {
        return size;
    }

    // ---------
    bool empty() const {
        return head == NULL;
    }

    // ---------
    T top() const {
        if (head == NULL) return -1;
        return head->data;
    }

    // ---------
    void push(T data) {
        Node<T>* node{new Node<T>(data)};
        node->next = head;
        head = node;
        size += 1;
    }

    // ---------
    void pop() {
        if (head == NULL) return;
        Node<T>* tmp{head};
        head = head->next;
        delete tmp;
        size -= 1;
    }

    // ---------
    void clean() {
        while (head != NULL) {
            Node<T>* tmp{head};
            head = head->next;
            delete tmp;
            size -= 1;
        }
    }

    // ---------
    ~Stack() {
        while (head != NULL) {
            Node<T>* tmp{head};
            head = head->next;
            tmp->next = NULL;
            delete tmp;
        }
    }
};

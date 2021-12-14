#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

class List {
    class Node {
        public:
        int data;
        Node* next;
        Node* prev;
        Node() {
            this->next = NULL;
            this->prev = NULL;
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    int SIZE;
    Node* head;
    Node* tail;

    public:

    //Default constructor
    List() {
        this->SIZE = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    //Parameterized constructor
    List(initializer_list<int> l) {
        this->head = NULL;
        this->tail = NULL;
        this->SIZE = 0;
        for(auto it{l.begin()}; it != l.end(); it++) {
            Node* node{new Node(*it)};
            if(this->head == NULL) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
        }
        this->SIZE = l.size();
    }

    // Parameterized constructor, take input from array
    List(int size, int* arr) {
        this->head = NULL;
        this->tail = NULL;
        this->SIZE = 0;
        for(int i{}; i < size; i++) {
            Node* node {new Node(arr[i])};
            if(this->head == NULL) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
        }
        this->SIZE = size;
    }

    //Copy constructor
    List(List& l) {
        this->SIZE = 0;
        this->head = NULL;
        this->tail = NULL;
        Node* tmp{l.head};
        int i{};
        while(i < l.SIZE) {
            Node* node{new Node(tmp->data)};
            if(this->head == NULL) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
            i++;
        }
        this->SIZE = l.SIZE;
    }

    void print() {
        if(this->head == NULL) return;
        Node* tmp {this->head};
        while(tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    int size() {
        if(this->head == NULL) return 0;
        return this->SIZE;
    }

    bool empty() {
        return this->head == NULL ? true : false;
    }

    void assign(initializer_list<int> l) {
        auto it{l.begin()};
        while(it != l.end()) {
            Node* node{new Node(*it)};
            if(this->head == NULL) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
            it++;
        }
        this->SIZE += l.size();
    }

    void assign(int size, int value) {
        int i{};
        while(i < size) {
            Node* node{new Node(value)};
            if(this->head == NULL) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
            i++;
        }
        this->SIZE += size;
    }

    int front() {
        if(this->head == NULL) return -1;
        return this->head->data;
    }

    int back() {
        if(this->head == NULL) return -1;
        return this->tail->data;
    }

    void push_back(int data) {
        Node* node{new Node(data)};
        if(this->head == NULL) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
        this->SIZE += 1;
    }

    void push_front(int data) {
        Node* node{new Node(data)};
        if(this->head == NULL) {
            this->head = node;
            this->tail = node;
        } else {
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
        }
        this->SIZE += 1;
    }

    void pop_back() {
        if(this->head == NULL) return;
        Node* tmp{this->tail};
        this->tail = this->tail->prev;
        this->tail->next = NULL;
        delete tmp;
        this->SIZE -= 1;
    }

    void pop_front() {
        if(this->head == NULL) return;
        Node* tmp{this->head};
        this->head = this->head->next;
        this->head->prev = NULL;
        delete tmp;
        this->SIZE -= 1;
    }

    void insert(int data) {
        Node* node{new Node(data)};
        if(this->head == NULL) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
        this->SIZE += 1;
    }

    void insert(int position, int data) {
        Node* node{new Node(data)};
        int i{};
        Node* tmp{this->head};
        while(i < position - 1 && tmp != NULL) {
            tmp = tmp->next;
            i++;
        }
        if(tmp == NULL) return;
        Node* prev{tmp->prev};
        prev->next = NULL;
        tmp->prev = NULL;
        prev->next = node;
        node->prev = prev;
        node->next = tmp;
        tmp->prev = node;
        this->SIZE += 1;
    }

    void remove(int position) {
        if(this->head == NULL) return;
        Node* tmp{this->head};
        int i{};
        while(tmp != NULL && i < position - 1) {
            tmp = tmp->next;
            i++;
        }
        if(tmp == NULL) return;
        // If tmp reach to last node
        if(tmp->next == NULL) {
            Node* prev{tmp->prev};
            prev->next = NULL;
            tmp->prev = NULL;
            this->tail = prev;
            delete tmp;
        } else {
            Node* prev{tmp->prev};
            Node* next{tmp->next};
            prev->next = next;
            next->prev = prev;
            tmp->next = NULL;
            tmp->prev = NULL;
            delete tmp;
        }
        this->SIZE -= 1;
    }

    void removeElement(int data) {
        if(this->head == NULL) return;
        Node* tmp{this->head};
        while(tmp != NULL && tmp->data != data) tmp = tmp->next;
        if(tmp == NULL) return;
        // If tmp reach to last node
        if(tmp->next == NULL) {
            Node* prev{tmp->prev};
            prev->next = NULL;
            tmp->prev = NULL;
            this->tail = prev;
            delete tmp;
        } else {
            Node* prev{tmp->prev};
            Node* next{tmp->next};
            prev->next = next;
            next->prev = prev;
            tmp->prev = NULL;
            tmp->next = NULL;
            delete tmp;
        }
        this->SIZE -= 1;
    }

    private:
    Node* reverse(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        Node* ans{reverse(head->next)};
        Node* tail{head->next};
        tail->next = head;
        head->prev = tail;
        head->next = NULL;
        return ans;
    }

    public:
    void reverse() {
        this->tail = this->head;
        this->head = reverse(this->head);
    }

    void clean() {
        if(this->head == NULL) return;
        while(this->head != NULL) {
            Node* tmp{this->head};
            this->head = this->head->next;
            this->SIZE -= 1;
            delete tmp;
        }
    }

    void TakeInput() {
        cout << "Enter data or -1 for exit" << endl;
        int data;
        cin >> data;
        while(data != -1) {
            Node* node{new Node(data)};
            if(this->head == NULL) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
            this->SIZE += 1;
            cin >> data;
        }
    }
};

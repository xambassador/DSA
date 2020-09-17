#include<bits/stdc++.h>
#include <initializer_list>
using namespace std;
class List { 
    class Node {
        public:
        int data;
        Node* next;
        Node* prev;
        Node(){
            this->next = NULL;
            this->prev = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    int LENGTH;
    int SIZE;
    Node* head;
    Node* tail;

    public:
    
    //Default constructor
    List(){
        this->LENGTH = 0;
        this->SIZE = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    //Perameterized constructor
    List(std::initializer_list<int> l){
        this->head = NULL;
        this->tail = NULL;
        for(auto it{l.begin()}; it != l.end(); it++){
            Node* node{new Node(*it)};
            if(this->head == NULL){
                this->head = node;
                this->tail = node;
            }else{
                this->tail->next = node;
                node->prev = tail;
                this->tail = node;
            }
        }
        this->LENGTH = l.size();
        this->SIZE = l.size();
    }
    
    List(int size, int* arr) {
        this->head = NULL;
        this->tail = NULL;
        for(int i{}; i<size; i++){
            Node* node {new Node(arr[i])};
            if(this->head == NULL){
                this->head = node;
                this->tail = node;
            }else {
                this->tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        this->SIZE = size;
        this->LENGTH = size;
    }

    void print(){
        if(this->head == NULL) return;
        Node* tmp {this->head};
        while(tmp != this->tail) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }

    int size(){
        if(this->head == NULL) return 0;
        return this->size();
    }
};

#include<bits/stdc++.h>
using namespace std;

namespace classNode {

    template<typename V>
    class LinkedList {
        template<typename T>
        class Node {
            public:
            T data;
            Node<T>* next;
            Node(T data){
                this->data = data;
                next = NULL;
            }
        };

        Node<V>* head,*tail;
        int _size;

        public:

        // Default constructor
        LinkedList(){
            head = NULL;
            tail = NULL;
            _size = 0;
        }

        // Perameterized Constructor, create list using array
        LinkedList(int size, V* arr){
            head = NULL;
            tail = NULL;
            this->_size = 0;
            int i{};
            while(i < size){
                Node<V>* node{new Node<V>(arr[i])};
                if(head == NULL){
                    head = node;
                    tail = node;
                }else {
                    tail->next = node;
                    tail = node;
                }
                i++;
            }
            this->_size = size;
        }

        // Perameterized constructor, list from initalizer list
        LinkedList(initializer_list<V> l){
            auto it{l.begin()};
            head = NULL;
            tail = NULL;
            this->_size = 0;
            while(it != l.end()){
                Node<V>* node{new Node<V>(*it)};
                if(head == NULL){
                    head = node;
                    tail = node;
                }else{
                    tail->next = node;
                    tail = node;
                }
                it++;
            }
            this->_size += l.size();
        }

        //Copy constructor
        LinkedList(LinkedList<V>& l2){
            //Deep copy
            this->_size = 0;
            this->_size = l2._size;
            this->head = NULL;
            this->tail = NULL;
            Node<V>* tmp{l2.head};
            while(tmp!=NULL){
                Node<V>* node{new Node<V>(tmp->data)};
                if(this->head == NULL){
                    this->head = node;
                    this->tail = node;
                }else{
                    this->tail->next = node;
                    tail = node;
                }
                tmp = tmp->next;
            }
        }
        
        // Copy assignment operator
        LinkedList<V>* operator=(LinkedList<V>& l2){
            //Deep copy
            this->_size = 0;
            //1.If left side list is empty
            if(this->head == NULL){
                Node<V>* tmp{l2.head};
                while(tmp!=NULL){
                    Node<V>* node{new Node<V>(tmp->data)};
                    if(this->head == NULL){
                        this->head = node;
                        this->tail = node;
                    }else{
                        this->tail->next = node;
                        this->tail = node;
                    }
                    tmp = tmp->next;
                }
                this->_size = l2._size;
            }

            //2. If left side list is not empty
            else {
                //1.If both list len is equal
                if(this->len == l2.len){
                    Node<V>* tmp{l2.head};
                    Node<V>* ltmp{this->head};
                    while(tmp!=NULL){
                        ltmp->data = tmp->data;
                        tmp = tmp->next;
                        ltmp = ltmp->next;
                    }
                }

                //2.If left list is smaller then right then we need to add extra nodes
                else if(this->len < l2.len){
                    Node<V>* tmp{l2.head};
                    Node<V>* ltmp{this->head};
                    
                    //go till last node of left list
                    while(ltmp->next!=NULL){
                        ltmp->data = tmp->data;
                        ltmp = ltmp->next;
                        tmp = tmp->next;
                    }
                    //update last node of left list
                    ltmp->data = tmp->data;
                    tmp = tmp->next;

                    //Now traverse rest of right list and insert new node to left list
                    while(tmp!=NULL){
                        Node<V>* node{new Node<V>(tmp->data)};
                        this->tail->next = node;
                        this->tail = node;
                        tmp = tmp->next;
                    }

                    this->_size = l2._size;
                }

                //3.If left list is bigger then right
                else{
                    // 1. Traverse on left list and reach to last node, and update all nodes
                    Node<V>* tmp{l2.head};
                    Node<V>* ltmp{this->head};
                    while(ltmp->next != NULL){
                        ltmp->data = tmp->data;
                        ltmp = ltmp->next;
                        tmp = tmp->next;
                    }
                    ltmp->data = tmp->data;

                    //2.Now delete extra nodes
                    Node<V>* t{ltmp->next};
                    ltmp->next = NULL;
                    while(t != NULL){
                        Node<V>* tmp{t};
                        t = t->next;
                        delete tmp;
                    }

                    this->tail = ltmp;
                    this->_size = l2._size;
                }
            }
            return this;
        }
        
        // assign function
        // assign(initializer_list)
        void assign(initializer_list<V> l) {
            auto it{l.begin()};
            while(it != l.end()){
                Node<V>* node{new Node<V>(*it)};
                if(this->head == NULL){
                    this->head = node;
                    this->tail = node;
                }else{
                    this->tail->next = node;
                    this->tail = node;
                }
                it++;
            }
            this->_size += l.size();
        }

        //assign(int size, V value)
        void assign(int size, V value) {
            int i{};
            while(i < size){
                Node<V>* node{new Node<V>(value)};
                if(this->head == NULL){
                    this->head = node;
                    this->tail = node;
                }else{
                    this->tail->next = node;
                    this->tail = node;
                }
                i++;
            }
            this->_size = size;
        }

        bool operator==(LinkedList<V>& l2){
            if(this->_size != l2._size){
                return false;
            }
            Node<V>* tmp1{this->head};
            Node<V>* tmp2{l2.head};
            while(tmp1 != NULL && tmp2 != NULL){
                if(tmp1->data != tmp2->data){
                    return false;
                }
            }
            return true;
        }

        bool operator!=(LinkedList<V>& l2){
            if(this->_size == l2._size){
                return false;
            }
            Node<V>* tmp1{this->head};
            Node<V>* tmp2{l2.head};
            while(tmp1 != NULL && tmp2 != NULL){
                if(tmp1->data == tmp2->data){
                    return false;
                }
            }
            return true;
        }

        //Take linked list input
        void takeInput(){
            int data;
            cin >> data;
            while(data != -1){
                Node<V>* node{new Node<V>(data)};
                if(head == NULL){
                    head = node;
                    tail = node;
                }else{
                    tail->next = node;
                    tail = node;
                }
                this->_size += 1;
                cin >> data;
            }
        }

        // Print List
        void print() const {
            Node<V>* tmp{this->head};
            while(tmp != NULL){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }cout << endl;
        }

        //Append new node to last position
        //or add new node to tail of list
        void push(V data){
            Node<V>* node{new Node<V>(data)};
            if(head == NULL){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = node;
            }
            this->_size += 1;
        }

        
        //Return size
        int size() const{
            return this->_size;
        }
        
        //Check if list is empty or not
        bool empty() const{
            return _size == 0;
        }

        private:
        //Remove node from last positon
        Node<V>* pop(Node<V>* tmp){
            // Base case if list is empty
            if(tmp == NULL){
                return tmp;
            }
            // Edge case to handle tail pointer position
            // when temp pointer reach to second last node then change position of tail to second last
            if(tmp->next == this->tail){
                tail = tmp;
            }
            //Now if tmp reach to last node
            if(tmp->next == NULL){
                tmp = NULL;
                delete tmp;
                return NULL;
            }
            Node<V>* ans{pop(tmp->next)};
            tmp->next = ans;
            return tmp;
        }

        public :
        void pop(){
            Node<V>* ans{pop(this->head)};
            this->head = ans;
            this->_size -= 1;
        }

        private:
        //Remove node from specific position
        Node<V>* remove(Node<V>* head, int position){
            //If list is empty
            if(head == NULL){
                return head;
            }
            // If head reach to second last node and position is 1 means node that goes to delete is last node
            // So now change position of tail pointer to second last node
            if(head->next == this->tail){
                if(position == 1){
                    tail = head;
                }
            }
            if(position == 0){
                Node<V>* tmp{head};
                head = head->next;
                delete tmp;
                return head;
            }
            head->next = remove(head->next,position-1);
            return head;
        }

        public:
        void remove(int position){
            this->head = remove(this->head,position);
            this->_size -= 1;
            return;
        }

        private:
        // Remove specific data node
        Node<V>* removeElement(Node<V>* head, V data){
            if(head == NULL){
                return head;
            }
            if(head->next == this->tail){
                if(this->tail->data == data){
                    tail = head;
                }
            }
            if(head->data == data){
                Node<V>* tmp{head};
                head = head->next;
                delete tmp;
                return head;
            }
            head->next = removeElement(head->next,data);
            return head;
        }

        public:
        void removeElement(V data){
            this->head = removeElement(this->head,data);
            this->_size -= 1;
            return;
        }

        private:
        // Insert new node at specific positions
        Node<V>* insert(Node<V>* head, V data, int positon){
            if(head == NULL){
                if(positon == 0){
                    Node<V>* node{new Node<V>(data)};
                    head = node;
                    return head;
                }
                return head;
            }
            if(head->next == tail && positon == 1){
                tail = head;
            }
            if(positon == 0){
                Node<V>* node{new Node<V>(data)};
                Node<V>* tmp{head};
                head = node;
                head->next = tmp;
                return head;
            }
            head->next = insert(head->next,data,positon-1);
            return head;
        }

        public:
        void insert(V data){
            Node<V>* node{new Node<V>(data)};
            if(this->head == NULL){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = node;
            }
            this->_size += 1;
            return;
        }

        void insert(V position, int data){
            this->head = insert(this->head,data,position);
            this->_size += 1;
            return;
        }

        private:
        // insert a new list at specific position
        Node<V>* insertList(Node<V>* head, int position, initializer_list<V> l){
            if(head == NULL){
                if(position == 0){
                    auto it{l.begin()};
                    Node<V>* tmp{head};
                    Node<V>* t{head->next};
                    while(it != l.end()){
                        Node<V>* node{new Node<V>(*it)};
                        if(tmp == NULL){
                            tmp = node;
                        }else{
                            tmp->next = node;
                            tmp = tmp->next;
                        }
                        it++;
                    }
                    tmp->next = t;
                    return head;
                }
                return head;
            }
            if(position == 0){
                auto it{l.begin()};
                Node<V>* t{head->next};
                if(head == tail){
                    while(it != l.end()){
                        Node<V>* node{new Node<V>(*it)};
                        if(this->tail == NULL){
                            this->tail = node;
                        }else{
                            this->tail->next = node;
                            this->tail = this->tail->next;
                        }
                        it++;
                    }
                    tail->next = NULL;
                }else{
                    Node<V>* tmp{head};
                    while(it != l.end()){
                        Node<V>* node{new Node<V>(*it)};
                        if(tmp == NULL){
                            tmp = node;
                        }else{
                            tmp->next = node;
                            tmp = tmp->next;
                        }
                        it++;
                    }
                    tmp->next = t;
                };
                return head;
            }
            head->next = insertList(head->next,position-1,l);
            return head;
        }


        public:
        void insertList(int position, initializer_list<V> l){
            this->head = insertList(this->head,position,l);
            this->_size += l.size();
        }

        //Return front node data
        V front() const {
            if(head == NULL){
                return -1;
            }
            return head->data;
        }

        //Return tail node data
        V back() const {
            if(tail == NULL){
                return -1;
            }
            return tail->data;
        }

        private:
        //Find whether node is present in list or not
        bool find(Node<V>* head, V data){
            if(head == NULL){
                return false;
            }
            if(head->data == data){
                return true;
            }
            return find(head->next,data);
        }

        public:
        bool find(V data){
            return find(head->next, data);  
        }

        private:
        //Append last n node to first
        Node<V>* appendNnodeToFirst(Node<V>* head, int n){
            int i{-n};
            Node<V>* tmp{head};
            Node<V>* t{head};
            while(tmp -> next != NULL){
                if(i>=0){
                    t = t-> next;
                }
                tmp = tmp->next;
                i++;
            }
            tmp->next = head;
            head = t->next;
            t->next = NULL;
            return head;
        }

        public:
        void appendNnodeToFirst(int n){
            this->head = appendNnodeToFirst(this->head,n);
            return;
        }

        //Remove consecutive duplicates
        void removeDuplicates(){
            Node<V>* tmp{head};
            while(tmp->next != NULL){
                if(tmp->data == tmp->next->data){
                    Node<V>* t{tmp->next->next};
                    delete tmp->next;
                    tmp->next = t;
                    this->_size -= 1;

                }else{
                    tmp = tmp->next;
                }
            }
            return;
        }

        private:
        //Print reverse list
        void preverse(Node<V>* head){
            if(head == NULL){
                cout << endl;
                return;
            }
            preverse(head->next);
            cout << head->data << " ";
        }

        public:
        
        //Reverse list method 1
        void preverse(){
            preverse(this->head);
            return;
        }

        private:
        // Reverse list iterativly, O(n^2)
        Node<V>* reverse_i(Node<V>* head){
            Node<V>* curr{head};
            Node<V>* prev{NULL};
            Node<V>* next{NULL};
            Node<V>* t{head};
            while (curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            tail = t;
            return head;
        }

        // Reverse list recursive, O(n^2)
        Node<V>* reverse_rec1(Node<V>* head){
            if(head == NULL || head->next == NULL){
                return head;
            }
            Node<V>* ans {reverse_rec1(head->next)};
            Node<V>* tmp{ans};
            this->tail = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            } 
            tmp->next = head;
            head->next = NULL;
            return ans;
        }

        // Reverse list recursive. O(n)
        class pair{
            public:
            Node<V>* _head;
            Node<V>* _tail;
        };

        pair reverse_rec2(Node<V>* head){
            if(head == NULL || head->next == NULL){
                pair p;
                p._head = head;
                p._tail = head;
                return p;
            }
            pair smallAns{reverse_rec2(head->next)};
            smallAns._tail->next = head;
            smallAns._tail = head;
            head->next = NULL;
            pair ans;
            ans._head = smallAns._head;
            ans._tail = smallAns._tail;
            return ans;
        }

        private:
        Node<V>* reverse_rec2H(){
            this->tail = head;
            return reverse_rec2(this->head)._head;
        }

        public:
        //Reverse list recursive, O(n)
        Node<V>* reverse_rec3(Node<V>* head){
            if(head == NULL || head->next == NULL){
                return head;
            }
            Node<V>* ans{reverse_rec3(head->next)};
            Node<V>* tail{head->next};
            tail->next = head;
            head->next = NULL;
            return ans;
        }

        public:

        //Reverse list method 2
        void reverse_i(){
            this->head = reverse_i(this->head);
            return;
        }
        
        // Reverse list method 3
        void reverse_rec1(){
            this->head = reverse_rec1(this->head);
            return;
        }

        //Reverse list method 4
        void revrerse_rec2(){
            this->head = reverse_rec2H();
            return;
        }

        // Reverse list method 5
        void reverse_rec3(){
            this->tail = this->head;
            this->head = reverse_rec3(this->head);
            return;
        }

        private:
        
        // Find mid node of list
        Node<V>* midpoint(Node<V>* head){
            if(head == NULL) return head;
            Node<V>* slow{head};
            Node<V>* fast{head};
            while(fast->next != NULL && fast->next->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }

        // Check list is palindrome or not
        bool palindrome(V* arr){
            int i{},j{this->len-1};
            while(i < j){
                if(arr[i] != arr[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }

        public:
        bool palindrome(){
            if(this->empty()){
                return true;
            }
            int i{};
            V* arr{new V[this->len]};
            Node<V>* tmp{this->head};
            for(int i{};i<this->len;i++){
                arr[i] = tmp->data;
                tmp = tmp->next;
            }
            bool ans = this->palindrome(arr);
            delete arr;
            return ans;
        }
        
        private:
        // Merge to sorted lists
        Node<V>* merge(Node<V>* head1, Node<V>* head2){
            if(head1 == NULL){
                return head2;
            }else if(head2 == NULL){
                return head1;
            }
            Node<V>* ans{NULL};
            if(head1->data <= head2->data){
                ans = head1;
                ans->next = merge(head1->next,head2);
            }else{
                ans = head2;
                ans->next = merge(head1,head2->next);
            }
            return ans;
        }

        // Arrenge node so odd node come first and even after
        Node<V>* evenAfterOdd(Node<V>* head){
            if(head == NULL || head->next == NULL){
                return head;
            }
            Node<V>* tmp{head};
            Node<V>* evenhead{NULL},*eventail{NULL};
            Node<V>* oddhead{NULL},*oddtail{NULL};
            while(tmp != NULL){
                if(tmp->data % 2 != 0){
                    if(oddhead == NULL){
                        oddhead = tmp;
                        oddtail = tmp;
                    }else{
                        oddtail->next = tmp;
                        oddtail = tmp;
                    }
                    tmp = tmp->next;
                    oddtail->next = NULL;
                }else{
                    if(evenhead == NULL){
                        evenhead = tmp;
                        eventail = tmp;
                    }else{
                        eventail->next = tmp;
                        eventail = tmp;
                    }
                    tmp = tmp->next;
                    eventail->next = NULL;
                }
            }
            this->tail = eventail;
            head = oddhead;
            oddtail->next = evenhead;
            return head;
        }

        // Merge sort on list
        Node<V>* sort(Node<V>* head){
            if(head == NULL || head->next == NULL){
                return head;
            }
            Node<V>* mid{midpoint(head)};
            Node<V>* left{head};
            Node<V>* right{mid->next};
            mid->next = NULL;
            return merge(sort(left),sort(right));
        }


        // Swap two nodes from their given position
        Node<V> *swap(Node<V> *head, int i, int j){
            Node<V> *curr1{head};
            Node<V> *curr2{head};
            Node<V> *prev1{NULL};
            Node<V> *prev2{NULL};
            int cnt = 0;
            if (i == 0 && j == 0){
                return NULL;
            }
            while (cnt < i){
                prev1 = curr1;
                curr1 = curr1->next;
                cnt++;
            }
            cnt = 0;
            while (cnt < j){
                prev2 = curr2;
                curr2 = curr2->next;
                cnt++;
            }
            if (curr1 == NULL || curr2 == NULL){
                return head;
            }
            if (prev1 != NULL){
                prev1->next = curr2;
            }
            else{
                head = curr2;
            }
            if (prev2 != NULL){
                prev2->next = curr1;
            }
            else{
                head = curr1;
            }
            Node<V> *tmp = curr2->next;
            curr2->next = curr1->next;
            curr1->next = tmp;
            return head;
        }


        // Reverse k nodes
        Node<V>* kreverse(Node<V>* head, int k){
            if(head == NULL || head->next == NULL){ 
                return head;
            }
            int i{};
            Node<V>* tmp{head};
            Node<V>* thead{NULL};
            while(i < k-1 && tmp != NULL){
                tmp = tmp->next;
            }
            thead = tmp->next;
            tmp->next = NULL;
            Node<V>* rhead{this->reverse_rec3(head)};
            head->next = kreverse(thead,k);
            return rhead;
        }


        // Skip m nodes and then delete n  nodes
        Node<V>* skipMremoveN(Node<V>* head, int m, int n){
            if(head == NULL){
                return head;
            }
            Node<V>* curr{head};
            if(m == 0 && n == 0){
                delete curr;
                this->_size -= 1;
                return NULL;
            }
            if(m == 0){
                while(curr != NULL){
                    Node<V>* t{curr};
                    for(int i{1}; i<=n && t!=NULL; i++){
                        Node<V>* tmp{t};
                        t = t->next;
                        delete tmp;
                        this->_size -= 1;
                    }
                    curr->next = t; 
                    curr = curr->next;
                }
                return curr;
            }
            while(curr != NULL){
                for(int i{1}; i<m && curr!= NULL; i++){
                    curr = curr->next;
                }
                if(curr == NULL){
                    return head;
                }
                Node<V>* t{curr->next};
                for(int i{1}; i<=n && t!=NULL; i++){
                    Node<V>* tmp{t};
                    t = t->next;
                    delete tmp;
                    this->_size -= 1;
                }
                curr->next = t;
                curr = curr->next;
            }
            return head;
        }


        public:
        void merge(LinkedList<V>& l2){
            LinkedList<V> l{l2};    
            this->head = merge(this->head,l.head);
            this->_size += l._size;
            return;
        }


        void sort(){
            this->head = sort(this->head);
            Node<V>* tmp{this->head};
            while(tmp != NULL){
                tmp = tmp->next;
            }
            this->tail = tmp;
        }


        void evenAfterOdd(){
            this->head = evenAfterOdd(this->head);
        }


        void swap(int position1, int position2){
            this->head = swap(this->head,position1,position2);
            if(position1 == (this->_size-1) || position2 == (this->_size-1)) {
                Node<V>* tmp{this->tail};
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                this->tail = tmp;
            }
        }


        void kreverse(int k){
            this->head = kreverse(this->head,k);
            Node<V>* tmp{this->tail};
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            this->tail = tmp;
        }


        void deleteEveryN(int numOfSkipNode, int numOfDelteNode){
            this->head = skipMremoveN(this->head,numOfSkipNode, numOfDelteNode);
        }


        private:
        Node<V>* BubbleSort(Node<V>* head){
            Node<V>* curr = head;
            Node<V>* prev = NULL;
            Node<V>* next = NULL;
            int l{this->_size}, i{};
            while(i < l-1){
                while(curr -> next != NULL){
                    if(curr -> data > curr -> next -> data){
                        if(prev == NULL){
                            next = curr->next;
                            curr->next = next->next;
                            next->next = curr;
                            prev = next;
                            head = prev;
                        }else{
                            next = curr->next;
                            if(curr->next == this->tail){
                                this->tail = curr;
                            }
                            prev->next = curr->next;
                            curr->next = next->next;
                            next->next = curr;
                            prev = prev->next;
                        }
                    }else{
                        prev = curr;
                        curr = curr->next;
                    }
                }
                curr = head;
                prev = NULL;
                next = NULL;
                i++;
            }
            return head;
        }

        public:
        void BubbleSort(){
            this->head = BubbleSort(this->head);
        }

    };
}

namespace structNode {
    template <typename T>
    struct Node {
        T data;
        Node<T>* next{NULL};
        Node(T data){
            this->data = data;
        }
    };
}

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
        int len,_size;

        public:

        // Default constructor
        LinkedList(){
            head = NULL;
            tail = NULL;
            len = 0;
            _size = 0;
        }

        // Perameterized Constructor, create list using array
        LinkedList(int size, V* arr){
            head = NULL;
            tail = NULL;
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
            len = size;
            this->_size = size;
        }

        // Perameterized constructor, list from initalizer list
        LinkedList(initializer_list<V> l){
            auto it{l.begin()};
            head = NULL;
            tail = NULL;
            while(it != l.end()){
                Node<V>* node{new Node<V>(*it)};
                if(head == NULL){
                    head = node;
                    tail = node;
                }else{
                    tail->next = node;
                    tail = node;
                }
                this->_size += 1;
                len += 1;
                it++;
            }
        }

        //Copy constructor
        LinkedList(LinkedList<V>& l2){
            //Deep copy
            this->_size = l2._size;
            this->len = l2.len;
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

        LinkedList<V>* operator=(LinkedList<V>& l2){
            //Deep copy
            
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
                this->len = l2.len;
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
                    this->len = l2.len;
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
                    this->len = l2.len;
                }
            }
            return this;
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
                len += 1;
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
            len += 1;
        }

        //Return length
        int length() const {
            return this->len;
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
            len -= 1;
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
            len -= 1;
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
            len -= 1;
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
            return;
        }

        void insert(V position, int data){
            this->head = insert(this->head,data,position);
            this->_size += 1;
            this->len += 1;
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
            this->len += l.size();
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
                    this->len -= 1;

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
        
        Node<V>* midpoint(Node<V>* head){
            Node<V>* slow{head};
            Node<V>* fast{head};
            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }

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

        public:
        void merge(LinkedList<V>& l2){
            LinkedList<V> l{l2};    
            this->head = merge(this->head,l.head);
            return;
        }



        void details(){
            cout << "Head node addres : " << this->head << endl;
            cout << "Tail node addres : " << this->tail << endl;
            cout << "Head node data : " << head->data << "\n" << "Tail node data : " << tail->data << endl;
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
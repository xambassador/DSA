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

        // ~LinkedList(){
        //     cout << "Destroctor is called !!" << endl;
        //     if(head != NULL){
        //         while(head != NULL){
        //             Node<V>* tmp{head};
        //             head = head->next;
        //             delete tmp;
        //         }
        //     }
        // }

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

        void print() const {
            Node<V>* tmp{this->head};
            while(tmp != NULL){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }cout << endl;
        }

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

        int length() const {
            return this->len;
        }

        int size() const{
            return this->_size;
        }

        bool empty() const{
            return _size == 0;
        }

        private:
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
        Node<V>* remove(Node<V>* head, int position){
            //If list is empty
            if(head == NULL){
                return head;
            }
            // Id head reach to second last node and position is 1 means node that goes to delete is last node
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

        V front() const {
            if(head == NULL){
                return -1;
            }
            return head->data;
        }

        V back() const {
            if(tail == NULL){
                return -1;
            }
            return tail->data;
        }

        private:
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

        Node<V>* reverse_rec2H(){
            this->tail = head;
            return reverse_rec2(this->head)._head;
        }

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

        

        void details(){
            cout << "Head node addres : " << this->head << endl;
            cout << "Tail node addres : " << this->tail << endl;
            cout << "Head node data : " << head->data << "\n" << "Tail node address : " << tail->data << endl;
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
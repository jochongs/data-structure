#include <iostream>
using namespace std;

template <typename T> class LinkedList;
template <typename T> class Iterator;

template <typename T> class Node {
    public:
        T data;
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    private:
        Node<T>* next;

    friend class LinkedList<T>;
    friend class Iterator<T>;
};

template <typename T> class Iterator {
    public: 
        Iterator(Node<T>* node) {
            this->curr_node = node;
        }
        Iterator() {
            this->curr_node = nullptr;
        }

        bool has_next() {
            if (this->curr_node->next == nullptr) {
                return false;
            }

            return true;
        }

        T get() {
            return this->curr_node->data;
        }

        Iterator<T> move_next() {
            if (this->has_next()) {
                this->curr_node =this->curr_node->next;
            }

            return nullptr;
        }

        // 전위 증가 연산자 오버로딩
        Iterator<T>& operator++() {
            if (this->curr_node != nullptr) {
                curr_node = curr_node->next;
            }
            return *this;
        }

        // 후위 증가 연산자 오버로딩
        Iterator<T> operator++(int) {
            Iterator<T> temp = *this; // 현재 객체의 복사본 생성
            if (this->has_next()) {
                this->move_next();
            }
            return temp;        
        }

        bool operator==(Iterator<T> it) {
            return (it.curr_node == this->curr_node);
        }
        
        bool operator!=(Iterator<T> it) {
            return (it.curr_node != this->curr_node);
        }
    private:
        Node<T>* curr_node;
};

template <typename T> class LinkedList {
    public: ;
        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }
        ~LinkedList() {
            Node<T>* curr_node = this->head;
            while (curr_node != nullptr) {
                Node<T>* next_node = curr_node->next;
                delete curr_node;
                curr_node = next_node;
            }
        }

        typedef Iterator<T> iterator;
        
        /**
         * 가장 뒤에 값 넣기
        */
        void push_back(T data) {
            Node<T>* new_node = new Node<T>(data);

            this->length++;
            if (this->head == nullptr) {
                this->head = new_node;
                this->tail = new_node;
                return;
            }

            this->tail->next = new_node;
            this->tail = new_node;
        }

        /**
         * 가장 뒤 값 지우기
        */
        void remove_back() {
            
        }

        /**
         * 가장 앞에 값 넣기
        */
        void push_front(T data) {
            Node<T>* new_node = new Node<T>(data);

            this->length++;
            if (this->head == nullptr) {
                this->head = new_node;
                this->tail = new_node;
                return;
            }

            new_node->next = this->head;
            this->head = new_node;
        }

        /**
         * 가장 앞 값 가져오기
        */
        T front() {
            if (this->head == nullptr) {
                throw runtime_error("Access to null point exception");
            }
            return this->head->data;
        }

        /**
         * 사이즈 가져오기
        */
        int size() {
            return this->length;
        }

        /**
         * 값 추가하기
        */
        void insert_after(Node<T>* node, T data) {
            Node<T>* new_node = new Node<T>(data);

            this->length++;
            if (node->next == nullptr) {
                node->next = new_node;
                this->tail = new_node;
                return;
            }

            new_node->next = node->next;
            node->next = new_node;
        }
        
        /**
         * 값 탐색하기
        */
        Node<T>* find_data(T data) {
            Node<T>* curr_node = this->head;
            while (curr_node != nullptr) {
                if (curr_node->data == data) {
                    return curr_node;
                }

                curr_node = curr_node->next;
            }

            return nullptr;
        }

        /**
         * 시작 값 가져오기
        */
        iterator begin() {
            return iterator(this->head);
        }
       
        /**
         * 끝 값 가져오기
        */
        iterator end() {
            return iterator(this->tail);
        }

        /**
         * 전부 출력하기
        */
        void displayAll() {
            Node<T>* node = this->head;
            for(int i = 0; i < this->length; i++) {
                cout << node->data << ' ';

                if (node->next != nullptr) {
                    node = node->next;
                }
            }
            cout << '\n';
            return;
        }

        Node<T>* getTail() {
            return this->tail;
        }
    private: 
        Node<T>* head;
        Node<T>* tail;
        int length;
};

int main() {
    LinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.displayAll();

    LinkedList<int>::iterator it = list.begin();

    while (!it.has_next()) {
        cout << it.get() << ' ';
        it++;
    }
    cout << '\n';
}
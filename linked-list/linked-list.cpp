#include <iostream>
using namespace std;

// 노드
template <typename T> class Node {
    public:
        T data;
    Node(T data) {
        this->data = data;
        this->nextNode = nullptr;
    }

    Node<T>* next() const {
        return this->nextNode;
    }

    void setNextNode(Node<T>* newNode) {
        this->nextNode = newNode;
    }

    T getData() {
        return this->data;
    }

    private:
        Node<T>* nextNode;
};

template <typename T> class Iterator {
    public: 
        Iterator(Node<T>* node) {
            this->currNode = node;
        }
        Iterator() {
            this->currNode = nullptr;
        }

        bool has_next() {
            if (this->currNode->next() == nullptr) {
                return false;
            }

            return true;
        }

        T get() {
            return this->currNode->getData();
        }

        Iterator<T> next() {
            if (this->has_next()) {
                this->currNode =this->currNode->next();
            }

            return nullptr;
        }

        // 전위 증가 연산자 오버로딩
        Iterator<T>& operator++() {
            if (this->currNode != nullptr) {
                currNode = currNode->next();
            }
            return *this;
        }

        // 후위 증가 연산자 오버로딩
        Iterator<T> operator++(int) {
            Iterator<T> temp = *this; // 현재 객체의 복사본 생성
            if (this->has_next()) {
                this->next();
            }
            return temp;        
        }

        bool operator==(Iterator<T> it) {
            return (it.currNode == this->currNode);
        }
        
        bool operator!=(Iterator<T> it) {
            return (it.currNode != this->currNode);
        }
    private:
        Node<T>* currNode;
};

// 단방향 링크드 리스트
template <typename T> class LinkedList {
    public: ;
        LinkedList() {
            this->header = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }
        ~LinkedList() {
            Node<T>* currNode = this->header;
            while (currNode != nullptr) {
                Node<T>* nextNode = currNode->next();
                delete currNode;
                currNode = nextNode;
            }
        }

        typedef Iterator<T> iterator;
        
        /**
         * 가장 뒤에 값 넣기
        */
        void push_back(T data) {
            Node<T>* newNode = new Node<T>(data);

            this->length++;
            if (this->header == nullptr) {
                this->header = newNode;
                this->tail = newNode;
                return;
            }

            if (this->header == this->tail) {
                this->header->setNextNode(newNode);
                this->tail = newNode;
                return;
            }

            this->tail->setNextNode(newNode);
            this->tail = newNode;
        }

        /**
         * 가장 앞에 값 넣기
        */
        void push_front(T data) {
            Node<T>* newNode = new Node<T>(data);

            this->length++;
            if (this->header == nullptr) {
                this->header = newNode;
                this->tail = newNode;
                return;
            }

            if (this->header == this->tail) {
                newNode->setNextNode(tail);
                this->header = newNode;
                return;
            }

            newNode->setNextNode(this->header);
            this->header = newNode;
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
            Node<T>* newNode = new Node<T>(data);

            this->length++;
            if (node->next() == nullptr) {
                node->setNextNode(newNode);
                this->tail = newNode;
                return;
            }

            newNode->setNextNode(node->next());
            node->setNextNode(newNode);
        }
        
        /**
         * 값 탐색하기
        */
        Node<T>* find_data(T data) {
            Node<T>* currNode = this->header;
            while (currNode != nullptr) {
                if (currNode->getData() == data) {
                    return currNode;
                }

                currNode = currNode->next();
            }

            return nullptr;
        }

        /**
         * 시작 값 가져오기
        */
        iterator begin() {
            return iterator(this->header);
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
            Node<T>* node = this->header;
            for(int i = 0; i < this->length; i++) {
                cout << node->getData() << ' ';

                if (node->next() != nullptr) {
                    node = node->next();
                }
            }
            cout << '\n';
            return;
        }

        Node<T>* getTail() {
            return this->tail;
        }
    private: 
        Node<T>* header;
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
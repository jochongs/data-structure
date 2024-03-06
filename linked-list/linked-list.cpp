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

// 단방향 링크드 리스트
template <typename T> class LinkedList {
    public: 
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
         * 전부 출력하기
        */
        void displayAll() {
            Node<T>* node = this->header;
            for(int i = 0; i < this->length; i++) {
                cout << node->getData() << ' ';

                node = node->next();
            }
            cout << '\n';
            return;
        }
    private: 
        Node<T>* header;
        Node<T>* tail;
        int length;
};

int main() {
    LinkedList<int> l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    Node<int>* node = l1.find_data(2);
    
    if (node == nullptr) {
        cout << "no" << '\n';
        return 1;
    }

    l1.insert_after(node, 100);
    l1.displayAll();
}
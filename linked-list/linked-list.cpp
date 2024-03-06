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
            this->size = 0;
        }
        ~LinkedList() {
            Node<T>* currNode = this->header;
            while (currNode != nullptr) {
                Node<T>* nextNode = currNode->next();
                delete currNode;
                currNode = nextNode;
            }
        }
        
        void push_back(T data) {
            Node<T>* newNode = new Node<T>(data);

            this->size++;
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

        void push_front(T data) {
            Node<T>* newNode = new Node<T>(data);

            this->size++;
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

        void displayAll() {
            Node<T>* node = this->header;

            for(int i = 0; i < this->size; i++) {
                cout << node->getData() << ' ';

                node = node->next();
            }
            cout << '\n';
            return;
        }
    private: 
        Node<T>* header;
        Node<T>* tail;
        int size;
};

int main() {
    LinkedList<int> l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_front(4);
    l1.push_front(5);
    l1.displayAll();
}
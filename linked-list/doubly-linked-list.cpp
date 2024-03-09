#include <iostream>
using namespace std;

template <typename T> class DoublyLinkedList;
template <typename T> class Iterator;
template <typename T> class Node;

template <typename T> class Node {
    public: 
        T data;
    
        Node(T data) {
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }
    
    private:
        Node<T>* prev;
        Node<T>* next;
    
    friend class DoublyLinkedList<T>;
    friend class Iterator<T>;
};

template <typename T> class DoublyLinkedList {
    public: 
        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        void push_back(T data) {
            Node<T>* newNode = new Node<T>(data);

            this->length++;
            if (this->head == nullptr) {
                this->head = this->tail = newNode;
                return;
            }

            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }

        void push_front(T data) {
            Node<T>* newNode = new Node<T>(data);

            this->length++;
            if (this->head == nullptr) {
                this->head = this->tail = newNode;
                return;
            }

            newNode->next = this->head;
            this->head->prev = newNode->next;
            this->head = newNode;
        }

        void remove_back() {
            if (this->head == nullptr) {
                return;
            }

            this->length--;
            if (this->head == this->tail) {
                this->head = this->tail = nullptr;
                return;
            }

            Node<T>* old_tail = this->tail;
            old_tail->prev->next = nullptr;
            this->tail = old_tail->prev;
            delete old_tail;
        }

        void remove_front() {
            if (this->head == nullptr) {
                return;
            }

            this->length--;
            if (this->head == this->tail) {
                this->head = this->tail = nullptr;
                return;
            }

            Node<T>* old_head = this->head;
            old_head->next->prev = nullptr;
            this->head = old_head->next;
            delete old_head;
        }

        int size() {
            return this->length;
        }

        void dispalyAllNode() {
            Node<T>* currNode = this->head;

            if (currNode == nullptr) {
                return;
            }
            
            for (int i = 0; i < this->length; i++) {
                cout << currNode->data << ' ';
                currNode = currNode->next;
            }

            cout << '\n';
            return;
        }
    private: 
        Node<T>* head;
        Node<T>* tail;
        int length;
};

int main() {
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_front(3);
    list.push_back(3);
    list.remove_back();
    list.remove_front();
    list.remove_front();
    list.remove_front();
    list.remove_front();

    list.dispalyAllNode();
}
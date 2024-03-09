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

template <typename T> class Iterator {
    public: 
        Iterator(Node<T>* node) {
            this->curr_node = node;
        }

        bool has_next() {
            if (this->curr_node->next == nullptr) {
                return false;
            }

            return true;
        }

        T get() {
            return curr_node->data;
        }

        void move_next() {
            if (this->curr_node == nullptr) {
                return;
            }

            this->curr_node = this->curr_node->next;
        }

        Iterator<T>& operator++() {
            if (this->has_next()) {
                this->move_next();
            }
            return *this;
        }

        Iterator<T> operator++(int) {
            Iterator<T> temp = *this;
            this->move_next();
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

template <typename T> class DoublyLinkedList {
    public: 
        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        typedef Iterator<T> Iterator;

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
            this->head->prev = newNode;
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
            Node<T>* old_head = this->head;
            if (this->head == this->tail) {
                this->head = this->tail = nullptr;
            } else { 
                old_head->next->prev = nullptr;
                this->head = old_head->next;
            }

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
    
        Iterator beign() {
            return Iterator(this->head);
        }

        Iterator end() {
            return Iterator(this->tail);
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
    list.push_back(3);

    DoublyLinkedList<int>::Iterator it = list.beign();

    for (it = list.beign(); it != nullptr; it++) {
        cout << it.get() << ' ';
    }
}
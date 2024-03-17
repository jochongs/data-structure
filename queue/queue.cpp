#include <iostream>
using namespace std;

template <typename T> class Queue;

template <typename T> class Node {
private:
    T data;
    Node* next;
    Node* prev;
public: 
    Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

friend class Queue<T>;
};

template <typename T> class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    Queue() {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    void push(T data) {
        Node<T>* new_node = new Node<T>(data);

        this->length++;
        if (this->head == nullptr) {
            this->head = this->tail = new_node;
            return;
        }

        new_node->next = this->head;
        this->head->prev = new_node;
        this->head = new_node;
    }

    void pop() {
        if (this->head == nullptr) {
            throw runtime_error("empty queue");
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

    T front() {
        return this->tail->data;   
    }

    bool is_empty() {
        return this->head == nullptr;
    }

    int size() {
        return this->length;
    }
};

int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    int size = q.size();
    for (int i = 0; i < size; i++) {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}
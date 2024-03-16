#include <iostream>
using namespace std;

template <typename T> class Stack {
private: 
    T arr[100];
    int size;
    int max_size;
public: 
    Stack() {
        this->size = 0;
        this->max_size = 100;
    }

    void push(T data) {
        if (size >= max_size) {
            throw runtime_error("Cannot push over the max size");
        }

        size++;
        arr[size - 1] = data;
    }

    T pop() {
        if (size == 0) {
            throw runtime_error("Cannot pop when stack is empty");
        }

        size--;
        T data = arr[size];
        return data;
    }

    void empty() {
        return size == 0;
    }

    T get(int idx) {
        if (idx >= size) {
            throw runtime_error("Cannot find data");
        }

        return arr[idx];
    }

    T top() {
        if (size == 0) {
            throw runtime_error("Cannot find data");
        }

        return arr[size - 1];
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    //s.pop();
    s.print();
}
#include <iostream>
using namespace std;

class arrQ {
private:
   int* Q;
   int rear;
   int front;
   int capacity;

public:
   arrQ(int capacity) {
      this->capacity = capacity + 1;
      Q = new int[this->capacity];
      front = rear = 0;

      for (int i = 0; i < capacity; i++) {
         Q[i] = 0;
      }
   }

   bool isFull() {
      return front == (rear + 1) % capacity;
   }

   bool isEmpty() {
      return front == rear;
   }

   void enqueue(int value) {
      if (isFull()) {
         cout << "Full" << endl;
      }
      else {
         rear = (rear + 1) % capacity;
         Q[rear] = value;
      }
   }

   void dequeue() {
      if (isEmpty()) {
         cout << "Empty" << endl;
      }
      else {
         front = (front + 1) % capacity;
         Q[front] = 0;
      }
   }

   void _front() {
      if (isEmpty()) {
         cout << "Empty" << endl;
      }
      else {
         cout << Q[(front + 1) % capacity] << endl;
      }
   }

   void _rear() {
      if (isEmpty()) {
         cout << "Empty" << endl;
      }
      else {
         cout << Q[rear] << endl;
      }
   }

   int size() {
      return (rear - front + capacity) % capacity;
   }

   void print() {
      cout << "================================" << endl;
      cout << "front index is " << front << endl;
      cout << "rear index is " << rear << endl;

      for (int i = 0; i < capacity; i++) {
         cout << Q[i] << " ";
      }
      cout << endl;
      cout << "================================" << endl;
   }
};

int main() {
   arrQ arQ(5);

   cout << boolalpha << arQ.isEmpty() << endl;
   cout << boolalpha << arQ.isFull() << endl;
   arQ.enqueue(1);
   arQ.enqueue(2);
   arQ.enqueue(3);
   arQ.enqueue(4);
   arQ.enqueue(5);
   arQ.print();
   arQ.dequeue();
   arQ.dequeue();
   arQ.enqueue(9);
   arQ.print();
   arQ.dequeue();
   arQ.print();
}
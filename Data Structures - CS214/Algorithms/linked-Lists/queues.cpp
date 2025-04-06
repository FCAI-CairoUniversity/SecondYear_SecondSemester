#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        clear();
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue underflow! Cannot dequeue from empty queue.");
        }
        Node* temp = front;
        T value = front->data;
        front = front->next;
        delete temp;
        size--;
        if (isEmpty()) rear = nullptr;
        return value;
    }

    T first() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty! Cannot access first element.");
        }
        return front->data;
    }

    int getSize() const {
        return size;
    }
    void print() const {
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;

        Node(T val, int prio) : data(val), priority(prio), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    PriorityQueue() : head(nullptr), size(0) {}

    ~PriorityQueue() {
        clear();
    }

    void enqueue(const T& item, int priority) {
        Node* newNode = new Node(item, priority);

        if (!head || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Priority queue is empty!");
        }
        Node* temp = head;
        T value = head->data;
        head = head->next;
        delete temp;
        size--;
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Priority queue is empty!");
        }
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    int getSize() const {
        return size;
    }
};



// int main() {
//   PriorityQueue<string> pq;
//   pq.enqueue("Task A", 2);
//   pq.enqueue("Task B", 5);  // Highest priority
//   pq.enqueue("Task C", 1);

//   cout << "Peek: " << pq.peek() << endl; // Task B
//   cout << "Dequeue: " << pq.dequeue() << endl; // Task B
//   cout << "Dequeue: " << pq.dequeue() << endl; // Task A

//   return 0;
// }

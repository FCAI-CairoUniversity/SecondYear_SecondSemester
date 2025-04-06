#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    // Node structure to store data, next, and prev pointers
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Copy Constructor
    DoublyLinkedList(const DoublyLinkedList& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;

        if (other.isEmpty()) return;

        Node* current = other.head;
        while (current != nullptr) {
            insertAtEnd(current->data);
            current = current->next;
        }
    }

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        clear();
    }

    // Insert at the end
    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {  // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Insert at the beginning
    void insertAtBeginning(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Delete first element
    void deleteFirst() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Delete last element
    void deleteLast() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    // Clear the list
    void clear() {
        while (!isEmpty()) {
            deleteFirst();
        }
    }

    // Print the list
    void printList() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Get size of the list
    int getSize() const {
        return size;
    }

    // Search for an element
    bool search(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Remove nodes that satisfy the given condition (remove if)
    void removeIf(bool (*predicate)(T)) {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            if (predicate(current->data)) {
                if (current == head) {
                    deleteFirst();
                } else if (current == tail) {
                    deleteLast();
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    size--;
                }
            }
            current = nextNode;
        }
    }

    // Sort the list using insertion sort
    void sort() {
        if (isEmpty() || head == tail) return;

        Node* sorted = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;
            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                if (sorted != nullptr) sorted->prev = current;
                sorted = current;
                current->prev = nullptr;
            } else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }
                temp->next = current;
                current->prev = temp;
            }
            current = nextNode;
        }

        head = sorted;
        tail = sorted;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }
    }

    // Merge two sorted lists
    void merge(DoublyLinkedList& other) {
        if (isEmpty()) {
            head = other.head;
            tail = other.tail;
        } else if (other.isEmpty()) {
            return;
        } else {
            Node* mergedHead = nullptr;
            Node* mergedTail = nullptr;

            Node* current1 = head;
            Node* current2 = other.head;

            while (current1 != nullptr && current2 != nullptr) {
                Node* newNode;
                if (current1->data <= current2->data) {
                    newNode = new Node(current1->data);
                    current1 = current1->next;
                } else {
                    newNode = new Node(current2->data);
                    current2 = current2->next;
                }

                if (mergedHead == nullptr) {
                    mergedHead = mergedTail = newNode;
                } else {
                    mergedTail->next = newNode;
                    newNode->prev = mergedTail;
                    mergedTail = newNode;
                }
            }

            while (current1 != nullptr) {
                Node* newNode = new Node(current1->data);
                mergedTail->next = newNode;
                newNode->prev = mergedTail;
                mergedTail = newNode;
                current1 = current1->next;
            }

            while (current2 != nullptr) {
                Node* newNode = new Node(current2->data);
                mergedTail->next = newNode;
                newNode->prev = mergedTail;
                mergedTail = newNode;
                current2 = current2->next;
            }

            head = mergedHead;
            tail = mergedTail;
        }
    }

    // Reverse the list
    void reverse() {
        if (isEmpty() || head == tail) return;

        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }
};


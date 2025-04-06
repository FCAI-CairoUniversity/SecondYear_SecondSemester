#include <iostream>
using namespace std;

template <typename T>
class CircularDoublyLinkedList {
private:
    // Node structure to store data, next, and prev pointers
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    int size;

public:
    // Constructor
    CircularDoublyLinkedList() : head(nullptr), size(0) {}

    // Destructor to clean up memory
    ~CircularDoublyLinkedList() {
        clear();
    }

    // Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get the size of the list
    int getSize() const {
        return size;
    }

    // Insert at the beginning
    void insertAtBeginning(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Insert at the end
    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        size++;
    }

    // Delete the first node
    void deleteFirst() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head->prev;
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        size--;
    }

    // Delete the last node
    void deleteLast() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head->prev;
            Node* secondLast = tail->prev;
            secondLast->next = head;
            head->prev = secondLast;
            delete tail;
        }
        size--;
    }

    // Clear the list
    void clear() {
        while (!isEmpty()) {
            deleteFirst();
        }
    }

    // Print the list in a forward direction
    void printList() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Print the list in a backward direction
    void printListReverse() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head->prev;
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != head->prev);
        cout << endl;
    }

    // Search for an element
    bool search(const T& value) const {
        if (isEmpty()) return false;
        Node* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

    // Remove nodes that satisfy the given condition (remove if)
    void removeIf(bool (*predicate)(T)) {
        if (isEmpty()) return;
        Node* current = head;
        do {
            Node* nextNode = current->next;
            if (predicate(current->data)) {
                if (current == head) {
                    deleteFirst();
                } else if (current == head->prev) {
                    deleteLast();
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    size--;
                }
            }
            current = nextNode;
        } while (current != head);
    }

    // Sort the list using insertion sort
    void sort() {
        if (isEmpty() || size == 1) return;

        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            while (temp->prev != head->prev && temp->data < temp->prev->data) {
                T tempData = temp->data;
                temp->data = temp->prev->data;
                temp->prev->data = tempData;
                temp = temp->prev;
            }
            current = current->next;
        }
    }

    // Reverse the list
    void reverse() {
        if (isEmpty() || size == 1) return;

        Node* current = head;
        do {
            Node* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = current->prev;
        } while (current != head);

        head = head->prev;
    }
};

// int main() {
//     CircularDoublyLinkedList<int> list;

//     // Inserting elements at the beginning and end
//     list.insertAtBeginning(10);
//     list.insertAtBeginning(20);
//     list.insertAtEnd(30);
//     list.insertAtEnd(40);

//     cout << "Circular List (Forward): ";
//     list.printList();

//     cout << "Circular List (Reverse): ";
//     list.printListReverse();

//     // Delete first and last element
//     list.deleteFirst();
//     cout << "After deleting first element (Forward): ";
//     list.printList();

//     list.deleteLast();
//     cout << "After deleting last element (Forward): ";
//     list.printList();

//     // Sort the list
//     list.sort();
//     cout << "After sorting: ";
//     list.printList();

//     // Reverse the list
//     list.reverse();
//     cout << "After reversing: ";
//     list.printList();

//     // Search for an element
//     bool found = list.search(30);
//     cout << "Element 30 found: " << (found ? "Yes" : "No") << endl;

//     return 0;
// }

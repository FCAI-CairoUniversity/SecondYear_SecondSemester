#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
protected:
    struct Node {
        T info;         // Data stored in the node
        Node* next;     // Pointer to the next node in the list
    };
    Node *head;   // Pointer to the head of the list
    Node *last;   // Pointer to the last node of the list
    int size;     // Size of the list

public:
    LinkedList() : head(nullptr), last(nullptr), size(0) {} // Constructor to initialize an empty list
    virtual ~LinkedList() { clear(); }

    virtual void insert(const T& item) = 0; // Pure virtual function for insertion

    void clear() {
        Node *current = head;
        Node *nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        last = nullptr;
        size = 0;
    }

    void print() const {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() const { return head == nullptr; }

    int getSize() const { return size; }

    // Search for a value in the list, returns true if found, otherwise false
    bool search(const T& item) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->info == item) {
                return true;  // Item found
            }
            current = current->next;
        }
        return false;  // Item not found
    }
};

template <typename T>
class OrderedLinkedList : public LinkedList<T> {
public:
    OrderedLinkedList() : LinkedList<T>() {} // Inherit the constructor from LinkedList

    // Insert an item into the ordered list, maintaining the sorted order
    void insert(const T& item) override {
        Node *newNode = new Node;
        newNode->info = item;
        newNode->next = nullptr;

        if(this->isEmpty() || this->head->info >= item) {
            newNode->next = this->head;
            this->head = newNode;
            if (this->last == nullptr) {
                this->last = newNode; // If the list was empty, the new node is also the last node
            }
        } else {
            Node *current = this->head;
            while (current->next != nullptr && current->next->info < item) {
                current = current->next; // Traverse to find the correct position
            }
            newNode->next = current->next; // Link the new node to the next node
            current->next = newNode;       // Link the previous node to the new node
            if (current->next == nullptr) {
                this->last = newNode; // Update the last pointer if it's the new last node
            }
        }
        this->size++; // Increase the size of the list
    }

    void deleteFirst() {
        if (this->isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        Node *temp = this->head; // Node to be deleted
        this->head = this->head->next; // Move head to the next node
        delete temp; // Delete the old head
        if (this->head == nullptr) {
            this->last = nullptr; // If the list is empty now, reset last pointer
        }
        this->size--; // Decrease the size of the list
    }

    void deleteLast() {
        if (this->isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        if (this->head == this->last) {
            this->deleteFirst(); // If there's only one node, delete it
            this->last = nullptr; // Reset last pointer
        } else {
            Node *current = this->head;
            while (current->next != this->last) {
                current = current->next; // Traverse to the node before last
            }
            delete this->last; // Delete the last node
            current->next = nullptr; // Set the new last node's next pointer to nullptr
            this->last = current; // Update last to the previous node
        }
        this->size--; // Decrease the size of the list
    }

    bool search(const T& item) const {
        Node *current = this->head;
        while (current != nullptr) {
            if (current->info == item) {
                return true; // Item found
            }
            if (current->info > item) {
                return false; // Item not found, since the list is ordered
            }
            current = current->next; // Move to the next node
        }
        return false; // Item not found
    }

    // Check if the list is empty
    bool isEmpty() const { return this->head == nullptr; }
};

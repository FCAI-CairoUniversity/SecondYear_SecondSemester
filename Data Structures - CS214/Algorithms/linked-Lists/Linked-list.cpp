#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T info;         // Data stored in the node
        Node* next;     // Pointer to the next node in the list
    };
    Node *head;   // Pointer to the head of the list
    Node *last;   // Pointer to the last node of the list
    int size;     // Size of the list

public:
    LinkedList() : head(nullptr), last(nullptr), size(0) {} // Constructor to initialize an empty list

    ~LinkedList() {
        clear(); // Clear the list when the object is destroyed
    }

    bool isEmpty() const {
        return head == nullptr; // Check if the list is empty
    }

    void clear() {
        Node *current = head;
        Node *nextNode;
        while (current != nullptr) {
            nextNode = current->next; // Store the next node
            delete current;           // Delete the current node
            current = nextNode;       // Move to the next node
        }
        head = nullptr;  // Reset the head pointer
        last = nullptr;  // Reset the last pointer
        size = 0;        // Reset the size
    }

    void print() const {
        if (isEmpty()) {
            cout << "The list is empty." << endl;
        } else {
            Node *current = head;
            while (current != nullptr) {
                cout << current->info << " "; // Print the data in the current node
                current = current->next;     // Move to the next node
            }
            cout << endl;
        }
    }

    void insertAtBegin(const T& item) {
        Node *newNode = new Node;     // Create a new node
        newNode->info = item;         // Set the data
        newNode->next = head;         // Link the new node to the previous head
        head = newNode;               // Move the head to the new node
        if (last == nullptr) {
            last = newNode;           // If the list was empty, the new node is also the last node
        }
        size++;                       // Increase the size of the list
    }

    void insertAtEnd(const T& item) {
        Node *newNode = new Node;     // Create a new node
        newNode->info = item;         // Set the data
        newNode->next = nullptr;      // New node will be the last node
        if (isEmpty()) {
            head = newNode;           // If the list is empty, set head to the new node
            last = newNode;           // Set last to the new node as well
        } else {
            last->next = newNode;     // Link the current last node to the new node
            last = newNode;           // Update last to the new node
        }
        size++;                       // Increase the size of the list
    }

    void insertAt(int index, const T& item) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds" << endl; // Index out of bounds
            return;
        }
        if (index == 0) {
            insertAtBegin(item);     // Insert at the beginning if the index is 0
        } else {
            Node *newNode = new Node; // Create a new node
            newNode->info = item;     // Set the data
            Node *current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next; // Traverse to the node before the insertion point
            }
            newNode->next = current->next; // Link the new node to the next node
            current->next = newNode;       // Link the current node to the new node
            if (newNode->next == nullptr) {
                last = newNode;           // Update last if the new node is the last node
            }
            size++;                       // Increase the size of the list
        }
    }

    void deleteFromBegin() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;             // Move the head pointer to the next node
        if (head == nullptr) {
            last = nullptr;           // If the list is empty after deletion, reset last
        }
        delete temp;                  // Delete the old head node
        size--;                       // Decrease the size of the list
    }

    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        if (head == last) {
            delete head;              // If there's only one node
            head = last = nullptr;    // List is now empty
        } else {
            Node *current = head;
            while (current->next != last) {
                current = current->next; // Traverse to the node before last
            }
            delete last;               // Delete the last node
            current->next = nullptr;   // Set the new last node's next pointer to nullptr
            last = current;            // Update last to the previous node
        }
        size--;                       // Decrease the size of the list
    }

    void deleteValue(const T& item) {
        if (isEmpty()) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        if (head->info == item) {
            deleteFromBegin();       // If the item is at the beginning, delete it from the beginning
            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->info != item) {
            current = current->next; // Traverse to the node before the item
        }
        if (current->next == nullptr) {
            cout << "Item not found in the list" << endl; // Item not found
            return;
        }
        Node *temp = current->next; // Node to be deleted
        current->next = current->next->next; // Link the previous node to the next node
        if (current->next == nullptr) {
            last = current; // If the deleted node was the last one, update last
        }
        delete temp; // Delete the node
        size--;      // Decrease the size of the list
    }

    bool search(const T& item) const {
        Node *current = head;
        while (current != nullptr) {
            if (current->info == item) {
                return true; // Item found
            }
            current = current->next; // Move to the next node
        }
        return false; // Item not found
    }

    class Iterator {
    private:
        Node* current; // Pointer to the current node
    public:
        Iterator(Node* start) : current(start) {} // Constructor initializes to the starting node

        bool hasNext() const {
            return current != nullptr; // Check if the current node is valid
        }

        T& next() {
            T& item = current->info; // Get the data of the current node
            current = current->next;  // Move to the next node
            return item;              // Return the data
        }

        T& operator*() {
            return current->info; // Dereference to get the data at the current node
        }

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next; // Move to the next node
            }
            return *this; // Return the updated iterator
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current; // Compare iterators for equality
        }
    };

    Iterator begin() {
        return Iterator(head); // Return an iterator starting from the head
    }

    Iterator end() {
        return Iterator(nullptr); // Return an iterator that points to nullptr (end of the list)
    }
};

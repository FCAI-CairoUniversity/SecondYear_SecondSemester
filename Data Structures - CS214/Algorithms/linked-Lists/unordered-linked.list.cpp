#include <iostream>
using namespace std;

// Template class for Unordered Linked List
template <typename T>
class UnorderedLinkedList {
private:
    // Node structure to store data and next pointer
    struct Node {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    // Constructor to initialize the Linked List
    UnorderedLinkedList() : head(nullptr), size(0) {}

    // Destructor to free memory
    ~UnorderedLinkedList() {
        clearList();
    }

    // Insert at the end
    void insertAtEnd(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Insert at the beginning
    void insertAtFirst(T value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Remove at specific index
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return;
        }
        Node* temp = head;
        if (index == 0) {
            head = temp->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        size--;
    }

    // Remove the first node
    void removeFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    // Sequential search for an element
    int seqSearch(T value) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == value) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1; // Element not found
    }

    // Clear the list
    void clearList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    // Display the list
    void displayList() const {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Get the current size of the list
    int listSize() const {
        return size;
    }
};

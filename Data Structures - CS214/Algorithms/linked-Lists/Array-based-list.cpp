#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* list;      // Dynamic array for storing elements (using template type T)
    int size;     // Current number of elements in the list
    int maxSize;  // Maximum capacity of the list

public:
    // Constructor to initialize the list with a given size
    ArrayList(int capacity) {
        maxSize = capacity;  // Set the maximum size of the list
        size = 0;            // Initialize size to 0
        list = new T[maxSize]; // Dynamically allocate memory for the list
        cout << "ArrayList created with capacity: " << maxSize << endl;
    }

    // Copy constructor (Deep copy to avoid shallow copying)
    ArrayList(const ArrayList& other) {
        maxSize = other.maxSize;  // Copy the maximum size from the other list
        size = other.size;        // Copy the current size from the other list
        list = new T[maxSize];    // Allocate memory for the new list
        assert(list != nullptr);  // Ensure memory allocation was successful
        for (int i = 0; i < size; i++) {
            list[i] = other.list[i]; // Copy each element from the other list
        }
        cout << "ArrayList copied with capacity: " << maxSize << endl;
    }

    // Assignment operator (Deep copy)
    ArrayList& operator=(const ArrayList& other) {
        if (this != &other) {
            delete[] list; // Free the current list memory

            maxSize = other.maxSize;  // Copy the maximum size from the other list
            size = other.size;        // Copy the current size from the other list
            list = new T[maxSize];    // Allocate memory for the new list
            assert(list != nullptr);  // Ensure memory allocation was successful

            for (int i = 0; i < size; i++) {
                list[i] = other.list[i]; // Copy each element from the other list
            }
        }
        return *this; // Return the current object
    }

    // Destructor to deallocate the dynamically allocated memory
    ~ArrayList() {
        delete[] list; // Free the allocated memory
        cout << "ArrayList destroyed and memory freed" << endl;
    }

    // Function to print the elements of the list
    void print() const {
        if (size == 0) {
            cout << "The list is empty." << endl;
        } else {
            for (int i = 0; i < size; i++) {
                cout << list[i] << " "; // Print each element
            }
            cout << endl; // New line after printing all elements
        }
    }

    bool isEmpty() const {
        return size == 0; // Check if the list is empty
    }

    bool isFull() const {
        return size == maxSize; // Check if the list is full
    }

    int getSize() const {
        return size; // Return the current size of the list
    }

    int getMaxSize() const {
        return maxSize; // Return the maximum size of the list
    }

    bool isItemAt(int index, const T& item) const {
        if (index < 0 || index >= size) {
            return false; // Index out of bounds
        }
        return list[index] == item; // Check if the item at the given index matches the provided item
    }

    // Function to insert item at specific index
    void insertAt(int index, const T& insertItem) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds" << endl; // Index out of bounds
            return;
        }
        if (isFull()) {
            cout << "List is full, cannot insert item" << endl; // List is full
            return;
        }
        for (int i = size; i > index; i--) {
            list[i] = list[i - 1]; // Shift elements to the right
        }
        list[index] = insertItem; // Insert the new item at the specified index
        size++; // Increase the size of the list
    }

    // Function to remove item at specific index
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds" << endl; // Index out of bounds
            return;
        }
        for (int i = index; i < size - 1; i++) {
            list[i] = list[i + 1]; // Shift elements to the left
        }
        size--; // Decrease the size of the list
    }

    // Function to replace item at specific index
    void replaceAt(int index, const T& newItem) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds" << endl; // Index out of bounds
            return;
        }
        list[index] = newItem; // Replace the item at the specified index with the new item
    }

    // Function to clear the list
    void clear() {
        size = 0; // Reset the size to 0, effectively clearing the list
    }

    // Sequential search function
    int seqSearch(const T& item) const {
        for (int i = 0; i < size; i++) {
            if (list[i] == item) {
                return i; // Return the index of the found item
            }
        }
        return -1; // Return -1 if item is not found
    }

    // Function to insert an item at the end if not already present
    void insert(const T& item) {
        if (isFull()) {
            cout << "List is full, cannot insert item" << endl; // List is full
            return;
        }
        int index = seqSearch(item); // Search for the item in the list
        if (index == -1) {
            list[size++] = item; // Insert the item at the end if not found
        } else {
            cout << "Item already exists in the list" << endl; // Item already exists
        }
    }

    // Function to remove an item from the list
    void remove(const T& item){
        int index = seqSearch(item); // Search for the item in the list
        if (index != -1) {
            removeAt(index); // Remove the item if found
        } else {
            cout << "Item not found in the list" << endl; // Item not found
        }
    }

};

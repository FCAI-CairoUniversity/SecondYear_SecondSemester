#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        // Assume the minimum is the first element of the unsorted part
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    
    // Dynamically allocate memory for the array
    int* arr = new int[size];
    
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    // Sorting the array
    selectionSort(arr, size);
    
    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Free allocated memory
    delete[] arr;
    
    return 0;
}

#include <iostream>
using namespace std;

// Function to perform binary search to find the correct position for insertion
int binarySearch(int* arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid + 1;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

// Function to perform Binary Insertion Sort
void binaryInsertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int pos = binarySearch(arr, 0, i - 1, key);
        
        // Shift elements to the right to make space for key
        int j = i;
        while (j > pos) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[pos] = key;
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
    binaryInsertionSort(arr, size);
    
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

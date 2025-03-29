# Sorting Algorithms Repository

## Binary Insertion Sort Implementation

This repository contains an implementation of the **Binary Insertion Sort** algorithm in C++ using a dynamically allocated array.

## 📌 Algorithm Explanation
Binary Insertion Sort is an optimized version of Insertion Sort that uses **binary search** to find the correct position of an element instead of linear scanning, reducing the number of comparisons.

### 🔍 How Binary Insertion Sort Works
1. Start with the second element.
2. Use **binary search** to find the correct position in the sorted portion of the array.
3. Shift elements to make space for the new element.
4. Insert the element at the found position.
5. Repeat for all elements until the array is sorted.

## ⏳ Time Complexity Analysis
| Case        | Time Complexity |
|------------|----------------|
| **Worst Case** (Reversed Order) | O(n²) |
| **Average Case** | O(n²) |
| **Best Case** (Already Sorted) | O(n log n) |

- **Best case**: O(n log n) since binary search takes O(log n) for each element.
- **Worst and average case**: O(n²) due to shifting elements.

## 🛠 Space Complexity
- **O(1)** (constant space) since sorting is done in place.
- Only a few extra variables are used.

## 📝 Code Implementation
```cpp
#include <iostream>
using namespace std;

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

void binaryInsertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int pos = binarySearch(arr, 0, i - 1, key);
        
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
    
    int* arr = new int[size];
    
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    binaryInsertionSort(arr, size);
    
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    
    return 0;
}
```

## 🚀 Usage
1. Compile the program using a C++ compiler:
   ```sh
   g++ binary_insertion_sort.cpp -o binary_insertion_sort
   ```
2. Run the executable:
   ```sh
   ./binary_insertion_sort
   ```
3. Enter the number of elements and provide input values.
4. The program will output the sorted array.

## 📌 Next Steps
- Implement **Merge Sort and Quick Sort** for better performance.
- Optimize shifting operations for efficiency.

---
Made with ❤️ for sorting enthusiasts!

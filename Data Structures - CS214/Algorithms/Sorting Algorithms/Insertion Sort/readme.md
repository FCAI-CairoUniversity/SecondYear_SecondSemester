# Sorting Algorithms Repository

## Insertion Sort Implementation

This repository contains an implementation of the **Insertion Sort** algorithm in C++ using a dynamically allocated array.

## 📌 Algorithm Explanation
Insertion Sort is an in-place, stable sorting algorithm that builds the sorted array one element at a time. It is efficient for small or nearly sorted datasets.

### 🔍 How Insertion Sort Works
1. Start with the second element and compare it with the previous elements.
2. Shift larger elements to the right to create space for the current element.
3. Insert the current element into its correct position.
4. Repeat for all elements until the array is sorted.

## ⏳ Time Complexity Analysis
| Case        | Time Complexity |
|------------|----------------|
| **Worst Case** (Reversed Order) | O(n²) |
| **Average Case** | O(n²) |
| **Best Case** (Already Sorted) | O(n) |

- The best case occurs when the array is already sorted, requiring **O(n)** time.
- The worst case happens when the array is sorted in reverse order, requiring **O(n²)** comparisons and shifts.

## 🛠 Space Complexity
- **O(1)** (constant space) since sorting is done in place.
- Only a few extra variables are used regardless of the input size.

## 📝 Code Implementation
```cpp
#include <iostream>
using namespace std;

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    
    insertionSort(arr, size);
    
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
   g++ insertion_sort.cpp -o insertion_sort
   ```
2. Run the executable:
   ```sh
   ./insertion_sort
   ```
3. Enter the number of elements and provide input values.
4. The program will output the sorted array.

## 📌 Next Steps
- Implement more sorting algorithms like **Merge Sort and Quick Sort**.
- Improve efficiency using hybrid sorting techniques.

---
Made with ❤️ for sorting enthusiasts!

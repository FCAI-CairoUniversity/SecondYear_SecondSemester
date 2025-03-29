# Sorting Algorithms Repository

## Bubble Sort Implementation

This repository contains an implementation of the **Bubble Sort** algorithm in C++ using a dynamically allocated array.

## 📌 Algorithm Explanation
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted.

### 🔍 How Bubble Sort Works
1. Start from the first element and compare it with the next.
2. If the current element is greater than the next, swap them.
3. Move to the next element and repeat until the end of the array.
4. The largest element will "bubble up" to the last position.
5. Repeat the process for the remaining elements until the array is sorted.

## ⏳ Time Complexity Analysis
| Case        | Time Complexity |
|------------|----------------|
| **Worst Case** (Reversed Order) | O(n²) |
| **Average Case** | O(n²) |
| **Best Case** (Already Sorted) | O(n) |

- The best case occurs when the array is already sorted, requiring only **O(n)** time with the optimized version.
- The worst case happens when the array is sorted in reverse order, requiring **O(n²)** swaps and comparisons.

## 🛠 Space Complexity
- **O(1)** (constant space) since sorting is done in place.
- Only a few extra variables are used regardless of the input size.

## 📝 Code Implementation
```cpp
#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
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
    
    bubbleSort(arr, size);
    
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
   g++ bubble_sort.cpp -o bubble_sort
   ```
2. Run the executable:
   ```sh
   ./bubble_sort
   ```
3. Enter the number of elements and provide input values.
4. The program will output the sorted array.

## 📌 Next Steps
- Implement more sorting algorithms like **Selection Sort, Insertion Sort, Merge Sort, and Quick Sort**.
- Improve efficiency using different approaches.

---
Made with ❤️ for sorting enthusiasts!

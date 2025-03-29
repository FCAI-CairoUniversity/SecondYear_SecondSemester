# Sorting Algorithms Repository

## Selection Sort Implementation

This repository contains an implementation of the **Selection Sort** algorithm in C++ using a dynamically allocated array.

## 📌 Algorithm Explanation
Selection Sort is an in-place sorting algorithm that divides the list into two parts: the sorted and the unsorted section. It repeatedly selects the smallest element from the unsorted section and swaps it with the first unsorted element.

### 🔍 How Selection Sort Works
1. Start with the first element, assume it is the smallest.
2. Compare it with the rest of the elements to find the minimum.
3. Swap the found minimum element with the first element.
4. Move to the next element and repeat until the array is sorted.

## ⏳ Time Complexity Analysis
| Case        | Time Complexity |
|------------|----------------|
| **Worst Case** (Reversed Order) | O(n²) |
| **Average Case** | O(n²) |
| **Best Case** (Already Sorted) | O(n²) |

- Selection Sort always takes **O(n²)** time, regardless of input order.
- It performs **(n-1) + (n-2) + ... + 1 ≈ n²/2** comparisons.

## 🛠 Space Complexity
- **O(1)** (constant space) since sorting is done in place.
- No extra memory is used apart from a few temporary variables.

## 📝 Code Implementation
```cpp
#include <iostream>
using namespace std;

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
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
    
    selectionSort(arr, size);
    
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
   g++ selection_sort.cpp -o selection_sort
   ```
2. Run the executable:
   ```sh
   ./selection_sort
   ```
3. Enter the number of elements and provide input values.
4. The program will output the sorted array.

## 📌 Next Steps
- Implement more sorting algorithms like **Insertion Sort, Merge Sort, and Quick Sort**.
- Improve efficiency using different approaches.

---
Made with ❤️ for sorting enthusiasts!

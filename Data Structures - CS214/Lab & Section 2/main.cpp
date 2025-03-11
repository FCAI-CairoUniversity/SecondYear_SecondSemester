/*
 * Author(s): Mohammed Atef & George Malak.
 * Date: March 11, 2025.
 * Lab & Section: 2.
 * Course: Data Structure - CS214.
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
int partition(T data[], int left, int right) {
    int mid = left + (right - left) / 2;
    swap(data[mid], data[right]);
    T pivot = data[right];

    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (data[j] < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[right]);
    return i + 1;
}

template <class T>
void quickSort(T data[], int left, int right) {
    if (left < right) {
        int pivot = partition(data, left, right);
        quickSort(data, left, pivot - 1);
        quickSort(data, pivot + 1, right);
    }
}

int main() {
    int arr[] = {20,1, 15,6, 2, 5, 3, 4,0,3};
    int size = sizeof (arr) / sizeof (arr[0]);

    quickSort(arr, 0, size-1);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " \n"[i == size - 1];
    }
    return 0;
}
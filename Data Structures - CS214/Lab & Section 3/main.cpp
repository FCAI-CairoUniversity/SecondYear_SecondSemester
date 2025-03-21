/*
 * Author(s): Mohammed Atef & George Malak.
 * Date: March 18, 2025.
 * Lab & Section: 3.
 * Course: Data Structure - CS214.
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void bubbleSort(T data[], int size) {
    long long num_iteration = 1 ;
    for (int i = 0; i < size; i++) {
        for (int j = size - 1 ; j > i; --j) {
            if (data[j-1] > data[j]) {
                swap(data[j-1], data[j]);
                num_iteration++;
            }
        }
    }
}

void fun() {
    char arr[] = {'a', 'c', 'h', 'g', 'z', 'e'};
    char c; cin >> c;
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);

    int start = 0, end = size -1;
    while (start <= end) {
        int mid = (start + end) /2;
        if (arr[mid] == c) {
            cout << "Found " << c << endl;
            return;
        }
        else if (arr[mid] < c) start = mid +1;
        else end = mid -1;
    }
    cout << "Not found..." << endl;
}

int main() {
    int t = 1;
    while (t--) fun();
    return 0;
}
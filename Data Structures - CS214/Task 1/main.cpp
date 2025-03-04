/*
 * Author(s): Mohammed Atef & George Malak.
 * Date: March 4, 2025.
 * Section: 1.
 * Course: Data Structure - CS214.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size -i -1; ++j) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void fun() {
    int arr[6] = {8, 4, 2, 29, 0, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, arrSize);
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " \n"[i == arrSize -1];
    }
}

int main() {
    ll t;
    t = 1;
//    cin >> t;
    while (t--) fun();
    return 0;
}
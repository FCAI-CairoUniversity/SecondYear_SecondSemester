/*
 * Author(s): Mohammed Atef & George Malak.
 * Date: March 18, 2025.
 * Lab & Section: 3.
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

void fun() {
    int size1, size2;

    cout << "Enter the size for arr 1 :";
    cin >> size1;
    int arr1[size1];
    for (int i = 0; i < size1; ++i) {
        cout << "Enter element " << i + 1 << " for arr 1 :";
        cin >> arr1[i] ;
    }

    cout << "Enter the size for arr 2 :";
    cin >> size2;
    int arr2[size2];
    for (int i = 0; i < size2; ++i) {
        cout << "Enter element " << i + 1 << " for arr 2 :";
        cin >> arr2[i];
    }

    quickSort(arr1, 0, size1 -1);
    quickSort(arr2, 0, size2 -1);

    int ind1 = 0 , ind2 = 0;
    cout << "Common elements : " ;
    while(ind1 < size1 && ind2 < size2){
        if(arr1[ind1] == arr2[ind2]){
            cout << arr1[ind1] << " \n"[ind1 == size1-1 || ind2 == size2-1];
            ind1++; ind2++;
        }
        else if (arr1[ind1] < arr2[ind2]) ind2++;
        else ind1++;
    }
}

int main() {
    int t = 1;
    while (t--) fun();
    return 0;
}
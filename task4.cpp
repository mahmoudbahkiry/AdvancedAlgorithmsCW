#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void rearrange(int arr[], int k, int start, int end) {
    if (start >= end)
        return;

    int pivot = arr[end];
    int left = start, right = end - 1;

    while (left <= right) {
        while (left <= right && arr[left] <= k)
            left++;
        while (left <= right && arr[right] > k)
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[left], arr[end]);

    rearrange(arr, k, start, left - 1);
    rearrange(arr, k, left + 1, end);
}

void rearrangeArray(int arr[], int size, int k) {
    rearrange(arr, k, 0, size - 1);
}

int main() {
    int arr[] = {3, 7, 1, 4, 2, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    rearrangeArray(arr, size, k);

    cout << "Rearranged array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
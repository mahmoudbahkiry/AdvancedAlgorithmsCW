#include <iostream>
using namespace std;

void removeDuplicates(char arr[], int& size) {
    int currentIndex = 0;

    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < currentIndex; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate == false) {
            arr[currentIndex++] = arr[i];
        }
    }

    size = currentIndex;
}

int main() {
    char arr[] = {'a', 'b', 'c', 'a', 'd', 'b', 'e'};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
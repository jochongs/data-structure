#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 2 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return;
}

int main() {
    int arr[10] = {10, 9, 3, 4, 5, 1, 2, 200, 300, 0};

    bubble_sort(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
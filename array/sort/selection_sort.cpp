#include <iostream>
using namespace std;

// 선택 정렬
void selection_sort(int arr[], int size, int direction = 1) {
    for (int i = 0; i < size; i++) {
        int idx = i;
        for (int j = i + 1; j < size; j++) {
            if (direction == 1) {
                if (arr[j] < arr[idx]) {
                    idx = j;
                }
                continue;
            }

            if (arr[j] > arr[idx]) {
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

int main() {
    int arr[10] = {2, 1, 3, 5, 6, 8, 6, 7, 9, 10};

    selection_sort(arr, 10, 1);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
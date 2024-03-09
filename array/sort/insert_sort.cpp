#include <iostream>
using namespace std;

void insert_sort(int arr[], int size, int direction = 1) {
    for (int i = 1; i < size; i ++) {
        int key = arr[i];

        int j = i - 1;
        while (j >= 0) {
            if (direction == 1 && arr[j] < key) {
                break;
            }

            if (direction != 1 && arr[j] > key) {
                break;
            }

            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key; 
    }
}

int main() {
    int arr[5] = {2, 1, 4, 5, 3};

    insert_sort(arr, 5, 2);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }
}
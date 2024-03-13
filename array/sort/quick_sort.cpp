#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int select_pivot_idx(int arr[], int start_idx, int end_idx) {
    return end_idx;
}

int partition(int arr[], int start_idx, int end_idx) {
    int pivot_idx = select_pivot_idx(arr, start_idx, end_idx);
    int pivot = arr[pivot_idx];

    int i = start_idx - 1;

    for (int j = start_idx; j <= end_idx; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, pivot_idx);
    return i + 1;
}

void quick_sort(int arr[], int start_idx, int end_idx) {
    if (start_idx >= end_idx) {
        return;
    }

    int mid_idx = partition(arr, start_idx, end_idx);

    quick_sort(arr, start_idx, mid_idx - 1);
    quick_sort(arr, mid_idx + 1, end_idx);
}

int main() {
    int arr[100000] = {8, 3, 4, 7, 2, 5, };

    int n = 3;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}
#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[], int size, int start_idx) {
    int largest_idx = start_idx;
    int left_node_idx = (start_idx + 1) * 2 - 1;
    int right_node_idx = (start_idx + 1) * 2;

    if (left_node_idx < size && arr[left_node_idx] > arr[largest_idx]) {
        largest_idx = left_node_idx;
    }

    if (right_node_idx < size && arr[right_node_idx] > arr[largest_idx]) {
        largest_idx = right_node_idx;
    }

    if (largest_idx != start_idx) {
        swap(arr, start_idx, largest_idx);
        heapify(arr, size, largest_idx);
    }
}

void heap_sort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[100000] = {0, };
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heap_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
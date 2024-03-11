#include <iostream>
using namespace std;

void merge(int arr[], int start_idx, int end_idx) {
    int new_arr[100] = {0, };

    int mid = (start_idx + end_idx) / 2;
    int i = start_idx;
    int j = mid + 1;
    int idx = 0;

    cout << "정렬 이전: ";
    for (int i = start_idx; i < end_idx + 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    while (i <= mid && j <= end_idx) {
        if (arr[i] > arr[j]) {
            new_arr[idx] = arr[j];
            j++;
        } else { 
            new_arr[idx] = arr[i];
            i++;
        }
        idx++;
    }

    while (i <= mid) {
        new_arr[idx] = arr[i];
        idx++;
        i++;
    }

    while (j <= end_idx) {
        new_arr[idx] = arr[j];
        idx++;
        j++;
    }
    
    cout << "정렬 결과: ";
    for (int i = 0; i < end_idx - start_idx + 1; i++) {
        arr[start_idx + i] = new_arr[i];
        cout << new_arr[i] << ' ';
    }
    cout << '\n';
}

void merge_sort(int arr[], int start_idx, int end_idx) {
    if (start_idx == end_idx) {
        return;
    }

    int mid = (start_idx + end_idx) / 2;

    cout << "분할: " << start_idx << " ~ " << mid << '\n';
    merge_sort(arr, start_idx, mid);

    cout << "분할: " << mid + 1 << " ~ " << end_idx << '\n';
    merge_sort(arr, mid + 1, end_idx);

    cout << "정렬: " << start_idx << " ~ " << end_idx << '\n';
    merge(arr, start_idx, end_idx);
}

int main() {
    int arr[100000] = {0, };

    int n = 0; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    cout << "최종 결과: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}